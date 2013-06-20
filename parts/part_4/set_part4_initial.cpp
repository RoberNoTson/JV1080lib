// set_initial.cpp
// for Parts tab, Part_4

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setPart4_Parms() {
  // set Part 1 controls/displays based on the active area memory contents, 
  // which were just updated from the synth after a Sync button was clicked.
  //  state_table->updates_enabled = false was set by the calling program, do not change it here.
  QString str;
  Part4_Level_select->setValue(active_area->active_performance.perf_part[3].level);
  Part4_Level_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[3].level));
  Part4_Pan_select->setValue(active_area->active_performance.perf_part[3].pan);
  Part4_Pan_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[3].pan));
  Part4_ChorusSend_select->setValue(active_area->active_performance.perf_part[3].chorus_send_level);
  Part4_ChorusSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[3].chorus_send_level));
  Part4_ReverbSend_select->setValue(active_area->active_performance.perf_part[3].reverb_send_level);
  Part4_ReverbSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[3].reverb_send_level));
  Part4_OutputLevel_select->setValue(active_area->active_performance.perf_part[3].output_level);
  Part4_OutputLevel_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[3].output_level));
  Part4_Transpose_select->setValue(active_area->active_performance.perf_part[3].coarse_tune-48);
  Part4_Transpose_display->display(active_area->active_performance.perf_part[3].coarse_tune-48);
  Part4_TuneAdj_select->setValue(active_area->active_performance.perf_part[3].fine_tune-50);
  Part4_VoiceReserve_select->setValue(active_area->active_performance.perf_common.voice_reserve[0]);
  Part4_LowLimit_select->setValue(active_area->active_performance.perf_part[3].key_lower);
  Part4_HighLimit_select->setValue(active_area->active_performance.perf_part[3].key_upper);
  Part4_ReceiveMidi_enable->setChecked(active_area->active_performance.perf_part[3].MIDI_receive);
  Part4_MidiChannel_select->setValue(active_area->active_performance.perf_part[3].MIDI_channel+1);
  Part4_ReceivePrgChg_enable->setChecked(active_area->active_performance.perf_part[3].receive_program_change);
  Part4_ReceiveVolume_enable->setChecked(active_area->active_performance.perf_part[3].receive_volume);
  Part4_ReceiveHold_enable->setChecked(active_area->active_performance.perf_part[3].receive_hold_1);
  Part4_Output_select->setCurrentIndex(active_area->active_performance.perf_part[3].output);
  Part4_TestTone_switch->setChecked(false);
  
  switch(active_area->active_performance.perf_part[3].patch_group_id) {
    case 0x01:  // User
      Part4_PatchGroup_select->setCurrentIndex(0);
      break;
    case 0x02:  // Exp A
	Part4_PatchGroup_select->setCurrentIndex(1);
	break;
    case 0x03:  // Preset A
	Part4_PatchGroup_select->setCurrentIndex(2);
	break;
    case 0x04:  // Preset B
	Part4_PatchGroup_select->setCurrentIndex(3);
	break;
    case 0x05:  // Preset C
	Part4_PatchGroup_select->setCurrentIndex(4);
	break;
    case 0x06:  // Preset D
	Part4_PatchGroup_select->setCurrentIndex(5);
	break;
    case 0x10:  // Exp B
	Part4_PatchGroup_select->setCurrentIndex(6);
	break;
    case 0x62:  // Exp C
	Part4_PatchGroup_select->setCurrentIndex(7);
	break;
    default:
	Part4_PatchGroup_select->setCurrentIndex(0);
	break;
  }	// end SWITCH
  Part4_SetPatchMax();
  Part4_PatchNumber_select->setValue((active_area->active_performance.perf_part[3].patch_num_high*16) + active_area->active_performance.perf_part[3].patch_num_low+1);
  Part4_PatchName_display->setText(QString::fromAscii(&active_area->active_perf_patch[3].patch_common.name[0],12));
  Part4_LowLimit_display->setText(funcNoteCalc(Part4_LowLimit_select->value()));
  Part4_HighLimit_display->setText(funcNoteCalc(Part4_HighLimit_select->value()));
  
  Part4_ReceivePrgChg_enable->setEnabled(AcceptProgramChg_switch->isChecked());
  Part4_ReceiveVolume_enable->setEnabled(AcceptVolumeChg_switch->isChecked());
  Part4_ReceiveHold_enable->setEnabled(AcceptHold1Chg_switch->isChecked());
}	// end setPart4_Parms
