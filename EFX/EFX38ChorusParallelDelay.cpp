// EFX38ChorusParallelDelay.cpp

#include	"JVlibForm.h"
#include	<QtGui>
#include	"EFX/EFX.h"

void JVlibForm::EFX38ChorusParallelDelay() {
      enable_4(false);
      enable_6(true);
      enable_7(true);
      enable_8(true);
      enable_9(true);
      enable_A(true);
      enable_B(false);
      enable_C(false);

  if (state_table->perf_mode && MainTabWidget->currentIndex()==1) {	// get Performance EFX settings
      EFXparm1_label->setText(QString("Chorus PreDelay"));
      PerfEFXparm1_select->setRange(0, 127);
      PerfEFXparm1_select->setValue(active_area->active_performance.perf_common.EFX_parameter[0]);
      EFXparm2_label->setText(QString("Chorus Rate"));
      PerfEFXparm2_select->setRange(0, 127);
      PerfEFXparm2_select->setValue(active_area->active_performance.perf_common.EFX_parameter[1]);
      EFXparm3_label->setText(QString("Chorus Depth"));
      PerfEFXparm3_select->setRange(0, 127);
      PerfEFXparm3_select->setValue(active_area->active_performance.perf_common.EFX_parameter[2]);
      EFXparm5_label->setText(QString("Chorus Balance"));
      PerfEFXparm5_select->setRange(0, 100);
      PerfEFXparm5_select->setValue(active_area->active_performance.perf_common.EFX_parameter[4]);
      EFXparm6_label->setText(QString("Delay Time"));
      PerfEFXparm6_select->setRange(0, 127);
      PerfEFXparm6_select->setValue(active_area->active_performance.perf_common.EFX_parameter[5]);
      EFXparm7_label->setText(QString("Delay Feedback"));
      PerfEFXparm7_select->setRange(0, 98);
      PerfEFXparm7_select->setValue(active_area->active_performance.perf_common.EFX_parameter[6]);
      EFXparm8_label->setText(QString("Delay HFDamp"));
      PerfEFXparm8_select->setRange(0, 17);
      PerfEFXparm8_select->setValue(active_area->active_performance.perf_common.EFX_parameter[7]);
      EFXparm9_label->setText(QString("Delay Balance"));
      PerfEFXparm9_select->setRange(0, 100);
      PerfEFXparm9_select->setValue(active_area->active_performance.perf_common.EFX_parameter[8]);
      EFXparmA_label->setText(QString("Output Level"));
      PerfEFXparmA_select->setRange(0, 127);
      PerfEFXparmA_select->setValue(active_area->active_performance.perf_common.EFX_parameter[9]);
  }	// end set Performance Tab EFX parms 
  
  if (MainTabWidget->currentIndex()>1) {		// PatchEFX tab settings for either Perf or Patch
    int val=Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt();		// 1-16 if Perfmode, 0 if Patch made
    int pn = (val>0 ? val-1 : 0);
    PatchEFX_parm1_label->setText(QString("Chorus PreDelay"));
    PatchEFX_parm1_select->setRange(0, 127);
    PatchEFX_parm1_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[0] :
      active_area->active_patch_patch.patch_common.EFX_parameter[0]);
    PatchEFX_parm2_label->setText(QString("Chorus Rate"));
    PatchEFX_parm2_select->setRange(0, 127);
    PatchEFX_parm2_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[1] :
      active_area->active_patch_patch.patch_common.EFX_parameter[1]);
    PatchEFX_parm3_label->setText(QString("Chorus Depth"));
    PatchEFX_parm3_select->setRange(0, 127);
    PatchEFX_parm3_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[2] :
      active_area->active_patch_patch.patch_common.EFX_parameter[2]);
    PatchEFX_parm5_label->setText(QString("Chorus Balance"));
    PatchEFX_parm5_select->setRange(0, 100);
    PatchEFX_parm5_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[4] :
      active_area->active_patch_patch.patch_common.EFX_parameter[4]);
    PatchEFX_parm6_label->setText(QString("Delay Time"));
    PatchEFX_parm6_select->setRange(0, 127);
    PatchEFX_parm6_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[5] :
      active_area->active_patch_patch.patch_common.EFX_parameter[5]);
    PatchEFX_parm7_label->setText(QString("Delay Feedback"));
    PatchEFX_parm7_select->setRange(0, 98);
    PatchEFX_parm7_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[6] :
      active_area->active_patch_patch.patch_common.EFX_parameter[6]);
    PatchEFX_parm8_label->setText(QString("Delay HFDamp"));
    PatchEFX_parm8_select->setRange(0, 17);
    PatchEFX_parm8_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[7] :
      active_area->active_patch_patch.patch_common.EFX_parameter[7]);
    PatchEFX_parm9_label->setText(QString("Delay Balance"));
    PatchEFX_parm9_select->setRange(0, 100);
    PatchEFX_parm9_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[8] :
      active_area->active_patch_patch.patch_common.EFX_parameter[8]);
    PatchEFX_parmA_label->setText(QString("Output Level"));
    PatchEFX_parmA_select->setRange(0, 127);
    PatchEFX_parmA_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[9] :
      active_area->active_patch_patch.patch_common.EFX_parameter[9]);
  }
}	// end EFX38ChorusParallelDelay
