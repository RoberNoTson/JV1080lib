// tuning_slots.cpp
/* Contains:
 * on_Tuning_ScaleTuning_enable_toggled
 * on_Tuning_PartTuneC_select_valueChanged
 * on_Tuning_PartTuneCs_select_valueChanged
 * on_Tuning_PartTuneD_select_valueChanged
 * on_Tuning_PartTuneDs_select_valueChanged
 * on_Tuning_PartTuneE_select_valueChanged
 * on_Tuning_PartTuneF_select_valueChanged
 * on_Tuning_PartTuneFs_select_valueChanged
 * on_Tuning_PartTuneG_select_valueChanged
 * on_Tuning_PartTuneGs_select_valueChanged
 * on_Tuning_PartTuneA_select_valueChanged
 * on_Tuning_PartTuneAs_select_valueChanged
 * on_Tuning_PartTuneB_select_valueChanged
 * on_Tuning_PartTune_select_valueChanged
 * on_Tuning_MasterTune_select_valueChanged
 * on_Tuning_Sync_button_clicked
 * on_Tuning_BaseKey_select_currentIndexChanged
 * on_Tuning_LoadCustomTemp_button_clicked
 * on_Tuning_SaveCustomTemp_button_clicked
 * slotTuning_TempButtons
 */

#include	"JVlibForm.h"
#include	<QtGui>

void JVlibForm::on_Tuning_ScaleTuning_enable_toggled(bool status) {
  // Tuning_ScaleTuning_enable
  if (state_table->perf_mode)  { 
    Tuning_Parts_box->setEnabled(status);
    Tuning_PartTune_select->setEnabled(status);
  }
  Tuning_PartTuning_box->setEnabled(status);
  Tuning_Temperament_box->setEnabled(status);
  state_table->tuningTab_enable = true;
  // update the system_area
  system_area->sys_common.scale_tune_switch = status;
  // update the synth
  if (state_table->updates_enabled)
    setSysSingleValue(7,status);
}	// end on_Tuning_ScaleTuning_enable_toggled

// Scale note tuning
void JVlibForm::on_Tuning_PartTuneC_select_valueChanged(int val) {
  TuningStdUpdate(0x00, val+64);
}
void JVlibForm::on_Tuning_PartTuneCs_select_valueChanged(int val) {
  TuningStdUpdate(0x01, val+64);
}
void JVlibForm::on_Tuning_PartTuneD_select_valueChanged(int val) {
  TuningStdUpdate(0x02, val+64);
}
void JVlibForm::on_Tuning_PartTuneDs_select_valueChanged(int val) {
  TuningStdUpdate(0x03, val+64);
}
void JVlibForm::on_Tuning_PartTuneE_select_valueChanged(int val) {
  TuningStdUpdate(0x04, val+64);
}
void JVlibForm::on_Tuning_PartTuneF_select_valueChanged(int val) {
  TuningStdUpdate(0x05, val+64);
}
void JVlibForm::on_Tuning_PartTuneFs_select_valueChanged(int val) {
  TuningStdUpdate(0x06, val+64);
}
void JVlibForm::on_Tuning_PartTuneG_select_valueChanged(int val) {
  TuningStdUpdate(0x07, val+64);
}
void JVlibForm::on_Tuning_PartTuneGs_select_valueChanged(int val) {
  TuningStdUpdate(0x08, val+64);
}
void JVlibForm::on_Tuning_PartTuneA_select_valueChanged(int val) {
  TuningStdUpdate(0x09, val+64);
}
void JVlibForm::on_Tuning_PartTuneAs_select_valueChanged(int val) {
  TuningStdUpdate(0x0A, val+64);
}
void JVlibForm::on_Tuning_PartTuneB_select_valueChanged(int val) {
  TuningStdUpdate(0x0B, val+64);
}

void JVlibForm::on_Tuning_PartTune_select_valueChanged(int val) {
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
  QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
  Tuning_Sync_status->off();
  get_scales();	// download all scale data, relative to Patch or Perf mode
  setScaleTunings(Patch_PerfPartNum_select->currentIndex()+1);	// set for currently synced Part Patch, if any; parm is ignored when in Patch mode
  QApplication::restoreOverrideCursor();
}	// end on_Tuning_Sync_button_clicked

void JVlibForm::on_Tuning_BaseKey_select_currentIndexChanged(int val) {
//  Tuning_setScaleTuning(val);
  int x=0;
  // set 'x' to where 'C' falls in the chosen key
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
    Tuning_PartTuneC_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
    Tuning_PartTuneCs_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
    Tuning_PartTuneD_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
    Tuning_PartTuneDs_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
    Tuning_PartTuneE_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
    Tuning_PartTuneF_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
    Tuning_PartTuneFs_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
    Tuning_PartTuneG_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
    Tuning_PartTuneGs_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
    Tuning_PartTuneA_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
    Tuning_PartTuneAs_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
    Tuning_PartTuneB_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64);
}

void JVlibForm::on_Tuning_LoadCustomTemp_button_clicked() {
// NOTE: tbd
  QString buf;
}

void JVlibForm::on_Tuning_SaveCustomTemp_button_clicked() {
// NOTE: tbd
  QString buf;
}

void JVlibForm::slotTuning_TempButtons(int val) {
  // redirect to Tuning_QueryTemp with correct parm
  // NOTE: button numbers do not correspond to the display order
  switch(val) {
    case 2: default:	// Equal temp
      state_table->tuning_type = EqualTemp;
      Tuning_BaseKey_select->setEnabled(false);
      Tuning_currentTuning.fill(0x40,12*16);
      Tuning_PartTuneC_select->setValue(0);
      Tuning_PartTuneCs_select->setValue(0);
      Tuning_PartTuneD_select->setValue(0);
      Tuning_PartTuneDs_select->setValue(0);
      Tuning_PartTuneE_select->setValue(0);
      Tuning_PartTuneF_select->setValue(0);
      Tuning_PartTuneFs_select->setValue(0);
      Tuning_PartTuneG_select->setValue(0);
      Tuning_PartTuneGs_select->setValue(0);
      Tuning_PartTuneA_select->setValue(0);
      Tuning_PartTuneAs_select->setValue(0);
      Tuning_PartTuneB_select->setValue(0);
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

