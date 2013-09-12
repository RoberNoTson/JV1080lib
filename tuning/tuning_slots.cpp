// tuning_slots.cpp
#include	"JVlibForm.h"
#include	<QtGui>

void JVlibForm::Tuning_BulkUpdate(int pn, int offset, int val) {
  system_area->sys_part_scale_tune[pn-1].scale[offset] = val;
  Tuning_PartTune_select->setValue(pn);
  if (state_table->jv_connect)
    setScaleSingleValue(offset,val);  
}	// end Tuning_BulkUpdate

void JVlibForm::TuningStdUpdate(int offset, int val) {
  if (state_table->updates_enabled) {
    if (state_table->patch_mode) {
      system_area->sys_patch_scale_tune.scale[offset] = val;
      if (state_table->jv_connect)
	setScaleSingleValue(offset,val);
    } else {
      if (Tuning_PartNoneTuning_select->isChecked()) {
	system_area->sys_part_scale_tune[Tuning_PartTune_select->value()-1].scale[offset] = val;
	if (state_table->jv_connect)
	  setScaleSingleValue(offset,val);
      } else {
	if (Tuning_Part1Tuning_select->isChecked()) Tuning_BulkUpdate(1,offset,val);
	if (Tuning_Part2Tuning_select->isChecked()) Tuning_BulkUpdate(2,offset,val);
	if (Tuning_Part3Tuning_select->isChecked()) Tuning_BulkUpdate(3,offset,val);
	if (Tuning_Part4Tuning_select->isChecked()) Tuning_BulkUpdate(4,offset,val);
	if (Tuning_Part5Tuning_select->isChecked()) Tuning_BulkUpdate(5,offset,val);
	if (Tuning_Part6Tuning_select->isChecked()) Tuning_BulkUpdate(6,offset,val);
	if (Tuning_Part7Tuning_select->isChecked()) Tuning_BulkUpdate(7,offset,val);
	if (Tuning_Part8Tuning_select->isChecked()) Tuning_BulkUpdate(8,offset,val);
	if (Tuning_Part9Tuning_select->isChecked()) Tuning_BulkUpdate(9,offset,val);
	if (Tuning_Part10Tuning_select->isChecked()) Tuning_BulkUpdate(10,offset,val);
	if (Tuning_Part11Tuning_select->isChecked()) Tuning_BulkUpdate(11,offset,val);
	if (Tuning_Part12Tuning_select->isChecked()) Tuning_BulkUpdate(12,offset,val);
	if (Tuning_Part13Tuning_select->isChecked()) Tuning_BulkUpdate(13,offset,val);
	if (Tuning_Part14Tuning_select->isChecked()) Tuning_BulkUpdate(14,offset,val);
	if (Tuning_Part15Tuning_select->isChecked()) Tuning_BulkUpdate(15,offset,val);
	if (Tuning_Part16Tuning_select->isChecked()) Tuning_BulkUpdate(16,offset,val);
      }	// end ELSE PartAllTuning checked
    }	// end ELSE perf mode
    state_table->tuning_modified = true;
  }	// end state_table->updates_enabled
}	// end TuningStdUpdate

void JVlibForm::on_Tuning_ScaleTuning_enable_toggled(bool status) {
  // Tuning_ScaleTuning_enable
  if (state_table->perf_mode)  { 
    Tuning_Parts_box->setEnabled(status);
    Tuning_PartTune_select->setEnabled(status);
  }
  Tuning_PartTuning_box->setEnabled(status);
  Tuning_Temperament_box->setEnabled(status);
//  Tuning_BaseKey_select->setEnabled(status);
  state_table->tuningTab_enable = true;
  // update the system_area
  system_area->sys_common.scale_tune_switch = status;
  // update the synth
  if (state_table->updates_enabled)
    setSysSingleValue(7,status);
}	// end on_Tuning_ScaleTuning_enable_toggled

