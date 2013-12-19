// midi_player.c
/* Function list:
 * check_snd()       -- INLINE
 * read_id()
 * on_System_OpenMidi_button_clicked()
 * on_System_PlayMidi_button_toggled(()
 * on_System_PauseMidi_button_toggled()
 * on_System_MIDI_Transpose_valueChanged()
 * send_data()
 * init_seq()
 * close_seq()
 * connect_port()
 * disconnect_port()
 * tickDisplay()
 * stop_sound()
*/

//#include "midi_player.h"
#include        "JVlibForm.h"
#include <alsa/asoundlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
#include <algorithm>
#include <QTimer>
#include <QtDebug>

#define MAKE_ID(c1, c2, c3, c4) ((c1) | ((c2) << 8) | ((c3) << 16) | ((c4) << 24))

// STATIC vars
snd_seq_t *JVlibForm::seq=0;
int JVlibForm::queue=0;
snd_seq_addr_t *JVlibForm::ports=0;
double JVlibForm::song_length_seconds=0;
unsigned int JVlibForm::event_num=0;

// FILE global vars
snd_seq_queue_status_t *status;
char playfile[PATH_MAX];
pid_t pid=0;

// INLINE functions
void JVlibForm::check_snd(const char *operation, int err)
{
    if (err < 0)
        QMessageBox::critical(this, "MIDI Player", QString("Cannot %1\n%2") .arg(operation) .arg(snd_strerror(err)));
}
int JVlibForm::read_id(void) {
    return read_32_le();
}

//  SLOTS
void JVlibForm::on_System_OpenMidi_button_clicked()
{
    System_PlayMidi_button->setChecked(false);
    System_PlayMidi_button->setEnabled(false);
    System_PauseMidi_button->setEnabled(false);
    SysFilePlaying->clear();
    System_MIDI_Transpose->setValue(0);
    System_MIDI_KeySig->clear();
    disconnect_port();
    close_seq();
    MIDI_length_display->setText("00:00");
    QString fn = QFileDialog::getOpenFileName(this,"Open MIDI File",MIDI_dir,"Midi files (*.mid, *.MID);;Any (*.*)");
    if (fn.isEmpty())
        return;
    strcpy(playfile, fn.toAscii().data());
    SysFilePlaying->setText(fn);
    init_seq();
    if (!queue) queue = snd_seq_alloc_named_queue(seq, "midi_play");
    check_snd("create queue", queue);
    connect_port();
    all_events.clear();
    if (!parseFile(playfile)) {
        QMessageBox::critical(this, "MIDI Player", QString("Invalid file"));
        return;
    }   // parseFile
    System_MIDI_progressBar->setRange(0,all_events.back().tick);
    System_MIDI_progressBar->setTickInterval(song_length_seconds<240? all_events.back().tick/song_length_seconds*10 : all_events.back().tick/song_length_seconds*30);
    System_MIDI_progressBar->setTickPosition(QSlider::TicksAbove);
    MIDI_length_display->setText(QString::number(static_cast<int>(song_length_seconds/60)).rightJustified(2,'0') + ":" + QString::number(static_cast<int>(song_length_seconds)%60).rightJustified(2,'0'));
    System_PlayMidi_button->setEnabled(true);
    System_MIDI_Transpose->setEnabled(true);
}   // end on_System_OpenMidi_button_clicked

