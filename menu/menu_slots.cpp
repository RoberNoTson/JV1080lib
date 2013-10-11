// menu_slots.cpp
#include	"JVlibForm.h"
#include	<QtGui>
#include	"config/ini_conf.h"
#include	"save_dialog/Save_Dialog.h"
#include	"load_dialog/load_dialog.h"

QSqlDatabase JVlibForm::db_mysql;

void JVlibForm::HelpDoc() {
  QProcess process;
  switch(MainTabWidget->currentIndex()) {
    case 0:
      process.startDetached("evince --page-index=66 "+qApp->applicationDirPath() +"/doc/JV-1080_OM.pdf");
      break;
    case 1:
      process.startDetached("evince --page-index=57 "+qApp->applicationDirPath() +"/doc/JV-1080_OM.pdf");
      break;
    case 2:
      process.startDetached("evince --page-index=59 "+qApp->applicationDirPath() +"/doc/JV-1080_OM.pdf");
      break;
    case 3:
      process.startDetached("evince --page-index=42 "+qApp->applicationDirPath() +"/doc/JV-1080_OM.pdf");
      break;
    case 4:
      process.startDetached("evince --page-index=45 "+qApp->applicationDirPath() +"/doc/JV-1080_OM.pdf");
      break;
    case 5:
      process.startDetached("evince --page-index=50 "+qApp->applicationDirPath() +"/doc/JV-1080_OM.pdf");
      break;
    case 6:
      process.startDetached("evince --page-index=51 "+qApp->applicationDirPath() +"/doc/JV-1080_OM.pdf");
      break;
    case 7:
      process.startDetached("evince --page-index=54 "+qApp->applicationDirPath() +"/doc/JV-1080_OM.pdf");
      break;
    case 8:
      process.startDetached("evince --page-index=61 "+qApp->applicationDirPath() +"/doc/JV-1080_OM.pdf");
      break;
    case 9:
      process.startDetached("evince --page-index=53 "+qApp->applicationDirPath() +"/doc/JV-1080_OM.pdf");
      break;
    case 10:
      process.startDetached("evince --page-index=68 "+qApp->applicationDirPath() +"/doc/JV-1080_OM.pdf");
      break;
    default:
      process.startDetached("evince --page-index=20 "+qApp->applicationDirPath() +"/doc/JV-1080_OM.pdf");
      break;
  }
}

void JVlibForm::selectedPort()  {
  menu_Setup->hide();
  QByteArray buf(PortBox->currentText().toAscii(),8);
  strcpy(MIDI_dev, buf.data());
  state_table->jv_connect = true;
  if (on_System_Sync_button_clicked() != EXIT_SUCCESS) {
    action_Offline->setChecked(true);
    System_JV_status->off();
    state_table->jv_connect = false;
    statusbar->showMessage("Failed to load System settings!");
    QMessageBox::critical(this, "JVlib", QString("Failed trying to load System settings.\nIs a valid MIDI port selected?"));
  }
}  // end selectedPort

void JVlibForm::slotOffline() {
  state_table->jv_connect = !(action_Offline->isChecked());
  statusbar->showMessage(state_table->jv_connect?"Online":"Offline");
  if (state_table->jv_connect) System_JV_status->on();
  else System_JV_status->off();
}
void JVlibForm::slotactionWhats_This() {
  QWhatsThis::enterWhatsThisMode ();
}

void JVlibForm::slotactionBulk_Dump() {
  
}
void JVlibForm::slotactionWrite() {
  
}
void JVlibForm::slotactionCopy() {
  
}

void  JVlibForm::slotConfig() {
  // pop up a text editor dialog box for the configuration file
  INI_CONF ini_conf;
  ini_conf.setData(CFGfile);
  ini_conf.exec();
}

bool JVlibForm::open() {
//    if (maybeSave()) {
      if (!state_table->db_connect) {
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty())
            loadFile(fileName);
	else
	  return false;
      }
      else {
	Load_Dialog load_dialog;
	if (!load_dialog.exec())
	  return false;
      }
//   }	// end maybeSave
  return true;
}

bool JVlibForm::save() {
  if (!state_table->db_connect) {
    if (curFile.isEmpty()) {
        return saveAs();
    } 
    else {
        return saveFile(curFile);
    }
  } 
  else {
    Save_Dialog save_dialog;
    if (!save_dialog.exec())
      return false;
  }
  return true;
}

bool JVlibForm::saveAs() {
    QString fileName = QFileDialog::getSaveFileName(this);
    if (fileName.isEmpty())
        return false;
    return saveFile(fileName);
}

void JVlibForm::about() {
   QMessageBox::about(this, "About JVlib",
            "<center><b>JV-1080</b></center><center>Synthesizer controller and library </center>"
               "<center>Created by Mark Roberson </center>"
               "<center>Copyright 2013, all rights reserved</center>");
}

