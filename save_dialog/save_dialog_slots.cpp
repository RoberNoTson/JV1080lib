// save_dialog_slots.cpp
// Create and display a valid Name for the selected option.
// Contains:
//	on_Save_System_button_toggled()
//	on_Save_PerfPatch_All_select_toggled()
//	on_Save_CurrentPerformance_button_toggled()
//	on_Save_CurrentPatch_button_toggled()
//	on_Save_CurrentRhythm_button_toggled()
//	on_Save_CurrentTuning_button_toggled()
//	on_Save_UserPerformance_button_toggled()
//	on_Save_UserPatch_button_toggled()
//	on_Save_UserRhythm_button_toggled()
//	on_Save_UserDump_button_toggled()
//	on_Save_buttonBox_rejected()
//	on_Save_buttonBox_helpRequested()
//	on_Save_buttonBox_accepted()
//	on_Save_RhythmNumber_select_valueChanged()
//	on_Save_PatchNumber_select_valueChanged()
//	on_Save_PerfNumber_select_valueChanged()
//	on_Save_All_button_toggled()
//	on_Save_ReceiveUserDump_button_toggled()

#include	"save_dialog/Save_Dialog.h"
#include	"ui_Save_Dialog.h"
#include        "JVlibForm.h"
#include        <QtGui>
#include	<QtSql>
//#include        "ui_JVlib.h"

void Save_Dialog::on_Save_PerfPatch_All_select_toggled(bool val) {
  ui->Save_PerfPatch_1_select->setChecked(val && ui->Save_PerfPatch_1_select->isEnabled());
  ui->Save_PerfPatch_2_select->setChecked(val && ui->Save_PerfPatch_2_select->isEnabled());
  ui->Save_PerfPatch_3_select->setChecked(val && ui->Save_PerfPatch_3_select->isEnabled());
  ui->Save_PerfPatch_4_select->setChecked(val && ui->Save_PerfPatch_4_select->isEnabled());
  ui->Save_PerfPatch_5_select->setChecked(val && ui->Save_PerfPatch_5_select->isEnabled());
  ui->Save_PerfPatch_6_select->setChecked(val && ui->Save_PerfPatch_6_select->isEnabled());
  ui->Save_PerfPatch_7_select->setChecked(val && ui->Save_PerfPatch_7_select->isEnabled());
  ui->Save_PerfPatch_8_select->setChecked(val && ui->Save_PerfPatch_8_select->isEnabled());
  ui->Save_PerfPatch_9_select->setChecked(val && ui->Save_PerfPatch_9_select->isEnabled());
  ui->Save_PerfPatch_10_select->setChecked(val && ui->Save_PerfPatch_10_select->isEnabled());
  ui->Save_PerfPatch_11_select->setChecked(val && ui->Save_PerfPatch_11_select->isEnabled());
  ui->Save_PerfPatch_12_select->setChecked(val && ui->Save_PerfPatch_12_select->isEnabled());
  ui->Save_PerfPatch_13_select->setChecked(val && ui->Save_PerfPatch_13_select->isEnabled());
  ui->Save_PerfPatch_14_select->setChecked(val && ui->Save_PerfPatch_14_select->isEnabled());
  ui->Save_PerfPatch_15_select->setChecked(val && ui->Save_PerfPatch_15_select->isEnabled());
  ui->Save_PerfPatch_16_select->setChecked(val && ui->Save_PerfPatch_16_select->isEnabled());
}

