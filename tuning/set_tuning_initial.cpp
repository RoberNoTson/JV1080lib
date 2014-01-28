#include	"JVlibForm.h"
#include	<QtGui>

void JVlibForm::setScaleTunings(int partnum) {
  // called after download from Synth, usually initiated by the Sync button
  // in Perf mode each Part has its own scale tuning
  state_table->updates_enabled = false;
  Tuning_ScaleTuning_enable->setEnabled(true);
  Tuning_ScaleTuning_enable->setChecked(system_area->sys_common.scale_tune_switch);
  
  if (partnum>16) return;
  if (state_table->patch_mode) {	// Patch mode
    Tuning_currentTuning.truncate(0);
    for (int x=0;x<12;x++) {
      Tuning_currentTuning[x] = system_area->sys_patch_scale_tune.scale[x];
    }
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
  }	// end Patch mode
  // Performance mode
  else if (state_table->perf_mode) {
    Tuning_currentTuning.truncate(0);
    for (int y=0;y<16;y++) {
      int x = 12 * y;
      for (int z=0;z<12;z++) {
	JVlibForm::Tuning_currentTuning[z+x] = system_area->sys_part_scale_tune[y].scale[z];
      }
    }
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
  }	// end Perf mode

  Tuning_PartTuning_box->setEnabled(Tuning_ScaleTuning_enable->isChecked() && state_table->tuning_sync);
  Tuning_Temperament_box->setEnabled(Tuning_ScaleTuning_enable->isChecked() && state_table->tuning_sync);
  calc_tuning();
  Tuning_LoadCustomTemp_button->setEnabled(Tuning_CustomTemp_button->isChecked());
  Tuning_SaveCustomTemp_button->setEnabled(Tuning_CustomTemp_button->isChecked());
  Tuning_CustomName_display->clear();
  Tuning_CustomComment_display->clear();
  state_table->updates_enabled = true;
  Tuning_Sync_status->on();
  state_table->tuning_sync = true;
  state_table->tuning_modified = false;
}	// end setScaleTunings
