// JVlibForm.cpp

#include	<QtGui>
#include	<QtSql>
#include	"JVlibForm.h"
#include	"ui_JVlib.h"
#include	<iniparser.h>

QString db_name;
QString db_user;
QString JVlibForm::CFGfile;
struct STATE_TABLE *JVlibForm::state_table = 0;

JVlibForm::~JVlibForm() {
  if (JVlibForm::mysql.contains("init"))
    JVlibForm::mysql.removeDatabase("init"); 
}

JVlibForm::JVlibForm() {
  setupUi(this);
  setInitial();
}	// end JVlibForm()

void JVlibForm::initGraphics() {
  // set up Patch Structure graphics
  scene1 = new QGraphicsScene();
  scene2 = new QGraphicsScene();
  scene3 = new QGraphicsScene();
  scene4 = new QGraphicsScene();
  scene5 = new QGraphicsScene();
  scene6 = new QGraphicsScene();
  scene7 = new QGraphicsScene();
  scene8 = new QGraphicsScene();
  scene9 = new QGraphicsScene();
  scene10 = new QGraphicsScene();
  scene1->addPixmap(QPixmap(":/res/Struct_Type1.png"));
  scene2->addPixmap(QPixmap(":/res/Struct_Type2.png"));
  scene3->addPixmap(QPixmap(":/res/Struct_Type3.png"));
  scene4->addPixmap(QPixmap(":/res/Struct_Type4.png"));
  scene5->addPixmap(QPixmap(":/res/Struct_Type5.png"));
  scene6->addPixmap(QPixmap(":/res/Struct_Type6.png"));
  scene7->addPixmap(QPixmap(":/res/Struct_Type7.png"));
  scene8->addPixmap(QPixmap(":/res/Struct_Type8.png"));
  scene9->addPixmap(QPixmap(":/res/Struct_Type9.png"));
  scene10->addPixmap(QPixmap(":/res/Struct_Type10.png"));
  Pitch_Env_scene = new QGraphicsScene;
  ToneTVA_Bias_scene = new QGraphicsScene;
  ToneTVA_Env_scene = new QGraphicsScene;
  ToneTVF_Env_scene = new QGraphicsScene;
  LFO1_scene = new QGraphicsScene;
  LFO2_scene = new QGraphicsScene;
  ToneEFX_PanKeyFollow_scene = new QGraphicsScene;
  ToneTVF_TimeKeyFollow_scene = new QGraphicsScene;
  ToneTVA_TimeKeyFollow_scene = new QGraphicsScene;
  Pitch_TimeKeyFollow_scene = new QGraphicsScene;
  Pitch_KeyFollow_scene = new QGraphicsScene;
  ToneTVF_CutoffKeyfollow_scene = new QGraphicsScene;
}	// end initGraphics

void JVlibForm::initStateTable() {
  state_table->perf_mode = false;
  state_table->patch_mode = false;
  state_table->GM_mode = false;
  state_table->systemTab_enable = false;
  state_table->system_sync = false;
  state_table->system_modified = false;
  state_table->performanceTab_enable = false;
  state_table->performance_sync = false;
  state_table->performance_modified = false;
  state_table->partsTab_enable = false;
  state_table->parts_modified = false;
  state_table->patchTab_enable = false;
  state_table->patch_sync = false;
  state_table->patch_modified = false;
  state_table->rhythmTab_enable = false;
  state_table->rhythm_sync = false;
  state_table->rhythm_modified = false;
  state_table->patchEFXTab_enable = false;
  state_table->toneTab_enable = false;
  state_table->tone_sync = false;
  state_table->tone_modified = false;
  state_table->toneEFXTab_enable = false;
  state_table->toneTVFTab_enable = false;
  state_table->toneTVATab_enable = false;
  state_table->pitchTab_enable = false;
  state_table->tuningTab_enable = false;
  state_table->tuningTab_sync = false;
  state_table->tuning_modified = false;
  state_table->midiPorts_open = false;	// PORTS_OPEN
  state_table->db_connect = false;	// DB_OPEN
  state_table->jv_connect = false;	// ONLINE
  state_table->updates_enabled = false;  
  state_table->part1_sync = false;  
  state_table->part2_sync = false;  
  state_table->part3_sync = false;  
  state_table->part4_sync = false;  
  state_table->part5_sync = false;  
  state_table->part6_sync = false;  
  state_table->part7_sync = false;  
  state_table->part8_sync = false;  
  state_table->part9_sync = false;  
  state_table->part10_sync = false;  
  state_table->part11_sync = false;  
  state_table->part12_sync = false;  
  state_table->part13_sync = false;  
  state_table->part14_sync = false;  
  state_table->part15_sync = false;  
  state_table->part16_sync = false;  
  state_table->initialized = true;
}	// end initStateTable

