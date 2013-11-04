// tuning_slots.cpp
/* Contains:
 * on_Tuning_Sync_button_clicked
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
 * on_Tuning_BaseKey_A_select_toggled
 * on_Tuning_BaseKey_As_select_toggled
 * on_Tuning_BaseKey_B_select_toggled
 * on_Tuning_BaseKey_C_select_toggled
 * on_Tuning_BaseKey_Cs_select_toggled
 * on_Tuning_BaseKey_D_select_toggled
 * on_Tuning_BaseKey_Ds_select_toggled
 * on_Tuning_BaseKey_E_select_toggled
 * on_Tuning_BaseKey_F_select_toggled
 * on_Tuning_BaseKey_Fs_select_toggled
 * on_Tuning_BaseKey_G_select_toggled
 * on_Tuning_BaseKey_Gs_select_toggled
 * on_Tuning_LoadCustomTemp_button_clicked
 * on_Tuning_SaveCustomTemp_button_clicked
 * slotTuning_TempButtons
 */

#include	"JVlibForm.h"
#include	<QtGui>

void JVlibForm::on_Tuning_ScaleTuning_enable_toggled(bool status) {
  // Tuning_ScaleTuning_enable
  if (state_table->perf_mode)  { 
    Tuning_Parts_box->setEnabled(status && state_table->tuning_sync);
    Tuning_PartTune_select->setEnabled(status && state_table->tuning_sync);
  }
  Tuning_PartTuning_box->setEnabled(status && state_table->tuning_sync);
  Tuning_Temperament_box->setEnabled(status && state_table->tuning_sync);
  state_table->tuningTab_enable = true;
  // update the system_area
  system_area->sys_common.scale_tune_switch = status;
  // update the synth
  if (state_table->updates_enabled)
    setSysSingleValue(7,status);
}	// end on_Tuning_ScaleTuning_enable_toggled

// Scale note tuning
void JVlibForm::on_Tuning_PartTuneC_select_valueChanged(int val) {
  Tuning_NoteUpdate(0x00, val+64);
}
void JVlibForm::on_Tuning_PartTuneCs_select_valueChanged(int val) {
  Tuning_NoteUpdate(0x01, val+64);
}
void JVlibForm::on_Tuning_PartTuneD_select_valueChanged(int val) {
  Tuning_NoteUpdate(0x02, val+64);
}
void JVlibForm::on_Tuning_PartTuneDs_select_valueChanged(int val) {
  Tuning_NoteUpdate(0x03, val+64);
}
void JVlibForm::on_Tuning_PartTuneE_select_valueChanged(int val) {
  Tuning_NoteUpdate(0x04, val+64);
}
void JVlibForm::on_Tuning_PartTuneF_select_valueChanged(int val) {
  Tuning_NoteUpdate(0x05, val+64);
}
void JVlibForm::on_Tuning_PartTuneFs_select_valueChanged(int val) {
  Tuning_NoteUpdate(0x06, val+64);
}
void JVlibForm::on_Tuning_PartTuneG_select_valueChanged(int val) {
  Tuning_NoteUpdate(0x07, val+64);
}
void JVlibForm::on_Tuning_PartTuneGs_select_valueChanged(int val) {
  Tuning_NoteUpdate(0x08, val+64);
}
void JVlibForm::on_Tuning_PartTuneA_select_valueChanged(int val) {
  Tuning_NoteUpdate(0x09, val+64);
}
void JVlibForm::on_Tuning_PartTuneAs_select_valueChanged(int val) {
  Tuning_NoteUpdate(0x0A, val+64);
}
void JVlibForm::on_Tuning_PartTuneB_select_valueChanged(int val) {
  Tuning_NoteUpdate(0x0B, val+64);
}

