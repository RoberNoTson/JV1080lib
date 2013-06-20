// EFXdisplayParm4.cpp
//  display EFXparm 4 as appropriate for the selected EFX type

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setEFXdisplayParm_4() {
  switch(MainTabWidget->currentIndex()==1 ? PerfEFXtype_select->currentIndex() : PatchEFX_Type_select->currentIndex()) {
//    case 34:
//    case 37:
    case 0:	// Stereo EQ
    case 1:	// Overdrive
    case 2:	// Distortion
    case 4:	// Spectrum
    case 5:	// Enhancer
    case 24:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm4_display->setText(QString::number(PerfEFXparm4_select->value()-15));
      else
	PatchEFX_parm4_display->setText(QString::number(PatchEFX_parm4_select->value()-15));
      break;

    case 3: 
    case 6:	// Auto-Wah
    case 10:
    case 36:
    case 39:      
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm4_display->setText(QString::number(PerfEFXparm4_select->value()));
      else
	PatchEFX_parm4_display->setText(QString::number(PatchEFX_parm4_select->value()));
      break;

    case 7:
    if (MainTabWidget->currentIndex()==1) {
    if (PerfEFXparm4_select->value()<99)
      PerfEFXparm4_display->setText(QString::number((PerfEFXparm4_select->value()*0.05 )+0.05));
    else if (PerfEFXparm4_select->value()<119)
      PerfEFXparm4_display->setText(QString::number(((PerfEFXparm4_select->value()-99)*0.1)+5));
    else
      PerfEFXparm4_display->setText(QString::number(((PerfEFXparm4_select->value()-119)*0.5)+7));
    } else {
    if (PatchEFX_parm4_select->value()<99)
      PatchEFX_parm4_display->setText(QString::number((PatchEFX_parm4_select->value()*0.05 )+0.05));
    else if (PatchEFX_parm4_select->value()<119)
      PatchEFX_parm4_display->setText(QString::number(((PatchEFX_parm4_select->value()-99)*0.1)+5));
    else
      PatchEFX_parm4_display->setText(QString::number(((PatchEFX_parm4_select->value()-119)*0.5)+7));
    }
    break;

    case 8:
    if (MainTabWidget->currentIndex()==1) {
    switch(PerfEFXparm4_select->value()) {
      case 0:
	PerfEFXparm4_display->setText(QString("1"));
	break;
      case 1:
	PerfEFXparm4_display->setText(QString("2"));
	break;
      case 2:
	PerfEFXparm4_display->setText(QString("4"));
	break;
      case 3:
	PerfEFXparm4_display->setText(QString("8"));
	break;
    }
    } else {
    switch(PatchEFX_parm4_select->value()) {
      case 0:
	PatchEFX_parm4_display->setText(QString("1"));
	break;
      case 1:
	PatchEFX_parm4_display->setText(QString("2"));
	break;
      case 2:
	PatchEFX_parm4_display->setText(QString("4"));
	break;
      case 3:
	PatchEFX_parm4_display->setText(QString("8"));
	break;
    }
    }
    break;

    case 9:
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm4_select->value()==64) 
	PerfEFXparm4_display->setText(QString("Center"));
      if (PerfEFXparm4_select->value()<64) 
	PerfEFXparm4_display->setText(QString("Left ")+QString::number((64-PerfEFXparm4_select->value())*90/64)+QString(" Deg."));
      if (PerfEFXparm4_select->value()>64) 
	PerfEFXparm4_display->setText(QString("Right ")+QString::number((PerfEFXparm4_select->value()-63)*90/64)+QString(" Deg."));
      } else {
      if (PatchEFX_parm4_select->value()==64) 
	PatchEFX_parm4_display->setText(QString("Center"));
      if (PatchEFX_parm4_select->value()<64) 
	PatchEFX_parm4_display->setText(QString("Left ")+QString::number((64-PatchEFX_parm4_select->value())*90/64)+QString(" Deg."));
      if (PatchEFX_parm4_select->value()>64) 
	PatchEFX_parm4_display->setText(QString("Right ")+QString::number((PatchEFX_parm4_select->value()-63)*90/64)+QString(" Deg."));
      }
      break;

    case 11:
    case 13:	// Stereo-Chorus
    case 14:	// Stereo-Flanger
    case 25:
    case 26:
    case 28:
    case 29:
    case 31:
    case 32:
      // 0.05 to 5.0 by 0.05/5.0 to 7.0 by 0.1/7 to 10 by 0.5
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm4_select->value()<99)
	PerfEFXparm4_display->setText(QString::number((PerfEFXparm4_select->value()*0.05 )+0.05));
      else if (PerfEFXparm4_select->value()<119)
	PerfEFXparm4_display->setText(QString::number(((PerfEFXparm4_select->value()-99)*0.1)+5));
      else
	PerfEFXparm4_display->setText(QString::number(((PerfEFXparm4_select->value()-119)*0.5)+7));
      } else {
      if (PatchEFX_parm4_select->value()<99)
	PatchEFX_parm4_display->setText(QString::number((PatchEFX_parm4_select->value()*0.05 )+0.05));
      else if (PatchEFX_parm4_select->value()<119)
	PatchEFX_parm4_display->setText(QString::number(((PatchEFX_parm4_select->value()-99)*0.1)+5));
      else
	PatchEFX_parm4_display->setText(QString::number(((PatchEFX_parm4_select->value()-119)*0.5)+7));
      }
      break;

    case 12:	// Space-D
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm4_display->setText(QString::number(PerfEFXparm4_select->value()*2));
      else
	PatchEFX_parm4_display->setText(QString::number(PatchEFX_parm4_select->value()*2));
      break;

    case 16:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm4_display->setText(PerfEFXparm4_select->value()?QString("Invert"):QString("Normal"));
      else
	PatchEFX_parm4_display->setText(PatchEFX_parm4_select->value()?QString("Invert"):QString("Normal"));
      break;

    case 15:
    case 17:
    case 18:
    case 27:
    case 30:
    case 33:
    case 35:
    case 38:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm4_display->setText(QString::number((PerfEFXparm4_select->value()*2)-98));
      else
	PatchEFX_parm4_display->setText(QString::number((PatchEFX_parm4_select->value()*2)-98));
      break;

    case 19:
      // 200 to 550 by 5/550 to 1000 by 10
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm4_select->value()<70)
        PerfEFXparm4_display->setText(QString::number(PerfEFXparm4_select->value()*5+200));
      else
        PerfEFXparm4_display->setText(QString::number((PerfEFXparm4_select->value()-70)*10+550));
      } else {
      if (PatchEFX_parm4_select->value()<70)
        PatchEFX_parm4_display->setText(QString::number(PatchEFX_parm4_select->value()*5+200));
      else
        PatchEFX_parm4_display->setText(QString::number((PatchEFX_parm4_select->value()-70)*10+550));
      }
      break;

    case 20:
    case 23:
      if (MainTabWidget->currentIndex()==1) {
      switch(PerfEFXparm4_select->value()) {
        case 0:
          PerfEFXparm4_display->setText(QString("200"));
          break;
        case 1:
          PerfEFXparm4_display->setText(QString("250"));
          break;
        case 2:
          PerfEFXparm4_display->setText(QString("315"));
          break;
        case 3:
          PerfEFXparm4_display->setText(QString("400"));
          break;
        case 4:
          PerfEFXparm4_display->setText(QString("500"));
          break;
        case 5:
          PerfEFXparm4_display->setText(QString("630"));
          break;
        case 6:
          PerfEFXparm4_display->setText(QString("800"));
          break;
        case 7:
          PerfEFXparm4_display->setText(QString("1000"));
          break;
        case 8:
          PerfEFXparm4_display->setText(QString("1250"));
          break;
        case 9:
          PerfEFXparm4_display->setText(QString("1600"));
          break;
        case 10:
          PerfEFXparm4_display->setText(QString("2000"));
          break;
        case 11:
          PerfEFXparm4_display->setText(QString("2500"));
          break;
        case 12:
          PerfEFXparm4_display->setText(QString("3150"));
          break;
        case 13:
          PerfEFXparm4_display->setText(QString("4000"));
          break;
        case 14:
          PerfEFXparm4_display->setText(QString("5000"));
          break;
        case 15:
          PerfEFXparm4_display->setText(QString("6300"));
          break;
        case 16:
          PerfEFXparm4_display->setText(QString("8000"));
          break;
        case 17:
          PerfEFXparm4_display->setText(QString("Bypass"));
          break;
      }	// end Switch
      } else {
      switch(PatchEFX_parm4_select->value()) {
        case 0:
          PatchEFX_parm4_display->setText(QString("200"));
          break;
        case 1:
          PatchEFX_parm4_display->setText(QString("250"));
          break;
        case 2:
          PatchEFX_parm4_display->setText(QString("315"));
          break;
        case 3:
          PatchEFX_parm4_display->setText(QString("400"));
          break;
        case 4:
          PatchEFX_parm4_display->setText(QString("500"));
          break;
        case 5:
          PatchEFX_parm4_display->setText(QString("630"));
          break;
        case 6:
          PatchEFX_parm4_display->setText(QString("800"));
          break;
        case 7:
          PatchEFX_parm4_display->setText(QString("1000"));
          break;
        case 8:
          PatchEFX_parm4_display->setText(QString("1250"));
          break;
        case 9:
          PatchEFX_parm4_display->setText(QString("1600"));
          break;
        case 10:
          PatchEFX_parm4_display->setText(QString("2000"));
          break;
        case 11:
          PatchEFX_parm4_display->setText(QString("2500"));
          break;
        case 12:
          PatchEFX_parm4_display->setText(QString("3150"));
          break;
        case 13:
          PatchEFX_parm4_display->setText(QString("4000"));
          break;
        case 14:
          PatchEFX_parm4_display->setText(QString("5000"));
          break;
        case 15:
          PatchEFX_parm4_display->setText(QString("6300"));
          break;
        case 16:
          PatchEFX_parm4_display->setText(QString("8000"));
          break;
        case 17:
          PatchEFX_parm4_display->setText(QString("Bypass"));
          break;
      }	// end Switch
      }
      break;

    case 21:
    // -100 to +100 by 2
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm4_display->setText(QString::number((PerfEFXparm4_select->value()*2)-100));
      else
	PatchEFX_parm4_display->setText(QString::number((PatchEFX_parm4_select->value()*2)-100));
      break;

    case 22:
    // 0 to 5.0 by 0.1/5.0 to 10.0 by 0.5/10 to 40 by 1/40 to 300 by 10/300 to 500  by 20
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm4_select->value()<50)
	PerfEFXparm4_display->setText(QString::number((PerfEFXparm4_select->value()*0.1)));
      else if (PerfEFXparm4_select->value()<60)
	PerfEFXparm4_display->setText(QString::number(((PerfEFXparm4_select->value()-50)*0.5)+5));
      else if (PerfEFXparm4_select->value()<90)
	PerfEFXparm4_display->setText(QString::number(((PerfEFXparm4_select->value()-60)*1)+10));
      else if (PerfEFXparm4_select->value()<116)
	PerfEFXparm4_display->setText(QString::number(((PerfEFXparm4_select->value()-90)*10)+40));
      else
	PerfEFXparm4_display->setText(QString::number(((PerfEFXparm4_select->value()-116)*20)+300));
      } else {
      if (PatchEFX_parm4_select->value()<50)
	PatchEFX_parm4_display->setText(QString::number((PatchEFX_parm4_select->value()*0.1)));
      else if (PatchEFX_parm4_select->value()<60)
	PatchEFX_parm4_display->setText(QString::number(((PatchEFX_parm4_select->value()-50)*0.5)+5));
      else if (PatchEFX_parm4_select->value()<90)
	PatchEFX_parm4_display->setText(QString::number(((PatchEFX_parm4_select->value()-60)*1)+10));
      else if (PatchEFX_parm4_select->value()<116)
	PatchEFX_parm4_display->setText(QString::number(((PatchEFX_parm4_select->value()-90)*10)+40));
      else
	PerfEFXparm4_display->setText(QString::number(((PerfEFXparm4_select->value()-116)*20)+300));
      }
      break;

    default:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm4_display->clear();
      else
	PatchEFX_parm4_display->clear();
      break;
  }
  if (state_table->jv_connect && state_table->updates_enabled) {
  if (MainTabWidget->currentIndex()==1)
    setPerfSingleValue(0xE + 3,PerfEFXparm4_select->value());
  else
    setPatchSingleValue(0xD + 3,PatchEFX_parm4_select->value());
  }
}
