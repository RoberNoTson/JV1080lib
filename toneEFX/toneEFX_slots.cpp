// toneEFX_slots.cpp
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::LFO1_setOffIn() {
    LFO1_OffLine.setLine(30,10,30,160);
    LFO1_ptrOffLine = LFO1_scene->addLine(LFO1_OffLine,dotLine);
    LFO1_OffText = LFO1_scene->addSimpleText("Off");
    LFO1_OffText->setPos(30,164);
}
void JVlibForm::LFO1_setOffOut() {
    LFO1_OffLine.setLine(42,10,42,160);
    LFO1_ptrOffLine = LFO1_scene->addLine(LFO1_OffLine,dotLine);
    LFO1_OffText = LFO1_scene->addSimpleText("Off");
    LFO1_OffText->setPos(40,164);
}
void JVlibForm::LFO2_setOffIn() {
    LFO2_OffLine.setLine(30,10,30,160);
    LFO2_ptrOffLine = LFO2_scene->addLine(LFO2_OffLine,dotLine);
    LFO2_OffText = LFO2_scene->addSimpleText("Off");
    LFO2_OffText->setPos(30,164);
}
void JVlibForm::LFO2_setOffOut() {
    LFO2_OffLine.setLine(42,10,42,160);
    LFO2_ptrOffLine = LFO2_scene->addLine(LFO2_OffLine,dotLine);
    LFO2_OffText = LFO2_scene->addSimpleText("Off");
    LFO2_OffText->setPos(40,164);
}

