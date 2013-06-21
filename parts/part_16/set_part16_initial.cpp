// set_initial.cpp
// for Parts tab, Part_16

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setPart16_Parms() {
  // set Part 1 controls/displays based on the active area memory contents, 
  // which were just updated from the synth after a Sync button was clicked.
  //  state_table->updates_enabled = false was set by the calling program, do not change it here.
  QString str;
  Part16_Level_select->setValue(active_area->active_performance.perf_part[15].level);
  Part16_Level_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[15].level));
  Part16_Pan_select->setValue(active_area->active_performance.perf_part[15].pan);
  Part16_Pan_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[15].pan));
  Part16_ChorusSend_select->setValue(active_area->active_performance.perf_part[15].chorus_send_level);
  Part16_ChorusSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[15].chorus_send_level));
  Part16_ReverbSend_select->setValue(active_area->active_performance.perf_part[15].reverb_send_level);
  Part16_ReverbSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[15].reverb_send_level));
  Part16_OutputLevel_select->setValue(active_area->active_performance.perf_part[15].output_level);
  Part16_OutputLevel_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[15].output_level));
  Part16_Transpose_select->setValue(active_area->active_performance.perf_part[15].coarse_tune-48);
  Part16_Transpose_display->display(active_area->active_performance.perf_part[15].coarse_tune-48);
  Part16_TuneAdj_select->setValue(active_area->active_performance.perf_part[15].fine_tune-50);
  Part16_VoiceReserve_select->setValue(active_area->active_performance.perf_common.voice_reserve[15]);
  Part16_LowLimit_select->setValue(active_area->active_performance.perf_part[15].key_lower);
  Part16_HighLimit_select->setValue(active_area->active_performance.perf_part[15].key_upper);
  Part16_ReceiveMidi_enable->setChecked(active_area->active_performance.perf_part[15].MIDI_receive);
  Part16_MidiChannel_select->setValue(active_area->active_performance.perf_part[15].MIDI_channel+1);
  Part16_ReceivePrgChg_enable->setChecked(active_area->active_performance.perf_part[15].receive_program_change);
  Part16_ReceiveVolume_enable->setChecked(active_area->active_performance.perf_part[15].receive_volume);
  Part16_ReceiveHold_enable->setChecked(active_area->active_performance.perf_part[15].receive_hold_1);
  Part16_Output_select->setCurrentIndex(active_area->active_performance.perf_part[15].output);
  Part16_TestTone_switch->setChecked(false);
  
  switch(active_area->active_performance.perf_part[15].patch_group_id) {
    case 0x01:  // User
      Part16_PatchGroup_select->setCurrentIndex(0);
      break;
    case 0x02:  // Exp A
	Part16_PatchGroup_select->setCurrentIndex(1);
	break;
    case 0x03:  // Preset A
	Part16_PatchGroup_select->setCurrentIndex(2);
	break;
    case 0x04:  // Preset B
	Part16_PatchGroup_select->setCurrentIndex(3);
	break;
    case 0x05:  // Preset C
	Part16_PatchGroup_select->setCurrentIndex(4);
	break;
    case 0x06:  // Preset D
	Part16_PatchGroup_select->setCurrentIndex(5);
	break;
    case 0x10:  // Exp B
	Part16_PatchGroup_select->setCurrentIndex(6);
	break;
    case 0x62:  // Exp C
	Part16_PatchGroup_select->setCurrentIndex(7);
	break;
    default:
	Part16_PatchGroup_select->setCurrentIndex(0);
	break;
  }	// end SWITCH
  Part16_SetPatchMax();
  Part16_PatchNumber_select->setValue((active_area->active_performance.perf_part[15].patch_num_high*16) + active_area->active_performance.perf_part[15].patch_num_low+1);
  Part16_PatchName_display->setText(QString::fromAscii(&active_area->active_perf_patch[15].patch_common.name[0],12));
  Part16_LowLimit_display->setText(funcNoteCalc(Part16_LowLimit_select->value()));
  Part16_HighLimit_display->setText(funcNoteCalc(Part16_HighLimit_select->value()));
  
  Part16_ReceivePrgChg_enable->setEnabled(AcceptProgramChg_switch->isChecked());
  Part16_ReceiveVolume_enable->setEnabled(AcceptVolumeChg_switch->isChecked());
  Part16_ReceiveHold_enable->setEnabled(AcceptHold1Chg_switch->isChecked());
}	// end setPart16_Parms
