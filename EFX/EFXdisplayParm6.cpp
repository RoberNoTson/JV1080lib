// EFXdisplayParm6.cpp
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setEFXdisplayParm_6() {
  switch(MainTabWidget->currentIndex()==1 ? PerfEFXtype_select->currentIndex() : PatchEFX_Type_select->currentIndex()) {
//    case 5:
//    case 25:
//    case 28:
//    case 31:

    case 0:
      if (MainTabWidget->currentIndex()==1) {
      switch(PerfEFXparm6_select->value()) {
      case 0:
	PerfEFXparm6_display->setText(QString("0.5"));
	break;
      case 1:
	PerfEFXparm6_display->setText(QString("1"));
	break;
      case 2:
	PerfEFXparm6_display->setText(QString("2"));
	break;
      case 3:
	PerfEFXparm6_display->setText(QString("4"));
	break;
      case 4:
	PerfEFXparm6_display->setText(QString("9"));
	break;
      }
      } else {
      switch(PatchEFX_parm6_select->value()) {
      case 0:
	PatchEFX_parm6_display->setText(QString("0.5"));
	break;
      case 1:
	PatchEFX_parm6_display->setText(QString("1"));
	break;
      case 2:
	PatchEFX_parm6_display->setText(QString("2"));
	break;
      case 3:
	PatchEFX_parm6_display->setText(QString("4"));
	break;
      case 4:
	PatchEFX_parm6_display->setText(QString("9"));
	break;
      }
      }
      break;
      
    case 1:
    case 2:
    case 6:
    case 7:
    case 10:
    case 18:
    case 19:
    case 24:
    case 25:
    case 27:
    case 30:
    case 33:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm6_display->setText(QString::number(PerfEFXparm6_select->value()));
      else
	PatchEFX_parm6_display->setText(QString::number(PatchEFX_parm6_select->value()));
      break;
      
    case 3:
    case 22:
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm6_select->value()==64) 
	PerfEFXparm6_display->setText(QString("Center"));
      if (PerfEFXparm6_select->value()<64) 
	PerfEFXparm6_display->setText(QString("Left ")+QString::number((64-PerfEFXparm6_select->value())*90/64)+QString(" Deg."));
      if (PerfEFXparm6_select->value()>64) 
	PerfEFXparm6_display->setText(QString("Right ")+QString::number((PerfEFXparm6_select->value()-63)*90/64)+QString(" Deg."));
      } else {
      if (PatchEFX_parm6_select->value()==64) 
	PatchEFX_parm6_display->setText(QString("Center"));
      if (PatchEFX_parm6_select->value()<64) 
	PatchEFX_parm6_display->setText(QString("Left ")+QString::number((64-PatchEFX_parm6_select->value())*90/64)+QString(" Deg."));
      if (PatchEFX_parm6_select->value()>64) 
	PatchEFX_parm6_display->setText(QString("Right ")+QString::number((PatchEFX_parm6_select->value()-63)*90/64)+QString(" Deg."));
      }
      break;

    case 4:
    case 8:
    case 9:
    case 12:	// Space-D
    case 20:
    case 23:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm6_display->setText(QString::number(PerfEFXparm6_select->value()-15));
      else
	PatchEFX_parm6_display->setText(QString::number(PatchEFX_parm6_select->value()-15));
      break;


    case 11: 
    case 13: 
    case 14: 
    case 15:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm6_display->setText(QString::number(PerfEFXparm6_select->value()*2));
      else
	PatchEFX_parm6_display->setText(QString::number(PatchEFX_parm6_select->value()*2));
      break;

    case 16:
    case 26:
    case 29:
    case 32:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm6_display->setText(QString::number(PerfEFXparm6_select->value()*2-98));
      else
	PatchEFX_parm6_display->setText(QString::number(PatchEFX_parm6_select->value()*2-98));
      break;

    case 17:
    case 36:
    case 39:
    // 0.05 to 5.0 by 0.05/5.0 to 7.0 by 0.1/7 to 10 by 0.5
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm6_select->value()<99)
        PerfEFXparm6_display->setText(QString::number((PerfEFXparm6_select->value()*0.05 )+0.05));
      else if (PerfEFXparm6_select->value()<119)
        PerfEFXparm6_display->setText(QString::number(((PerfEFXparm6_select->value()-99)*0.1)+5));
      else
        PerfEFXparm6_display->setText(QString::number(((PerfEFXparm6_select->value()-119)*0.5)+7));
      } else {
      if (PatchEFX_parm6_select->value()<99)
        PatchEFX_parm6_display->setText(QString::number((PatchEFX_parm6_select->value()*0.05 )+0.05));
      else if (PatchEFX_parm6_select->value()<119)
        PatchEFX_parm6_display->setText(QString::number(((PatchEFX_parm6_select->value()-99)*0.1)+5));
      else
        PatchEFX_parm6_display->setText(QString::number(((PatchEFX_parm6_select->value()-119)*0.5)+7));
      }
      break;

    case 21:
    case 34:
    case 35:
    case 37:
    case 38:
      if (MainTabWidget->currentIndex()==1) {
      if (PerfEFXparm6_select->value()<50)
	PerfEFXparm6_display->setText(QString::number((PerfEFXparm6_select->value()*0.1)));
      else if (PerfEFXparm6_select->value()<60)
	PerfEFXparm6_display->setText(QString::number(((PerfEFXparm6_select->value()-50)*0.5)+5));
      else if (PerfEFXparm6_select->value()<90)
	PerfEFXparm6_display->setText(QString::number(((PerfEFXparm6_select->value()-60)*1)+10));
      else if (PerfEFXparm6_select->value()<116)
	PerfEFXparm6_display->setText(QString::number(((PerfEFXparm6_select->value()-90)*10)+40));
      else
	PerfEFXparm6_display->setText(QString::number(((PerfEFXparm6_select->value()-116)*20)+300));
      } else {
      if (PatchEFX_parm6_select->value()<50)
	PatchEFX_parm6_display->setText(QString::number((PatchEFX_parm6_select->value()*0.1)));
      else if (PatchEFX_parm6_select->value()<60)
	PatchEFX_parm6_display->setText(QString::number(((PatchEFX_parm6_select->value()-50)*0.5)+5));
      else if (PatchEFX_parm6_select->value()<90)
	PatchEFX_parm6_display->setText(QString::number(((PatchEFX_parm6_select->value()-60)*1)+10));
      else if (PatchEFX_parm6_select->value()<116)
	PatchEFX_parm6_display->setText(QString::number(((PatchEFX_parm6_select->value()-90)*10)+40));
      else
	PatchEFX_parm6_display->setText(QString::number(((PatchEFX_parm6_select->value()-116)*20)+300));
      }
      break;

    default:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparm6_display->clear();
      else
	PatchEFX_parm6_display->clear();
      break;
  }
  if (state_table->jv_connect && state_table->updates_enabled) {
    if (MainTabWidget->currentIndex()==1)
      setPerfSingleValue(0xE + 5,PerfEFXparm6_select->value());
    else
      setPatchSingleValue(0xD + 5,PatchEFX_parm6_select->value());
  }
}
