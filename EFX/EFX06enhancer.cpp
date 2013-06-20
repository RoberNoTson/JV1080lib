// EFX06enhancer.cpp
// Enhancer parms
#include        "JVlibForm.h"
#include        <QtGui>
#include        "EFX/EFX.h"

void JVlibForm::EFX06enhancer() {
  enable_4(true);
  enable_6(false);
  enable_7(false);
  enable_8(false);
  enable_9(false);
  enable_A(false);
  enable_B(false);
  enable_C(false);

  if (SysMode_select->currentIndex()==0 && MainTabWidget->currentIndex()==1) {	// get Performance EFX settings
    EFXparm1_label->setText(QString("Sensitivity"));
    PerfEFXparm1_select->setRange(0, 127);
    PerfEFXparm1_select->setValue(active_area->active_performance.perf_common.EFX_parameter[0]);
    EFXparm2_label->setText(QString("Mix Level"));
    PerfEFXparm2_select->setRange(0, 127);
    PerfEFXparm2_select->setValue(active_area->active_performance.perf_common.EFX_parameter[1]);
    EFXparm3_label->setText(QString("Low Gain"));
    PerfEFXparm3_select->setRange(0, 30);
    PerfEFXparm3_select->setValue(active_area->active_performance.perf_common.EFX_parameter[2]);
    EFXparm4_label->setText(QString("High Gain"));
    PerfEFXparm4_select->setRange(0, 30);
    PerfEFXparm4_select->setValue(active_area->active_performance.perf_common.EFX_parameter[3]);
    EFXparm5_label->setText(QString("Output Level"));
    PerfEFXparm5_select->setRange(0, 127);
    PerfEFXparm5_select->setValue(active_area->active_performance.perf_common.EFX_parameter[4]);
  }
  
  if (MainTabWidget->currentIndex()>1) {		// PatchEFX tab settings for either Perf or Patch
    int val=Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt();		// 1-16 if Perfmode, 0 if Patch made
    int pn = (val>0 ? val-1 : 0);
    PatchEFX_parm1_label->setText(QString("Sensitivity"));
    PatchEFX_parm1_select->setRange(0, 127);
    PatchEFX_parm1_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[0] :
      active_area->active_patch_patch.patch_common.EFX_parameter[0]);
    PatchEFX_parm2_label->setText(QString("Mix Level"));
    PatchEFX_parm2_select->setRange(0, 127);
    PatchEFX_parm2_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[1] :
      active_area->active_patch_patch.patch_common.EFX_parameter[1]);
    PatchEFX_parm3_label->setText(QString("Low Gain"));
    PatchEFX_parm3_select->setRange(0, 30);
    PatchEFX_parm3_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[2] :
      active_area->active_patch_patch.patch_common.EFX_parameter[2]);
    PatchEFX_parm4_label->setText(QString("High Gain"));
    PatchEFX_parm4_select->setRange(0, 30);
    PatchEFX_parm4_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[3] :
      active_area->active_patch_patch.patch_common.EFX_parameter[3]);
    PatchEFX_parm5_label->setText(QString("Output Level"));
    PatchEFX_parm5_select->setRange(0, 127);
    PatchEFX_parm5_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[4] :
      active_area->active_patch_patch.patch_common.EFX_parameter[4]);
  }
} // end EFXenhancer

