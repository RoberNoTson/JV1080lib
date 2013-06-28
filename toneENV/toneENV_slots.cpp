// // toneENV_slots.cpp
#include        "JVlibForm.h"
#include        <QtGui>

QPen ToneEnv_dotLine(Qt::DotLine);
QPen ToneEnv_redLine(Qt::red, 0);

void JVlibForm::ToneENVStdUpdate(int offset, int val) {
  if (state_table->updates_enabled) {
    char *ptr;
    int tn = Tone_ToneNumber_select->value() - 1;
    if (state_table->perf_mode)
      ptr = &active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_tone[tn].wave_group;
    else
      ptr = &active_area->active_patch_patch.patch_tone[tn].wave_group;
    ptr[offset-1] = val;
    if (state_table->jv_connect) 
      setToneSingleValue(tn,offset, val);
  }     // end state_table->updates_enabled
}       // end ToneENVStdUpdate

void JVlibForm::on_ToneTVF_TestTone_switch_toggled(bool val) {
  if (state_table->jv_connect) {
  unsigned char buf[6];
  int pn = state_table->perf_mode ? (Patch_PerfPartNum_select->currentIndex()) : 0;
  if (val) {
    buf[0] = 0x90 + (state_table->perf_mode ? active_area->active_performance.perf_part[pn].MIDI_channel : 
      system_area->sys_common.patch_receive_channel);
    buf[1] = SysPreviewNote1_select->value();
    buf[2] = SysPreviewNote1_volume->value();
    if (open_ports() == EXIT_FAILURE) return;
    if (change_send(buf,3) == EXIT_FAILURE) { close_ports(); return; }
    close_ports();
  } else {
    buf[0] = 0xB0 + (state_table->perf_mode ? active_area->active_performance.perf_part[pn].MIDI_channel : 
      system_area->sys_common.patch_receive_channel);
    buf[1] = 0x7B;
    buf[2] = 0;
    buf[3] = 0xB0 + (state_table->perf_mode ? active_area->active_performance.perf_part[pn].MIDI_channel : 
      system_area->sys_common.patch_receive_channel);
    buf[4] = 0x79;
    buf[5] = 0;
  if (open_ports() == EXIT_FAILURE) return;
  if (change_send(buf,6) == EXIT_FAILURE) { close_ports(); return; }
  close_ports();
  }
  ToneTVF_TestTone_switch->setText(val ? QString::fromUtf8("Stop") : QString::fromUtf8("Play Patch") );
  }
}	// end on_ToneTVF_TestTone_switch_toggled

void JVlibForm::on_ToneTVA_TestTone_switch_toggled(bool val) {
  if (state_table->jv_connect) {
  unsigned char buf[6];
  int pn = state_table->perf_mode ? (Patch_PerfPartNum_select->currentIndex()) : 0;
  if (val) {
    buf[0] = 0x90 + (state_table->perf_mode ? active_area->active_performance.perf_part[pn].MIDI_channel : 
      system_area->sys_common.patch_receive_channel);
    buf[1] = SysPreviewNote1_select->value();
    buf[2] = SysPreviewNote1_volume->value();
    if (open_ports() == EXIT_FAILURE) return;
    if (change_send(buf,3) == EXIT_FAILURE) { close_ports(); return; }
    close_ports();
  } else {
    buf[0] = 0xB0 + (state_table->perf_mode ? active_area->active_performance.perf_part[pn].MIDI_channel : 
      system_area->sys_common.patch_receive_channel);
    buf[1] = 0x7B;
    buf[2] = 0;
    buf[3] = 0xB0 + (state_table->perf_mode ? active_area->active_performance.perf_part[pn].MIDI_channel : 
      system_area->sys_common.patch_receive_channel);
    buf[4] = 0x79;
    buf[5] = 0;
  if (open_ports() == EXIT_FAILURE) return;
  if (change_send(buf,6) == EXIT_FAILURE) { close_ports(); return; }
  close_ports();
  }
  ToneTVA_TestTone_switch->setText(val ? QString::fromUtf8("Stop") : QString::fromUtf8("Play Patch") );
  }
}	// end on_ToneTVA_TestTone_switch_toggled

void JVlibForm::on_ToneTVF_FilterType_select_currentIndexChanged(int val) {
  switch(val) {
    case 0:
      ToneTVF_enable(false);
      ToneTVF_FilterType_select->setToolTip("Select a Filter Type");
      ToneTVF_CutoffFreq_select->setToolTip("Filter Type is Off, cutoff frequency is not used");
      ToneTVF_CutoffKeyfollow_select->setToolTip("Filter Type is Off, Cutoff Key Follow control has no effect");
      ToneTVF_Resonance_select->setToolTip("Filter Type is Off, Resonance control has no effect");
      ToneTVF_ResVelocSens_select->setToolTip("Filter Type is Off, Resonance velocity sensitivity control has no effect");
      ToneTVF_Depth_select->setToolTip("Filter Type is Off, Depth control has no effect");
      ToneTVF_VelocityCurve_select->setToolTip("Filter Type is Off, Velocity Curve selection has no effect");
      break;
    case 1:
      ToneTVF_enable(true);
      ToneTVF_FilterType_select->setToolTip("Low-pass Filter: Components higher than the cutoff freq are eliminated, making the sound \"rounder\". This is the most often used filter.");
      ToneTVF_CutoffFreq_select->setToolTip("Filter Type is LPF, remove sounds above the cutoff freq.");
      ToneTVF_CutoffKeyfollow_select->setToolTip("Changes the cutoff freq based on the keyboard key played. 0 sets Middle C as the reference key.");
      ToneTVF_Resonance_select->setToolTip("Resonance works with the Filter Type to increase the tone velocity around the cutoff freq");
      ToneTVF_ResVelocSens_select->setToolTip("Adjust the amount of Resonance applied according to the velocity.");
      ToneTVF_Depth_select->setToolTip("Adjust the extent of the effectiveness of the TVF envelope.");
      ToneTVF_VelocityCurve_select->setToolTip("Choose the curve used when changing the Cutoff Freq with Velocity.");
      break;
    case 2:
      ToneTVF_enable(true);
      ToneTVF_FilterType_select->setToolTip("Bandpass Filter: Only components near the cutoff freq remain - all others are eliminated. Produces highly distinctive sounds.");
      ToneTVF_CutoffFreq_select->setToolTip("Filter Type is HPF, remove sounds below the cutoff freq.");
      ToneTVF_CutoffKeyfollow_select->setToolTip("Changes the cutoff freq based on the keyboard key played. 0 sets Middle C as the reference key.");
      ToneTVF_Resonance_select->setToolTip("Resonance works with the Filter Type to increase the tone velocity around the cutoff freq");
      ToneTVF_ResVelocSens_select->setToolTip("Adjust the amount of Resonance applied according to the velocity.");
      ToneTVF_Depth_select->setToolTip("Adjust the extent of the effectiveness of the TVF envelope.");
      ToneTVF_VelocityCurve_select->setToolTip("Choose the curve used when changing the Cutoff Freq with Velocity.");
      break;
    case 3:
      ToneTVF_enable(true);
      ToneTVF_FilterType_select->setToolTip("High-pass Filter: Components below the cutoff freq are eliminated. Usefule for making percussion instruments with distinctive high ranges.");
      ToneTVF_CutoffFreq_select->setToolTip("Filter Type is BPF, remove sounds farther from the cutoff freq.");
      ToneTVF_CutoffKeyfollow_select->setToolTip("Changes the cutoff freq based on the keyboard key played. 0 sets Middle C as the reference key.");
      ToneTVF_Resonance_select->setToolTip("Resonance works with the Filter Type to increase the tone velocity around the cutoff freq");
      ToneTVF_ResVelocSens_select->setToolTip("Adjust the amount of Resonance applied according to the velocity.");
      ToneTVF_Depth_select->setToolTip("Adjust the extent of the effectiveness of the TVF envelope.");
      ToneTVF_VelocityCurve_select->setToolTip("Choose the curve used when changing the Cutoff Freq with Velocity.");
      break;
    case 4:
      ToneTVF_enable(true);
      ToneTVF_FilterType_select->setToolTip("Peaking Filter: Emphasize components near the cutoff freq. Useful for expressing drum sounds or creating a \"wow\" effect.");
      ToneTVF_CutoffFreq_select->setToolTip("Filter Type is PKF, emphasize sounds closer to the cutoff freq.");
      ToneTVF_CutoffKeyfollow_select->setToolTip("Changes the cutoff freq based on the keyboard key played. 0 sets Middle C as the reference key.");
      ToneTVF_Resonance_select->setToolTip("Resonance works with the Filter Type to increase the tone velocity around the cutoff freq");
      ToneTVF_ResVelocSens_select->setToolTip("Adjust the amount of Resonance applied according to the velocity.");
      ToneTVF_Depth_select->setToolTip("Adjust the extent of the effectiveness of the TVF envelope.");
      ToneTVF_VelocityCurve_select->setToolTip("Choose the curve used when changing the Cutoff Freq with Velocity.");
      break;    
  }	// end Switch
  ToneENVStdUpdate(0x50, val);
}

