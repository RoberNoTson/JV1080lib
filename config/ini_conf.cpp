#include "config/ini_conf.h"
#include "ui_ini_conf.h"
#include <alsa/asoundlib.h>

QString INI_CONF::CFGfile = 0;
QString INI_CONF::bakHost = 0;
QString INI_CONF::bakDatabase = 0;
QString INI_CONF::bakUsername = 0;
QString INI_CONF::bakPassword = 0;
QString INI_CONF::bakStartOnline = 0;
QString INI_CONF::bakDumpDir = 0;
QString INI_CONF::bakHelpDir = 0;
QString INI_CONF::bakTempDir = 0;
QString INI_CONF::bakMidiDir = 0;
QString INI_CONF::bakPortname = 0;
QString INI_CONF::bakPortnumber = 0;
int INI_CONF::bakDevID = 0;

INI_CONF::INI_CONF(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::INI_CONF)
{
    ui->setupUi(this);
    CFGfile  = "./test.cfg";
    QSettings settings(CFGfile,QSettings::IniFormat);
    bakHost = settings.value("mysql/host").toString();
    bakDatabase = settings.value("mysql/database").toString();
    bakUsername = settings.value("mysql/username").toString();
    bakPassword = settings.value("mysql/password").toString();
    bakStartOnline = settings.value("JV1080/start_online").toString();
    bakDumpDir = settings.value("JV1080/dump_dir").toString();
    bakHelpDir = settings.value("JV1080/help_dir").toString();
    bakTempDir = settings.value("JV1080/temp_dir").toString();
    bakMidiDir = settings.value("JV1080/midi_dir").toString();
    bakPortname = settings.value("JV1080/port_name").toString();
    bakPortnumber = settings.value("JV1080/port_number").toString();
    bakDevID = settings.value("JV1080/Dev_ID", 17).toInt();

    ui->Host_edit->setText(bakHost);
    ui->Database_edit->setText(bakDatabase);
    ui->Username_edit->setText(bakUsername);
    ui->Password_edit->setText(bakPassword);
    ui->DumpDir_edit->setText(bakDumpDir);
    ui->HelpDir_edit->setText(bakHelpDir);
    ui->TempDir_edit->setText(bakTempDir);
    ui->MidiDir_edit->setText(bakMidiDir);
    ui->DevID->setValue(bakDevID);
    if (bakStartOnline[0]=='y' || bakStartOnline[0]=='y' ||bakStartOnline[0]=='1' ||bakStartOnline[0]=='t' ||bakStartOnline[0]=='T')
        ui->StartOnline_select->setChecked(true);
    else if (bakStartOnline[0]=='n' || bakStartOnline[0]=='N' ||bakStartOnline[0]=='0' ||bakStartOnline[0]=='f' ||bakStartOnline[0]=='F')
        ui->StartOnline_select->setChecked(false);
    else if (settings.contains("JV1080/start_online")) {
        ui->StartOnline_select->setChecked(false);
        QMessageBox::critical(this, "CONFIG", QString("Invalid value for start_online\n%1") .arg(bakStartOnline));
    }
    if (ui->ShowPassword_select->isChecked())
        ui->Password_edit->setEchoMode(QLineEdit::Normal);
    else
        ui->Password_edit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    ui->PortName_select->blockSignals(true);
    ui->PortNumber_select->blockSignals(true);
    getPort();
    if (bakPortname.length()) {
        int x = ui->PortName_select->findText(bakPortname);
        if (x>=0) ui->PortName_select->setCurrentIndex(x);
        else {
            ui->PortName_select->blockSignals(true);
            ui->PortName_select->insertItem(0,"");
            ui->PortName_select->setCurrentIndex(0);
            ui->PortName_select->blockSignals(false);
        }
    } else {
        ui->PortName_select->setCurrentIndex(0);
    }
    if (bakPortnumber.length()) {
        int x = ui->PortNumber_select->findText(bakPortnumber);
        if (x>=0) ui->PortNumber_select->setCurrentIndex(x);
        else {
            ui->PortNumber_select->blockSignals(true);
            ui->PortNumber_select->insertItem(0,"");
            ui->PortNumber_select->setCurrentIndex(0);
            ui->PortNumber_select->blockSignals(false);
        }
    } else {
        ui->PortNumber_select->setCurrentIndex(0);
    }
    ui->PortName_select->blockSignals(false);
    ui->PortNumber_select->blockSignals(false);
    ui->buttonBox->setFocus();
}

