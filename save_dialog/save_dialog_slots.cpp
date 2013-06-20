// save_dialog_slots.cpp
#include        "JVlibForm.h"
#include        <QtGui>

// initialize the static pointers.
struct SYSTEM_AREA *JVlibForm::sys_area = 0;
struct ACTIVE_AREA *JVlibForm::act_area = 0;
QSqlDatabase JVlibForm::db_mysql;

void Save_Dialog::slotSave_System(bool val) {
  if (val) {
    QString buf = "System_"+QDate::currentDate().toString(Qt::ISODate);
    Save_Name_edit->setText(buf);    
  }
}
void Save_Dialog::slotSave_Performance(bool val) {
  if (val) {
    QString buf;
    int pn = JVlibForm::sys_area->sys_common.perf_num;
    if (pn < 0x20) 
      buf = "User_"+QString::number(pn+1);
    else if (pn < 0x40) 
      buf = "PCM_Card_"+QString::number(pn-0x1F);
    else if (pn < 0x60) 
      buf = "Preset_A_"+QString::number(pn-0x3F);
    else if (pn < 0x80)
      buf = "Preset_B_"+QString::number(pn-0x5F);
    else	// invalid value, maybe we aren't in perf mode
      return;
    buf += "_";
    buf += QString::fromAscii(&JVlibForm::act_area->active_performance.perf_common.name[0],12).trimmed();
    buf += "_";
    buf += QDate::currentDate().toString(Qt::ISODate);
    Save_Name_edit->setText(buf);
  }
} 
void Save_Dialog::slotSave_Patch(bool val) {
  if (val) {
    QString buf;
    switch(JVlibForm::sys_area->sys_common.patch_group_id) {
    case 0x01:  // User
      buf = "User_";
      break;
    case 0x02:  // Exp A
      buf = "Expansion_A_";
      break;
    case 0x03:  // Preset A
      buf = "Preset_A_";
      break;
    case 0x04:  // Preset B
      buf = "Preset_B_";
      break;
    case 0x05:  // Preset C
      buf = "Preset_C_";
      break;
    case 0x06:  // Preset D
      buf = "Preset_D_";
      break;
    case 0x10:  // Exp B
      buf = "Expansion_B_";
      break;
    case 0x62:  // Exp C
      buf = "Expansion_C_";
      break;
    }
    buf += QString::number(JVlibForm::sys_area->sys_common.patch_num_high*16 + JVlibForm::sys_area->sys_common.patch_num_low+1)+"_";
    buf += QString::fromAscii(&JVlibForm::act_area->active_patch_patch.patch_common.name[0],12).trimmed();
    buf += "_";
    buf += QDate::currentDate().toString(Qt::ISODate);
    Save_Name_edit->setText(buf);
  }
}
void Save_Dialog::slotSave_Rhythm(bool val) {
  if (val) {
    QString buf;
    switch (JVlibForm::act_area->active_performance.perf_part[9].patch_group_id) {
      case 0x01:  // User
	buf = "User_";
	break;
      case 0x02:  // Exp A
	buf = "Expansion_A_";
	break;
      case 0x03:  // Preset A
	buf = "Preset_A_";
	break;
      case 0x04:  // Preset B
	buf = "Preset_B_";
	break;
      case 0x05:  // Preset C
	buf = "Preset_C_";
	break;
      case 0x06:  // Preset D
	buf = "Preset_D_";
	break;
      case 0x10:  // Exp B
	buf = "Expansion_B_";
	break;
      case 0x62:  // Exp C
	buf = "Expansion_C_";
	break;
    }
    buf += QString::number(JVlibForm::act_area->active_performance.perf_part[9].patch_num_high*16 + JVlibForm::act_area->active_performance.perf_part[9].patch_num_low+1)+"_";
    buf += QString::fromAscii(&JVlibForm::act_area->active_rhythm.rhythm_common.name[0],12).trimmed();
    buf += "_";
    buf += QDate::currentDate().toString(Qt::ISODate);
    Save_Name_edit->setText(buf);
    
  }
}
void Save_Dialog::slotSave_Tuning(bool val) {
  if (val) {
  }
}

