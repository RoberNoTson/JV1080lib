// EFXdisplayParm9.cpp
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setEFXdisplayParm_9() {
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
      if (MainTabWidget->currentIndex()==1) {
      switch(PerfEFXparm9_select->value()) {
	case 0:
	  PerfEFXparm9_display->setText(QString("0.5"));
	  break;
	case 1:
	  PerfEFXparm9_display->setText(QString("1"));
	  break;
	case 2:
	  PerfEFXparm9_display->setText(QString("2"));
	  break;
	case 3:
	  PerfEFXparm9_display->setText(QString("4"));
	  break;
	case 4:
	  PerfEFXparm9_display->setText(QString("9"));
	  break;
      }	// end SWITCH
      } else {
	switch(PatchEFX_parm9_select->value()) {
	case 0:
	  PatchEFX_parm9_display->setText(QString("0.5"));
	  break;
	case 1:
	  PatchEFX_parm9_display->setText(QString("1"));
	  break;
	case 2:
	  PatchEFX_parm9_display->setText(QString("2"));
	  break;
	case 3:
	  PatchEFX_parm9_display->setText(QString("4"));
	  break;
	case 4:
	  PatchEFX_parm9_display->setText(QString("9"));
	  break;
	}
      }
      break;
            
    case 4:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm9_display->setText(QString::number(PerfEFXparm9_select->value()+1));
      else
	PatchEFX_parm9_display->setText(QString::number(PatchEFX_parm9_select->value()+1));
      break;
            
    case 13:	// Stereo-Chorus
    case 14:	// Stereo-Flanger
    case 16:
    case 17:
    case 18:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm9_display->setText(QString::number(PerfEFXparm9_select->value()-15));
      else
	PatchEFX_parm9_display->setText(QString::number(PatchEFX_parm9_select->value()-15));
      break;
      
    case 19:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm9_display->setText(QString::number(PerfEFXparm9_select->value()*2-98));
      else
	PatchEFX_parm9_display->setText(QString::number(PatchEFX_parm9_select->value()*2-98));
      break;
           
    case 21:
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm9_select->value()==64) 
        PerfEFXparm9_display->setText(QString("Center"));
      if (PerfEFXparm9_select->value()<64) 
        PerfEFXparm9_display->setText(QString("Left ")+QString::number((64-PerfEFXparm9_select->value())*90/64)+QString(" Deg."));
      if (PerfEFXparm9_select->value()>64) 
        PerfEFXparm9_display->setText(QString("Right ")+QString::number((PerfEFXparm9_select->value()-63)*90/64)+QString(" Deg."));
      } else {
      if (PatchEFX_parm9_select->value()==64) 
        PatchEFX_parm9_display->setText(QString("Center"));
      if (PatchEFX_parm9_select->value()<64) 
        PatchEFX_parm9_display->setText(QString("Left ")+QString::number((64-PatchEFX_parm9_select->value())*90/64)+QString(" Deg."));
      if (PatchEFX_parm9_select->value()>64) 
        PatchEFX_parm9_display->setText(QString("Right ")+QString::number((PatchEFX_parm9_select->value()-63)*90/64)+QString(" Deg."));
      }
      break;

    case 7:
    case 15:
    case 20:
    case 22:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm9_display->setText(QString::number(PerfEFXparm9_select->value()));
      else
	PatchEFX_parm9_display->setText(QString::number(PatchEFX_parm9_select->value()));
      break;

    default:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm9_display->clear();
      else
	PatchEFX_parm9_display->clear();
      break;
  }
  if (state_table->jv_connect && state_table->updates_enabled) {
    if (MainTabWidget->currentIndex()==1)
      setPerfSingleValue(0xE + 8,PerfEFXparm9_select->value());
    else
      setPatchSingleValue(0xD + 8,PatchEFX_parm9_select->value());
  }
}