void JVlibForm::on_ToneTVF_CutoffFreq_select_valueChanged(int val) {
  ToneENVStdUpdate(0x51, val);
}	// end on_ToneTVF_CutoffFreq_select_valueChanged

void JVlibForm::on_ToneTVF_CutoffKeyfollow_select_currentIndexChanged(int val) {
  QPixmap modepic;
  switch(val) {
    case 0:
      modepic.load(":/res/keyfollow_d100.png");
      break;
    case 1:
      modepic.load(":/res/keyfollow_d70.png");
      break;
    case 2:
      modepic.load(":/res/keyfollow_d50.png");
      break;
    case 3:
      modepic.load(":/res/keyfollow_d30.png");
      break;
    case 4:
      modepic.load(":/res/keyfollow_d10.png");
      break;
    case 5:
      modepic.load(":/res/keyfollow_0.png");
      break;
    case 6:
      modepic.load(":/res/keyfollow_u10.png");
      break;
    case 7:
      modepic.load(":/res/keyfollow_u20.png");
      break;
    case 8:
      modepic.load(":/res/keyfollow_u30.png");
      break;
    case 9:
      modepic.load(":/res/keyfollow_u40.png");
      break;
    case 10:
      modepic.load(":/res/keyfollow_u50.png");
      break;
    case 11:
      modepic.load(":/res/keyfollow_u70.png");
      break;
    case 12:
      modepic.load(":/res/keyfollow_u100.png");
      break;
    case 13:
      modepic.load(":/res/keyfollow_u120.png");
      break;
    case 14:
      modepic.load(":/res/keyfollow_u150.png");
      break;
    case 15:
      modepic.load(":/res/keyfollow_u200.png");
      break;
    default:
      modepic.load(":/res/keyfollow_0.png");
      break;
  }	// end Switch
  ToneENV_CutoffKeyfollow_pixmap->setPixmap(modepic);
  ToneENVStdUpdate(0x52, val);
}
void JVlibForm::on_ToneTVF_Resonance_select_valueChanged(int val) {
  // increases velocity of tones nearer the cutoff freq
  ToneENVStdUpdate(0x53, val);   
}
void JVlibForm::on_ToneTVF_ResVelocSens_select_valueChanged(int val) {
  ToneENVStdUpdate(0x54, (val+100)/2);
}
void JVlibForm::on_ToneTVF_Depth_select_valueChanged(int val) {
  ToneTVF_Env_display->resetTransform();
  if (val) {
    qreal dy = (64-fabs(val/2))/64;
    ToneTVF_Env_display->scale(1,dy);
  }
  on_ToneTVF_Lvl1_select_valueChanged(ToneTVF_Lvl1_select->value());
  ToneENVStdUpdate(0x55, val+63);
}
void JVlibForm::on_ToneTVF_VelocityCurve_select_currentIndexChanged(int val) {
  ToneENVStdUpdate(0x56, val);
}
void JVlibForm::on_ToneTVF_VelocSens_select_valueChanged(int val) {
  ToneENVStdUpdate(0x57, (val+100)/2);
}
void JVlibForm::on_ToneTVF_Time1Sens_select_currentIndexChanged(int val) {
  ToneENVStdUpdate(0x58, val);
}
void JVlibForm::on_ToneTVF_Time4Sens_select_currentIndexChanged(int val) {
  ToneENVStdUpdate(0x59, val);
}
void JVlibForm::on_ToneTVF_TimeKeyfollow_select_currentIndexChanged(int val) {
  QPixmap modepic;
  switch(val) {
    case 0:
      modepic.load(":/res/keyfollow_d100.png");
      break;
    case 1:
      modepic.load(":/res/keyfollow_d70.png");
      break;
    case 2:
      modepic.load(":/res/keyfollow_d50.png");
      break;
    case 3:
      modepic.load(":/res/keyfollow_d40.png");
      break;
    case 4:
      modepic.load(":/res/keyfollow_d30.png");
      break;
    case 5:
      modepic.load(":/res/keyfollow_d20.png");
      break;
    case 6:
      modepic.load(":/res/keyfollow_d10.png");
      break;
    case 7:
      modepic.load(":/res/keyfollow_0.png");
      break;
    case 8:
      modepic.load(":/res/keyfollow_u10.png");
      break;
    case 9:
      modepic.load(":/res/keyfollow_u20.png");
      break;
    case 10:
      modepic.load(":/res/keyfollow_u30.png");
      break;
    case 11:
      modepic.load(":/res/keyfollow_u40.png");
      break;
    case 12:
      modepic.load(":/res/keyfollow_u50.png");
      break;
    case 13:
      modepic.load(":/res/keyfollow_u70.png");
      break;
    case 14:
      modepic.load(":/res/keyfollow_u100.png");
      break;
    case 15:
      modepic.load(":/res/keyfollow_u120.png");
      break;
    case 16:
      modepic.load(":/res/keyfollow_u150.png");
      break;
    case 17:
      modepic.load(":/res/keyfollow_u200.png");
      break;
  }	// end Switch
  ToneENV_TimeKeyfollow_pixmap->setPixmap(modepic);
  ToneENVStdUpdate(0x5A, val);
}

