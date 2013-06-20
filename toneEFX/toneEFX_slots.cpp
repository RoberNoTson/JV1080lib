// toneEFX_slots.cpp
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::ToneEFXStdUpdate(int offset, int val) {
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
  }	// end state_table->updates_enabled
}	// end ToneEFXStdUpdate

void JVlibForm::on_ToneEFX_PanControl_select_currentIndexChanged(int val) {
  ToneEFX_Pan_select->setEnabled(val?true:false);
  ToneEFX_AltPan_select->setEnabled(val?true:false);
  ToneEFX_PanLFO1Depth_select->setEnabled(val?true:false);
  ToneEFX_PanLFO2Depth_select->setEnabled(val?true:false);
  ToneEFX_PanRandDepth_select->setEnabled(val?true:false);
  ToneEFX_PanKeyFollow_select->setEnabled(val?true:false);
  ToneEFXStdUpdate(0x14, val);
}
void JVlibForm::on_ToneEFX_Pan_select_valueChanged(int val) {
 if (val==64)
  ToneEFX_Pan_display->setText(QString("Center"));
 else if (val<64)
  ToneEFX_Pan_display->setText(QString("L")+QString::number((val-64)*90/64)+QString(" Deg."));
 else 
  ToneEFX_Pan_display->setText(QString("R")+QString::number((63-val)*90/63)+QString(" Deg."));
  ToneEFXStdUpdate(0x77, val);
}
void JVlibForm::on_ToneEFX_PanKeyFollow_select_currentIndexChanged(int val) {
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
    case 3:	// down 40
      modepic.load(":/res/keyfollow_d40.png");
      break;
    case 4:	// -30
      modepic.load(":/res/keyfollow_d30.png");
      break;
    case 5:	// -20
      modepic.load(":/res/keyfollow_d20.png");
      break;
    case 6:	// -10
      modepic.load(":/res/keyfollow_d10.png");
      break;
    case 7:	//0
      modepic.load(":/res/keyfollow_0.png");
      break;
    case 8:	// +10
      modepic.load(":/res/keyfollow_u10.png");
      break;
    case 9:	// +20
      modepic.load(":/res/keyfollow_u20.png");
      break;
    case 10:	// +30
      modepic.load(":/res/keyfollow_u30.png");
      break;
    case 11:	// +40
      modepic.load(":/res/keyfollow_u40.png");
      break;
    case 12:	// +50
      modepic.load(":/res/keyfollow_u50.png");
      break;
    case 13:	// +70
      modepic.load(":/res/keyfollow_u70.png");
      break;
    case 14:	// +100
      modepic.load(":/res/keyfollow_u100.png");
      break;
    case 15:	// +120
      modepic.load(":/res/keyfollow_u120.png");
      break;
    case 16:	// +150
      modepic.load(":/res/keyfollow_u150.png");
      break;
    case 17:	// +200
      modepic.load(":/res/keyfollow_u200.png");
      break;
  }	// end Switch
  ToneEFX_PanKeyfollow_pixmap->setPixmap(modepic);
  ToneEFXStdUpdate(0x78, val);
}
void JVlibForm::on_ToneEFX_PanRandDepth_select_valueChanged(int val) {
  ToneEFXStdUpdate(0x79, val);
}
void JVlibForm::on_ToneEFX_AltPan_select_valueChanged(int val) {
 if (val==64)
  ToneEFX_AltPan_display->setText(QString("Center"));
 else if (val<64)
  ToneEFX_AltPan_display->setText(QString("L")+QString::number((val-64)*90/64)+QString(" Deg."));
 else 
  ToneEFX_AltPan_display->setText(QString("R")+QString::number((63-val)*90/63)+QString(" Deg."));
  ToneEFXStdUpdate(0x7A, val);
}
void JVlibForm::on_ToneEFX_PanLFO1Depth_select_valueChanged(int val) {
  ToneEFXStdUpdate(0x7B, val+63);
}
void JVlibForm::on_ToneEFX_PanLFO2Depth_select_valueChanged(int val) {
  ToneEFXStdUpdate(0x7C, val+63);
}
void JVlibForm::on_ToneEFX_LF01Waveform_select_currentIndexChanged(int val) {
  ToneEFXStdUpdate(0x2D, val);
}
void JVlibForm::on_ToneEFX_LFO1KeyTrigger_enable_toggled(bool val) {
  ToneEFXStdUpdate(0x2E, val);
}
void JVlibForm::on_ToneEFX_LFO1Rate_select_valueChanged(int val) {
  QString buf;
  if (ToneEFX_LFO1ExtSync_select->currentIndex()>0) {
    if (val<49) {
      buf = QString::number(val*2);
      if (val<6) buf += " <32nd";
      else if (val==6) buf += " =32nd";
      else if (val<8) buf += " <16th Triplet";
      else if (val==8) buf += " =16th Triplet";
      else if (val==9) buf += " =dotted 32nd";
      else if (val<12) buf += " <16th";
      else if (val==12) buf += " =16th";
      else if (val<16) buf += " <8th Triplet";
      else if (val==16) buf += " =8th Triplet";
      else if (val<18) buf += " <dotted 16th";
      else if (val==18) buf += " =dotted 16th";
      else if (val<24) buf += " <8th";
      else if (val==24) buf += " =8th";
      else if (val<32) buf += " <Quarter Trp";
      else if (val==32) buf += " =Quarter Trp";
      else if (val<36) buf += " <dotted 8th";
      else if (val==36) buf += " =dotted 8th";
      else if (val<48) buf += " <Quarter";
      else  buf += " =Quarter";
    } else if (val<73) {
      buf = QString::number((val-24)*4);
      if (val<56) buf += " <Half Tpl";
      else if (val==56) buf += " =Half Tpl";
      else if (val<60) buf += " <dotted Quarter";
      else if (val==60) buf += " =dotted Quarter";
      else if (val<72) buf += " <Halfnote";
      else  buf += " =Halfnote";
    } else if (val<97) {
      buf = QString::number((val-48)*8);
      if (val<80)  buf += " <Wholenote Trp";
      else if (val==80) buf += " =Wholenote Trp";
      else if (val<84) buf += " <dotted Half";
      else if (val==84) buf += " =dotted Half";
      else if (val<96) buf += " <Wholenote";
      else buf += " =Wholenote";
    } else {
      buf = QString::number((val-72)*16);
      if (val<104) buf += " <DlbWhole Trp";
      else if (val==104) buf += " =DlbWhole Trp";
      else if (val<108) buf += " <dotted Wholenote";
      else if (val==108) buf += " =dotted Wholenote";
      else if (val<120) buf += " <DblWhole";
      else if (val==120) buf += " =DblWhole";
      else  buf += " >DblWhole";
    }
  } else {
    buf = QString::number(val);
  }
  ToneEFX_LFO1Rate_display->setText(buf);
  ToneEFXStdUpdate(0x2F, val);
}	// end on_ToneEFX_LFO1Rate_select_valueChanged