// Scale note tuning
void JVlibForm::on_Tuning_PartTuneC_select_valueChanged(int val) {
  Tuning_currentTuning[0] = val + 64;
  TuningStdUpdate(0x00, val+64);
}
void JVlibForm::on_Tuning_PartTuneCs_select_valueChanged(int val) {
  Tuning_currentTuning[1] = val + 64;
  TuningStdUpdate(0x01, val+64);
}
void JVlibForm::on_Tuning_PartTuneD_select_valueChanged(int val) {
  Tuning_currentTuning[2] = val + 64;
  TuningStdUpdate(0x02, val+64);
}
void JVlibForm::on_Tuning_PartTuneDs_select_valueChanged(int val) {
  Tuning_currentTuning[3] = val + 64;
  TuningStdUpdate(0x03, val+64);
}
void JVlibForm::on_Tuning_PartTuneE_select_valueChanged(int val) {
  Tuning_currentTuning[4] = val + 64;
  TuningStdUpdate(0x04, val+64);
}
void JVlibForm::on_Tuning_PartTuneF_select_valueChanged(int val) {
  Tuning_currentTuning[5] = val + 64;
  TuningStdUpdate(0x05, val+64);
}
void JVlibForm::on_Tuning_PartTuneFs_select_valueChanged(int val) {
  Tuning_currentTuning[6] = val + 64;
  TuningStdUpdate(0x06, val+64);
}
void JVlibForm::on_Tuning_PartTuneG_select_valueChanged(int val) {
  Tuning_currentTuning[7] = val + 64;
  TuningStdUpdate(0x07, val+64);
}
void JVlibForm::on_Tuning_PartTuneGs_select_valueChanged(int val) {
  Tuning_currentTuning[8] = val + 64;
  TuningStdUpdate(0x08, val+64);
}
void JVlibForm::on_Tuning_PartTuneA_select_valueChanged(int val) {
  Tuning_currentTuning[9] = val + 64;
  TuningStdUpdate(0x09, val+64);
}
void JVlibForm::on_Tuning_PartTuneAs_select_valueChanged(int val) {
  Tuning_currentTuning[10] = val + 64;
  TuningStdUpdate(0x0A, val+64);
}
void JVlibForm::on_Tuning_PartTuneB_select_valueChanged(int val) {
  Tuning_currentTuning[11] = val + 64;
  TuningStdUpdate(0x0B, val+64);
}

void JVlibForm::on_Tuning_PartTune_select_valueChanged(int val) {
  // update display to show the scale tunings for the selected part
  state_table->updates_enabled = false;
  Tuning_PartTuneC_select->setValue(system_area->sys_part_scale_tune[val-1].scale[0]-64);
  Tuning_PartTuneCs_select->setValue(system_area->sys_part_scale_tune[val-1].scale[1]-64);
  Tuning_PartTuneD_select->setValue(system_area->sys_part_scale_tune[val-1].scale[2]-64);
  Tuning_PartTuneDs_select->setValue(system_area->sys_part_scale_tune[val-1].scale[3]-64);
  Tuning_PartTuneE_select->setValue(system_area->sys_part_scale_tune[val-1].scale[4]-64);
  Tuning_PartTuneF_select->setValue(system_area->sys_part_scale_tune[val-1].scale[5]-64);
  Tuning_PartTuneFs_select->setValue(system_area->sys_part_scale_tune[val-1].scale[6]-64);
  Tuning_PartTuneG_select->setValue(system_area->sys_part_scale_tune[val-1].scale[7]-64);
  Tuning_PartTuneGs_select->setValue(system_area->sys_part_scale_tune[val-1].scale[8]-64);
  Tuning_PartTuneA_select->setValue(system_area->sys_part_scale_tune[val-1].scale[9]-64);
  Tuning_PartTuneAs_select->setValue(system_area->sys_part_scale_tune[val-1].scale[10]-64);
  Tuning_PartTuneB_select->setValue(system_area->sys_part_scale_tune[val-1].scale[11]-64);
  state_table->updates_enabled = true;
}
void JVlibForm::on_Tuning_MasterTune_select_valueChanged(double val) {
  setSysSingleValue(0x06, (val-427.4) / 0.2);
}

void JVlibForm::on_Tuning_Sync_button_clicked() {
  // get Scale Tuning data
  Tuning_Sync_status->off();
  get_scales();
  setScaleTunings(Patch_PerfPartNum_select->currentIndex()+1);  
}	// end on_Tuning_Sync_button_clicked

