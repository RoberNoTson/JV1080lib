// midi_player.c
// Function list:
//  MIDI_PLAYER     -- constructor
// ~MIDI_PLAYER     -- destructor
// on_Open_button_clicked   -- SLOT
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
// getRawDev
// getPorts

#include "midi_player.h"
#include "ui_midi_player.h"
#include <alsa/asoundlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <vector>
#include <algorithm>
#include <QtDebug>
#include <QTimer>
#include <iostream>

#define MAKE_ID(c1, c2, c3, c4) ((c1) | ((c2) << 8) | ((c3) << 16) | ((c4) << 24))

// STATIC vars
snd_seq_t *MIDI_PLAYER::seq=0;
int MIDI_PLAYER::queue=0;
snd_seq_addr_t *MIDI_PLAYER::ports=0;
double MIDI_PLAYER::song_length_seconds=0;

// FILE global vars
snd_seq_queue_status_t *status;
char playfile[PATH_MAX];
pid_t pid=0;
char port_name[16];
char MIDI_dev[16];

// INLINE functions
void MIDI_PLAYER::check_snd(const char *operation, int err)
{
    if (err < 0)
        QMessageBox::critical(this, "MIDI Player", QString("Cannot %1\n%2") .arg(operation) .arg(snd_strerror(err)));
}
int MIDI_PLAYER::read_id(void) {
    return read_32_le();
}

// constructor
MIDI_PLAYER::MIDI_PLAYER(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MIDI_PLAYER)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    memset(MIDI_dev,0,sizeof(MIDI_dev));
    memset(port_name,0,sizeof(port_name));

    init_seq();
    queue = snd_seq_alloc_named_queue(seq, "midi_player");
    check_snd("create queue", queue);
    getPorts();     // empty parm means fill in the PortBox list
    snd_seq_queue_status_malloc(&status);
    close_seq();
}   // end constructor

MIDI_PLAYER::~MIDI_PLAYER()
{
    ui->Play_button->setChecked(false);
    close_seq();
    delete ui;
}   // end destructor

//  SLOTS
void MIDI_PLAYER::on_Open_button_clicked()
{
    ui->Play_button->setChecked(false);
    ui->Play_button->setEnabled(false);
    ui->Pause_button->setEnabled(false);
    ui->MidiFile_display->clear();
    disconnect_port();
    close_seq();

    QString fn = QFileDialog::getOpenFileName(this,"Open MIDI File","/Music/midi","Midi files (*.mid, *.MID);;Any (*.*)");
    if (fn.isEmpty())
        return;
    ui->MidiFile_display->setText(fn);
    ui->MIDI_length_display->setText("00:00:00");
    init_seq();
    queue = snd_seq_alloc_named_queue(seq, "midi_player");
    check_snd("create queue", queue);
    connect_port();
    strcpy(playfile, fn.toAscii().data());
    all_events.clear();
    if (!parseFile(playfile)) {
        QMessageBox::critical(this, "MIDI Player", QString("Invalid file"));
        return;
    }   // parseFile
    qDebug() << "last tick: " << all_events.back().tick;
    ui->progressBar->setRange(0,all_events.back().tick-1);
    ui->Play_button->setEnabled(true);
    ui->MIDI_length_display->setText(QTime(static_cast<int>(song_length_seconds/3600), static_cast<int>(song_length_seconds/60), static_cast<int>(song_length_seconds)%60).toString());
}   // end on_Open_button_clicked

void MIDI_PLAYER::on_Play_button_toggled(bool checked)
{
    if (checked) {
        ui->Pause_button->setEnabled(true);
        ui->Open_button->setEnabled(false);
        ui->Play_button->setText("Stop");
        init_seq();
        connect_port();
        all_events.clear();
        if (!parseFile(playfile)) {
            QMessageBox::critical(this, "MIDI Player", QString("Invalid file"));
            return;
        }   // parseFile
        qDebug() << "last tick: " << all_events.back().tick;
        pid=fork();
        if (!pid) {
            play_midi();
            exit(EXIT_SUCCESS);
        }   // end pid fork
        connect(timer, SIGNAL(timeout()), this, SLOT(tickDisplay()));
        timer->start(500);
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
        if (timer->isActive()) {
            disconnect(timer, SIGNAL(timeout()), this, SLOT(tickDisplay()));
            timer->stop();
        }
        ui->progressBar->reset();
        ui->MIDI_time_display->setText("00:00:00");
        if (ui->Pause_button->isChecked()) {
            ui->Pause_button->blockSignals(true);
            ui->Pause_button->setChecked(false);
            ui->Pause_button->blockSignals(false);
            ui->Pause_button->setText("Pause");
        }
        ui->Pause_button->setEnabled(false);
        ui->Play_button->setText("Play");
        ui->Open_button->setEnabled(true);
    }
}   // end on_Play_button_toggled

