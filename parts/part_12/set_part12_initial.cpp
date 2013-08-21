// set_initial.cpp
// for Parts tab, Part_12

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setPart12_Parms() {
  if (state_table->perf_mode) {
  // set Part 12 controls/displays based on the active area memory contents, 
  // which were just updated from the synth after a Sync button was clicked.
  //  state_table->updates_enabled = false was set by the calling program, do not change it here.
  QString str;
  Part12_Level_select->setValue(active_area->active_performance.perf_part[11].level);
  Part12_Level_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[11].level));
  Part12_Pan_select->setValue(active_area->active_performance.perf_part[11].pan);
  Part12_Pan_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[11].pan));
  Part12_ChorusSend_select->setValue(active_area->active_performance.perf_part[11].chorus_send_level);
  Part12_ChorusSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[11].chorus_send_level));
  Part12_ReverbSend_select->setValue(active_area->active_performance.perf_part[11].reverb_send_level);
  Part12_ReverbSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[11].reverb_send_level));
  Part12_OutputLevel_select->setValue(active_area->active_performance.perf_part[11].output_level);
  Part12_OutputLevel_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[11].output_level));
  Part12_Transpose_select->setValue(active_area->active_performance.perf_part[11].coarse_tune-48);
  Part12_Transpose_display->display(active_area->active_performance.perf_part[11].coarse_tune-48);
  Part12_TuneAdj_select->setValue(active_area->active_performance.perf_part[11].fine_tune-50);
  Part12_VoiceReserve_select->setValue(active_area->active_performance.perf_common.voice_reserve[11]);
  Part12_LowLimit_select->setValue(active_area->active_performance.perf_part[11].key_lower);
  Part12_HighLimit_select->setValue(active_area->active_performance.perf_part[11].key_upper);
  Part12_ReceiveMidi_enable->setChecked(active_area->active_performance.perf_part[11].MIDI_receive);
  Part12_MidiChannel_select->setValue(active_area->active_performance.perf_part[11].MIDI_channel+1);
  Part12_ReceivePrgChg_enable->setChecked(active_area->active_performance.perf_part[11].receive_program_change);
  Part12_ReceiveVolume_enable->setChecked(active_area->active_performance.perf_part[11].receive_volume);
  Part12_ReceiveHold_enable->setChecked(active_area->active_performance.perf_part[11].receive_hold_1);
  Part12_Output_select->setCurrentIndex(active_area->active_performance.perf_part[11].output);
  Part12_VoiceMode_switch->setChecked(active_area->active_perf_patch[11].patch_common.key_assign_mode);
  Part12_VoiceMode_switch->setText(active_area->active_perf_patch[11].patch_common.key_assign_mode==0 ? QString("Poly") : QString("Solo"));
  
  switch(active_area->active_performance.perf_part[11].patch_group_id) {
    case 0x01:  // User
      Part12_PatchGroup_select->setCurrentIndex(0);
      break;
    case 0x02:  // Exp A
	Part12_PatchGroup_select->setCurrentIndex(1);
	break;
    case 0x03:  // Preset A
	Part12_PatchGroup_select->setCurrentIndex(2);
	break;
    case 0x04:  // Preset B
	Part12_PatchGroup_select->setCurrentIndex(3);
	break;
    case 0x05:  // Preset C
	Part12_PatchGroup_select->setCurrentIndex(4);
	break;
    case 0x06:  // Preset D
	Part12_PatchGroup_select->setCurrentIndex(5);
	break;
    case 0x10:  // Exp B
	Part12_PatchGroup_select->setCurrentIndex(6);
	break;
    case 0x62:  // Exp C
	Part12_PatchGroup_select->setCurrentIndex(7);
	break;
    default:
	Part12_PatchGroup_select->setCurrentIndex(0);
	break;
  }	// end SWITCH
    Part12_PatchNumber_select->setValue((active_area->active_performance.perf_part[11].patch_num_high*16) + active_area->active_performance.perf_part[11].patch_num_low+1);
    Part12_PatchName_display->setText(QString::fromAscii(&active_area->active_perf_patch[11].patch_common.name[0],12));
    Part12_LowLimit_display->setText(funcNoteCalc(Part12_LowLimit_select->value()));
    Part12_HighLimit_display->setText(funcNoteCalc(Part12_HighLimit_select->value()));
    Part12_PatchGroup_select->setEnabled(Part12_ReceivePrgChg_enable->isChecked()); 
    Part12_MidiChannel_select->setEnabled(Part12_ReceiveMidi_enable->isChecked());
    Part12_ReceivePrgChg_enable->setEnabled(AcceptProgramChg_switch->isChecked());
    Part12_ReceiveVolume_enable->setEnabled(AcceptVolumeChg_switch->isChecked());
    Part12_ReceiveHold_enable->setEnabled(AcceptHold1Chg_switch->isChecked());
  }
  // set GM-MODE only parms
  if (state_table->GM_mode) {
      Part12_PatchGroup_select->setCurrentIndex(5);
      Part12_ReceiveMidi_enable->setChecked(true);
      Part12_ReceivePrgChg_enable->setChecked(true);
      Part12_ReceiveVolume_enable->setChecked(true);
      Part12_ReceiveHold_enable->setChecked(true);
      Part12_PatchNumber_select->setValue(12);
      Part12_PatchName_display->setText(getPartPatchName(11));
      Part12_MidiChannel_select->setValue(12);
      Part12_Transpose_select->setValue(0);
      Part12_TuneAdj_select->setValue(0);
      Part12_ReverbSend_select->setValue(0);
      Part12_ChorusSend_select->setValue(0);
      Part12_Pan_select->setValue(64);
      Part12_Level_select->setValue(127);
      Part12_OutputLevel_select->setValue(127);
      Part12_PatchGroup_select->setEnabled(false);
      Part12_VoiceReserve_select->setEnabled(false);
      Part12_OutputLevel_select->setEnabled(false);
      Part12_Output_select->setEnabled(false);
      Part12_MidiChannel_select->setEnabled(false);
      Part12_ReceivePrgChg_enable->setEnabled(false);
      Part12_ReceiveVolume_enable->setEnabled(false);
      Part12_ReceiveHold_enable->setEnabled(false);
      Part12_ReceiveMidi_enable->setEnabled(false);
      Part12_VoiceMode_switch->setChecked(false);
      Part12_VoiceMode_switch->setText("Poly");
      Part12_VoiceMode_switch->setEnabled(true);
  }
  // following are used for both Perf and GM modes
  Part12_TestTone_switch->setChecked(false);
  Part12_SetPatchMax();
  Part12_PatchNumber_select->setEnabled(Part12_ReceivePrgChg_enable->isChecked()); 
  Part12_TestTone_switch->setEnabled(Part12_ReceiveMidi_enable->isChecked());
}	// end setPart12_Parms
