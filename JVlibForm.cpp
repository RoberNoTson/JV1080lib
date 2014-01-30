// JVlibForm.cpp
// Contains:
//	JVlibForm()
//	~JVlibForm()
//	initGraphics()
//	initStateTable()
//	setInitial()
//	readConfigFile()
//	getSeqPort()
//	closeEvent()
//	createStatusBar()
//	db_connect()
//	getPort()

#include	<QtGui>
#include	<QtSql>
#include	"JVlibForm.h"
#include	"ui_JVlib.h"

// Form-level variables
QString db_name;
QString db_user;
QString PORT_NAME;
QString JVlibForm::CFGfile;
// static variables
struct STATE_TABLE *JVlibForm::state_table = 0;
struct SYSTEM_AREA *JVlibForm::system_area=0;
struct ACTIVE_AREA *JVlibForm::active_area=0;
char JVlibForm::MIDI_dev[] = { 0 };
snd_rawmidi_t *JVlibForm::midiInHandle = 0;
snd_rawmidi_t *JVlibForm::midiOutHandle = 0;
QByteArray JVlibForm::Tuning_Just = 0;
QByteArray JVlibForm::Tuning_Pythag = 0;
QByteArray JVlibForm::Tuning_Pure = 0;
QByteArray JVlibForm::Tuning_Well = 0;
QByteArray JVlibForm::Tuning_Meantone = 0;
QByteArray JVlibForm::Tuning_Arabic = 0;

JVlibForm::~JVlibForm() {
  Data_List.close();
  if (JVlibForm::mysql.contains("init"))
    JVlibForm::mysql.removeDatabase("init"); 
  System_PlayMidi_button->setChecked(false);
  close_seq();
}

JVlibForm::JVlibForm() {
  setupUi(this);
  setInitial();
  static DATA_LIST Data_List;
  static NOTE_LIST Note_List;
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
  state_table->rhythm_mode = false;
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
  state_table->tuning_sync = false;
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
  state_table = new STATE_TABLE;
  char Temp[12];
  Temp = { 0x40, 0x4C, 0x44, 0x50, 0x32, 0x3E, 0x2E, 0x42, 0x24, 0x30, 0x52, 0x34 };
  Tuning_Just.replace(0,12,Temp);
  Temp = {  0x40, 0x36, 0x44, 0x3A, 0x48, 0x3E, 0x4C, 0x42, 0x38, 0x46, 0x3C, 0x4A};
  Tuning_Pythag.replace(0,12,Temp);
  Temp = { 0x40, 0x38, 0x44, 0x50, 0x32, 0x3E, 0x36, 0x42, 0x4E, 0x30, 0x4E, 0x34 };
  Tuning_Pure.replace(0,12,Temp);
  Temp = { 0x46, 0x40, 0x42, 0x44, 0x3E, 0x46, 0x3E, 0x44, 0x42, 0x40, 0x46, 0x3E };
  Tuning_Well.replace(0,12,Temp);
  Temp = { 0x40, 0x28, 0x39, 0x4B, 0x32, 0x44, 0x2B, 0x3D, 0x24, 0x36, 0x47, 0x2E };
  Tuning_Meantone.replace(0,12,Temp);
  Temp = { 0x3A, 0x6D, 0x3E, 0x34, 0x0D, 0x38, 0x6B, 0x3C, 0x6F, 0x40, 0x36, 0x0F };
  Tuning_Arabic.replace(0,12,Temp);
  initStateTable();
  initGraphics();
  createStatusBar();
  createMenuActions();
  createSysActions();
  createToneENVactions();
  MainTabWidget->setCurrentIndex(0);
  MainTabWidget->setTabEnabled(1,false);
  MainTabWidget->setTabEnabled(2,false);
  MainTabWidget->setTabEnabled(3,false);
  MainTabWidget->setTabEnabled(4,false);
  MainTabWidget->setTabEnabled(5,false);
  MainTabWidget->setTabEnabled(6,false);
  MainTabWidget->setTabEnabled(7,false);
  MainTabWidget->setTabEnabled(8,false);
  MainTabWidget->setTabEnabled(9,false);
  MainTabWidget->setTabEnabled(10,false);
  MainTabWidget->setTabEnabled(11,false);
  setPerfTabs(false);
  setPatchTabs(false);
  if (readConfigFile()) return;
  db_connect(db_name, db_user);
  getPort();
  if (!state_table->jv_connect) {
    action_Offline->setChecked(true);
    System_JV_status->off();
    statusbar->showMessage("Failed to load System settings!");
    QMessageBox::critical(this, "JVlib", QString("Failed trying to load System settings.\nIs a valid MIDI port selected?"));
    return;
  }
  createPlayMidi();
  getSeqPort();
  setSystemParms();
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
  strcpy(MIDI_dir, settings.value("JV1080/midi_dir").toByteArray().data());
  PORT_NAME = settings.value("JV1080/port_name").toString();
  state_table->Dev_ID = settings.value("JV1080/Dev_ID", 17).toInt();
  return 0;
}	// end readConfigFile