void MIDI_PLAYER::on_Pause_button_toggled(bool checked)
{
    if (checked) {
        if (timer->isActive()) {
            timer->stop();
            disconnect(timer, SIGNAL(timeout()), this, SLOT(tickDisplay()));
        }
        snd_seq_stop_queue(seq,queue,NULL);
        snd_seq_drain_output(seq);
        ui->Pause_button->setText("Resume");
        qDebug() << "Paused queue" << queue;
    }
    else {
        ui->Pause_button->setText("Pause");
        snd_seq_continue_queue(seq, queue, NULL);
        snd_seq_drain_output(seq);
        connect(timer, SIGNAL(timeout()), this, SLOT(tickDisplay()));
        timer->start();
        qDebug() << "Playing resumed from pause for queue" << queue;
    }
}   // end on_Pause_button_toggled

void MIDI_PLAYER::on_Panic_button_clicked()
{
  char buf[6];
  if (seq) {
    connect_port();
    for (int x=0;x<16;x++) {
        buf[0] = 0xb0+x;
        buf[1] = 0x7B;
        buf[2] = 00;
        send_data(buf,3);
        buf[0] = 0xb0+x;
        buf[1] = 0x79;
        buf[2] = 00;
        send_data(buf,3);
    }
  }
  else {
      getRawDev(ui->PortBox->currentText());
      if (strlen(MIDI_dev)) {
          snd_rawmidi_t *midiInHandle;
          snd_rawmidi_t *midiOutHandle;
          int err=snd_rawmidi_open(&midiInHandle, &midiOutHandle, MIDI_dev, 0);
          check_snd("open rawidi",err);
          snd_rawmidi_nonblock(midiInHandle, 0);
          err = snd_rawmidi_read(midiInHandle, NULL, 0);
          check_snd("read rawidi",err);
          snd_rawmidi_drop(midiOutHandle);
          for (int x=0;x<16;x++) {
              buf[0] = buf[3] = 0xb0+x;
              buf[1] = 0x7B;
              buf[4] = 0x79;
              buf[2] = buf[5] = 00;
              err = snd_rawmidi_write(midiOutHandle, buf, 6);
          }
          snd_rawmidi_drain(midiOutHandle);
          snd_rawmidi_close(midiOutHandle);
          snd_rawmidi_close(midiInHandle);
      } // end strlen(MIDI_dev)
  } // end else
}   // end on_Panic_button_clicked

void MIDI_PLAYER::on_PortBox_currentIndexChanged(QString buf)
{
    qDebug() << "Index changed";
    init_seq();
    disconnect_port();
    getPorts(buf);
    connect_port();
}

