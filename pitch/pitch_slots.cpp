// pitch_slots.cpp
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::PitchStdUpdate(int offset, int val) {
  if (state_table->updates_enabled) {
    bool *ptr;
    int tn = Tone_ToneNumber_select->value() - 1;
    if (state_table->perf_mode)
      ptr = &active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_tone[tn].tone;
    else
      ptr = &active_area->active_patch_patch.patch_tone[tn].tone;
    ptr[offset] = val;
    if (state_table->jv_connect) 
      setToneSingleValue(tn,offset, val);
  }     // end state_table->updates_enabled
}       // end PitchStdUpdate

void JVlibForm::on_Pitch_TestTone_switch_toggled(bool val) {
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
  if (open_ports() == EXIT_FAILURE) return;
  if (change_send(buf,3) == EXIT_FAILURE) { close_ports(); return; }
  close_ports();
  }
  Pitch_TestTone_switch->setText(val ? QString::fromUtf8("Stop") : QString::fromUtf8("Play Patch") );
  }
}	// end on_Pitch_TestTone_switch_toggled

void JVlibForm::on_Pitch_StretchTuning_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.stretch_tune_depth = val;
    else
      active_area->active_patch_patch.patch_common.stretch_tune_depth = val;
    if (state_table->jv_connect) 
      setPatchSingleValue(0x42, val);    
  }	// end state_table->updates_enabled
  QPixmap StretchTune_pixmap;
  switch(val) {
    case 0:
      StretchTune_pixmap.load(":/res/Patch_StretchTune0.png");
      break;
    case 1:
      StretchTune_pixmap.load(":/res/Patch_StretchTune1.png");
      break;
    case 2:
      StretchTune_pixmap.load(":/res/Patch_StretchTune2.png");
      break;
    case 3:
      StretchTune_pixmap.load(":/res/Patch_StretchTune3.png");
      break;
  }	// end Switch
  Pitch_StretchTuning_picture->setPixmap(StretchTune_pixmap);
}	// end on_Pitch_StretchTuning_select_valueChanged

void JVlibForm::on_Pitch_LowLimit_select_valueChanged(int val) {
  Pitch_LowLimit_display->setText(funcNoteCalc(val));
  if (val>Pitch_HighLimit_select->value()) on_Pitch_HighLimit_select_valueChanged(val);
  PitchStdUpdate(0x0E, val);
}
void JVlibForm::on_Pitch_HighLimit_select_valueChanged(int val) {
  Pitch_HighLimit_display->setText(funcNoteCalc(val));
  if (val<Pitch_LowLimit_select->value()) on_Pitch_LowLimit_select_valueChanged(val);
  PitchStdUpdate(0x0F, val);
}

void JVlibForm::on_Pitch_TimeKeyfollow_select_currentIndexChanged(int val) {
  static QGraphicsLineItem *ptrLine;
  if (ptrLine) {
    Pitch_TimeKeyFollow_scene->removeItem(ptrLine);
    ptrLine = 0;
  }
  switch(val) {
    case 0: // +100
        ptrLine = Pitch_TimeKeyFollow_scene->addLine(10,110,345,10,redLine);
        break;
    case 1: // +70
        ptrLine = Pitch_TimeKeyFollow_scene->addLine(10,103,345,17,redLine);
        break;
    case 2: // +50
        ptrLine = Pitch_TimeKeyFollow_scene->addLine(10,95,345,24,redLine);
        break;
    case 3: // +40
        ptrLine = Pitch_TimeKeyFollow_scene->addLine(10,88,345,31,redLine);
        break;
    case 4: // +30
        ptrLine = Pitch_TimeKeyFollow_scene->addLine(10,81,345,38,redLine);
        break;
    case 5: // +20
        ptrLine = Pitch_TimeKeyFollow_scene->addLine(10,74,345,45,redLine);
        break;
    case 6: // +10
        ptrLine = Pitch_TimeKeyFollow_scene->addLine(10,67,345,52,redLine);
        break;
    case 7: // 0
        ptrLine = Pitch_TimeKeyFollow_scene->addLine(10,60,345,60,redLine);
        break;
    case 8: // -10
        ptrLine = Pitch_TimeKeyFollow_scene->addLine(10,52,345,67,redLine);
        break;
    case 9: // -20
        ptrLine = Pitch_TimeKeyFollow_scene->addLine(10,45,345,74,redLine);
        break;
    case 10:    // -30
        ptrLine = Pitch_TimeKeyFollow_scene->addLine(10,38,345,81,redLine);
        break;
    case 11:    // -40
        ptrLine = Pitch_TimeKeyFollow_scene->addLine(10,31,345,88,redLine);
        break;
    case 12:    // -50
        ptrLine = Pitch_TimeKeyFollow_scene->addLine(10,24,345,95,redLine);
        break;
    case 13:    // -70
        ptrLine = Pitch_TimeKeyFollow_scene->addLine(10,17,345,103,redLine);
        break;
    case 14:    // -100
        ptrLine = Pitch_TimeKeyFollow_scene->addLine(10,10,345,110,redLine);
        break;
  }	// end Switch
 PitchStdUpdate(0x45, 14-val);
}
void JVlibForm::on_Pitch_Transpose_select_valueChanged(int val) {
  Pitch_Transpose_display->display(val);
  PitchStdUpdate(0x3D, val+48);
}
void JVlibForm::on_Pitch_TuneAdj_select_valueChanged(int val) {
  Pitch_TuneAdj_display->display(val);
  PitchStdUpdate(0x3E, val+50);
}
void JVlibForm::on_Pitch_RandPitchDepth_select_currentIndexChanged(int val) {
  PitchStdUpdate(0x3F, val);
}
void JVlibForm::on_Pitch_Depth_select_valueChanged(int val) {
  // -12 to +12 half-steps
  PitchStdUpdate(0x41, val+12);
  on_Pitch_Lvl1_select_valueChanged(Pitch_Lvl1_select->value());
}