void JVlibForm::on_System_PlayMidi_button_toggled(bool checked) {
    if (checked) {
	seqTimer = new QTimer(this);
        System_PauseMidi_button->setEnabled(true);
        System_OpenMidi_button->setEnabled(false);
        System_PlayMidi_button->setText("Stop");
	System_MIDI_progressBar->setEnabled(true);
//        if (!seq) init_seq();
//	if (!queue) {
//	  queue = snd_seq_alloc_named_queue(seq, "midi_player");
//	  check_snd("create queue", queue);
//	}
        connect_port();
        // queue won't actually start until it is drained
        int err = snd_seq_start_queue(seq, queue, NULL);
        check_snd("start queue", err);
	System_PlayMidi_status->on();
        connect(JVlibForm::seqTimer, SIGNAL(timeout()), this, SLOT(tickDisplay()));
        seqTimer->start(100);
	startPlayer(0);
    }
    else {
        if (seqTimer->isActive()) {
            disconnect(JVlibForm::seqTimer, SIGNAL(timeout()), this, SLOT(tickDisplay()));
            seqTimer->stop();
	    delete seqTimer;
        }
        snd_seq_stop_queue(seq,queue,NULL);
        snd_seq_drain_output(seq);
	stopPlayer();
	stop_sound();
        disconnect_port();
	System_PlayMidi_status->off();
	System_MIDI_progressBar->blockSignals(true);
        System_MIDI_progressBar->setValue(0);
	System_MIDI_progressBar->blockSignals(false);
        MIDI_time_display->setText("00:00");
        if (System_PauseMidi_button->isChecked()) {
            System_PauseMidi_button->blockSignals(true);
            System_PauseMidi_button->setChecked(false);
            System_PauseMidi_button->blockSignals(false);
            System_PauseMidi_button->setText("Pause");
        }
        System_PauseMidi_button->setEnabled(false);
        System_PlayMidi_button->setText("Play");
        System_OpenMidi_button->setEnabled(true);
	System_MIDI_Transpose->setEnabled(true);
	System_MIDI_progressBar->setEnabled(false);
//	close_seq();
	event_num=0;
    }
}   // end on_System_PlayMidi_button_toggled

void JVlibForm::on_System_PauseMidi_button_toggled(bool checked)
{
  unsigned int current_tick;
  if (checked) {
      stopPlayer();
      if (seqTimer->isActive()) {
            disconnect(JVlibForm::seqTimer, SIGNAL(timeout()), this, SLOT(tickDisplay()));
            seqTimer->stop();
      }
        snd_seq_get_queue_status(seq, queue, status);
	current_tick = snd_seq_queue_status_get_tick_time(status);
        snd_seq_stop_queue(seq,queue,NULL);
        snd_seq_drain_output(seq);
	stop_sound();
        System_PauseMidi_button->setText("Resume");
  }
  else {
        snd_seq_continue_queue(seq, queue, NULL);
        snd_seq_drain_output(seq);
        snd_seq_get_queue_status(seq, queue, status);
	current_tick = snd_seq_queue_status_get_tick_time(status);
        System_PauseMidi_button->setText("Pause");
        connect(JVlibForm::seqTimer, SIGNAL(timeout()), this, SLOT(tickDisplay()));
	startPlayer(current_tick);
        seqTimer->start(100);
  }
}   // end on_Pause_button_toggled

