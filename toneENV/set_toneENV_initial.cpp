// set_toneENV_initial.cpp
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setToneENVParms(int val) {
  // (int val) is either a part number or 0 for patch mode
  int tn = Tone_ToneNumber_select->value() - 1;
  if (state_table->perf_mode && val) {
    int pn = val - 1;
    ToneTVA_Time1_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].A_ENV_time[0]);
    ToneTVA_Time2_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].A_ENV_time[1]);
    ToneTVA_Time3_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].A_ENV_time[2]);
    ToneTVA_Time4_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].A_ENV_time[3]);
    ToneTVA_Lvl1_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].A_ENV_level[0]);
    ToneTVA_Lvl2_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].A_ENV_level[1]);
    ToneTVA_Lvl3_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].A_ENV_level[2]);
    ToneTVA_LFO1Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].amplitude_LFO_1_depth-63);
    ToneTVA_LFO2Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].amplitude_LFO_2_depth-63);
    ToneTVA_VelocSens_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].A_ENV_veloc_sens*2 - 100);
    ToneTVF_Time1_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].F_ENV_time[0]);
    ToneTVF_Time2_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].F_ENV_time[1]);
    ToneTVF_Time3_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].F_ENV_time[2]);
    ToneTVF_Time4_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].F_ENV_time[3]);
    ToneTVF_Lvl1_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].F_ENV_level[0]);
    ToneTVF_Lvl2_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].F_ENV_level[1]);
    ToneTVF_Lvl3_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].F_ENV_level[2]);
    ToneTVF_Lvl4_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].F_ENV_level[3]);
    ToneTVF_LFO1Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].filter_LFO_1_depth-63);
    ToneTVF_LFO2Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].filter_LFO_2_depth-63);
    ToneTVF_VelocSens_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].F_ENV_veloc_sens*2 - 100);
    ToneTVF_ResVelocSens_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].resonance_veloc_sens*2 - 100);
    ToneTVF_CutoffFreq_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].cutoff_freq);
    ToneTVF_Resonance_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].resonance);
    ToneTVA_BiasPoint_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].bias_point);
    ToneTVF_Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].F_ENV_depth-63);
    ToneTVA_Time1Sens_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].A_ENV_veloc_time_1_sens);
    ToneTVA_Time4Sens_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].A_ENV_veloc_time_4_sens);
    ToneTVA_VelocityCurve_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].A_ENV_veloc_curve);
    ToneTVA_TimeKeyfollow_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].A_ENV_time_keyfollow);
    ToneTVF_TimeKeyfollow_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].F_ENV_time_keyfollow);
    
    ToneTVA_BiasLvl_select->setCurrentIndex(14-active_area->active_perf_patch[pn].patch_tone[tn].bias_level);
    
    ToneTVA_BiasDirection_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].bias_direction);
    ToneTVF_Time1Sens_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].F_ENV_veloc_time_1_sens);
    ToneTVF_Time4Sens_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].F_ENV_veloc_time_4_sens);
    ToneTVF_VelocityCurve_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].F_ENV_veloc_curve);
    ToneTVF_CutoffKeyfollow_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].cutoff_keyfollow);
    ToneTVF_FilterType_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].filter_type);
    
  }	// end Perf mode
  else if(state_table->patch_mode) 
  {	// Patch mode
    ToneTVA_Time1_select->setValue(active_area->active_patch_patch.patch_tone[tn].A_ENV_time[0]);
    ToneTVA_Time2_select->setValue(active_area->active_patch_patch.patch_tone[tn].A_ENV_time[1]);
    ToneTVA_Time3_select->setValue(active_area->active_patch_patch.patch_tone[tn].A_ENV_time[2]);
    ToneTVA_Time4_select->setValue(active_area->active_patch_patch.patch_tone[tn].A_ENV_time[3]);
    ToneTVA_Lvl1_select->setValue(active_area->active_patch_patch.patch_tone[tn].A_ENV_level[0]);
    ToneTVA_Lvl2_select->setValue(active_area->active_patch_patch.patch_tone[tn].A_ENV_level[1]);
    ToneTVA_Lvl3_select->setValue(active_area->active_patch_patch.patch_tone[tn].A_ENV_level[2]);
    ToneTVA_LFO1Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].amplitude_LFO_1_depth-63);
    ToneTVA_LFO2Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].amplitude_LFO_2_depth-63);
    ToneTVA_VelocSens_select->setValue(active_area->active_patch_patch.patch_tone[tn].A_ENV_veloc_sens*2 - 100);
    ToneTVF_Time1_select->setValue(active_area->active_patch_patch.patch_tone[tn].F_ENV_time[0]);
    ToneTVF_Time2_select->setValue(active_area->active_patch_patch.patch_tone[tn].F_ENV_time[1]);
    ToneTVF_Time3_select->setValue(active_area->active_patch_patch.patch_tone[tn].F_ENV_time[2]);
    ToneTVF_Time4_select->setValue(active_area->active_patch_patch.patch_tone[tn].F_ENV_time[3]);
    ToneTVF_Lvl1_select->setValue(active_area->active_patch_patch.patch_tone[tn].F_ENV_level[0]);
    ToneTVF_Lvl2_select->setValue(active_area->active_patch_patch.patch_tone[tn].F_ENV_level[1]);
    ToneTVF_Lvl3_select->setValue(active_area->active_patch_patch.patch_tone[tn].F_ENV_level[2]);
    ToneTVF_Lvl4_select->setValue(active_area->active_patch_patch.patch_tone[tn].F_ENV_level[3]);
    ToneTVF_LFO1Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].filter_LFO_1_depth-63);
    ToneTVF_LFO2Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].filter_LFO_2_depth-63);
    ToneTVF_VelocSens_select->setValue(active_area->active_patch_patch.patch_tone[tn].F_ENV_veloc_sens*2 - 100);
    ToneTVF_ResVelocSens_select->setValue(active_area->active_patch_patch.patch_tone[tn].resonance_veloc_sens*2 - 100);
    ToneTVF_CutoffFreq_select->setValue(active_area->active_patch_patch.patch_tone[tn].cutoff_freq);
    ToneTVF_Resonance_select->setValue(active_area->active_patch_patch.patch_tone[tn].resonance);
    ToneTVA_BiasPoint_select->setValue(active_area->active_patch_patch.patch_tone[tn].bias_point);
    ToneTVF_Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].F_ENV_depth-63);
    ToneTVA_Time1Sens_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].A_ENV_veloc_time_1_sens);
    ToneTVA_Time4Sens_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].A_ENV_veloc_time_4_sens);
    ToneTVA_VelocityCurve_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].A_ENV_veloc_curve);
    ToneTVA_TimeKeyfollow_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].A_ENV_time_keyfollow);
    ToneTVF_TimeKeyfollow_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].F_ENV_time_keyfollow);
    ToneTVA_BiasLvl_select->setCurrentIndex(14-active_area->active_patch_patch.patch_tone[tn].bias_level);
    ToneTVA_BiasDirection_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].bias_direction);
    ToneTVF_Time1Sens_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].F_ENV_veloc_time_1_sens);
    ToneTVF_Time4Sens_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].F_ENV_veloc_time_4_sens);
    ToneTVF_VelocityCurve_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].F_ENV_veloc_curve);
    ToneTVF_CutoffKeyfollow_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].cutoff_keyfollow);
    ToneTVF_FilterType_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].filter_type);
  }	// end if Patch_mode
  ToneTVF_enable(ToneTVF_FilterType_select->currentIndex()==0?false:true);
  on_ToneTVA_BiasDirection_select_currentIndexChanged(ToneTVA_BiasDirection_select->currentIndex());
}	// end setToneENVParms