INI_CONF::~INI_CONF()
{
    QFileInfo fn(CFGfile);
    if (fn.exists()) {
    QSettings settings(CFGfile,QSettings::IniFormat);
    if (!settings.contains("mysql/host"))
        settings.setValue("mysql/host","localhost");
    if (!settings.contains("mysql/database"))
        settings.setValue("mysql/database","JV1080");
    if (!settings.contains("mysql/username"))
        settings.setValue("mysql/username","");
    if (!settings.contains("mysql/password"))
        settings.setValue("mysql/password","");
    if (!settings.contains("JV1080/start_online"))
        settings.setValue("JV1080/start_online","false");
    if (!settings.contains("JV1080/dump_dir"))
        settings.setValue("JV1080/dump_dir","dumps");
    if (!settings.contains("JV1080/temp_dir"))
        settings.setValue("JV1080/temp_dir","/temp");
    if (!settings.contains("JV1080/help_dir"))
        settings.setValue("JV1080/help_dir","help");
    if (!settings.contains("JV1080/midi_dir"))
        settings.setValue("JV1080/midi_dir","");
    }   // end fn.exists
    delete ui;
}

void INI_CONF::on_Host_edit_editingFinished()
{
    QSettings settings(CFGfile,QSettings::IniFormat);
    settings.setValue("mysql/host",ui->Host_edit->text());
}

void INI_CONF::on_Username_edit_editingFinished()
{
    QSettings settings(CFGfile,QSettings::IniFormat);
    settings.setValue("mysql/username",ui->Username_edit->text());
}

void INI_CONF::on_Database_edit_editingFinished()
{
    QSettings settings(CFGfile,QSettings::IniFormat);
    settings.setValue("mysql/database",ui->Database_edit->text());
}

void INI_CONF::on_Password_edit_editingFinished()
{
  QSettings settings(CFGfile,QSettings::IniFormat);
  settings.setValue("mysql/password",ui->Password_edit->text());
}

void INI_CONF::on_TempDir_edit_editingFinished()
{
    QSettings settings(CFGfile,QSettings::IniFormat);
    settings.setValue("JV1080/temp_dir",ui->TempDir_edit->text());
}

void INI_CONF::on_HelpDir_edit_editingFinished()
{
    QSettings settings(CFGfile,QSettings::IniFormat);
    settings.setValue("JV1080/help_dir",ui->HelpDir_edit->text());
}

void INI_CONF::on_DumpDir_edit_editingFinished()
{
    QSettings settings(CFGfile,QSettings::IniFormat);
    settings.setValue("JV1080/dump_dir",ui->DumpDir_edit->text());
}

void INI_CONF::on_MidiDir_edit_editingFinished()
{
    QSettings settings(CFGfile,QSettings::IniFormat);
    settings.setValue("JV1080/midi_dir",ui->MidiDir_edit->text());
}

void INI_CONF::on_StartOnline_select_toggled(bool checked)
{
    QSettings settings(CFGfile,QSettings::IniFormat);
    if (checked)
        settings.setValue("JV1080/start_online","true");
    else
        settings.setValue("JV1080/start_online","false");
}

void INI_CONF::on_buttonBox_accepted()
{
    QSettings settings(CFGfile,QSettings::IniFormat);
    settings.sync();
    this->close();
}

void INI_CONF::on_buttonBox_rejected()
{
this->close();
}