void Save_Dialog::slotSave_UserPerformance(bool val) {
  if (val) {
  }
}
void Save_Dialog::slotSave_UserPatch(bool val) {
  if (val) {
  }
}
void Save_Dialog::slotSave_UserRhythm(bool val) {
  if (val) {
  }
}
void Save_Dialog::slotSave_UserDump(bool val) {
  if (val) {
    QString buf = "User_Dump_"+QDate::currentDate().toString(Qt::ISODate);
    buf += "_";
    buf += QDate::currentDate().toString(Qt::ISODate);
    Save_Name_edit->setText(buf);
  }
}
  
void Save_Dialog::slotSaveDialog_accept() {
  // Save_comments are optional, but recommended
  QString table_name;
  int sz = 0;
  char *ptr = NULL;
  if (Save_Comment_edit->text().isEmpty()) {
    Save_Comment_edit->setPlaceholderText("Optional comment describing this data");
    Save_buttonBox->setFocus();
  }
  // must have a name specified
  if (Save_Name_edit->text().isEmpty()) {
//    Save_Name_edit->setFocus();
    Save_Name_edit->setPlaceholderText("Enter a valid name");
    Save_Comment_edit->setFocus();
    return;
  }
  if (Save_System_button->isChecked()) {
    table_name = "Dumps";
    sz = 0x28;
    ptr = &JVlibForm::sys_area->sys_common.panel_mode;
  }
  if (Save_CurrentPerformance_button->isChecked()) {
    table_name = "Performances";
    sz = 0x40+(0x13*16);
    ptr = &JVlibForm::act_area->active_performance.perf_common.name[0];
  }
  if (Save_CurrentPatch_button->isChecked()) {
    table_name = "Patches";
    sz = 0x48 + (0x81*4);
    ptr = &JVlibForm::act_area->active_patch_patch.patch_common.name[0];    
  }
  if (Save_CurrentRhythm_button->isChecked()) {
    table_name = "RhythmSets";
    sz = 0x0C + (0x3A*64);
    ptr = &JVlibForm::act_area->active_rhythm.rhythm_common.name[0];
  }
  if (Save_CurrentTuning_button->isChecked()) {
    table_name = "Tuning";
    sz = 0;	// NOTE: tbd
    ptr = NULL;	// NOTE: tbd
  }
  if (Save_UserPerformance_button->isChecked()) {
    table_name = "Dumps";
    sz = 0;	// NOTE: tbd
    ptr = NULL;	// NOTE: tbd
  }
  if (Save_UserPatch_button->isChecked()) {
    table_name = "Dumps";
    sz = 0;	// NOTE: tbd
    ptr = NULL;	// NOTE: tbd
  }
  if (Save_UserRhythm_button->isChecked()) {
    table_name = "Dumps";
    sz = 0;	// NOTE: tbd
    ptr = NULL;	// NOTE: tbd
  }
  if (Save_UserDump_button->isChecked()) {
    table_name = "Dumps";
    sz = 0;	// NOTE: tbd
    ptr = NULL;	// NOTE: tbd
  }
  // create a temp file
//  QTemporaryFile file;
  QFile file("/Data/music/jv1080/asdf");
//  if (!file.open()) {
  if (!file.open(QIODevice::WriteOnly|QIODevice::Truncate)) {
    QMessageBox::critical(this, "Save Dialog", tr("Could not create a temporary file!"));
    return;
  }
  // write selected data to file.fileName()
  QDataStream out(&file);
  if (out.writeRawData(ptr, sz) != sz) {
    QMessageBox::critical(this, "Save Dialog", tr("Could not write to temporary file!"));
    return;
  }
  file.close();
  file.setPermissions(QFile::ReadOwner|QFile::WriteOwner|QFile::ReadGroup|QFile::ReadOther);
  // load the temp file into the db
  QSqlQuery query(JVlibForm::db_mysql);
  QString buf = "insert into "+table_name+" values('"+Save_Name_edit->text()+"', LOAD_FILE('"+file.fileName()+"'), DEFAULT, '"+Save_Comment_edit->text()+"')";
  if (query.exec(buf) == false) {
    puts("Query exec failed");
    query.finish();
    return;
  }
  query.finish();
  this->close();
}	// end slotSaveDialog_accept

void Save_Dialog::slotSaveDialog_cancel() {
  this->close();
}

void Save_Dialog::slotSaveDialog_help() {
  QMessageBox::critical(this, "Save Dialog", "Help not yet available for this function");
}

