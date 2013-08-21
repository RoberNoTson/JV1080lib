// set_initial.cpp
// for Parts tab, Part_11

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setPart11_Parms() {
  if (state_table->perf_mode) {
  // set Part 11 controls/displays based on the active area memory contents, 
  // which were just updated from the synth after a Sync button was clicked.
  //  state_table->updates_enabled = false was set by the calling program, do not change it here.
  QString str;
  Part11_Level_select->setValue(active_area->active_performance.perf_part[10].level);
  Part11_Level_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[10].level));
  Part11_Pan_select->setValue(active_area->active_performance.perf_part[10].pan);
  Part11_Pan_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[10].pan));
  Part11_ChorusSend_select->setValue(active_area->active_performance.perf_part[10].chorus_send_level);
  Part11_ChorusSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[10].chorus_send_level));
  Part11_ReverbSend_select->setValue(active_area->active_performance.perf_part[10].reverb_send_level);
  Part11_ReverbSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[10].reverb_send_level));
  Part11_OutputLevel_select->setValue(active_area->active_performance.perf_part[10].output_level);
  Part11_OutputLevel_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[10].output_level));
  Part11_Transpose_select->setValue(active_area->active_performance.perf_part[10].coarse_tune-48);
  Part11_Transpose_display->display(active_area->active_performance.perf_part[10].coarse_tune-48);
  Part11_TuneAdj_select->setValue(active_area->active_performance.perf_part[10].fine_tune-50);
  Part11_VoiceReserve_select->setValue(active_area->active_performance.perf_common.voice_reserve[10]);
  Part11_LowLimit_select->setValue(active_area->active_performance.perf_part[10].key_lower);
  Part11_HighLimit_select->setValue(active_area->active_performance.perf_part[10].key_upper);
  Part11_ReceiveMidi_enable->setChecked(active_area->active_performance.perf_part[10].MIDI_receive);
  Part11_MidiChannel_select->setValue(active_area->active_performance.perf_part[10].MIDI_channel+1);
  Part11_ReceivePrgChg_enable->setChecked(active_area->active_performance.perf_part[10].receive_program_change);
  Part11_ReceiveVolume_enable->setChecked(active_area->active_performance.perf_part[10].receive_volume);
  Part11_ReceiveHold_enable->setChecked(active_area->active_performance.perf_part[10].receive_hold_1);
  Part11_Output_select->setCurrentIndex(active_area->active_performance.perf_part[10].output);
  Part11_VoiceMode_switch->setChecked(active_area->active_perf_patch[10].patch_common.key_assign_mode);
  Part11_VoiceMode_switch->setText(active_area->active_perf_patch[10].patch_common.key_assign_mode==0 ? QString("Poly") : QString("Solo"));
  
  switch(active_area->active_performance.perf_part[10].patch_group_id) {
    case 0x01:  // User
      Part11_PatchGroup_select->setCurrentIndex(0);
      break;
    case 0x02:  // Exp A
	Part11_PatchGroup_select->setCurrentIndex(1);
	break;
    case 0x03:  // Preset A
	Part11_PatchGroup_select->setCurrentIndex(2);
	break;
    case 0x04:  // Preset B
	Part11_PatchGroup_select->setCurrentIndex(3);
	break;
    case 0x05:  // Preset C
	Part11_PatchGroup_select->setCurrentIndex(4);
	break;
    case 0x06:  // Preset D
	Part11_PatchGroup_select->setCurrentIndex(5);
	break;
    case 0x10:  // Exp B
	Part11_PatchGroup_select->setCurrentIndex(6);
	break;
    case 0x62:  // Exp C
	Part11_PatchGroup_select->setCurrentIndex(7);
	break;
    default:
	Part11_PatchGroup_select->setCurrentIndex(0);
	break;
  }	// end SWITCH
    Part11_PatchNumber_select->setValue((active_area->active_performance.perf_part[10].patch_num_high*16) + active_area->active_performance.perf_part[10].patch_num_low+1);
    Part11_PatchName_display->setText(QString::fromAscii(&active_area->active_perf_patch[10].patch_common.name[0],12));
    Part11_LowLimit_display->setText(funcNoteCalc(Part11_LowLimit_select->value()));
    Part11_HighLimit_display->setText(funcNoteCalc(Part11_HighLimit_select->value()));
    Part11_PatchGroup_select->setEnabled(Part11_ReceivePrgChg_enable->isChecked()); 
    Part11_MidiChannel_select->setEnabled(Part11_ReceiveMidi_enable->isChecked());
    Part11_ReceivePrgChg_enable->setEnabled(AcceptProgramChg_switch->isChecked());
    Part11_ReceiveVolume_enable->setEnabled(AcceptVolumeChg_switch->isChecked());
    Part11_ReceiveHold_enable->setEnabled(AcceptHold1Chg_switch->isChecked());
  }
  // set GM-MODE only parms
  if (state_table->GM_mode) {
      Part11_PatchGroup_select->setCurrentIndex(5);
      Part11_ReceiveMidi_enable->setChecked(true);
      Part11_ReceivePrgChg_enable->setChecked(true);
      Part11_ReceiveVolume_enable->setChecked(true);
      Part11_ReceiveHold_enable->setChecked(true);
      Part11_PatchNumber_select->setValue(11);
      Part11_PatchName_display->setText(getPartPatchName(10));
      Part11_MidiChannel_select->setValue(11);
      Part11_Transpose_select->setValue(0);
      Part11_TuneAdj_select->setValue(0);
      Part11_ReverbSend_select->setValue(0);
      Part11_ChorusSend_select->setValue(0);
      Part11_Pan_select->setValue(64);
      Part11_Level_select->setValue(127);
      Part11_OutputLevel_select->setValue(127);
      Part11_PatchGroup_select->setEnabled(false);
      Part11_VoiceReserve_select->setEnabled(false);
      Part11_OutputLevel_select->setEnabled(false);
      Part11_Output_select->setEnabled(false);
      Part11_MidiChannel_select->setEnabled(false);
      Part11_ReceivePrgChg_enable->setEnabled(false);
      Part11_ReceiveVolume_enable->setEnabled(false);
      Part11_ReceiveHold_enable->setEnabled(false);
      Part11_ReceiveMidi_enable->setEnabled(false);
      Part11_VoiceMode_switch->setChecked(false);
      Part11_VoiceMode_switch->setText("Poly");
      Part11_VoiceMode_switch->setEnabled(true);
  }
  // following are used for both Perf and GM modes
  Part11_TestTone_switch->setChecked(false);
  Part11_SetPatchMax();
  Part11_PatchNumber_select->setEnabled(Part11_ReceivePrgChg_enable->isChecked()); 
  Part11_TestTone_switch->setEnabled(Part11_ReceiveMidi_enable->isChecked());
}	// end setPart11_Parms
