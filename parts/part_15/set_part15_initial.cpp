// set_initial.cpp
// for Parts tab, Part_15

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setPart15_Parms() {
  if (state_table->perf_mode) {
  // set Part 15 controls/displays based on the active area memory contents, 
  // which were just updated from the synth after a Sync button was clicked.
  //  state_table->updates_enabled = false was set by the calling program, do not change it here.
  QString str;
  Part15_Level_select->setValue(active_area->active_performance.perf_part[14].level);
  Part15_Level_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[14].level));
  Part15_Pan_select->setValue(active_area->active_performance.perf_part[14].pan);
  Part15_Pan_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[14].pan));
  Part15_ChorusSend_select->setValue(active_area->active_performance.perf_part[14].chorus_send_level);
  Part15_ChorusSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[14].chorus_send_level));
  Part15_ReverbSend_select->setValue(active_area->active_performance.perf_part[14].reverb_send_level);
  Part15_ReverbSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[14].reverb_send_level));
  Part15_OutputLevel_select->setValue(active_area->active_performance.perf_part[14].output_level);
  Part15_OutputLevel_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[14].output_level));
  Part15_Transpose_select->setValue(active_area->active_performance.perf_part[14].coarse_tune-48);
  Part15_Transpose_display->display(active_area->active_performance.perf_part[14].coarse_tune-48);
  Part15_TuneAdj_select->setValue(active_area->active_performance.perf_part[14].fine_tune-50);
  Part15_VoiceReserve_select->setValue(active_area->active_performance.perf_common.voice_reserve[14]);
  Part15_LowLimit_select->setValue(active_area->active_performance.perf_part[14].key_lower);
  Part15_HighLimit_select->setValue(active_area->active_performance.perf_part[14].key_upper);
  Part15_ReceiveMidi_enable->setChecked(active_area->active_performance.perf_part[14].MIDI_receive);
  Part15_MidiChannel_select->setValue(active_area->active_performance.perf_part[14].MIDI_channel+1);
  Part15_ReceivePrgChg_enable->setChecked(active_area->active_performance.perf_part[14].receive_program_change);
  Part15_ReceiveVolume_enable->setChecked(active_area->active_performance.perf_part[14].receive_volume);
  Part15_ReceiveHold_enable->setChecked(active_area->active_performance.perf_part[14].receive_hold_1);
  Part15_Output_select->setCurrentIndex(active_area->active_performance.perf_part[14].output);
  
  switch(active_area->active_performance.perf_part[14].patch_group_id) {
    case 0x01:  // User
      Part15_PatchGroup_select->setCurrentIndex(0);
      break;
    case 0x02:  // Exp A
	Part15_PatchGroup_select->setCurrentIndex(1);
	break;
    case 0x03:  // Preset A
	Part15_PatchGroup_select->setCurrentIndex(2);
	break;
    case 0x04:  // Preset B
	Part15_PatchGroup_select->setCurrentIndex(3);
	break;
    case 0x05:  // Preset C
	Part15_PatchGroup_select->setCurrentIndex(4);
	break;
    case 0x06:  // Preset D
	Part15_PatchGroup_select->setCurrentIndex(5);
	break;
    case 0x10:  // Exp B
	Part15_PatchGroup_select->setCurrentIndex(6);
	break;
    case 0x62:  // Exp C
	Part15_PatchGroup_select->setCurrentIndex(7);
	break;
    default:
	Part15_PatchGroup_select->setCurrentIndex(0);
	break;
  }	// end SWITCH
  Part15_PatchNumber_select->setValue((active_area->active_performance.perf_part[14].patch_num_high*16) + active_area->active_performance.perf_part[14].patch_num_low+1);
  Part15_PatchName_display->setText(QString::fromAscii(&active_area->active_perf_patch[14].patch_common.name[0],12));
  Part15_LowLimit_display->setText(funcNoteCalc(Part15_LowLimit_select->value()));
  Part15_HighLimit_display->setText(funcNoteCalc(Part15_HighLimit_select->value()));
    Part15_PatchGroup_select->setEnabled(Part15_ReceivePrgChg_enable->isChecked()); 
    Part15_MidiChannel_select->setEnabled(Part15_ReceiveMidi_enable->isChecked());
  }
  // set GM-MODE only parms
  if (state_table->GM_mode) {
      Part15_PatchGroup_select->setCurrentIndex(5);
      Part15_ReceiveMidi_enable->setChecked(true);
      Part15_ReceivePrgChg_enable->setChecked(true);
      Part15_ReceiveVolume_enable->setChecked(true);
      Part15_ReceiveHold_enable->setChecked(true);
      Part15_PatchNumber_select->setValue(15);
      Part15_PatchName_display->setText(getPartPatchName(14));
      Part15_MidiChannel_select->setValue(15);
      Part15_Transpose_select->setValue(0);
      Part15_TuneAdj_select->setValue(0);
      Part15_ReverbSend_select->setValue(0);
      Part15_ChorusSend_select->setValue(0);
      Part15_Pan_select->setValue(64);
      Part15_Level_select->setValue(127);
      Part15_OutputLevel_select->setValue(127);
      Part15_PatchGroup_select->setEnabled(false);
      Part15_VoiceReserve_select->setEnabled(false);
      Part15_OutputLevel_select->setEnabled(false);
      Part15_Output_select->setEnabled(false);
      Part15_MidiChannel_select->setEnabled(false);
  }
  // following are used for both Perf and GM modes
  Part15_TestTone_switch->setChecked(false);
  Part15_SetPatchMax();
  Part15_PatchNumber_select->setEnabled(Part15_ReceivePrgChg_enable->isChecked()); 
  Part15_TestTone_switch->setEnabled(Part15_ReceiveMidi_enable->isChecked());
  Part15_ReceivePrgChg_enable->setEnabled(AcceptProgramChg_switch->isChecked());
  Part15_ReceiveVolume_enable->setEnabled(AcceptVolumeChg_switch->isChecked());
  Part15_ReceiveHold_enable->setEnabled(AcceptHold1Chg_switch->isChecked());
}	// end setPart15_Parms