void Save_Dialog::on_Save_CurrentPerformance_button_toggled(bool val) {
  ui->Save_PerfPatch_box->setEnabled(val);
  if (!val) return;
  // create valid Name and fill in the Name_edit field
  QString buf;
  // fill in the Name box
  int pn = JVlibForm::system_area->sys_common.perf_num;
  if (pn < 0x20) 
      buf = "User "+QString::number(pn+1);
  else if (pn < 0x40) 
      buf = "PCM_Card "+QString::number(pn-0x1F);
  else if (pn < 0x60) 
      buf = "Preset_A "+QString::number(pn-0x3F);
  else if (pn < 0x80)
      buf = "Preset_B "+QString::number(pn-0x5F);
  else	// invalid value, maybe we aren't in perf mode
      return;
  buf += " ";
  buf += QString::fromAscii(&JVlibForm::active_area->active_performance.perf_common.name[0],12).trimmed();
  ui->Save_Name_edit->setText(buf);
  // enable checkbox if the Part is a User Patch
  ui->Save_PerfPatch_1_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[0].patch_group_id==1);
  ui->Save_PerfPatch_2_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[1].patch_group_id==1);
  ui->Save_PerfPatch_3_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[2].patch_group_id==1);
  ui->Save_PerfPatch_4_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[3].patch_group_id==1);
  ui->Save_PerfPatch_5_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[4].patch_group_id==1);
  ui->Save_PerfPatch_6_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[5].patch_group_id==1);
  ui->Save_PerfPatch_7_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[6].patch_group_id==1);
  ui->Save_PerfPatch_8_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[7].patch_group_id==1);
  ui->Save_PerfPatch_9_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[8].patch_group_id==1);
  ui->Save_PerfPatch_10_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[9].patch_group_id==1);
  ui->Save_PerfPatch_11_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[10].patch_group_id==1);
  ui->Save_PerfPatch_12_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[11].patch_group_id==1);
  ui->Save_PerfPatch_13_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[12].patch_group_id==1);
  ui->Save_PerfPatch_14_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[13].patch_group_id==1);
  ui->Save_PerfPatch_15_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[14].patch_group_id==1);
  ui->Save_PerfPatch_16_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[15].patch_group_id==1);
  // fill in the User Patch numbers/names
  if (ui->Save_PerfPatch_1_select->isEnabled()) {
      ui->Save_Part_1_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[0].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[0].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[0].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPatch_2_select->isEnabled()) {
      ui->Save_Part_2_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[1].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[1].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[1].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPatch_3_select->isEnabled()) {
      ui->Save_Part_3_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[2].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[2].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[2].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPatch_4_select->isEnabled()) {
      ui->Save_Part_4_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[3].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[3].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[3].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPatch_5_select->isEnabled()) {
      ui->Save_Part_5_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[4].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[4].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[4].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPatch_6_select->isEnabled()) {
      ui->Save_Part_6_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[5].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[5].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[5].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPatch_7_select->isEnabled()) {
      ui->Save_Part_7_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[6].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[6].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[6].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPatch_8_select->isEnabled()) {
      ui->Save_Part_8_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[7].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[7].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[7].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPatch_9_select->isEnabled()) {
      ui->Save_Part_9_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[8].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[8].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[8].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPatch_10_select->isEnabled()) {
      ui->Save_Part_10_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[9].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[9].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[9].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPatch_11_select->isEnabled()) {
      ui->Save_Part_11_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[10].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[10].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[10].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPatch_12_select->isEnabled()) {
      ui->Save_Part_12_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[11].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[11].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[11].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPatch_13_select->isEnabled()) {
      ui->Save_Part_13_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[12].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[12].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[12].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPatch_14_select->isEnabled()) {
      ui->Save_Part_14_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[13].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[13].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[13].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPatch_15_select->isEnabled()) {
      ui->Save_Part_15_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[14].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[14].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[14].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPatch_16_select->isEnabled()) {
      ui->Save_Part_16_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[15].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[15].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[15].patch_common.name[0],12).rightJustified(15));
  }
}	// end on_Save_CurrentPerformance_button_toggled

void Save_Dialog::on_Save_CurrentPatch_button_toggled(bool val) {
  if (!val) return;
  QString buf;
  switch(JVlibForm::system_area->sys_common.patch_group_id) {
    case 0x01:  // User
      buf = "User ";
      break;
    case 0x02:  // Exp A
      buf = "Expansion_A ";
      break;
    case 0x03:  // Preset A
      buf = "Preset_A ";
      break;
    case 0x04:  // Preset B
      buf = "Preset_B ";
      break;
    case 0x05:  // Preset C
      buf = "Preset_C ";
      break;
    case 0x06:  // Preset D
      buf = "Preset_D ";
      break;
    case 0x10:  // Exp B
      buf = "Expansion_B ";
      break;
    case 0x62:  // Exp C
      buf = "Expansion_C ";
      break;
  }
  buf += QString::number(JVlibForm::system_area->sys_common.patch_num_high*16 + JVlibForm::system_area->sys_common.patch_num_low+1)+" ";
  buf += QString::fromAscii(&JVlibForm::active_area->active_patch_patch.patch_common.name[0],12).trimmed();
  ui->Save_Name_edit->setText(buf);
}	// end on_Save_CurrentPatch_button_toggled

void Save_Dialog::on_Save_CurrentRhythm_button_toggled(bool val) {
  if (!val) return;
  QString buf;
  switch (JVlibForm::active_area->active_performance.perf_part[9].patch_group_id) {
      case 0x01:  // User
	buf = "User ";
	break;
      case 0x02:  // Exp A
	buf = "Expansion_A ";
	break;
      case 0x03:  // Preset A
	buf = "Preset_A ";
	break;
      case 0x04:  // Preset B
	buf = "Preset_B ";
	break;
      case 0x05:  // Preset C
	buf = "Preset_C ";
	break;
      case 0x06:  // Preset D
	buf = "Preset_D ";
	break;
      case 0x10:  // Exp B
	buf = "Expansion_B ";
	break;
      case 0x62:  // Exp C
	buf = "Expansion_C ";
	break;
    }
    buf += QString::number(JVlibForm::active_area->active_performance.perf_part[9].patch_num_high*16 + JVlibForm::active_area->active_performance.perf_part[9].patch_num_low+1)+" ";
    buf += QString::fromAscii(&JVlibForm::active_area->active_rhythm.rhythm_common.name[0],12).trimmed();
    ui->Save_Name_edit->setText(buf);
}	// end on_Save_CurrentRhythm_button_toggled