void JVlibForm::on_ToneEFX_LFO1LevelOffset_select_currentIndexChanged(int val) {
  ToneEFXStdUpdate(0x30, val);
}
void JVlibForm::on_ToneEFX_LFO1Delay_select_valueChanged(int val) {
  ToneEFXStdUpdate(0x31, val);
}
void JVlibForm::on_ToneEFX_LFO1FadeMode_select_currentIndexChanged(int val) {
  QPixmap modepic;
  switch(val) {
    case 0:
      modepic.load(":/res/LFOon_in.png");
      break;
    case 1:
      modepic.load(":/res/LFOon_out.png");
      break;
    case 2:
      modepic.load(":/res/LFOoff_in.png");
      break;
    case 3:
      modepic.load(":/res/LFOoff_out.png");
      break;
  }
  ToneEFX_LFO1_Mode_picture->setPixmap(modepic);
  ToneEFXStdUpdate(0x32, val);
}
void JVlibForm::on_ToneEFX_LFO1FadeTime_select_valueChanged(int val) {
  ToneEFXStdUpdate(0x33, val);
}
void JVlibForm::on_ToneEFX_LFO1ExtSync_select_currentIndexChanged(int val) {
  if (state_table->updates_enabled) {
    state_table->updates_enabled=false;
    on_ToneEFX_LFO1Rate_select_valueChanged(ToneEFX_LFO1Rate_select->value());
    state_table->updates_enabled=true;
    ToneEFXStdUpdate(0x34, val);
  }
}
void JVlibForm::on_ToneEFX_LF02Waveform_select_currentIndexChanged(int val) {
  ToneEFXStdUpdate(0x35, val);
}
void JVlibForm::on_ToneEFX_LFO2KeyTrigger_enable_toggled(bool val) {
  ToneEFXStdUpdate(0x36, val);
}
void JVlibForm::on_ToneEFX_LFO2Rate_select_valueChanged(int val) {
  QString buf;
  if (ToneEFX_LFO2ExtSync_select->currentIndex()>0) {
    if (val<49) {
      buf = QString::number(val*2);
      if (val<6) buf += " <32nd";
      else if (val==6) buf += " =32nd";
      else if (val<8) buf += " <16th Triplet";
      else if (val==8) buf += " =16th Triplet";
      else if (val==9) buf += " =dotted 32nd";
      else if (val<12) buf += " <16th";
      else if (val==12) buf += " =16th";
      else if (val<16) buf += " <8th Triplet";
      else if (val==16) buf += " =8th Triplet";
      else if (val<18) buf += " <dotted 16th";
      else if (val==18) buf += " =dotted 16th";
      else if (val<24) buf += " <8th";
      else if (val==24) buf += " =8th";
      else if (val<32) buf += " <Quarter Trp";
      else if (val==32) buf += " =Quarter Trp";
      else if (val<36) buf += " <dotted 8th";
      else if (val==36) buf += " =dotted 8th";
      else if (val<48) buf += " <Quarter";
      else  buf += " =Quarter";
    } else if (val<73) {
      buf = QString::number((val-24)*4);
      if (val<56) buf += " <Half Tpl";
      else if (val==56) buf += " =Half Tpl";
      else if (val<60) buf += " <dotted Quarter";
      else if (val==60) buf += " =dotted Quarter";
      else if (val<72) buf += " <Halfnote";
      else  buf += " =Halfnote";
    } else if (val<97) {
      buf = QString::number((val-48)*8);
      if (val<80)  buf += " <Wholenote Trp";
      else if (val==80) buf += " =Wholenote Trp";
      else if (val<84) buf += " <dotted Half";
      else if (val==84) buf += " =dotted Half";
      else if (val<96) buf += " <Wholenote";
      else buf += " =Wholenote";
    } else {
      buf = QString::number((val-72)*16);
      if (val<104) buf += " <DlbWhole Trp";
      else if (val==104) buf += " =DlbWhole Trp";
      else if (val<108) buf += " <dotted Wholenote";
      else if (val==108) buf += " =dotted Wholenote";
      else if (val<120) buf += " <DblWhole";
      else if (val==120) buf += " =DblWhole";
      else  buf += " >DblWhole";
    }
  } else {
    buf = QString::number(val);
  }
  ToneEFX_LFO2Rate_display->setText(buf);
  ToneEFXStdUpdate(0x37, val);
}	// end on_ToneEFX_LFO2Rate_select_valueChanged

