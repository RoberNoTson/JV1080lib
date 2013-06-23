// create_actions.cpp
// for system tab

#include	"JVlibForm.h"
#include	<QtGui>

void JVlibForm::createSysActions() {
  // set up Patch Structure graphics
  scene1 = new QGraphicsScene();
  scene2 = new QGraphicsScene();
  scene3 = new QGraphicsScene();
  scene4 = new QGraphicsScene();
  scene5 = new QGraphicsScene();
  scene6 = new QGraphicsScene();
  scene7 = new QGraphicsScene();
  scene8 = new QGraphicsScene();
  scene9 = new QGraphicsScene();
  scene10 = new QGraphicsScene();
  scene1->addPixmap(QPixmap(":/res/Struct_Type1.png"));
  scene2->addPixmap(QPixmap(":/res/Struct_Type2.png"));
  scene3->addPixmap(QPixmap(":/res/Struct_Type3.png"));
  scene4->addPixmap(QPixmap(":/res/Struct_Type4.png"));
  scene5->addPixmap(QPixmap(":/res/Struct_Type5.png"));
  scene6->addPixmap(QPixmap(":/res/Struct_Type6.png"));
  scene7->addPixmap(QPixmap(":/res/Struct_Type7.png"));
  scene8->addPixmap(QPixmap(":/res/Struct_Type8.png"));
  scene9->addPixmap(QPixmap(":/res/Struct_Type9.png"));
  scene10->addPixmap(QPixmap(":/res/Struct_Type10.png"));
  
  Pitch_Env_scene = new QGraphicsScene;
  ToneTVA_Bias_scene = new QGraphicsScene;
  ToneTVA_Env_scene = new QGraphicsScene;
  ToneTVF_Env_scene = new QGraphicsScene;
  
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
  
  connect(Tuning_ButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(slotTuning_TempButtons(int)));
  connect(JVlibForm::PerfEFXsource_select, SIGNAL(currentIndexChanged(int)), this, SLOT(slotPerfEFXsource(int)));
  connect(JVlibForm::PerfEFXtype_select, SIGNAL(currentIndexChanged(int)), this, SLOT(slotPerfEFXtype(int)));
  connect(JVlibForm::PatchEFX_Type_select, SIGNAL(currentIndexChanged(int)), this, SLOT(slotPatchEFXtype(int)));
  
  connect(JVlibForm::PerfEFXreverbSend_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXreverbSend(int)));
  connect(JVlibForm::PerfEFXchorusSend_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXchorusSend(int)));
  connect(JVlibForm::PerfEFXoutputLevel_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXoutputLevel(int)));
  connect(JVlibForm::PerfEFXoutput_select, SIGNAL(currentIndexChanged(int)), this, SLOT(slotEFXoutput(int)));
  connect(JVlibForm::PerfControl1Depth_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXcontrol1Depth(int)));
  connect(JVlibForm::PerfControl2Depth_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXcontrol2Depth(int)));
  connect(JVlibForm::PerfControlSource1_select, SIGNAL(currentIndexChanged(int)), this, SLOT(slotEFXcontrolSource1(int)));
  connect(JVlibForm::PerfControlSource2_select, SIGNAL(currentIndexChanged(int)), this, SLOT(slotEFXcontrolSource2(int)));
  connect(JVlibForm::PatchEFX_ReverbSend_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXreverbSend(int)));
  connect(JVlibForm::PatchEFX_ChorusSend_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXchorusSend(int)));
  connect(JVlibForm::PatchEFX_OutputLevel_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXoutputLevel(int)));
  connect(JVlibForm::PatchEFX_Output_select, SIGNAL(currentIndexChanged(int)), this, SLOT(slotEFXoutput(int)));
  connect(JVlibForm::PatchEFX_Control1Depth_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXcontrol1Depth(int)));
  connect(JVlibForm::PatchEFX_Control2Depth_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXcontrol2Depth(int)));
  connect(JVlibForm::PatchEFX_Control1Source_select, SIGNAL(currentIndexChanged(int)), this, SLOT(slotEFXcontrolSource1(int)));
  connect(JVlibForm::PatchEFX_Control2Source_select, SIGNAL(currentIndexChanged(int)), this, SLOT(slotEFXcontrolSource2(int)));
  
  connect(JVlibForm::PerfEFXparm1_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparm1(int)));
  connect(JVlibForm::PerfEFXparm2_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparm2(int)));
  connect(JVlibForm::PerfEFXparm3_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparm3(int)));
  connect(JVlibForm::PerfEFXparm4_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparm4(int)));
  connect(JVlibForm::PerfEFXparm5_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparm5(int)));
  connect(JVlibForm::PerfEFXparm6_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparm6(int)));
  connect(JVlibForm::PerfEFXparm7_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparm7(int)));
  connect(JVlibForm::PerfEFXparm8_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparm8(int)));
  connect(JVlibForm::PerfEFXparm9_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparm9(int)));
  connect(JVlibForm::PerfEFXparmA_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparmA(int)));
  connect(JVlibForm::PerfEFXparmB_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparmB(int)));
  connect(JVlibForm::PerfEFXparmC_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparmC(int)));
  connect(JVlibForm::PatchEFX_parm1_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparm1(int)));
  connect(JVlibForm::PatchEFX_parm2_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparm2(int)));
  connect(JVlibForm::PatchEFX_parm3_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparm3(int)));
  connect(JVlibForm::PatchEFX_parm4_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparm4(int)));
  connect(JVlibForm::PatchEFX_parm5_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparm5(int)));
  connect(JVlibForm::PatchEFX_parm6_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparm6(int)));
  connect(JVlibForm::PatchEFX_parm7_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparm7(int)));
  connect(JVlibForm::PatchEFX_parm8_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparm8(int)));
  connect(JVlibForm::PatchEFX_parm9_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparm9(int)));
  connect(JVlibForm::PatchEFX_parmA_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparmA(int)));
  connect(JVlibForm::PatchEFX_parmB_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparmB(int)));
  connect(JVlibForm::PatchEFX_parmC_select, SIGNAL(valueChanged(int)), this, SLOT(slotEFXparmC(int)));
  
  connect(JVlibForm::SysPerfSelect, SIGNAL(currentIndexChanged(int)), this, SLOT(slotSysSetPerf()));
  connect(JVlibForm::SysPatchSelect, SIGNAL(currentIndexChanged(int)), this, SLOT(slotSysSetPatch()));
  connect(JVlibForm::SysExit_button, SIGNAL(clicked()), this, SLOT(close()));
}	// end createSysActions

