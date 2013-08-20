// set_initial.cpp
// for Parts tab, Part_10

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setPart10_Parms() {
  if (state_table->perf_mode) {
  // set Part 10 controls/displays based on the active area memory contents, 
  // which were just updated from the synth after a Sync button was clicked.
  //  state_table->updates_enabled = false was set by the calling program, do not change it here.
  QString str;
  Part10_Level_select->setValue(active_area->active_performance.perf_part[9].level);
  Part10_Level_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[9].level));
  Part10_Pan_select->setValue(active_area->active_performance.perf_part[9].pan);
  Part10_Pan_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[9].pan));
  Part10_ChorusSend_select->setValue(active_area->active_performance.perf_part[9].chorus_send_level);
  Part10_ChorusSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[9].chorus_send_level));
  Part10_ReverbSend_select->setValue(active_area->active_performance.perf_part[9].reverb_send_level);
  Part10_ReverbSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[9].reverb_send_level));
  Part10_OutputLevel_select->setValue(active_area->active_performance.perf_part[9].output_level);
  Part10_OutputLevel_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[9].output_level));
  Part10_Transpose_select->setValue(active_area->active_performance.perf_part[9].coarse_tune-48);
  Part10_Transpose_display->display(active_area->active_performance.perf_part[9].coarse_tune-48);
  Part10_TuneAdj_select->setValue(active_area->active_performance.perf_part[9].fine_tune-50);
  Part10_VoiceReserve_select->setValue(active_area->active_performance.perf_common.voice_reserve[9]);
  Part10_LowLimit_select->setValue(active_area->active_performance.perf_part[9].key_lower);
  Part10_HighLimit_select->setValue(active_area->active_performance.perf_part[9].key_upper);
  Part10_ReceiveMidi_enable->setChecked(active_area->active_performance.perf_part[9].MIDI_receive);
  Part10_MidiChannel_select->setValue(active_area->active_performance.perf_part[9].MIDI_channel+1);
  Part10_ReceivePrgChg_enable->setChecked(active_area->active_performance.perf_part[9].receive_program_change);
  Part10_ReceiveVolume_enable->setChecked(active_area->active_performance.perf_part[9].receive_volume);
  Part10_ReceiveHold_enable->setChecked(active_area->active_performance.perf_part[9].receive_hold_1);
  Part10_Output_select->setCurrentIndex(active_area->active_performance.perf_part[9].output);
  
  switch(active_area->active_performance.perf_part[9].patch_group_id) {
    case 0x01:  // User
      Part10_PatchGroup_select->setCurrentIndex(0);
      break;
    case 0x03:  // Preset A
	Part10_PatchGroup_select->setCurrentIndex(1);
	break;
    case 0x04:  // Preset B
	Part10_PatchGroup_select->setCurrentIndex(2);
	break;
    case 0x05:  // Preset C
	Part10_PatchGroup_select->setCurrentIndex(3);
	break;
    case 0x06:  // Preset D
	Part10_PatchGroup_select->setCurrentIndex(4);
	break;
    case 0x10:  // Exp B
	Part10_PatchGroup_select->setCurrentIndex(5);
	break;
    default:
	Part10_PatchGroup_select->setCurrentIndex(0);
	break;
  }	// end SWITCH
  Part10_PatchNumber_select->setValue((active_area->active_performance.perf_part[9].patch_num_high*16) + active_area->active_performance.perf_part[9].patch_num_low+1);
  Part10_PatchName_display->setText(QString::fromAscii(&active_area->active_perf_patch[9].patch_common.name[0],12));
  Part10_LowLimit_display->setText(funcNoteCalc(Part10_LowLimit_select->value()));
  Part10_HighLimit_display->setText(funcNoteCalc(Part10_HighLimit_select->value()));
  Rhythm_PatchGroup_display->setText(Part10_PatchGroup_select->currentText());
  Rhythm_PatchNumber_display->setText(Part10_PatchNumber_select->text());
  Rhythm_PatchName_display->setText(Part10_PatchName_display->text());
    Part10_PatchGroup_select->setEnabled(Part10_ReceivePrgChg_enable->isChecked()); 
    Part10_MidiChannel_select->setEnabled(Part10_ReceiveMidi_enable->isChecked());
  }
  // set GM-MODE only parms
  if (state_table->GM_mode) {
      Part10_PatchGroup_select->setCurrentIndex(4);
      Part10_ReceiveMidi_enable->setChecked(true);
      Part10_ReceivePrgChg_enable->setChecked(true);
      Part10_ReceiveVolume_enable->setChecked(true);
      Part10_ReceiveHold_enable->setChecked(true);
      Part10_PatchNumber_select->setValue(1);
//      Part10_PatchName_display->setText(getPartPatchName(9));
      Part10_PatchName_display->setText(Part10_PatchNumber_select->value()==1 ? "GM Drum Set" : "BrushDrumSet");
      Part10_MidiChannel_select->setValue(10);
      Part10_Transpose_select->setValue(0);
      Part10_TuneAdj_select->setValue(0);
      Part10_ReverbSend_select->setValue(0);
      Part10_ChorusSend_select->setValue(0);
      Part10_Pan_select->setValue(64);
      Part10_Level_select->setValue(127);
      Part10_OutputLevel_select->setValue(127);
      Part10_PatchGroup_select->setEnabled(false);
      Part10_VoiceReserve_select->setEnabled(false);
      Part10_OutputLevel_select->setEnabled(false);
      Part10_Output_select->setEnabled(false);
      Part10_MidiChannel_select->setEnabled(false);
  }
  // following are used for both Perf and GM modes
  Part10_TestTone_switch->setChecked(false);
  Part10_PatchNumber_select->setEnabled(Part10_ReceivePrgChg_enable->isChecked()); 
  Part10_TestTone_switch->setEnabled(Part10_ReceiveMidi_enable->isChecked());
  Part10_ReceivePrgChg_enable->setEnabled(AcceptProgramChg_switch->isChecked());
  Part10_ReceiveVolume_enable->setEnabled(AcceptVolumeChg_switch->isChecked());
  Part10_ReceiveHold_enable->setEnabled(AcceptHold1Chg_switch->isChecked());
}	// end setPart10_Parms
