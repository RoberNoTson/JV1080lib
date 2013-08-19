// midi_player.c
// Function list:
//  JVlibForm     -- constructor
// ~JVlibForm     -- destructor
// on_System_OpenMidi_button_clicked   -- SLOT
// on_Play_button_clicked   -- SLOT
// on_Stop_button_clicked   -- SLOT
// on_Panic_button_clicked   -- SLOT
// on_PortBox_currentIndexChanged   -- SLOT
//  check_snd       -- INLINE
// send_data
// init_seq
// close_seq
// connect_port
// disconnect_port
// tickDisplay

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
    SysPlayMidi_button->setChecked(false);
    SysPlayMidi_button->setEnabled(false);
    System_PauseMidi_button->setEnabled(false);
    SysFilePlaying->clear();
    disconnect_port();
    close_seq();
    MIDI_length_display->setText("00:00");

    QString fn = QFileDialog::getOpenFileName(this,"Open MIDI File",MIDI_dir,"Midi files (*.mid, *.MID);;Any (*.*)");
    if (fn.isEmpty())
        return;
    strcpy(playfile, fn.toAscii().data());
    SysFilePlaying->setText(fn);
    SysPlayMidi_button->setEnabled(true);
}   // end on_System_OpenMidi_button_clicked

void JVlibForm::on_SysPlayMidi_button_toggled(bool checked) {
    if (checked) {
        System_PauseMidi_button->setEnabled(true);
        System_OpenMidi_button->setEnabled(false);
        SysPlayMidi_button->setText("Stop");
        init_seq();
	if (!queue) {
	  queue = snd_seq_alloc_named_queue(seq, "midi_player");
	  check_snd("create queue", queue);
	}
        connect_port();
        all_events.clear();
        if (!parseFile(playfile)) {
            QMessageBox::critical(this, "MIDI Player", QString("Invalid file"));
	    close_seq();
            return;
        }   // parseFile
	qDebug() << "last tick: " << all_events.back().tick;
	System_MIDI_progressBar->setRange(0,all_events.back().tick-1);
	MIDI_length_display->setText(QString::number(static_cast<int>(song_length_seconds/60)).rightJustified(2,'0') + ":" + QString::number(static_cast<int>(song_length_seconds)%60).rightJustified(2,'0'));
	System_PlayMidi_status->on();
	pid=fork();
        if (!pid) {
            play_midi();
            exit(EXIT_SUCCESS);
        }   // end pid fork
        connect(JVlibForm::seqTimer, SIGNAL(timeout()), this, SLOT(tickDisplay()));
        seqTimer->start(500);
    }
    else {
        snd_seq_stop_queue(seq,queue,NULL);
        snd_seq_drain_output(seq);
        if (pid) {
            kill(pid,SIGKILL);
            waitpid(pid,NULL,0);
        }
        pid = 0;
        disconnect_port();
        if (seqTimer->isActive()) {
            disconnect(JVlibForm::seqTimer, SIGNAL(timeout()), this, SLOT(tickDisplay()));
            seqTimer->stop();
        }
	System_PlayMidi_status->off();
        System_MIDI_progressBar->reset();
        MIDI_time_display->setText("00:00");
        if (System_PauseMidi_button->isChecked()) {
            System_PauseMidi_button->blockSignals(true);
            System_PauseMidi_button->setChecked(false);
            System_PauseMidi_button->blockSignals(false);
            System_PauseMidi_button->setText("Pause");
        }
        System_PauseMidi_button->setEnabled(false);
        SysPlayMidi_button->setText("Play");
        System_OpenMidi_button->setEnabled(true);
	close_seq();
    }
}   // end on_Play_button_toggled

