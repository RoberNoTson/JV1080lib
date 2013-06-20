// EFXdisplayParm10.cpp
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setEFXdisplayParm_A() {
  switch(MainTabWidget->currentIndex()==1 ? PerfEFXtype_select->currentIndex() : PatchEFX_Type_select->currentIndex()) {
//    case 1:
//    case 2:
//    case 3: 
//    case 5: 
//    case 6:
//    case 8:
//    case 9:
//    case 10:
//    case 11:
//    case 12:
//    case 20:
//    case 23:
//    case 24:
//    case 25:
//    case 26:
//    case 27:
//    case 28:
//    case 29:
//    case 30:
//    case 31:
//    case 32:
//    case 33:

    case 0:
    case 17:
    case 18:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparmA_display->setText(QString::number(PerfEFXparmA_select->value()-15));
      else
	PatchEFX_parmA_display->setText(QString::number(PatchEFX_parmA_select->value()-15));
      break;

    case 4: 
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparmA_select->value()==64) 
	PerfEFXparmA_display->setText(QString("Center"));
      if (PerfEFXparmA_select->value()<64) 
	PerfEFXparmA_display->setText(QString("Left ")+QString::number((64-PerfEFXparmA_select->value())*90/64)+QString(" Deg."));
      if (PerfEFXparmA_select->value()>64) 
	PerfEFXparmA_display->setText(QString("Right ")+QString::number((PerfEFXparmA_select->value()-63)*90/64)+QString(" Deg."));
      } else {
      if (PatchEFX_parmA_select->value()==64) 
	PatchEFX_parmA_display->setText(QString("Center"));
      if (PatchEFX_parmA_select->value()<64) 
	PatchEFX_parmA_display->setText(QString("Left ")+QString::number((64-PatchEFX_parmA_select->value())*90/64)+QString(" Deg."));
      if (PatchEFX_parmA_select->value()>64) 
	PatchEFX_parmA_display->setText(QString("Right ")+QString::number((PatchEFX_parmA_select->value()-63)*90/64)+QString(" Deg."));
      }
      break;

    case 7:
    case 13:	// Stereo-Chorus
    case 14:	// Stereo-Flanger
    case 15:
    case 16:
    case 21:
    case 22:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparmA_display->setText(QString::number(PerfEFXparmA_select->value()));
      else
	PatchEFX_parmA_display->setText(QString::number(PatchEFX_parmA_select->value()));
      break;

    case 19:
      if (MainTabWidget->currentIndex()==1) {
      switch(PerfEFXparmA_select->value()) {
        case 0:
          PerfEFXparmA_display->setText(QString("200"));
          break;
        case 1:
          PerfEFXparmA_display->setText(QString("250"));
          break;
        case 2:
          PerfEFXparmA_display->setText(QString("315"));
          break;
        case 3:
          PerfEFXparmA_display->setText(QString("400"));
          break;
        case 4:
          PerfEFXparmA_display->setText(QString("500"));
          break;
        case 5:
          PerfEFXparmA_display->setText(QString("630"));
          break;
        case 6:
          PerfEFXparmA_display->setText(QString("800"));
          break;
	case 7:
          PerfEFXparmA_display->setText(QString("1000"));
          break;
        case 8:
          PerfEFXparmA_display->setText(QString("1250"));
          break;
        case 9:
          PerfEFXparmA_display->setText(QString("1600"));
          break;
        case 10:
          PerfEFXparmA_display->setText(QString("2000"));
          break;
        case 11:
          PerfEFXparmA_display->setText(QString("2500"));
          break;
        case 12:
          PerfEFXparmA_display->setText(QString("3150"));
          break;
        case 13:
          PerfEFXparmA_display->setText(QString("4000"));
          break;
        case 14:
          PerfEFXparmA_display->setText(QString("5000"));
          break;
        case 15:
          PerfEFXparmA_display->setText(QString("6300"));
          break;
        case 16:
          PerfEFXparmA_display->setText(QString("8000"));
          break;
        case 17:
          PerfEFXparmA_display->setText(QString("Bypass"));
	  break;
      }	// end Switch
      } else {
      switch(PatchEFX_parmA_select->value()) {
        case 0:
          PatchEFX_parmA_display->setText(QString("200"));
          break;
        case 1:
          PatchEFX_parmA_display->setText(QString("250"));
          break;
        case 2:
          PatchEFX_parmA_display->setText(QString("315"));
          break;
        case 3:
          PatchEFX_parmA_display->setText(QString("400"));
          break;
        case 4:
          PatchEFX_parmA_display->setText(QString("500"));
          break;
        case 5:
          PatchEFX_parmA_display->setText(QString("630"));
          break;
        case 6:
          PatchEFX_parmA_display->setText(QString("800"));
          break;
	case 7:
          PatchEFX_parmA_display->setText(QString("1000"));
          break;
        case 8:
          PatchEFX_parmA_display->setText(QString("1250"));
          break;
        case 9:
          PatchEFX_parmA_display->setText(QString("1600"));
          break;
        case 10:
          PatchEFX_parmA_display->setText(QString("2000"));
          break;
        case 11:
          PatchEFX_parmA_display->setText(QString("2500"));
          break;
        case 12:
          PatchEFX_parmA_display->setText(QString("3150"));
          break;
        case 13:
          PatchEFX_parmA_display->setText(QString("4000"));
          break;
        case 14:
          PatchEFX_parmA_display->setText(QString("5000"));
          break;
        case 15:
          PatchEFX_parmA_display->setText(QString("6300"));
          break;
        case 16:
          PatchEFX_parmA_display->setText(QString("8000"));
          break;
        case 17:
          PatchEFX_parmA_display->setText(QString("Bypass"));
	  break;
      }	// end SWITCH
      }	// end ELSE
    break;

    default:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparmA_display->clear();
      else
	PatchEFX_parmA_display->clear();
      break;
  }	// end SWITCH
  if (state_table->jv_connect && state_table->updates_enabled) {
    if (MainTabWidget->currentIndex()==1)
      setPerfSingleValue(0xE + 9,PerfEFXparmA_select->value());
    else
      setPatchSingleValue(0xD + 9,PatchEFX_parmA_select->value());
  }
}