void JVlibForm::LFO1_FillEffect() {
    static QList<qreal> Xcross;
    static QList<QGraphicsLineItem *> WaveLines;
    if (!Xcross.isEmpty()) Xcross.clear();
    QGraphicsLineItem *dummy;
    while (!WaveLines.isEmpty()) {
        dummy = WaveLines.takeFirst();
        LFO1_scene->removeItem(dummy);
    }
  if (ToneEFX_LFO1Rate_select->value()) {
    QPen WavePen(Qt::darkGreen);
    qreal newX1, newX2, newY1, newY2;
    qreal spacer;
    qreal WaveFreq =  35 - (ToneEFX_LFO1Rate_select->value()/4);
    qreal UpSlope = LFO1_FadeUpLine.dy() / LFO1_FadeUpLine.dx();
    qreal DownSlope = LFO1_FadeDownLine.dy() / LFO1_FadeDownLine.dx();
    qreal UpBeta = LFO1_FadeUpLine.y2() - (UpSlope*LFO1_FadeUpLine.x2());
    qreal DownBeta = LFO1_FadeDownLine.y2() - (DownSlope*LFO1_FadeDownLine.x2());
    int L;
    int thisDepth = 0;
    switch(ToneEFX_LFO1Target_select->currentIndex()) {
      case 0:
	thisDepth = Pitch_LFO1Depth_select->value();
	break;
      case 1:
	thisDepth = ToneEFX_PanLFO1Depth_select->value();
	break;
      case 2:
	thisDepth = ToneTVA_LFO1Depth_select->value();
	break;
      case 3:
	thisDepth = ToneTVF_LFO1Depth_select->value();
	break;
    }
    switch(ToneEFX_LFO1FadeMode_select->currentIndex()) {
      case 0:
      case 2:
        spacer = LFO1_FadeStartLine.x1()+1;
        for (int x=0;x<=140/WaveFreq;x++) {
            Xcross << spacer;
            spacer += WaveFreq;
            if (spacer > 141) break;
        }
        L = Xcross.size() - 1;
        for (int n=(thisDepth>0?0:1);n<L;n+=2) {
            newX1 = n ? (Xcross[n]+Xcross[n-1])/2 : Xcross[n];
            newX2 = (Xcross[n]+Xcross[n+1])/2;
            if (!n)
	      newY1 = 96;
	    else
	      newY1 = newX1>=LFO1_FadeEndLine.x1() ? LFO1_EffectDownLine.y1()-1 : DownSlope*newX1+DownBeta-1;
            if (newY1 >= LFO1_EffectDownLine.y1()) newY1 = LFO1_EffectDownLine.y1()-1;
            if (newY1 >= DownSlope*newX2+DownBeta) newY1 = DownSlope*newX2+DownBeta-1;
            newY2 = newX2>=LFO1_FadeEndLine.x1() ? LFO1_EffectUpLine.y1()+1 : UpSlope*newX2+UpBeta+1;
            if (newY2 <= LFO1_EffectUpLine.y1()) newY2 = LFO1_EffectUpLine.y1()+1;
            if (newY2 < UpSlope*newX2+UpBeta) newY2 = UpSlope*newX2+UpBeta+1;
            dummy = LFO1_scene->addLine(newX1, newY1, newX2, newY2);
            dummy->setPen(WavePen);
            WaveLines << dummy;
        }
        for (int n=(thisDepth>0?1:0);n<L;n+=2) {
            newX1 = n ? (Xcross[n]+Xcross[n-1])/2 : Xcross[n];
            newX2 = (Xcross[n]+Xcross[n+1])/2;
            if (!n)
	      newY1 = 96;
	    else
	      newY1 = newX1>=LFO1_FadeEndLine.x1() ? LFO1_EffectUpLine.y1()+1 : UpSlope*newX1+UpBeta+1;
            if (newY1 <= LFO1_EffectUpLine.y1()) newY1 = LFO1_EffectUpLine.y1()+1;
            if (newY1 <= UpSlope*newX2+UpBeta) newY1 = UpSlope*newX2+UpBeta+1;
            newY2 = newX2>=LFO1_FadeEndLine.x1() ? LFO1_EffectDownLine.y1()-1 : DownSlope*newX2+DownBeta-1;
            if (newY2 >= LFO1_EffectDownLine.y1()) newY2 = LFO1_EffectDownLine.y1()-1;
            if (newY2 >= DownSlope*newX2+DownBeta) newY2 = DownSlope*newX2+DownBeta-1;
            dummy = LFO1_scene->addLine(newX1, newY1, newX2, newY2);
            dummy->setPen(WavePen);
            WaveLines << dummy;
        }
        newX1 = Xcross[L] - (WaveFreq/2);
        newX2 = 140;
	if (thisDepth>0)
	  newY1 = Xcross.size()%2 ?LFO1_EffectDownLine.y2()-1:LFO1_EffectUpLine.y2()+1;
	else
	  newY1 = Xcross.size()%2 ?LFO1_EffectUpLine.y2()+1 : LFO1_EffectDownLine.y2()-1;
        newY2 = 96;
        dummy = LFO1_scene->addLine(newX1, newY1, newX2, newY2);
        dummy->setPen(WavePen);
        WaveLines << dummy;
        break;
      case 1:
      case 3:
        spacer = 11;
        for (int x=0;x<=LFO1_FadeEndLine.x1()/WaveFreq;x++) {
            Xcross << spacer;
            spacer += WaveFreq;
            if (spacer > LFO1_FadeEndLine.x1()+1) break;
        }
        L = Xcross.size() - 1;
        for (int n=(thisDepth>0?0:1);n<L;n+=2) {
            newX1 = n ? (Xcross[n]+Xcross[n-1])/2 : Xcross[n];
            newX2 = (Xcross[n]+Xcross[n+1])/2;
            if (!n) 
	      newY1 = 96;
	    else
	      newY1 = newX1<=LFO1_FadeStartLine.x1() ? LFO1_EffectDownLine.y1()-1 : DownSlope*newX1+DownBeta-1;
            if (newY1 >= LFO1_EffectDownLine.y1()) newY1 = LFO1_EffectDownLine.y1()-1;
            newY2 = newX2<=LFO1_FadeStartLine.x1() ? LFO1_EffectUpLine.y1()+1 : UpSlope*newX2+UpBeta+1;
            if (newY2 <= LFO1_EffectUpLine.y1()) newY2 = LFO1_EffectUpLine.y1()+1;
            dummy = LFO1_scene->addLine(newX1, newY1, newX2, newY2);
            dummy->setPen(WavePen);
            WaveLines << dummy;
        }
        for (int n=(thisDepth>0?1:0);n<L;n+=2) {
            newX1 = n ? (Xcross[n]+Xcross[n-1])/2 : Xcross[n];
            newX2 = (Xcross[n]+Xcross[n+1])/2;
            if (!n) 
	      newY1 = 96;
	    else
            newY1 = newX1<=LFO1_FadeStartLine.x1() ? LFO1_EffectUpLine.y1()+1 : UpSlope*newX1+UpBeta+1;
            if (newY1 <= LFO1_EffectUpLine.y1()) newY1 = LFO1_EffectUpLine.y1()+1;
            newY2 = newX2<=LFO1_FadeStartLine.x1() ? LFO1_EffectDownLine.y1()-1 : DownSlope*newX2+DownBeta-1;
            if (newY2 >= LFO1_EffectDownLine.y1()) newY2 = LFO1_EffectDownLine.y1()-1;
            dummy = LFO1_scene->addLine(newX1, newY1, newX2, newY2);
            dummy->setPen(WavePen);
            WaveLines << dummy;
        }
        newX1 = Xcross[L] - (WaveFreq/2);
        newX2 = newX1 + (WaveFreq/2);
        if (newX2>= LFO1_FadeEndLine.x1()) {
            newX2 = LFO1_FadeEndLine.x1()-1;
	}	
	if (thisDepth>0) {
	  if (Xcross.size()%2) {
            newY1 = newX1<LFO1_FadeStartLine.x1() ? LFO1_EffectDownLine.y1()-1 : DownSlope*newX1+DownBeta-1;
            newY2 = newX2 > LFO1_FadeStartLine.x1() ? UpSlope*newX2+UpBeta+1 : LFO1_EffectUpLine.y1()+1;
	  }
	  else {
            newY1 = newX1<LFO1_FadeStartLine.x1() ? LFO1_EffectUpLine.y1()+1 : UpSlope*newX1+UpBeta+1;
            newY2 = newX2 > LFO1_FadeStartLine.x1() ? DownSlope*newX2+DownBeta-1 : LFO1_EffectDownLine.y2()-1;
	  }
	}
	else {	  
	  if (Xcross.size()%2) {
            newY1 = newX1<LFO1_FadeStartLine.x1() ? LFO1_EffectUpLine.y1()+1 : UpSlope*newX1+UpBeta+1;
            newY2 = newX2 > LFO1_FadeStartLine.x1() ? UpSlope*newX2+UpBeta+1 : LFO1_EffectUpLine.y1()+1;
	  }
	  else {
            newY1 = newX1<LFO1_FadeStartLine.x1() ? LFO1_EffectDownLine.y1()-1 : DownSlope*newX1+DownBeta-1;
            newY2 = newX2 > LFO1_FadeStartLine.x1() ? DownSlope*newX2+DownBeta-1 : LFO1_EffectDownLine.y2()-1;
	  }
	}
        if (newX2>= LFO1_FadeEndLine.x1()) {
            newY2 = 96;
        }
        dummy = LFO1_scene->addLine(newX1, newY1, newX2, newY2);
        dummy->setPen(WavePen);
        WaveLines << dummy;
        break;
    } // end switch
  } // end if Rate>0
}   // end LFO1_FillEffect

