// toneEFX.cpp
#include	"JVlibForm.h"
#include	<QtGui>

void JVlibForm::Enable_ToneEFX(bool val) {
  ToneEFX_PanControl_select->setEnabled(val);
  ToneEFX_Pan_select->setEnabled(ToneEFX_PanControl_select->currentIndex() && val?true:false);
  ToneEFX_AltPan_select->setEnabled(ToneEFX_PanControl_select->currentIndex() && val?true:false);
  ToneEFX_PanLFO1Depth_select->setEnabled(ToneEFX_PanControl_select->currentIndex() && val?true:false);
  ToneEFX_PanLFO2Depth_select->setEnabled(ToneEFX_PanControl_select->currentIndex() && val?true:false);
  ToneEFX_PanRandDepth_select->setEnabled(ToneEFX_PanControl_select->currentIndex() && val?true:false);
  ToneEFX_PanKeyFollow_select->setEnabled(ToneEFX_PanControl_select->currentIndex() && val?true:false);
}	// end Enable_ToneEFX