void JVlibForm::on_Pitch_OctaveShift_select_currentIndexChanged(int val) {
  if (state_table->updates_enabled) {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.octave_shift = val;
    else
      active_area->active_patch_patch.patch_common.octave_shift = val;
    if (state_table->jv_connect) 
      setPatchSingleValue(0x41, val);    
  }
}

void JVlibForm::on_Pitch_KeyFollow_select_currentIndexChanged(int val) {
    static QGraphicsLineItem *ptrLine;
    if (ptrLine) {
        Pitch_KeyFollow_scene->removeItem(ptrLine);
        ptrLine = 0;
    }
    switch(val) {
    case 0: // +200
        ptrLine = Pitch_KeyFollow_scene->addLine(10,110,345,10,redLine);
        break;
    case 1: // +150
        ptrLine = Pitch_KeyFollow_scene->addLine(10,97.5,345,22.5,redLine);
        break;
    case 2: // +120
        ptrLine = Pitch_KeyFollow_scene->addLine(10,90,345,30,redLine);
        break;
    case 3: // +100
        ptrLine = Pitch_KeyFollow_scene->addLine(10,85,345,35,redLine);
        break;
    case 4: // +70
        ptrLine = Pitch_KeyFollow_scene->addLine(10,77.5,345,42.5,redLine);
        break;
    case 5: // +50
        ptrLine = Pitch_KeyFollow_scene->addLine(10,72.5,345,47.5,redLine);
        break;
    case 6: // +40
        ptrLine = Pitch_KeyFollow_scene->addLine(10,70,345,50,redLine);
        break;
    case 7: // +30
        ptrLine = Pitch_KeyFollow_scene->addLine(10,67.5,345,52.5,redLine);
        break;
    case 8: // +20
        ptrLine = Pitch_KeyFollow_scene->addLine(10,65,345,55,redLine);
        break;
    case 9: // +10
        ptrLine = Pitch_KeyFollow_scene->addLine(10,62.5,345,57.5,redLine);
        break;
    case 10:    // 0
        ptrLine = Pitch_KeyFollow_scene->addLine(10,60,345,60,redLine);
        break;
    case 11:    // -10
        ptrLine = Pitch_KeyFollow_scene->addLine(10,57.5,345,62.5,redLine);
        break;
    case 12:    // -30
        ptrLine = Pitch_KeyFollow_scene->addLine(10,52.5,345,67.5,redLine);
        break;
    case 13:    // -50
        ptrLine = Pitch_KeyFollow_scene->addLine(10,47.5,345,72.5,redLine);
        break;
    case 14:    // -70
        ptrLine = Pitch_KeyFollow_scene->addLine(10,42.5,345,77.5,redLine);
        break;
    case 15:    // -100
        ptrLine = Pitch_KeyFollow_scene->addLine(10,35,345,85,redLine);
        break;
    }   // end switch
  PitchStdUpdate(0x40, 15-val);
}	// end on_Pitch_KeyFollow_select_currentIndexChanged