void JVlibForm::on_ToneEFX_LFO2LevelOffset_select_currentIndexChanged(int val) {
  ToneEFXStdUpdate(0x38, val);
}
void JVlibForm::on_ToneEFX_LFO2Delay_select_valueChanged(int val) {
  ToneEFXStdUpdate(0x39, val);
}
void JVlibForm::on_ToneEFX_LFO2FadeMode_select_currentIndexChanged(int val) {
  QPixmap modepic;
  switch(val) {
    case 0:
      modepic.load(":/res/LFOon_in.png");
      break;
    case 1:
      modepic.load(":/res/LFOon_out.png");
      break;
    case 2:
      modepic.load(":/res/LFOoff_in.png");
      break;
    case 3:
      modepic.load(":/res/LFOoff_out.png");
      break;
  }
  ToneEFX_LFO2_Mode_picture->setPixmap(modepic);
  ToneEFXStdUpdate(0x3A, val);
}
void JVlibForm::on_ToneEFX_LFO2FadeTime_select_valueChanged(int val) {
  ToneEFXStdUpdate(0x3B, val);
}
void JVlibForm::on_ToneEFX_LFO2ExtSync_select_currentIndexChanged(int val) {
  if (state_table->updates_enabled) {
    state_table->updates_enabled=false;
    on_ToneEFX_LFO2Rate_select_valueChanged(ToneEFX_LFO2Rate_select->value());
    state_table->updates_enabled=true;
    ToneEFXStdUpdate(0x3C, val);
  }
}


