// save_dialog_slots.cpp
// Create and display a valid Name for the selected option.
// Contains:
/* on_Save_System_button_toggled()
 * on_Save_PerfPart_All_select_toggled()
 * on_Save_CurrentPerformance_button_toggled()
 * on_Save_CurrentPatch_button_toggled()
 * on_Save_CurrentRhythm_button_toggled()
 * on_Save_CurrentTuning_button_toggled()
 * on_Save_UserPerformance_button_toggled()
 * on_Save_UserPatch_button_toggled()
 * on_Save_UserRhythm_button_toggled()
 * on_Save_AllUserDump_button_toggled()
 * on_Save_buttonBox_rejected()
 * on_Save_buttonBox_helpRequested()
 * on_Save_buttonBox_accepted()
 * on_Save_RhythmNumber_select_valueChanged()
 * on_Save_PatchNumber_select_valueChanged()
 * on_Save_PerfNumber_select_valueChanged()
 * on_Save_All_button_toggled()
 * on_Save_ReceiveUserDump_button_toggled()
 * hexdump()
*/
#include	"save_dialog/Save_Dialog.h"
#include	"ui_Save_Dialog.h"
#include        "JVlibForm.h"
#include        <QtGui>
#include	<QtSql>

void Save_Dialog::on_Save_PerfPart_All_select_toggled(bool val) {
  ui->Save_PerfPart_1_select->setChecked(val && ui->Save_PerfPart_1_select->isEnabled());
  ui->Save_PerfPart_2_select->setChecked(val && ui->Save_PerfPart_2_select->isEnabled());
  ui->Save_PerfPart_3_select->setChecked(val && ui->Save_PerfPart_3_select->isEnabled());
  ui->Save_PerfPart_4_select->setChecked(val && ui->Save_PerfPart_4_select->isEnabled());
  ui->Save_PerfPart_5_select->setChecked(val && ui->Save_PerfPart_5_select->isEnabled());
  ui->Save_PerfPart_6_select->setChecked(val && ui->Save_PerfPart_6_select->isEnabled());
  ui->Save_PerfPart_7_select->setChecked(val && ui->Save_PerfPart_7_select->isEnabled());
  ui->Save_PerfPart_8_select->setChecked(val && ui->Save_PerfPart_8_select->isEnabled());
  ui->Save_PerfPart_9_select->setChecked(val && ui->Save_PerfPart_9_select->isEnabled());
  ui->Save_PerfPart_10_select->setChecked(val && ui->Save_PerfPart_10_select->isEnabled());
  ui->Save_PerfPart_11_select->setChecked(val && ui->Save_PerfPart_11_select->isEnabled());
  ui->Save_PerfPart_12_select->setChecked(val && ui->Save_PerfPart_12_select->isEnabled());
  ui->Save_PerfPart_13_select->setChecked(val && ui->Save_PerfPart_13_select->isEnabled());
  ui->Save_PerfPart_14_select->setChecked(val && ui->Save_PerfPart_14_select->isEnabled());
  ui->Save_PerfPart_15_select->setChecked(val && ui->Save_PerfPart_15_select->isEnabled());
  ui->Save_PerfPart_16_select->setChecked(val && ui->Save_PerfPart_16_select->isEnabled());
}