//  FUNCTIONS
void MIDI_PLAYER::send_data(char * buf,int data_size) {
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

void MIDI_PLAYER::init_seq() {
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

void MIDI_PLAYER::close_seq() {
    if (seq) {
        snd_seq_stop_queue(seq,queue,NULL);
        snd_seq_drop_output(seq);
        snd_seq_drop_output_buffer(seq);
        snd_seq_drain_output(seq);
        snd_seq_free_queue(seq, queue);
        snd_seq_close(seq);
        seq = 0;
        qDebug() << "Seq closed";
    }
}

void MIDI_PLAYER::connect_port() {
    if (seq && strlen(port_name)) {
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
        err = snd_seq_parse_address(seq, &ports[0], port_name);
        if (err < 0) {
            QMessageBox::critical(this, "MIDI Player", QString("Invalid port%1\n%2") .arg(port_name) .arg(snd_strerror(err)));
            return;
        }
        err = snd_seq_connect_to(seq, 0, ports[0].client, ports[0].port);
        if (err < 0 && err!= -16)
            QMessageBox::critical(this, "MIDI Player", QString("%4 Cannot connect to port %1:%2 - %3") .arg(ports[0].client) .arg(ports[0].port) .arg(strerror(errno)) .arg(err));
        qDebug() << "Connected port" << port_name;
    }
}   // end connect_port

void MIDI_PLAYER::disconnect_port() {
    if (seq && strlen(port_name)) {
        int err;
        ports = (snd_seq_addr_t *)realloc(ports, sizeof(snd_seq_addr_t));
//    snd_seq_addr_t *ports = new snd_seq_addr_t;
        err = snd_seq_parse_address(seq, &ports[0], port_name);
        if (err < 0) {
            QMessageBox::critical(this, "MIDI Player", QString("Invalid port%1\n%2") .arg(port_name) .arg(snd_strerror(err)));
            return;
        }
        err = snd_seq_disconnect_to(seq, 0, ports[0].client, ports[0].port);
        if (err < 0 )
            QMessageBox::critical(this, "MIDI Player", QString("%4 Cannot disconnect from port %1:%2 - %3") .arg(ports[0].client) .arg(ports[0].port) .arg(strerror(errno)) .arg(err));
        qDebug() << "Disconnected current port" << port_name;
    }   // end if seq
}   // end disconnect_port

void MIDI_PLAYER::getPorts(QString buf) {
    // fill in the combobox with all available ports
    // or set port_name to the port passed in buf
    snd_seq_client_info_t *cinfo;
    snd_seq_port_info_t *pinfo;
    snd_seq_client_info_alloca(&cinfo);
    snd_seq_port_info_alloca(&pinfo);
    snd_seq_client_info_set_client(cinfo, -1);
    if (buf.isEmpty()) {
        ui->PortBox->blockSignals(true);
        ui->PortBox->clear();
        ui->PortBox->blockSignals(false);
    }
    while (snd_seq_query_next_client(seq, cinfo) >= 0) {
        int client = snd_seq_client_info_get_client(cinfo);
        snd_seq_port_info_set_client(pinfo, client);
        snd_seq_port_info_set_port(pinfo, -1);
        while (snd_seq_query_next_port(seq, pinfo) >= 0) {
            /* we need both WRITE and SUBS_WRITE */
            if ((snd_seq_port_info_get_capability(pinfo)
                 & (SND_SEQ_PORT_CAP_WRITE | SND_SEQ_PORT_CAP_SUBS_WRITE))
                != (SND_SEQ_PORT_CAP_WRITE | SND_SEQ_PORT_CAP_SUBS_WRITE))
                continue;
            if (buf.isEmpty()) {
                ui->PortBox->blockSignals(true);
                ui->PortBox->insertItem(9999, snd_seq_port_info_get_name(pinfo));
                ui->PortBox->blockSignals(false);
                printf("port: %s\n",snd_seq_port_info_get_name(pinfo));
            }
            else if (buf.toAscii().data() == QString(snd_seq_port_info_get_name(pinfo))) {
                QString holdit = QString::number(snd_seq_port_info_get_client(pinfo)) + ":" + QString::number(snd_seq_port_info_get_port(pinfo));
                strcpy(port_name, holdit.toAscii().data());
                qDebug() << "Selected port name " << port_name;
            }
        }
    }
}   // end getPorts

void MIDI_PLAYER::getRawDev(QString buf) {
  if (buf.isEmpty()) return;
  signed int card_num=-1;
  signed int dev_num=-1;
  signed int subdev_num=-1;
  int err,i;
  char	str[64];
  snd_rawmidi_info_t  *rawMidiInfo;
  snd_ctl_t *cardHandle;
  err = snd_card_next(&card_num);
  if (err < 0) {
     memset(MIDI_dev,0,sizeof(MIDI_dev));
    // no MIDI cards found in the system
    snd_card_next(&card_num);
    return;
  }
  while (card_num >= 0) {
    sprintf(str, "hw:%i", card_num);
    if ((err = snd_ctl_open(&cardHandle, str, 0)) < 0) break;
    dev_num = -1;
    err = snd_ctl_rawmidi_next_device(cardHandle, &dev_num);
    if (err < 0) {
      // card exists, but no midi device was found
      snd_card_next(&card_num);
      continue;
    }
    while (dev_num >= 0) {
      snd_rawmidi_info_alloca(&rawMidiInfo);
      memset(rawMidiInfo, 0, snd_rawmidi_info_sizeof());
      // Tell ALSA which device (number) we want info about
      snd_rawmidi_info_set_device(rawMidiInfo, dev_num);
      // Get info on the MIDI outs of this device
      snd_rawmidi_info_set_stream(rawMidiInfo, SND_RAWMIDI_STREAM_OUTPUT);
      i = -1;
      subdev_num = 1;
      // More subdevices?
      while (++i < subdev_num) {
          // Tell ALSA to fill in our snd_rawmidi_info_t with info on this subdevice
          snd_rawmidi_info_set_subdevice(rawMidiInfo, i);
          if ((err = snd_ctl_rawmidi_info(cardHandle, rawMidiInfo)) < 0) continue;
          // Print out how many subdevices (once only)
          if (!i) {
              subdev_num = snd_rawmidi_info_get_subdevices_count(rawMidiInfo);
          }
          // got a valid card, dev and subdev
          if (buf == (QString)snd_rawmidi_info_get_subdevice_name(rawMidiInfo)) {
              QString holdit = "hw:" + QString::number(card_num) + "," + QString::number(dev_num) + "," + QString::number(i);
              strcpy(MIDI_dev, holdit.toAscii().data());
          }
      }	// end WHILE subdev_num
      snd_ctl_rawmidi_next_device(cardHandle, &dev_num);
    }	// end WHILE dev_num
    snd_ctl_close(cardHandle);
    err = snd_card_next(&card_num);
  }	// end WHILE card_num
}	// end getRawDev()

void MIDI_PLAYER::tickDisplay() {
    // do timestamp display
    static unsigned int current_tick = 0;
    static const snd_seq_real_time_t *current_time;
    snd_seq_get_queue_status(seq, queue, status);

    current_tick = snd_seq_queue_status_get_tick_time(status);
    current_time = snd_seq_queue_status_get_real_time(status);
    ui->MIDI_time_display->setText(QTime(current_time->tv_sec/3600,current_time->tv_sec/60,current_time->tv_sec%60).toString());
    ui->progressBar->setValue(static_cast<int>(current_tick));
    if (current_tick >= all_events.back().tick) {
        sleep(1);
        ui->Play_button->setChecked(false);
}
}   // end tickDisplay

