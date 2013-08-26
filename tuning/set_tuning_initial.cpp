#include	"JVlibForm.h"
#include	<QtGui>
//#include	"tuning_slots.h"

void JVlibForm::setScaleTunings(int partnum) {
  // called after download from Synth, usually initiated by the Sync button
  state_table->updates_enabled = false;
  Tuning_ScaleTuning_enable->setEnabled(true);

  if (partnum>16) return;
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
  } else {
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
  }
  
  Tuning_BaseKey_select->setEnabled(Tuning_ScaleTuning_enable->isChecked());
  Tuning_Temperament_box->setEnabled(Tuning_ScaleTuning_enable->isChecked());
  Tuning_PartTuning_box->setEnabled(Tuning_ScaleTuning_enable->isChecked());
  state_table->updates_enabled = true;
  Tuning_Sync_status->on();
  state_table->tuning_sync = true;
  state_table->tuning_modified = false;
}	// end setScaleTunings