void JVlibForm::LFO2_FillEffect() {
    static QList<qreal> Xcross;
    static QList<QGraphicsLineItem *> WaveLines;
    if (!Xcross.isEmpty()) Xcross.clear();
    QGraphicsLineItem *dummy;
    while (!WaveLines.isEmpty()) {
        dummy = WaveLines.takeFirst();
        LFO2_scene->removeItem(dummy);
    }
  if (ToneEFX_LFO2Rate_select->value()) {
    QPen WavePen(Qt::darkGreen);
    qreal newX1, newX2, newY1, newY2;
    qreal spacer;
    qreal WaveFreq =  35 - (ToneEFX_LFO2Rate_select->value()/4);
    qreal UpSlope = LFO2_FadeUpLine.dy() / LFO2_FadeUpLine.dx();
    qreal DownSlope = LFO2_FadeDownLine.dy() / LFO2_FadeDownLine.dx();
    qreal UpBeta = LFO2_FadeUpLine.y2() - (UpSlope*LFO2_FadeUpLine.x2());
    qreal DownBeta = LFO2_FadeDownLine.y2() - (DownSlope*LFO2_FadeDownLine.x2());
    int L;
    int thisDepth = 0;
    switch(ToneEFX_LFO2Target_select->currentIndex()) {
      case 0:
	thisDepth = Pitch_LFO2Depth_select->value();
	break;
      case 1:
	thisDepth = ToneEFX_PanLFO2Depth_select->value();
	break;
      case 2:
	thisDepth = ToneTVA_LFO2Depth_select->value();
	break;
      case 3:
	thisDepth = ToneTVF_LFO2Depth_select->value();
	break;
    }
    switch(ToneEFX_LFO2FadeMode_select->currentIndex()) {
      case 0:
      case 2:
        spacer = LFO2_FadeStartLine.x1()+1;
        for (int x=0;x<=140/WaveFreq;x++) {
            Xcross << spacer;
            spacer += WaveFreq;
            if (spacer > 141) break;
        }
        L = Xcross.size() - 1;
        for (int n=(thisDepth>0?0:1);n<L;n+=2) {
            newX1 = n ? (Xcross[n]+Xcross[n-1])/2 : Xcross[n];
            newX2 = (Xcross[n]+Xcross[n+1])/2;
            if (!n) 
	      newY1 = 96;
	    else
	      newY1 = newX1>=LFO2_FadeEndLine.x1() ? LFO2_EffectDownLine.y1()-1 : DownSlope*newX1+DownBeta-1;
            if (newY1 >= LFO2_EffectDownLine.y1()) newY1 = LFO2_EffectDownLine.y1()-1;
            if (newY1 >= DownSlope*newX2+DownBeta) newY1 = DownSlope*newX2+DownBeta-1;
            newY2 = newX2>=LFO2_FadeEndLine.x1() ? LFO2_EffectUpLine.y1()+1 : UpSlope*newX2+UpBeta+1;
            if (newY2 <= LFO2_EffectUpLine.y1()) newY2 = LFO2_EffectUpLine.y1()+1;
            if (newY2 < UpSlope*newX2+UpBeta) newY2 = UpSlope*newX2+UpBeta+1;
            dummy = LFO2_scene->addLine(newX1, newY1, newX2, newY2);
            dummy->setPen(WavePen);
            WaveLines << dummy;
        }
        for (int n=(thisDepth>0?1:0);n<L;n+=2) {
            newX1 = n ? (Xcross[n]+Xcross[n-1])/2 : Xcross[n];
            newX2 = (Xcross[n]+Xcross[n+1])/2;
            if (!n) 
	      newY1 = 96;
	    else
	      newY1 = newX1>=LFO2_FadeEndLine.x1() ? LFO2_EffectUpLine.y1()+1 : UpSlope*newX1+UpBeta+1;
            if (newY1 <= LFO2_EffectUpLine.y1()) newY1 = LFO2_EffectUpLine.y1()+1;
            if (newY1 <= UpSlope*newX2+UpBeta) newY1 = UpSlope*newX2+UpBeta+1;
            newY2 = newX2>=LFO2_FadeEndLine.x1() ? LFO2_EffectDownLine.y1()-1 : DownSlope*newX2+DownBeta-1;
            if (newY2 >= LFO2_EffectDownLine.y1()) newY2 = LFO2_EffectDownLine.y1()-1;
            if (newY2 >= DownSlope*newX2+DownBeta) newY2 = DownSlope*newX2+DownBeta-1;
            dummy = LFO2_scene->addLine(newX1, newY1, newX2, newY2);
            dummy->setPen(WavePen);
            WaveLines << dummy;
        }
        newX1 = Xcross[L] - (WaveFreq/2);
        newX2 = 140;
	if (thisDepth>0)
	  newY1 = Xcross.size()%2 ?LFO2_EffectDownLine.y2()-1:LFO2_EffectUpLine.y2()+1;
	else
	  newY1 = Xcross.size()%2 ?LFO2_EffectUpLine.y2()+1 : LFO2_EffectDownLine.y2()-1;
        newY2 = 96;
        dummy = LFO2_scene->addLine(newX1, newY1, newX2, newY2);
        dummy->setPen(WavePen);
        WaveLines << dummy;
        break;
      case 1:
      case 3:
        spacer = 11;
        for (int x=0;x<=LFO2_FadeEndLine.x1()/WaveFreq;x++) {
            Xcross << spacer;
            spacer += WaveFreq;
            if (spacer > LFO2_FadeEndLine.x1()+1) break;
        }
        L = Xcross.size() - 1;
        for (int n=(thisDepth>0?0:1);n<L;n+=2) {
            newX1 = n ? (Xcross[n]+Xcross[n-1])/2 : Xcross[n];
            newX2 = (Xcross[n]+Xcross[n+1])/2;
            if (!n) 
	      newY1 = 96;
	    else
	      newY1 = newX1<=LFO2_FadeStartLine.x1() ? LFO2_EffectDownLine.y1()-1 : DownSlope*newX1+DownBeta+1;
            if (newY1 >= LFO2_EffectDownLine.y1()) newY1 = LFO2_EffectDownLine.y1()-1;
            newY2 = newX2<=LFO2_FadeStartLine.x1() ? LFO2_EffectUpLine.y1()+1 : UpSlope*newX2+UpBeta-1;
            if (newY2 <= LFO2_EffectUpLine.y1()) newY2 = LFO2_EffectUpLine.y1()+1;
            dummy = LFO2_scene->addLine(newX1, newY1, newX2, newY2);
            dummy->setPen(WavePen);
            WaveLines << dummy;
        }
        for (int n=(thisDepth>0?1:0);n<L;n+=2) {
            newX1 = n ? (Xcross[n]+Xcross[n-1])/2 : Xcross[n];
            newX2 = (Xcross[n]+Xcross[n+1])/2;
            if (!n) 
	      newY1 = 96;
	    else
	      newY1 = newX1<=LFO2_FadeStartLine.x1() ? LFO2_EffectUpLine.y1()+1 : UpSlope*newX1+UpBeta+1;
            if (newY1 <= LFO2_EffectUpLine.y1()) newY1 = LFO2_EffectUpLine.y1()+1;
            newY2 = newX2<=LFO2_FadeStartLine.x1() ? LFO2_EffectDownLine.y1()-1 : DownSlope*newX2+DownBeta-1;
            if (newY2 >= LFO2_EffectDownLine.y1()) newY2 = LFO2_EffectDownLine.y1()-1;
            dummy = LFO2_scene->addLine(newX1, newY1, newX2, newY2);
            dummy->setPen(WavePen);
            WaveLines << dummy;
        }
        newX1 = Xcross[L] - (WaveFreq/2);
        newX2 = newX1 + (WaveFreq/2);
	if (thisDepth>0) {
	  if (Xcross.size()%2) {
            newY1 = newX1<LFO2_FadeStartLine.x1() ? LFO2_EffectDownLine.y1()-1 : DownSlope*newX1+DownBeta-1;
            newY2 = newX2 > LFO2_FadeStartLine.x1() ? UpSlope*newX2+UpBeta+1 : LFO2_EffectUpLine.y1()+1;
	  }
	  else {
            newY1 = newX1<LFO2_FadeStartLine.x1() ? LFO2_EffectUpLine.y1()+1 : UpSlope*newX1+UpBeta+1;
            newY2 = newX2 > LFO2_FadeStartLine.x1() ? DownSlope*newX2+DownBeta-1 : LFO2_EffectDownLine.y2()-1;
	  }
	}
	else {	  
	  if (Xcross.size()%2) {
            newY1 = newX1<LFO2_FadeStartLine.x1() ? LFO2_EffectUpLine.y1()+1 : UpSlope*newX1+UpBeta+1;
            newY2 = newX2 > LFO2_FadeStartLine.x1() ? UpSlope*newX2+UpBeta+1 : LFO2_EffectUpLine.y1()+1;
	  }
	  else {
            newY1 = newX1<LFO2_FadeStartLine.x1() ? LFO2_EffectDownLine.y1()-1 : DownSlope*newX1+DownBeta-1;
            newY2 = newX2 > LFO2_FadeStartLine.x1() ? DownSlope*newX2+DownBeta-1 : LFO2_EffectDownLine.y2()-1;
	  }
	}
        if (newX2>= LFO2_FadeEndLine.x1()) {
            newX2 = LFO2_FadeEndLine.x1()-1;
            newY2 = 96;
        }
        dummy = LFO2_scene->addLine(newX1, newY1, newX2, newY2);
        dummy->setPen(WavePen);
        WaveLines << dummy;
        break;
    } // end switch
  } // end if Rate>0
}   // end LFO2_FillEffect

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

