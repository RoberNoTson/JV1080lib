// EFX31DistortionSeriesDelay.cpp

#include	"JVlibForm.h"
#include	<QtGui>
#include	"EFX/EFX.h"

void JVlibForm::EFX31DistortionSeriesDelay() {
      enable_4(true);
      enable_6(true);
      enable_7(true);
      enable_8(false);
      enable_9(false);
      enable_A(false);
      enable_B(false);
      enable_C(false);
      
  if (state_table->perf_mode && MainTabWidget->currentIndex()==1) {	// get Performance EFX settings
      EFXparm1_label->setText(QString("Drive"));
      PerfEFXparm1_select->setRange(0, 127);
      PerfEFXparm1_select->setValue(active_area->active_performance.perf_common.EFX_parameter[0]);
      EFXparm2_label->setText(QString("Overdrive Pan"));
      PerfEFXparm2_select->setRange(0, 127);
      PerfEFXparm2_select->setValue(active_area->active_performance.perf_common.EFX_parameter[1]);
      EFXparm3_label->setText(QString("Delay Time"));
      PerfEFXparm3_select->setRange(0, 127);
      PerfEFXparm3_select->setValue(active_area->active_performance.perf_common.EFX_parameter[2]);
      EFXparm4_label->setText(QString("Delay Feedback"));
      PerfEFXparm4_select->setRange(0, 98);
      PerfEFXparm4_select->setValue(active_area->active_performance.perf_common.EFX_parameter[3]);
      EFXparm5_label->setText(QString("Delay HFDamp"));
      PerfEFXparm5_select->setRange(0, 17);
      PerfEFXparm5_select->setValue(active_area->active_performance.perf_common.EFX_parameter[4]);
      EFXparm6_label->setText(QString("Delay Balance"));
      PerfEFXparm6_select->setRange(0, 100);
      PerfEFXparm6_select->setValue(active_area->active_performance.perf_common.EFX_parameter[5]);
      EFXparm7_label->setText(QString("Output Level"));
      PerfEFXparm7_select->setRange(0, 127);
      PerfEFXparm7_select->setValue(active_area->active_performance.perf_common.EFX_parameter[6]);
  }	// end set Perf Tab EFX
    if (MainTabWidget->currentIndex()>1) {		// PatchEFX tab settings for either Perf or Patch
    int pn = 0;
    int val = Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt();
    if (state_table->perf_mode) 
      pn = Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()-1;
    PatchEFX_parm1_label->setText(QString("Drive"));
    PatchEFX_parm1_select->setRange(0, 127);
    PatchEFX_parm1_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[0] :
      active_area->active_patch_patch.patch_common.EFX_parameter[0]);
    PatchEFX_parm2_label->setText(QString("Overdrive Pan"));
    PatchEFX_parm2_select->setRange(0, 127);
    PatchEFX_parm2_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[1] :
      active_area->active_patch_patch.patch_common.EFX_parameter[1]);
    PatchEFX_parm3_label->setText(QString("Delay Time"));
    PatchEFX_parm3_select->setRange(0, 127);
    PatchEFX_parm3_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[2] :
      active_area->active_patch_patch.patch_common.EFX_parameter[2]);
    PatchEFX_parm4_label->setText(QString("Delay Feedback"));
    PatchEFX_parm4_select->setRange(0, 98);
    PatchEFX_parm4_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[3] :
      active_area->active_patch_patch.patch_common.EFX_parameter[3]);
    PatchEFX_parm5_label->setText(QString("Delay HFDamp"));
    PatchEFX_parm5_select->setRange(0, 17);
    PatchEFX_parm5_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[4] :
      active_area->active_patch_patch.patch_common.EFX_parameter[4]);
    PatchEFX_parm6_label->setText(QString("Delay Balance"));
    PatchEFX_parm6_select->setRange(0, 100);
    PatchEFX_parm6_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[5] :
      active_area->active_patch_patch.patch_common.EFX_parameter[5]);
    PatchEFX_parm7_label->setText(QString("Output Level"));
    PatchEFX_parm7_select->setRange(0, 127);
    PatchEFX_parm7_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[6] :
      active_area->active_patch_patch.patch_common.EFX_parameter[6]);
    } 
  }	// end EFX31DistortionSeriesDelay