void JVlibForm::on_ToneTVF_Time1_select_valueChanged(int val) {
  static QGraphicsLineItem *ptrT1Mark;
  qreal oldY = ToneTVF_Env_ptrT1?ToneTVF_Env_t1.y2():90;
  if (ptrT1Mark) {
      ToneTVF_Env_scene->removeItem(ptrT1Mark);
      ptrT1Mark=0;
  }
  if (ToneTVF_Env_t1Text) {
      ToneTVF_Env_scene->removeItem(ToneTVF_Env_t1Text);
      ToneTVF_Env_t1Text=0;
  }
  if (ToneTVF_Env_ptrT1) {
      ToneTVF_Env_scene->removeItem(ToneTVF_Env_ptrT1);
      ToneTVF_Env_ptrT1=0;
  }
  ToneTVF_Env_t1.setLine(50,90,val/2+50,oldY);
  ToneTVF_Env_ptrT1 = ToneTVF_Env_scene->addLine(ToneTVF_Env_t1,ToneEnv_redLine);
  if (val>0) {
    ToneTVF_Env_t1Mark.setLine(ToneTVF_Env_t1.x2(),20,ToneTVF_Env_t1.x2(),157);
    ptrT1Mark = ToneTVF_Env_scene->addLine(ToneTVF_Env_t1Mark,ToneEnv_dotLine);
    ToneTVF_Env_t1Text = ToneTVF_Env_scene->addSimpleText("T1");
    ToneTVF_Env_t1Text->setPos((ToneTVF_Env_t1.x2()+ToneTVF_Env_t1.x1())/2-5,ToneTVF_Env_t1.y2()-20);
  }
  if (state_table->updates_enabled == true) {
    state_table->updates_enabled = false;
    on_ToneTVF_Time2_select_valueChanged(ToneTVF_Time2_select->value());
    state_table->updates_enabled = true;
  } else {
    on_ToneTVF_Time2_select_valueChanged(ToneTVF_Time2_select->value());
  }
  ToneENVStdUpdate(0x5B, val);
}
void JVlibForm::on_ToneTVF_Time2_select_valueChanged(int val) {
    static QGraphicsLineItem *ptrT2Mark;
    qreal oldY2 = ToneTVF_Env_ptrT2?ToneTVF_Env_t2.y2():90;
    if (ptrT2Mark) {
        ToneTVF_Env_scene->removeItem(ptrT2Mark);
        ptrT2Mark=0;
    }
    if (ToneTVF_Env_ptrT2) {
        ToneTVF_Env_scene->removeItem(ToneTVF_Env_ptrT2);
        ToneTVF_Env_ptrT2=0;
    }
    if (ToneTVF_Env_t2Text) {
        ToneTVF_Env_scene->removeItem(ToneTVF_Env_t2Text);
        ToneTVF_Env_t2Text=0;
    }
    ToneTVF_Env_t2.setLine(ToneTVF_Env_t1.x2(),ToneTVF_Env_t1.y2(),ToneTVF_Env_t1.x2()+val/2,oldY2);
    ToneTVF_Env_t2Mark.setLine(ToneTVF_Env_t2.x2(),20,ToneTVF_Env_t2.x2(),157);
    ToneTVF_Env_ptrT2 = ToneTVF_Env_scene->addLine(ToneTVF_Env_t2,ToneEnv_redLine);
    if (val>0) {
        ptrT2Mark = ToneTVF_Env_scene->addLine(ToneTVF_Env_t2Mark,ToneEnv_dotLine);
        ToneTVF_Env_t2Text = ToneTVF_Env_scene->addSimpleText("T2");
    }
  if (ToneTVF_Env_t2Text) ToneTVF_Env_t2Text->setPos((ToneTVF_Env_t2.x2()+ToneTVF_Env_t2.x1())/2-5, ToneTVF_Env_t2.y1()<ToneTVF_Env_t2.y2()?ToneTVF_Env_t2.y1()-20:ToneTVF_Env_t2.y2()-20);
  if (state_table->updates_enabled == true) {
    state_table->updates_enabled = false;
    on_ToneTVF_Time3_select_valueChanged(ToneTVF_Time3_select->value());
    state_table->updates_enabled = true;
  } else {
    on_ToneTVF_Time3_select_valueChanged(ToneTVF_Time3_select->value());
  }
  ToneENVStdUpdate(0x5C, val);
}
void JVlibForm::on_ToneTVF_Time3_select_valueChanged(int val) {
    static QGraphicsLineItem *ptrT3Mark;
    qreal oldY2 = ToneTVF_Env_ptrT3?ToneTVF_Env_t3.y2():90;
    if (ptrT3Mark) {
        ToneTVF_Env_scene->removeItem(ptrT3Mark);
        ptrT3Mark=0;
    }
    if (ToneTVF_Env_t3Text) {
        ToneTVF_Env_scene->removeItem(ToneTVF_Env_t3Text);
        ToneTVF_Env_t3Text=0;
    }
    if (ToneTVF_Env_ptrT3) {
        ToneTVF_Env_scene->removeItem(ToneTVF_Env_ptrT3);
        ToneTVF_Env_ptrT3=0;
    }
    ToneTVF_Env_t3.setLine(ToneTVF_Env_t2.x2(),ToneTVF_Env_t2.y2(),ToneTVF_Env_t2.x2()+val/2,oldY2);
    ToneTVF_Env_t3Mark.setLine(ToneTVF_Env_t3.x2(),20,ToneTVF_Env_t3.x2(),157);
    if (val>0) {
        ToneTVF_Env_ptrT3 = ToneTVF_Env_scene->addLine(ToneTVF_Env_t3,ToneEnv_redLine);
        ptrT3Mark = ToneTVF_Env_scene->addLine(ToneTVF_Env_t3Mark,ToneEnv_dotLine);
        ToneTVF_Env_t3Text = ToneTVF_Env_scene->addSimpleText("T3");
    }
    if (ToneTVF_Env_t3Text) ToneTVF_Env_t3Text->setPos((ToneTVF_Env_t3.x2()+ToneTVF_Env_t3.x1())/2-5,ToneTVF_Env_t3.y1()<ToneTVF_Env_t3.y2()?ToneTVF_Env_t3.y1()-20:ToneTVF_Env_t3.y2()-20);
  if (state_table->updates_enabled == true) {
    state_table->updates_enabled = false;
    on_ToneTVF_Time4_select_valueChanged(ToneTVF_Time4_select->value());
    state_table->updates_enabled = true;
  } else {
    on_ToneTVF_Time4_select_valueChanged(ToneTVF_Time4_select->value());
  }
  ToneENVStdUpdate(0x5D, val);
}
void JVlibForm::on_ToneTVF_Time4_select_valueChanged(int val) {
  static QGraphicsLineItem *ptrT4Mark;
  static QGraphicsLineItem *ptrOffLine;

  if (ptrT4Mark) {
      ToneTVF_Env_scene->removeItem(ptrT4Mark);
      ptrT4Mark=0;
  }
  if (ptrOffLine) {
      ToneTVF_Env_scene->removeItem(ptrOffLine);
      ptrOffLine=0;
  }
  if (ToneTVF_Env_sndText) {
      ToneTVF_Env_scene->removeItem(ToneTVF_Env_sndText);
      ToneTVF_Env_sndText=0;
  }
  if (ToneTVF_Env_ptrSustain) {
      ToneTVF_Env_scene->removeItem(ToneTVF_Env_ptrSustain);
      ToneTVF_Env_ptrSustain=0;
  }
  if (ToneTVF_Env_ptrT4) {
      ToneTVF_Env_scene->removeItem(ToneTVF_Env_ptrT4);
      ToneTVF_Env_ptrT4=0;
  }
  if (ToneTVF_Env_t4Text) {
      ToneTVF_Env_scene->removeItem(ToneTVF_Env_t4Text);
      ToneTVF_Env_t4Text=0;
  }
  ToneTVF_Env_sustain.setLine(ToneTVF_Env_t3.x2(), ToneTVF_Env_t3.y2(), 384-(val/2), ToneTVF_Env_t3.y2());
  ToneTVF_Env_ptrSustain = ToneTVF_Env_scene->addLine(ToneTVF_Env_sustain,ToneEnv_redLine);
  if (ToneTVF_Lvl3_select->value()) {
    ToneTVF_Env_sndText = ToneTVF_Env_scene->addSimpleText("(sounding)");
    ToneTVF_Env_sndText->setPos((ToneTVF_Env_sustain.x1()+ToneTVF_Env_sustain.x2())/2-35, ToneTVF_Env_sustain.y1()-20);
  }
  ToneTVF_Env_t4.setLine(ToneTVF_Env_sustain.x2(),ToneTVF_Env_sustain.y2(), 384, -(ToneTVF_Lvl4_select->value()/2+90));
  ToneTVF_Env_offLine.setLine(ToneTVF_Env_t4.x1(),20,ToneTVF_Env_t4.x1(),157);
  ToneTVF_Env_t4Mark.setLine(ToneTVF_Env_t4.x2(),20,ToneTVF_Env_t4.x2(),157);
  ptrOffLine = ToneTVF_Env_scene->addLine(ToneTVF_Env_offLine,ToneEnv_dotLine);
  ToneTVF_Env_OffText->setPos(ToneTVF_Env_t4.x1()-3,160);
  if (val>0) {
      ToneTVF_Env_ptrT4 = ToneTVF_Env_scene->addLine(ToneTVF_Env_t4,ToneEnv_redLine);
      ptrT4Mark = ToneTVF_Env_scene->addLine(ToneTVF_Env_t4Mark,ToneEnv_dotLine);
      ToneTVF_Env_t4Text = ToneTVF_Env_scene->addSimpleText("T4");
      ToneTVF_Env_t4Text->setPos((ToneTVF_Env_t4.x2()+ToneTVF_Env_t4.x1())/2-5,ToneTVF_Env_t4.y1()<ToneTVF_Env_t4.y2()?ToneTVF_Env_t4.y1()-20:ToneTVF_Env_t4.y2()-20);
  }
  ToneENVStdUpdate(0x5E, val);
}
void JVlibForm::on_ToneTVF_Lvl1_select_valueChanged(int val) {
  qreal oldX = ToneTVF_Env_ptrT1?ToneTVF_Env_t1.x2():50;
  if (ToneTVF_Env_ptrT1) {
      ToneTVF_Env_scene->removeItem(ToneTVF_Env_ptrT1);
      ToneTVF_Env_ptrT1=0;
  }
  val += fabs(ToneTVF_Depth_select->value());
  ToneTVF_Env_t1.setLine(50,90,oldX, ToneTVF_Depth_select->value()>=0?90-val/2:90+val/2);
  ToneTVF_Env_ptrT1 = ToneTVF_Env_scene->addLine(ToneTVF_Env_t1,ToneEnv_redLine);
  if (ToneTVF_Env_t1Text) ToneTVF_Env_t1Text->setPos((ToneTVF_Env_t1.x2()+ToneTVF_Env_t1.x1())/2-5,ToneTVF_Env_t1.y2()-20);
  if (state_table->updates_enabled == true) {
    state_table->updates_enabled = false;
    on_ToneTVF_Lvl2_select_valueChanged(ToneTVF_Lvl2_select->value());
    state_table->updates_enabled = true;
  } else {
    on_ToneTVF_Lvl2_select_valueChanged(ToneTVF_Lvl2_select->value());
  }
  ToneENVStdUpdate(0x5F, val);
}
void JVlibForm::on_ToneTVF_Lvl2_select_valueChanged(int val) {
    qreal oldX = ToneTVF_Env_t2.x2();
    if (ToneTVF_Env_ptrT2) {
        ToneTVF_Env_scene->removeItem(ToneTVF_Env_ptrT2);
        ToneTVF_Env_ptrT2=0;
    }
  val += fabs(ToneTVF_Depth_select->value());
  ToneTVF_Env_t2.setLine(ToneTVF_Env_t1.x2(),ToneTVF_Env_t1.y2(),oldX, ToneTVF_Depth_select->value()>=0?90-val/2:90+val/2);
  ToneTVF_Env_ptrT2 = ToneTVF_Env_scene->addLine(ToneTVF_Env_t2,ToneEnv_redLine);
  if (ToneTVF_Env_t2Text) ToneTVF_Env_t2Text->setPos((ToneTVF_Env_t2.x2()+ToneTVF_Env_t2.x1())/2-5, ToneTVF_Env_t2.y1()<ToneTVF_Env_t2.y2()?ToneTVF_Env_t2.y1()-20:ToneTVF_Env_t2.y2()-20);
  if (state_table->updates_enabled == true) {
    state_table->updates_enabled = false;
    on_ToneTVF_Lvl3_select_valueChanged(ToneTVF_Lvl3_select->value());
    state_table->updates_enabled = true;
  } else {
    on_ToneTVF_Lvl3_select_valueChanged(ToneTVF_Lvl3_select->value());
  }
  ToneENVStdUpdate(0x60, val);
}
void JVlibForm::on_ToneTVF_Lvl3_select_valueChanged(int val) {
    qreal oldX = ToneTVF_Env_t3.x2();
    if (ToneTVF_Env_ptrT3) {
        ToneTVF_Env_scene->removeItem(ToneTVF_Env_ptrT3);
        ToneTVF_Env_ptrT3=0;
    }
  val += fabs(ToneTVF_Depth_select->value());
  ToneTVF_Env_t3.setLine(ToneTVF_Env_t2.x2(),ToneTVF_Env_t2.y2(),oldX,ToneTVF_Depth_select->value()>=0?90-val/2:90+val/2);
  ToneTVF_Env_ptrT3 = ToneTVF_Env_scene->addLine(ToneTVF_Env_t3,ToneEnv_redLine);
  if (ToneTVF_Env_t3Text) ToneTVF_Env_t3Text->setPos((ToneTVF_Env_t3.x2()+ToneTVF_Env_t3.x1())/2-5, ToneTVF_Env_t3.y1()<ToneTVF_Env_t3.y2()?ToneTVF_Env_t3.y1()-20:ToneTVF_Env_t3.y2()-20);
  if (state_table->updates_enabled == true) {
    state_table->updates_enabled = false;
    on_ToneTVF_Lvl4_select_valueChanged(ToneTVF_Lvl4_select->value());
    state_table->updates_enabled = true;
  } else {
    on_ToneTVF_Lvl4_select_valueChanged(ToneTVF_Lvl4_select->value());
  }
  ToneENVStdUpdate(0x61, val);
}
void JVlibForm::on_ToneTVF_Lvl4_select_valueChanged(int val) {
  if (ToneTVF_Env_ptrSustain) {
      ToneTVF_Env_scene->removeItem(ToneTVF_Env_ptrSustain);
      ToneTVF_Env_ptrSustain=0;
  }
  if (ToneTVF_Env_sndText) {
      ToneTVF_Env_scene->removeItem(ToneTVF_Env_sndText);
      ToneTVF_Env_sndText=0;
  }
  if (ToneTVF_Env_ptrT4) {
      ToneTVF_Env_scene->removeItem(ToneTVF_Env_ptrT4);
      ToneTVF_Env_ptrT4=0;
  }
  ToneTVF_Env_sustain.setLine(ToneTVF_Env_t3.x2(), ToneTVF_Env_t3.y2(), ToneTVF_Env_t4.x1(), ToneTVF_Env_t3.y2());
  ToneTVF_Env_ptrSustain = ToneTVF_Env_scene->addLine(ToneTVF_Env_sustain,ToneEnv_redLine);
  if (ToneTVF_Lvl3_select->value()) {
    ToneTVF_Env_sndText = ToneTVF_Env_scene->addSimpleText("(sounding)");
    ToneTVF_Env_sndText->setPos((ToneTVF_Env_sustain.x1()+ToneTVF_Env_sustain.x2())/2-35, ToneTVF_Env_sustain.y1()-20);
  }
  ToneTVF_Env_t4.setLine(ToneTVF_Env_sustain.x2(),ToneTVF_Env_sustain.y2(),384,ToneTVF_Depth_select->value()>=0?90-val/2:90+val/2);
  ToneTVF_Env_ptrT4 = ToneTVF_Env_scene->addLine(ToneTVF_Env_t4,ToneEnv_redLine);
  if (ToneTVF_Env_t4Text) ToneTVF_Env_t4Text->setPos((ToneTVF_Env_t4.x2()+ToneTVF_Env_t4.x1())/2-5, ToneTVF_Env_t4.y1()<ToneTVF_Env_t4.y2()?ToneTVF_Env_t4.y1()-20:ToneTVF_Env_t4.y2()-20);    
  ToneENVStdUpdate(0x62, val);
}
void JVlibForm::on_ToneTVF_LFO1Depth_select_valueChanged(int val) {
  ToneENVStdUpdate(0x63, val+63);
}
void JVlibForm::on_ToneTVF_LFO2Depth_select_valueChanged(int val) {
  ToneENVStdUpdate(0x64, val+63);
}
void JVlibForm::on_ToneTVA_BiasDirection_select_currentIndexChanged(int val) {
  on_ToneTVA_BiasLvl_select_currentIndexChanged(ToneTVA_BiasLvl_select->currentText());
  ToneENVStdUpdate(0x66, val);
}
void JVlibForm::on_ToneTVA_BiasPoint_select_valueChanged(int val) {
  if (ToneTVA_Bias_ptrbpMark) {
      ToneTVA_Bias_scene->removeItem(ToneTVA_Bias_ptrbpMark);
      ToneTVA_Bias_ptrbpMark = 0;
  }
  if (ToneTVA_Bias_bpText) {
      ToneTVA_Bias_scene->removeItem(ToneTVA_Bias_bpText);
      ToneTVA_Bias_bpText = 0;
  }
  ToneTVA_Bias_bpMark.setLine((val*2)+40,10,(val*2)+40,115);
  ToneTVA_Bias_ptrbpMark = ToneTVA_Bias_scene->addLine(ToneTVA_Bias_bpMark,ToneEnv_dotLine);
  ToneTVA_Bias_bpText = ToneTVA_Bias_scene->addSimpleText(funcNoteCalc(val));
  ToneTVA_Bias_bpText->setPos(ToneTVA_Bias_bpMark.x1()-5, 120);
  on_ToneTVA_BiasLvl_select_currentIndexChanged(ToneTVA_BiasLvl_select->currentText());
  ToneENVStdUpdate(0x67, val);
}
void JVlibForm::on_ToneTVA_BiasLvl_select_currentIndexChanged(QString val) {
    if (ToneTVA_Bias_ptrHiLine) {
        ToneTVA_Bias_scene->removeItem(ToneTVA_Bias_ptrHiLine);
        ToneTVA_Bias_ptrHiLine = 0;
    }
    if (ToneTVA_Bias_ptrLowLine) {
        ToneTVA_Bias_scene->removeItem(ToneTVA_Bias_ptrLowLine);
        ToneTVA_Bias_ptrLowLine = 0;
    }
    switch(ToneTVA_BiasDirection_select->currentIndex()) {
    case 0:     // Lower
        ToneTVA_Bias_LowLine.setLine(40, 65-(val.toInt()*.5), ToneTVA_Bias_bpMark.x1(),65);
        ToneTVA_Bias_ptrLowLine = ToneTVA_Bias_scene->addLine(ToneTVA_Bias_LowLine,ToneEnv_redLine);
        ToneTVA_Bias_HiLine.setLine(ToneTVA_Bias_bpMark.x1(),65,295,65);
        ToneTVA_Bias_ptrHiLine = ToneTVA_Bias_scene->addLine(ToneTVA_Bias_HiLine,ToneEnv_redLine);
        break;
    case 1:     // Upper
        ToneTVA_Bias_HiLine.setLine(ToneTVA_Bias_bpMark.x1(),65,295,65-(val.toInt()*.5));
        ToneTVA_Bias_ptrHiLine = ToneTVA_Bias_scene->addLine(ToneTVA_Bias_HiLine,ToneEnv_redLine);
        ToneTVA_Bias_LowLine.setLine(40, 65, ToneTVA_Bias_bpMark.x1(),65);
        ToneTVA_Bias_ptrLowLine = ToneTVA_Bias_scene->addLine(ToneTVA_Bias_LowLine,ToneEnv_redLine);
        break;
    case 2:     // Upper&Lower
        ToneTVA_Bias_LowLine.setLine(40, 65-(val.toInt()*.5), ToneTVA_Bias_bpMark.x1(),65);
        ToneTVA_Bias_ptrLowLine = ToneTVA_Bias_scene->addLine(ToneTVA_Bias_LowLine,ToneEnv_redLine);
        ToneTVA_Bias_HiLine.setLine(ToneTVA_Bias_bpMark.x1(),65,295,65-(val.toInt()*.5));
        ToneTVA_Bias_ptrHiLine = ToneTVA_Bias_scene->addLine(ToneTVA_Bias_HiLine,ToneEnv_redLine);
        break;
    case 3:     // All
        ToneTVA_Bias_HiLine.setLine(ToneTVA_Bias_bpMark.x1(),65,295,65-(val.toInt()*.5));
        ToneTVA_Bias_ptrHiLine = ToneTVA_Bias_scene->addLine(ToneTVA_Bias_HiLine,ToneEnv_redLine);
        ToneTVA_Bias_LowLine.setLine(40, 65+(val.toInt()*.5), ToneTVA_Bias_bpMark.x1(),65);
        ToneTVA_Bias_ptrLowLine = ToneTVA_Bias_scene->addLine(ToneTVA_Bias_LowLine,ToneEnv_redLine);
        break;
    }   // end switch

  ToneENVStdUpdate(0x68, 14-ToneTVA_BiasLvl_select->currentIndex());
}
void JVlibForm::on_ToneTVA_VelocityCurve_select_currentIndexChanged(int val) {
  ToneENVStdUpdate(0x69, val);
}
void JVlibForm::on_ToneTVA_VelocSens_select_valueChanged(int val) {
  val = (val+100) / 2;
  ToneENVStdUpdate(0x6A, val);
}
void JVlibForm::on_ToneTVA_Time1Sens_select_currentIndexChanged(int val) {
  ToneENVStdUpdate(0x6B, val);
}
void JVlibForm::on_ToneTVA_Time4Sens_select_currentIndexChanged(int val) {
  ToneENVStdUpdate(0x6C, val);
}
void JVlibForm::on_ToneTVA_TimeKeyfollow_select_currentIndexChanged(int val) {
  QPixmap modepic;
  switch(val) {
    case 0:
      modepic.load(":/res/keyfollow_d100.png");
      break;
    case 1:
      modepic.load(":/res/keyfollow_d70.png");
      break;
    case 2:
      modepic.load(":/res/keyfollow_d50.png");
      break;
    case 3:
      modepic.load(":/res/keyfollow_d40.png");
      break;
    case 4:
      modepic.load(":/res/keyfollow_d30.png");
      break;
    case 5:
      modepic.load(":/res/keyfollow_d20.png");
      break;
    case 6:
      modepic.load(":/res/keyfollow_d10.png");
      break;
    case 7:
      modepic.load(":/res/keyfollow_0.png");
      break;
    case 8:
      modepic.load(":/res/keyfollow_u10.png");
      break;
    case 9:
      modepic.load(":/res/keyfollow_u20.png");
      break;
    case 10:
      modepic.load(":/res/keyfollow_u30.png");
      break;
    case 11:
      modepic.load(":/res/keyfollow_u40.png");
      break;
    case 12:
      modepic.load(":/res/keyfollow_u50.png");
      break;
    case 13:
      modepic.load(":/res/keyfollow_u70.png");
      break;
    case 14:
      modepic.load(":/res/keyfollow_u100.png");
      break;
    case 15:
      modepic.load(":/res/keyfollow_u120.png");
      break;
    case 16:
      modepic.load(":/res/keyfollow_u150.png");
      break;
    case 17:
      modepic.load(":/res/keyfollow_u200.png");
      break;
  }	// end Switch
  ToneTVA_TimeKeyfollow_pixmap->setPixmap(modepic);
  ToneENVStdUpdate(0x6D, val);
}

