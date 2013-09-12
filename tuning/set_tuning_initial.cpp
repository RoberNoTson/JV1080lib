#include	"JVlibForm.h"
#include	<QtGui>

void JVlibForm::setScaleTunings(int partnum) {
  // called after download from Synth, usually initiated by the Sync button
  state_table->updates_enabled = false;
  Tuning_ScaleTuning_enable->setEnabled(true);
  Tuning_ScaleTuning_enable->setChecked(system_area->sys_common.scale_tune_switch);
  
  if (partnum>16) return;
  int cur_chksum;
  if (state_table->patch_mode) {
    Tuning_PartTuneC_select->setValue(system_area->sys_patch_scale_tune.scale[0]-64);
    Tuning_PartTuneCs_select->setValue(system_area->sys_patch_scale_tune.scale[1]-64);
    Tuning_PartTuneD_select->setValue(system_area->sys_patch_scale_tune.scale[2]-64);
    Tuning_PartTuneDs_select->setValue(system_area->sys_patch_scale_tune.scale[3]-64);
    Tuning_PartTuneE_select->setValue(system_area->sys_patch_scale_tune.scale[4]-64);
    Tuning_PartTuneF_select->setValue(system_area->sys_patch_scale_tune.scale[5]-64);
    Tuning_PartTuneFs_select->setValue(system_area->sys_patch_scale_tune.scale[6]-64);
    Tuning_PartTuneG_select->setValue(system_area->sys_patch_scale_tune.scale[7]-64);
    Tuning_PartTuneGs_select->setValue(system_area->sys_patch_scale_tune.scale[8]-64);
    Tuning_PartTuneA_select->setValue(system_area->sys_patch_scale_tune.scale[9]-64);
    Tuning_PartTuneAs_select->setValue(system_area->sys_patch_scale_tune.scale[10]-64);
    Tuning_PartTuneB_select->setValue(system_area->sys_patch_scale_tune.scale[11]-64);
    Tuning_PartTune_select->setEnabled(false);
    Tuning_Parts_box->setEnabled(false);
    Tuning_PartNoneTuning_select->setChecked(true);
    cur_chksum = qChecksum((char *)&system_area->sys_patch_scale_tune.scale[0],12);
  } else {	// Performance mode
    Tuning_PartTune_select->setValue(partnum);
    Tuning_PartTuneC_select->setValue(system_area->sys_part_scale_tune[partnum-1].scale[0]-64);
    Tuning_PartTuneCs_select->setValue(system_area->sys_part_scale_tune[partnum-1].scale[1]-64);
    Tuning_PartTuneD_select->setValue(system_area->sys_part_scale_tune[partnum-1].scale[2]-64);
    Tuning_PartTuneDs_select->setValue(system_area->sys_part_scale_tune[partnum-1].scale[3]-64);
    Tuning_PartTuneE_select->setValue(system_area->sys_part_scale_tune[partnum-1].scale[4]-64);
    Tuning_PartTuneF_select->setValue(system_area->sys_part_scale_tune[partnum-1].scale[5]-64);
    Tuning_PartTuneFs_select->setValue(system_area->sys_part_scale_tune[partnum-1].scale[6]-64);
    Tuning_PartTuneG_select->setValue(system_area->sys_part_scale_tune[partnum-1].scale[7]-64);
    Tuning_PartTuneGs_select->setValue(system_area->sys_part_scale_tune[partnum-1].scale[8]-64);
    Tuning_PartTuneA_select->setValue(system_area->sys_part_scale_tune[partnum-1].scale[9]-64);
    Tuning_PartTuneAs_select->setValue(system_area->sys_part_scale_tune[partnum-1].scale[10]-64);
    Tuning_PartTuneB_select->setValue(system_area->sys_part_scale_tune[partnum-1].scale[11]-64);
    if (Tuning_ScaleTuning_enable->isChecked()) {
      Tuning_PartAllTuning_select->setChecked(true);
      Tuning_PartTune_select->setEnabled(Tuning_ScaleTuning_enable->isEnabled());
      Tuning_Parts_box->setEnabled(Tuning_ScaleTuning_enable->isEnabled());
    }
    cur_chksum = qChecksum((char *)&system_area->sys_part_scale_tune[partnum-1].scale[0],12);
  }
  JVlibForm::Tuning_currentTuning[0] = JVlibForm::Tuning_PartTuneC_select->value() + 64;
  JVlibForm::Tuning_currentTuning[1] = JVlibForm::Tuning_PartTuneCs_select->value() + 64;
  JVlibForm::Tuning_currentTuning[2] = JVlibForm::Tuning_PartTuneD_select->value() + 64;
  JVlibForm::Tuning_currentTuning[3] = JVlibForm::Tuning_PartTuneDs_select->value() + 64;
  JVlibForm::Tuning_currentTuning[4] = JVlibForm::Tuning_PartTuneE_select->value() + 64;
  JVlibForm::Tuning_currentTuning[5] = JVlibForm::Tuning_PartTuneF_select->value() + 64;
  JVlibForm::Tuning_currentTuning[6] = JVlibForm::Tuning_PartTuneFs_select->value() + 64;
  JVlibForm::Tuning_currentTuning[7] = JVlibForm::Tuning_PartTuneG_select->value() + 64;
  JVlibForm::Tuning_currentTuning[8] = JVlibForm::Tuning_PartTuneGs_select->value() + 64;
  JVlibForm::Tuning_currentTuning[9] = JVlibForm::Tuning_PartTuneA_select->value() + 64;
  JVlibForm::Tuning_currentTuning[10] = JVlibForm::Tuning_PartTuneAs_select->value() + 64;
  JVlibForm::Tuning_currentTuning[11] = JVlibForm::Tuning_PartTuneB_select->value() + 64;

  Tuning_PartTuning_box->setEnabled(Tuning_ScaleTuning_enable->isChecked());
  Tuning_Temperament_box->setEnabled(Tuning_ScaleTuning_enable->isChecked());
  // query the cur_chksum value to determine which temperament we are in
  if (cur_chksum==35508) Tuning_ArabicTemp_button->setChecked(true);
  else if (cur_chksum==14340) Tuning_EqualTemp_button->setChecked(true);
  else if (cur_chksum==53569) Tuning_JustTemp_button->setChecked(true);
  else if (cur_chksum==15732) Tuning_MeantoneTemp_button->setChecked(true);
  else if (cur_chksum==52045) Tuning_PureTemp_button->setChecked(true);
  else if (cur_chksum==11020) Tuning_PythagTemp_button->setChecked(true);
  else if (cur_chksum==40503) Tuning_WellTemp_button->setChecked(true);
  else Tuning_CustomTemp_button->setChecked(true);
  
  state_table->updates_enabled = true;
  Tuning_Sync_status->on();
  state_table->tuning_sync = true;
  state_table->tuning_modified = false;
}	// end setScaleTunings