void JVlibForm::setInitial() {
  active_area = new ACTIVE_AREA;
  system_area = new SYSTEM_AREA;
  act_area = active_area;
  sys_area = system_area;
  state_table = new STATE_TABLE;
  initStateTable();
  initGraphics();
  createStatusBar();
  createMenuActions();
  createSysActions();
  createToneENVactions();
  MainTabWidget->setCurrentIndex(0);
  MainTabWidget->setTabEnabled(1,false);
  MainTabWidget->setTabEnabled(3,false);
  MainTabWidget->setTabEnabled(11,false);
  setPerfTabs(false);
  setPatchTabs(false);
 
  if (readConfigFile()) return;
  db_connect(db_name, db_user);
  // try to copy System data from the synth
  if (on_System_Sync_button_clicked() != EXIT_SUCCESS) {
    action_Offline->setChecked(true);
    System_JV_status->off();
    state_table->jv_connect = false;
    statusbar->showMessage("Failed to load System settings!");
    QMessageBox::critical(this, "JVlib", QString("Failed trying to load System settings.\nIs a valid MIDI port selected?"));
    return;
  }
  state_table->updates_enabled = true;
}	// end setInitial

int JVlibForm::readConfigFile() {
  QDir myDir;
  QCoreApplication *app;
  
  if (app->arguments().size() < 2) {
    QString myHome = myDir.homePath();
    QFileInfo fi(app->arguments().at(0));
    CFGfile = myHome+"/"+fi.fileName()+".cfg";
  } else {
    QFileInfo fi(app->arguments().at(1));
    CFGfile = fi.fileName();
  }
  QFile file(CFGfile);
  if (!file.exists()) {
    statusbar->showMessage("Not found "+CFGfile);
    return 1;
  }
  // open and parse the config file
  QSettings settings(CFGfile,QSettings::IniFormat);
  db_name = settings.value("mysql/database").toString();
  db_user = settings.value("mysql/username").toString();
  QString PORT_NAME = settings.value("JV1080/port_name").toString();
  QByteArray buf(PortBox->itemText(PortBox->findText(PORT_NAME, Qt::MatchContains)).toAscii(),8);
  strcpy(MIDI_dev, buf);
  state_table->jv_connect = true;
  return 0;
}	// end readConfigFile

void JVlibForm::closeEvent(QCloseEvent *event) {
  close_ports();
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
  if (state_table->db_connect) {
    if (mysql.isOpen()) mysql.close();
  }
}	// end closeEvent

void JVlibForm::createStatusBar()
{
  statusbar->setSizeGripEnabled(false);
  statusbar->showMessage("Ready");
}	// end createStatusBar

int JVlibForm::change_send(unsigned char *buf, int buf_size) {
  if (state_table->jv_connect) {
    int	err;
  // set to blocking mode
  snd_rawmidi_nonblock(midiInHandle, 0);
  snd_rawmidi_drop(midiOutHandle);
  // transmit the data
  if ((err = snd_rawmidi_write(midiOutHandle, buf, buf_size)) < 0) { 
    QMessageBox::critical(this, "JVlib", tr("Cannot write to MIDI output\n%1") .arg(snd_strerror(err)));
    return(EXIT_FAILURE);
  }
  snd_rawmidi_drain(midiOutHandle);
  return(err);
  }	// end state_table->jv_connect
  return EXIT_FAILURE;
}	// end CHANGE_SEND