void Save_Dialog::on_Save_CurrentPerformance_button_toggled(bool val) {
  clearPartLabels();
  ui->Save_PerfPart_box->setEnabled(val);
  if (!val) return;
  ui->Save_All_button->setEnabled(false);
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
  ui->Save_PerfPart_1_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[0].patch_group_id==1);
  ui->Save_PerfPart_2_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[1].patch_group_id==1);
  ui->Save_PerfPart_3_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[2].patch_group_id==1);
  ui->Save_PerfPart_4_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[3].patch_group_id==1);
  ui->Save_PerfPart_5_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[4].patch_group_id==1);
  ui->Save_PerfPart_6_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[5].patch_group_id==1);
  ui->Save_PerfPart_7_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[6].patch_group_id==1);
  ui->Save_PerfPart_8_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[7].patch_group_id==1);
  ui->Save_PerfPart_9_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[8].patch_group_id==1);
  ui->Save_PerfPart_10_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[9].patch_group_id==1);
  ui->Save_PerfPart_11_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[10].patch_group_id==1);
  ui->Save_PerfPart_12_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[11].patch_group_id==1);
  ui->Save_PerfPart_13_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[12].patch_group_id==1);
  ui->Save_PerfPart_14_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[13].patch_group_id==1);
  ui->Save_PerfPart_15_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[14].patch_group_id==1);
  ui->Save_PerfPart_16_select->setEnabled(JVlibForm::active_area->active_performance.perf_part[15].patch_group_id==1);
  // fill in the User Patch numbers/names
  if (ui->Save_PerfPart_1_select->isEnabled()) {
      ui->Save_Part_1_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[0].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[0].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[0].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPart_2_select->isEnabled()) {
      ui->Save_Part_2_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[1].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[1].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[1].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPart_3_select->isEnabled()) {
      ui->Save_Part_3_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[2].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[2].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[2].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPart_4_select->isEnabled()) {
      ui->Save_Part_4_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[3].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[3].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[3].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPart_5_select->isEnabled()) {
      ui->Save_Part_5_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[4].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[4].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[4].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPart_6_select->isEnabled()) {
      ui->Save_Part_6_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[5].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[5].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[5].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPart_7_select->isEnabled()) {
      ui->Save_Part_7_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[6].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[6].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[6].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPart_8_select->isEnabled()) {
      ui->Save_Part_8_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[7].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[7].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[7].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPart_9_select->isEnabled()) {
      ui->Save_Part_9_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[8].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[8].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[8].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPart_10_select->isEnabled()) {
      ui->Save_Part_10_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[9].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[9].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[9].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPart_11_select->isEnabled()) {
      ui->Save_Part_11_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[10].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[10].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[10].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPart_12_select->isEnabled()) {
      ui->Save_Part_12_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[11].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[11].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[11].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPart_13_select->isEnabled()) {
      ui->Save_Part_13_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[12].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[12].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[12].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPart_14_select->isEnabled()) {
      ui->Save_Part_14_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[13].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[13].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[13].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPart_15_select->isEnabled()) {
      ui->Save_Part_15_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[14].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[14].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[14].patch_common.name[0],12).rightJustified(15));
  }
  if (ui->Save_PerfPart_16_select->isEnabled()) {
      ui->Save_Part_16_data->setText("User "+
      QString::number((JVlibForm::active_area->active_performance.perf_part[15].patch_num_high*16)+
      JVlibForm::active_area->active_performance.perf_part[15].patch_num_low+1).rightJustified(3) +
      QString::fromAscii(&JVlibForm::active_area->active_perf_patch[15].patch_common.name[0],12).rightJustified(15));
  }
}	// end on_Save_CurrentPerformance_button_toggled

void Save_Dialog::on_Save_CurrentPatch_button_toggled(bool val) {
  if (!val) return;
  ui->Save_All_button->setEnabled(false);
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
  ui->Save_All_button->setEnabled(false);
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
  ui->Save_All_button->setEnabled(false);
  if (JVlibForm::state_table->perf_mode)
    ui->Save_Name_edit->setText("Performance Tuning Custom Settings");
  if (JVlibForm::state_table->patch_mode)
    ui->Save_Name_edit->setText("Patch Tuning Custom Settings");
}	// end on_Save_CurrentTuning_button_toggled

void Save_Dialog::on_Save_System_button_toggled(bool val) {
  if (!val) return;
  ui->Save_All_button->setEnabled(false);
  QString buf = "System_"+QDate::currentDate().toString(Qt::ISODate);
  ui->Save_Name_edit->setText(buf);
}

