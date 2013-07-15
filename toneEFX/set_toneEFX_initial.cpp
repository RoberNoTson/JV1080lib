// set_toneEFX_initial.cpp
// for ToneEFX Tab
#include        "JVlibForm.h"
#include        <QtGui>

void::JVlibForm::setToneEFXParms(int val) {
 int tn = Tone_ToneNumber_select->value()-1;
 if (state_table->perf_mode && val) {	// Performance mode patches
  int pn = val - 1;
  // set controls
  ToneEFX_LFO1Delay_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].LFO_1_delay_time);
  ToneEFX_LFO1Rate_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].LFO_1_rate);
  ToneEFX_LFO2Rate_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].LFO_2_rate);
  ToneEFX_LFO2Delay_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].LFO_2_delay_time);
  //  QCheckBox 
  ToneEFX_LFO1KeyTrigger_enable->setChecked(active_area->active_perf_patch[pn].patch_tone[tn].LFO_1_key_trigger);
  ToneEFX_LFO2KeyTrigger_enable->setChecked(active_area->active_perf_patch[pn].patch_tone[tn].LFO_2_key_trigger);
  // QSpinBox 
  ToneEFX_LFO1LevelOffset_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].LFO_1_level_offset);
  ToneEFX_LFO2LevelOffset_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].LFO_2_level_offset);
  // QComboBox
  ToneEFX_LF01Waveform_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].LFO_1_waveform);
  ToneEFX_LFO1FadeMode_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].LFO_1_fade_mode);
  ToneEFX_LFO1FadeTime_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].LFO_1_fade_time);
  ToneEFX_LFO2FadeTime_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].LFO_2_fade_time);
  ToneEFX_LFO1ExtSync_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].LFO_1_ext_sync);
  ToneEFX_LF02Waveform_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].LFO_2_waveform);
  ToneEFX_LFO2FadeMode_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].LFO_2_fade_mode);
  ToneEFX_LFO2ExtSync_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].LFO_2_ext_sync);
  ToneEFX_PanControl_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].pan_control);
  ToneEFX_Pan_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].tone_pan);
  ToneEFX_AltPan_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].alt_pan_depth);
  ToneEFX_PanLFO1Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].pan_LFO_1_depth-63);
  ToneEFX_PanLFO2Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].pan_LFO_2_depth-63);
  ToneEFX_PanRandDepth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].random_pan_depth);
  ToneEFX_PanKeyFollow_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].pan_keyfollow);
  
 } else {		// Patch mode patch 
  // QDial
  ToneEFX_LFO1Delay_select->setValue(active_area->active_patch_patch.patch_tone[tn].LFO_1_delay_time);
  ToneEFX_LFO1Rate_select->setValue(active_area->active_patch_patch.patch_tone[tn].LFO_1_rate);
  ToneEFX_LFO2Rate_select->setValue(active_area->active_patch_patch.patch_tone[tn].LFO_2_rate);
  ToneEFX_LFO2Delay_select->setValue(active_area->active_patch_patch.patch_tone[tn].LFO_2_delay_time);
  //  QCheckBox 
  ToneEFX_LFO1KeyTrigger_enable->setChecked(active_area->active_patch_patch.patch_tone[tn].LFO_1_key_trigger);
  ToneEFX_LFO2KeyTrigger_enable->setChecked(active_area->active_patch_patch.patch_tone[tn].LFO_2_key_trigger);
  // QSpinBox 
  ToneEFX_LFO1LevelOffset_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].LFO_1_level_offset);
  ToneEFX_LFO2LevelOffset_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].LFO_2_level_offset);
  // QComboBox
  ToneEFX_LF01Waveform_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].LFO_1_waveform);
  ToneEFX_LFO1FadeMode_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].LFO_1_fade_mode);
  ToneEFX_LFO1FadeTime_select->setValue(active_area->active_patch_patch.patch_tone[tn].LFO_1_fade_time);
  ToneEFX_LFO1ExtSync_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].LFO_1_ext_sync);
  ToneEFX_LF02Waveform_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].LFO_2_waveform);
  ToneEFX_LFO2FadeMode_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].LFO_2_fade_mode);
  ToneEFX_LFO2FadeTime_select->setValue(active_area->active_patch_patch.patch_tone[tn].LFO_2_fade_time);
  ToneEFX_LFO2ExtSync_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].LFO_2_ext_sync);
  ToneEFX_PanControl_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].pan_control );
  ToneEFX_Pan_select->setValue(active_area->active_patch_patch.patch_tone[tn].tone_pan );
  ToneEFX_AltPan_select->setValue(active_area->active_patch_patch.patch_tone[tn].alt_pan_depth);
  ToneEFX_PanLFO1Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].pan_LFO_1_depth-63);
  ToneEFX_PanLFO2Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].pan_LFO_2_depth-63);
  ToneEFX_PanRandDepth_select->setValue(active_area->active_patch_patch.patch_tone[tn].random_pan_depth);
  ToneEFX_PanKeyFollow_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].pan_keyfollow);
 }	// end IF...ELSE patch

  if (state_table->updates_enabled) state_table->updates_enabled=false;
  on_ToneEFX_PanKeyFollow_select_currentIndexChanged(ToneEFX_PanKeyFollow_select->currentIndex());
  on_ToneEFX_Pan_select_valueChanged(ToneEFX_Pan_select->value());
  on_ToneEFX_AltPan_select_valueChanged(ToneEFX_AltPan_select->value());
}	// end setToneEFXParms