int JVlibForm::sysex_send(unsigned char *buf, int buf_size) {
  if (state_table->jv_connect) {
  int	err;
  char    JV_header[4] = { 0xF0,0x41,0x10,0x6A };
  // set to blocking mode
  snd_rawmidi_nonblock(midiInHandle, 0);
  snd_rawmidi_drop(midiOutHandle);
  for (int x=0;x<4;x++) buf[x]=JV_header[x];
//  if (buf[4] == 0x12) MODIFIED ? : MODIFIED=true;
  // transmit the data
  if ((err = snd_rawmidi_write(midiOutHandle, buf, buf_size)) < 0) { 
    QMessageBox::critical(this, "JVlib", tr("Cannot write to MIDI output\n%1") .arg(snd_strerror(err)));
    return(EXIT_FAILURE);
  }
  snd_rawmidi_drain(midiOutHandle);
  return(err);
  }	// end state_table->jv_connect
  return EXIT_FAILURE;
}	// end SYSEX_SEND

int JVlibForm::sysex_get(unsigned char *buf, char *req_size) {
  if (state_table->jv_connect) {
  int	data_size,x,buf_size,read;
  register int err;
  int npfds, time;
  int timeout = 2000;
  struct pollfd *pfds;
  unsigned char	recv_buf[256];
  unsigned char hold_buf[512];
  unsigned short revents;
  snd_rawmidi_status_t *ptr;
  
  // calculate data size
  data_size = req_size[0] * 0x80*0x80*0x80;
  data_size += req_size[1] * 0x80*0x80;
  data_size += req_size[2] * 0x80;
  data_size += req_size[3];
  buf_size=data_size+11;
  // set up polling structs, prepare for reading data
  time=0;
  npfds = snd_rawmidi_poll_descriptors_count(midiInHandle);
  pfds = new pollfd;
  snd_rawmidi_poll_descriptors(midiInHandle, pfds, npfds);
  snd_rawmidi_nonblock(midiInHandle,1);		// set to nonblocking mode
  memset(recv_buf,0,sizeof(recv_buf));
  read=0;
  // big loop to read data
  for (;;) {
    err = poll(pfds, npfds, 200);
    // process poll status/errors
    if (err < 0 && errno == EINTR) break;
    if (err < 0) { printf("poll failed: %s", strerror(errno)); break; }
    // timeout (or correct amount of data) are the only good ways to exit this loop
    if (err == 0) {
      time += 200;
      if (timeout && time >= timeout) {puts("#### TIMEOUT ####"); break; }
      usleep(40000); continue;
    }
    if ((err = snd_rawmidi_poll_descriptors_revents(midiInHandle, pfds, npfds, &revents)) < 0) {
      printf("Cannot get poll events: %s\n", snd_strerror(err));
      break;
    }
    if (revents & (POLLERR | POLLHUP)) break;
    if (!(revents & POLLIN)) { usleep(40000); continue; }	// loop if no data and still polling
    // read the incoming data
    err = snd_rawmidi_read(midiInHandle, recv_buf, sizeof(recv_buf));
    if (err == -EAGAIN) { usleep(40000); continue; }
    if (err < 0) {
      printf("cannot read from port \"%s\": %s", MIDI_dev, snd_strerror(err));
      delete pfds;
      return(2);	// signal possible retry to calling routine
    }
    if (err == 0) { usleep(40000); continue; }
    time = 0;	// data received, reset the timeout value
    memcpy(hold_buf+read, recv_buf, err);
    read += err;
    if (read >= buf_size) break;
  }	// end FOR bigloop
  // pause before parsing data and returning
  usleep(40000);
  // validate the data received
  if ((x=chksum((unsigned char *)&hold_buf[5], buf_size-7)) != hold_buf[buf_size-2]) { 
//    printf("Chksum error! Expected 0x%02X, received 0x%02X\n",recv_buf[buf_size-2],x);
    // We need to get a snd_rawmidi_status_t struct
    if ((err = snd_rawmidi_status_malloc(&ptr)) < 0)
      printf("Can't get snd_rawmidi_status_t: %s\n", snd_strerror(err));
    else {
      // Tell ALSA to fill in our snd_rawmidi_status_t struct with this device's status
      if ((err = snd_rawmidi_status(midiInHandle, ptr)) < 0)
	  printf("Can't get status: %s\n", snd_strerror(err));
      else {
	err = snd_rawmidi_status_get_xruns(ptr);
	if (err != 0) printf("There are %i overrun errors\n", err);
      }
      // Free the snd_rawmidi_status_t struct when done
      snd_rawmidi_status_free(ptr);
    }
    delete pfds;
    return(3);	// signal possible retry to calling routine
  }
  if (hold_buf[buf_size-1] != 0xF7) { 
    puts("#### Incomplete data received! ####");
//    printf("#### 0x%02X bytes received, last byte was 0x%02X, not 0xF7 ####\n", read,recv_buf[buf_size-1]);
    // We need to get a snd_rawmidi_status_t struct
    if ((err = snd_rawmidi_status_malloc(&ptr)) < 0)
      printf("Can't get snd_rawmidi_status_t: %s\n", snd_strerror(err));
    else {
      // Tell ALSA to fill in our snd_rawmidi_status_t struct with this device's status
      if ((err = snd_rawmidi_status(midiInHandle, ptr)) < 0)
	  printf("Can't get status: %s\n", snd_strerror(err));
      else {
	err = snd_rawmidi_status_get_xruns(ptr);
	if (err != 0) printf("There are %i overrun errors\n", err);
      }
      // Free the snd_rawmidi_status_t struct when done
      snd_rawmidi_status_free(ptr);
    }
    delete pfds;
    return(2);	// signal possible retry to calling routine
  }
  // valid data, copy to the request buffer
  memcpy(buf, (char *)hold_buf+9, data_size);
  delete pfds;
  return EXIT_SUCCESS;
  }	// end state_table->jv_connect
  return EXIT_FAILURE;
}	// end SYSEX_GET