void Save_Dialog::on_Save_CurrentTuning_button_toggled(bool val) {
  if (!val) return;
  ui->Save_Name_edit->setText("Tuning Custom Settings");
}	// end on_Save_CurrentTuning_button_toggled

void Save_Dialog::on_Save_System_button_toggled(bool val) {
  if (!val) return;
  QString buf = "System_"+QDate::currentDate().toString(Qt::ISODate);
  ui->Save_Name_edit->setText(buf);
}

void Save_Dialog::on_Save_UserPerformance_button_toggled(bool val) {
  ui->Save_PerfNumber_select->setEnabled(val);
  if (!val) return;
  unsigned char buf[16];
  char r_name[12];
  char       user1_perf_common[]={ 0x10,0x00,0x00,0x00 };  
  char    perf_name_size[] = { 0x00,0x00,0x00,0x0C };
  // get the Patch name from the JV
  memset(buf,0,sizeof(buf));
  buf[4] = JV_REQ;
  memcpy(buf+5,user1_perf_common,4);
  buf[6] = ui->Save_PerfNumber_select->value() - 1;
  memcpy(buf+9,perf_name_size,4);
  buf[13] = JVlibForm::chksum(buf+5,8);
  buf[14] = 0xF7;
  if (JVlibForm::open_ports() == EXIT_FAILURE) return;
  JVlibForm::sysex_send(buf,15);
  JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)perf_name_size);
  JVlibForm::close_ports();
  // fill out the Name field
  QString d_name = "User "+QString::number(ui->Save_PerfNumber_select->value())+" "+QString::fromAscii(r_name,12);
  ui->Save_Name_edit->setText(d_name);  
}	// end on_Save_UserPerformance_button_toggled

void Save_Dialog::on_Save_UserPatch_button_toggled(bool val) {
  ui->Save_PatchNumber_select->setEnabled(val);
  if (!val) return;
  unsigned char buf[16];
  char r_name[12];
  char       user1_patch_common[]={ 0x11,0x00,0x00,0x00 };  
  char    patch_name_size[] = { 0x00,0x00,0x00,0x0C };
  // get the Patch name from the JV
  memset(buf,0,sizeof(buf));
  buf[4] = JV_REQ;
  memcpy(buf+5,user1_patch_common,4);
  buf[6] = ui->Save_PatchNumber_select->value() - 1;
  memcpy(buf+9,patch_name_size,4);
  buf[13] = JVlibForm::chksum(buf+5,8);
  buf[14] = 0xF7;
  if (JVlibForm::open_ports() == EXIT_FAILURE) return;
  JVlibForm::sysex_send(buf,15);
  JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)patch_name_size);
  JVlibForm::close_ports();
  // fill out the Name field
  QString d_name = "User "+QString::number(ui->Save_PatchNumber_select->value())+" "+QString::fromAscii(r_name,12);
  ui->Save_Name_edit->setText(d_name);  
}	// end on_Save_UserPatch_button_toggled

void Save_Dialog::on_Save_UserRhythm_button_toggled(bool val) {
  ui->Save_RhythmNumber_select->setEnabled(val);
  if (!val) return;
  unsigned char buf[16];
  char r_name[12];
  char       user1_rhythm_common[]={ 0x10,0x40,0x0,0x0 };  
  char    rhythm_name_size[] = { 0x0,0x0,0x0,0x0C };
  // get the Rhythmset name from the JV
  memset(buf,0,sizeof(buf));
  buf[4] = JV_REQ;
  memcpy(buf+5,user1_rhythm_common,4);
  if (ui->Save_RhythmNumber_select->value()==2)
    buf[6] = 0x41;
  memcpy(buf+9,rhythm_name_size,4);
  buf[13] = JVlibForm::chksum(buf+5,8);
  buf[14] = 0xF7;
  if (JVlibForm::open_ports() == EXIT_FAILURE) return;
  JVlibForm::sysex_send(buf,15);
  JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)rhythm_name_size);
  JVlibForm::close_ports();
  // fill out the Name field
  QString d_name = "User "+QString::number(ui->Save_RhythmNumber_select->value())+" "+QString::fromAscii(r_name,12);
  ui->Save_Name_edit->setText(d_name);
}	// end on_Save_UserRhythm_button_toggled

void Save_Dialog::on_Save_ReceiveUserDump_button_toggled(bool val) {
  if (!val) {
    return;
  }
  ui->Save_Name_edit->setText("Full User Dump");
}