void JVlibForm::on_Pitch_VelocSens_select_valueChanged(int val) {
  // -100 to +150 by 2
  val = (val+100) / 2;
  PitchStdUpdate(0x42, val);
}
void JVlibForm::on_Pitch_Time1Sens_select_currentIndexChanged(int val) {
  PitchStdUpdate(0x43, val);
}
void JVlibForm::on_Pitch_Time4Sens_select_currentIndexChanged(int val) {
  PitchStdUpdate(0x44, val);
}
void JVlibForm::on_Pitch_Time1_select_valueChanged(int val) {
  static QGraphicsLineItem *ptrT1Mark;
  int newVal = Pitch_Lvl1_select->value() + abs(Pitch_Lvl1_select->value()/63*Pitch_Depth_select->value());
  qreal oldY = Pitch_Env_ptrT1?Pitch_Env_t1.y2() :
    Pitch_Time1_select->value()? (Pitch_Depth_select->value()>=0?90-newVal:90+newVal):90;
  if (ptrT1Mark) {
      Pitch_Env_scene->removeItem(ptrT1Mark);
      ptrT1Mark=0;
  }
  if (Pitch_Env_t1Text) {
      Pitch_Env_scene->removeItem(Pitch_Env_t1Text);
      Pitch_Env_t1Text=0;
  }
  if (Pitch_Env_ptrT1) {
      Pitch_Env_scene->removeItem(Pitch_Env_ptrT1);
      Pitch_Env_ptrT1=0;
  }
  Pitch_Env_t1.setLine(50,90,val/2+50, oldY);
  if (val>0) {
    Pitch_Env_ptrT1 = Pitch_Env_scene->addLine(Pitch_Env_t1,redLine);
    Pitch_Env_t1Mark.setLine(Pitch_Env_t1.x2(),20,Pitch_Env_t1.x2(),157);
    ptrT1Mark = Pitch_Env_scene->addLine(Pitch_Env_t1Mark,dotLine);
    Pitch_Env_t1Text = Pitch_Env_scene->addSimpleText("T1");
    Pitch_Env_t1Text->setPos((Pitch_Env_t1.x2()+Pitch_Env_t1.x1())/2-5,Pitch_Env_t1.y2()-15);
  }
  if (state_table->updates_enabled == true) {
    state_table->updates_enabled = false;
    on_Pitch_Time2_select_valueChanged(Pitch_Time2_select->value());
    state_table->updates_enabled = true;
  } else {
    on_Pitch_Time2_select_valueChanged(Pitch_Time2_select->value());
  }
  PitchStdUpdate(0x46, val);
}
void JVlibForm::on_Pitch_Time2_select_valueChanged(int val) {
    static QGraphicsLineItem *ptrT2Mark;
    qreal oldY2 = Pitch_Env_ptrT2?Pitch_Env_t2.y2():90;
    if (ptrT2Mark) {
        Pitch_Env_scene->removeItem(ptrT2Mark);
        ptrT2Mark=0;
    }
    if (Pitch_Env_ptrT2) {
        Pitch_Env_scene->removeItem(Pitch_Env_ptrT2);
        Pitch_Env_ptrT2=0;
    }
    if (Pitch_Env_t2Text) {
        Pitch_Env_scene->removeItem(Pitch_Env_t2Text);
        Pitch_Env_t2Text=0;
    }
    Pitch_Env_t2.setLine(Pitch_Env_t1.x2(),Pitch_Env_t1.y2(),Pitch_Env_t1.x2()+val/2,oldY2);
    Pitch_Env_t2Mark.setLine(Pitch_Env_t2.x2(),20,Pitch_Env_t2.x2(),157);
    if (val>0) {
      Pitch_Env_ptrT2 = Pitch_Env_scene->addLine(Pitch_Env_t2,redLine);
      ptrT2Mark = Pitch_Env_scene->addLine(Pitch_Env_t2Mark,dotLine);
      Pitch_Env_t2Text = Pitch_Env_scene->addSimpleText("T2");
    }
  if (Pitch_Env_t2Text) Pitch_Env_t2Text->setPos((Pitch_Env_t2.x2()+Pitch_Env_t2.x1())/2-5, Pitch_Env_t2.y1()<Pitch_Env_t2.y2()?Pitch_Env_t2.y1()-15:Pitch_Env_t2.y2()-15);
  if (state_table->updates_enabled == true) {
    state_table->updates_enabled = false;
    on_Pitch_Time3_select_valueChanged(Pitch_Time3_select->value());
    state_table->updates_enabled = true;
  } else {
    on_Pitch_Time3_select_valueChanged(Pitch_Time3_select->value());
  }
  PitchStdUpdate(0x47, val);
}
void JVlibForm::on_Pitch_Time3_select_valueChanged(int val) {
    static QGraphicsLineItem *ptrT3Mark;
    if (ptrT3Mark) {
        Pitch_Env_scene->removeItem(ptrT3Mark);
        ptrT3Mark=0;
    }
    if (Pitch_Env_t3Text) {
        Pitch_Env_scene->removeItem(Pitch_Env_t3Text);
        Pitch_Env_t3Text=0;
    }
    if (Pitch_Env_ptrT3) {
        Pitch_Env_scene->removeItem(Pitch_Env_ptrT3);
        Pitch_Env_ptrT3=0;
    }
    int newVal = Pitch_Lvl3_select->value() + abs(Pitch_Lvl3_select->value()/63*Pitch_Depth_select->value());
    Pitch_Env_t3.setLine(Pitch_Env_t2.x2(), Pitch_Env_t2.y2(), Pitch_Env_t2.x2()+val/2, Pitch_Depth_select->value()>=0?90-newVal:90+newVal);
    if (Pitch_Time1_select->value() || Pitch_Time2_select->value() || val)
      Pitch_Env_ptrT3 = Pitch_Env_scene->addLine(Pitch_Env_t3,redLine);
    
    if (val>0) {
      Pitch_Env_t3Mark.setLine(Pitch_Env_t3.x2(),20,Pitch_Env_t3.x2(),157);
      ptrT3Mark = Pitch_Env_scene->addLine(Pitch_Env_t3Mark,dotLine);
      Pitch_Env_t3Text = Pitch_Env_scene->addSimpleText("T3");
      if (Pitch_Env_t3Text) Pitch_Env_t3Text->setPos((Pitch_Env_t3.x2()+Pitch_Env_t3.x1())/2-5,Pitch_Env_t3.y1()<Pitch_Env_t3.y2()?Pitch_Env_t3.y1()-15:Pitch_Env_t3.y2()-15);
    }
  if (state_table->updates_enabled == true) {
    state_table->updates_enabled = false;
    on_Pitch_Time4_select_valueChanged(Pitch_Time4_select->value());
    state_table->updates_enabled = true;
  } else {
    on_Pitch_Time4_select_valueChanged(Pitch_Time4_select->value());
  }
  PitchStdUpdate(0x48, val);
}
void JVlibForm::on_Pitch_Time4_select_valueChanged(int val) {
  static QGraphicsLineItem *ptrT4Mark;
  static QGraphicsLineItem *ptrOffLine;

  if (ptrT4Mark) {
      Pitch_Env_scene->removeItem(ptrT4Mark);
      ptrT4Mark=0;
  }
  if (ptrOffLine) {
      Pitch_Env_scene->removeItem(ptrOffLine);
      ptrOffLine=0;
  }
  if (Pitch_Env_sndText) {
      Pitch_Env_scene->removeItem(Pitch_Env_sndText);
      Pitch_Env_sndText=0;
  }
  if (Pitch_Env_ptrSustain) {
      Pitch_Env_scene->removeItem(Pitch_Env_ptrSustain);
      Pitch_Env_ptrSustain=0;
  }
  if (Pitch_Env_ptrT4) {
      Pitch_Env_scene->removeItem(Pitch_Env_ptrT4);
      Pitch_Env_ptrT4=0;
  }
  if (Pitch_Env_t4Text) {
      Pitch_Env_scene->removeItem(Pitch_Env_t4Text);
      Pitch_Env_t4Text=0;
  }
  Pitch_Env_sustain.setLine(Pitch_Env_t3.x2(), Pitch_Env_t3.y2(), 384-(val/2), Pitch_Env_t3.y2());
  Pitch_Env_ptrSustain = Pitch_Env_scene->addLine(Pitch_Env_sustain,redLine);
    Pitch_Env_sndText = Pitch_Env_scene->addSimpleText("(sounding)");
    Pitch_Env_sndText->setPos((Pitch_Env_sustain.x1()+Pitch_Env_sustain.x2())/2-35, Pitch_Env_sustain.y1()-15);
  Pitch_Env_t4.setLine(Pitch_Env_sustain.x2(), Pitch_Env_sustain.y2(), 384, Pitch_Depth_select->value()>=0?90-Pitch_Lvl4_select->value():90+Pitch_Lvl4_select->value());
  Pitch_Env_offLine.setLine(Pitch_Env_t4.x1(),20,Pitch_Env_t4.x1(),157);
  ptrOffLine = Pitch_Env_scene->addLine(Pitch_Env_offLine,dotLine);
  Pitch_Env_OffText->setPos(Pitch_Env_t4.x1()-3,160);
  Pitch_Env_ptrT4 = Pitch_Env_scene->addLine(Pitch_Env_t4,redLine);
  if (val>0) {
    Pitch_Env_t4Mark.setLine(Pitch_Env_t4.x2(),20,Pitch_Env_t4.x2(),157);
    ptrT4Mark = Pitch_Env_scene->addLine(Pitch_Env_t4Mark,dotLine);
    Pitch_Env_t4Text = Pitch_Env_scene->addSimpleText("T4");
    Pitch_Env_t4Text->setPos((Pitch_Env_t4.x2()+Pitch_Env_t4.x1())/2-5,Pitch_Env_t4.y1()<Pitch_Env_t4.y2()?Pitch_Env_t4.y1()-15:Pitch_Env_t4.y2()-15);
  }
  PitchStdUpdate(0x49, val);
}
void JVlibForm::on_Pitch_Lvl1_select_valueChanged(int val) {
  qreal oldX = Pitch_Env_ptrT1?Pitch_Env_t1.x2():50;
  if (Pitch_Env_ptrT1) {
      Pitch_Env_scene->removeItem(Pitch_Env_ptrT1);
      Pitch_Env_ptrT1=0;
  }
  int newVal = val + abs(val/63*Pitch_Depth_select->value());
  Pitch_Env_t1.setLine(50,90,oldX,
      Pitch_Time1_select->value()? (Pitch_Depth_select->value()>=0?90-newVal:90+newVal):90);
  if (Pitch_Time1_select->value() && Pitch_Depth_select->value()!=0) {
    Pitch_Env_ptrT1 = Pitch_Env_scene->addLine(Pitch_Env_t1,redLine);
    if (Pitch_Env_t1Text) Pitch_Env_t1Text->setPos((Pitch_Env_t1.x2()+Pitch_Env_t1.x1())/2-5,
      Pitch_Env_t1.y2()-15);
  }
  if (state_table->updates_enabled == true) {
    state_table->updates_enabled = false;
    on_Pitch_Lvl2_select_valueChanged(Pitch_Lvl2_select->value());
    state_table->updates_enabled = true;
  } else {
    on_Pitch_Lvl2_select_valueChanged(Pitch_Lvl2_select->value());
  }
  PitchStdUpdate(0x4A, val+63);
}
void JVlibForm::on_Pitch_Lvl2_select_valueChanged(int val) {
  qreal oldX = Pitch_Env_t2.x2();
  if (Pitch_Env_ptrT2) {
    Pitch_Env_scene->removeItem(Pitch_Env_ptrT2);
    Pitch_Env_ptrT2=0;
  }
  int newVal = val + abs(val/63*Pitch_Depth_select->value());
  Pitch_Env_t2.setLine(Pitch_Env_t1.x2(),Pitch_Env_t1.y2(),oldX,
   Pitch_Depth_select->value()>=0?90-newVal:90+newVal);
  if (Pitch_Time2_select->value()) Pitch_Env_ptrT2 = Pitch_Env_scene->addLine(Pitch_Env_t2,redLine);
  if (Pitch_Time2_select->value() && Pitch_Depth_select->value()!=0) {
    if (Pitch_Env_t2Text) Pitch_Env_t2Text->setPos((Pitch_Env_t2.x2()+Pitch_Env_t2.x1())/2-5,
      Pitch_Env_t2.y1()<Pitch_Env_t2.y2()?Pitch_Env_t2.y1()-15:Pitch_Env_t2.y2()-15);
  }
  if (state_table->updates_enabled == true) {
    state_table->updates_enabled = false;
    on_Pitch_Lvl3_select_valueChanged(Pitch_Lvl3_select->value());
    state_table->updates_enabled = true;
  } else {
    on_Pitch_Lvl3_select_valueChanged(Pitch_Lvl3_select->value());
  }
  PitchStdUpdate(0x4B, val+63);
}
void JVlibForm::on_Pitch_Lvl3_select_valueChanged(int val) {
  qreal oldX = Pitch_Env_t3.x2();
  if (Pitch_Env_ptrT3) {
    Pitch_Env_scene->removeItem(Pitch_Env_ptrT3);
    Pitch_Env_ptrT3=0;
  }
  int newVal = val + abs(val/63*Pitch_Depth_select->value());
  Pitch_Env_t3.setLine(Pitch_Env_t2.x2(), Pitch_Env_t2.y2(), oldX, Pitch_Depth_select->value()>=0?90-newVal:90+newVal);
  if (Pitch_Time1_select->value() || Pitch_Time2_select->value() || Pitch_Time3_select->value())
    Pitch_Env_ptrT3 = Pitch_Env_scene->addLine(Pitch_Env_t3,redLine);
    
  if (Pitch_Time3_select->value() && Pitch_Depth_select->value()!=0) {
    if (Pitch_Env_t3Text) Pitch_Env_t3Text->setPos((Pitch_Env_t3.x2()+Pitch_Env_t3.x1())/2-5, 
      Pitch_Env_t3.y1()<Pitch_Env_t3.y2() ? Pitch_Env_t3.y1()-15 : Pitch_Env_t3.y2()-15);
  }
  if (state_table->updates_enabled == true) {
    state_table->updates_enabled = false;
    on_Pitch_Lvl4_select_valueChanged(Pitch_Lvl4_select->value());
    state_table->updates_enabled = true;
  } else {
    on_Pitch_Lvl4_select_valueChanged(Pitch_Lvl4_select->value());
  }
  PitchStdUpdate(0x4C, val+63);
}
void JVlibForm::on_Pitch_Lvl4_select_valueChanged(int val) {
  if (Pitch_Env_ptrSustain) {
      Pitch_Env_scene->removeItem(Pitch_Env_ptrSustain);
      Pitch_Env_ptrSustain=0;
  }
  if (Pitch_Env_sndText) {
      Pitch_Env_scene->removeItem(Pitch_Env_sndText);
      Pitch_Env_sndText=0;
  }
  if (Pitch_Env_ptrT4) {
      Pitch_Env_scene->removeItem(Pitch_Env_ptrT4);
      Pitch_Env_ptrT4=0;
  }
  Pitch_Env_sustain.setLine(Pitch_Env_t3.x2(), Pitch_Env_t3.y2(), Pitch_Env_t4.x1(), Pitch_Env_t3.y2());
  Pitch_Env_ptrSustain = Pitch_Env_scene->addLine(Pitch_Env_sustain,redLine);
  Pitch_Env_sndText = Pitch_Env_scene->addSimpleText("(sounding)");
  Pitch_Env_sndText->setPos((Pitch_Env_sustain.x1()+Pitch_Env_sustain.x2())/2-35, Pitch_Env_sustain.y1()-15);
  int newVal = val + abs(val/63*Pitch_Depth_select->value());
  Pitch_Env_t4.setLine(Pitch_Env_sustain.x2(), Pitch_Env_sustain.y2(), 384, Pitch_Depth_select->value()>=0?90-newVal:90+newVal);
  Pitch_Env_ptrT4 = Pitch_Env_scene->addLine(Pitch_Env_t4,redLine);
  if (Pitch_Time4_select->value() && Pitch_Depth_select->value()!=0) {
    if (Pitch_Env_t4Text) Pitch_Env_t4Text->setPos((Pitch_Env_t4.x2()+Pitch_Env_t4.x1())/2-5, 
      Pitch_Env_t4.y1()<Pitch_Env_t4.y2()?Pitch_Env_t4.y1()-15:Pitch_Env_t4.y2()-15);    
  }
    PitchStdUpdate(0x4D, val+63);
}
void JVlibForm::on_Pitch_LFO1Depth_select_valueChanged(int val) {
  if (ToneEFX_LFO1Target_select->currentIndex() == 0) {
    on_ToneEFX_LFO1Delay_select_valueChanged(ToneEFX_LFO1Delay_select->value());
  }
  PitchStdUpdate(0x4E, val+63);
}
void JVlibForm::on_Pitch_LFO2Depth_select_valueChanged(int val) {
  if (ToneEFX_LFO2Target_select->currentIndex() == 0) {
    on_ToneEFX_LFO2Delay_select_valueChanged(ToneEFX_LFO2Delay_select->value());
  }
  PitchStdUpdate(0x4F, val+63);
}