void JVlibForm::on_System_PauseMidi_button_toggled(bool checked)
{
    if (checked) {
        if (seqTimer->isActive()) {
            seqTimer->stop();
            disconnect(JVlibForm::seqTimer, SIGNAL(timeout()), this, SLOT(tickDisplay()));
        }
        snd_seq_stop_queue(seq,queue,NULL);
        snd_seq_drain_output(seq);
        System_PauseMidi_button->setText("Resume");
        qDebug() << "Paused queue" << queue;
    }
    else {
        System_PauseMidi_button->setText("Pause");
        snd_seq_continue_queue(seq, queue, NULL);
        snd_seq_drain_output(seq);
        connect(JVlibForm::seqTimer, SIGNAL(timeout()), this, SLOT(tickDisplay()));
        seqTimer->start();
        qDebug() << "Playing resumed from pause for queue" << queue;
    }
}   // end on_Pause_button_toggled

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
    if (!seq) {
        int err = snd_seq_open(&seq, "default", SND_SEQ_OPEN_OUTPUT, 0);
        check_snd("open sequencer", err);
        err = snd_seq_set_client_name(seq, "midi_player");
        check_snd("set client name", err);
        int client = snd_seq_client_id(seq);    // client # is 128 by default
        check_snd("get client id", client);
        qDebug() << "Seq and client initialized";
    }
}

void JVlibForm::close_seq() {
    if (seq) {
        snd_seq_stop_queue(seq,queue,NULL);
        snd_seq_drop_output(seq);
        snd_seq_drop_output_buffer(seq);
        snd_seq_drain_output(seq);
        snd_seq_free_queue(seq, queue);
        snd_seq_close(seq);
        seq = 0;
	queue = 0;
        qDebug() << "Seq closed";
    }
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
//    snd_seq_addr_t *ports = new snd_seq_addr_t;
        err = snd_seq_parse_address(seq, &ports[0], SEQ_dev);
        if (err < 0) {
            QMessageBox::critical(this, "MIDI Player", QString("Invalid port%1\n%2") .arg(SEQ_dev) .arg(snd_strerror(err)));
            return;
        }
        err = snd_seq_connect_to(seq, 0, ports[0].client, ports[0].port);
        if (err < 0 && err!= -16)
            QMessageBox::critical(this, "MIDI Player", QString("%4 Cannot connect to port %1:%2 - %3") .arg(ports[0].client) .arg(ports[0].port) .arg(strerror(errno)) .arg(err));
        qDebug() << "Connected port" << SEQ_dev;
    }
}   // end connect_port

void JVlibForm::disconnect_port() {
    if (seq && strlen(SEQ_dev)) {
        int err;
        ports = (snd_seq_addr_t *)realloc(ports, sizeof(snd_seq_addr_t));
//    snd_seq_addr_t *ports = new snd_seq_addr_t;
        err = snd_seq_parse_address(seq, &ports[0], SEQ_dev);
        if (err < 0) {
            QMessageBox::critical(this, "MIDI Player", QString("Invalid port%1\n%2") .arg(SEQ_dev) .arg(snd_strerror(err)));
            return;
        }
        err = snd_seq_disconnect_to(seq, 0, ports[0].client, ports[0].port);
//        if (err < 0 && err != -6 )
//            QMessageBox::critical(this, "MIDI Player", QString("%4 Cannot disconnect from port %1:%2 - %3") .arg(ports[0].client) .arg(ports[0].port) .arg(strerror(errno)) .arg(err));
        qDebug() << "Disconnected current port" << SEQ_dev;
    }   // end if seq
}   // end disconnect_port

void JVlibForm::tickDisplay() {
    // do timestamp display
    static unsigned int current_tick = 0;
    static const snd_seq_real_time_t *current_time;
    snd_seq_get_queue_status(seq, queue, status);

    current_tick = snd_seq_queue_status_get_tick_time(status);
    current_time = snd_seq_queue_status_get_real_time(status);
//    MIDI_time_display->setText(QTime(current_time->tv_sec/3600,current_time->tv_sec/60,current_time->tv_sec%60).toString());
    MIDI_time_display->setText(QString::number(current_time->tv_sec/60).rightJustified(2,'0')+":"+QString::number(current_time->tv_sec%60).rightJustified(2,'0'));
    System_MIDI_progressBar->setValue(static_cast<int>(current_tick));
    if (current_tick >= all_events.back().tick) {
        sleep(1);
        SysPlayMidi_button->setChecked(false);
}
}   // end tickDisplay
