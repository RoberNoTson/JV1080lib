// set_initial.cpp
// for Parts tab, Part_7

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setPart7_Parms() {
  // set Part 1 controls/displays based on the active area memory contents, 
  // which were just updated from the synth after a Sync button was clicked.
  //  state_table->updates_enabled = false was set by the calling program, do not change it here.
  QString str;
  Part7_Level_select->setValue(active_area->active_performance.perf_part[6].level);
  Part7_Level_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[6].level));
  Part7_Pan_select->setValue(active_area->active_performance.perf_part[6].pan);
  Part7_Pan_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[6].pan));
  Part7_ChorusSend_select->setValue(active_area->active_performance.perf_part[6].chorus_send_level);
  Part7_ChorusSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[6].chorus_send_level));
  Part7_ReverbSend_select->setValue(active_area->active_performance.perf_part[6].reverb_send_level);
  Part7_ReverbSend_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[6].reverb_send_level));
  Part7_OutputLevel_select->setValue(active_area->active_performance.perf_part[6].output_level);
  Part7_OutputLevel_select->setStatusTip(str.setNum(active_area->active_performance.perf_part[6].output_level));
  Part7_Transpose_select->setValue(active_area->active_performance.perf_part[6].coarse_tune-48);
  Part7_Transpose_display->display(active_area->active_performance.perf_part[6].coarse_tune-48);
  Part7_TuneAdj_select->setValue(active_area->active_performance.perf_part[6].fine_tune-50);
  Part7_VoiceReserve_select->setValue(active_area->active_performance.perf_common.voice_reserve[6]);
  Part7_LowLimit_select->setValue(active_area->active_performance.perf_part[6].key_lower);
  Part7_HighLimit_select->setValue(active_area->active_performance.perf_part[6].key_upper);
  Part7_ReceiveMidi_enable->setChecked(active_area->active_performance.perf_part[6].MIDI_receive);
  Part7_MidiChannel_select->setValue(active_area->active_performance.perf_part[6].MIDI_channel+1);
  Part7_ReceivePrgChg_enable->setChecked(active_area->active_performance.perf_part[6].receive_program_change);
  Part7_ReceiveVolume_enable->setChecked(active_area->active_performance.perf_part[6].receive_volume);
  Part7_ReceiveHold_enable->setChecked(active_area->active_performance.perf_part[6].receive_hold_1);
  Part7_Output_select->setCurrentIndex(active_area->active_performance.perf_part[6].output);
  Part7_TestTone_switch->setChecked(false);
  
  switch(active_area->active_performance.perf_part[6].patch_group_id) {
    case 0x01:  // User
      Part7_PatchGroup_select->setCurrentIndex(0);
      break;
    case 0x02:  // Exp A
	Part7_PatchGroup_select->setCurrentIndex(1);
	break;
    case 0x03:  // Preset A
	Part7_PatchGroup_select->setCurrentIndex(2);
	break;
    case 0x04:  // Preset B
	Part7_PatchGroup_select->setCurrentIndex(3);
	break;
    case 0x05:  // Preset C
	Part7_PatchGroup_select->setCurrentIndex(4);
	break;
    case 0x06:  // Preset D
	Part7_PatchGroup_select->setCurrentIndex(5);
	break;
    case 0x10:  // Exp B
	Part7_PatchGroup_select->setCurrentIndex(6);
	break;
    case 0x62:  // Exp C
	Part7_PatchGroup_select->setCurrentIndex(7);
	break;
    default:
	Part7_PatchGroup_select->setCurrentIndex(0);
	break;
  }	// end SWITCH
  Part7_SetPatchMax();
  Part7_PatchNumber_select->setValue((active_area->active_performance.perf_part[6].patch_num_high*16) + active_area->active_performance.perf_part[6].patch_num_low+1);
  Part7_PatchName_display->setText(QString::fromAscii(&active_area->active_perf_patch[6].patch_common.name[0],12));
  Part7_LowLimit_display->setText(funcNoteCalc(Part7_LowLimit_select->value()));
  Part7_HighLimit_display->setText(funcNoteCalc(Part7_HighLimit_select->value()));
  
  Part7_ReceivePrgChg_enable->setEnabled(AcceptProgramChg_switch->isChecked());
  Part7_ReceiveVolume_enable->setEnabled(AcceptVolumeChg_switch->isChecked());
  Part7_ReceiveHold_enable->setEnabled(AcceptHold1Chg_switch->isChecked());
}	// end setPart7_Parms