void JVlibForm::on_ToneEFX_TestTone_switch_toggled(bool val) {
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
//    buf[3] = 0xB0 + (state_table->perf_mode ? active_area->active_performance.perf_part[pn].MIDI_channel : 
//      system_area->sys_common.patch_receive_channel);
//    buf[4] = 0x79;
//    buf[5] = 0;
  if (open_ports() == EXIT_FAILURE) return;
  if (change_send(buf,3) == EXIT_FAILURE) { close_ports(); return; }
  close_ports();
  }
  ToneEFX_TestTone_switch->setText(val ? QString::fromUtf8("Stop") : QString::fromUtf8("Play Patch") );
  }
}	// end on_ToneEFX_TestTone_switch_toggled

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
  static QGraphicsLineItem *ptrLine;
  if (ptrLine) {
    ToneEFX_PanKeyFollow_scene->removeItem(ptrLine);
    ptrLine = 0;
  }
  switch(val) {
    case 0: // +100
        ptrLine = ToneEFX_PanKeyFollow_scene->addLine(10,110,345,10,redLine);
        break;
    case 1: // +70
        ptrLine = ToneEFX_PanKeyFollow_scene->addLine(10,103,345,17,redLine);
        break;
    case 2: // +50
        ptrLine = ToneEFX_PanKeyFollow_scene->addLine(10,95,345,24,redLine);
        break;
    case 3: // +40
        ptrLine = ToneEFX_PanKeyFollow_scene->addLine(10,88,345,31,redLine);
        break;
    case 4: // +30
        ptrLine = ToneEFX_PanKeyFollow_scene->addLine(10,81,345,38,redLine);
        break;
    case 5: // +20
        ptrLine = ToneEFX_PanKeyFollow_scene->addLine(10,74,345,45,redLine);
        break;
    case 6: // +10
        ptrLine = ToneEFX_PanKeyFollow_scene->addLine(10,67,345,52,redLine);
        break;
    case 7: // 0
        ptrLine = ToneEFX_PanKeyFollow_scene->addLine(10,60,345,60,redLine);
        break;
    case 8: // -10
        ptrLine = ToneEFX_PanKeyFollow_scene->addLine(10,52,345,67,redLine);
        break;
    case 9: // -20
        ptrLine = ToneEFX_PanKeyFollow_scene->addLine(10,45,345,74,redLine);
        break;
    case 10:    // -30
        ptrLine = ToneEFX_PanKeyFollow_scene->addLine(10,38,345,81,redLine);
        break;
    case 11:    // -40
        ptrLine = ToneEFX_PanKeyFollow_scene->addLine(10,31,345,88,redLine);
        break;
    case 12:    // -50
        ptrLine = ToneEFX_PanKeyFollow_scene->addLine(10,24,345,95,redLine);
        break;
    case 13:    // -70
        ptrLine = ToneEFX_PanKeyFollow_scene->addLine(10,17,345,103,redLine);
        break;
    case 14:    // -100
        ptrLine = ToneEFX_PanKeyFollow_scene->addLine(10,10,345,110,redLine);
        break;
  }	// end Switch
  ToneEFXStdUpdate(0x78, 14-val);
}	// end on_ToneEFX_PanKeyFollow_select_currentIndexChanged
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
  if (ToneEFX_LFO1Target_select->currentIndex() == 1) {
    on_ToneEFX_LFO1Delay_select_valueChanged(ToneEFX_LFO1Delay_select->value());
  }
  ToneEFXStdUpdate(0x7B, val+63);
}
void JVlibForm::on_ToneEFX_PanLFO2Depth_select_valueChanged(int val) {
  if (ToneEFX_LFO2Target_select->currentIndex() == 1) {
    on_ToneEFX_LFO2Delay_select_valueChanged(ToneEFX_LFO2Delay_select->value());
  }
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
  on_ToneEFX_LFO1Delay_select_valueChanged(ToneEFX_LFO1Delay_select->value());
  ToneEFXStdUpdate(0x2F, val);
}	// end on_ToneEFX_LFO1Rate_select_valueChanged

