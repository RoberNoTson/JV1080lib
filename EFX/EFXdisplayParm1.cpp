// EFXdisplayParm1.cpp
// procedures to display Parm 1 for all possible EFX types, and update the synth
// called from EFX_slots when the on-screen value changes for Parm 1
// uses switch/case to determine how to display the value, based on the EFX type currently selected

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setEFXdisplayParm_1() {
//  switch(SysMode_select->currentIndex()==0 ? PerfEFXtype_select->currentIndex() : PatchEFX_Type_select->currentIndex()) {
  switch(MainTabWidget->currentIndex()==1 ? PerfEFXtype_select->currentIndex() : PatchEFX_Type_select->currentIndex()) {
    case 0:	// Stereo EQ
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm1_display->setText(QString::number((PerfEFXparm1_select->value()+1)*200));
      else
	PatchEFX_parm1_display->setText(QString::number(( PatchEFX_parm1_select->value() +1)*200));
      break;
      
    case 1: 
    case 2: 
    case 5: 
    case 8: 
    case 9: 
    case 12:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm1_display->setText(QString::number(PerfEFXparm1_select->value()));
      else
	PatchEFX_parm1_display->setText(QString::number(PatchEFX_parm1_select->value()));
      break;
      
    case 3:	// Phaser
      // 100 to 300 by 10/300 to 1000 by 20/1000 to 8000 by 100
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm1_select->value()<20)
	PerfEFXparm1_display->setText(QString::number((PerfEFXparm1_select->value()*10)+100));
      else if (PerfEFXparm1_select->value()<55)
	PerfEFXparm1_display->setText(QString::number(((PerfEFXparm1_select->value()-20)*20)+300));
      else
	PerfEFXparm1_display->setText(QString::number(((PerfEFXparm1_select->value()-55)*100)+1000));
      } else {
      if (PatchEFX_parm1_select->value()<20)
	PatchEFX_parm1_display->setText(QString::number((PatchEFX_parm1_select->value()*10)+100));
      else if (PatchEFX_parm1_select->value()<55)
	PatchEFX_parm1_display->setText(QString::number(((PatchEFX_parm1_select->value()-20)*20)+300));
      else
	PatchEFX_parm1_display->setText(QString::number(((PatchEFX_parm1_select->value()-55)*100)+1000));
      }
      break;
      
    case 4:	// Spectrum
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm1_display->setText(QString::number(PerfEFXparm1_select->value()-15));
      else
	PatchEFX_parm1_display->setText(QString::number(PatchEFX_parm1_select->value()-15));
      break;
      
    case 6:	// Auto-Wah
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm1_display->setText(PerfEFXparm1_select->value()?QString("Band Pass Filter"):QString("Low Pass Filter"));
      else
	PatchEFX_parm1_display->setText(PatchEFX_parm1_select->value()?QString("Band Pass Filter"):QString("Low Pass Filter"));
      break;
      
    case 7:	// Rotary
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm1_select->value()<99)
	PerfEFXparm1_display->setText(QString::number((PerfEFXparm1_select->value()*0.05 )+0.05));
      else if (PerfEFXparm1_select->value()<119)
	PerfEFXparm1_display->setText(QString::number(((PerfEFXparm1_select->value()-99)*0.1)+5));
      else
	PerfEFXparm1_display->setText(QString::number(((PerfEFXparm1_select->value()-119)*0.5)+7));
      } else {
      if (PatchEFX_parm1_select->value()<99)
	PatchEFX_parm1_display->setText(QString::number((PatchEFX_parm1_select->value()*0.05 )+0.05));
      else if (PatchEFX_parm1_select->value()<119)
	PatchEFX_parm1_display->setText(QString::number(((PatchEFX_parm1_select->value()-99)*0.1)+5));
      else
	PatchEFX_parm1_display->setText(QString::number(((PatchEFX_parm1_select->value()-119)*0.5)+7));	
      }
      break;
      
    case 10: 
    case 11:	// Hexa-Chorus
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm1_select->value()<50)
	PerfEFXparm1_display->setText(QString::number((PerfEFXparm1_select->value()*0.1)));
      else if (PerfEFXparm1_select->value()<60)
	PerfEFXparm1_display->setText(QString::number(((PerfEFXparm1_select->value()-70)*0.5)+5));
      else if (PerfEFXparm1_select->value()<110)
	PerfEFXparm1_display->setText(QString::number(((PerfEFXparm1_select->value()-70))+10));
      else
	PerfEFXparm1_display->setText(QString::number(((PerfEFXparm1_select->value()-110)*2)+50));
      } else {
      if (PatchEFX_parm1_select->value()<50)
	PatchEFX_parm1_display->setText(QString::number((PatchEFX_parm1_select->value()*0.1)));
      else if (PatchEFX_parm1_select->value()<60)
	PatchEFX_parm1_display->setText(QString::number(((PatchEFX_parm1_select->value()-70)*0.5)+5));
      else if (PatchEFX_parm1_select->value()<110)
	PatchEFX_parm1_display->setText(QString::number(((PatchEFX_parm1_select->value()-70))+10));
      else
	PatchEFX_parm1_display->setText(QString::number(((PatchEFX_parm1_select->value()-110)*2)+50));
      }
      break;
      
    case 13: 
    case 14:	// Stereo-Chorus
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm1_select->value()==0)
	PerfEFXparm1_display->setText(QString("Off"));
      if (PerfEFXparm1_select->value()==1)
	PerfEFXparm1_display->setText(QString("LowPass Filter"));
      if (PerfEFXparm1_select->value()==2)
	PerfEFXparm1_display->setText(QString("HighPass Filter"));
      } else {
      if (PatchEFX_parm1_select->value()==0)
	PatchEFX_parm1_display->setText(QString("Off"));
      if (PatchEFX_parm1_select->value()==1)
	PatchEFX_parm1_display->setText(QString("LowPass Filter"));
      if (PatchEFX_parm1_select->value()==2)
	PatchEFX_parm1_display->setText(QString("HighPass Filter"));
      }
      break;
      
    case 15:
      // 0 to 5.0 by 0.1/5.0 to 10.0 by 0.5/10 to 50 by 1/50 to 100 by 2
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm1_select->value()<50)
	PerfEFXparm1_display->setText(QString::number((PerfEFXparm1_select->value()*0.1)));
      else if (PerfEFXparm1_select->value()<60)
	PerfEFXparm1_display->setText(QString::number(((PerfEFXparm1_select->value()-70)*0.5)+5));
      else if (PerfEFXparm1_select->value()<110)
	PerfEFXparm1_display->setText(QString::number(((PerfEFXparm1_select->value()-70))+10));
      else
	PerfEFXparm1_display->setText(QString::number(((PerfEFXparm1_select->value()-110)*2)+50));
      } else {
      if (PatchEFX_parm1_select->value()<50)
	PatchEFX_parm1_display->setText(QString::number((PatchEFX_parm1_select->value()*0.1)));
      else if (PatchEFX_parm1_select->value()<60)
	PatchEFX_parm1_display->setText(QString::number(((PatchEFX_parm1_select->value()-70)*0.5)+5));
      else if (PatchEFX_parm1_select->value()<110)
	PatchEFX_parm1_display->setText(QString::number(((PatchEFX_parm1_select->value()-70))+10));
      else
	PatchEFX_parm1_display->setText(QString::number(((PatchEFX_parm1_select->value()-110)*2)+50));
      }
      break;

    case 16: 
    case 17:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm1_display->setText(PerfEFXparm1_select->value()?QString("Cross"):QString("Normal"));
      else
	PatchEFX_parm1_display->setText(PatchEFX_parm1_select->value()?QString("Cross"):QString("Normal"));
      break;

    case 18: 
    case 19:
    // 200 to 550 by 5/550 to 1000 by 10
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm1_select->value()< 70)
	PerfEFXparm1_display->setText(QString::number(PerfEFXparm1_select->value()*5+200));
      else
	PerfEFXparm1_display->setText(QString::number((PerfEFXparm1_select->value()-70)*10+550));
      } else {
      if (PatchEFX_parm1_select->value()< 70)
	PatchEFX_parm1_display->setText(QString::number(PatchEFX_parm1_select->value()*5+200));
      else
	PatchEFX_parm1_display->setText(QString::number((PatchEFX_parm1_select->value()-70)*10+550));
      }
      break;
      
    case 20:
    // 200 to 600 by 5/ 600 to 1000 by 10
      if (MainTabWidget->currentIndex()==1) {
	if (PerfEFXparm1_select->value()< 80)
	  PerfEFXparm1_display->setText(QString::number(PerfEFXparm1_select->value()*5+200));
	else
	  PerfEFXparm1_display->setText(QString::number((PerfEFXparm1_select->value()-80)*10+600));
      } else {
      if (PatchEFX_parm1_select->value()< 80)
	PatchEFX_parm1_display->setText(QString::number(PatchEFX_parm1_select->value()*5+200));
      else
	PatchEFX_parm1_display->setText(QString::number((PatchEFX_parm1_select->value()-80)*10+600));
      }
      break;
      
    case 21:
    case 22:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm1_display->setText(QString::number(PerfEFXparm1_select->value()+1));
      else
	PatchEFX_parm1_display->setText(QString::number(PatchEFX_parm1_select->value()+1));
      break;
    
    case 23:
      if (MainTabWidget->currentIndex()==1) {
      switch(PerfEFXparm1_select->value()) {
	case 0:
	  PerfEFXparm1_display->setText(QString("Room1"));
	  break;
	case 1:
	  PerfEFXparm1_display->setText(QString("Room2"));
	  break;	  
	case 2:
	  PerfEFXparm1_display->setText(QString("Stage1"));
	  break;
	case 3:
	  PerfEFXparm1_display->setText(QString("Stage2"));
	  break;
	case 4:
	  PerfEFXparm1_display->setText(QString("Hall1"));
	  break;
	case 5:
	  PerfEFXparm1_display->setText(QString("Hall2"));
	  break;
      }
      } else {
      switch(PatchEFX_parm1_select->value()) {
	case 0:
	  PatchEFX_parm1_display->setText(QString("Room1"));
	break;
	case 1:
	  PatchEFX_parm1_display->setText(QString("Room2"));
	break;
	case 2:
	  PatchEFX_parm1_display->setText(QString("Stage1"));
	break;
	case 3:
	  PatchEFX_parm1_display->setText(QString("Stage2"));
	break;
	case 4:
	  PatchEFX_parm1_display->setText(QString("Hall1"));
	break;
	case 5:
	  PatchEFX_parm1_display->setText(QString("Hall2"));
	break;
      }
      }
      break;
      
    case 24:
      if (MainTabWidget->currentIndex()==1) {
      switch(PerfEFXparm1_select->value()) {
	case 0:
	  PerfEFXparm1_display->setText(QString("Normal"));
	  break;
	case 1:
	  PerfEFXparm1_display->setText(QString("Reverse"));
	  break;	  
	case 2:
	  PerfEFXparm1_display->setText(QString("Sweep1"));
	  break;
	case 3:
	  PerfEFXparm1_display->setText(QString("Sweep2"));
	  break;
      }
      } else {
      switch(PatchEFX_parm1_select->value()) {
	case 0:
	  PatchEFX_parm1_display->setText(QString("Normal"));
	break;
	case 1:
	  PatchEFX_parm1_display->setText(QString("Reverse"));
	break;
	case 2:
	  PatchEFX_parm1_display->setText(QString("Sweep1"));
	break;
	case 3:
	  PatchEFX_parm1_display->setText(QString("Sweep2"));
	break;
      }
      }
      break;
      
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm1_display->setText(QString::number(PerfEFXparm1_select->value()));
      else
	PatchEFX_parm1_display->setText(QString::number(PatchEFX_parm1_select->value()));
      break;
      
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    // 0 to 5.0 by 0.1/5.0 to 10.0 by 0.5/10 to 50 by 1/50 to 100 by 2
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm1_select->value()<50)
	PerfEFXparm1_display->setText(QString::number((PerfEFXparm1_select->value()*0.1)));
      else if (PerfEFXparm1_select->value()<60)
	PerfEFXparm1_display->setText(QString::number(((PerfEFXparm1_select->value()-70)*0.5)+5));
      else if (PerfEFXparm1_select->value()<110)
	PerfEFXparm1_display->setText(QString::number(((PerfEFXparm1_select->value()-70))+10));
      else
	PerfEFXparm1_display->setText(QString::number(((PerfEFXparm1_select->value()-110)*2)+50));
      } else {
      if (PatchEFX_parm1_select->value()<50)
	PatchEFX_parm1_display->setText(QString::number((PatchEFX_parm1_select->value()*0.1)));
      else if (PatchEFX_parm1_select->value()<60)
	PatchEFX_parm1_display->setText(QString::number(((PatchEFX_parm1_select->value()-70)*0.5)+5));
      else if (PatchEFX_parm1_select->value()<110)
	PatchEFX_parm1_display->setText(QString::number(((PatchEFX_parm1_select->value()-70))+10));
      else
	PatchEFX_parm1_display->setText(QString::number(((PatchEFX_parm1_select->value()-110)*2)+50));
      }
      break;

    default:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm1_display->clear();
      else
	PatchEFX_parm1_display->clear();
      break;
  }	// end SWITCH
// update the SYNTH
  if (state_table->jv_connect && state_table->updates_enabled) {
  if (MainTabWidget->currentIndex()==1)
    setPerfSingleValue(0xE + 0,PerfEFXparm1_select->value());
  else
    setPatchSingleValue(0xD + 0,PatchEFX_parm1_select->value());
  }
}	// end setEFXdisplayParm_1
