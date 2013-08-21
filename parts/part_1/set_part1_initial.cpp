// set_initial.cpp
// for Parts tab, Part_1

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setPart1_Parms() {
  if (state_table->perf_mode) {
  // set Part 1 controls/displays based on the active area memory contents, 
  // which were just updated from the synth after a Sync button was clicked.
  //  state_table->updates_enabled = false was set by the calling program, do not change it here.
  QString str;
  Part1_Level_select->setValue(active_area->active_performance.perf_part[0].level);
  Part1_Level_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[0].level));
  Part1_Pan_select->setValue(active_area->active_performance.perf_part[0].pan);
  Part1_Pan_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[0].pan));
  Part1_ChorusSend_select->setValue(active_area->active_performance.perf_part[0].chorus_send_level);
  Part1_ChorusSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[0].chorus_send_level));
  Part1_ReverbSend_select->setValue(active_area->active_performance.perf_part[0].reverb_send_level);
  Part1_ReverbSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[0].reverb_send_level));
  Part1_OutputLevel_select->setValue(active_area->active_performance.perf_part[0].output_level);
  Part1_OutputLevel_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[0].output_level));
  Part1_Transpose_select->setValue(active_area->active_performance.perf_part[0].coarse_tune-48);
  Part1_Transpose_display->display(active_area->active_performance.perf_part[0].coarse_tune-48);
  Part1_TuneAdj_select->setValue(active_area->active_performance.perf_part[0].fine_tune-50);
  Part1_VoiceReserve_select->setValue(active_area->active_performance.perf_common.voice_reserve[0]);
  Part1_LowLimit_select->setValue(active_area->active_performance.perf_part[0].key_lower);
  Part1_HighLimit_select->setValue(active_area->active_performance.perf_part[0].key_upper);
  Part1_ReceiveMidi_enable->setChecked(active_area->active_performance.perf_part[0].MIDI_receive);
  Part1_ReceivePrgChg_enable->setChecked(active_area->active_performance.perf_part[0].receive_program_change);
  Part1_ReceiveVolume_enable->setChecked(active_area->active_performance.perf_part[0].receive_volume);
  Part1_ReceiveHold_enable->setChecked(active_area->active_performance.perf_part[0].receive_hold_1);
  Part1_MidiChannel_select->setValue(active_area->active_performance.perf_part[0].MIDI_channel+1);
  Part1_Output_select->setCurrentIndex(active_area->active_performance.perf_part[0].output);
  Part1_VoiceMode_switch->setChecked(active_area->active_perf_patch[0].patch_common.key_assign_mode);
  Part1_VoiceMode_switch->setText(active_area->active_perf_patch[0].patch_common.key_assign_mode==0 ? QString("Poly") : QString("Solo"));
  
  switch(active_area->active_performance.perf_part[0].patch_group_id) {
    case 0x01:  // User
      Part1_PatchGroup_select->setCurrentIndex(0);
      break;
    case 0x02:  // Exp A
	Part1_PatchGroup_select->setCurrentIndex(1);
	break;
    case 0x03:  // Preset A
	Part1_PatchGroup_select->setCurrentIndex(2);
	break;
    case 0x04:  // Preset B
	Part1_PatchGroup_select->setCurrentIndex(3);
	break;
    case 0x05:  // Preset C
	Part1_PatchGroup_select->setCurrentIndex(4);
	break;
    case 0x06:  // Preset D
	Part1_PatchGroup_select->setCurrentIndex(5);
	break;
    case 0x10:  // Exp B
	Part1_PatchGroup_select->setCurrentIndex(6);
	break;
    case 0x62:  // Exp C
	Part1_PatchGroup_select->setCurrentIndex(7);
	break;
    default:
	Part1_PatchGroup_select->setCurrentIndex(0);
	break;
    }	// end SWITCH
    Part1_PatchNumber_select->setValue((active_area->active_performance.perf_part[0].patch_num_high*16) + active_area->active_performance.perf_part[0].patch_num_low+1);
    Part1_PatchName_display->setText(QString::fromAscii(&active_area->active_perf_patch[0].patch_common.name[0],12));
    Part1_LowLimit_display->setText(funcNoteCalc(Part1_LowLimit_select->value()));
    Part1_HighLimit_display->setText(funcNoteCalc(Part1_HighLimit_select->value()));  
    Part1_PatchGroup_select->setEnabled(Part1_ReceivePrgChg_enable->isChecked()); 
    Part1_MidiChannel_select->setEnabled(Part1_ReceiveMidi_enable->isChecked());
    Part1_ReceivePrgChg_enable->setEnabled(AcceptProgramChg_switch->isChecked());
    Part1_ReceiveVolume_enable->setEnabled(AcceptVolumeChg_switch->isChecked());
    Part1_ReceiveHold_enable->setEnabled(AcceptHold1Chg_switch->isChecked());
  }	// end perf_mode
  // set GM-MODE only parms
  if (state_table->GM_mode) {
      Part1_PatchGroup_select->setCurrentIndex(5);
      Part1_ReceiveMidi_enable->setChecked(true);
      Part1_ReceivePrgChg_enable->setChecked(true);
      Part1_ReceiveVolume_enable->setChecked(true);
      Part1_ReceiveHold_enable->setChecked(true);
      Part1_PatchNumber_select->setValue(1);
      Part1_PatchName_display->setText(getPartPatchName(0));
      Part1_MidiChannel_select->setValue(1);
      Part1_Transpose_select->setValue(0);
      Part1_TuneAdj_select->setValue(0);
      Part1_ReverbSend_select->setValue(0);
      Part1_ChorusSend_select->setValue(0);
      Part1_Pan_select->setValue(64);
      Part1_Level_select->setValue(127);
      Part1_OutputLevel_select->setValue(127);
      Part1_PatchGroup_select->setEnabled(false);
      Part1_VoiceReserve_select->setEnabled(false);
      Part1_OutputLevel_select->setEnabled(false);
      Part1_Output_select->setEnabled(false);
      Part1_MidiChannel_select->setEnabled(false);
      Part1_ReceivePrgChg_enable->setEnabled(false);
      Part1_ReceiveVolume_enable->setEnabled(false);
      Part1_ReceiveHold_enable->setEnabled(false);
      Part1_ReceiveMidi_enable->setEnabled(false);
      Part1_VoiceMode_switch->setChecked(false);
      Part1_VoiceMode_switch->setText("Poly");
      Part1_VoiceMode_switch->setEnabled(true);
  }
  // following are used for both Perf and GM modes
  Part1_TestTone_switch->setChecked(false);
  Part1_SetPatchMax();
  Part1_PatchNumber_select->setEnabled(Part1_ReceivePrgChg_enable->isChecked()); 
  Part1_TestTone_switch->setEnabled(Part1_ReceiveMidi_enable->isChecked());
}	// end setPart1_Parms
