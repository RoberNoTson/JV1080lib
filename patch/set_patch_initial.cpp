// set_patch_initial.cpp
// for Patch tab
#include        "JVlibForm.h"
#include        <QtGui>

void::JVlibForm::setPatchParms(int val) {
  // sets controls/displays so they match the synth, based on what is in the active area
  // passed a Perf part number, else 0 means we are in Patch mode
  state_table->updates_enabled = false;
 if (state_table->perf_mode && val) {	// set Performance Parts for specified part number (val)
  int pn = val-1;
  // set controls
  //Patch_Group_select
    switch(active_area->active_performance.perf_part[pn].patch_group_id) {
    case 0x01:  // User
      Patch_Group_select->setCurrentIndex(0);
      break;
    case 0x02:  // Exp A
        Patch_Group_select->setCurrentIndex(1);
        break;
    case 0x03:  // Preset A
        Patch_Group_select->setCurrentIndex(2);
        break;
    case 0x04:  // Preset B
        Patch_Group_select->setCurrentIndex(3);
        break;
    case 0x05:  // Preset C
        Patch_Group_select->setCurrentIndex(4);
        break;
    case 0x06:  // Preset D
        Patch_Group_select->setCurrentIndex(5);
        break;
    case 0x10:  // Exp B
        Patch_Group_select->setCurrentIndex(6);
        break;
    case 0x62:  // Exp C
        Patch_Group_select->setCurrentIndex(7);
        break;
    default:
        Patch_Group_select->setCurrentIndex(0);
        break;
  }     // end SWITCH

  Patch_Number_select->setValue((active_area->active_performance.perf_part[pn].patch_num_high*16)+(active_area->active_performance.perf_part[pn].patch_num_low%16)+1);
  Patch_Name_edit->setText(QString::fromAscii(&active_area->active_perf_patch[pn].patch_common.name[0],12));
  if (Patch_PerfPartNum_select->itemText(0)=="0")
    Patch_PerfPartNum_select->removeItem(0);
  
  Patch_HoldPeak_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_common.control_hold_peak);
  Patch_C1_HoldPeak_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_common.control_1_hold_peak);
  Patch_C2_HoldPeak_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_common.control_2_hold_peak);
  Patch_C3_HoldPeak_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_common.control_3_hold_peak);
  Patch_BenderDown_select->setValue(active_area->active_perf_patch[pn].patch_common.bender_range_down*(-1));
  Patch_BenderUp_select->setValue(active_area->active_perf_patch[pn].patch_common.bender_range_up);
  Patch_Struct12_select->setValue(active_area->active_perf_patch[pn].patch_common.structure_type_1_2+1);
  Patch_Booster12_select->setValue(active_area->active_perf_patch[pn].patch_common.booster_level_1_2*6);
  Patch_Struct34_select->setValue(active_area->active_perf_patch[pn].patch_common.structure_type_3_4+1);
  Patch_Booster34_select->setValue(active_area->active_perf_patch[pn].patch_common.booster_level_3_4*6);
  Patch_DefaultTempo_select->setValue((active_area->active_perf_patch[pn].patch_common.default_tempo_high*16) + active_area->active_perf_patch[pn].patch_common.default_tempo_low);
  Patch_Tone1_enable->setChecked(active_area->active_perf_patch[pn].patch_tone[0].tone);
  Patch_Tone2_enable->setChecked(active_area->active_perf_patch[pn].patch_tone[1].tone);
  Patch_Tone3_enable->setChecked(active_area->active_perf_patch[pn].patch_tone[2].tone);
  Patch_Tone4_enable->setChecked(active_area->active_perf_patch[pn].patch_tone[3].tone);
  Patch_Level_select->setValue(active_area->active_perf_patch[pn].patch_common.level);
  Patch_Pan_select->setValue(active_area->active_perf_patch[pn].patch_common.pan-64);
  Patch_AnalogFeel_select->setValue(active_area->active_perf_patch[pn].patch_common.analog_feel_depth);
  Patch_PortamentoTime_select->setValue(active_area->active_perf_patch[pn].patch_common.portamento_time);
  Patch_VoicePriority_switch->setChecked(active_area->active_perf_patch[pn].patch_common.voice_priority);
  Patch_VoiceMode_switch->setChecked(active_area->active_perf_patch[pn].patch_common.key_assign_mode);
  Patch_SoloLegato_enable->setChecked(active_area->active_perf_patch[pn].patch_common.legato);
  Patch_PortamentoEnable_switch->setChecked(active_area->active_perf_patch[pn].patch_common.portamento);
  Patch_PortamentoMode_switch->setChecked(active_area->active_perf_patch[pn].patch_common.portamento_mode);
  Patch_PortamentoType_switch->setChecked(active_area->active_perf_patch[pn].patch_common.portamento_type);
  Patch_PortamentoStart_switch->setChecked(active_area->active_perf_patch[pn].patch_common.portamento_start);
  Patch_VoicePriority_switch->setText(active_area->active_perf_patch[pn].patch_common.voice_priority==0 ? QString("Last") : QString("Loudest"));
  Patch_VoiceMode_switch->setText(active_area->active_perf_patch[pn].patch_common.key_assign_mode==0 ? QString("Poly") : QString("Solo"));
  Patch_PortamentoEnable_switch->setText(active_area->active_perf_patch[pn].patch_common.portamento==0 ? QString("Off") : QString("On"));
  Patch_PortamentoMode_switch->setText(active_area->active_perf_patch[pn].patch_common.portamento_mode==0 ? QString("Normal") : QString("Legato"));
  Patch_PortamentoType_switch->setText(active_area->active_perf_patch[pn].patch_common.portamento_type==0 ? QString("Rate") : QString("Time"));
  Patch_PortamentoStart_switch->setText(active_area->active_perf_patch[pn].patch_common.portamento_start==0 ? QString("Pitch") : QString("Note"));
  Patch_VelocityRange_enable->setChecked(active_area->active_perf_patch[pn].patch_common.velocity_range);
  Patch_ControlSource2_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_common.patch_control_src_2);
  Patch_ControlSource3_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_common.patch_control_src_3);

  PatchEFX_ChorusSend_select->setValue(active_area->active_perf_patch[pn].patch_common.EFX_chorus_send_level);
  PatchEFX_ReverbSend_select->setValue(active_area->active_perf_patch[pn].patch_common.EFX_reverb_send_level);
  PatchEFX_OutputLevel_select->setValue(active_area->active_perf_patch[pn].patch_common.EFX_output_level);
  PatchEFX_Control1Depth_select->setValue(active_area->active_perf_patch[pn].patch_common.EFX_control_depth_1-63);
  PatchEFX_Control2Depth_select->setValue(active_area->active_perf_patch[pn].patch_common.EFX_control_depth_2-63);
  PatchEFX_ReverbLevel_select->setValue(active_area->active_perf_patch[pn].patch_common.reverb_level);
  PatchEFX_ReverbTime_select->setValue(active_area->active_perf_patch[pn].patch_common.reverb_time);
  PatchEFX_ReverbFeedback_select->setValue(active_area->active_perf_patch[pn].patch_common.reverb_feedback);
  PatchEFX_ChorusLevel_select->setValue(active_area->active_perf_patch[pn].patch_common.chorus_level);
  PatchEFX_ChorusRate_select->setValue(active_area->active_perf_patch[pn].patch_common.chorus_rate);
  PatchEFX_ChorusDepth_select->setValue(active_area->active_perf_patch[pn].patch_common.chorus_depth);
  PatchEFX_ChorusPreDelay_select->setValue(active_area->active_perf_patch[pn].patch_common.chorus_pre_delay);
  PatchEFX_ChorusFeedback_select->setValue(active_area->active_perf_patch[pn].patch_common.chorus_feedback);
  PatchEFX_Output_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_common.EFX_output);
  PatchEFX_Type_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_common.EFX_type);
  PatchEFX_Control1Source_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_common.EFX_control_src_1);
  PatchEFX_Control2Source_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_common.EFX_control_src_2);
  PatchEFX_ReverbType_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_common.reverb_type);
  PatchEFX_ReverbHiFreqDamp_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_common.reverb_HF_damp);
  PatchEFX_ChorusOutput_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_common.chorus_output);
  Tone_ToneNumber_select->setMaximum(Patch_Tone4_enable->isChecked() ?
    4:Patch_Tone3_enable->isChecked() ?
      3:Patch_Tone2_enable->isChecked() ? 2:1);
  Tone_ToneNumber_select->setValue(Patch_Tone1_enable->isChecked() ?
    1:Patch_Tone2_enable->isChecked() ?
      2:Patch_Tone3_enable->isChecked() ?
	3:Patch_Tone4_enable->isChecked() ? 4:1);
  int tn = Tone_ToneNumber_select->value()-1;
  
  Tone_Number_select->blockSignals(true);
  Tone_Number_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].wave_num_low+(active_area->active_perf_patch[pn].patch_tone[tn].wave_num_high * 16) + 1);
  Tone_Number_select->blockSignals(false);
  switch(active_area->active_perf_patch[pn].patch_tone[tn].wave_group_id) {
    case 0x01:
    default:
     Tone_Group_select->setCurrentIndex(0);
     break;
    case 0x02:
      Tone_Group_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].wave_group==0?1:2);
      break;
    case 0x10:
      Tone_Group_select->setCurrentIndex(3);
      break;
    case 0x62:
      Tone_Group_select->setCurrentIndex(4);
      break;
    }
 }	// end Performance mode settings 
 else 
 {	// Patch mode settings
 
  //Patch_Group_select
  switch(system_area->sys_common.patch_group_id) {
    case 0x01:  // User
      Patch_Group_select->setCurrentIndex(0);
      Patch_Number_select->setMaximum(128);
      break;
    case 0x02:  // Exp A
      Patch_Group_select->setCurrentIndex(1);
      Patch_Number_select->setMaximum(255);
      break;
    case 0x03:  // Preset A
      Patch_Group_select->setCurrentIndex(2);
      Patch_Number_select->setMaximum(128);
      break;
    case 0x04:  // Preset B
      Patch_Group_select->setCurrentIndex(3);
      Patch_Number_select->setMaximum(128);
      break;
    case 0x05:  // Preset C
      Patch_Group_select->setCurrentIndex(4);
      Patch_Number_select->setMaximum(128);
      break;
    case 0x06:  // Preset D
      Patch_Group_select->setCurrentIndex(5);
      Patch_Number_select->setMaximum(128);
      break;
    case 0x10:  // Exp B
      Patch_Group_select->setCurrentIndex(6);
      Patch_Number_select->setMaximum(255);
      break;
    case 0x62:  // Exp C
      Patch_Group_select->setCurrentIndex(7);
      Patch_Number_select->setMaximum(255);
      break;
    default:
      Patch_Group_select->setCurrentIndex(0);
      Patch_Number_select->setMaximum(128);
      break;
  }     // end switch patch source
  
  if (Patch_PerfPartNum_select->itemText(0)=="1")
    Patch_PerfPartNum_select->insertItem(0,"0");
  Patch_PerfPartNum_select->setCurrentIndex(0);
  Patch_Number_select->setValue(system_area->sys_common.patch_num_low+(system_area->sys_common.patch_num_high*16)+1);
  Patch_Name_edit->setText(QString::fromAscii(&active_area->active_patch_patch.patch_common.name[0],12));
  Patch_TestTone_switch->setChecked(false);
  Patch_HoldPeak_select->setCurrentIndex(active_area->active_patch_patch.patch_common.control_hold_peak);
  Patch_C1_HoldPeak_select->setCurrentIndex(active_area->active_patch_patch.patch_common.control_1_hold_peak);
  Patch_C2_HoldPeak_select->setCurrentIndex(active_area->active_patch_patch.patch_common.control_2_hold_peak);
  Patch_C3_HoldPeak_select->setCurrentIndex(active_area->active_patch_patch.patch_common.control_3_hold_peak);
  Patch_BenderDown_select->setValue(active_area->active_patch_patch.patch_common.bender_range_down*(-1));
  Patch_BenderUp_select->setValue(active_area->active_patch_patch.patch_common.bender_range_up);
  Patch_Struct12_select->setValue(active_area->active_patch_patch.patch_common.structure_type_1_2+1);
  Patch_Booster12_select->setValue(active_area->active_patch_patch.patch_common.booster_level_1_2*6);
  Patch_Struct34_select->setValue(active_area->active_patch_patch.patch_common.structure_type_3_4+1);
  Patch_Booster34_select->setValue(active_area->active_patch_patch.patch_common.booster_level_3_4*6);
  Patch_DefaultTempo_select->setValue((active_area->active_patch_patch.patch_common.default_tempo_high*16) + active_area->active_patch_patch.patch_common.default_tempo_low);
  Patch_Tone1_enable->setChecked(active_area->active_patch_patch.patch_tone[0].tone);
  Patch_Tone2_enable->setChecked(active_area->active_patch_patch.patch_tone[1].tone);
  Patch_Tone3_enable->setChecked(active_area->active_patch_patch.patch_tone[2].tone);
  Patch_Tone4_enable->setChecked(active_area->active_patch_patch.patch_tone[3].tone);
  Patch_Level_select->setValue(active_area->active_patch_patch.patch_common.level);
  Patch_Pan_select->setValue(active_area->active_patch_patch.patch_common.pan - 64);
  Patch_AnalogFeel_select->setValue(active_area->active_patch_patch.patch_common.analog_feel_depth);
  Patch_PortamentoTime_select->setValue(active_area->active_patch_patch.patch_common.portamento_time);
  Patch_VoicePriority_switch->setChecked(active_area->active_patch_patch.patch_common.voice_priority);
  Patch_VoiceMode_switch->setChecked(active_area->active_patch_patch.patch_common.key_assign_mode);
  Patch_PortamentoEnable_switch->setChecked(active_area->active_patch_patch.patch_common.portamento);
  Patch_PortamentoMode_switch->setChecked(active_area->active_patch_patch.patch_common.portamento_mode);
  Patch_PortamentoType_switch->setChecked(active_area->active_patch_patch.patch_common.portamento_type);
  Patch_PortamentoStart_switch->setChecked(active_area->active_patch_patch.patch_common.portamento_start);
  Patch_VoicePriority_switch->setText(active_area->active_patch_patch.patch_common.voice_priority==0 ? QString("Last") : QString("Loudest"));
  Patch_VoiceMode_switch->setText(active_area->active_patch_patch.patch_common.key_assign_mode==0 ? QString("Poly") : QString("Solo"));
  Patch_PortamentoEnable_switch->setText(active_area->active_patch_patch.patch_common.portamento==0 ? QString("Off") : QString("On"));
  Patch_PortamentoMode_switch->setText(active_area->active_patch_patch.patch_common.portamento_mode==0 ? QString("Normal") : QString("Legato"));
  Patch_PortamentoType_switch->setText(active_area->active_patch_patch.patch_common.portamento_type==0 ? QString("Rate") : QString("Time"));
  Patch_PortamentoStart_switch->setText(active_area->active_patch_patch.patch_common.portamento_start==0 ? QString("Pitch") : QString("Note"));
  Patch_VelocityRange_enable->setChecked(active_area->active_patch_patch.patch_common.velocity_range);
  Patch_ControlSource2_select->setCurrentIndex(active_area->active_patch_patch.patch_common.patch_control_src_2);
  Patch_ControlSource3_select->setCurrentIndex(active_area->active_patch_patch.patch_common.patch_control_src_3);
  
  PatchEFX_ChorusSend_select->setValue(active_area->active_patch_patch.patch_common.EFX_chorus_send_level);
  PatchEFX_ReverbSend_select->setValue(active_area->active_patch_patch.patch_common.EFX_reverb_send_level);
  PatchEFX_OutputLevel_select->setValue(active_area->active_patch_patch.patch_common.EFX_output_level);
  PatchEFX_Control1Depth_select->setValue(active_area->active_patch_patch.patch_common.EFX_control_depth_1-63);
  PatchEFX_Control2Depth_select->setValue(active_area->active_patch_patch.patch_common.EFX_control_depth_2-63);
  PatchEFX_ReverbLevel_select->setValue(active_area->active_patch_patch.patch_common.reverb_level);
  PatchEFX_ReverbTime_select->setValue(active_area->active_patch_patch.patch_common.reverb_time);
  PatchEFX_ReverbFeedback_select->setValue(active_area->active_patch_patch.patch_common.reverb_feedback);
  PatchEFX_ChorusLevel_select->setValue(active_area->active_patch_patch.patch_common.chorus_level);
  PatchEFX_ChorusRate_select->setValue(active_area->active_patch_patch.patch_common.chorus_rate);
  PatchEFX_ChorusDepth_select->setValue(active_area->active_patch_patch.patch_common.chorus_depth);
  PatchEFX_ChorusPreDelay_select->setValue(active_area->active_patch_patch.patch_common.chorus_pre_delay);
  PatchEFX_ChorusFeedback_select->setValue(active_area->active_patch_patch.patch_common.chorus_feedback);
  PatchEFX_Output_select->setCurrentIndex(active_area->active_patch_patch.patch_common.EFX_output);
  PatchEFX_Type_select->setCurrentIndex(active_area->active_patch_patch.patch_common.EFX_type);
  PatchEFX_Control1Source_select->setCurrentIndex(active_area->active_patch_patch.patch_common.EFX_control_src_1);
  PatchEFX_Control2Source_select->setCurrentIndex(active_area->active_patch_patch.patch_common.EFX_control_src_2);
  PatchEFX_ReverbType_select->setCurrentIndex(active_area->active_patch_patch.patch_common.reverb_type);
  PatchEFX_ReverbHiFreqDamp_select->setCurrentIndex(active_area->active_patch_patch.patch_common.reverb_HF_damp);
  PatchEFX_ChorusOutput_select->setCurrentIndex(active_area->active_patch_patch.patch_common.chorus_output);
  Tone_ToneNumber_select->setMaximum(Patch_Tone4_enable->isChecked() ?
    4:Patch_Tone3_enable->isChecked() ?
      3:Patch_Tone2_enable->isChecked() ? 2:1);
  Tone_ToneNumber_select->setValue(Patch_Tone1_enable->isChecked() ?
    1:Patch_Tone2_enable->isChecked() ?
      2:Patch_Tone3_enable->isChecked() ?
	3:Patch_Tone4_enable->isChecked() ? 4:1);
  int tn = Tone_ToneNumber_select->value()-1;
  switch(active_area->active_patch_patch.patch_tone[tn].wave_group_id) {
    case 0x01:
    default:
     Tone_Group_select->setCurrentIndex(0);
     break;
    case 0x02:
      Tone_Group_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].wave_group==0 ? 1 : 2);
      break;
    case 0x10:
      Tone_Group_select->setCurrentIndex(3);
      break;
    case 0x62:
      Tone_Group_select->setCurrentIndex(4);
      break;
  }
  Tone_Number_select->setValue(active_area->active_patch_patch.patch_tone[tn].wave_num_low+(active_area->active_patch_patch.patch_tone[tn].wave_num_high * 16) + 1);