void JVlibForm::on_System_MIDI_Transpose_valueChanged(signed int val) {
  // change the Key Signature if one is displayed
  if (System_MIDI_KeySig->text().isEmpty() ||System_MIDI_KeySig->text()=="n/a") return;
  // if timer is running, pause playback, change the key, and resume
  on_System_PauseMidi_button_toggled(true);
  System_MIDI_KeySig->clear();
  signed int y = (7*val) + (sf>7?sf-256 :sf);
  while(y>7)
    y -= 12;
  while(y<-7)
    y += 12;
  y = y<0?0x100+y:y;
  if (minor_key) {
    switch(y) {
      case 0:
        System_MIDI_KeySig->setText("a minor");
        break;
      case 1:
        System_MIDI_KeySig->setText("e minor");
        break;
      case 2:
        System_MIDI_KeySig->setText("b minor");
        break;
      case 3:
        System_MIDI_KeySig->setText("f# minor");
        break;
      case 4:
        System_MIDI_KeySig->setText("c# minor");
        break;
      case 5:
        System_MIDI_KeySig->setText("g# minor");
        break;
      case 6:
        System_MIDI_KeySig->setText("d# minor");
        break;
      case 7:
        System_MIDI_KeySig->setText("a# minor");
        break;
      case 0xff:
        System_MIDI_KeySig->setText("d minor");
        break;
      case 0xfe:
        System_MIDI_KeySig->setText("g minor");
        break;
      case 0xfd:
        System_MIDI_KeySig->setText("c minor");
        break;
      case 0xFC:
        System_MIDI_KeySig->setText("f minor");
        break;
      case 0xFB:
        System_MIDI_KeySig->setText("bf minor");
        break;
      case 0xFA:
        System_MIDI_KeySig->setText("ef minor");
        break;
      case 0xF9:
        System_MIDI_KeySig->setText("af minor");
        break;
      default:
	System_MIDI_KeySig->clear();
	System_MIDI_KeySig->setText("n/a");
	break;
    }  // end switch
  }   // end ninor key
  else {
    switch(y) {
      case 0:
        System_MIDI_KeySig->setText("C Major");
        break;
      case 1:
        System_MIDI_KeySig->setText("G Major");
        break;
      case 2:
        System_MIDI_KeySig->setText("D Major");
        break;
      case 3:
        System_MIDI_KeySig->setText("A Major");
        break;
      case 4:
        System_MIDI_KeySig->setText("E Major");
        break;
      case 5:
        System_MIDI_KeySig->setText("B Major");
        break;
      case 6:
        System_MIDI_KeySig->setText("F# Major");
        break;
      case 7:
        System_MIDI_KeySig->setText("C# Major");
        break;
      case 0xFF:
        System_MIDI_KeySig->setText("F Major");
        break;
      case 0xFE:
        System_MIDI_KeySig->setText("Bf Major");
        break;
      case 0xFD:
        System_MIDI_KeySig->setText("Ef Major");
        break;
      case 0xFC:
        System_MIDI_KeySig->setText("Af Major");
        break;
      case 0xFB:
        System_MIDI_KeySig->setText("Df Major");
        break;
      case 0xFA:
        System_MIDI_KeySig->setText("Gf Major");
        break;
      case 0xF9:
        System_MIDI_KeySig->setText("Cf Major");
        break;
      default:
	System_MIDI_KeySig->clear();
	System_MIDI_KeySig->setText("n/a");
	break;
    } // end switch
  }   // end Major key
  on_System_PauseMidi_button_toggled(false);
} // end on_System_MIDI_Transpose_valueChanged

//  FUNCTIONS
void JVlibForm::send_data(char * buf,int data_size) {
    snd_seq_event_t ev;
    snd_seq_ev_clear(&ev);
    snd_seq_ev_set_direct(&ev);
    ev.queue = SND_SEQ_QUEUE_DIRECT;
    ev.type = SND_SEQ_EVENT_CONTROLLER;
    ev.dest = ports[0];
    ev.data.control.channel = buf[0];
    if (data_size>1)
      ev.data.control.param = buf[1];
    if (data_size==3)
      ev.data.control.value = buf[2];
    snd_seq_ev_set_fixed(&ev);
    snd_seq_ev_set_direct(&ev);
    snd_seq_event_output_direct(seq, &ev);
    snd_seq_drain_output(seq);
}   // end send_data

void JVlibForm::init_seq() {
  if (seq) return;
  int err = snd_seq_open(&seq, "default", SND_SEQ_OPEN_OUTPUT, 0);
  check_snd("open sequencer", err);
  err = snd_seq_set_client_name(seq, "midi_player");
  check_snd("set client name", err);
  int client = snd_seq_client_id(seq);    // client # is 128 by default
  check_snd("get client id", client);
}

void JVlibForm::close_seq() {
  if (!seq) return;
  snd_seq_stop_queue(seq,queue,NULL);
  snd_seq_drop_output(seq);
  snd_seq_drain_output(seq);
  snd_seq_close(seq);
  seq = 0;
}

