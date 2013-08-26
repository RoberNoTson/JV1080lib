// save_dialog_slots.cpp
#include	"save_dialog/Save_Dialog.h"
#include	"ui_Save_Dialog.h"
#include        "JVlibForm.h"
#include        <QtGui>
#include	<QtSql>
#include        "ui_JVlib.h"

void Save_Dialog::on_Save_System_button_toggled(bool val) {
  if (val) {
    QString buf = "System_"+QDate::currentDate().toString(Qt::ISODate);
    ui->Save_Name_edit->setText(buf);
  }
}

void Save_Dialog::on_Save_CurrentPerformance_button_toggled(bool val) {
  ui->Save_PerfPatch_box->setEnabled(val);
  if (val) {
    QString buf;
    int pn = JVlibForm::system_area->sys_common.perf_num;
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
    buf += QString::fromAscii(&JVlibForm::active_area->active_performance.perf_common.name[0],12).trimmed();
    buf += "_";
    buf += QDate::currentDate().toString(Qt::ISODate);
    ui->Save_Name_edit->setText(buf);
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
  }	// end IF checked


}	// end on_Save_CurrentPerformance_button_toggled

void Save_Dialog::on_Save_CurrentPatch_button_toggled(bool val) {
  if (val) {
    QString buf;
    switch(JVlibForm::system_area->sys_common.patch_group_id) {
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
    buf += QString::number(JVlibForm::system_area->sys_common.patch_num_high*16 + JVlibForm::system_area->sys_common.patch_num_low+1)+"_";
    buf += QString::fromAscii(&JVlibForm::active_area->active_patch_patch.patch_common.name[0],12).trimmed();
    buf += "_";
    buf += QDate::currentDate().toString(Qt::ISODate);
    ui->Save_Name_edit->setText(buf);
  }
}	// end on_Save_CurrentPatch_button_toggled

void Save_Dialog::on_Save_CurrentRhythm_button_toggled(bool val) {
  if (val) {
    QString buf;
    switch (JVlibForm::active_area->active_performance.perf_part[9].patch_group_id) {
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
    buf += QString::number(JVlibForm::active_area->active_performance.perf_part[9].patch_num_high*16 + JVlibForm::active_area->active_performance.perf_part[9].patch_num_low+1)+"_";
    buf += QString::fromAscii(&JVlibForm::active_area->active_rhythm.rhythm_common.name[0],12).trimmed();
    buf += "_";
    buf += QDate::currentDate().toString(Qt::ISODate);
    ui->Save_Name_edit->setText(buf);
    
  }
}	// end on_Save_CurrentRhythm_button_toggled

void Save_Dialog::on_Save_CurrentTuning_button_toggled(bool val) {
  if (val) {
  }
}	// end on_Save_CurrentTuning_button_toggled

void Save_Dialog::on_Save_UserPerformance_button_toggled(bool val) {
  if (val) {
  }
}	// end on_Save_UserPerformance_button_toggled

void Save_Dialog::on_Save_UserPatch_button_toggled(bool val) {
  if (val) {
  }
}	// end on_Save_UserPatch_button_toggled

void Save_Dialog::on_Save_UserRhythm_button_toggled(bool val) {
  if (val) {
  }
}	// end on_Save_UserRhythm_button_toggled

void Save_Dialog::on_Save_UserDump_button_toggled(bool val) {
  if (val) {
    QString buf = "User_Dump_"+QDate::currentDate().toString(Qt::ISODate);
    buf += "_";
    buf += QDate::currentDate().toString(Qt::ISODate);
    ui->Save_Name_edit->setText(buf);
  }
}	// end on_Save_UserDump_button_toggled

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
  }
  if (ui->Save_CurrentPerformance_button->isChecked()) {
    table_name = "Performances";
    sz = 0x40+(0x13*16);
    ptr = &JVlibForm::active_area->active_performance.perf_common.name[0];
    int perf_number = db_insert_data(table_name, ptr, sz);
    printf("inserted item %d into table %s\n",perf_number, table_name.toAscii().data());
    
  }
  if (ui->Save_CurrentPatch_button->isChecked()) {
    table_name = "Patches";
    sz = 0x48 + (0x81*4);
    ptr = &JVlibForm::active_area->active_patch_patch.patch_common.name[0];    
  }
  if (ui->Save_CurrentRhythm_button->isChecked()) {
    table_name = "RhythmSets";
    sz = 0x0C + (0x3A*64);
    ptr = &JVlibForm::active_area->active_rhythm.rhythm_common.name[0];
  }
  if (ui->Save_CurrentTuning_button->isChecked()) {
    table_name = "Tuning";
    sz = 0;	// NOTE: tbd
    ptr = NULL;	// NOTE: tbd
  }
  if (ui->Save_UserPerformance_button->isChecked()) {
    table_name = "Dumps";
    sz = 0;	// NOTE: tbd
    ptr = NULL;	// NOTE: tbd
  }
  if (ui->Save_UserPatch_button->isChecked()) {
    table_name = "Dumps";
    sz = 0;	// NOTE: tbd
    ptr = NULL;	// NOTE: tbd
  }
  if (ui->Save_UserRhythm_button->isChecked()) {
    table_name = "Dumps";
    sz = 0;	// NOTE: tbd
    ptr = NULL;	// NOTE: tbd
  }
  if (ui->Save_UserDump_button->isChecked()) {
    table_name = "Dumps";
    sz = 0;	// NOTE: tbd
    ptr = NULL;	// NOTE: tbd
  }
  db_insert_data(table_name, ptr, sz);
  this->close();
}	// end on_Save_buttonBox_accepted

