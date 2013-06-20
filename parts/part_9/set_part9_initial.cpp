// set_initial.cpp
// for Parts tab, Part_9

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setPart9_Parms() {
  // set Part 1 controls/displays based on the active area memory contents, 
  // which were just updated from the synth after a Sync button was clicked.
  //  state_table->updates_enabled = false was set by the calling program, do not change it here.
  QString str;
  Part9_Level_select->setValue(active_area->active_performance.perf_part[8].level);
  Part9_Level_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[8].level));
  Part9_Pan_select->setValue(active_area->active_performance.perf_part[8].pan);
  Part9_Pan_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[8].pan));
  Part9_ChorusSend_select->setValue(active_area->active_performance.perf_part[8].chorus_send_level);
  Part9_ChorusSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[8].chorus_send_level));
  Part9_ReverbSend_select->setValue(active_area->active_performance.perf_part[8].reverb_send_level);
  Part9_ReverbSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[8].reverb_send_level));
  Part9_OutputLevel_select->setValue(active_area->active_performance.perf_part[8].output_level);
  Part9_OutputLevel_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[8].output_level));
  Part9_Transpose_select->setValue(active_area->active_performance.perf_part[8].coarse_tune-48);
  Part9_Transpose_display->display(active_area->active_performance.perf_part[8].coarse_tune-48);
  Part9_TuneAdj_select->setValue(active_area->active_performance.perf_part[8].fine_tune-50);
  Part9_VoiceReserve_select->setValue(active_area->active_performance.perf_common.voice_reserve[0]);
  Part9_LowLimit_select->setValue(active_area->active_performance.perf_part[8].key_lower);
  Part9_HighLimit_select->setValue(active_area->active_performance.perf_part[8].key_upper);
  Part9_ReceiveMidi_enable->setChecked(active_area->active_performance.perf_part[8].MIDI_receive);
  Part9_MidiChannel_select->setValue(active_area->active_performance.perf_part[8].MIDI_channel+1);
  Part9_ReceivePrgChg_enable->setChecked(active_area->active_performance.perf_part[8].receive_program_change);
  Part9_ReceiveVolume_enable->setChecked(active_area->active_performance.perf_part[8].receive_volume);
  Part9_ReceiveHold_enable->setChecked(active_area->active_performance.perf_part[8].receive_hold_1);
  Part9_Output_select->setCurrentIndex(active_area->active_performance.perf_part[8].output);
  Part9_TestTone_switch->setChecked(false);
  
  switch(active_area->active_performance.perf_part[8].patch_group_id) {
    case 0x01:  // User
      Part9_PatchGroup_select->setCurrentIndex(0);
      break;
    case 0x02:  // Exp A
	Part9_PatchGroup_select->setCurrentIndex(1);
	break;
    case 0x03:  // Preset A
	Part9_PatchGroup_select->setCurrentIndex(2);
	break;
    case 0x04:  // Preset B
	Part9_PatchGroup_select->setCurrentIndex(3);
	break;
    case 0x05:  // Preset C
	Part9_PatchGroup_select->setCurrentIndex(4);
	break;
    case 0x06:  // Preset D
	Part9_PatchGroup_select->setCurrentIndex(5);
	break;
    case 0x10:  // Exp B
	Part9_PatchGroup_select->setCurrentIndex(6);
	break;
    case 0x62:  // Exp C
	Part9_PatchGroup_select->setCurrentIndex(7);
	break;
    default:
	Part9_PatchGroup_select->setCurrentIndex(0);
	break;
  }	// end SWITCH
  Part9_SetPatchMax();
  Part9_PatchNumber_select->setValue((active_area->active_performance.perf_part[8].patch_num_high*16) + active_area->active_performance.perf_part[8].patch_num_low+1);
  Part9_PatchName_display->setText(QString::fromAscii(&active_area->active_perf_patch[8].patch_common.name[0],12));
  Part9_LowLimit_display->setText(funcNoteCalc(Part9_LowLimit_select->value()));
  Part9_HighLimit_display->setText(funcNoteCalc(Part9_HighLimit_select->value()));
  
  Part9_ReceivePrgChg_enable->setEnabled(AcceptProgramChg_switch->isChecked());
  Part9_ReceiveVolume_enable->setEnabled(AcceptVolumeChg_switch->isChecked());
  Part9_ReceiveHold_enable->setEnabled(AcceptHold1Chg_switch->isChecked());
}	// end setPart9_Parms
