// set_initial.cpp
// for Parts tab, Part_3

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setPart3_Parms() {
  if (state_table->perf_mode) {
  // set Part 3 controls/displays based on the active area memory contents, 
  // which were just updated from the synth after a Sync button was clicked.
  //  state_table->updates_enabled = false was set by the calling program, do not change it here.
  QString str;
  Part3_Level_select->setValue(active_area->active_performance.perf_part[2].level);
  Part3_Level_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[2].level));
  Part3_Pan_select->setValue(active_area->active_performance.perf_part[2].pan);
  Part3_Pan_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[2].pan));
  Part3_ChorusSend_select->setValue(active_area->active_performance.perf_part[2].chorus_send_level);
  Part3_ChorusSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[2].chorus_send_level));
  Part3_ReverbSend_select->setValue(active_area->active_performance.perf_part[2].reverb_send_level);
  Part3_ReverbSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[2].reverb_send_level));
  Part3_OutputLevel_select->setValue(active_area->active_performance.perf_part[2].output_level);
  Part3_OutputLevel_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[2].output_level));
  Part3_Transpose_select->setValue(active_area->active_performance.perf_part[2].coarse_tune-48);
  Part3_Transpose_display->display(active_area->active_performance.perf_part[2].coarse_tune-48);
  Part3_TuneAdj_select->setValue(active_area->active_performance.perf_part[2].fine_tune-50);
  Part3_VoiceReserve_select->setValue(active_area->active_performance.perf_common.voice_reserve[2]);
  Part3_LowLimit_select->setValue(active_area->active_performance.perf_part[2].key_lower);
  Part3_HighLimit_select->setValue(active_area->active_performance.perf_part[2].key_upper);
  Part3_ReceiveMidi_enable->setChecked(active_area->active_performance.perf_part[2].MIDI_receive);
  Part3_MidiChannel_select->setValue(active_area->active_performance.perf_part[2].MIDI_channel+1);
  Part3_ReceivePrgChg_enable->setChecked(active_area->active_performance.perf_part[2].receive_program_change);
  Part3_ReceiveVolume_enable->setChecked(active_area->active_performance.perf_part[2].receive_volume);
  Part3_ReceiveHold_enable->setChecked(active_area->active_performance.perf_part[2].receive_hold_1);
  Part3_Output_select->setCurrentIndex(active_area->active_performance.perf_part[2].output);
  
  switch(active_area->active_performance.perf_part[2].patch_group_id) {
    case 0x01:  // User
      Part3_PatchGroup_select->setCurrentIndex(0);
      break;
    case 0x02:  // Exp A
	Part3_PatchGroup_select->setCurrentIndex(1);
	break;
    case 0x03:  // Preset A
	Part3_PatchGroup_select->setCurrentIndex(2);
	break;
    case 0x04:  // Preset B
	Part3_PatchGroup_select->setCurrentIndex(3);
	break;
    case 0x05:  // Preset C
	Part3_PatchGroup_select->setCurrentIndex(4);
	break;
    case 0x06:  // Preset D
	Part3_PatchGroup_select->setCurrentIndex(5);
	break;
    case 0x10:  // Exp B
	Part3_PatchGroup_select->setCurrentIndex(6);
	break;
    case 0x62:  // Exp C
	Part3_PatchGroup_select->setCurrentIndex(7);
	break;
    default:
	Part3_PatchGroup_select->setCurrentIndex(0);
	break;
  }	// end SWITCH
  Part3_PatchNumber_select->setValue((active_area->active_performance.perf_part[2].patch_num_high*16) + active_area->active_performance.perf_part[2].patch_num_low+1);
  Part3_PatchName_display->setText(QString::fromAscii(&active_area->active_perf_patch[2].patch_common.name[0],12));
  Part3_LowLimit_display->setText(funcNoteCalc(Part3_LowLimit_select->value()));
  Part3_HighLimit_display->setText(funcNoteCalc(Part3_HighLimit_select->value()));
  Part3_PatchGroup_select->setEnabled(Part3_ReceivePrgChg_enable->isChecked()); 
  Part3_MidiChannel_select->setEnabled(Part3_ReceiveMidi_enable->isChecked());
  }
  // set GM-MODE only parms
  if (state_table->GM_mode) {
      Part3_PatchGroup_select->setCurrentIndex(5);
      Part3_ReceiveMidi_enable->setChecked(true);
      Part3_ReceivePrgChg_enable->setChecked(true);
      Part3_ReceiveVolume_enable->setChecked(true);
      Part3_ReceiveHold_enable->setChecked(true);
      Part3_PatchNumber_select->setValue(3);
      Part3_PatchName_display->setText(getPartPatchName(2));
      Part3_MidiChannel_select->setValue(3);
      Part3_Transpose_select->setValue(0);
      Part3_TuneAdj_select->setValue(0);
      Part3_ReverbSend_select->setValue(0);
      Part3_ChorusSend_select->setValue(0);
      Part3_Pan_select->setValue(64);
      Part3_Level_select->setValue(127);
      Part3_OutputLevel_select->setValue(127);
      Part3_PatchGroup_select->setEnabled(false);
      Part3_VoiceReserve_select->setEnabled(false);
      Part1_OutputLevel_select->setEnabled(false);
      Part1_Output_select->setEnabled(false);
      Part1_MidiChannel_select->setEnabled(false);
  }
  // following are used for both Perf and GM modes
  Part3_TestTone_switch->setChecked(false);
  Part3_SetPatchMax();
  Part3_PatchNumber_select->setEnabled(Part3_ReceivePrgChg_enable->isChecked()); 
  Part3_TestTone_switch->setEnabled(Part3_ReceiveMidi_enable->isChecked());
  Part3_ReceivePrgChg_enable->setEnabled(AcceptProgramChg_switch->isChecked());
  Part3_ReceiveVolume_enable->setEnabled(AcceptVolumeChg_switch->isChecked());
  Part3_ReceiveHold_enable->setEnabled(AcceptHold1Chg_switch->isChecked());  
}	// end setPart3_Parms
