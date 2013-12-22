// set_rhythm_initial.cpp
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setRhythmParms(int val) {
  state_table->updates_enabled = false;
  if (val>34) val -= 35;
  else return;
  switch (active_area->active_rhythm.rhythm_note[val].wave_group_id) {
    case 0x01:
      Rhythm_WaveGroup_select->setCurrentIndex(0);
      break;
    case 0x02:
      Rhythm_WaveGroup_select->setCurrentIndex(active_area->active_rhythm.rhythm_note[val].wave_group==0?1:2);
      break;
    case 0x10:
      Rhythm_WaveGroup_select->setCurrentIndex(3);
      break;
    case 0x62:
      Rhythm_WaveGroup_select->setCurrentIndex(4);
      break;
  }
  Rhythm_WaveNumber_select->setValue(active_area->active_rhythm.rhythm_note[val].wave_num_low + 
    (active_area->active_rhythm.rhythm_note[val].wave_num_high*16) + 1);
  
  Rhythm_KeyPress_select->setValue(val+35);
  
  Rhythm_BenderRange_select->setValue(active_area->active_rhythm.rhythm_note[val].bender_range);
  Rhythm_TuneAdj_select->setValue(active_area->active_rhythm.rhythm_note[val].fine_tune - 50);
  Rhythm_ToneLevel_select->setValue(active_area->active_rhythm.rhythm_note[val].tone_level);
  
  // QPushButton
  Rhythm_EnvMode_select->setChecked(active_area->active_rhythm.rhythm_note[val].envelope_mode);
  // QCheckBox
  Rhythm_Note_enable->setChecked(active_area->active_rhythm.rhythm_note[val].tone);
  Rhythm_Hold_enable->setChecked(active_area->active_rhythm.rhythm_note[val].hold_1_control);
  Rhythm_Volume_enable->setChecked(active_area->active_rhythm.rhythm_note[val].volume_control);
  
  // QComboBox
  Rhythm_WaveGain_select->setCurrentIndex(active_area->active_rhythm.rhythm_note[val].wave_gain);
  Rhythm_Output_select->setCurrentIndex(active_area->active_rhythm.rhythm_note[val].output);
  Rhythm_PanControl_select->setCurrentIndex(active_area->active_rhythm.rhythm_note[val].pan_control);
  Rhythm_PitchVeloTime_select->setCurrentIndex(active_area->active_rhythm.rhythm_note[val].P_ENV_veloc_time_sens);
  Rhythm_RandPitchDepth_select->setCurrentIndex(active_area->active_rhythm.rhythm_note[val].random_pitch_depth);
  Rhythm_TVAVelTimeSens_select->setCurrentIndex(active_area->active_rhythm.rhythm_note[val].A_ENV_veloc_time_sens);
  Rhythm_TVFFilterType_select->setCurrentIndex(active_area->active_rhythm.rhythm_note[val].filter_type);
  Rhythm_TVFVelTimeSens_select->setCurrentIndex(active_area->active_rhythm.rhythm_note[val].F_ENV_veloc_time_sens);
  // QSpinBox
  Rhythm_MuteGroup_select->setValue(active_area->active_rhythm.rhythm_note[val].mute_group);
  Rhythm_PanRandDepth_select->setValue(active_area->active_rhythm.rhythm_note[val].random_pan_depth);
  Rhythm_PitchDepth_select->setValue(active_area->active_rhythm.rhythm_note[val].P_ENV_depth - 12);
  Rhythm_TVFDepth_select->setValue(active_area->active_rhythm.rhythm_note[val].F_ENV_depth - 63);
  // QDial
  Rhythm_OutputLevel_select->setValue(active_area->active_rhythm.rhythm_note[val].output_level);
  Rhythm_ChorusSend_select->setValue(active_area->active_rhythm.rhythm_note[val].chorus_level);
  Rhythm_ReverbSend_select->setValue(active_area->active_rhythm.rhythm_note[val].reverb_level);
  Rhythm_Pan_select->setValue(active_area->active_rhythm.rhythm_note[val].tone_pan - 64);
  Rhythm_AltPan_select->setValue(active_area->active_rhythm.rhythm_note[val].alt_pan_depth - 63);
  Rhythm_PitchTime1_select->setValue(active_area->active_rhythm.rhythm_note[val].P_ENV_time[0]);
  Rhythm_PitchTime2_select->setValue(active_area->active_rhythm.rhythm_note[val].P_ENV_time[1]);
  Rhythm_PitchTime3_select->setValue(active_area->active_rhythm.rhythm_note[val].P_ENV_time[2]);
  Rhythm_PitchTime4_select->setValue(active_area->active_rhythm.rhythm_note[val].P_ENV_time[3]);
  Rhythm_PitchLvl1_select->setValue(active_area->active_rhythm.rhythm_note[val].P_ENV_level[0]-63);
  Rhythm_PitchLvl2_select->setValue(active_area->active_rhythm.rhythm_note[val].P_ENV_level[1]-63);
  Rhythm_PitchLvl3_select->setValue(active_area->active_rhythm.rhythm_note[val].P_ENV_level[2]-63);
  Rhythm_PitchLvl4_select->setValue(active_area->active_rhythm.rhythm_note[val].P_ENV_level[3]-63);
  Rhythm_PitchVelocSens_select->setValue((active_area->active_rhythm.rhythm_note[val].P_ENV_veloc_sens-50)*2);
//  Rhythm_PitchVelocSens_display->display((active_area->active_rhythm.rhythm_note[val].P_ENV_veloc_sens*2)-50);
  Rhythm_TVATime1_select->setValue(active_area->active_rhythm.rhythm_note[val].A_ENV_time[0]);
  Rhythm_TVATime2_select->setValue(active_area->active_rhythm.rhythm_note[val].A_ENV_time[1]);
  Rhythm_TVATime3_select->setValue(active_area->active_rhythm.rhythm_note[val].A_ENV_time[2]);
  Rhythm_TVATime4_select->setValue(active_area->active_rhythm.rhythm_note[val].A_ENV_time[3]);
  Rhythm_TVALvl1_select->setValue(active_area->active_rhythm.rhythm_note[val].A_ENV_level[0]);
  Rhythm_TVALvl2_select->setValue(active_area->active_rhythm.rhythm_note[val].A_ENV_level[1]);
  Rhythm_TVALvl3_select->setValue(active_area->active_rhythm.rhythm_note[val].A_ENV_level[2]);
  Rhythm_TVAVelocSens_select->setValue((active_area->active_rhythm.rhythm_note[val].A_ENV_veloc_sens-50)*2);
  Rhythm_TVFTime1_select->setValue(active_area->active_rhythm.rhythm_note[val].F_ENV_time[0]);
  Rhythm_TVFTime2_select->setValue(active_area->active_rhythm.rhythm_note[val].F_ENV_time[1]);
  Rhythm_TVFTime3_select->setValue(active_area->active_rhythm.rhythm_note[val].F_ENV_time[2]);
  Rhythm_TVFTime4_select->setValue(active_area->active_rhythm.rhythm_note[val].F_ENV_time[3]);
  Rhythm_TVFLvl2_select->setValue(active_area->active_rhythm.rhythm_note[val].F_ENV_level[0]);
  Rhythm_TVFLvl3_select->setValue(active_area->active_rhythm.rhythm_note[val].F_ENV_level[1]);
  Rhythm_TVFLvl4_select->setValue(active_area->active_rhythm.rhythm_note[val].F_ENV_level[2]);
  Rhythm_TVFLvl1_select->setValue(active_area->active_rhythm.rhythm_note[val].F_ENV_level[3]);
  Rhythm_TVFResVelocSens_select->setValue((active_area->active_rhythm.rhythm_note[val].resonance_veloc_sens-50)*2);
  Rhythm_TVFCutoffFreq_select->setValue(active_area->active_rhythm.rhythm_note[val].cutoff_freq);
  Rhythm_TVFResonance_select->setValue(active_area->active_rhythm.rhythm_note[val].resonance);
  Rhythm_TVFVelocSens_select->setValue((active_area->active_rhythm.rhythm_note[val].F_ENV_veloc_sens-50)*2);
  // QSlider
  Rhythm_SoundingPitch_select->setValue(active_area->active_rhythm.rhythm_note[val].source_key);
  // special Display settings
  Rhythm_SoundingPitch_display->setText(funcNoteCalc(active_area->active_rhythm.rhythm_note[val].source_key));
  Rhythm_WaveName_display->setText(RhythmName_query());
  Rhythm_KeyPress_display->setText(funcNoteCalc(Rhythm_KeyPress_select->value()));
  Rhythm_PatchName_display->setText(QString::fromAscii(&active_area->active_rhythm.rhythm_common.name[0],12));
  Rhythm_PatchNumber_select->setValue(active_area->active_performance.perf_part[9].patch_num_low + 1);
  switch(active_area->active_performance.perf_part[9].patch_group_id) {
    case 0x01:
      Rhythm_PatchGroup_select->setCurrentIndex(0);
      break;
    case 0x02:
      break;
    case 0x03:
      Rhythm_PatchGroup_select->setCurrentIndex(1);
      break;
    case 0x04:
      Rhythm_PatchGroup_select->setCurrentIndex(2);
      break;
    case 0x05:
      Rhythm_PatchGroup_select->setCurrentIndex(3);
      break;
    case 0x06:
      Rhythm_PatchGroup_select->setCurrentIndex(4);
      break;
    case 0x10:
      Rhythm_PatchGroup_select->setCurrentIndex(5);
      break;
    case 0x62:
      break;
    default:
      Rhythm_PatchGroup_select->setCurrentIndex(0);
      break;
  }	// end Switch
  Rhythm_Pan_display->setText(Pan2Deg(Rhythm_Pan_select->value()));
  Rhythm_AltPan_display->setText(QString::number(Rhythm_AltPan_select->value()/90*63)+" Deg.");
  if (Rhythm_EnvMode_select->isChecked())
    Rhythm_TestTone_switch->setCheckable(true);
  else
    Rhythm_TestTone_switch->setCheckable(false);
//  Rhythm_PatchGroup_select->setEnabled(system_area->sys_common.receive_bank_select);
//  Rhythm_PatchNumber_select->setEnabled(system_area->sys_common.receive_program_change && active_area->active_performance.perf_part[9].receive_program_change);
  state_table->updates_enabled = true;
}	// end setRhythmParms
