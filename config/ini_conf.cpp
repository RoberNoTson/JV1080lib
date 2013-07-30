#include "config/ini_conf.h"
#include "ui_ini_conf.h"

QString INI_CONF::CFGfile = 0;
QString INI_CONF::bakHost = 0;
QString INI_CONF::bakDatabase = 0;
QString INI_CONF::bakUsername = 0;
QString INI_CONF::bakPassword = 0;
QString INI_CONF::bakStartOnline = 0;
QString INI_CONF::bakDumpDir = 0;
QString INI_CONF::bakHelpDir = 0;
QString INI_CONF::bakTempDir = 0;
QString INI_CONF::bakPortname = 0;

INI_CONF::INI_CONF(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::INI_CONF)
{
    ui->setupUi(this);
    if (ui->ShowPassword_select->isChecked())
        ui->Password_edit->setEchoMode(QLineEdit::Normal);
    else
        ui->Password_edit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    CFGfile  = "./test.cfg";
    // make a backup of the file
    //    QFile bakFile(CFGfile+".old");
    //    QFile cfgFile(CFGfile);
    //    if (bakFile.exists()) bakFile.remove();
    //    cfgFile.copy(CFGfile+".old");
    QSettings settings(CFGfile,QSettings::IniFormat);
    bakHost = settings.value("mysql/host").toString();
    bakDatabase = settings.value("mysql/database").toString();
    bakUsername = settings.value("mysql/username").toString();
    bakPassword = settings.value("mysql/password").toString();
    bakStartOnline = settings.value("JV1080/start_online").toString();
    bakDumpDir = settings.value("JV1080/dump_dir").toString();
    bakHelpDir = settings.value("JV1080/help_dir").toString();;
    bakTempDir = settings.value("JV1080/temp_dir").toString();;
    bakPortname = settings.value("JV1080/port_name").toString();;

    ui->Host_edit->setText(bakHost);
    ui->Database_edit->setText(bakDatabase);
    ui->Username_edit->setText(bakUsername);
    ui->Password_edit->setText(bakPassword);
    ui->Portname_edit->setText(bakPortname);
    ui->DumpDir_edit->setText(bakDumpDir);
    ui->HelpDir_edit->setText(bakHelpDir);
    ui->TempDir_edit->setText(bakTempDir);
    if (bakStartOnline[0]=='y' || bakStartOnline[0]=='y' ||bakStartOnline[0]=='1' ||bakStartOnline[0]=='t' ||bakStartOnline[0]=='T')
        ui->StartOnline_select->setChecked(true);
    else if (bakStartOnline[0]=='n' || bakStartOnline[0]=='N' ||bakStartOnline[0]=='0' ||bakStartOnline[0]=='f' ||bakStartOnline[0]=='F')
        ui->StartOnline_select->setChecked(false);
    else {
        ui->StartOnline_select->setChecked(false);
        QMessageBox::critical(this, "CONFIG", QString("Invalid value for start_online\n%1") .arg(bakStartOnline));
    }
}

INI_CONF::~INI_CONF()
{
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

void INI_CONF::on_Portname_edit_editingFinished()
{
  QSettings settings(CFGfile,QSettings::IniFormat);
  settings.setValue("JV1080/port_name",ui->Portname_edit->text());
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
        QSettings settings(CFGfile,QSettings::IniFormat);
        settings.setValue("mysql/host",bakHost);
        settings.setValue("mysql/database",bakDatabase);
        settings.setValue("mysql/username",bakUsername);
        settings.setValue("mysql/password",bakPassword);
        settings.setValue("JV1080/dump_dir",bakDumpDir);
        settings.setValue("JV1080/help_dir",bakHelpDir);
        settings.setValue("JV1080/temp_dir",bakTempDir);
        settings.setValue("JV1080/port_name",bakPortname);
        settings.setValue("JV1080/start_online",bakStartOnline);
        settings.sync();
        ui->Host_edit->setText(bakHost);
        ui->Database_edit->setText(bakDatabase);
        ui->Username_edit->setText(bakUsername);
        ui->Password_edit->setText(bakPassword);
        ui->Portname_edit->setText(bakPortname);
        ui->DumpDir_edit->setText(bakDumpDir);
        ui->HelpDir_edit->setText(bakHelpDir);
        ui->TempDir_edit->setText(bakTempDir);
        if (bakStartOnline[0]=='y' || bakStartOnline[0]=='y' ||bakStartOnline[0]=='1' ||bakStartOnline[0]=='t' ||bakStartOnline[0]=='T')
            ui->StartOnline_select->setChecked(true);
        else if (bakStartOnline[0]=='n' || bakStartOnline[0]=='N' ||bakStartOnline[0]=='0' ||bakStartOnline[0]=='f' ||bakStartOnline[0]=='F')
            ui->StartOnline_select->setChecked(false);
        else {
            ui->StartOnline_select->setChecked(false);
            QMessageBox::critical(this, "CONFIG", QString("Invalid value for start_online\n%1") .arg(bakStartOnline));
        }
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
