// create_actions.cpp
// for system tab

#include	"JVlibForm.h"
#include	<QtGui>

void JVlibForm::createSysActions() {
  connect(JVlibForm::SysPerfSelect, SIGNAL(currentIndexChanged(int)), this, SLOT(slotSysSetPerf()));
  connect(JVlibForm::SysPatchSelect, SIGNAL(currentIndexChanged(int)), this, SLOT(slotSysSetPatch()));
  connect(JVlibForm::SysExit_button, SIGNAL(clicked()), this, SLOT(close()));
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
  QPen ToneEnv_blackLine(Qt::black, 0);
  ToneEnv_redLine.setColor(Qt::red);
  ToneEnv_dotLine.setStyle(Qt::DotLine);
  ToneEnv_dotLine.setColor(Qt::blue);
  
  ToneTVA_Bias_ptrbpMark = 0;
  ToneTVA_Bias_ptrHiLine = 0;
  ToneTVA_Bias_ptrLowLine = 0;
  ToneTVA_Bias_scene = new QGraphicsScene;
  ToneTVA_Bias_scene->setSceneRect(0, 0, 325, 135);
  ToneTVA_Bias_scene->addLine(40, 65, 295, 65, ToneEnv_blackLine);     // X axis
  ToneTVA_Bias_scene->addLine(40, 10, 40, 118, ToneEnv_blackLine);    // Y axis
  ToneTVA_Bias_scene->addLine(295, 10, 295, 118, ToneEnv_blackLine);    // Y2 axis
  ToneTVA_Bias_scene->addSimpleText("Level")->setPos(3,45);
  ToneTVA_Bias_scene->addSimpleText("+100")->setPos(5,10);
  ToneTVA_Bias_scene->addSimpleText("-100")->setPos(5,100);
  ToneTVA_Bias_bpMark.setLine(104,20,104,150);
  ToneTVA_Bias_LowLine.setLine(40, 65, ToneTVA_Bias_bpMark.x1(),65);
  ToneTVA_Bias_ptrLowLine = ToneTVA_Bias_scene->addLine(ToneTVA_Bias_LowLine,ToneEnv_redLine);
  ToneTVA_Bias_HiLine.setLine(ToneTVA_Bias_bpMark.x1(),65,295,65);
  ToneTVA_Bias_ptrHiLine = ToneTVA_Bias_scene->addLine(ToneTVA_Bias_HiLine,ToneEnv_redLine);
  ToneTVA_Bias_bpMark.setLine((64*2)+40,10,(64*2)+40,115);
  ToneTVA_Bias_ptrbpMark = ToneTVA_Bias_scene->addLine(ToneTVA_Bias_bpMark,ToneEnv_dotLine);
  ToneTVA_Bias_bpText = ToneTVA_Bias_scene->addSimpleText("C 4");
  ToneTVA_Bias_bpText->setPos(ToneTVA_Bias_bpMark.x1(), 120);
  JVlibForm::ToneTVA_BiasPoint_display->setScene(ToneTVA_Bias_scene);
  JVlibForm::ToneTVA_BiasPoint_display->show();
  
  ToneTVA_Env_scene = new QGraphicsScene;
  ToneTVA_Env_scene->setSceneRect(0, -60, 390, 60);
  QLineF ToneTVA_Env_t4(384,0,384,0);
  QLineF ToneTVA_Env_offLine(384,0,384,-63);
  QLineF ToneTVA_Env_t1Mark(30,0,30,-63);
  QLineF ToneTVA_Env_t2Mark(30,0,30,-63);
  QLineF ToneTVA_Env_t3Mark(30,0,30,-63);
  QLineF ToneTVA_Env_t4Mark(380,0,380,-63);
  ToneTVA_Env_scene->addLine(10, 0, 394, 0, ToneEnv_blackLine);     // X axis
  ToneTVA_Env_scene->addLine(10, 0, 10, -63, ToneEnv_blackLine);    // Y axis
  ToneTVA_Env_scene->addLine(30,8,30,-63,ToneEnv_dotLine);   // Note-On line
  ToneTVA_Env_scene->addLine(ToneTVA_Env_offLine,ToneEnv_dotLine);
  ToneTVA_Env_scene->addSimpleText("Level")->setPos(-20,-35);
  ToneTVA_Env_scene->addSimpleText("127")->setPos(-12,-60);
  ToneTVA_Env_scene->addSimpleText("0")->setPos(0,-10);
  ToneTVA_Env_scene->addSimpleText("Time")->setPos(180,5);
  ToneTVA_Env_scene->addSimpleText("Key-On")->setPos(7,8);
  ToneTVA_Env_OffText = ToneTVA_Env_scene->addSimpleText("Key-Off");
  ToneTVA_Env_OffText->setPos(361,8);
  ToneTVA_Env_ptrT1 = 0;
  ToneTVA_Env_ptrT2 = 0;
  ToneTVA_Env_ptrT3 = 0;
  ToneTVA_Env_ptrT4 = 0;
  ToneTVA_Env_t1Text = 0;
  ToneTVA_Env_t2Text = 0;
  ToneTVA_Env_t3Text = 0;
  ToneTVA_Env_t4Text = 0;
  ToneTVA_Env_sndText = 0;
  ToneTVA_Env_ptrSustain = 0;
  JVlibForm::ToneTVA_Env_display->setScene(ToneTVA_Env_scene);
  JVlibForm::ToneTVA_Env_display->show();
  
  ToneTVF_Env_scene = new QGraphicsScene;
  ToneTVF_Env_scene->setSceneRect(0, 0, 425, 175);
  QLineF ToneTVF_Env_t4(384,0,384,0);
  QLineF ToneTVF_Env_offLine(374,90,374,90);
  QLineF ToneTVF_Env_t1Mark(50,20,50,150);
  QLineF ToneTVF_Env_t2Mark(50,20,50,150);
  QLineF ToneTVF_Env_t3Mark(50,20,50,150);
  QLineF ToneTVF_Env_t4Mark(375,20,374,150);
  ToneTVF_Env_scene->addLine(40, 90, 380, 90, ToneEnv_blackLine);     // X axis
  ToneTVF_Env_scene->addLine(40, 20, 40, 157, ToneEnv_blackLine);    // Y axis
  ToneTVF_Env_scene->addLine(50,20,50,158,ToneEnv_dotLine);   // Note-On line
  ToneTVF_Env_scene->addLine(ToneTVF_Env_offLine,ToneEnv_dotLine);
  ToneTVF_Env_scene->addSimpleText("Cutoff\nFreq")->setPos(3,55);
  ToneTVF_Env_scene->addSimpleText("+")->setPos(30,20);
  ToneTVF_Env_scene->addSimpleText("-")->setPos(30,140);
  ToneTVF_Env_scene->addSimpleText("Time")->setPos(386,85);
  ToneTVF_Env_scene->addSimpleText("Key-On")->setPos(48,160);
  ToneTVF_Env_OffText = ToneTVF_Env_scene->addSimpleText("Key-Off");
  ToneTVF_Env_OffText->setPos(372,160);
  ToneTVF_Env_ptrT1 = 0;
  ToneTVF_Env_ptrT2 = 0;
  ToneTVF_Env_ptrT3 = 0;
  ToneTVF_Env_ptrT4 = 0;
  ToneTVF_Env_t1Text = 0;
  ToneTVF_Env_t2Text = 0;
  ToneTVF_Env_t3Text = 0;
  ToneTVF_Env_t4Text = 0;
  ToneTVF_Env_sndText = 0;
  ToneTVF_Env_ptrSustain = 0;
  JVlibForm::ToneTVF_Env_display->setScene(ToneTVF_Env_scene);
  JVlibForm::ToneTVF_Env_display->show();
  ToneTVF_Time1_select->setValue(1);
  ToneTVF_Time2_select->setValue(1);
  ToneTVF_Time3_select->setValue(1);
  ToneTVF_Time4_select->setValue(1);
  ToneTVA_Time1_select->setValue(1);
  ToneTVA_Time2_select->setValue(1);
  ToneTVA_Time3_select->setValue(1);
  ToneTVA_Time4_select->setValue(1);
}	// end createSysActions