void JVlibForm::on_ToneEFX_LFO1LevelOffset_select_currentIndexChanged(int val) {
  ToneEFXStdUpdate(0x30, val);
}
void JVlibForm::on_ToneEFX_LFO1Delay_select_valueChanged(int val) {
    static QGraphicsLineItem *ptrFadeStartLine;
    qreal DelayVal = val/3;
    if (ptrFadeStartLine) {
        LFO1_scene->removeItem(ptrFadeStartLine);
        ptrFadeStartLine = 0;
    }
    if (LFO1_DelayText) {
        LFO1_scene->removeItem(LFO1_DelayText);
        LFO1_DelayText = 0;
    }
    if (val) LFO1_DelayText = LFO1_scene->addSimpleText(val>50?"Dly":"D");
    switch(ToneEFX_LFO1FadeMode_select->currentIndex()) {
    case 0:   // On-In
    case 1:
        DelayVal += 10;
        LFO1_FadeStartLine.setLine(DelayVal,10,DelayVal,160);
        if (LFO1_DelayText) LFO1_DelayText->setPos(val>50 ? LFO1_FadeStartLine.x1()/2 : LFO1_FadeStartLine.x1()/2+5,5);
        break;
    case 2:   // Off-In
        if (!LFO1_ptrOffLine) LFO1_setOffIn();
        DelayVal += LFO1_OffLine.x1();
        LFO1_FadeStartLine.setLine(DelayVal,10,DelayVal,160);
        if (LFO1_DelayText) LFO1_DelayText->setPos((LFO1_FadeStartLine.x1()+LFO1_OffLine.x1())/2-10,5);
      break;
    case 3:   // Off-Out
        if (!LFO1_ptrOffLine) LFO1_setOffOut();
        DelayVal += LFO1_OffLine.x1();
        LFO1_FadeStartLine.setLine(DelayVal,10,DelayVal,160);
        if (LFO1_DelayText) LFO1_DelayText->setPos((LFO1_FadeStartLine.x1()+LFO1_OffLine.x1())/2-10,5);
      break;
    } // end switch
    ptrFadeStartLine = LFO1_scene->addLine(LFO1_FadeStartLine,dotLine);
    if (state_table->updates_enabled) {
      state_table->updates_enabled = false;
      on_ToneEFX_LFO1FadeTime_select_valueChanged(ToneEFX_LFO1FadeTime_select->value());
      state_table->updates_enabled = true;
    } else {
      on_ToneEFX_LFO1FadeTime_select_valueChanged(ToneEFX_LFO1FadeTime_select->value());
    }      
  ToneEFXStdUpdate(0x31, val);
}	// end on_ToneEFX_LFO1Delay_select_valueChanged
void JVlibForm::on_ToneEFX_LFO1FadeMode_select_currentIndexChanged(int val) {
    if (LFO1_ptrOffLine) {
        LFO1_scene->removeItem(LFO1_ptrOffLine);
        LFO1_ptrOffLine = 0;
        LFO1_scene->removeItem(LFO1_OffText);
        LFO1_OffText = 0;
    }
    if (val == 2) LFO1_setOffIn();
    if (val == 3) LFO1_setOffOut();
    if (state_table->updates_enabled) {
      state_table->updates_enabled = false;
      on_ToneEFX_LFO1Delay_select_valueChanged(ToneEFX_LFO1Delay_select->value());
      state_table->updates_enabled = true;
    } else {
      on_ToneEFX_LFO1Delay_select_valueChanged(ToneEFX_LFO1Delay_select->value());
    }
  ToneEFXStdUpdate(0x32, val);
}	// end on_ToneEFX_LFO1FadeMode_select_currentIndexChanged
void JVlibForm::on_ToneEFX_LFO1FadeTime_select_valueChanged(int val) {
    static QGraphicsLineItem *ptrFadeEndLine;
    qreal FadeVal = val/3 + LFO1_FadeStartLine.x2();
    if (ptrFadeEndLine) {
        LFO1_scene->removeItem(ptrFadeEndLine);
        ptrFadeEndLine = 0;
    }
    if (LFO1_FadeText) {
        LFO1_scene->removeItem(LFO1_FadeText);
        LFO1_FadeText = 0;
    }
    if (LFO1_ptrFadeUp) {
        LFO1_scene->removeItem(LFO1_ptrFadeUp);
        LFO1_ptrFadeUp = 0;
    }
    if (LFO1_ptrFadeDown) {
        LFO1_scene->removeItem(LFO1_ptrFadeDown);
        LFO1_ptrFadeDown = 0;
    }
    if (LFO1_ptrEffectUp) {
        LFO1_scene->removeItem(LFO1_ptrEffectUp);
        LFO1_ptrEffectUp = 0;
    }
    if (LFO1_ptrEffectDown) {
        LFO1_scene->removeItem(LFO1_ptrEffectDown);
        LFO1_ptrEffectDown = 0;
    }
    LFO1_FadeEndLine.setLine(FadeVal,10,FadeVal,160);
    ptrFadeEndLine = LFO1_scene->addLine(LFO1_FadeEndLine,dotLine);
    int thisDepth = 0;
    switch(ToneEFX_LFO1Target_select->currentIndex()) {
      case 0:
	thisDepth = Pitch_LFO1Depth_select->value();
	break;
      case 1:
	thisDepth = ToneEFX_PanLFO1Depth_select->value();
	break;
      case 2:
	thisDepth = ToneTVA_LFO1Depth_select->value();
	break;
      case 3:
	thisDepth = ToneTVF_LFO1Depth_select->value();
	break;
    }
    switch(ToneEFX_LFO1FadeMode_select->currentIndex()) {
      case 0:
      case 2:
          LFO1_FadeUpLine.setLine(LFO1_FadeStartLine.x1(), 96, LFO1_FadeEndLine.x1(), 96-abs(thisDepth));
          LFO1_FadeDownLine.setLine(LFO1_FadeStartLine.x1(), 96, LFO1_FadeEndLine.x1(), 96+abs(thisDepth));
          LFO1_EffectUpLine.setLine(LFO1_FadeEndLine.x2(), LFO1_FadeUpLine.y2(), 140, LFO1_FadeUpLine.y2());
          LFO1_EffectDownLine.setLine(LFO1_FadeEndLine.x2(), LFO1_FadeDownLine.y2(), 140, LFO1_FadeDownLine.y2());
          break;
      case 1:
      case 3:
          LFO1_FadeUpLine.setLine(LFO1_FadeStartLine.x1(), 96-abs(thisDepth), LFO1_FadeEndLine.x1(), 96);
          LFO1_FadeDownLine.setLine(LFO1_FadeStartLine.x1(), 96+abs(thisDepth), LFO1_FadeEndLine.x1(), 96);
          LFO1_EffectUpLine.setLine(10, LFO1_FadeUpLine.y1(), LFO1_FadeStartLine.x1(), LFO1_FadeUpLine.y1());
          LFO1_EffectDownLine.setLine(10, LFO1_FadeDownLine.y1(), LFO1_FadeStartLine.x1(), LFO1_FadeDownLine.y1());
          break;
    } // end switch
    if (val) {
        LFO1_FadeText = LFO1_scene->addSimpleText(val>50?"Fade":"F");
        LFO1_FadeText->setPos(val>50 ? (LFO1_FadeEndLine.x1()+LFO1_FadeStartLine.x1())/2-10 : (LFO1_FadeEndLine.x1()+LFO1_FadeStartLine.x1())/2,5);
    }
    LFO1_ptrFadeUp = LFO1_scene->addLine(LFO1_FadeUpLine,redLine);
    LFO1_ptrFadeDown = LFO1_scene->addLine(LFO1_FadeDownLine,redLine);
    LFO1_ptrEffectUp = LFO1_scene->addLine(LFO1_EffectUpLine,redLine);
    LFO1_ptrEffectDown = LFO1_scene->addLine(LFO1_EffectDownLine,redLine);
    LFO1_FillEffect();
  ToneEFXStdUpdate(0x33, val);
}	// end on_ToneEFX_LFO1FadeTime_select_valueChanged

