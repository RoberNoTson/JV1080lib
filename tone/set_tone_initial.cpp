// set_tone_initial.cpp
// for Tone Tab
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setToneParms(int val) {
  // called after download from Synth, initiated by the Patch or Tone Sync buttons, or changing the Tone Number
  // (int val) is either 1-16 for the Patch_PerfPartNumber or 0 for Patch mode.
  // Also sets ToneENV, ToneEFX and Pitch parms
  int tn = Tone_ToneNumber_select->value()-1;
//printf("Setting parms for Tone # %d\n", tn+1);

  // set Performance mode patch data
  if (state_table->perf_mode && val) {
    int pn = val-1;
    // Tone_Group
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
    }	// end Switch
  if (state_table->db_connect) {
    // set wave_list maximum Number
    QSqlQuery query(mysql);
    query.prepare("Select number from wave_list where group_area = ?");
    query.bindValue(0, Tone_Group_select->currentText());
    if (query.exec() == false) {
      puts("Query exec failed in on_Tone_Group_select_currentIndexChanged");
      QMessageBox::critical(this, "JVlib", QString("Query failed in setWaveChooser for query\n%1") .arg(query.executedQuery()));
      query.finish();
      return;
    }
    if (query.size()==0) {
      puts("0 rows found in on_Tone_Group_select_currentIndexChanged"); 
      QMessageBox::critical(this, "JVlib", QString("0 rows returned in setWaveChooser for query\n%1") .arg(query.executedQuery()));
      query.finish();
      return;
    }
    Tone_Number_select->setMaximum((int)query.size());
    query.finish();
  }	// end db_connect

//printf("Tone_Number Wave value is %d, wave_group_id is %2x\n",active_area->active_perf_patch[pn].patch_tone[tn].wave_num_low+(active_area->active_perf_patch[pn].patch_tone[tn].wave_num_high*16)+1, active_area->active_perf_patch[pn].patch_tone[tn].wave_group_id);
    Tone_Number_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].wave_num_low + 
      (active_area->active_perf_patch[pn].patch_tone[tn].wave_num_high*16)+1);
    // set various switches
    Tone_Output_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].output);
    Tone_C1D1_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].cont_1_dest_1);
    Tone_C1D2_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].cont_1_dest_2);
    Tone_C1D3_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].cont_1_dest_3);
    Tone_C1D4_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].cont_1_dest_4);
    Tone_C2D1_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].cont_2_dest_1);
    Tone_C2D2_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].cont_2_dest_2);
    Tone_C2D3_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].cont_2_dest_3);
    Tone_C2D4_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].cont_2_dest_4);
    Tone_C3D1_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].cont_3_dest_1);
    Tone_C3D2_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].cont_3_dest_2);
    Tone_C3D3_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].cont_3_dest_3);
    Tone_C3D4_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].cont_3_dest_4);
    Tone_C1D1Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].cont_1_depth_1-63);
    Tone_C1D2Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].cont_1_depth_2-63);
    Tone_C1D3Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].cont_1_depth_3-63);
    Tone_C1D4Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].cont_1_depth_4-63);
    Tone_C2D1Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].cont_2_depth_1-63);
    Tone_C2D2Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].cont_2_depth_2-63);
    Tone_C2D3Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].cont_2_depth_3-63);
    Tone_C2D4Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].cont_2_depth_4-63);
    Tone_C3D1Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].cont_3_depth_1-63);
    Tone_C3D2Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].cont_3_depth_2-63);
    Tone_C3D3Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].cont_3_depth_3-63);
    Tone_C3D4Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].cont_3_depth_4-63);
    Tone_WaveGain_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].wave_gain );
    Tone_DelayMode_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].tone_delay_mode);
    Tone_ChorusSend_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].chorus_level );
    Tone_ReverbSend_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn]. reverb_level);
    Tone_OutputLevel_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].output_level );
    Tone_Level_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].tone_level );
    Tone_VeloXfadeDepth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].veloc_xfade_depth);
    Tone_VeloLowerRange_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].veloc_range_lower);
    Tone_DelayTime_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].tone_delay_time);
    Tone_VeloUpperRange_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].veloc_range_upper);
    Tone_ReceiveVolume_enable->setChecked(active_area->active_perf_patch[pn].patch_tone[tn].volume_control);
    Tone_ReceiveHold_enable->setChecked(active_area->active_perf_patch[pn].patch_tone[tn].hold_1_control);
    Tone_ReceiveReDamper_enable->setChecked(active_area->active_perf_patch[pn].patch_tone[tn].redamper_control);
    Tone_ReceiveBender_enable->setChecked(active_area->active_perf_patch[pn].patch_tone[tn].bender_control);
    Tone_FXM_enable->setChecked(active_area->active_perf_patch[pn].patch_tone[tn].FXM);
    Tone_FXMColor_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].FXM_color);
    Tone_FXMDepth_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].FXM_depth);
  }	// end set Perf mode patch
  else 
  {
    // set Patch mode patch 
    switch(active_area->active_patch_patch.patch_tone[tn].wave_group_id) {
    case 0x01:
    default:
     Tone_Group_select->setCurrentIndex(0);
     break;
    case 0x02:
      Tone_Group_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].wave_group==0?1:2);
      break;
    case 0x10:
      Tone_Group_select->setCurrentIndex(3);
      break;
    case 0x62:
      Tone_Group_select->setCurrentIndex(4);
      break;
    }	// end Switch

    Tone_Number_select->setValue(active_area->active_patch_patch.patch_tone[tn].wave_num_low + 
      (active_area->active_patch_patch.patch_tone[tn].wave_num_high*16)+1);
    Tone_Output_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].output);
    Tone_C1D1_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].cont_1_dest_1);
    Tone_C1D2_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].cont_1_dest_2);
    Tone_C1D3_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].cont_1_dest_3);
    Tone_C1D4_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].cont_1_dest_4);
    Tone_C2D1_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].cont_2_dest_1);
    Tone_C2D2_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].cont_2_dest_2);
    Tone_C2D3_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].cont_2_dest_3);
    Tone_C2D4_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].cont_2_dest_4);
    Tone_C3D1_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].cont_3_dest_1);
    Tone_C3D2_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].cont_3_dest_2);
    Tone_C3D3_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].cont_3_dest_3);
    Tone_C3D4_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].cont_3_dest_4);
    Tone_C1D1Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].cont_1_depth_1-63);
    Tone_C1D2Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].cont_1_depth_2-63);
    Tone_C1D3Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].cont_1_depth_3-63);
    Tone_C1D4Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].cont_1_depth_4-63);
    Tone_C2D1Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].cont_2_depth_1-63);
    Tone_C2D2Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].cont_2_depth_2-63);
    Tone_C2D3Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].cont_2_depth_3-63);
    Tone_C2D4Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].cont_2_depth_4-63);
    Tone_C3D1Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].cont_3_depth_1-63);
    Tone_C3D2Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].cont_3_depth_2-63);
    Tone_C3D3Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].cont_3_depth_3-63);
    Tone_C3D4Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].cont_3_depth_4-63);
    Tone_WaveGain_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].wave_gain );
    Tone_DelayMode_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].tone_delay_mode);
    Tone_ChorusSend_select->setValue(active_area->active_patch_patch.patch_tone[tn].chorus_level );
    Tone_ReverbSend_select->setValue(active_area->active_patch_patch.patch_tone[tn]. reverb_level);
    Tone_OutputLevel_select->setValue(active_area->active_patch_patch.patch_tone[tn].output_level );
    Tone_Level_select->setValue(active_area->active_patch_patch.patch_tone[tn].tone_level );
    Tone_VeloXfadeDepth_select->setValue(active_area->active_patch_patch.patch_tone[tn].veloc_xfade_depth );
    Tone_VeloLowerRange_select->setValue(active_area->active_patch_patch.patch_tone[tn].veloc_range_lower );
    Tone_DelayTime_select->setValue(active_area->active_patch_patch.patch_tone[tn].tone_delay_time);
    Tone_VeloUpperRange_select->setValue(active_area->active_patch_patch.patch_tone[tn].veloc_range_upper );
    Tone_ReceiveVolume_enable->setChecked(active_area->active_patch_patch.patch_tone[tn].volume_control );
    Tone_ReceiveHold_enable->setChecked(active_area->active_patch_patch.patch_tone[tn].hold_1_control );
    Tone_ReceiveReDamper_enable->setChecked(active_area->active_patch_patch.patch_tone[tn].redamper_control );
    Tone_ReceiveBender_enable->setChecked(active_area->active_patch_patch.patch_tone[tn].bender_control );
    Tone_FXM_enable->setChecked(active_area->active_patch_patch.patch_tone[tn].FXM);
    Tone_FXMColor_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].FXM_color);
    Tone_FXMDepth_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].FXM_depth);
  }	// end set Patch Mode patch
  
  on_Tone_DelayTime_select_valueChanged(Tone_DelayTime_select->value());	// initialze Tone_DelayTime_display
 
  Tone_InstrFamily_select->setCurrentIndex(-1);
  setWaveChooser();
  setToneEFXParms(val);
  setToneENVParms(val);
  setPitchParms(val);
  state_table->tone_modified = false;
  Enable_Tone(true);
}	// end setToneParms