//-----------------------------------------------------------------------------//
void JVlibForm::on_ToneTVA_Time1_select_valueChanged(int val) {
  static QGraphicsLineItem *ptrT1Mark;
  qreal oldY = ToneTVA_Env_ptrT1?ToneTVA_Env_t1.y2():-63;
  if (ptrT1Mark) {
      ToneTVA_Env_scene->removeItem(ptrT1Mark);
      ptrT1Mark=0;
  }
  if (ToneTVA_Env_t1Text) {
      ToneTVA_Env_scene->removeItem(ToneTVA_Env_t1Text);
      ToneTVA_Env_t1Text=0;
  }
  if (ToneTVA_Env_ptrT1) {
      ToneTVA_Env_scene->removeItem(ToneTVA_Env_ptrT1);
      ToneTVA_Env_ptrT1=0;
  }
  ToneTVA_Env_t1.setLine(30,0,val/2+30,oldY);
  ToneTVA_Env_ptrT1 = ToneTVA_Env_scene->addLine(ToneTVA_Env_t1,ToneEnv_redLine);
  if (val>0) {
      ToneTVA_Env_t1Mark.setLine(ToneTVA_Env_t1.x2(),0,ToneTVA_Env_t1.x2(),-63);
      ptrT1Mark = ToneTVA_Env_scene->addLine(ToneTVA_Env_t1Mark,ToneEnv_dotLine);
      ToneTVA_Env_t1Text = ToneTVA_Env_scene->addSimpleText("T1");
      ToneTVA_Env_t1Text->setPos((ToneTVA_Env_t1.x2()+ToneTVA_Env_t1.x1())/2-5,-80);
  }
  if (state_table->updates_enabled == true) {
    state_table->updates_enabled = false;
    on_ToneTVA_Time2_select_valueChanged(ToneTVA_Time2_select->value());
    state_table->updates_enabled = true;
  } else {
    on_ToneTVA_Time2_select_valueChanged(ToneTVA_Time2_select->value());
  }
  ToneENVStdUpdate(0x6E, val);
}
void JVlibForm::on_ToneTVA_Time2_select_valueChanged(int val) {
    static QGraphicsLineItem *ptrT2Mark;
    qreal oldY2 = ToneTVA_Env_ptrT2?ToneTVA_Env_t2.y2():-63;
    if (ptrT2Mark) {
        ToneTVA_Env_scene->removeItem(ptrT2Mark);
        ptrT2Mark=0;
    }
    if (ToneTVA_Env_ptrT2) {
        ToneTVA_Env_scene->removeItem(ToneTVA_Env_ptrT2);
        ToneTVA_Env_ptrT2=0;
    }
    if (ToneTVA_Env_t2Text) {
        ToneTVA_Env_scene->removeItem(ToneTVA_Env_t2Text);
        ToneTVA_Env_t2Text=0;
    }
    ToneTVA_Env_t2.setLine(ToneTVA_Env_t1.x2(),ToneTVA_Env_t1.y2(),ToneTVA_Env_t1.x2()+val/2,oldY2);
    ToneTVA_Env_ptrT2 = ToneTVA_Env_scene->addLine(ToneTVA_Env_t2,ToneEnv_redLine);
    if (ToneTVA_Env_t2.x2()-ToneTVA_Env_t2.x1()>0) {
        ToneTVA_Env_t2Mark.setLine(ToneTVA_Env_t2.x2(),0,ToneTVA_Env_t2.x2(),-63);
        ptrT2Mark = ToneTVA_Env_scene->addLine(ToneTVA_Env_t2Mark,ToneEnv_dotLine);
        ToneTVA_Env_t2Text = ToneTVA_Env_scene->addSimpleText("T2");
        ToneTVA_Env_t2Text->setPos((ToneTVA_Env_t2.x2()+ToneTVA_Env_t2.x1())/2-5,-80);
    }
  if (state_table->updates_enabled == true) {
    state_table->updates_enabled = false;
    on_ToneTVA_Time3_select_valueChanged(ToneTVA_Time3_select->value());
    state_table->updates_enabled = true;
  } else {
    on_ToneTVA_Time3_select_valueChanged(ToneTVA_Time3_select->value());
  }
  ToneENVStdUpdate(0x6F, val);
}
void JVlibForm::on_ToneTVA_Time3_select_valueChanged(int val) {
    static QGraphicsLineItem *ptrT3Mark;
    qreal oldY2 = ToneTVA_Env_ptrT3?ToneTVA_Env_t3.y2():-63;
    if (ptrT3Mark) {
        ToneTVA_Env_scene->removeItem(ptrT3Mark);
        ptrT3Mark=0;
    }
    if (ToneTVA_Env_t3Text) {
        ToneTVA_Env_scene->removeItem(ToneTVA_Env_t3Text);
        ToneTVA_Env_t3Text=0;
    }
    if (ToneTVA_Env_ptrT3) {
        ToneTVA_Env_scene->removeItem(ToneTVA_Env_ptrT3);
        ToneTVA_Env_ptrT3=0;
    }
    ToneTVA_Env_t3.setLine(ToneTVA_Env_t2.x2(),ToneTVA_Env_t2.y2(),ToneTVA_Env_t2.x2()+val/2,oldY2);
    ToneTVA_Env_ptrT3 = ToneTVA_Env_scene->addLine(ToneTVA_Env_t3,ToneEnv_redLine);
    if (ToneTVA_Env_t3.x2()-ToneTVA_Env_t3.x1()>0) {
        ToneTVA_Env_t3Mark.setLine(ToneTVA_Env_t3.x2(),0,ToneTVA_Env_t3.x2(),-63);
        ptrT3Mark = ToneTVA_Env_scene->addLine(ToneTVA_Env_t3Mark,ToneEnv_dotLine);
        ToneTVA_Env_t3Text = ToneTVA_Env_scene->addSimpleText("T3");
        ToneTVA_Env_t3Text->setPos((ToneTVA_Env_t3.x2()+ToneTVA_Env_t3.x1())/2-5,-80);
    }
  if (state_table->updates_enabled == true) {
    state_table->updates_enabled = false;
    on_ToneTVA_Time4_select_valueChanged(ToneTVA_Time4_select->value());
    state_table->updates_enabled = true;
  } else {
    on_ToneTVA_Time4_select_valueChanged(ToneTVA_Time4_select->value());
  }
  ToneENVStdUpdate(0x70, val);
}
void JVlibForm::on_ToneTVA_Time4_select_valueChanged(int val) {
  static QGraphicsLineItem *ptrT4Mark;
  static QGraphicsLineItem *ptrOffLine;

  if (ptrT4Mark) {
      ToneTVA_Env_scene->removeItem(ptrT4Mark);
      ptrT4Mark=0;
  }
  if (ptrOffLine) {
      ToneTVA_Env_scene->removeItem(ptrOffLine);
      ptrOffLine=0;
  }
  if (ToneTVA_Env_sndText) {
      ToneTVA_Env_scene->removeItem(ToneTVA_Env_sndText);
      ToneTVA_Env_sndText=0;
  }
  if (ToneTVA_Env_ptrSustain) {
      ToneTVA_Env_scene->removeItem(ToneTVA_Env_ptrSustain);
      ToneTVA_Env_ptrSustain=0;
  }
  if (ToneTVA_Env_ptrT4) {
      ToneTVA_Env_scene->removeItem(ToneTVA_Env_ptrT4);
      ToneTVA_Env_ptrT4=0;
  }
  if (ToneTVA_Env_t4Text) {
      ToneTVA_Env_scene->removeItem(ToneTVA_Env_t4Text);
      ToneTVA_Env_t4Text=0;
  }
  ToneTVA_Env_sustain.setLine(ToneTVA_Env_t3.x2(), ToneTVA_Env_t3.y2(), 384-(val/2), ToneTVA_Env_t3.y2());
  ToneTVA_Env_ptrSustain = ToneTVA_Env_scene->addLine(ToneTVA_Env_sustain,ToneEnv_redLine);
  ToneTVA_Env_t4.setLine(ToneTVA_Env_sustain.x2(),ToneTVA_Env_sustain.y2(), 384, 0);
  if (ToneTVA_Lvl3_select->value()) {
    ToneTVA_Env_sndText = ToneTVA_Env_scene->addSimpleText("(sounding)");
    ToneTVA_Env_sndText->setPos((ToneTVA_Env_sustain.x1()+ToneTVA_Env_sustain.x2())/2-35, ToneTVA_Env_sustain.y1()-20);
  }
  ToneTVA_Env_ptrT4 = ToneTVA_Env_scene->addLine(ToneTVA_Env_t4,ToneEnv_redLine);
  ToneTVA_Env_t4Mark.setLine(ToneTVA_Env_t4.x2(),0,ToneTVA_Env_t4.x2(),-63);
  ToneTVA_Env_offLine.setLine(ToneTVA_Env_t4.x1(),8,ToneTVA_Env_t4.x1(),-63);
  ptrOffLine = ToneTVA_Env_scene->addLine(ToneTVA_Env_offLine,ToneEnv_dotLine);
  ToneTVA_Env_OffText->setPos(ToneTVA_Env_t4.x1()-23,8);
  ptrT4Mark = ToneTVA_Env_scene->addLine(ToneTVA_Env_t4Mark,ToneEnv_dotLine);
  ToneTVA_Env_t4Text = ToneTVA_Env_scene->addSimpleText("T4");
  ToneTVA_Env_t4Text->setPos((ToneTVA_Env_t4.x2()+ToneTVA_Env_t4.x1())/2-5,-80);
  ToneENVStdUpdate(0x71, val);
}
void JVlibForm::on_ToneTVA_Lvl1_select_valueChanged(int val) {
  qreal oldX = ToneTVA_Env_ptrT1?ToneTVA_Env_t1.x2():30;
  if (ToneTVA_Env_ptrT1) {
      ToneTVA_Env_scene->removeItem(ToneTVA_Env_ptrT1);
      ToneTVA_Env_ptrT1=0;
  }
  ToneTVA_Env_t1.setLine(30,0,oldX,-val/2);
  ToneTVA_Env_ptrT1 = ToneTVA_Env_scene->addLine(ToneTVA_Env_t1,ToneEnv_redLine);
  if (state_table->updates_enabled == true) {
    state_table->updates_enabled = false;
    on_ToneTVA_Lvl2_select_valueChanged(ToneTVA_Lvl2_select->value());
    state_table->updates_enabled = true;
  } else {
    on_ToneTVA_Lvl2_select_valueChanged(ToneTVA_Lvl2_select->value());
  }
  ToneENVStdUpdate(0x72, val);
}
void JVlibForm::on_ToneTVA_Lvl2_select_valueChanged(int val) {
    qreal oldX = ToneTVA_Env_t2.x2();
    if (ToneTVA_Env_ptrT2) {
        ToneTVA_Env_scene->removeItem(ToneTVA_Env_ptrT2);
        ToneTVA_Env_ptrT2=0;
    }
    ToneTVA_Env_t2.setLine(ToneTVA_Env_t1.x2(),ToneTVA_Env_t1.y2(),oldX,-val/2);
    ToneTVA_Env_ptrT2 = ToneTVA_Env_scene->addLine(ToneTVA_Env_t2,ToneEnv_redLine);
  if (state_table->updates_enabled == true) {
    state_table->updates_enabled = false;
    on_ToneTVA_Lvl3_select_valueChanged(ToneTVA_Lvl3_select->value());
    state_table->updates_enabled = true;
  } else {
    on_ToneTVA_Lvl3_select_valueChanged(ToneTVA_Lvl3_select->value());
  }
  ToneENVStdUpdate(0x73, val);
}
void JVlibForm::on_ToneTVA_Lvl3_select_valueChanged(int val) {
    qreal oldX = ToneTVA_Env_t3.x2();
    if (ToneTVA_Env_ptrT3) {
        ToneTVA_Env_scene->removeItem(ToneTVA_Env_ptrT3);
        ToneTVA_Env_ptrT3=0;
    }
    ToneTVA_Env_t3.setLine(ToneTVA_Env_t2.x2(),ToneTVA_Env_t2.y2(),oldX,-val/2);
    ToneTVA_Env_ptrT3 = ToneTVA_Env_scene->addLine(ToneTVA_Env_t3,ToneEnv_redLine);
  if (state_table->updates_enabled == true) {
    state_table->updates_enabled = false;
    on_ToneTVA_Time4_select_valueChanged(ToneTVA_Time4_select->value());
    state_table->updates_enabled = true;
  } else {
    on_ToneTVA_Time4_select_valueChanged(ToneTVA_Time4_select->value());
  }
  ToneENVStdUpdate(0x74, val);
}

