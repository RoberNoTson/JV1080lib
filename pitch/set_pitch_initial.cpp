// set_pitch_initial.cpp
#include        "JVlibForm.h"
#include        <QtGui>

void::JVlibForm::setPitchParms(int val) {
  // sets controls/displays so they match the synth, based on what is in the active area
  // passed a Perf part number, else 0 means we are in Patch mode
  
  QPen Pitch_blackLine(Qt::black, 0);
  Pitch_redLine.setColor(Qt::red);
  Pitch_dotLine.setStyle(Qt::DotLine);
  Pitch_dotLine.setColor(Qt::blue);
//  Pitch_Env_scene = new QGraphicsScene;
  Pitch_Env_scene->setSceneRect(0, 0, 425, 175);
  QLineF Pitch_Env_t4(384,0,384,0);
  QLineF Pitch_Env_offLine(374,90,374,90);
  QLineF Pitch_Env_t1Mark(50,20,50,150);
  QLineF Pitch_Env_t2Mark(50,20,50,150);
  QLineF Pitch_Env_t3Mark(50,20,50,150);
  QLineF Pitch_Env_t4Mark(375,20,374,150);
  Pitch_Env_scene->addLine(40, 90, 380, 90, Pitch_blackLine);     // X axis
  Pitch_Env_scene->addLine(40, 20, 40, 157, Pitch_blackLine);    // Y axis
  Pitch_Env_scene->addLine(50,20,50,158,Pitch_dotLine);   // Note-On line
  Pitch_Env_scene->addLine(Pitch_Env_offLine,Pitch_dotLine);
  Pitch_Env_scene->addSimpleText("Pitch")->setPos(3,55);
  Pitch_Env_scene->addSimpleText("+")->setPos(30,20);
  Pitch_Env_scene->addSimpleText("-")->setPos(30,140);
  Pitch_Env_scene->addSimpleText("Time")->setPos(386,85);
  Pitch_Env_scene->addSimpleText("Key-On")->setPos(48,160);
  Pitch_Env_OffText = Pitch_Env_scene->addSimpleText("Key-Off");
  Pitch_Env_OffText->setPos(372,160);
  Pitch_Env_ptrT1 = 0;
  Pitch_Env_ptrT2 = 0;
  Pitch_Env_ptrT3 = 0;
  Pitch_Env_ptrT4 = 0;
  Pitch_Env_t1Text = 0;
  Pitch_Env_t2Text = 0;
  Pitch_Env_t3Text = 0;
  Pitch_Env_t4Text = 0;
  Pitch_Env_sndText = 0;
  Pitch_Env_ptrSustain = 0;
  JVlibForm::Pitch_Env_display->setScene(Pitch_Env_scene);
  JVlibForm::Pitch_Env_display->show();

  state_table->updates_enabled = false;
  Pitch_Time1_select->setValue(1);
  Pitch_Time2_select->setValue(1);
  Pitch_Time3_select->setValue(1);
  Pitch_Time4_select->setValue(1);
//  int tn = (val?val-1:0);
  int tn = (Tone_ToneNumber_select->value()-1);
  if (val) {	// set Pitch for specified part number (val)
    int pn = val-1;
    Pitch_StretchTuning_select->setValue(active_area->active_perf_patch[pn].patch_common.stretch_tune_depth);
  Pitch_HighLimit_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].key_range_upper );
  Pitch_LowLimit_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].key_range_lower );
  Pitch_TimeKeyfollow_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].P_ENV_veloc_time_keyfollow);
  Pitch_RandPitchDepth_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].random_pitch_depth );
  Pitch_TuneAdj_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].fine_tune-50 );
  Pitch_Transpose_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].coarse_tune-48 );
  Pitch_Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].P_ENV_depth-12);
  Pitch_OctaveShift_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_common.octave_shift);
  Pitch_KeyFollow_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].pitch_keyfollow );
  // QDial
  Pitch_Time1_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].P_ENV_time[0]);
  Pitch_Time2_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].P_ENV_time[1]);
  Pitch_Time3_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].P_ENV_time[2]);
  Pitch_Time4_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].P_ENV_time[3]);
  Pitch_Lvl1_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].P_ENV_level[0]-63);
  Pitch_Lvl2_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].P_ENV_level[1]-63);
  Pitch_Lvl3_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].P_ENV_level[2]-63);
  Pitch_Lvl4_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].P_ENV_level[3]-63);
  Pitch_LFO1Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].pitch_LFO_1_depth-63);
  Pitch_LFO2Depth_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].pitch_LFO_2_depth-63);
  Pitch_VelocSens_select->setValue(active_area->active_perf_patch[pn].patch_tone[tn].P_ENV_veloc_sens*2 - 100);
  Pitch_Time1Sens_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].P_ENV_veloc_time1_sens);
  Pitch_Time4Sens_select->setCurrentIndex(active_area->active_perf_patch[pn].patch_tone[tn].P_ENV_veloc_time4_sens);

    // end Performance mode settings
  } else {
    // start Patch mode settings
    Pitch_StretchTuning_select->setValue(active_area->active_patch_patch.patch_common.stretch_tune_depth);
  Pitch_HighLimit_select->setValue(active_area->active_patch_patch.patch_tone[tn].key_range_upper );
  Pitch_LowLimit_select->setValue(active_area->active_patch_patch.patch_tone[tn].key_range_lower );
  Pitch_TimeKeyfollow_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].P_ENV_veloc_time_keyfollow);
  Pitch_RandPitchDepth_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].random_pitch_depth );
  Pitch_TuneAdj_select->setValue(active_area->active_patch_patch.patch_tone[tn].fine_tune-50 );
  Pitch_Transpose_select->setValue(active_area->active_patch_patch.patch_tone[tn].coarse_tune-48 );
  Pitch_Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].P_ENV_depth-12);
  Pitch_OctaveShift_select->setCurrentIndex(active_area->active_patch_patch.patch_common.octave_shift);
  Pitch_KeyFollow_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].pitch_keyfollow );
  Pitch_Time1_select->setValue(active_area->active_patch_patch.patch_tone[tn].P_ENV_time[0]);
  Pitch_Time2_select->setValue(active_area->active_patch_patch.patch_tone[tn].P_ENV_time[1]);
  Pitch_Time3_select->setValue(active_area->active_patch_patch.patch_tone[tn].P_ENV_time[2]);
  Pitch_Time4_select->setValue(active_area->active_patch_patch.patch_tone[tn].P_ENV_time[3]);
  Pitch_Lvl1_select->setValue(active_area->active_patch_patch.patch_tone[tn].P_ENV_level[0]-63);
  Pitch_Lvl2_select->setValue(active_area->active_patch_patch.patch_tone[tn].P_ENV_level[1]-63);
  Pitch_Lvl3_select->setValue(active_area->active_patch_patch.patch_tone[tn].P_ENV_level[2]-63);
  Pitch_Lvl4_select->setValue(active_area->active_patch_patch.patch_tone[tn].P_ENV_level[3]-63);
  Pitch_LFO1Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].pitch_LFO_1_depth-63);
  Pitch_LFO2Depth_select->setValue(active_area->active_patch_patch.patch_tone[tn].pitch_LFO_2_depth-63);
  Pitch_VelocSens_select->setValue(active_area->active_patch_patch.patch_tone[tn].P_ENV_veloc_sens*2 - 100);
  Pitch_Time1Sens_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].P_ENV_veloc_time1_sens);
  Pitch_Time4Sens_select->setCurrentIndex(active_area->active_patch_patch.patch_tone[tn].P_ENV_veloc_time4_sens);

  }
  Pitch_HighLimit_display->setText(funcNoteCalc(Pitch_HighLimit_select->value()));
  Pitch_LowLimit_display->setText(funcNoteCalc(Pitch_LowLimit_select->value()));
  Pitch_TuneAdj_display->display(Pitch_TuneAdj_select->value());
  Pitch_Transpose_display->display(Pitch_Transpose_select->value());
  if (state_table->updates_enabled) state_table->updates_enabled=false;
  on_Pitch_TimeKeyfollow_select_currentIndexChanged(Pitch_TimeKeyfollow_select->currentIndex());
  on_Pitch_KeyFollow_select_currentIndexChanged(Pitch_KeyFollow_select->currentIndex());
  
  state_table->updates_enabled = true;
}	// end setPitchParms
