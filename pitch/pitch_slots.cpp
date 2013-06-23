// pitch_slots.cpp
#include        "JVlibForm.h"
#include        <QtGui>

QPen Pitch_dotLine(Qt::DotLine);
QPen Pitch_redLine(Qt::red, 0);

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
  PitchStdUpdate(0x0E, val);
}
void JVlibForm::on_Pitch_HighLimit_select_valueChanged(int val) {
  Pitch_HighLimit_display->setText(funcNoteCalc(val));
  PitchStdUpdate(0x0F, val);
}

void JVlibForm::on_Pitch_TimeKeyfollow_select_currentIndexChanged(int val) {
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
  Pitch_TimeKeyfollow_pixmap->setPixmap(modepic);
  PitchStdUpdate(0x45, val);
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
  // -12 to +12
  PitchStdUpdate(0x41, val+12);
/*  Pitch_Env_display->resetTransform();
  if (val) {
    qreal dy = (12-fabs(val))/12;
    Pitch_Env_display->scale(1,dy);
  }
*/
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
  }	// end Switch
  Pitch_Keyfollow_pixmap->setPixmap(modepic);
  PitchStdUpdate(0x40, val);
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
  qreal oldY = Pitch_Env_ptrT1?Pitch_Env_t1.y2():90;
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
  Pitch_Env_t1.setLine(50,90,val/2+50,oldY);
  Pitch_Env_ptrT1 = Pitch_Env_scene->addLine(Pitch_Env_t1,Pitch_redLine);
  if (val>0) {
    Pitch_Env_t1Mark.setLine(Pitch_Env_t1.x2(),20,Pitch_Env_t1.x2(),157);
    ptrT1Mark = Pitch_Env_scene->addLine(Pitch_Env_t1Mark,Pitch_dotLine);
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
    Pitch_Env_ptrT2 = Pitch_Env_scene->addLine(Pitch_Env_t2,Pitch_redLine);
    if (val>0) {
        ptrT2Mark = Pitch_Env_scene->addLine(Pitch_Env_t2Mark,Pitch_dotLine);
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
    qreal oldY2 = Pitch_Env_ptrT3?Pitch_Env_t3.y2():90;
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
    Pitch_Env_t3.setLine(Pitch_Env_t2.x2(),Pitch_Env_t2.y2(),Pitch_Env_t2.x2()+val/2,oldY2);
    Pitch_Env_t3Mark.setLine(Pitch_Env_t3.x2(),20,Pitch_Env_t3.x2(),157);
    if (val>0) {
        Pitch_Env_ptrT3 = Pitch_Env_scene->addLine(Pitch_Env_t3,Pitch_redLine);
        ptrT3Mark = Pitch_Env_scene->addLine(Pitch_Env_t3Mark,Pitch_dotLine);
        Pitch_Env_t3Text = Pitch_Env_scene->addSimpleText("T3");
    }
    if (Pitch_Env_t3Text) Pitch_Env_t3Text->setPos((Pitch_Env_t3.x2()+Pitch_Env_t3.x1())/2-5,Pitch_Env_t3.y1()<Pitch_Env_t3.y2()?Pitch_Env_t3.y1()-15:Pitch_Env_t3.y2()-15);
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
  Pitch_Env_ptrSustain = Pitch_Env_scene->addLine(Pitch_Env_sustain,Pitch_redLine);
  if (Pitch_Lvl3_select->value()) {
    Pitch_Env_sndText = Pitch_Env_scene->addSimpleText("(sounding)");
    Pitch_Env_sndText->setPos((Pitch_Env_sustain.x1()+Pitch_Env_sustain.x2())/2-35, Pitch_Env_sustain.y1()-15);
  }
  Pitch_Env_t4.setLine(Pitch_Env_sustain.x2(), Pitch_Env_sustain.y2(), 384, Pitch_Depth_select->value()>=0?90-Pitch_Lvl4_select->value():90+Pitch_Lvl4_select->value());
  Pitch_Env_offLine.setLine(Pitch_Env_t4.x1(),20,Pitch_Env_t4.x1(),157);
  Pitch_Env_t4Mark.setLine(Pitch_Env_t4.x2(),20,Pitch_Env_t4.x2(),157);
  ptrOffLine = Pitch_Env_scene->addLine(Pitch_Env_offLine,Pitch_dotLine);
  Pitch_Env_OffText->setPos(Pitch_Env_t4.x1()-3,160);
  Pitch_Env_ptrT4 = Pitch_Env_scene->addLine(Pitch_Env_t4,Pitch_redLine);
  if (val>0) {
      ptrT4Mark = Pitch_Env_scene->addLine(Pitch_Env_t4Mark,Pitch_dotLine);
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
  val += fabs(Pitch_Depth_select->value());
  Pitch_Env_t1.setLine(50,90,oldX, Pitch_Depth_select->value()>=0?90-val:90+val);
  Pitch_Env_ptrT1 = Pitch_Env_scene->addLine(Pitch_Env_t1,Pitch_redLine);
  if (Pitch_Env_t1Text) Pitch_Env_t1Text->setPos((Pitch_Env_t1.x2()+Pitch_Env_t1.x1())/2-5,Pitch_Env_t1.y2()-15);
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
  val += fabs(Pitch_Depth_select->value());
  Pitch_Env_t2.setLine(Pitch_Env_t1.x2(),Pitch_Env_t1.y2(),oldX, Pitch_Depth_select->value()>=0?90-val:90+val);
  Pitch_Env_ptrT2 = Pitch_Env_scene->addLine(Pitch_Env_t2,Pitch_redLine);
  if (Pitch_Env_t2Text) Pitch_Env_t2Text->setPos((Pitch_Env_t2.x2()+Pitch_Env_t2.x1())/2-5, Pitch_Env_t2.y1()<Pitch_Env_t2.y2()?Pitch_Env_t2.y1()-15:Pitch_Env_t2.y2()-15);
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
  val += fabs(Pitch_Depth_select->value());
  Pitch_Env_t3.setLine(Pitch_Env_t2.x2(),Pitch_Env_t2.y2(),oldX,Pitch_Depth_select->value()>=0?90-val:90+val);
  Pitch_Env_ptrT3 = Pitch_Env_scene->addLine(Pitch_Env_t3,Pitch_redLine);
  if (Pitch_Env_t3Text) Pitch_Env_t3Text->setPos((Pitch_Env_t3.x2()+Pitch_Env_t3.x1())/2-5, 
      Pitch_Env_t3.y1()<Pitch_Env_t3.y2() ? Pitch_Env_t3.y1()-15 : Pitch_Env_t3.y2()-15);
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
  Pitch_Env_ptrSustain = Pitch_Env_scene->addLine(Pitch_Env_sustain,Pitch_redLine);
  if (Pitch_Lvl3_select->value()) {
    Pitch_Env_sndText = Pitch_Env_scene->addSimpleText("(sounding)");
    Pitch_Env_sndText->setPos((Pitch_Env_sustain.x1()+Pitch_Env_sustain.x2())/2-35, Pitch_Env_sustain.y1()-15);
  }
  Pitch_Env_t4.setLine(Pitch_Env_sustain.x2(), Pitch_Env_sustain.y2(), 384, Pitch_Depth_select->value()>=0?90-val:90+val);
  Pitch_Env_ptrT4 = Pitch_Env_scene->addLine(Pitch_Env_t4,Pitch_redLine);
  if (Pitch_Env_t4Text) Pitch_Env_t4Text->setPos((Pitch_Env_t4.x2()+Pitch_Env_t4.x1())/2-5, Pitch_Env_t4.y1()<Pitch_Env_t4.y2()?Pitch_Env_t4.y1()-15:Pitch_Env_t4.y2()-15);    
  PitchStdUpdate(0x4D, val+63);
}
void JVlibForm::on_Pitch_LFO1Depth_select_valueChanged(int val) {
  PitchStdUpdate(0x4E, val+63);
}
void JVlibForm::on_Pitch_LFO2Depth_select_valueChanged(int val) {
  PitchStdUpdate(0x4F, val+63);
}
