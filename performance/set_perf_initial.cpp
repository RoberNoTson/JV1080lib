// set_initial.cpp
// for Performance tab

#include	"JVlibForm.h"
#include	<QtGui>
//#include	"performance.h"

void JVlibForm::setPerfParms() {
  // called after the Sync button is pushed to update displays/controls to reflect the synth configuration
  state_table->updates_enabled = false;
  // any changes to controls are automatically cascaded to the correct display
  PerfEFXtype_select->setCurrentIndex(active_area->active_performance.perf_common.EFX_type);
  PerfEFXsource_select->setCurrentIndex(active_area->active_performance.perf_common.EFX_source);
  PerfEFXoutput_select->setCurrentIndex(active_area->active_performance.perf_common.EFX_output);
  PerfEFXreverbSend_select->setValue(active_area->active_performance.perf_common.EFX_reverb_send_level);
  PerfEFXchorusSend_select->setValue(active_area->active_performance.perf_common.EFX_chorus_send_level);
  PerfEFXoutputLevel_select->setValue(active_area->active_performance.perf_common.EFX_output_level);
  PerfReverbType_select->setCurrentIndex(active_area->active_performance.perf_common.reverb_type);
  PerfReverbHiFreqDamp_select->setCurrentIndex(active_area->active_performance.perf_common.reverb_HF_damp);
  PerfReverbTime_select->setValue(active_area->active_performance.perf_common.reverb_time);
  if (PerfReverbType_select->currentIndex() > 5) {
    PerfReverbFeedback_select->setEnabled(true);
    PerfReverbFeedback_display->setEnabled(true);
  }
  PerfReverbFeedback_select->setValue(active_area->active_performance.perf_common.reverb_feedback);
  PerfReverbLevel_select->setValue(active_area->active_performance.perf_common.reverb_level);
  PerfChorusOutput_select->setCurrentIndex(active_area->active_performance.perf_common.chorus_output);
  PerfChorusLevel_select->setValue(active_area->active_performance.perf_common.chorus_level);
  PerfChorusRate_select->setValue(active_area->active_performance.perf_common.chorus_rate);
  PerfChorusDepth_select->setValue(active_area->active_performance.perf_common.chorus_depth);
  PerfChorusPreDelay_select->setValue(active_area->active_performance.perf_common.chorus_pre_delay);
  PerfChorusFeedback_select->setValue(active_area->active_performance.perf_common.chorus_feedback);
  PerfDefaultTempo_select->setValue((active_area->active_performance.perf_common.default_tempo_high*16)+active_area->active_performance.perf_common.default_tempo_low);
  PerfControlSource1_select->setCurrentIndex(active_area->active_performance.perf_common.EFX_control_src_1);
  PerfControlSource2_select->setCurrentIndex(active_area->active_performance.perf_common.EFX_control_src_2);
  PerfControl1Depth_select->setValue(active_area->active_performance.perf_common.EFX_control_depth_1-63);
  PerfControl2Depth_select->setValue(active_area->active_performance.perf_common.EFX_control_depth_2-63);
  // set Part group,number,name
  setPartsParms();
  // set EFX parms
  setPerfEFXparms();
  state_table->updates_enabled = true;
  MainTabWidget->setTabEnabled(2,true);
  MainTabWidget->setTabEnabled(3,true);
  MainTabWidget->setTabEnabled(4,true);
  EnableParts(true);
} // end setPerfParms