void JVlibForm::on_Tuning_PartTune_select_valueChanged(int val) {
  int x = val-1;
  state_table->updates_enabled = false;
  Tuning_PartTuneC_select->setValue(system_area->sys_part_scale_tune[x].scale[0] - 64);
  Tuning_PartTuneCs_select->setValue(system_area->sys_part_scale_tune[x].scale[1] - 64);
  Tuning_PartTuneD_select->setValue(system_area->sys_part_scale_tune[x].scale[2] - 64);
  Tuning_PartTuneDs_select->setValue(system_area->sys_part_scale_tune[x].scale[3] - 64);
  Tuning_PartTuneE_select->setValue(system_area->sys_part_scale_tune[x].scale[4] - 64);
  Tuning_PartTuneF_select->setValue(system_area->sys_part_scale_tune[x].scale[5] - 64);
  Tuning_PartTuneFs_select->setValue(system_area->sys_part_scale_tune[x].scale[6] - 64);
  Tuning_PartTuneG_select->setValue(system_area->sys_part_scale_tune[x].scale[7] - 64);
  Tuning_PartTuneGs_select->setValue(system_area->sys_part_scale_tune[x].scale[8] - 64);
  Tuning_PartTuneA_select->setValue(system_area->sys_part_scale_tune[x].scale[9] - 64);
  Tuning_PartTuneAs_select->setValue(system_area->sys_part_scale_tune[x].scale[10] - 64);
  Tuning_PartTuneB_select->setValue(system_area->sys_part_scale_tune[x].scale[11] - 64);
  state_table->updates_enabled = true;
}
void JVlibForm::on_Tuning_MasterTune_select_valueChanged(double val) {
  setSysSingleValue(0x06, (val-427.4) / 0.2);
}

void JVlibForm::on_Tuning_Sync_button_clicked() {
  // get Scale Tuning data
  if (!state_table->jv_connect || !state_table->updates_enabled) return;
  Tuning_Sync_status->off();
//  get_scales();	// download all scale data, relative to Patch or Perf mode
  int	x,err;
  int	Stop=0;
  unsigned char	buf[8];
  char scale_size[] = { 0x0,0x0,0x0,0x0C };
  
  JVlibForm::statusbar->showMessage("Loading scale tunings",0);
  memset(buf,0,sizeof(buf));
  buf[7] = 0x0C;	// scale size
  if (open_ports() == EXIT_FAILURE) return;
  QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
  if (state_table->perf_mode) {
    // get the 16 Part scales
    for (x=0;x<16;x++) {
      printf("Scale #%d\n",x);
      buf[2] = 0x10 + x;		// scale number
      RetryB:
      if (sysex_request(buf,8) == EXIT_FAILURE) { close_ports(); QApplication::restoreOverrideCursor(); return; }
      err = sysex_get((unsigned char *)&system_area->sys_part_scale_tune[x].scale[0], (char *)scale_size);
      if (err == EXIT_FAILURE) { close_ports(); QApplication::restoreOverrideCursor(); return; }
      if (err==2 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryB; }
      if (err==3 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryB; }
      if (err != EXIT_SUCCESS) { close_ports(); QApplication::restoreOverrideCursor(); return; }
      Stop=0;
//      Tuning_currentTuning.insert(x*12, (char *)&system_area->sys_part_scale_tune[x].scale[0], 12);
//      Tuning_currentTuning.replace(x*12, 12, (char *)&system_area->sys_part_scale_tune[x].scale[0]);
    }	// end FOR 16 part scales
  } 
  else if (state_table->patch_mode) {
    // get one patch scale tune
    buf[2] = 0x20;
    RetryC:
    if (sysex_request(buf,8) == EXIT_FAILURE) { close_ports(); QApplication::restoreOverrideCursor(); return; }
    err = sysex_get((unsigned char *)&system_area->sys_patch_scale_tune.scale[0], (char *)scale_size);
    if (err == EXIT_FAILURE) { close_ports(); QApplication::restoreOverrideCursor(); return; }
    if (err==2 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryC; }
    if (err==3 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryC; }
    if (err != EXIT_SUCCESS) { close_ports(); QApplication::restoreOverrideCursor(); return; }
    Stop=0;
//    Tuning_currentTuning.setRawData((char *)&system_area->sys_patch_scale_tune.scale[0], 12);
  }
  close_ports();
  statusbar->showMessage("Scale tunings downloaded",0);
  state_table->tuning_modified = false;
  state_table->tuning_sync = true;
  setScaleTunings(Patch_PerfPartNum_select->currentIndex()+1);	// set for currently synced Part Patch, if any; parm is ignored when in Patch mode
  QApplication::restoreOverrideCursor();
}	// end on_Tuning_Sync_button_clicked

