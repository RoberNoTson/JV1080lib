// EFXdisplayParm3.cpp
//  display EFXparm 3 as appropriate for the selecte EFX type
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setEFXdisplayParm_3() {
  switch(MainTabWidget->currentIndex()==1 ? PerfEFXtype_select->currentIndex() : PatchEFX_Type_select->currentIndex()) {
    case 0:	// Stereo EQ
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm3_display->setText(QString::number((PerfEFXparm3_select->value()+1)*4000));
      else
	PatchEFX_parm3_display->setText(QString::number((PatchEFX_parm3_select->value()+1)*4000));
      break;
      
    case 1: 
    case 2:	// Overdrive // Distortion
      if (MainTabWidget->currentIndex()==1) {
      switch(PerfEFXparm3_select->value()) {
        case 0:
          PerfEFXparm3_display->setText(QString("Small"));
          break;
        case 1:
          PerfEFXparm3_display->setText(QString("Built-In"));
          break;
        case 2:
          PerfEFXparm3_display->setText(QString("2 Stack"));
          break;
        case 3:
          PerfEFXparm3_display->setText(QString("3 Stack"));
          break;
      }
      } else {
      switch(PatchEFX_parm3_select->value()) {
        case 0:
          PatchEFX_parm3_display->setText(QString("Small"));
          break;
        case 1:
          PatchEFX_parm3_display->setText(QString("Built-In"));
          break;
        case 2:
          PatchEFX_parm3_display->setText(QString("2 Stack"));
          break;
        case 3:
          PatchEFX_parm3_display->setText(QString("3 Stack"));
          break;
      }	// end SWITCH
      }
      break;
      
    case 3: 
    case 15:	// Phaser 
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm3_display->setText(QString::number(PerfEFXparm3_select->value()) );
      else
	PatchEFX_parm3_display->setText(QString::number(PerfEFXparm3_select->value()) );
      break;
      
    case 4: 
    case 5:	// Spectrum	// Enhancer
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm3_display->setText(QString::number(PerfEFXparm3_select->value()-15 ) );
      else
	PatchEFX_parm3_display->setText(QString::number(PatchEFX_parm3_select->value()-15 ) );
      break;
      
    case 6:	// Auto-Wah
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm3_display->setText(QString::number(PerfEFXparm3_select->value()));
      else
	PatchEFX_parm3_display->setText(QString::number(PatchEFX_parm3_select->value()));
      break;
      
    case 7:
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm3_select->value()<99)
	PerfEFXparm3_display->setText(QString::number((PerfEFXparm3_select->value()*0.05 )+0.05));
      else if (PerfEFXparm3_select->value()<119)
	PerfEFXparm3_display->setText(QString::number(((PerfEFXparm3_select->value()-99)*0.1)+5));
      else
	PerfEFXparm3_display->setText(QString::number(((PerfEFXparm3_select->value()-119)*0.5)+7));
      } else {
      if (PatchEFX_parm3_select->value()<99)
	PatchEFX_parm3_display->setText(QString::number((PatchEFX_parm3_select->value()*0.05 )+0.05));
      else if (PatchEFX_parm3_select->value()<119)
	PatchEFX_parm3_display->setText(QString::number(((PatchEFX_parm3_select->value()-99)*0.1)+5));
      else
	PatchEFX_parm3_display->setText(QString::number(((PatchEFX_parm3_select->value()-119)*0.5)+7));
      }
      break;
      
    case 8:
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm3_select->value()==64) 
	PerfEFXparm3_display->setText(QString("Center"));
      if (PerfEFXparm3_select->value()<64) 
	PerfEFXparm3_display->setText(QString("Left ")+QString::number((64-PerfEFXparm3_select->value())*90/64)+QString(" Deg."));
      if (PerfEFXparm3_select->value()>64) 
	PerfEFXparm3_display->setText(QString("Right ")+QString::number((PerfEFXparm3_select->value()-63)*90/64)+QString(" Deg."));
      } else {
      if (PatchEFX_parm3_select->value()==64) 
	PatchEFX_parm3_display->setText(QString("Center"));
      if (PatchEFX_parm3_select->value()<64) 
	PatchEFX_parm3_display->setText(QString("Left ")+QString::number((64-PatchEFX_parm3_select->value())*90/64)+QString(" Deg."));
      if (PatchEFX_parm3_select->value()>64) 
	PatchEFX_parm3_display->setText(QString("Right ")+QString::number((PatchEFX_parm3_select->value()-63)*90/64)+QString(" Deg."));
      }
      break;
      
    case 9:
      if (MainTabWidget->currentIndex()==1) {
      switch(PerfEFXparm3_select->value()) {
	case 0:
	  PerfEFXparm3_display->setText(QString::number(1.5));
	  break;
	case 1:
	  PerfEFXparm3_display->setText(QString::number(2));
	  break;
	case 2:
	  PerfEFXparm3_display->setText(QString::number(4));
	  break;
	case 3:
	  PerfEFXparm3_display->setText(QString::number(100));
	  break;
      }
      } else {
      switch(PatchEFX_parm3_select->value()) {
	case 0:
	  PatchEFX_parm3_display->setText(QString::number(1.5));
	  break;
	case 1:
	  PatchEFX_parm3_display->setText(QString::number(2));
	  break;
	case 2:
	  PatchEFX_parm3_display->setText(QString::number(4));
	  break;
	case 3:
	  PatchEFX_parm3_display->setText(QString::number(100));
	  break;
      }
      }
      break;
      
    case 10: 
    case 11: 
    case 12:
    case 20:
    case 23:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm3_display->setText(QString::number(PerfEFXparm3_select->value()));
      else
	PatchEFX_parm3_display->setText(QString::number(PatchEFX_parm3_select->value()));
      break;
      
    case 13: 
    case 14:	// Stereo-Chorus Stereo-Flanger
    case 25:
    case 26:
    case 31:
    case 32:
    case 28:
    case 29:
    // 0 to 5.0 by 0.1/5.0 to 10.0 by 0.5/10 to 50 by 1/50 to 100 by 2
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm3_select->value()<50)
        PerfEFXparm3_display->setText(QString::number((PerfEFXparm3_select->value()*0.1)));
      else if (PerfEFXparm3_select->value()<60)
        PerfEFXparm3_display->setText(QString::number(((PerfEFXparm3_select->value()-70)*0.5)+5));
      else if (PerfEFXparm3_select->value()<110)
        PerfEFXparm3_display->setText(QString::number(((PerfEFXparm3_select->value()-70))+10));
      else
        PerfEFXparm3_display->setText(QString::number(((PerfEFXparm3_select->value()-110)*2)+50));
      } else {
      if (PatchEFX_parm3_select->value()<50)
        PatchEFX_parm3_display->setText(QString::number((PatchEFX_parm3_select->value()*0.1)));
      else if (PatchEFX_parm3_select->value()<60)
        PatchEFX_parm3_display->setText(QString::number(((PatchEFX_parm3_select->value()-70)*0.5)+5));
      else if (PatchEFX_parm3_select->value()<110)
        PatchEFX_parm3_display->setText(QString::number(((PatchEFX_parm3_select->value()-70))+10));
      else
        PatchEFX_parm3_display->setText(QString::number(((PatchEFX_parm3_select->value()-110)*2)+50));
      }
      break;
      
    case 16: 
    case 17:
    case 27:
    case 30:
    case 33:
    // 0 to 5.0 by 0.1/5.0 to 10.0 by 0.5/10 to 40 by 1/40 to 300 by 10/300 to 500  by 20
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm3_select->value()<50)
	PerfEFXparm3_display->setText(QString::number((PerfEFXparm3_select->value()*0.1)));
      else if (PerfEFXparm3_select->value()<60)
	PerfEFXparm3_display->setText(QString::number(((PerfEFXparm3_select->value()-50)*0.5)+5));
      else if (PerfEFXparm3_select->value()<90)
	PerfEFXparm3_display->setText(QString::number(((PerfEFXparm3_select->value()-60)*1)+10));
      else if (PerfEFXparm3_select->value()<116)
	PerfEFXparm3_display->setText(QString::number(((PerfEFXparm3_select->value()-90)*10)+40));
      else
	PerfEFXparm3_display->setText(QString::number(((PerfEFXparm3_select->value()-116)*20)+300));
      } else {
      if (PatchEFX_parm3_select->value()<50)
	PatchEFX_parm3_display->setText(QString::number((PatchEFX_parm3_select->value()*0.1)));
      else if (PatchEFX_parm3_select->value()<60)
	PatchEFX_parm3_display->setText(QString::number(((PatchEFX_parm3_select->value()-50)*0.5)+5));
      else if (PatchEFX_parm3_select->value()<90)
	PatchEFX_parm3_display->setText(QString::number(((PatchEFX_parm3_select->value()-60)*1)+10));
      else if (PatchEFX_parm3_select->value()<116)
	PatchEFX_parm3_display->setText(QString::number(((PatchEFX_parm3_select->value()-90)*10)+40));
      else
	PerfEFXparm3_display->setText(QString::number(((PerfEFXparm3_select->value()-116)*20)+300));
      }
      break;
      
    case 18: 
    case 19:
      // 200 to 550 by 5/550 to 1000 by 10
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm3_select->value()<70)
	PerfEFXparm3_display->setText(QString::number(PerfEFXparm3_select->value()*5+200));
      else
	PerfEFXparm3_display->setText(QString::number((PerfEFXparm3_select->value()-70)*10+550));
      } else {
      if (PatchEFX_parm3_select->value()<70)
	PatchEFX_parm3_display->setText(QString::number(PatchEFX_parm3_select->value()*5+200));
      else
	PatchEFX_parm3_display->setText(QString::number((PatchEFX_parm3_select->value()-70)*10+550));
      }
      break;
      
    case 21:
    // -24 to +12 by 1
      if (MainTabWidget->currentIndex()==1)
        PerfEFXparm3_display->setText(QString::number(PerfEFXparm3_select->value()-24));
      else
	PatchEFX_parm3_display->setText(QString::number(PatchEFX_parm3_select->value()-24));
      break;

    case 22:
    // -100 to +100 by 2
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm3_display->setText(QString::number((PerfEFXparm3_select->value()*2)-100));
      else
	PatchEFX_parm3_display->setText(QString::number((PatchEFX_parm3_select->value()*2)-100));
      break;

    case 24:
    // 5 to 500 by 5
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm3_display->setText(QString::number((PerfEFXparm3_select->value()+1)*5));
      else
	PatchEFX_parm3_display->setText(QString::number((PatchEFX_parm3_select->value()+1)*5));
      break;
      
    default:
      if (MainTabWidget->currentIndex()==1)
        PerfEFXparm3_display->clear();
      else
	PatchEFX_parm3_display->clear();
      break;
  }
  if (state_table->jv_connect && state_table->updates_enabled) {
  if (MainTabWidget->currentIndex()==1)
    setPerfSingleValue(0xE + 2,PerfEFXparm3_select->value());
  else
    setPatchSingleValue(0xD + 2,PatchEFX_parm3_select->value());
  }
}