void Save_Dialog::on_Save_All_button_toggled(bool val) {
  if (!val) {
    if (ui->Save_UserRhythm_button->isChecked()) on_Save_UserRhythm_button_toggled(true);
    if (ui->Save_UserPatch_button->isChecked()) on_Save_UserPatch_button_toggled(true);
    if (ui->Save_UserPerformance_button->isChecked()) on_Save_UserPerformance_button_toggled(true);
    return;
  }
  QString buf = "User ";
  // save all User entries for Perf, Patch or Rhythm
  if (ui->Save_UserRhythm_button->isChecked()) {
    ui->Save_RhythmNumber_select->setEnabled(false);
    buf += "Rhythm";
  }
  if (ui->Save_UserPatch_button->isChecked()) {
    ui->Save_PatchNumber_select->setEnabled(false);
    buf += "Patch";
  }
  if (ui->Save_UserPerformance_button->isChecked()) {
    ui->Save_PerfNumber_select->setEnabled(false);
    buf += "Performance";
  }
  buf += " Dump "+QDate::currentDate().toString(Qt::ISODate);
  ui->Save_Name_edit->setText(buf);
}	// end on_Save_All_button_toggled

void Save_Dialog::on_Save_RhythmNumber_select_valueChanged() {
  on_Save_UserRhythm_button_toggled(true);
}

void Save_Dialog::on_Save_PatchNumber_select_valueChanged() {
  on_Save_UserPatch_button_toggled(true);
}

void Save_Dialog::on_Save_PerfNumber_select_valueChanged() {
  on_Save_UserPerformance_button_toggled(true);
}

void Save_Dialog::on_Save_buttonBox_rejected() {
  this->close();
}

void Save_Dialog::on_Save_buttonBox_helpRequested() {
  QMessageBox::critical(this, "Save Dialog", "Help not yet available for this function");
}

void Save_Dialog::on_Save_buttonBox_accepted() {
  // Save_comments are optional, but recommended
  QString table_name;
  int sz = 0;
  char *ptr = NULL;
  if (ui->Save_Comment_edit->text().isEmpty()) {
    ui->Save_Comment_edit->setPlaceholderText("Optional comment describing this data");
    ui->Save_buttonBox->setFocus();
  }
  // must have a name specified
  if (ui->Save_Name_edit->text().isEmpty()) {
    ui->Save_Name_edit->setPlaceholderText("Enter a valid name");
    ui->Save_Comment_edit->setFocus();
    return;
  }
  if (ui->Save_System_button->isChecked()) {
    table_name = "Dumps";
    sz = 0x28;
    ptr = &JVlibForm::system_area->sys_common.panel_mode;
    db_insert_data(table_name, ptr, sz);
  }
  if (ui->Save_CurrentPerformance_button->isChecked()) {
    save_current_perf();
  }
  if (ui->Save_CurrentPatch_button->isChecked()) {
    table_name = "Patches";
    sz = 0x48 + (0x81*4);	// common and 4 tones
    ptr = &JVlibForm::active_area->active_patch_patch.patch_common.name[0];    
    db_insert_data(table_name, ptr, sz);
  }
  if (ui->Save_CurrentRhythm_button->isChecked()) {
    table_name = "RhythmSets";
    sz = 0x0C + (0x3A*64);	// common and 64 notes
    ptr = &JVlibForm::active_area->active_rhythm.rhythm_common.name[0];
    db_insert_data(table_name, ptr, sz);
  }
  if (ui->Save_UserRhythm_button->isChecked()) {
    SaveUserRhythm();
  }
  if (ui->Save_CurrentTuning_button->isChecked()) {
//    if (JVlibForm::Tuning_CustomTemp_button->isChecked()==false) return;
//    table_name = "Tuning";
//    sz = 0;	// NOTE: tbd
//    ptr = NULL;	// NOTE: tbd
//    db_insert_data(table_name, ptr, sz);
  }
  if (ui->Save_UserPerformance_button->isChecked()) {
//    table_name = "Performances";
//    sz = 0;	// NOTE: tbd
//    ptr = NULL;	// NOTE: tbd
//    db_insert_data(table_name, ptr, sz);
  }
  if (ui->Save_UserPatch_button->isChecked()) {
//    table_name = "Patches";
//    sz = 0;	// NOTE: tbd
//    ptr = NULL;	// NOTE: tbd
//    db_insert_data(table_name, ptr, sz);
  }
  if (ui->Save_ReceiveUserDump_button->isChecked()) {
    // save all entries of User Performance, Patch or Rhythm
//    table_name = "Dumps";
//    sz = 0;	// NOTE: tbd
//    ptr = NULL;	// NOTE: tbd
//    db_insert_data(table_name, ptr, sz);
  }
  this->close();
}	// end on_Save_buttonBox_accepted