void Save_Dialog::on_Save_UserPerformance_button_toggled(bool val) {
  clearPartLabels();
  ui->Save_PerfPart_box->setEnabled(val);
  if (!val) return;
  ui->Save_All_button->setEnabled(true);
  this->setCursor(Qt::WaitCursor);
  unsigned char buf[8];
  char r_name[12];
  char user1_perf_common[]={ 0x10,0x00,0x00,0x00 };  
  char perf_name_size[] = { 0x00,0x00,0x00,0x0C };
  char part_data_size[] = { 0x00,0x00,0x00,0x06 };
  char patch_name_size[] = { 0x00,0x00,0x00,0x0C };
  
  // get the Perf name from the JV
  memset(buf,0,sizeof(buf));
  memcpy(buf,user1_perf_common,4);
  buf[1] = ui->Save_PerfNumber_select->value() - 1;
  memcpy(buf+4,perf_name_size,4);
  if (JVlibForm::open_ports() == EXIT_FAILURE) return;
  JVlibForm::sysex_request(buf);
  JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)perf_name_size);
  // fill out the Name field
  QString d_name = "User "+QString::number(ui->Save_PerfNumber_select->value())+" "+QString::fromAscii(r_name,12);
  ui->Save_Name_edit->setText(d_name);
  
  // see if a PerfPart has a User patch, enable the checkbox if so
  buf[7] = 6;	// get 6 bytes from Part
  for (int x=0;x<16;x++) {
    buf[2] = 0x10 + x;
    JVlibForm::sysex_request(buf);
    JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)part_data_size);
    bool valUser = (r_name[0]) && (r_name[3]==1);
    switch(x) {
	case 0:
	  ui->Save_PerfPart_1_select->setEnabled(valUser);
	  if (valUser) ui->Save_Part_1_data->setText("User "+QString::number(r_name[5]+1).rightJustified(3));
	  break;
	case 1:
	  ui->Save_PerfPart_2_select->setEnabled(valUser);
	  if (valUser) ui->Save_Part_2_data->setText("User "+QString::number(r_name[5]+1).rightJustified(3));
	  break;
	case 2:
	  ui->Save_PerfPart_3_select->setEnabled(valUser);
	  if (valUser) ui->Save_Part_3_data->setText("User "+QString::number(r_name[5]+1).rightJustified(3));
	  break;
	case 3:
	  ui->Save_PerfPart_4_select->setEnabled(valUser);
	  if (valUser) ui->Save_Part_4_data->setText("User "+QString::number(r_name[5]+1).rightJustified(3));
	  break;
	case 4:
	  ui->Save_PerfPart_5_select->setEnabled(valUser);
	  if (valUser) ui->Save_Part_5_data->setText("User "+QString::number(r_name[5]+1).rightJustified(3));
	  break;
	case 5:
	  ui->Save_PerfPart_6_select->setEnabled(valUser);
	  if (valUser) ui->Save_Part_6_data->setText("User "+QString::number(r_name[5]+1).rightJustified(3));
	  break;
	case 6:
	  ui->Save_PerfPart_7_select->setEnabled(valUser);
	  if (valUser) ui->Save_Part_7_data->setText("User "+QString::number(r_name[5]+1).rightJustified(3));
	  break;
	case 7:
	  ui->Save_PerfPart_8_select->setEnabled(valUser);
	  if (valUser) ui->Save_Part_8_data->setText("User "+QString::number(r_name[5]+1).rightJustified(3));
	  break;
	case 8:
	  ui->Save_PerfPart_9_select->setEnabled(valUser);
	  if (valUser) ui->Save_Part_9_data->setText("User "+QString::number(r_name[5]+1).rightJustified(3));
	  break;
	case 9:
	  ui->Save_PerfPart_10_select->setEnabled(valUser);
	  if (valUser) ui->Save_Part_10_data->setText("User "+QString::number(r_name[5]+1).rightJustified(3));
	  break;
	case 10:
	  ui->Save_PerfPart_11_select->setEnabled(valUser);
	  if (valUser) ui->Save_Part_11_data->setText("User "+QString::number(r_name[5]+1).rightJustified(3));
	  break;
	case 11:
	  ui->Save_PerfPart_12_select->setEnabled(valUser);
	  if (valUser) ui->Save_Part_12_data->setText("User "+QString::number(r_name[5]+1).rightJustified(3));
	  break;
	case 12:
	  ui->Save_PerfPart_13_select->setEnabled(valUser);
	  if (valUser) ui->Save_Part_13_data->setText("User "+QString::number(r_name[5]+1).rightJustified(3));
	  break;
	case 13:
	  ui->Save_PerfPart_14_select->setEnabled(valUser);
	  if (valUser) ui->Save_Part_14_data->setText("User "+QString::number(r_name[5]+1).rightJustified(3));
	  break;
	case 14:
	  ui->Save_PerfPart_15_select->setEnabled(valUser);
	  if (valUser) ui->Save_Part_15_data->setText("User "+QString::number(r_name[5]+1).rightJustified(3));
	  break;
	case 15:
	  ui->Save_PerfPart_16_select->setEnabled(valUser);
	  if (valUser) ui->Save_Part_16_data->setText("User "+QString::number(r_name[5]+1).rightJustified(3));
	  break;
      }	// end switch
  }	// end FOR
  // all User Patch checkboxes are enabled,
  // get Patch name for User parts
  memset(buf,0,sizeof(buf));
  buf[0] = 0x11;
  buf[7] = 0x0C;
  if (ui->Save_PerfPart_1_select->isEnabled()) {
    buf[1] = ui->Save_Part_1_data->text().right(3).toInt() - 1;
    JVlibForm::sysex_request(buf);
    JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)patch_name_size);
    QString t_text = ui->Save_Part_1_data->text()+QString::fromAscii(&r_name[0],12).rightJustified(15);
    ui->Save_Part_1_data->setText(t_text);
  }
  if (ui->Save_PerfPart_2_select->isEnabled()) {
    buf[1] = ui->Save_Part_2_data->text().right(3).toInt() - 1;
    JVlibForm::sysex_request(buf);
    JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)patch_name_size);
    QString t_text = ui->Save_Part_2_data->text()+QString::fromAscii(&r_name[0],12).rightJustified(15);
    ui->Save_Part_2_data->setText(t_text);
  }
  if (ui->Save_PerfPart_3_select->isEnabled()) {
    buf[1] = ui->Save_Part_3_data->text().right(3).toInt() - 1;
    JVlibForm::sysex_request(buf);
    JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)patch_name_size);
    QString t_text = ui->Save_Part_3_data->text()+QString::fromAscii(&r_name[0],12).rightJustified(15);
    ui->Save_Part_3_data->setText(t_text);
  }
  if (ui->Save_PerfPart_4_select->isEnabled()) {
    buf[1] = ui->Save_Part_4_data->text().right(3).toInt() - 1;
    JVlibForm::sysex_request(buf);
    JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)patch_name_size);
    QString t_text = ui->Save_Part_4_data->text()+QString::fromAscii(&r_name[0],12).rightJustified(15);
    ui->Save_Part_4_data->setText(t_text);
  }
  if (ui->Save_PerfPart_5_select->isEnabled()) {
    buf[1] = ui->Save_Part_5_data->text().right(3).toInt() - 1;
    JVlibForm::sysex_request(buf);
    JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)patch_name_size);
    QString t_text = ui->Save_Part_5_data->text()+QString::fromAscii(&r_name[0],12).rightJustified(15);
    ui->Save_Part_5_data->setText(t_text);
  }
  if (ui->Save_PerfPart_6_select->isEnabled()) {
    buf[1] = ui->Save_Part_6_data->text().right(3).toInt() - 1;
    JVlibForm::sysex_request(buf);
    JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)patch_name_size);
    QString t_text = ui->Save_Part_6_data->text()+QString::fromAscii(&r_name[0],12).rightJustified(15);
    ui->Save_Part_6_data->setText(t_text);
  }
  if (ui->Save_PerfPart_7_select->isEnabled()) {
    buf[1] = ui->Save_Part_7_data->text().right(3).toInt() - 1;
    JVlibForm::sysex_request(buf);
    JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)patch_name_size);
    QString t_text = ui->Save_Part_7_data->text()+QString::fromAscii(&r_name[0],12).rightJustified(15);
    ui->Save_Part_7_data->setText(t_text);
  }
  if (ui->Save_PerfPart_8_select->isEnabled()) {
    buf[1] = ui->Save_Part_8_data->text().right(3).toInt() - 1;
    JVlibForm::sysex_request(buf);
    JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)patch_name_size);
    QString t_text = ui->Save_Part_8_data->text()+QString::fromAscii(&r_name[0],12).rightJustified(15);
    ui->Save_Part_8_data->setText(t_text);
  }
  if (ui->Save_PerfPart_9_select->isEnabled()) {
    buf[1] = ui->Save_Part_9_data->text().right(3).toInt() - 1;
    JVlibForm::sysex_request(buf);
    JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)patch_name_size);
    QString t_text = ui->Save_Part_9_data->text()+QString::fromAscii(&r_name[0],12).rightJustified(15);
    ui->Save_Part_9_data->setText(t_text);
  }
  if (ui->Save_PerfPart_11_select->isEnabled()) {
    buf[1] = ui->Save_Part_11_data->text().right(3).toInt() - 1;
    JVlibForm::sysex_request(buf);
    JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)patch_name_size);
    QString t_text = ui->Save_Part_11_data->text()+QString::fromAscii(&r_name[0],12).rightJustified(15);
    ui->Save_Part_11_data->setText(t_text);
  }
  if (ui->Save_PerfPart_12_select->isEnabled()) {
    buf[1] = ui->Save_Part_12_data->text().right(3).toInt() - 1;
    JVlibForm::sysex_request(buf);
    JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)patch_name_size);
    QString t_text = ui->Save_Part_12_data->text()+QString::fromAscii(&r_name[0],12).rightJustified(15);
    ui->Save_Part_12_data->setText(t_text);
  }
  if (ui->Save_PerfPart_13_select->isEnabled()) {
    buf[1] = ui->Save_Part_13_data->text().right(3).toInt() - 1;
    JVlibForm::sysex_request(buf);
    JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)patch_name_size);
    QString t_text = ui->Save_Part_13_data->text()+QString::fromAscii(&r_name[0],12).rightJustified(15);
    ui->Save_Part_13_data->setText(t_text);
  }
  if (ui->Save_PerfPart_14_select->isEnabled()) {
    buf[1] = ui->Save_Part_14_data->text().right(3).toInt() - 1;
    JVlibForm::sysex_request(buf);
    JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)patch_name_size);
    QString t_text = ui->Save_Part_14_data->text()+QString::fromAscii(&r_name[0],12).rightJustified(15);
    ui->Save_Part_14_data->setText(t_text);
  }
  if (ui->Save_PerfPart_15_select->isEnabled()) {
    buf[1] = ui->Save_Part_15_data->text().right(3).toInt() - 1;
    JVlibForm::sysex_request(buf);
    JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)patch_name_size);
    QString t_text = ui->Save_Part_15_data->text()+QString::fromAscii(&r_name[0],12).rightJustified(15);
    ui->Save_Part_15_data->setText(t_text);
  }
  if (ui->Save_PerfPart_16_select->isEnabled()) {
    buf[1] = ui->Save_Part_16_data->text().right(3).toInt() - 1;
    JVlibForm::sysex_request(buf);
    JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)patch_name_size);
    QString t_text = ui->Save_Part_16_data->text()+QString::fromAscii(&r_name[0],12).rightJustified(15);
    ui->Save_Part_16_data->setText(t_text);
  }
  if (ui->Save_PerfPart_10_select->isEnabled()) {	// Rhythm set
    buf[1] = ui->Save_Part_10_data->text().right(3).toInt() + 0x3F;
    buf[0] = 0x10;
    JVlibForm::sysex_request(buf);
    JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)patch_name_size);
    QString t_text = ui->Save_Part_10_data->text()+QString::fromAscii(&r_name[0],12).rightJustified(15);
    ui->Save_Part_10_data->setText(t_text);
  }
  JVlibForm::close_ports();
  this->setCursor(Qt::ArrowCursor);   
}	// end on_Save_UserPerformance_button_toggled

