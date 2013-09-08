// create_actions.cpp
// for system tab

#include	"JVlibForm.h"
#include	<QtGui>

void JVlibForm::createSysActions() {
  connect(JVlibForm::SysExit_button, SIGNAL(clicked()), this, SLOT(close()));
  
  Tuning_ButtonGroup = new QButtonGroup();
  Tuning_ButtonGroup->addButton(Tuning_EqualTemp_button,0);
  Tuning_ButtonGroup->addButton(Tuning_JustTemp_button,1);
  Tuning_ButtonGroup->addButton(Tuning_PythagTemp_button,2);
  Tuning_ButtonGroup->addButton(Tuning_MeantoneTemp_button,3);
  Tuning_ButtonGroup->addButton(Tuning_WellTemp_button,4);
  Tuning_ButtonGroup->addButton(Tuning_PureTemp_button,5);
  Tuning_ButtonGroup->addButton(Tuning_ArabicTemp_button,6);
  Tuning_ButtonGroup->addButton(Tuning_CustomTemp_button,7);
  Tuning_currentTuning.fill(0x40, 12); 
  Tuning_EqualTemp_button->setChecked(true);
  connect(Tuning_ButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(slotTuning_TempButtons(int)));
  
  connect(JVlibForm::PatchEFX_parm1_select, SIGNAL(valueChanged(int)), this, SLOT(on_PerfEFXparm1_select_valueChanged(int)));
  connect(JVlibForm::PatchEFX_parm2_select, SIGNAL(valueChanged(int)), this, SLOT(on_PerfEFXparm2_select_valueChanged(int)));
  connect(JVlibForm::PatchEFX_parm3_select, SIGNAL(valueChanged(int)), this, SLOT(on_PerfEFXparm3_select_valueChanged(int)));
  connect(JVlibForm::PatchEFX_parm4_select, SIGNAL(valueChanged(int)), this, SLOT(on_PerfEFXparm4_select_valueChanged(int)));
  connect(JVlibForm::PatchEFX_parm5_select, SIGNAL(valueChanged(int)), this, SLOT(on_PerfEFXparm5_select_valueChanged(int)));
  connect(JVlibForm::PatchEFX_parm6_select, SIGNAL(valueChanged(int)), this, SLOT(on_PerfEFXparm6_select_valueChanged(int)));
  connect(JVlibForm::PatchEFX_parm7_select, SIGNAL(valueChanged(int)), this, SLOT(on_PerfEFXparm7_select_valueChanged(int)));
  connect(JVlibForm::PatchEFX_parm8_select, SIGNAL(valueChanged(int)), this, SLOT(on_PerfEFXparm8_select_valueChanged(int)));
  connect(JVlibForm::PatchEFX_parm9_select, SIGNAL(valueChanged(int)), this, SLOT(on_PerfEFXparm9_select_valueChanged(int)));
  connect(JVlibForm::PatchEFX_parmA_select, SIGNAL(valueChanged(int)), this, SLOT(on_PerfEFXparmA_select_valueChanged(int)));
  connect(JVlibForm::PatchEFX_parmB_select, SIGNAL(valueChanged(int)), this, SLOT(on_PerfEFXparmB_select_valueChanged(int)));
  connect(JVlibForm::PatchEFX_parmC_select, SIGNAL(valueChanged(int)), this, SLOT(on_PerfEFXparmC_select_valueChanged(int)));
}	// end createSysActions