void JVlibForm::connect_port() {
    if (seq && strlen(SEQ_dev)) {
        //  create_source_port
        snd_seq_port_info_t *pinfo;
        snd_seq_port_info_alloca(&pinfo);
        // the first created port is 0 anyway, but let's make sure ...
        snd_seq_port_info_set_port(pinfo, 0);
        snd_seq_port_info_set_port_specified(pinfo, 1);
        snd_seq_port_info_set_name(pinfo, "midi_player");
        snd_seq_port_info_set_capability(pinfo, 0);
        snd_seq_port_info_set_type(pinfo,
               SND_SEQ_PORT_TYPE_MIDI_GENERIC |
               SND_SEQ_PORT_TYPE_APPLICATION);
        int err = snd_seq_create_port(seq, pinfo);
        check_snd("create port", err);
	
        ports = (snd_seq_addr_t *)realloc(ports, sizeof(snd_seq_addr_t));
        err = snd_seq_parse_address(seq, &ports[0], SEQ_dev);
        if (err < 0) {
            QMessageBox::critical(this, "MIDI Player", QString("Invalid port%1\n%2") .arg(SEQ_dev) .arg(snd_strerror(err)));
            return;
        }
        err = snd_seq_connect_to(seq, 0, ports[0].client, ports[0].port);
        if (err < 0 && err!= -16)
            QMessageBox::critical(this, "MIDI Player", QString("%4 Cannot connect to port %1:%2 - %3") .arg(ports[0].client) .arg(ports[0].port) .arg(strerror(errno)) .arg(err));
    }
}   // end connect_port

void JVlibForm::disconnect_port() {
    if (seq && strlen(SEQ_dev)) {
      int err;
      ports = (snd_seq_addr_t *)realloc(ports, sizeof(snd_seq_addr_t));
      err = snd_seq_parse_address(seq, &ports[0], SEQ_dev);
      if (err < 0) {
        QMessageBox::critical(this, "MIDI Player", QString("Invalid port%1\n%2") .arg(SEQ_dev) .arg(snd_strerror(err)));
        return;
      }
//      stop_sound();
      err = snd_seq_disconnect_to(seq, 0, ports[0].client, ports[0].port);
    }   // end if seq
}   // end disconnect_port

void JVlibForm::tickDisplay() {
    // set timestamp display
  snd_seq_get_queue_status(seq, queue, status);
  unsigned int current_tick = snd_seq_queue_status_get_tick_time(status);
  System_MIDI_progressBar->blockSignals(true);
  System_MIDI_progressBar->setValue(current_tick);
  System_MIDI_progressBar->blockSignals(false);
  // set time label
  double new_seconds = static_cast<double>(current_tick)/all_events.back().tick;
  new_seconds *= song_length_seconds;
  MIDI_time_display->setText(QString::number(static_cast<int>(new_seconds)/60).rightJustified(2,'0')+
      ":"+QString::number(static_cast<int>(new_seconds)%60).rightJustified(2,'0'));
  if (current_tick >= all_events.back().tick) {	// end of song
      sleep(1);
      System_PlayMidi_button->setChecked(false);
      return;
  }
  while (all_events[event_num].tick<current_tick)
    event_num++;
}   // end tickDisplay

void JVlibForm::stop_sound() {
      // stop all sounds
      char buf[3];
      buf[1] = 0x78;
      buf[2] = 0;
      for (int x=0xB0;x<0xC0;x++) {
	buf[0] = x;
	send_data(buf,3);
      }
      buf[1] = 0x7B;
      for (int x=0xB0;x<0xC0;x++) {
	buf[0] = x;
	send_data(buf,3);
      }
}

void JVlibForm::startPlayer(int startTick) {
    if (pid>0) 
      return;
    pid=fork();
    if (!pid) {
        play_midi(startTick);
        exit(EXIT_SUCCESS);
    }   // end pid fork
}	// end startPlayer

void JVlibForm::stopPlayer() {
    if (pid) {
        kill(pid,SIGKILL);
        waitpid(pid,NULL,0);
    }
    pid = 0;
    snd_seq_drop_output(seq);
    snd_seq_drain_output(seq);
}
