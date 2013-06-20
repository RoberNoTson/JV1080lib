// EFXdisplayParm2.cpp
// procedures to display Parm 2 for all possible EFX types
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setEFXdisplayParm_2() {
  switch(MainTabWidget->currentIndex()==1 ? PerfEFXtype_select->currentIndex() : PatchEFX_Type_select->currentIndex()) {
    case 0: 
    case 4:	// Stereo EQ
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm2_display->setText(QString::number(PerfEFXparm2_select->value()-15));
      else
	PatchEFX_parm2_display->setText(QString::number(PatchEFX_parm2_select->value()-15));
      break;
      
    case 1: 
    case 2:	// Overdrive  Distortion
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm2_select->value()==64) 
	PerfEFXparm2_display->setText(QString("Center"));
      if (PerfEFXparm2_select->value()<64) 
	PerfEFXparm2_display->setText(QString("Left ")+QString::number((64-PerfEFXparm2_select->value())*90/64)+QString(" Deg."));
      if (PerfEFXparm2_select->value()>64) 
	PerfEFXparm2_display->setText(QString("Right ")+QString::number((PerfEFXparm2_select->value()-63)*90/64)+QString(" Deg."));
      } else {
      if (PatchEFX_parm2_select->value()==64) 
	PatchEFX_parm2_display->setText(QString("Center"));
      if (PatchEFX_parm2_select->value()<64) 
	PatchEFX_parm2_display->setText(QString("Left ")+QString::number((64-PatchEFX_parm2_select->value())*90/64)+QString(" Deg."));
      if (PatchEFX_parm2_select->value()>64) 
	PatchEFX_parm2_display->setText(QString("Right ")+QString::number((PatchEFX_parm2_select->value()-63)*90/64)+QString(" Deg."));
      }
      break;
      
    case 3:	// Phaser
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
      //0.05 to 5.0 by 0.05/5.0 to 7.0 by 0.1/7 to 10 by 0.5
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm2_select->value()<99)
	PerfEFXparm2_display->setText(QString::number((PerfEFXparm2_select->value()*0.05 )+0.05));
      else if (PerfEFXparm2_select->value()<119)
	PerfEFXparm2_display->setText(QString::number(((PerfEFXparm2_select->value()-99)*0.1)+5));
      else
	PerfEFXparm2_display->setText(QString::number(((PerfEFXparm2_select->value()-119)*0.5)+7));
      } else {
      if (PatchEFX_parm2_select->value()<99)
	PatchEFX_parm2_display->setText(QString::number((PatchEFX_parm2_select->value()*0.05 )+0.05));
      else if (PatchEFX_parm2_select->value()<119)
	PatchEFX_parm2_display->setText(QString::number(((PatchEFX_parm2_select->value()-99)*0.1)+5));
      else
	PatchEFX_parm2_display->setText(QString::number(((PatchEFX_parm2_select->value()-119)*0.5)+7));
      }
      break;
      
    case 5: 
    case 6: 
    case 8: 
    case 9:	// Enhancer
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm2_display->setText(QString::number(PerfEFXparm2_select->value()));
      else
	PatchEFX_parm2_display->setText(QString::number(PatchEFX_parm2_select->value()));
      break;
      
    case 7: 
    case 10: 
    case 11:	// Rotary
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm2_select->value()<99)
	PerfEFXparm2_display->setText(QString::number((PerfEFXparm2_select->value()*0.05 )+0.05));
      else if (PerfEFXparm2_select->value()<119)
	PerfEFXparm2_display->setText(QString::number(((PerfEFXparm2_select->value()-99)*0.1)+5));
      else
	PerfEFXparm2_display->setText(QString::number(((PerfEFXparm2_select->value()-119)*0.5)+7));
      } else {
      if (PatchEFX_parm2_select->value()<99)
	PatchEFX_parm2_display->setText(QString::number((PatchEFX_parm2_select->value()*0.05 )+0.05));
      else if (PatchEFX_parm2_select->value()<119)
	PatchEFX_parm2_display->setText(QString::number(((PatchEFX_parm2_select->value()-99)*0.1)+5));
      else
	PatchEFX_parm2_display->setText(QString::number(((PatchEFX_parm2_select->value()-119)*0.5)+7));
      }
      break;
      
    case 12:	// Space-D
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm2_display->setText(QString::number(PerfEFXparm2_select->value()));
      else
	PatchEFX_parm2_display->setText(QString::number(PatchEFX_parm2_select->value()));
      break;
      
    case 13: 
    case 14:	// Stereo-Chorus
      // 200/ 250/ 315/ 400/ 500/ 630/ 800/ 1000/ 1250/ 1600/ 2000/ 2500/ 3150/ 4000/ 5000/ 6300/ 8000
      if (MainTabWidget->currentIndex()==1) {
      switch(PerfEFXparm2_select->value()) {
	case 0:
	  PerfEFXparm2_display->setText(QString("200"));
	  break;
        case 1:
          PerfEFXparm2_display->setText(QString("250"));
          break;
        case 2:
          PerfEFXparm2_display->setText(QString("315"));
          break;
        case 3:
          PerfEFXparm2_display->setText(QString("400"));
          break;
        case 4:
          PerfEFXparm2_display->setText(QString("500"));
          break;
        case 5:
          PerfEFXparm2_display->setText(QString("630"));
          break;
        case 6:
          PerfEFXparm2_display->setText(QString("800"));
          break;
        case 7:
          PerfEFXparm2_display->setText(QString("1000"));
          break;
        case 8:
          PerfEFXparm2_display->setText(QString("1250"));
          break;
        case 9:
          PerfEFXparm2_display->setText(QString("1600"));
          break;
        case 10:
          PerfEFXparm2_display->setText(QString("2000"));
          break;
        case 11:
          PerfEFXparm2_display->setText(QString("2500"));
          break;
        case 12:
          PerfEFXparm2_display->setText(QString("3150"));
          break;
        case 13:
          PerfEFXparm2_display->setText(QString("4000"));
          break;
        case 14:
          PerfEFXparm2_display->setText(QString("5000"));
          break;
        case 15:
          PerfEFXparm2_display->setText(QString("6300"));
          break;
        case 16:
          PerfEFXparm2_display->setText(QString("8000"));
          break;
        default:
          PerfEFXparm2_display->setText(QString(""));
          break;
      }	// end Switch
      } else {
      switch(PatchEFX_parm2_select->value()) {
	case 0:
	  PatchEFX_parm2_display->setText(QString("200"));
	  break;
        case 1:
          PatchEFX_parm2_display->setText(QString("250"));
          break;
        case 2:
          PatchEFX_parm2_display->setText(QString("315"));
          break;
        case 3:
          PatchEFX_parm2_display->setText(QString("400"));
          break;
        case 4:
          PatchEFX_parm2_display->setText(QString("500"));
          break;
        case 5:
          PatchEFX_parm2_display->setText(QString("630"));
          break;
        case 6:
          PatchEFX_parm2_display->setText(QString("800"));
          break;
        case 7:
          PatchEFX_parm2_display->setText(QString("1000"));
          break;
        case 8:
          PatchEFX_parm2_display->setText(QString("1250"));
          break;
        case 9:
          PatchEFX_parm2_display->setText(QString("1600"));
          break;
        case 10:
          PatchEFX_parm2_display->setText(QString("2000"));
          break;
        case 11:
          PatchEFX_parm2_display->setText(QString("2500"));
          break;
        case 12:
          PatchEFX_parm2_display->setText(QString("3150"));
          break;
        case 13:
          PatchEFX_parm2_display->setText(QString("4000"));
          break;
        case 14:
          PatchEFX_parm2_display->setText(QString("5000"));
          break;
        case 15:
          PatchEFX_parm2_display->setText(QString("6300"));
          break;
        case 16:
          PatchEFX_parm2_display->setText(QString("8000"));
          break;
        default:
          PatchEFX_parm2_display->setText(QString(""));
          break;
      }	// end SWITCH
      }
      break;
      
    case 15:
      //0.05 to 5.0 by 0.05/5.0 to 7.0 by 0.1/7 to 10 by 0.5
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm2_select->value()<99)
	PerfEFXparm2_display->setText(QString::number((PerfEFXparm2_select->value()*0.05 )+0.05));
      else if (PerfEFXparm2_select->value()<119)
	PerfEFXparm2_display->setText(QString::number(((PerfEFXparm2_select->value()-99)*0.1)+5));
      else
	PerfEFXparm2_display->setText(QString::number(((PerfEFXparm2_select->value()-119)*0.5)+7));
      } else {
      if (PatchEFX_parm2_select->value()<99)
	PatchEFX_parm2_display->setText(QString::number((PatchEFX_parm2_select->value()*0.05 )+0.05));
      else if (PatchEFX_parm2_select->value()<119)
	PatchEFX_parm2_display->setText(QString::number(((PatchEFX_parm2_select->value()-99)*0.1)+5));
      else
	PatchEFX_parm2_display->setText(QString::number(((PatchEFX_parm2_select->value()-119)*0.5)+7));	
      }
      break;

    case 16: 
    case 17:
    // 0 to 5.0 by 0.1/5.0 to 10.0 by 0.5/10 to 40 by 1/40 to 300 by 10/300 to 500  by 20
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm2_select->value()<50)
	PerfEFXparm2_display->setText(QString::number((PerfEFXparm2_select->value()*0.1)));
      else if (PerfEFXparm2_select->value()<60)
	PerfEFXparm2_display->setText(QString::number(((PerfEFXparm2_select->value()-50)*0.5)+5));
      else if (PerfEFXparm2_select->value()<90)
	PerfEFXparm2_display->setText(QString::number(((PerfEFXparm2_select->value()-60)*1)+10));
      else if (PerfEFXparm2_select->value()<116)
	PerfEFXparm2_display->setText(QString::number(((PerfEFXparm2_select->value()-90)*10)+40));
      else
	PerfEFXparm2_display->setText(QString::number(((PerfEFXparm2_select->value()-116)*20)+300));
      } else {
      if (PatchEFX_parm2_select->value()<50)
	PatchEFX_parm2_display->setText(QString::number((PatchEFX_parm2_select->value()*0.1)));
      else if (PatchEFX_parm2_select->value()<60)
	PatchEFX_parm2_display->setText(QString::number(((PatchEFX_parm2_select->value()-50)*0.5)+5));
      else if (PatchEFX_parm2_select->value()<90)
	PatchEFX_parm2_display->setText(QString::number(((PatchEFX_parm2_select->value()-60)*1)+10));
      else if (PatchEFX_parm2_select->value()<116)
	PatchEFX_parm2_display->setText(QString::number(((PatchEFX_parm2_select->value()-90)*10)+40));
      else
	PatchEFX_parm2_display->setText(QString::number(((PatchEFX_parm2_select->value()-116)*20)+300));
      }
      break;

    case 18: 
    case 19:
      // 200 to 550 by 5/550 to 1000 by 10
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm2_select->value()<70)
	PerfEFXparm2_display->setText(QString::number(PerfEFXparm2_select->value()*5+200));
      else
	PerfEFXparm2_display->setText(QString::number((PerfEFXparm2_select->value()-70)*10+550));
      } else {
      if (PatchEFX_parm2_select->value()<70)
	PatchEFX_parm2_display->setText(QString::number(PatchEFX_parm2_select->value()*5+200));
      else
	PatchEFX_parm2_display->setText(QString::number((PatchEFX_parm2_select->value()-70)*10+550));
      }
      break;

    case 20:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm2_display->setText(QString::number((PerfEFXparm2_select->value()*2)-98));
      else
	PatchEFX_parm2_display->setText(QString::number((PatchEFX_parm2_select->value()*2)-98));
      break;

    case 21:
    case 22:
    // -24 to +12 by 1
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm2_display->setText(QString::number(PerfEFXparm2_select->value()-24));
      else
	PatchEFX_parm2_display->setText(QString::number(PatchEFX_parm2_select->value()-24));
      break;

    case 23:
    case 24:
    // 0 to 5.0 by 0.1/5.0 to 10.0 by 0.5/10 to 50 by 1/50 to 100 by 2
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm2_select->value()<50)
	PerfEFXparm2_display->setText(QString::number((PerfEFXparm2_select->value()*0.1)));
      else if (PerfEFXparm2_select->value()<60)
	PerfEFXparm2_display->setText(QString::number(((PerfEFXparm2_select->value()-60)*0.5)+5));
      else if (PerfEFXparm2_select->value()<100)
	PerfEFXparm2_display->setText(QString::number(((PerfEFXparm2_select->value()-60))+10));
      else
	PerfEFXparm2_display->setText(QString::number(((PerfEFXparm2_select->value()-100)*2)+50));
      } else {
      if (PatchEFX_parm2_select->value()<50)
	PatchEFX_parm2_display->setText(QString::number((PatchEFX_parm2_select->value()*0.1)));
      else if (PatchEFX_parm2_select->value()<60)
	PatchEFX_parm2_display->setText(QString::number(((PatchEFX_parm2_select->value()-60)*0.5)+5));
      else if (PatchEFX_parm2_select->value()<100)
	PatchEFX_parm2_display->setText(QString::number(((PatchEFX_parm2_select->value()-60))+10));
      else
	PatchEFX_parm2_display->setText(QString::number(((PatchEFX_parm2_select->value()-100)*2)+50));
      }
      break;
      
    case 31:
    case 32:
    case 33:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm2_display->setText(QString::number(PerfEFXparm2_select->value()));
      else
	PatchEFX_parm2_display->setText(QString::number(PatchEFX_parm2_select->value()));
      break;

    default:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm2_display->clear();
      else
	PatchEFX_parm2_display->clear();
      break;
  }
  if (state_table->jv_connect && state_table->updates_enabled) {
  if (MainTabWidget->currentIndex()==1)
    setPerfSingleValue(0xE + 1,PerfEFXparm2_select->value());
  else
    setPatchSingleValue(0xD + 1,PatchEFX_parm2_select->value());
  }
}