void Save_Dialog::on_Save_UserPatch_button_toggled(bool val) {
  if (!val) return;
  ui->Save_All_button->setEnabled(true);
  unsigned char buf[8];
  char r_name[12];
  char       user1_patch_common[]={ 0x11,0x00,0x00,0x00 };  
  char    patch_name_size[] = { 0x00,0x00,0x00,0x0C };
  // get the Patch name from the JV
  memset(buf,0,sizeof(buf));
  memcpy(buf,user1_patch_common,4);
  buf[1] = ui->Save_PatchNumber_select->value() - 1;
  memcpy(buf+4,patch_name_size,4);
  if (JVlibForm::open_ports() == EXIT_FAILURE) return;
  JVlibForm::sysex_request(buf);
  JVlibForm::sysex_get((unsigned char *)&r_name[0], (char *)patch_name_size);
  JVlibForm::close_ports();
  // fill out the Name field
  QString d_name = "User "+QString::number(ui->Save_PatchNumber_select->value())+" "+QString::fromAscii(r_name,12);
  ui->Save_Name_edit->setText(d_name);  
}	// end on_Save_UserPatch_button_toggled

void Save_Dialog::on_Save_UserRhythm_button_toggled(bool val) {
  if (!val) return;
  ui->Save_All_button->setEnabled(true);
  unsigned char buf[8];
  char r_name[12];
  char       user1_rhythm_common[]={ 0x10,0x40,0x0,0x0 };  
  char    rhythm_name_size[] = { 0x0,0x0,0x0,0x0C };
  // get the Rhythmset name from the JV
  memset(buf,0,sizeof(buf));
  memcpy(buf,user1_rhythm_common,4);
  if (ui->Save_RhythmNumber_select->value()==2)
    buf[1] = 0x41;
  memcpy(buf+4,rhythm_name_size,4);
  if (JVlibForm::open_ports() == EXIT_FAILURE) return;
  JVlibForm::sysex_request(buf);
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
  ui->Save_All_button->setEnabled(false);
  ui->Save_Name_edit->setText("Full User Dump");
}

