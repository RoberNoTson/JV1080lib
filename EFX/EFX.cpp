// EFX.cpp

#include        "JVlibForm.h"
#include        <QtGui>
#include	"EFX.h"

void JVlibForm::enable_4(bool val) {
  if (SysMode_select->currentIndex()==0 && MainTabWidget->currentIndex()==1) {	// get Performance EFX settings
    EFXparm4_label->setEnabled(val);
    PerfEFXparm4_select->setEnabled(val);
    PerfEFXparm4_display->setEnabled(val);
    if (val == false) {
      EFXparm4_label->clear();
      PerfEFXparm4_display->clear();
      PerfEFXparm4_select->setValue(0);
    }
  } 	// Patch EFX
  PatchEFX_parm4_label->setEnabled(val);
  PatchEFX_parm4_select->setEnabled(val);
  PatchEFX_parm4_display->setEnabled(val);    
  if (val == false) {
    PatchEFX_parm4_label->clear();
    PatchEFX_parm4_select->setValue(0);
    PatchEFX_parm4_display->clear();
  }
} // end enable_4
void JVlibForm::enable_6(bool val) {
  if (SysMode_select->currentIndex()==0 && MainTabWidget->currentIndex()==1) {	// get Performance EFX settings
    EFXparm6_label->setEnabled(val);
    PerfEFXparm6_select->setEnabled(val);
    PerfEFXparm6_display->setEnabled(val);
    if (val == false) {
      EFXparm6_label->clear();
      PerfEFXparm6_display->clear();
      PerfEFXparm6_select->setValue(0);
    }
  } 	// Patch EFX
  PatchEFX_parm6_label->setEnabled(val);
  PatchEFX_parm6_select->setEnabled(val);
  PatchEFX_parm6_display->setEnabled(val);    
  if (val == false) {
    PatchEFX_parm6_label->clear();
    PatchEFX_parm6_select->setValue(0);
    PatchEFX_parm6_display->clear();
  }
} // end enable_6
void JVlibForm::enable_7(bool val) {
  if (SysMode_select->currentIndex()==0 && MainTabWidget->currentIndex()==1) {	// get Performance EFX settings
  EFXparm7_label->setEnabled(val);
  PerfEFXparm7_select->setEnabled(val);
  PerfEFXparm7_display->setEnabled(val);
  if (val == false) {
    EFXparm7_label->clear();
    PerfEFXparm7_display->clear();
    PerfEFXparm7_select->setValue(0);
  }
  }
  PatchEFX_parm7_label->setEnabled(val);
  PatchEFX_parm7_select->setEnabled(val);
  PatchEFX_parm7_display->setEnabled(val);    
  if (val == false) {
    PatchEFX_parm7_label->clear();
    PatchEFX_parm7_select->setValue(0);
    PatchEFX_parm7_display->clear();
  }
} // end enable_7
void JVlibForm::enable_8(bool val) {
  if (SysMode_select->currentIndex()==0 && MainTabWidget->currentIndex()==1) {	// get Performance EFX settings
  EFXparm8_label->setEnabled(val);
  PerfEFXparm8_select->setEnabled(val);
  PerfEFXparm8_display->setEnabled(val);
  if (val == false) {
    EFXparm8_label->clear();
    PerfEFXparm8_display->clear();
    PerfEFXparm8_select->setValue(0);
  }
  }
  PatchEFX_parm8_label->setEnabled(val);
  PatchEFX_parm8_select->setEnabled(val);
  PatchEFX_parm8_display->setEnabled(val);    
  if (val == false) {
    PatchEFX_parm8_label->clear();
    PatchEFX_parm8_select->setValue(0);
    PatchEFX_parm8_display->clear();
  }
} // end enable_8
void JVlibForm::enable_9(bool val) {
  if (SysMode_select->currentIndex()==0 && MainTabWidget->currentIndex()==1) {	// get Performance EFX settings
  EFXparm9_label->setEnabled(val);
  PerfEFXparm9_select->setEnabled(val);
  PerfEFXparm9_display->setEnabled(val);
  if (val == false) {
    EFXparm9_label->clear();
    PerfEFXparm9_select->setValue(0);
    PerfEFXparm9_display->clear();
  }
  }
  PatchEFX_parm9_label->setEnabled(val);
  PatchEFX_parm9_select->setEnabled(val);
  PatchEFX_parm9_display->setEnabled(val);    
  if (val == false) {
    PatchEFX_parm9_label->clear();
    PatchEFX_parm9_select->setValue(0);
    PatchEFX_parm9_display->clear();
  }
} // end enable_9

void JVlibForm::enable_A(bool val) {
  if (SysMode_select->currentIndex()==0 && MainTabWidget->currentIndex()==1) {	// get Performance EFX settings
  EFXparmA_label->setEnabled(val);
  PerfEFXparmA_select->setEnabled(val);
  PerfEFXparmA_display->setEnabled(val);
  if (val == false) {
    EFXparmA_label->clear();
    PerfEFXparmA_select->setValue(0);
    PerfEFXparmA_display->clear();
  }
  }
  PatchEFX_parmA_label->setEnabled(val);
  PatchEFX_parmA_select->setEnabled(val);
  PatchEFX_parmA_display->setEnabled(val);    
  if (val == false) {
    PatchEFX_parmA_label->clear();
    PatchEFX_parmA_select->setValue(0);
    PatchEFX_parmA_display->clear();
  }
} // end enable_A

void JVlibForm::enable_B(bool val) {
  if (SysMode_select->currentIndex()==0 && MainTabWidget->currentIndex()==1) {	// get Performance EFX settings
    EFXparmB_label->setEnabled(val);
    PerfEFXparmB_select->setEnabled(val);
    PerfEFXparmB_display->setEnabled(val);
    if (val == false) {
      EFXparmB_label->clear();
      PerfEFXparmB_select->setValue(0);
      PerfEFXparmB_display->clear();
    }
  }
  PatchEFX_parmB_label->setEnabled(val);
  PatchEFX_parmB_select->setEnabled(val);
  PatchEFX_parmB_display->setEnabled(val);    
  if (val == false) {
    PatchEFX_parmB_label->clear();
    PatchEFX_parmB_select->setValue(0);
    PatchEFX_parmB_display->clear();
  }
} // end enable_B

void JVlibForm::enable_C(bool val) {
  if (SysMode_select->currentIndex()==0 && MainTabWidget->currentIndex()==1) {	// get Performance EFX settings
  EFXparmC_label->setEnabled(val);
  PerfEFXparmC_select->setEnabled(val);
  PerfEFXparmC_display->setEnabled(val);
  if (val == false) {
    EFXparmC_label->clear();
    PerfEFXparmC_select->setValue(0);
    PerfEFXparmC_display->clear();
  }
  }
  PatchEFX_parmC_label->setEnabled(val);
  PatchEFX_parmC_select->setEnabled(val);
  PatchEFX_parmC_display->setEnabled(val);    
  if (val == false) {
    PatchEFX_parmC_label->clear();
    PatchEFX_parmC_select->setValue(0);
    PatchEFX_parmC_display->clear();
  }
} // end enable_C