void	JVlibForm::close_ports() {
  if (state_table->midiPorts_open == true) {
    snd_rawmidi_close(midiInHandle);
    snd_rawmidi_close(midiOutHandle);
    state_table->midiPorts_open = false;
  }
}  // end CLOSE_PORTS

int JVlibForm::open_ports() {
  int err;
  if (state_table->midiPorts_open == false) {
    if (strlen(MIDI_dev)) {
      if ((err = snd_rawmidi_open(&midiInHandle, &midiOutHandle, MIDI_dev, 0)) < 0) {
	QMessageBox::critical(this, "JVlib", tr("Cannot open MIDI port %1\n%2") .arg(MIDI_dev) .arg(snd_strerror(err)));
	return EXIT_FAILURE;
      }
      // dummy read to activate the ports
      if ((err = snd_rawmidi_read(midiInHandle, NULL, 0)) < 0) { 
	QMessageBox::critical(this, "JVlib", tr("Cannot read from MIDI port %1\n%2") .arg(MIDI_dev) .arg(snd_strerror(err)));
	close_ports();
	return EXIT_FAILURE;
      }
    } else {
      QMessageBox::critical(this, "JVlib", tr("No MIDI port selected"));
      return EXIT_FAILURE;
    }
    state_table->midiPorts_open = true;
  }
  return EXIT_SUCCESS;
}	// end OPEN_PORTS

short int JVlibForm::chksum(unsigned char *buf, int buf_size) {
  int x,sum;
  sum=0;
  for(x=0;x<buf_size;x++) sum += buf[x];
  sum %= 0x80;
  sum = 0x80-sum;
  sum &= 0x7F;
  return sum;
}	// end CHKSUM