void INI_CONF::on_buttonBox_clicked(QAbstractButton* button)
{
    if (ui->buttonBox->standardButton(button)==QDialogButtonBox::Reset) {
        ui->Host_edit->setText(bakHost);
        ui->Database_edit->setText(bakDatabase);
        ui->Username_edit->setText(bakUsername);
        ui->Password_edit->setText(bakPassword);
        ui->DumpDir_edit->setText(bakDumpDir);
        ui->HelpDir_edit->setText(bakHelpDir);
        ui->TempDir_edit->setText(bakTempDir);
        ui->MidiDir_edit->setText(bakMidiDir);
        if (bakStartOnline[0]=='y' || bakStartOnline[0]=='y' ||bakStartOnline[0]=='1' ||bakStartOnline[0]=='t' ||bakStartOnline[0]=='T')
            ui->StartOnline_select->setChecked(true);
        else if (bakStartOnline[0]=='n' || bakStartOnline[0]=='N' ||bakStartOnline[0]=='0' ||bakStartOnline[0]=='f' ||bakStartOnline[0]=='F')
            ui->StartOnline_select->setChecked(false);
        else {
            ui->StartOnline_select->setChecked(false);
        }
        QSettings settings(CFGfile,QSettings::IniFormat);
        settings.setValue("mysql/host",bakHost);
        settings.setValue("mysql/database",bakDatabase);
        settings.setValue("mysql/username",bakUsername);
        settings.setValue("mysql/password",bakPassword);
        settings.setValue("JV1080/dump_dir",bakDumpDir);
        settings.setValue("JV1080/help_dir",bakHelpDir);
        settings.setValue("JV1080/temp_dir",bakTempDir);
        settings.setValue("JV1080/midi_dir",bakMidiDir);
        settings.setValue("JV1080/port_number",bakPortnumber);
        settings.setValue("JV1080/port_name",bakPortname);
        settings.setValue("JV1080/start_online",bakStartOnline);
        settings.sync();
    }
}

void INI_CONF::on_ShowPassword_select_toggled(bool checked)
{
    if (checked)
        ui->Password_edit->setEchoMode(QLineEdit::Normal);
    else
        ui->Password_edit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
}

void INI_CONF::setData(QString cfile) {
  CFGfile = cfile;
}
void INI_CONF::on_PortName_select_currentIndexChanged(QString pname)
{
    QSettings settings(CFGfile,QSettings::IniFormat);
    if (ui->UsePortname_button->isChecked())
        settings.setValue("JV1080/port_name", pname);
}

void INI_CONF::on_PortNumber_select_currentIndexChanged(QString pname)
{
    QSettings settings(CFGfile,QSettings::IniFormat);
    if (ui->UsePortnumber_button->isChecked())
       settings.setValue("JV1080/port_number", pname);
}


void INI_CONF::on_PortSelect_buttonGroup_buttonClicked(QAbstractButton * button)
{
    QSettings settings(CFGfile,QSettings::IniFormat);
    if (button->objectName() == "UsePortname_button") {
        settings.setValue("JV1080/port_name", ui->PortName_select->currentText());
        settings.remove("JV1080/port_number");
    }
    if (button->objectName() == "UsePortnumber_button") {
        settings.setValue("JV1080/port_number", ui->PortNumber_select->currentText());
        settings.remove("JV1080/port_name");
    }
}

void INI_CONF::getPort() {
  signed int card_num=-1;
  signed int dev_num=-1;
  signed int subdev_num=-1;
  int err,i;
  char	buf[64];
  char	str[64];
  snd_rawmidi_info_t  *rawMidiInfo;
  snd_ctl_t *cardHandle;
  using namespace Ui;

  ui->PortName_select->clear();
  ui->PortNumber_select->clear();
  err = snd_card_next(&card_num);
  if (err < 0) {
    // no MIDI cards found in the system
    QMessageBox::critical(this, "CONFIG", QString("No MIDI cards found"));
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
      QMessageBox::critical(this, "CONFIG", QString("A sound card is installed but no MIDI devices were found on the card"));
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
          // Tell ALSA to fill in our snd_rawmidi_info_t with info on this subdevice
          memset(buf,0,sizeof(buf));
          sprintf(buf,"hw:%i,%i,%i", card_num, dev_num, i);
          ui->PortNumber_select->insertItem(9999, QString::fromAscii(buf));
          ui->PortName_select->insertItem(9999, QString::fromAscii(snd_rawmidi_info_get_subdevice_name(rawMidiInfo)));
      }	// end WHILE subdev_num
      snd_ctl_rawmidi_next_device(cardHandle, &dev_num);
  }	// end WHILE dev_num
  snd_ctl_close(cardHandle);
  err = snd_card_next(&card_num);
  }	// end WHILE card_num
}	// end get_port()

void INI_CONF::on_DevID_valueChanged(int id) {
    QSettings settings(CFGfile,QSettings::IniFormat);
    settings.setValue("JV1080/Dev_ID",id);
}