void JVlibForm::on_ToneEFX_LFO1ExtSync_select_currentIndexChanged(int val) {
    ToneEFXStdUpdate(0x34, val);
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
  on_ToneEFX_LFO2Delay_select_valueChanged(ToneEFX_LFO2Delay_select->value());
  ToneEFXStdUpdate(0x37, val);
}	// end on_ToneEFX_LFO2Rate_select_valueChanged

void JVlibForm::on_ToneEFX_LFO2LevelOffset_select_currentIndexChanged(int val) {
  ToneEFXStdUpdate(0x38, val);
}
void JVlibForm::on_ToneEFX_LFO2Delay_select_valueChanged(int val) {
    static QGraphicsLineItem *ptrFadeStartLine;
    qreal DelayVal = val/3;
    if (ptrFadeStartLine) {
        LFO2_scene->removeItem(ptrFadeStartLine);
        ptrFadeStartLine = 0;
    }
    if (LFO2_DelayText) {
        LFO2_scene->removeItem(LFO2_DelayText);
        LFO2_DelayText = 0;
    }
    if (val) LFO2_DelayText = LFO2_scene->addSimpleText(val>50?"Dly":"D");
    switch(ToneEFX_LFO2FadeMode_select->currentIndex()) {
    case 0:   // On-In
    case 1:
        DelayVal += 10;
        LFO2_FadeStartLine.setLine(DelayVal,10,DelayVal,160);
        if (LFO2_DelayText) LFO2_DelayText->setPos(val>50 ? LFO2_FadeStartLine.x1()/2 : LFO2_FadeStartLine.x1()/2+5,5);
        break;
    case 2:   // Off-In
        if (!LFO2_ptrOffLine) LFO2_setOffIn();
        DelayVal += LFO2_OffLine.x1();
        LFO2_FadeStartLine.setLine(DelayVal,10,DelayVal,160);
        if (LFO2_DelayText) LFO2_DelayText->setPos((LFO2_FadeStartLine.x1()+LFO2_OffLine.x1())/2-10,5);
      break;
    case 3:   // Off-Out
        if (!LFO2_ptrOffLine) LFO2_setOffOut();
        DelayVal += LFO2_OffLine.x1();
        LFO2_FadeStartLine.setLine(DelayVal,10,DelayVal,160);
        if (LFO2_DelayText) LFO2_DelayText->setPos((LFO2_FadeStartLine.x1()+LFO2_OffLine.x1())/2-10,5);
      break;
    } // end switch
    ptrFadeStartLine = LFO2_scene->addLine(LFO2_FadeStartLine,dotLine);
    if (state_table->updates_enabled) {
      state_table->updates_enabled = false;
      on_ToneEFX_LFO2FadeTime_select_valueChanged(ToneEFX_LFO2FadeTime_select->value());
      state_table->updates_enabled = true;
    } else {
      on_ToneEFX_LFO2FadeTime_select_valueChanged(ToneEFX_LFO2FadeTime_select->value());
    }      
  ToneEFXStdUpdate(0x39, val);
}
void JVlibForm::on_ToneEFX_LFO2FadeMode_select_currentIndexChanged(int val) {
    if (LFO2_ptrOffLine) {
        LFO2_scene->removeItem(LFO2_ptrOffLine);
        LFO2_ptrOffLine = 0;
        LFO2_scene->removeItem(LFO2_OffText);
        LFO2_OffText = 0;
    }
    if (val == 2) LFO2_setOffIn();
    if (val == 3) LFO2_setOffOut();
    if (state_table->updates_enabled) {
      state_table->updates_enabled = false;
      on_ToneEFX_LFO2Delay_select_valueChanged(ToneEFX_LFO2Delay_select->value());
      state_table->updates_enabled = true;
    } else {
      on_ToneEFX_LFO2Delay_select_valueChanged(ToneEFX_LFO2Delay_select->value());
    }
  ToneEFXStdUpdate(0x3A, val);
}	// end on_ToneEFX_LFO2FadeMode_select_currentIndexChanged