int JVlibForm::getSeqPort() {
  memset(SEQ_dev,0,sizeof(SEQ_dev));
    // find the desired port in the combo box
    snd_seq_client_info_t *cinfo;
    snd_seq_port_info_t *pinfo;
    snd_seq_client_info_alloca(&cinfo);
    snd_seq_port_info_alloca(&pinfo);
    snd_seq_client_info_set_client(cinfo, -1);
    while (snd_seq_query_next_client(seq, cinfo) >= 0) {
        int client = snd_seq_client_info_get_client(cinfo);
        snd_seq_port_info_set_client(pinfo, client);
        snd_seq_port_info_set_port(pinfo, -1);
        while (snd_seq_query_next_port(seq, pinfo) >= 0) {
            // we need both WRITE and SUBS_WRITE
            if ((snd_seq_port_info_get_capability(pinfo)
                 & (SND_SEQ_PORT_CAP_WRITE | SND_SEQ_PORT_CAP_SUBS_WRITE))
                != (SND_SEQ_PORT_CAP_WRITE | SND_SEQ_PORT_CAP_SUBS_WRITE))
                continue;
            if (PortBox->currentText().contains(QString(snd_seq_port_info_get_name(pinfo)))) {
                QString holdit = QString::number(snd_seq_port_info_get_client(pinfo)) + ":" + QString::number(snd_seq_port_info_get_port(pinfo));
                strcpy(SEQ_dev, holdit.toAscii().data());
                qDebug() << "Selected sequencer port name " << SEQ_dev;
	    }
	}	// end while
    }	// end while
  state_table->jv_connect = true;
  return 0;
}   // end getSeqPort

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


int JVlibForm::db_connect(QString db_name, QString user_name) {
  if (mysql.isOpen()) return EXIT_SUCCESS;
  QSqlDatabase mysql = QSqlDatabase::addDatabase("QMYSQL");
  if (mysql.isValid()) puts("created db connection");
  else puts("invalid db connection");
  mysql.setConnectOptions("UNIX_SOCKET=/var/lib/mysql/mysql.sock");
  mysql.setDatabaseName(db_name);
  mysql.setUserName(user_name);
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

void JVlibForm::getPort() {
  signed int card_num=-1;
  signed int dev_num=-1;
  signed int subdev_num=-1;
  int err,i;
  char	buf[64];
  char	str[64];
  snd_rawmidi_info_t  *rawMidiInfo;
  snd_ctl_t *cardHandle;

  PortBox->clear();
  err = snd_card_next(&card_num);
  if (err < 0) {
    // no MIDI cards found in the system
    puts("No MIDI card found");
    memset(MIDI_dev,0,sizeof(MIDI_dev));
    snd_card_next(&card_num);
    return;
  }
  while (card_num >= 0) {
    // Open this card's control interface. We specify only the card number -- not
    // any device nor sub-device too
    sprintf(str, "hw:%i", card_num);
    if ((err = snd_ctl_open(&cardHandle, str, 0)) < 0) break;
    dev_num = -1;
    err = snd_ctl_rawmidi_next_device(cardHandle, &dev_num);
    if (err < 0) { 
      // card exists, but no midi device was found
      printf("No MIDI device on card #%d\n", card_num);
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
	// Tell ALSA to fill in our snd_rawmidi_info_t with info on this subdevice
	memset(buf,0,sizeof(buf));
	sprintf(buf,"hw:%i,%i,%i %s", card_num, dev_num, i, snd_rawmidi_info_get_subdevice_name(rawMidiInfo));
	PortBox->blockSignals(true);
	PortBox->insertItem(9999, QString::fromAscii(buf));
	PortBox->blockSignals(false);
      }	// end WHILE subdev_num
      snd_ctl_rawmidi_next_device(cardHandle, &dev_num);
    }	// end WHILE dev_num
    snd_ctl_close(cardHandle);
    err = snd_card_next(&card_num);
  }	// end WHILE card_num
  int x = PortBox->findText(PORT_NAME, Qt::MatchContains);
  if (x == -1) {
    puts("Port not found, not connected to JV");
    state_table->jv_connect = false;
  } else {
    state_table->jv_connect = true;
    PortBox->setCurrentIndex(x);	// NOTE: this will trigger the System Sync button
  }
}	// end get_port()