//  setPatchEFXparms();
 }	// end Patch mode settings
 
//--------------------------------------------------------------------------------------------------
// Enable structures as needed
  switch(Patch_Struct12_select->value()) {
    case 1:
      Patch_Struct12_view->setScene(scene1);
      Patch_Booster12_select->setEnabled(false);
      break;
    case 2:
      Patch_Struct12_view->setScene(scene2);
      Patch_Booster12_select->setEnabled(false);
      break;
    case 3:
      Patch_Struct12_view->setScene(scene3);
      Patch_Booster12_select->setEnabled(true);
      break;
    case 4:
      Patch_Struct12_view->setScene(scene4);
      Patch_Booster12_select->setEnabled(true);
      break;
    case 5:
      Patch_Struct12_view->setScene(scene5);
      Patch_Booster12_select->setEnabled(false);
      break;
    case 6:
      Patch_Struct12_view->setScene(scene6);
      Patch_Booster12_select->setEnabled(false);
      break;
    case 7:
      Patch_Struct12_view->setScene(scene7);
      Patch_Booster12_select->setEnabled(false);
      break;
    case 8:
      Patch_Struct12_view->setScene(scene8);
      Patch_Booster12_select->setEnabled(false);
      break;
    case 9:
      Patch_Struct12_view->setScene(scene9);
      Patch_Booster12_select->setEnabled(false);
      break;
    case 10:
      Patch_Struct12_view->setScene(scene10);
      Patch_Booster12_select->setEnabled(false);
      break;
    default:
      Patch_Struct12_view->setScene(scene1);
      Patch_Booster12_select->setEnabled(false);
      break;
  }	// end SWitch
  switch(Patch_Struct34_select->value()) {
    case 1:
      Patch_Struct34_view->setScene(scene1);
      Patch_Booster34_select->setEnabled(false);
      break;
    case 2:
      Patch_Struct34_view->setScene(scene2);
      Patch_Booster34_select->setEnabled(false);
      break;
    case 3:
      Patch_Struct34_view->setScene(scene3);
      Patch_Booster34_select->setEnabled(true);
      break;
    case 4:
      Patch_Struct34_view->setScene(scene4);
      Patch_Booster34_select->setEnabled(true);
      break;
    case 5:
      Patch_Struct34_view->setScene(scene5);
      Patch_Booster34_select->setEnabled(false);
      break;
    case 6:
      Patch_Struct34_view->setScene(scene6);
      Patch_Booster34_select->setEnabled(false);
      break;
    case 7:
      Patch_Struct34_view->setScene(scene7);
      Patch_Booster34_select->setEnabled(false);
      break;
    case 8:
      Patch_Struct34_view->setScene(scene8);
      Patch_Booster34_select->setEnabled(false);
      break;
    case 9:
      Patch_Struct34_view->setScene(scene9);
      Patch_Booster34_select->setEnabled(false);
      break;
    case 10:
      Patch_Struct34_view->setScene(scene10);
      Patch_Booster34_select->setEnabled(false);
      break;
    default:
      Patch_Struct34_view->setScene(scene1);
      break;
  }
  Patch_Struct12_view->show();
  Patch_Struct34_view->show();

