// set_initial.cpp
// for Parts tab, Part_6

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setPart6_Parms() {
  if (state_table->perf_mode) {
  // set Part 6 controls/displays based on the active area memory contents, 
  // which were just updated from the synth after a Sync button was clicked.
  //  state_table->updates_enabled = false was set by the calling program, do not change it here.
  QString str;
  Part6_Level_select->setValue(active_area->active_performance.perf_part[5].level);
  Part6_Level_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[5].level));
  Part6_Pan_select->setValue(active_area->active_performance.perf_part[5].pan);
  Part6_Pan_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[5].pan));
  Part6_ChorusSend_select->setValue(active_area->active_performance.perf_part[5].chorus_send_level);
  Part6_ChorusSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[5].chorus_send_level));
  Part6_ReverbSend_select->setValue(active_area->active_performance.perf_part[5].reverb_send_level);
  Part6_ReverbSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[5].reverb_send_level));
  Part6_OutputLevel_select->setValue(active_area->active_performance.perf_part[5].output_level);
  Part6_OutputLevel_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[5].output_level));
  Part6_Transpose_select->setValue(active_area->active_performance.perf_part[5].coarse_tune-48);
  Part6_Transpose_display->display(active_area->active_performance.perf_part[5].coarse_tune-48);
  Part6_TuneAdj_select->setValue(active_area->active_performance.perf_part[5].fine_tune-50);
  Part6_VoiceReserve_select->setValue(active_area->active_performance.perf_common.voice_reserve[5]);
  Part6_LowLimit_select->setValue(active_area->active_performance.perf_part[5].key_lower);
  Part6_HighLimit_select->setValue(active_area->active_performance.perf_part[5].key_upper);
  Part6_ReceiveMidi_enable->setChecked(active_area->active_performance.perf_part[5].MIDI_receive);
  Part6_MidiChannel_select->setValue(active_area->active_performance.perf_part[5].MIDI_channel+1);
  Part6_ReceivePrgChg_enable->setChecked(active_area->active_performance.perf_part[5].receive_program_change);
  Part6_ReceiveVolume_enable->setChecked(active_area->active_performance.perf_part[5].receive_volume);
  Part6_ReceiveHold_enable->setChecked(active_area->active_performance.perf_part[5].receive_hold_1);
  Part6_Output_select->setCurrentIndex(active_area->active_performance.perf_part[5].output);
  Part6_VoiceMode_switch->setChecked(active_area->active_perf_patch[5].patch_common.key_assign_mode);
  Part6_VoiceMode_switch->setText(active_area->active_perf_patch[5].patch_common.key_assign_mode==0 ? QString("Poly") : QString("Solo"));
  
  switch(active_area->active_performance.perf_part[5].patch_group_id) {
    case 0x01:  // User
      Part6_PatchGroup_select->setCurrentIndex(0);
      break;
    case 0x02:  // Exp A
	Part6_PatchGroup_select->setCurrentIndex(1);
	break;
    case 0x03:  // Preset A
	Part6_PatchGroup_select->setCurrentIndex(2);
	break;
    case 0x04:  // Preset B
	Part6_PatchGroup_select->setCurrentIndex(3);
	break;
    case 0x05:  // Preset C
	Part6_PatchGroup_select->setCurrentIndex(4);
	break;
    case 0x06:  // Preset D
	Part6_PatchGroup_select->setCurrentIndex(5);
	break;
    case 0x10:  // Exp B
	Part6_PatchGroup_select->setCurrentIndex(6);
	break;
    case 0x62:  // Exp C
	Part6_PatchGroup_select->setCurrentIndex(7);
	break;
    default:
	Part6_PatchGroup_select->setCurrentIndex(0);
	break;
  }	// end SWITCH
  Part6_PatchNumber_select->setValue((active_area->active_performance.perf_part[5].patch_num_high*16) + active_area->active_performance.perf_part[5].patch_num_low+1);
  Part6_PatchName_display->setText(QString::fromAscii(&active_area->active_perf_patch[5].patch_common.name[0],12));
  Part6_LowLimit_display->setText(funcNoteCalc(Part6_LowLimit_select->value()));
  Part6_HighLimit_display->setText(funcNoteCalc(Part6_HighLimit_select->value()));
//  Part6_PatchGroup_select->setEnabled(Part6_ReceivePrgChg_enable->isChecked() && AcceptBankSel_switch->isChecked()); 
  Part6_MidiChannel_select->setEnabled(Part6_ReceiveMidi_enable->isChecked());
  Part6_ReceivePrgChg_enable->setEnabled(AcceptProgramChg_switch->isChecked() || AcceptBankSel_switch->isChecked());
  Part6_ReceiveVolume_enable->setEnabled(AcceptVolumeChg_switch->isChecked());
  Part6_ReceiveHold_enable->setEnabled(AcceptHold1Chg_switch->isChecked());
  }
  // set GM-MODE only parms
  if (state_table->GM_mode) {
      Part6_PatchGroup_select->setCurrentIndex(5);
      Part6_ReceiveMidi_enable->setChecked(true);
      Part6_ReceivePrgChg_enable->setChecked(true);
      Part6_ReceiveVolume_enable->setChecked(true);
      Part6_ReceiveHold_enable->setChecked(true);
      Part6_PatchNumber_select->setValue(6);
      Part6_PatchName_display->setText(getPartPatchName(5));
      Part6_MidiChannel_select->setValue(6);
      Part6_Transpose_select->setValue(0);
      Part6_TuneAdj_select->setValue(0);
      Part6_ReverbSend_select->setValue(0);
      Part6_ChorusSend_select->setValue(0);
      Part6_Pan_select->setValue(64);
      Part6_Level_select->setValue(127);
      Part6_OutputLevel_select->setValue(127);
      Part6_PatchGroup_select->setEnabled(false);
      Part6_VoiceReserve_select->setEnabled(false);
      Part6_OutputLevel_select->setEnabled(false);
      Part6_Output_select->setEnabled(false);
      Part6_MidiChannel_select->setEnabled(false);
      Part6_ReceivePrgChg_enable->setEnabled(false);
      Part6_ReceiveVolume_enable->setEnabled(false);
      Part6_ReceiveHold_enable->setEnabled(false);
      Part6_ReceiveMidi_enable->setEnabled(false);
      Part6_VoiceMode_switch->setChecked(false);
      Part6_VoiceMode_switch->setText("Poly");
      Part6_VoiceMode_switch->setEnabled(true);
  }
  // following are used for both Perf and GM modes
  Part6_TestTone_switch->setChecked(false);
  Part6_SetPatchMax();
//  Part6_PatchNumber_select->setEnabled(Part6_ReceivePrgChg_enable->isChecked() && AcceptProgramChg_switch->isChecked()); 
  Part6_TestTone_switch->setEnabled(Part6_ReceiveMidi_enable->isChecked());
}	// end setPart6_Parms