void JVlibForm::on_ToneEFX_LFO2FadeTime_select_valueChanged(int val) {
    static QGraphicsLineItem *ptrFadeEndLine;
    qreal FadeVal = val/3 + LFO2_FadeStartLine.x2();
    if (ptrFadeEndLine) {
        LFO2_scene->removeItem(ptrFadeEndLine);
        ptrFadeEndLine = 0;
    }
    if (LFO2_FadeText) {
        LFO2_scene->removeItem(LFO2_FadeText);
        LFO2_FadeText = 0;
    }
    if (LFO2_ptrFadeUp) {
        LFO2_scene->removeItem(LFO2_ptrFadeUp);
        LFO2_ptrFadeUp = 0;
    }
    if (LFO2_ptrFadeDown) {
        LFO2_scene->removeItem(LFO2_ptrFadeDown);
        LFO2_ptrFadeDown = 0;
    }
    if (LFO2_ptrEffectUp) {
        LFO2_scene->removeItem(LFO2_ptrEffectUp);
        LFO2_ptrEffectUp = 0;
    }
    if (LFO2_ptrEffectDown) {
        LFO2_scene->removeItem(LFO2_ptrEffectDown);
        LFO2_ptrEffectDown = 0;
    }
    LFO2_FadeEndLine.setLine(FadeVal,10,FadeVal,160);
    ptrFadeEndLine = LFO2_scene->addLine(LFO2_FadeEndLine,dotLine);
    int thisDepth = 0;
    switch(ToneEFX_LFO2Target_select->currentIndex()) {
      case 0:
	thisDepth = Pitch_LFO2Depth_select->value();
	break;
      case 1:
	thisDepth = ToneEFX_PanLFO2Depth_select->value();
	break;
      case 2:
	thisDepth = ToneTVA_LFO2Depth_select->value();
	break;
      case 3:
	thisDepth = ToneTVF_LFO2Depth_select->value();
	break;
    }
    switch(ToneEFX_LFO2FadeMode_select->currentIndex()) {
      case 0:
      case 2:
          LFO2_FadeUpLine.setLine(LFO2_FadeStartLine.x1(), 96, LFO2_FadeEndLine.x1(), 96-abs(thisDepth));
          LFO2_FadeDownLine.setLine(LFO2_FadeStartLine.x1(), 96, LFO2_FadeEndLine.x1(), 96+abs(thisDepth));
          LFO2_EffectUpLine.setLine(LFO2_FadeEndLine.x2(), LFO2_FadeUpLine.y2(), 140, LFO2_FadeUpLine.y2());
          LFO2_EffectDownLine.setLine(LFO2_FadeEndLine.x2(), LFO2_FadeDownLine.y2(), 140, LFO2_FadeDownLine.y2());
          break;
      case 1:
      case 3:
          LFO2_FadeUpLine.setLine(LFO2_FadeStartLine.x1(), 96-abs(thisDepth), LFO2_FadeEndLine.x1(), 96);
          LFO2_FadeDownLine.setLine(LFO2_FadeStartLine.x1(), 96+abs(thisDepth), LFO2_FadeEndLine.x1(), 96);
          LFO2_EffectUpLine.setLine(10, LFO2_FadeUpLine.y1(), LFO2_FadeStartLine.x1(), LFO2_FadeUpLine.y1());
          LFO2_EffectDownLine.setLine(10, LFO2_FadeDownLine.y1(), LFO2_FadeStartLine.x1(), LFO2_FadeDownLine.y1());
          break;
    } // end switch
    if (val) {
        LFO2_FadeText = LFO2_scene->addSimpleText(val>50?"Fade":"F");
        LFO2_FadeText->setPos(val>50 ? (LFO2_FadeEndLine.x1()+LFO2_FadeStartLine.x1())/2-10 : (LFO2_FadeEndLine.x1()+LFO2_FadeStartLine.x1())/2,5);
    }
    LFO2_ptrFadeUp = LFO2_scene->addLine(LFO2_FadeUpLine,redLine);
    LFO2_ptrFadeDown = LFO2_scene->addLine(LFO2_FadeDownLine,redLine);
    LFO2_ptrEffectUp = LFO2_scene->addLine(LFO2_EffectUpLine,redLine);
    LFO2_ptrEffectDown = LFO2_scene->addLine(LFO2_EffectDownLine,redLine);
    LFO2_FillEffect();
  ToneEFXStdUpdate(0x3B, val);
}	// end on_ToneEFX_LFO2FadeTime_select_valueChanged

void JVlibForm::on_ToneEFX_LFO2ExtSync_select_currentIndexChanged(int val) {
  if (state_table->updates_enabled) {
    state_table->updates_enabled=false;
    on_ToneEFX_LFO2Rate_select_valueChanged(ToneEFX_LFO2Rate_select->value());
    state_table->updates_enabled=true;
    ToneEFXStdUpdate(0x3C, val);
  }
}	// end on_ToneEFX_LFO2ExtSync_select_currentIndexChanged

void JVlibForm::on_ToneEFX_LFO1Target_select_currentIndexChanged() {
    on_ToneEFX_LFO1Delay_select_valueChanged(ToneEFX_LFO1Delay_select->value());
}
void JVlibForm::on_ToneEFX_LFO2Target_select_currentIndexChanged() {
    on_ToneEFX_LFO2Delay_select_valueChanged(ToneEFX_LFO2Delay_select->value());
}
