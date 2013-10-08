// set_initial.cpp
// setSystemParms() for system tab

#include	"JVlibForm.h"
#include	<QtGui>

void JVlibForm::setSystemParms() {
  // Called from slotGetActiveSystem, after all System data is received from the synth,
  // triggered after the Port is selected or the Download button is clicked
  
  state_table->updates_enabled = false;
  Tuning_MasterTune_select->setValue((system_area->sys_common.master_tune*0.2)+427.4);
  Tuning_ScaleTuning_enable->setChecked(system_area->sys_common.scale_tune_switch);
  EFX_switch->setChecked(system_area->sys_common.EFX_switch);
  Chorus_switch->setChecked(system_area->sys_common.chorus_switch);
  Reverb_switch->setChecked(system_area->sys_common.reverb_switch);
  PatchRemain_switch->setChecked(system_area->sys_common.patch_remain);
  AcceptProgramChg_switch->setChecked(system_area->sys_common.receive_program_change);
  AcceptBankSel_switch->setChecked(system_area->sys_common.receive_bank_select);
  AcceptControlChange_switch->setChecked(system_area->sys_common.receive_control_change);
  AcceptModulation_switch->setChecked(system_area->sys_common.receive_modulation);
  AcceptVolumeChg_switch->setChecked(system_area->sys_common.receive_volume);
  AcceptHold1Chg_switch->setChecked(system_area->sys_common.receive_hold_1);
  AcceptBender_switch->setChecked(system_area->sys_common.receive_bender);
  AcceptAftertouch_switch->setChecked(system_area->sys_common.receive_aftertouch);
  SysClock_select->setCurrentIndex(system_area->sys_common.clock_source);
  SysTapControl_select->setCurrentIndex(system_area->sys_common.tap_control_source);
  SysVolumeControl_select->setCurrentIndex(system_area->sys_common.volume_control_source);
  SysHoldControl_select->setCurrentIndex(system_area->sys_common.hold_control_source);
  SysPeakControl_select->setCurrentIndex(system_area->sys_common.peak_control_source);
  SysAftertouchControl_select->setCurrentIndex(system_area->sys_common.aftertouch_control_source);
  SysMode_select->blockSignals(true);
  SysMode_select->setCurrentIndex(system_area->sys_common.panel_mode);
  SysMode_select->blockSignals(false);
  SysControlChg1Number_select->setValue(system_area->sys_common.sys_control_source_1);
  SysControlChg2Number_select->setValue(system_area->sys_common.sys_control_source_2);
  SysPatchRecvChannel_select->setValue(system_area->sys_common.patch_receive_channel+1);
  SysControlRecvChannel_select->setValue(system_area->sys_common.control_channel+1);
  SysPerfSelect->setCurrentIndex(system_area->sys_common.perf_num<0x20 ? 0 :
    (system_area->sys_common.perf_num<60 ? 1 : 2));
  SysPerfNumber->setValue(system_area->sys_common.perf_num<0x20?system_area->sys_common.perf_num+1:
    (system_area->sys_common.perf_num<60?system_area->sys_common.perf_num-0x3F:system_area->sys_common.perf_num-0x5F));
  SysPatchNumber->setValue(system_area->sys_common.patch_num_low+(system_area->sys_common.patch_num_high*16)+1);
  SysPreviewMode_switch->setChecked(system_area->sys_common.preview_mode);
  SysPreviewMode_switch->setText( system_area->sys_common.preview_mode==0 ? QString::fromUtf8("Single") : QString::fromUtf8("Chord") );
  SysPreviewNote1_select->setValue(system_area->sys_common.preview_key_set_1);
  SysPreviewNote2_select->setValue(system_area->sys_common.preview_key_set_2);
  SysPreviewNote3_select->setValue(system_area->sys_common.preview_key_set_3);
  SysPreviewNote4_select->setValue(system_area->sys_common.preview_key_set_4);
  SysPreviewNote1_display->setText(funcNoteCalc(system_area->sys_common.preview_key_set_1));
  SysPreviewNote2_display->setText(funcNoteCalc(system_area->sys_common.preview_key_set_2));
  SysPreviewNote3_display->setText(funcNoteCalc(system_area->sys_common.preview_key_set_3));
  SysPreviewNote4_display->setText(funcNoteCalc(system_area->sys_common.preview_key_set_4));
  SysPreviewNote1_volume->setValue(system_area->sys_common.preview_velocity_set_1);
  SysPreviewNote2_volume->setValue(system_area->sys_common.preview_velocity_set_2);
  SysPreviewNote3_volume->setValue(system_area->sys_common.preview_velocity_set_3);
  SysPreviewNote4_volume->setValue(system_area->sys_common.preview_velocity_set_4);
  // SysPatchSelect
  switch(system_area->sys_common.patch_group_id) {
    case 0x01:	// User
      SysPatchSelect->setCurrentIndex(0);
      SysPatchNumber->setMaximum(128);
      break;
    case 0x02:	// Exp A
      SysPatchSelect->setCurrentIndex(1);
      SysPatchNumber->setMaximum(255);
      break;
    case 0x03:	// Preset A
      SysPatchSelect->setCurrentIndex(2);
      SysPatchNumber->setMaximum(128);
      break;
    case 0x04:	// Preset B
      SysPatchSelect->setCurrentIndex(3);
      SysPatchNumber->setMaximum(128);
      break;
    case 0x05:	// Preset C
      SysPatchSelect->setCurrentIndex(4);
      SysPatchNumber->setMaximum(128);
      break;
    case 0x06:	// Preset D
      SysPatchSelect->setCurrentIndex(5);
      SysPatchNumber->setMaximum(128);
      break;
    case 0x10:	// Exp B
      SysPatchSelect->setCurrentIndex(6);
      SysPatchNumber->setMaximum(255);
      break;
    case 0x62:	// Exp C
      SysPatchSelect->setCurrentIndex(7);
      SysPatchNumber->setMaximum(255);
      break;
    default:
      SysPatchSelect->setCurrentIndex(0);
      SysPatchNumber->setMaximum(128);
      break;
  }	// end patch source
  // SysControlSource1
  switch(system_area->sys_common.sys_control_source_1) {
    case 96:
      SysControlSource1_select->setCurrentIndex(1);
      SysControlChg1Number_select->setEnabled(false);
      SysControlChg1Number_select->setValue(0);
      break;
    case 97:
      SysControlSource1_select->setCurrentIndex(2);
      SysControlChg1Number_select->setEnabled(false);
      SysControlChg1Number_select->setValue(0);
      break;
    default:
      SysControlSource1_select->setCurrentIndex(0);
      SysControlChg1Number_select->setEnabled(true);
      SysControlChg1Number_select->setValue(system_area->sys_common.sys_control_source_1);
      break;
  }	// end SysControlSource1
  // SysControlSource2
  switch(system_area->sys_common.sys_control_source_2) {
    case 96:
      SysControlSource2_select->setCurrentIndex(1);
      SysControlChg2Number_select->setEnabled(false);
      SysControlChg2Number_select->setValue(0);
      break;
    case 97:
      SysControlSource2_select->setCurrentIndex(2);
      SysControlChg2Number_select->setEnabled(false);
      SysControlChg2Number_select->setValue(0);
      break;
    default:
      SysControlSource2_select->setCurrentIndex(0);
      SysControlChg2Number_select->setEnabled(true);
      SysControlChg2Number_select->setValue(system_area->sys_common.sys_control_source_2);
      break;
  }	// end SysControlSource2
  
  Patch_BenderRange_box->setEnabled(system_area->sys_common.receive_bender);
  
  if (system_area->sys_common.panel_mode == 0) {	// Performance
    state_table->perf_mode = true;
    state_table->patch_mode = false;
    getSysPerfName();
    PerfGroup_select->setCurrentIndex(SysPerfSelect->currentIndex());
    PerfNumber_select->setValue(SysPerfNumber->value());
    PartsPerfGroup_display->setText(PerfGroup_select->currentText());
    PartsPerfNumber_display->setText(QString::number(SysPerfNumber->value()));
  } else if (system_area->sys_common.panel_mode == 1) {		// Patch
    state_table->perf_mode = false;
    state_table->patch_mode = true;
    getSysPatchName();
    Patch_Group_select->setCurrentIndex(SysPatchSelect->currentIndex());
    Patch_Number_select->setValue(SysPatchNumber->value());
    Patch_Sync_button->setEnabled(true);
    PatchEFX_Number_display->setText(QString::number(SysPatchNumber->value()));
    PatchEFX_Group_display->setText(Patch_Group_select->currentText());
  } else 			// GM mode
    return;
  // setup Tone_InstrFamily list
  if (state_table->db_connect) {
    Tone_WaveChooser_select->clear();
    QSqlQuery query("Select distinct(Instruments) from wave_list",mysql);
    Tone_InstrFamily_select->blockSignals(true);
    Tone_InstrFamily_select->clear();
    while (query.next()) {
      Tone_InstrFamily_select->insertItem(0,query.value(0).toString());
    }
    Tone_InstrFamily_select->blockSignals(false);
    query.finish();
  }
  System_PlayMidi_status->off();
  state_table->updates_enabled = true;
  state_table->system_sync = true;
  state_table->system_modified = false;
  System_Sync_status->on();
}	// end setSystemParms