void Save_Dialog::on_Save_AllUserDump_button_toggled() {
  ui->Save_All_button->setEnabled(false);
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
  // process the selected data
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
    if (!ui->Save_All_button->isChecked()) {
      SaveUserRhythm(ui->Save_RhythmNumber_select->value());
    }
    else {
      SaveAllUserRhythmDump();
    }
  }
  if (ui->Save_UserPatch_button->isChecked()) {
    if (!ui->Save_All_button->isChecked()) {
      SaveUserPatch(ui->Save_PatchNumber_select->value());
    }
    else {
      SaveAllUserPatchDump();
    }
  }
  if (ui->Save_UserPerformance_button->isChecked()) {
    if (!ui->Save_All_button->isChecked()) {
      SaveUserPerf();
    }
    else {
      SaveAllUserPerfDump();
    }
  }
  if (ui->Save_CurrentTuning_button->isChecked()) {
    Tuning_currentTuning.truncate(0);
    if (JVlibForm::state_table->patch_mode) {
      Tuning_currentTuning.setRawData(&JVlibForm::system_area->sys_patch_scale_tune.scale[0], 12);
    }
    if (JVlibForm::state_table->perf_mode) {
      Tuning_currentTuning.setRawData(&JVlibForm::system_area->sys_part_scale_tune[0].scale[0], 12*16);      
    }
    db_insert_data("Tuning", (char *)Tuning_currentTuning.constData(), Tuning_currentTuning.size());
  }
  if (ui->Save_AllUserDump_button->isChecked()) {
    SaveAllDump();
  }
  if (ui->Save_ReceiveUserDump_button->isChecked()) {
    // save a dump initiated from the JV
    ReceiveDump();
  }
  this->close();
}	// end on_Save_buttonBox_accepted

void Save_Dialog::hexdump(unsigned char *buffer, int data_size) {
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
  return;
}	// end HEXDUMP

