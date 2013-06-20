// EFXdisplayParm8.cpp
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setEFXdisplayParm_8() {
  switch(MainTabWidget->currentIndex()==1 ? PerfEFXtype_select->currentIndex() : PatchEFX_Type_select->currentIndex()) {
//    case 1:
//    case 2:
//    case 3:
//    case 5:
//    case 6:
//    case 8:
//    case 24:
//    case 27:
//    case 30:
//    case 33:
    case 0:
      if (MainTabWidget->currentIndex()==1) {
      switch(PerfEFXparm8_select->value()) {
        case 0:
          PerfEFXparm8_display->setText(QString("200"));
          break;
        case 1:
          PerfEFXparm8_display->setText(QString("250"));
          break;
        case 2:
          PerfEFXparm8_display->setText(QString("315"));
          break;
        case 3:
          PerfEFXparm8_display->setText(QString("400"));
          break;
        case 4:
          PerfEFXparm8_display->setText(QString("500"));
          break;
        case 5:
          PerfEFXparm8_display->setText(QString("630"));
          break;
        case 6:
          PerfEFXparm8_display->setText(QString("800"));
          break;
	case 7:
          PerfEFXparm8_display->setText(QString("1000"));
          break;
        case 8:
          PerfEFXparm8_display->setText(QString("1250"));
          break;
        case 9:
          PerfEFXparm8_display->setText(QString("1600"));
          break;
        case 10:
          PerfEFXparm8_display->setText(QString("2000"));
          break;
        case 11:
          PerfEFXparm8_display->setText(QString("2500"));
          break;
        case 12:
          PerfEFXparm8_display->setText(QString("3150"));
          break;
        case 13:
          PerfEFXparm8_display->setText(QString("4000"));
          break;
        case 14:
          PerfEFXparm8_display->setText(QString("5000"));
          break;
        case 15:
          PerfEFXparm8_display->setText(QString("6300"));
          break;
        case 16:
          PerfEFXparm8_display->setText(QString("8000"));
          break;
        default:
          PerfEFXparm8_display->setText(QString("0"));
	  break;
      }	// end Switch
      } else {
      switch(PatchEFX_parm8_select->value()) {
        case 0:
          PatchEFX_parm8_display->setText(QString("200"));
          break;
        case 1:
          PatchEFX_parm8_display->setText(QString("250"));
          break;
        case 2:
          PatchEFX_parm8_display->setText(QString("315"));
          break;
        case 3:
          PatchEFX_parm8_display->setText(QString("400"));
          break;
        case 4:
          PatchEFX_parm8_display->setText(QString("500"));
          break;
        case 5:
          PatchEFX_parm8_display->setText(QString("630"));
          break;
        case 6:
          PatchEFX_parm8_display->setText(QString("800"));
          break;
	case 7:
          PatchEFX_parm8_display->setText(QString("1000"));
          break;
        case 8:
          PatchEFX_parm8_display->setText(QString("1250"));
          break;
        case 9:
          PatchEFX_parm8_display->setText(QString("1600"));
          break;
        case 10:
          PatchEFX_parm8_display->setText(QString("2000"));
          break;
        case 11:
          PatchEFX_parm8_display->setText(QString("2500"));
          break;
        case 12:
          PatchEFX_parm8_display->setText(QString("3150"));
          break;
        case 13:
          PatchEFX_parm8_display->setText(QString("4000"));
          break;
        case 14:
          PatchEFX_parm8_display->setText(QString("5000"));
          break;
        case 15:
          PatchEFX_parm8_display->setText(QString("6300"));
          break;
        case 16:
          PatchEFX_parm8_display->setText(QString("8000"));
          break;
        default:
          PatchEFX_parm8_display->setText(QString("0"));
	  break;
      }	// end SWITCH
      }
      break;

    case 4:
    case 13:	// Stereo-Chorus
    case 14:	// Stereo-Flanger
    case 15:
    case 16: case 22:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm8_display->setText(QString::number(PerfEFXparm8_select->value()-15));
      else
	PatchEFX_parm8_display->setText(QString::number(PerfEFXparm8_select->value()-15));
      break;

    case 7:
    case 9:
    case 10:
    case 11:
    case 12:	// Space-D
    case 18:
    case 19:
    case 20:
    case 21:
    case 23:
    case 25:
    case 26:
    case 28:
    case 29:
    case 31:
    case 32:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm8_display->setText(QString::number(PerfEFXparm8_select->value()));
      else
	PatchEFX_parm8_display->setText(QString::number(PatchEFX_parm8_select->value()));
      break;
      
    case 17:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm8_display->setText(QString::number(PerfEFXparm8_select->value()*2));
      else
	PatchEFX_parm8_display->setText(QString::number(PatchEFX_parm8_select->value()*2));
      break;


    case 34:
    case 35:
    case 37:
    case 38:
      if (MainTabWidget->currentIndex()==1) {
      switch(PerfEFXparm8_select->value()) {
        case 0:
          PerfEFXparm8_display->setText(QString("200"));
          break;
        case 1:
          PerfEFXparm8_display->setText(QString("250"));
          break;
        case 2:
          PerfEFXparm8_display->setText(QString("315"));
          break;
        case 3:
          PerfEFXparm8_display->setText(QString("400"));
          break;
        case 4:
          PerfEFXparm8_display->setText(QString("500"));
          break;
        case 5:
          PerfEFXparm8_display->setText(QString("630"));
          break;
        case 6:
          PerfEFXparm8_display->setText(QString("800"));
          break;
	case 7:
          PerfEFXparm8_display->setText(QString("1000"));
          break;
        case 8:
          PerfEFXparm8_display->setText(QString("1250"));
          break;
        case 9:
          PerfEFXparm8_display->setText(QString("1600"));
          break;
        case 10:
          PerfEFXparm8_display->setText(QString("2000"));
          break;
        case 11:
          PerfEFXparm8_display->setText(QString("2500"));
          break;
        case 12:
          PerfEFXparm8_display->setText(QString("3150"));
          break;
        case 13:
          PerfEFXparm8_display->setText(QString("4000"));
          break;
        case 14:
          PerfEFXparm8_display->setText(QString("5000"));
          break;
        case 15:
          PerfEFXparm8_display->setText(QString("6300"));
          break;
        case 16:
          PerfEFXparm8_display->setText(QString("8000"));
          break;
        default:
          PerfEFXparm8_display->setText(QString("0"));
	  break;
      }	// end Switch
      } else {
      switch(PatchEFX_parm8_select->value()) {
        case 0:
          PatchEFX_parm8_display->setText(QString("200"));
          break;
        case 1:
          PatchEFX_parm8_display->setText(QString("250"));
          break;
        case 2:
          PatchEFX_parm8_display->setText(QString("315"));
          break;
        case 3:
          PatchEFX_parm8_display->setText(QString("400"));
          break;
        case 4:
          PatchEFX_parm8_display->setText(QString("500"));
          break;
        case 5:
          PatchEFX_parm8_display->setText(QString("630"));
          break;
        case 6:
          PatchEFX_parm8_display->setText(QString("800"));
          break;
	case 7:
          PatchEFX_parm8_display->setText(QString("1000"));
          break;
        case 8:
          PatchEFX_parm8_display->setText(QString("1250"));
          break;
        case 9:
          PatchEFX_parm8_display->setText(QString("1600"));
          break;
        case 10:
          PatchEFX_parm8_display->setText(QString("2000"));
          break;
        case 11:
          PatchEFX_parm8_display->setText(QString("2500"));
          break;
        case 12:
          PatchEFX_parm8_display->setText(QString("3150"));
          break;
        case 13:
          PatchEFX_parm8_display->setText(QString("4000"));
          break;
        case 14:
          PatchEFX_parm8_display->setText(QString("5000"));
          break;
        case 15:
          PatchEFX_parm8_display->setText(QString("6300"));
          break;
        case 16:
          PatchEFX_parm8_display->setText(QString("8000"));
          break;
	case 17:
          PatchEFX_parm8_display->setText(QString("ByPass"));
          break;
        default:
          PatchEFX_parm8_display->setText(QString("0"));
	  break;
      }	// end SWITCH	
      }
      break;
      
    case 36:
    case 39:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm8_display->setText(QString::number(PerfEFXparm8_select->value()*2-98));
      else
	PatchEFX_parm8_display->setText(QString::number(PatchEFX_parm8_select->value()*2-98));
      break;

    default:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm8_display->clear();
      else
	PatchEFX_parm8_display->clear();
      break;
  }
  if (state_table->jv_connect && state_table->updates_enabled) {
    if (MainTabWidget->currentIndex()==1)
      setPerfSingleValue(0xE + 7,PerfEFXparm8_select->value());
    else
      setPatchSingleValue(0xD + 7,PatchEFX_parm8_select->value());
  }
}