void JVlibForm::slotTuning_TempButtons(int val) {
  // redirect to Tuning_QueryTemp with correct parm
  // QByteArray Tuning_currentTuning, filled with 0x40 from create_...
  switch(val) {
    case 2: default:	// Equal temp
      state_table->tuning_type = EqualTemp;
      Tuning_BaseKey_select->setEnabled(false);
      Tuning_QueryTemp(2);
      break;
    case 3:		// Just temp
      state_table->tuning_type = JustTemp;
      Tuning_BaseKey_select->setEnabled(true);
      Tuning_QueryTemp(3);
      break;
    case 6:		// Pythagorean
      state_table->tuning_type = PythagTemp;
      Tuning_BaseKey_select->setEnabled(true);
      Tuning_QueryTemp(6);
      break;
    case 4:		// Meantone
      state_table->tuning_type = MeantoneTemp;
      Tuning_BaseKey_select->setEnabled(true);
      Tuning_QueryTemp(4);
      break;
    case 7:		// Well
      state_table->tuning_type = WellTemp;
      Tuning_BaseKey_select->setEnabled(true);
      Tuning_QueryTemp(7);
      break;
    case 5:		// Pure
      state_table->tuning_type = PureTemp;
      Tuning_BaseKey_select->setEnabled(true);
      Tuning_QueryTemp(5);
      break;
    case 1:		// Arabic
      state_table->tuning_type = ArabicTemp;
      Tuning_BaseKey_select->setEnabled(true);
      Tuning_QueryTemp(1);
      break;
    case 0:		// custom tuning
      state_table->tuning_type = CustomTemp;
      Tuning_BaseKey_select->setEnabled(true);
      break;
  }	// end Switch
  state_table->tuning_modified = false;
}	// end slotTuning_TempButtons

void JVlibForm::Tuning_QueryTemp(int val) {
  // fill Tuning_currentTuning from database
  // and call Tuning_setScaleTuning to update displays, which will update the synth
  QSqlQuery query(mysql);
  query.prepare("Select cents from Tuning where SerNumber = ?");
  query.bindValue(0, val);
  if (query.exec() == false) {
    puts("Query exec failed in Tuning_QueryTemp");
    query.finish();
    return;
  }
  if (query.size()==0) {
    puts("0 rows found in Tuning_QueryTemp");
    query.finish();
    return;
  }
  if (query.size() > 1) {
    puts("Too many rows found in Tuning_QueryTemp");
    query.finish();
    return;
  }
  if (query.first())
    Tuning_currentTuning = query.value(0).toByteArray();
  else {
    puts("query.first failed in Tuning_QueryTemp");
    query.finish();
    return;
  }
  query.finish();
  Tuning_setScaleTuning(Tuning_BaseKey_select->currentIndex());
}	// end Tuning_QueryTemp

void JVlibForm::Tuning_setScaleTuning(int val) {
  // set individual scale note tunings from the QByteArray Tuning_currentTuning
  // uses val = Tuning_BaseKey_select->currentIndex()
  // updating the display will update the synth
  int x=0;
  switch(val) {
    case 0: case 19:	// C Maj, a min
      x=0;
      break;
    case 2: case 21:	// D-flat Maj, b-flat min
      x=11;
      break;
    case 4: case 23:	// D 
      x=10;
      break;
    case 6: case 1:	// E-flat
      x=9;
      break;
    case 8: case 3:	// E
      x=8;
      break;
    case 10: case 5:	// F
      x=7;
      break;
    case 12: case 7:	// F#
      x=6;
      break;
    case 14: case 9:	// G
      x=5;
      break;
    case 16: case 11:	// A-flat
      x=4;
      break;
    case 18: case 13:	// A
      x=3;
      break;
    case 20: case 15:	// B-flat
      x=2;
      break;
    case 22: case 17:	// B
      x=1;
      break;

  }	// end Switch
  // x is the offset for C
  Tuning_PartTuneC_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64);x++;
  Tuning_PartTuneCs_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64);x++;
  Tuning_PartTuneD_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64);x++;
  Tuning_PartTuneDs_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64);x++;
  Tuning_PartTuneE_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64);x++;
  Tuning_PartTuneF_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64);x++;
  Tuning_PartTuneFs_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64);x++;
  Tuning_PartTuneG_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64);x++;
  Tuning_PartTuneGs_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64);x++;
  Tuning_PartTuneA_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64);x++;
  Tuning_PartTuneAs_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64);x++;
  Tuning_PartTuneB_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64);
}	// end Tuning_setScaleTuning

void JVlibForm::on_Tuning_BaseKey_select_currentIndexChanged(int val) {
  Tuning_setScaleTuning(val);
}

void JVlibForm::on_Tuning_LoadCustomTemp_button_clicked() {
  QString buf;
  
}
void JVlibForm::on_Tuning_SaveCustomTemp_button_clicked() {
  QString buf;
  
}
