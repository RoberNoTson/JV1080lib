// EFXdisplayParm7.cpp
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setEFXdisplayParm_7() {
  switch(MainTabWidget->currentIndex()==1 ? PerfEFXtype_select->currentIndex() : PatchEFX_Type_select->currentIndex()) {
//    case 1:
//    case 2: 
//    case 5:
//    case 13:	// Stereo-Chorus

    case 0: 
    case 4: 
    case 9: 
    case 15:
    case 20:
    case 22:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm7_display->setText(QString::number(PerfEFXparm7_select->value()-15));
      else
	PatchEFX_parm7_display->setText(QString::number(PatchEFX_parm7_select->value()-15));
      break;

    case 3:
    case 6:
    case 7:
    case 8:
    case 10:
    case 11:
    case 12:	// Space-D
    case 17:
    case 18:
    case 19:
    case 21:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 36:
    case 39:      
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm7_display->setText(QString::number(PerfEFXparm7_select->value()));
      else
	PatchEFX_parm7_display->setText(QString::number(PatchEFX_parm7_select->value()));
      break;


    case 14:	// Stereo-Flanger
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm7_display->setText(QString::number((PerfEFXparm7_select->value()-49)*2));
      else
	PatchEFX_parm7_display->setText(QString::number((PatchEFX_parm7_select->value()-49)*2));
      break;
      
    case 16:
      if (MainTabWidget->currentIndex()==1) {
      switch(PerfEFXparm7_select->value()) {
        case 0:
          PerfEFXparm7_display->setText(QString("200"));
          break;
        case 1:
          PerfEFXparm7_display->setText(QString("250"));
          break;
        case 2:
          PerfEFXparm7_display->setText(QString("315"));
          break;
        case 3:
          PerfEFXparm7_display->setText(QString("400"));
          break;
        case 4:
          PerfEFXparm7_display->setText(QString("500"));
          break;
        case 5:
          PerfEFXparm7_display->setText(QString("630"));
          break;
        case 6:
          PerfEFXparm7_display->setText(QString("800"));
          break;
        case 7:
          PerfEFXparm7_display->setText(QString("1000"));
          break;
        case 8:
          PerfEFXparm7_display->setText(QString("1250"));
          break;
        case 9:
          PerfEFXparm7_display->setText(QString("1600"));
          break;
        case 10:
          PerfEFXparm7_display->setText(QString("2000"));
          break;
        case 11:
          PerfEFXparm7_display->setText(QString("2500"));
          break;
        case 12:
          PerfEFXparm7_display->setText(QString("3150"));
          break;
        case 13:
          PerfEFXparm7_display->setText(QString("4000"));
          break;
        case 14:
          PerfEFXparm7_display->setText(QString("5000"));
          break;
        case 15:
          PerfEFXparm7_display->setText(QString("6300"));
          break;
        case 16:
          PerfEFXparm7_display->setText(QString("8000"));
          break;
        case 17:
          PerfEFXparm7_display->setText(QString("Bypass"));
          break;
      }	// end Switch
      } else {
      switch(PatchEFX_parm7_select->value()) {
        case 0:
          PatchEFX_parm7_display->setText(QString("200"));
          break;
        case 1:
          PatchEFX_parm7_display->setText(QString("250"));
          break;
        case 2:
          PatchEFX_parm7_display->setText(QString("315"));
          break;
        case 3:
          PatchEFX_parm7_display->setText(QString("400"));
          break;
        case 4:
          PatchEFX_parm7_display->setText(QString("500"));
          break;
        case 5:
          PatchEFX_parm7_display->setText(QString("630"));
          break;
        case 6:
          PatchEFX_parm7_display->setText(QString("800"));
          break;
        case 7:
          PatchEFX_parm7_display->setText(QString("1000"));
          break;
        case 8:
          PatchEFX_parm7_display->setText(QString("1250"));
          break;
        case 9:
          PatchEFX_parm7_display->setText(QString("1600"));
          break;
        case 10:
          PatchEFX_parm7_display->setText(QString("2000"));
          break;
        case 11:
          PatchEFX_parm7_display->setText(QString("2500"));
          break;
        case 12:
          PatchEFX_parm7_display->setText(QString("3150"));
          break;
        case 13:
          PatchEFX_parm7_display->setText(QString("4000"));
          break;
        case 14:
          PatchEFX_parm7_display->setText(QString("5000"));
          break;
        case 15:
          PatchEFX_parm7_display->setText(QString("6300"));
          break;
        case 16:
          PatchEFX_parm7_display->setText(QString("8000"));
          break;
        case 17:
          PatchEFX_parm7_display->setText(QString("Bypass"));
          break;
      }	// end Switch
      }
      break;

    case 34:
    case 35:
    case 37:
    case 38:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm7_display->setText(QString::number((PerfEFXparm7_select->value()*2)-98));
      else
	PatchEFX_parm7_display->setText(QString::number((PatchEFX_parm7_select->value()*2)-98));
      break;
      
    default:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm7_display->clear();
      else
	PatchEFX_parm7_display->clear();
      break;
  }
  if (state_table->jv_connect && state_table->updates_enabled) {
    if (MainTabWidget->currentIndex()==1)
      setPerfSingleValue(0xE + 6,PerfEFXparm7_select->value());
    else
      setPatchSingleValue(0xD + 6,PatchEFX_parm7_select->value());
  }
}