// Enable controls as needed
  Patch_SoloLegato_enable->setEnabled(Patch_VoiceMode_switch->isChecked());  
  Patch_PerfPartNum_select->setEnabled(state_table->perf_mode?true:false);

  switch(Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()) {
    case 0:
      Patch_Number_select->setEnabled(true);
      Patch_Group_select->setEnabled(true);
      Patch_Name_edit->setEnabled(true);
      break;
    case 1:
      Patch_Number_select->setEnabled( Part1_ReceivePrgChg_enable->isChecked() );
      Patch_Group_select->setEnabled( Part1_ReceivePrgChg_enable->isChecked() );
      Patch_Name_edit->setEnabled( Part1_ReceivePrgChg_enable->isChecked() );
      break;
    case 2:
      Patch_Number_select->setEnabled( Part2_ReceivePrgChg_enable->isChecked() );
      Patch_Group_select->setEnabled( Part2_ReceivePrgChg_enable->isChecked() );
      Patch_Name_edit->setEnabled( Part2_ReceivePrgChg_enable->isChecked() );
      break;     
    case 3:
      Patch_Number_select->setEnabled( Part3_ReceivePrgChg_enable->isChecked() );
      Patch_Group_select->setEnabled( Part3_ReceivePrgChg_enable->isChecked() );
      Patch_Name_edit->setEnabled( Part3_ReceivePrgChg_enable->isChecked() );
      break;     
    case 4:
      Patch_Number_select->setEnabled( Part4_ReceivePrgChg_enable->isChecked() );
      Patch_Group_select->setEnabled( Part4_ReceivePrgChg_enable->isChecked() );
      Patch_Name_edit->setEnabled( Part4_ReceivePrgChg_enable->isChecked() );
      break;      
    case 5:
      Patch_Number_select->setEnabled( Part5_ReceivePrgChg_enable->isChecked() );
      Patch_Group_select->setEnabled( Part5_ReceivePrgChg_enable->isChecked() );
      Patch_Name_edit->setEnabled( Part5_ReceivePrgChg_enable->isChecked() );
      break;
    case 6:
      Patch_Number_select->setEnabled( Part6_ReceivePrgChg_enable->isChecked() );
      Patch_Group_select->setEnabled( Part6_ReceivePrgChg_enable->isChecked() );
      Patch_Name_edit->setEnabled( Part6_ReceivePrgChg_enable->isChecked() );
      break;
    case 7:
      Patch_Number_select->setEnabled( Part7_ReceivePrgChg_enable->isChecked() );
      Patch_Group_select->setEnabled( Part7_ReceivePrgChg_enable->isChecked() );
      Patch_Name_edit->setEnabled( Part7_ReceivePrgChg_enable->isChecked() );
      break;     
    case 8:
      Patch_Number_select->setEnabled( Part8_ReceivePrgChg_enable->isChecked() );
      Patch_Group_select->setEnabled( Part8_ReceivePrgChg_enable->isChecked() );
      Patch_Name_edit->setEnabled( Part8_ReceivePrgChg_enable->isChecked() );
      break;     
    case 9:
      Patch_Number_select->setEnabled( Part9_ReceivePrgChg_enable->isChecked() );
      Patch_Group_select->setEnabled( Part9_ReceivePrgChg_enable->isChecked() );
      Patch_Name_edit->setEnabled( Part9_ReceivePrgChg_enable->isChecked() );
      break;      
    case 11:
      Patch_Number_select->setEnabled( Part11_ReceivePrgChg_enable->isChecked() );
      Patch_Group_select->setEnabled( Part11_ReceivePrgChg_enable->isChecked() );
      Patch_Name_edit->setEnabled( Part11_ReceivePrgChg_enable->isChecked() );
      break;
    case 12:
      Patch_Number_select->setEnabled( Part12_ReceivePrgChg_enable->isChecked() );
      Patch_Group_select->setEnabled( Part12_ReceivePrgChg_enable->isChecked() );
      Patch_Name_edit->setEnabled( Part12_ReceivePrgChg_enable->isChecked() );
      break;
    case 13:
      Patch_Number_select->setEnabled( Part13_ReceivePrgChg_enable->isChecked() );
      Patch_Group_select->setEnabled( Part13_ReceivePrgChg_enable->isChecked() );
      Patch_Name_edit->setEnabled( Part13_ReceivePrgChg_enable->isChecked() );
      break;
    case 14:
      Patch_Number_select->setEnabled( Part14_ReceivePrgChg_enable->isChecked() );
      Patch_Group_select->setEnabled( Part14_ReceivePrgChg_enable->isChecked() );
      Patch_Name_edit->setEnabled( Part14_ReceivePrgChg_enable->isChecked() );
      break;
    case 15:
      Patch_Number_select->setEnabled( Part15_ReceivePrgChg_enable->isChecked() );
      Patch_Group_select->setEnabled( Part15_ReceivePrgChg_enable->isChecked() );
      Patch_Name_edit->setEnabled( Part15_ReceivePrgChg_enable->isChecked() );
      break;
  }	// end Switch  
  PatchEFX_Group_display->setText(Patch_Group_select->currentText());
  PatchEFX_Number_display->setText(QString::number(Patch_Number_select->value()));
  PatchEFX_Name_display->setText(Patch_Name_edit->text());
  Tone_PatchName_display->setText(Patch_Name_edit->text());
  Tone_PatchGroup_display->setText(Patch_Group_select->currentText());
  Tone_PatchNumber_display->setText(QString::number(Patch_Number_select->value()));
//  Tone_WaveName_display->setText(WaveName_query());
  // set EFX parms
  setPatchEFXparms();
  setToneParms(val);
  state_table->patch_modified = false;
  state_table->patch_sync = true;
  state_table->updates_enabled = true;
}	// end setPatchParms
