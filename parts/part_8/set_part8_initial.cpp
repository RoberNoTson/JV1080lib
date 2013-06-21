// set_initial.cpp
// for Parts tab, Part_8

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setPart8_Parms() {
  // set Part 1 controls/displays based on the active area memory contents, 
  // which were just updated from the synth after a Sync button was clicked.
  //  state_table->updates_enabled = false was set by the calling program, do not change it here.
  QString str;
  Part8_Level_select->setValue(active_area->active_performance.perf_part[7].level);
  Part8_Level_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[7].level));
  Part8_Pan_select->setValue(active_area->active_performance.perf_part[7].pan);
  Part8_Pan_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[7].pan));
  Part8_ChorusSend_select->setValue(active_area->active_performance.perf_part[7].chorus_send_level);
  Part8_ChorusSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[7].chorus_send_level));
  Part8_ReverbSend_select->setValue(active_area->active_performance.perf_part[7].reverb_send_level);
  Part8_ReverbSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[7].reverb_send_level));
  Part8_OutputLevel_select->setValue(active_area->active_performance.perf_part[7].output_level);
  Part8_OutputLevel_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[7].output_level));
  Part8_Transpose_select->setValue(active_area->active_performance.perf_part[7].coarse_tune-48);
  Part8_Transpose_display->display(active_area->active_performance.perf_part[7].coarse_tune-48);
  Part8_TuneAdj_select->setValue(active_area->active_performance.perf_part[7].fine_tune-50);
  Part8_VoiceReserve_select->setValue(active_area->active_performance.perf_common.voice_reserve[7]);
  Part8_LowLimit_select->setValue(active_area->active_performance.perf_part[7].key_lower);
  Part8_HighLimit_select->setValue(active_area->active_performance.perf_part[7].key_upper);
  Part8_ReceiveMidi_enable->setChecked(active_area->active_performance.perf_part[7].MIDI_receive);
  Part8_MidiChannel_select->setValue(active_area->active_performance.perf_part[7].MIDI_channel+1);
  Part8_ReceivePrgChg_enable->setChecked(active_area->active_performance.perf_part[7].receive_program_change);
  Part8_ReceiveVolume_enable->setChecked(active_area->active_performance.perf_part[7].receive_volume);
  Part8_ReceiveHold_enable->setChecked(active_area->active_performance.perf_part[7].receive_hold_1);
  Part8_Output_select->setCurrentIndex(active_area->active_performance.perf_part[7].output);
  Part8_TestTone_switch->setChecked(false);
  
  switch(active_area->active_performance.perf_part[7].patch_group_id) {
    case 0x01:  // User
      Part8_PatchGroup_select->setCurrentIndex(0);
      break;
    case 0x02:  // Exp A
	Part8_PatchGroup_select->setCurrentIndex(1);
	break;
    case 0x03:  // Preset A
	Part8_PatchGroup_select->setCurrentIndex(2);
	break;
    case 0x04:  // Preset B
	Part8_PatchGroup_select->setCurrentIndex(3);
	break;
    case 0x05:  // Preset C
	Part8_PatchGroup_select->setCurrentIndex(4);
	break;
    case 0x06:  // Preset D
	Part8_PatchGroup_select->setCurrentIndex(5);
	break;
    case 0x10:  // Exp B
	Part8_PatchGroup_select->setCurrentIndex(6);
	break;
    case 0x62:  // Exp C
	Part8_PatchGroup_select->setCurrentIndex(7);
	break;
    default:
	Part8_PatchGroup_select->setCurrentIndex(0);
	break;
  }	// end SWITCH
  Part8_SetPatchMax();
  Part8_PatchNumber_select->setValue((active_area->active_performance.perf_part[7].patch_num_high*16) + active_area->active_performance.perf_part[7].patch_num_low+1);
  Part8_PatchName_display->setText(QString::fromAscii(&active_area->active_perf_patch[7].patch_common.name[0],12));
  Part8_LowLimit_display->setText(funcNoteCalc(Part8_LowLimit_select->value()));
  Part8_HighLimit_display->setText(funcNoteCalc(Part8_HighLimit_select->value()));
  
  Part8_ReceivePrgChg_enable->setEnabled(AcceptProgramChg_switch->isChecked());
  Part8_ReceiveVolume_enable->setEnabled(AcceptVolumeChg_switch->isChecked());
  Part8_ReceiveHold_enable->setEnabled(AcceptHold1Chg_switch->isChecked());
}	// end setPart8_Parms