int JVlibForm::hexdump(unsigned char *buffer, int data_size) {
  int	y,offset;
  offset=0;
  y=data_size%16;
  for (int x=0;x<data_size-y;x+=16) {
    // Print the offset in the file, followed by the bytes themselves
    printf ("0x%06x : ", offset);
    for (int i = 0; i < 16; i++) {
      printf ("%02x ", buffer[x+i]);
    }
    printf ("  |  ");
    for (int i = 0; i < 16; i++) {
	if (isprint(buffer[x+i])) {
	putchar(buffer[x+i]);
	} else {
	printf (".");
	}
    }
    puts("");
    // Keep count of our position in the file
    offset += 16;
  }
  // print any remaining partial lines
  if (y) {
    // Print the offset in the file, followed by the bytes themselves
    printf ("0x%06x : ", offset);
    for (int i = data_size-y; i < data_size; i++) {
      printf ("%02x ", buffer[i]);
    }
    for (int i=0;i<16-y;i++) printf("   ");
    printf ("  |  ");
    for (int i = data_size-y; i < data_size; i++) {
      if (isprint(buffer[i])) {
	putchar(buffer[i]);
      } else {
	printf (".");
      }
    }
    puts("");
  }	// end IF
  return EXIT_SUCCESS;
}	// end HEXDUMP

int JVlibForm::db_connect(QString db_name, QString user_name) {
  if (mysql.isOpen()) return EXIT_SUCCESS;
  QSqlDatabase mysql = QSqlDatabase::addDatabase("QMYSQL");
  if (mysql.isValid()) puts("created db connection");
  else puts("invalid db connection");
  mysql.setConnectOptions("UNIX_SOCKET=/var/lib/mysql/mysql.sock");
  mysql.setDatabaseName(db_name);
  mysql.setUserName(user_name);
  puts("opening the db");
  if (mysql.open() == false) {
    // ERROR!
    QMessageBox::critical(this, "JVlib", tr("Database could not be opened\n%1") .arg(mysql.lastError().databaseText()));
    puts("Unable to open the database");
    statusbar->showMessage(mysql.lastError().databaseText());
    return EXIT_FAILURE;
  }
  state_table->db_connect = true;
  System_DB_status->on();
  return EXIT_SUCCESS;
}

QString JVlibForm::funcNoteCalc(int val) {
  char note_name[] = "C C#D D#E F F#G G#A A#B ";
  char note_octave[] = "-1 0 1 2 3 4 5 6 7 8 9";
  char note_buffer[4];

  memcpy(note_buffer,&note_name[(val%12)*2],2);
  memcpy(note_buffer+2,&note_octave[(val/12)*2],2);
  QString QNoteBuf = QString::fromAscii(note_buffer,4);
  emit noteval(&QNoteBuf);
  return QNoteBuf;
}	// end funcNoteCalc

QString JVlibForm::Pan2Deg(int val) {
  // val ranges between -64 to +63, where 0 is center
  QString buf = "";
  if (val == 0)
    buf = "Center";
  else if (val < 0)
    buf = "L"+QString::number((val*90)/(-64))+QString(" Deg.");
  else 
    buf = "R"+QString::number((val)*90/63)+QString(" Deg.");
  return buf;
}	// end Pan2Deg

void JVlibForm::on_MainTabWidget_currentChanged(int val) {
  switch(val) {
    case 0:
      SysMode_select->setFocus();
      break;
    case 1:
      PerfSync_button->setFocus();
      break;
    case 2:
      PartsPerfName_display->setFocus();
      break;
    case 3:
      Patch_Sync_button->setFocus();
      break;
    case 4:
      Rhythm_Sync_button->setFocus();
    case 5:
      PatchEFX_Type_select->setFocus();
      break;
    case 6:
      ToneSync_button->setFocus();
      break;
    case 7:
      ToneEFX_PanControl_select->setFocus();
      break;
    case 8:
      ToneTVF_FilterType_select->setFocus();
      break;
    case 9:
      break;
    case 10:
      Pitch_KeyFollow_select->setFocus();
      break;
    case 11:
      Tuning_MasterTune_select->setFocus();
      break;
    default:
      SysMode_select->setFocus();
      break;
  }
}
