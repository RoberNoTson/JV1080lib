// EFXdisplayParm12.cpp
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setEFXdisplayParm_C() {
//    case 0:
//    case 1:
//    case 2:
//    case 3:
//    case 4:
//    case 5:
//    case 6:
//    case 7:
//    case 8:
//    case 9:
//    case 10:
//    case 11:
//    case 12:
//    case 13:
//    case 14:
//    case 15:
//    case 16:
//    case 20:
//    case 22:
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
//    case 34:
//    case 35:
//    case 36:
//    case 37:
//    case 38:
//    case 39:      
  switch(MainTabWidget->currentIndex()==1 ? PerfEFXtype_select->currentIndex() : PatchEFX_Type_select->currentIndex()) {
    case 17:
    case 18:
    case 19: 
    case 21:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparmC_display->setText(QString::number(PerfEFXparmC_select->value()));
      else
	PatchEFX_parmC_display->setText(QString::number(PatchEFX_parmC_select->value()));
      break;
      
    default:
      if (MainTabWidget->currentIndex()==1)
	PerfEFXparmC_display->clear();
      else
	PatchEFX_parmC_display->clear();
      break;
  }	// end SWITCH
  
  if (state_table->jv_connect && state_table->updates_enabled) {
    if (MainTabWidget->currentIndex()==1)
      setPerfSingleValue(0xE + 11,PerfEFXparmC_select->value());
    else
      setPatchSingleValue(0xD + 11,PatchEFX_parmC_select->value());
  }
}	// end setEFXdisplayParm_C
