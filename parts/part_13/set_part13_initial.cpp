// set_initial.cpp
// for Parts tab, Part_13

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setPart13_Parms() {
  if (state_table->perf_mode) {
  // set Part 13 controls/displays based on the active area memory contents, 
  // which were just updated from the synth after a Sync button was clicked.
  //  state_table->updates_enabled = false was set by the calling program, do not change it here.
  QString str;
  Part13_Level_select->setValue(active_area->active_performance.perf_part[12].level);
  Part13_Level_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[12].level));
  Part13_Pan_select->setValue(active_area->active_performance.perf_part[12].pan);
  Part13_Pan_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[12].pan));
  Part13_ChorusSend_select->setValue(active_area->active_performance.perf_part[12].chorus_send_level);
  Part13_ChorusSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[12].chorus_send_level));
  Part13_ReverbSend_select->setValue(active_area->active_performance.perf_part[12].reverb_send_level);
  Part13_ReverbSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[12].reverb_send_level));
  Part13_OutputLevel_select->setValue(active_area->active_performance.perf_part[12].output_level);
  Part13_OutputLevel_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[12].output_level));
  Part13_Transpose_select->setValue(active_area->active_performance.perf_part[12].coarse_tune-48);
  Part13_Transpose_display->display(active_area->active_performance.perf_part[12].coarse_tune-48);
  Part13_TuneAdj_select->setValue(active_area->active_performance.perf_part[12].fine_tune-50);
  Part13_VoiceReserve_select->setValue(active_area->active_performance.perf_common.voice_reserve[12]);
  Part13_LowLimit_select->setValue(active_area->active_performance.perf_part[12].key_lower);
  Part13_HighLimit_select->setValue(active_area->active_performance.perf_part[12].key_upper);
  Part13_ReceiveMidi_enable->setChecked(active_area->active_performance.perf_part[12].MIDI_receive);
  Part13_MidiChannel_select->setValue(active_area->active_performance.perf_part[12].MIDI_channel+1);
  Part13_ReceivePrgChg_enable->setChecked(active_area->active_performance.perf_part[12].receive_program_change);
  Part13_ReceiveVolume_enable->setChecked(active_area->active_performance.perf_part[12].receive_volume);
  Part13_ReceiveHold_enable->setChecked(active_area->active_performance.perf_part[12].receive_hold_1);
  Part13_Output_select->setCurrentIndex(active_area->active_performance.perf_part[12].output);
  
  switch(active_area->active_performance.perf_part[12].patch_group_id) {
    case 0x01:  // User
      Part13_PatchGroup_select->setCurrentIndex(0);
      break;
    case 0x02:  // Exp A
	Part13_PatchGroup_select->setCurrentIndex(1);
	break;
    case 0x03:  // Preset A
	Part13_PatchGroup_select->setCurrentIndex(2);
	break;
    case 0x04:  // Preset B
	Part13_PatchGroup_select->setCurrentIndex(3);
	break;
    case 0x05:  // Preset C
	Part13_PatchGroup_select->setCurrentIndex(4);
	break;
    case 0x06:  // Preset D
	Part13_PatchGroup_select->setCurrentIndex(5);
	break;
    case 0x10:  // Exp B
	Part13_PatchGroup_select->setCurrentIndex(6);
	break;
    case 0x62:  // Exp C
	Part13_PatchGroup_select->setCurrentIndex(7);
	break;
    default:
	Part13_PatchGroup_select->setCurrentIndex(0);
	break;
  }	// end SWITCH
  Part13_PatchNumber_select->setValue((active_area->active_performance.perf_part[12].patch_num_high*16) + active_area->active_performance.perf_part[12].patch_num_low+1);
  Part13_PatchName_display->setText(QString::fromAscii(&active_area->active_perf_patch[12].patch_common.name[0],12));
  Part13_LowLimit_display->setText(funcNoteCalc(Part13_LowLimit_select->value()));
  Part13_HighLimit_display->setText(funcNoteCalc(Part13_HighLimit_select->value()));
    Part13_PatchGroup_select->setEnabled(Part13_ReceivePrgChg_enable->isChecked()); 
    Part13_MidiChannel_select->setEnabled(Part13_ReceiveMidi_enable->isChecked());
  }
  // set GM-MODE only parms
  if (state_table->GM_mode) {
      Part13_PatchGroup_select->setCurrentIndex(5);
      Part13_ReceiveMidi_enable->setChecked(true);
      Part13_ReceivePrgChg_enable->setChecked(true);
      Part13_ReceiveVolume_enable->setChecked(true);
      Part13_ReceiveHold_enable->setChecked(true);
      Part13_PatchNumber_select->setValue(13);
      Part13_PatchName_display->setText(getPartPatchName(12));
      Part13_MidiChannel_select->setValue(13);
      Part13_Transpose_select->setValue(0);
      Part13_TuneAdj_select->setValue(0);
      Part13_ReverbSend_select->setValue(0);
      Part13_ChorusSend_select->setValue(0);
      Part13_Pan_select->setValue(64);
      Part13_Level_select->setValue(127);
      Part13_OutputLevel_select->setValue(127);
      Part13_PatchGroup_select->setEnabled(false);
      Part13_VoiceReserve_select->setEnabled(false);
      Part13_OutputLevel_select->setEnabled(false);
      Part13_Output_select->setEnabled(false);
      Part13_MidiChannel_select->setEnabled(false);
  }
  // following are used for both Perf and GM modes
  Part13_TestTone_switch->setChecked(false);
  Part13_SetPatchMax();
  Part13_PatchNumber_select->setEnabled(Part13_ReceivePrgChg_enable->isChecked()); 
  Part13_TestTone_switch->setEnabled(Part13_ReceiveMidi_enable->isChecked());
  Part13_ReceivePrgChg_enable->setEnabled(AcceptProgramChg_switch->isChecked());
  Part13_ReceiveVolume_enable->setEnabled(AcceptVolumeChg_switch->isChecked());
  Part13_ReceiveHold_enable->setEnabled(AcceptHold1Chg_switch->isChecked());
}	// end setPart13_Parms
