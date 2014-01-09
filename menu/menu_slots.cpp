// menu_slots.cpp
/* Contains:
 * HelpDoc()
 * selectedPort()
 * slotOffline()
 * slotactionWhats_This()
 * slotactionBulk_Dump()
 * slotactionWrite()
 * slotactionCopy()
 * slotDB_Maint()
 * slotConfig()
 * open()
 * save()
 * saveAs()
 * about()
 * on_actionData_Lists_triggered()
 */

#include	"JVlibForm.h"
#include	<QtGui>
#include	"config/ini_conf.h"
#include	"save_dialog/Save_Dialog.h"
#include	"load_dialog/load_dialog.h"
#include	"data_list/data_list.h"

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

void JVlibForm::slotOffline(bool checked) {
  state_table->jv_connect = !checked;
  statusbar->showMessage(checked?"Offline":"Online");
  if (!checked) {
    System_JV_status->on();
    on_System_Sync_button_clicked();
  }
  else {
    System_JV_status->off();
    System_Sync_status->off();
    EnablePerf(true);
    EnablePatch(true);
  }
}

void JVlibForm::slotactionWhats_This() {
  QWhatsThis::enterWhatsThisMode ();
}

void JVlibForm::slotactionBulk_Dump() {
  // NOTE: tbd
}
void JVlibForm::slotactionWrite() {
  if (!state_table->jv_connect) return;
  QMessageBox msgBox;
  msgBox.setText("Write current settings to the JV-1080");
  if (state_table->perf_mode)
    msgBox.setInformativeText(QString("Overwrite settings for\nUser Performance %1?") .arg(SysPerfNumber->value() ));
  if (state_table->patch_mode)
    msgBox.setInformativeText(QString("Overwrite settings for\nUser Patch %1?") .arg(SysPatchNumber->value() ));
  if (state_table->rhythm_mode)
    msgBox.setInformativeText(QString("Overwrite settings for\nUser Rhythm %1?") .arg(Rhythm_PatchNumber_select->value() ));
  msgBox.setDetailedText("CAUTION!\nClicking the Apply button will permanently write the current settings to the designated User area. It will overwrite the existing settings for that number.");
  msgBox.setIcon(QMessageBox::Question);
  msgBox.setStandardButtons(QMessageBox::Apply | QMessageBox::Cancel);
  msgBox.setDefaultButton(QMessageBox::Apply);
  int ret = msgBox.exec();
  switch(ret) {
    case QMessageBox::Apply:
      if (QMessageBox::warning(this, "JVlib", "Confirm overwritting the existing settings",QMessageBox::Ok | QMessageBox::Cancel,QMessageBox::Ok) == QMessageBox::Cancel) break;
      // do the upload
      puts("Uploading current settings");

      break;
    case QMessageBox::Cancel:
      // do nothing
      puts("Upload cancelled");
      break;
    default:
      // should never happen
      puts("How did we get here?");
      break;
  }
}
void JVlibForm::slotactionCopy() {
  // NOTE: tbd  
}
void JVlibForm::slotDB_Maint() {
  // NOTE: tbd  
}

void  JVlibForm::slotConfig() {
  // pop up a text editor dialog box for the configuration file
  INI_CONF ini_conf;
  ini_conf.setData(CFGfile);
  ini_conf.exec();
}

bool JVlibForm::open() {
  if (state_table->db_connect) {
    Load_Dialog load_dialog;
    connect(&load_dialog, SIGNAL(System_Loaded()), this, SLOT(System_Loaded()) );
    connect(&load_dialog, SIGNAL(Tuning_Loaded(int)), this, SLOT(Tuning_Loaded(int)) );
    if (!load_dialog.exec())
      return false;
  }
  else {
    QString fileName = QFileDialog::getOpenFileName(this);
    if (fileName.isEmpty())
      return false;
    loadFile(fileName);
  }
  return true;
}

bool JVlibForm::save() {
  if (state_table->db_connect) {
    Save_Dialog save_dialog;
    if (!save_dialog.exec())
      return false;
  } 
  else {
    if (curFile.isEmpty())
      return saveAs();
    else
      return saveFile(curFile);
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

void JVlibForm::on_actionData_Lists_triggered() {
  Data_List.show();
  Data_List.raise();
  Data_List.activateWindow();
}
