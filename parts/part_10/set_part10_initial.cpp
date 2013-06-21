// set_initial.cpp
// for Parts tab, Part_10

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setPart10_Parms() {
  // set Part 1 controls/displays based on the active area memory contents, 
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
  Part10_TestTone_switch->setChecked(false);
  
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
  
  Part10_ReceivePrgChg_enable->setEnabled(AcceptProgramChg_switch->isChecked());
  Part10_ReceiveVolume_enable->setEnabled(AcceptVolumeChg_switch->isChecked());
  Part10_ReceiveHold_enable->setEnabled(AcceptHold1Chg_switch->isChecked());
}	// end setPart10_Parms