//-----------------------------------------------------------------------------//
void JVlibForm::on_ToneTVA_LFO1Depth_select_valueChanged(int val) {
  ToneENVStdUpdate(0x75, val+63);
}
void JVlibForm::on_ToneTVA_LFO2Depth_select_valueChanged(int val) {
  ToneENVStdUpdate(0x76, val+63);
}

void JVlibForm::ToneTVF_enable(bool val) {
  ToneTVF_CutoffFreq_select->setEnabled(val);
  ToneTVF_Resonance_select->setEnabled(val);
  ToneTVF_CutoffKeyfollow_select->setEnabled(val);
  ToneTVF_ResVelocSens_select->setEnabled(val);
  ToneTVF_VelocSens_select->setEnabled(val);
  ToneTVF_Depth_select->setEnabled(val);
  ToneTVF_VelocityCurve_select->setEnabled(val);
  ToneTVF_Time1Sens_select->setEnabled(val);
  ToneTVF_Time4Sens_select->setEnabled(val);
  ToneTVF_TimeKeyfollow_select->setEnabled(val);
  ToneTVF_Time1_select->setEnabled(val);
  ToneTVF_Time2_select->setEnabled(val);
  ToneTVF_Time3_select->setEnabled(val);
  ToneTVF_Time4_select->setEnabled(val);
  ToneTVF_Lvl1_select->setEnabled(val);
  ToneTVF_Lvl2_select->setEnabled(val);
  ToneTVF_Lvl3_select->setEnabled(val);
  ToneTVF_Lvl4_select->setEnabled(val);
  ToneTVF_LFO1Depth_select->setEnabled(val);
  ToneTVF_LFO2Depth_select->setEnabled(val);
}