// EFX07autoWah.cpp
// Auto-Wah parms

#include        "JVlibForm.h"
#include        <QtGui>
#include        "EFX/EFX.h"

void JVlibForm::EFX07autoWah() {
  enable_4(true);
  enable_6(true);
  enable_7(true);
  enable_8(false);
  enable_9(false);
  enable_A(false);
  enable_B(false);
  enable_C(false);
  
  if (SysMode_select->currentIndex()==0 && MainTabWidget->currentIndex()==1) {	// get Performance EFX settings
    EFXparm1_label->setText(QString("Filter Type"));
    PerfEFXparm1_select->setRange(0, 1);
    PerfEFXparm1_select->setValue(active_area->active_performance.perf_common.EFX_parameter[0]);
    EFXparm2_label->setText(QString("LFO Rate"));
    PerfEFXparm2_select->setRange(0, 125);
    PerfEFXparm2_select->setValue(active_area->active_performance.perf_common.EFX_parameter[1]);
    EFXparm3_label->setText(QString("LFO Depth"));
    PerfEFXparm3_select->setRange(0, 127);
    PerfEFXparm3_select->setValue(active_area->active_performance.perf_common.EFX_parameter[2]);
    EFXparm4_label->setText(QString("Sensitivity"));
    PerfEFXparm4_select->setRange(0, 127);
    PerfEFXparm4_select->setValue(active_area->active_performance.perf_common.EFX_parameter[3]);
    EFXparm5_label->setText(QString("Reference Frequency"));
    PerfEFXparm5_select->setRange(0, 127);
    PerfEFXparm5_select->setValue(active_area->active_performance.perf_common.EFX_parameter[4]);
    EFXparm6_label->setText(QString("Peak"));
    PerfEFXparm6_select->setRange(0, 127);
    PerfEFXparm6_select->setValue(active_area->active_performance.perf_common.EFX_parameter[5]);
    EFXparm7_label->setText(QString("Output Level"));
    PerfEFXparm7_select->setRange(0, 127);
    PerfEFXparm7_select->setValue(active_area->active_performance.perf_common.EFX_parameter[6]);
  }
  
  if (MainTabWidget->currentIndex()>1) {		// PatchEFX tab settings for either Perf or Patch
    int val=Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt();		// 1-16 if Perfmode, 0 if Patch made
    int pn = (val>0 ? val-1 : 0);
    PatchEFX_parm1_label->setText(QString("Filter Type"));
    PatchEFX_parm1_select->setRange(0, 1);
    PatchEFX_parm1_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[0] :
      active_area->active_patch_patch.patch_common.EFX_parameter[0]);
    PatchEFX_parm2_label->setText(QString("LFO Rate"));
    PatchEFX_parm2_select->setRange(0, 125);
    PatchEFX_parm2_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[1] :
      active_area->active_patch_patch.patch_common.EFX_parameter[1]);
    PatchEFX_parm3_label->setText(QString("LFO Depth"));
    PatchEFX_parm3_select->setRange(0, 127);
    PatchEFX_parm3_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[2] :
      active_area->active_patch_patch.patch_common.EFX_parameter[2]);
    PatchEFX_parm4_label->setText(QString("Sensitivity"));
    PatchEFX_parm4_select->setRange(0, 127);
    PatchEFX_parm4_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[3] :
      active_area->active_patch_patch.patch_common.EFX_parameter[3]);
    PatchEFX_parm5_label->setText(QString("Reference Frequency"));
    PatchEFX_parm5_select->setRange(0, 127);
    PatchEFX_parm5_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[4] :
      active_area->active_patch_patch.patch_common.EFX_parameter[4]);
    PatchEFX_parm6_label->setText(QString("Peak"));
    PatchEFX_parm6_select->setRange(0, 127);
    PatchEFX_parm6_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[5] :
      active_area->active_patch_patch.patch_common.EFX_parameter[5]);
    PatchEFX_parm7_label->setText(QString("Output Level"));
    PatchEFX_parm7_select->setRange(0, 127);
    PatchEFX_parm7_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[6] :
      active_area->active_patch_patch.patch_common.EFX_parameter[6]);
  }
} // end EFXautoWah

