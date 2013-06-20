// EFXdisplayParm5.cpp
//  display EFXparm 5 as appropriate for the selecte EFX type

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setEFXdisplayParm_5() {
  switch(MainTabWidget->currentIndex()==1 ? PerfEFXtype_select->currentIndex() : PatchEFX_Type_select->currentIndex()) {
    case 0:	// Stereo EQ
      if (MainTabWidget->currentIndex()==1) {
      switch(PerfEFXparm5_select->value()) {
        case 0:
          PerfEFXparm5_display->setText(QString("200"));
          break;
        case 1:
          PerfEFXparm5_display->setText(QString("250"));
          break;
        case 2:
          PerfEFXparm5_display->setText(QString("315"));
          break;
        case 3:
          PerfEFXparm5_display->setText(QString("400"));
          break;
        case 4:
          PerfEFXparm5_display->setText(QString("500"));
          break;
        case 5:
          PerfEFXparm5_display->setText(QString("630"));
          break;
        case 6:
          PerfEFXparm5_display->setText(QString("800"));
          break;
	case 7:
          PerfEFXparm5_display->setText(QString("1000"));
          break;
        case 8:
          PerfEFXparm5_display->setText(QString("1250"));
          break;
        case 9:
          PerfEFXparm5_display->setText(QString("1600"));
          break;
        case 10:
          PerfEFXparm5_display->setText(QString("2000"));
          break;
        case 11:
          PerfEFXparm5_display->setText(QString("2500"));
          break;
        case 12:
          PerfEFXparm5_display->setText(QString("3150"));
          break;
        case 13:
          PerfEFXparm5_display->setText(QString("4000"));
          break;
        case 14:
          PerfEFXparm5_display->setText(QString("5000"));
          break;
        case 15:
          PerfEFXparm5_display->setText(QString("6300"));
          break;
        case 16:
          PerfEFXparm5_display->setText(QString("8000"));
          break;
        default:
          PerfEFXparm5_display->setText(QString("0"));
	  break;
      }	// end Switch
      } else {
      switch(PatchEFX_parm5_select->value()) {
        case 0:
          PatchEFX_parm5_display->setText(QString("200"));
          break;
        case 1:
          PatchEFX_parm5_display->setText(QString("250"));
          break;
        case 2:
          PatchEFX_parm5_display->setText(QString("315"));
          break;
        case 3:
          PatchEFX_parm5_display->setText(QString("400"));
          break;
        case 4:
          PatchEFX_parm5_display->setText(QString("500"));
          break;
        case 5:
          PatchEFX_parm5_display->setText(QString("630"));
          break;
        case 6:
          PatchEFX_parm5_display->setText(QString("800"));
          break;
	case 7:
          PatchEFX_parm5_display->setText(QString("1000"));
          break;
        case 8:
          PatchEFX_parm5_display->setText(QString("1250"));
          break;
        case 9:
          PatchEFX_parm5_display->setText(QString("1600"));
          break;
        case 10:
          PatchEFX_parm5_display->setText(QString("2000"));
          break;
        case 11:
          PatchEFX_parm5_display->setText(QString("2500"));
          break;
        case 12:
          PatchEFX_parm5_display->setText(QString("3150"));
          break;
        case 13:
          PatchEFX_parm5_display->setText(QString("4000"));
          break;
        case 14:
          PatchEFX_parm5_display->setText(QString("5000"));
          break;
        case 15:
          PatchEFX_parm5_display->setText(QString("6300"));
          break;
        case 16:
          PatchEFX_parm5_display->setText(QString("8000"));
          break;
        default:
          PatchEFX_parm5_display->setText(QString("0"));
	  break;
      }	// end Switch
      }
      break;

    case 1: 
    case 2: 
    case 4: 
    case 8:
    case 12:	// Space-D
    case 23:
    case 24:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm5_display->setText(QString::number(PerfEFXparm5_select->value()-15));
      else
	PatchEFX_parm5_display->setText(QString::number(PatchEFX_parm5_select->value()-15));
      break;

    case 3:	// Phaser
    case 5:	// Enhancer
    case 6:	// Auto-Wah
    case 11:
    case 13:
    case 14:	// Stereo-Flanger
    case 19:
    case 20:
    case 25:
    case 26:
    case 28:
    case 29:
    case 31:
    case 32:      
    case 34:
    case 35:
    case 37:
    case 38:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm5_display->setText(QString::number(PerfEFXparm5_select->value()));
      else
	PatchEFX_parm5_display->setText(QString::number(PatchEFX_parm5_select->value()));
      break;

    case 7:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm5_display->setText(PerfEFXparm5_select->value()?"Fast":"Slow");
      else
	PatchEFX_parm5_display->setText(PatchEFX_parm5_select->value()?"Fast":"Slow");
      break;

    case 9:
      if (MainTabWidget->currentIndex()==1) {
      switch(PerfEFXparm5_select->value()) {
	case 0:
	  PerfEFXparm5_display->setText(QString::number(1));
	  break;
	case 1:
	  PerfEFXparm5_display->setText(QString::number(2));
	  break;
	case 2:
	  PerfEFXparm5_display->setText(QString::number(4));
	  break;
	case 3:
	  PerfEFXparm5_display->setText(QString::number(8));
	  break;
      }
      } else {
      switch(PatchEFX_parm5_select->value()) {
	case 0:
	  PatchEFX_parm5_display->setText(QString::number(1));
	  break;
	case 1:
	  PatchEFX_parm5_display->setText(QString::number(2));
	  break;
	case 2:
	  PatchEFX_parm5_display->setText(QString::number(4));
	  break;
	case 3:
	  PatchEFX_parm5_display->setText(QString::number(8));
	  break;
      }
      }
      break;
      
    case 10:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm5_display->setText(QString::number((PerfEFXparm5_select->value())-20));
      else
	PatchEFX_parm5_display->setText(QString::number((PatchEFX_parm5_select->value())-20));
      break;
      
    case 15:	// Step-Flanger
      // 0.05 to 4.0 by 0.05/4.0 to 7.0 by 0.1/7 to 10 by 0.5/ 10 notes
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm5_select->value()<79)
        PerfEFXparm5_display->setText(QString::number((PerfEFXparm5_select->value()*0.05 )+0.05));
      else if (PerfEFXparm5_select->value()<109)
        PerfEFXparm5_display->setText(QString::number(((PerfEFXparm5_select->value()-79)*0.1)+4));
      else if (PerfEFXparm5_select->value()<116)
        PerfEFXparm5_display->setText(QString::number(((PerfEFXparm5_select->value()-109)*0.5)+7));
      else 
	switch(PerfEFXparm5_select->value()) {
	  case 116:
	    PerfEFXparm5_display->setText("16th Note");
	    break;
	  case 117:
	    PerfEFXparm5_display->setText("8th Triplet");
	    break;
	  case 118:
	    PerfEFXparm5_display->setText("Dotted 16th");
	    break;
	  case 119:
	    PerfEFXparm5_display->setText("8th Note");
	    break;
	  case 120:
	    PerfEFXparm5_display->setText("Quarter Triplet");
	    break;
	  case 121:
	    PerfEFXparm5_display->setText("Dotted 8th");
	    break;
	  case 122:
	    PerfEFXparm5_display->setText("Quarter Note");
	    break;
	  case 123:
	    PerfEFXparm5_display->setText("Half Triplet");
	    break;
	  case 124:
	    PerfEFXparm5_display->setText("Dotted Quarter");
	    break;
	  case 125:
	    PerfEFXparm5_display->setText("Half Note");
	    break;
	}	// end Switch
      } else {
      if (PatchEFX_parm5_select->value()<79)
        PatchEFX_parm5_display->setText(QString::number((PatchEFX_parm5_select->value()*0.05 )+0.05));
      else if (PatchEFX_parm5_select->value()<109)
        PatchEFX_parm5_display->setText(QString::number(((PatchEFX_parm5_select->value()-79)*0.1)+4));
      else if (PatchEFX_parm5_select->value()<116)
        PatchEFX_parm5_display->setText(QString::number(((PatchEFX_parm5_select->value()-109)*0.5)+7));
      else 
	switch(PatchEFX_parm5_select->value()) {
	  case 116:
	    PatchEFX_parm5_display->setText("16th Note");
	    break;
	  case 117:
	    PatchEFX_parm5_display->setText("8th Triplet");
	    break;
	  case 118:
	    PatchEFX_parm5_display->setText("Dotted 16th");
	    break;
	  case 119:
	    PatchEFX_parm5_display->setText("8th Note");
	    break;
	  case 120:
	    PatchEFX_parm5_display->setText("Quarter Triplet");
	    break;
	  case 121:
	    PatchEFX_parm5_display->setText("Dotted 8th");
	    break;
	  case 122:
	    PatchEFX_parm5_display->setText("Quarter Note");
	    break;
	  case 123:
	    PatchEFX_parm5_display->setText("Half Triplet");
	    break;
	  case 124:
	    PatchEFX_parm5_display->setText("Dotted Quarter");
	    break;
	  case 125:
	    PatchEFX_parm5_display->setText("Half Note");
	    break;
	}	// end SWITCH
      }
      break;
      
    case 16:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm5_display->setText(PerfEFXparm5_select->value()?QString("Invert"):QString("Normal"));
      else
	PatchEFX_parm5_display->setText(PatchEFX_parm5_select->value()?QString("Invert"):QString("Normal"));
      break;
      
    case 17:
    case 18:
      if (MainTabWidget->currentIndex()==1) {
      switch(PerfEFXparm5_select->value()) {
        case 0:
          PerfEFXparm5_display->setText(QString("200"));
          break;
        case 1:
          PerfEFXparm5_display->setText(QString("250"));
          break;
        case 2:
          PerfEFXparm5_display->setText(QString("315"));
          break;
        case 3:
          PerfEFXparm5_display->setText(QString("400"));
          break;
        case 4:
          PerfEFXparm5_display->setText(QString("500"));
          break;
        case 5:
          PerfEFXparm5_display->setText(QString("630"));
          break;
        case 6:
          PerfEFXparm5_display->setText(QString("800"));
          break;
	case 7:
          PerfEFXparm5_display->setText(QString("1000"));
          break;
        case 8:
          PerfEFXparm5_display->setText(QString("1250"));
          break;
        case 9:
          PerfEFXparm5_display->setText(QString("1600"));
          break;
        case 10:
          PerfEFXparm5_display->setText(QString("2000"));
          break;
        case 11:
          PerfEFXparm5_display->setText(QString("2500"));
          break;
        case 12:
          PerfEFXparm5_display->setText(QString("3150"));
          break;
        case 13:
          PerfEFXparm5_display->setText(QString("4000"));
          break;
        case 14:
          PerfEFXparm5_display->setText(QString("5000"));
          break;
        case 15:
          PerfEFXparm5_display->setText(QString("6300"));
          break;
        case 16:
          PerfEFXparm5_display->setText(QString("8000"));
          break;
        case 17:
          PerfEFXparm5_display->setText(QString("Bypass"));
	  break;
      }	// end Switch
      } else {
      switch(PatchEFX_parm5_select->value()) {
        case 0:
          PatchEFX_parm5_display->setText(QString("200"));
          break;
        case 1:
          PatchEFX_parm5_display->setText(QString("250"));
          break;
        case 2:
          PatchEFX_parm5_display->setText(QString("315"));
          break;
        case 3:
          PatchEFX_parm5_display->setText(QString("400"));
          break;
        case 4:
          PatchEFX_parm5_display->setText(QString("500"));
          break;
        case 5:
          PatchEFX_parm5_display->setText(QString("630"));
          break;
        case 6:
          PatchEFX_parm5_display->setText(QString("800"));
          break;
	case 7:
          PatchEFX_parm5_display->setText(QString("1000"));
          break;
        case 8:
          PatchEFX_parm5_display->setText(QString("1250"));
          break;
        case 9:
          PatchEFX_parm5_display->setText(QString("1600"));
          break;
        case 10:
          PatchEFX_parm5_display->setText(QString("2000"));
          break;
        case 11:
          PatchEFX_parm5_display->setText(QString("2500"));
          break;
        case 12:
          PatchEFX_parm5_display->setText(QString("3150"));
          break;
        case 13:
          PatchEFX_parm5_display->setText(QString("4000"));
          break;
        case 14:
          PatchEFX_parm5_display->setText(QString("5000"));
          break;
        case 15:
          PatchEFX_parm5_display->setText(QString("6300"));
          break;
        case 16:
          PatchEFX_parm5_display->setText(QString("8000"));
          break;
        case 17:
          PatchEFX_parm5_display->setText(QString("Bypass"));
	  break;
      }	// end SWITCH
      }
      break;
      
    case 21:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm5_display->setText(QString::number((PerfEFXparm5_select->value()*2)-100));
      else
	PatchEFX_parm5_display->setText(QString::number((PatchEFX_parm5_select->value()*2)-100));
      break;
    
    case 22:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm5_display->setText(QString::number((PerfEFXparm5_select->value()*2)-98));
      else
	PatchEFX_parm5_display->setText(QString::number((PatchEFX_parm5_select->value()*2)-98));
      break;
    
    case 27:
    case 30:
    case 33:
      if (MainTabWidget->currentIndex()==1) {
      switch(PerfEFXparm5_select->value()) {
        case 0:
          PerfEFXparm5_display->setText(QString("200"));
          break;
        case 1:
          PerfEFXparm5_display->setText(QString("250"));
          break;
        case 2:
          PerfEFXparm5_display->setText(QString("315"));
          break;
        case 3:
          PerfEFXparm5_display->setText(QString("400"));
          break;
        case 4:
          PerfEFXparm5_display->setText(QString("500"));
          break;
        case 5:
          PerfEFXparm5_display->setText(QString("630"));
          break;
        case 6:
          PerfEFXparm5_display->setText(QString("800"));
          break;
	case 7:
          PerfEFXparm5_display->setText(QString("1000"));
          break;
        case 8:
          PerfEFXparm5_display->setText(QString("1250"));
          break;
        case 9:
          PerfEFXparm5_display->setText(QString("1600"));
          break;
        case 10:
          PerfEFXparm5_display->setText(QString("2000"));
          break;
        case 11:
          PerfEFXparm5_display->setText(QString("2500"));
          break;
        case 12:
          PerfEFXparm5_display->setText(QString("3150"));
          break;
        case 13:
          PerfEFXparm5_display->setText(QString("4000"));
          break;
        case 14:
          PerfEFXparm5_display->setText(QString("5000"));
          break;
        case 15:
          PerfEFXparm5_display->setText(QString("6300"));
          break;
        case 16:
          PerfEFXparm5_display->setText(QString("8000"));
          break;
        case 17:
          PerfEFXparm5_display->setText(QString("Bypass"));
          break;
        default:
          PerfEFXparm5_display->setText(QString("0"));
	  break;
      }	// end Switch
      } else {
      switch(PatchEFX_parm5_select->value()) {
        case 0:
          PatchEFX_parm5_display->setText(QString("200"));
          break;
        case 1:
          PatchEFX_parm5_display->setText(QString("250"));
          break;
        case 2:
          PatchEFX_parm5_display->setText(QString("315"));
          break;
        case 3:
          PatchEFX_parm5_display->setText(QString("400"));
          break;
        case 4:
          PatchEFX_parm5_display->setText(QString("500"));
          break;
        case 5:
          PatchEFX_parm5_display->setText(QString("630"));
          break;
        case 6:
          PatchEFX_parm5_display->setText(QString("800"));
          break;
	case 7:
          PatchEFX_parm5_display->setText(QString("1000"));
          break;
        case 8:
          PatchEFX_parm5_display->setText(QString("1250"));
          break;
        case 9:
          PatchEFX_parm5_display->setText(QString("1600"));
          break;
        case 10:
          PatchEFX_parm5_display->setText(QString("2000"));
          break;
        case 11:
          PatchEFX_parm5_display->setText(QString("2500"));
          break;
        case 12:
          PatchEFX_parm5_display->setText(QString("3150"));
          break;
        case 13:
          PatchEFX_parm5_display->setText(QString("4000"));
          break;
        case 14:
          PatchEFX_parm5_display->setText(QString("5000"));
          break;
        case 15:
          PatchEFX_parm5_display->setText(QString("6300"));
          break;
        case 16:
          PatchEFX_parm5_display->setText(QString("8000"));
          break;
        case 17:
          PatchEFX_parm5_display->setText(QString("Bypass"));
          break;
        default:
          PatchEFX_parm5_display->setText(QString("0"));
	  break;
      } // end Switch
      }
      break;

    case 36:
    case 39:
    // 0 to 5.0 by 0.1/5.0 to 10.0 by 0.5/10 to 50 by 1/50 to 100 by 2
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm5_select->value()<50)
	PerfEFXparm5_display->setText(QString::number((PerfEFXparm5_select->value()*0.1)));
      else if (PerfEFXparm5_select->value()<60)
	PerfEFXparm5_display->setText(QString::number(((PerfEFXparm5_select->value()-60)*0.5)+5));
      else if (PerfEFXparm5_select->value()<100)
	PerfEFXparm5_display->setText(QString::number(((PerfEFXparm5_select->value()-60))+10));
      else
	PerfEFXparm5_display->setText(QString::number(((PerfEFXparm5_select->value()-100)*2)+50));
      } else {
      if (PatchEFX_parm5_select->value()<50)
	PatchEFX_parm5_display->setText(QString::number((PatchEFX_parm5_select->value()*0.1)));
      else if (PatchEFX_parm5_select->value()<60)
	PatchEFX_parm5_display->setText(QString::number(((PatchEFX_parm5_select->value()-60)*0.5)+5));
      else if (PatchEFX_parm5_select->value()<100)
	PatchEFX_parm5_display->setText(QString::number(((PatchEFX_parm5_select->value()-60))+10));
      else
	PatchEFX_parm5_display->setText(QString::number(((PatchEFX_parm5_select->value()-100)*2)+50));
      }
      break;

    default:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm5_display->clear();
      else
	PatchEFX_parm5_display->clear();
      break;
  }
  if (state_table->jv_connect && state_table->updates_enabled) {
  if (MainTabWidget->currentIndex()==1)
    setPerfSingleValue(0xE + 4,PerfEFXparm5_select->value());
  else
    setPatchSingleValue(0xD + 4,PatchEFX_parm5_select->value());
  }
}