void JVlibForm::on_Tuning_BaseKey_A_select_toggled(bool status) {
  if (status) Tuning_BaseKey_set(3);
}
void JVlibForm::on_Tuning_BaseKey_As_select_toggled(bool status) {
  if (status) Tuning_BaseKey_set(2);
}
void JVlibForm::on_Tuning_BaseKey_B_select_toggled(bool status) {
  if (status) Tuning_BaseKey_set(1);
}
void JVlibForm::on_Tuning_BaseKey_C_select_toggled(bool status) {
  if (status) Tuning_BaseKey_set(0);
}
void JVlibForm::on_Tuning_BaseKey_Cs_select_toggled(bool status) {
  if (status) Tuning_BaseKey_set(11);
}
void JVlibForm::on_Tuning_BaseKey_D_select_toggled(bool status) {
  if (status) Tuning_BaseKey_set(10);
}
void JVlibForm::on_Tuning_BaseKey_Ds_select_toggled(bool status) {
  if (status) Tuning_BaseKey_set(9);
}
void JVlibForm::on_Tuning_BaseKey_E_select_toggled(bool status) {
  if (status) Tuning_BaseKey_set(8);
}
void JVlibForm::on_Tuning_BaseKey_F_select_toggled(bool status) {
  if (status) Tuning_BaseKey_set(7);
}
void JVlibForm::on_Tuning_BaseKey_Fs_select_toggled(bool status) {
  if (status) Tuning_BaseKey_set(6);
}
void JVlibForm::on_Tuning_BaseKey_G_select_toggled(bool status) {
  if (status) Tuning_BaseKey_set(5);
}
void JVlibForm::on_Tuning_BaseKey_Gs_select_toggled(bool status) {
  if (status) Tuning_BaseKey_set(4);
}

void JVlibForm::on_Tuning_LoadCustomTemp_button_clicked() {
  open();
  setScaleTunings(1);
}

void JVlibForm::on_Tuning_SaveCustomTemp_button_clicked() {
  save();
}

void JVlibForm::slotTuning_TempButtons(int val) {
  // redirect to Tuning_QueryTemp with correct parm
  switch(val) {
    case 0: default:	// Equal temp
      state_table->tuning_type = EqualTemp;
      Tuning_BaseKey_C_select->blockSignals(true);
      Tuning_BaseKey_C_select->setChecked(true);
      Tuning_BaseKey_C_select->blockSignals(false);
      Tuning_BaseKey_box->setEnabled(false);
      Tuning_QueryTemp(0);
      break;
    case 1:		// Just temp
      state_table->tuning_type = JustTemp;
      Tuning_BaseKey_box->setEnabled(true);
      Tuning_QueryTemp(1);
      break;
    case 2:		// Pythagorean
      state_table->tuning_type = PythagTemp;
      Tuning_BaseKey_box->setEnabled(true);
      Tuning_QueryTemp(2);
      break;
    case 3:		// Pure
      state_table->tuning_type = PureTemp;
      Tuning_BaseKey_box->setEnabled(true);
      Tuning_QueryTemp(3);
    break;
    case 4:		// Well
      state_table->tuning_type = WellTemp;
      Tuning_BaseKey_box->setEnabled(true);
      Tuning_QueryTemp(4);
      break;
    case 5:		// Meantone
      state_table->tuning_type = MeantoneTemp;
      Tuning_BaseKey_box->setEnabled(true);
      Tuning_QueryTemp(5);
      break;
    case 6:		// Arabic
      state_table->tuning_type = ArabicTemp;
      Tuning_BaseKey_box->setEnabled(true);
      Tuning_QueryTemp(6);
      break;
    case 7:		// custom tuning
      state_table->tuning_type = CustomTemp;
      Tuning_BaseKey_box->setEnabled(true);
      break;
  }	// end Switch
  state_table->tuning_modified = false;
}	// end slotTuning_TempButtons
