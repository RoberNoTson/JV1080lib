// EFX12TremoloChorus.cpp
#include        "JVlibForm.h"
#include        <QtGui>
#include        "EFX/EFX.h"

void JVlibForm::EFX12TremoloChorus() {
  enable_4(true);
  enable_6(true);
  enable_7(true);
  enable_8(true);
  enable_9(false);
  enable_A(false);
  enable_B(false);
  enable_C(false);

  if (SysMode_select->currentIndex()==0 && MainTabWidget->currentIndex()==1) {	// get Performance EFX settings
    EFXparm1_label->setText(QString("PreDelay ms"));
    PerfEFXparm1_select->setRange(0, 127);
    PerfEFXparm1_select->setValue(active_area->active_performance.perf_common.EFX_parameter[0]);
    EFXparm2_label->setText(QString("Chorus Rate"));
    PerfEFXparm2_select->setRange(0, 127);
    PerfEFXparm2_select->setValue(active_area->active_performance.perf_common.EFX_parameter[1]);
    EFXparm3_label->setText(QString("Chorus Depth"));
    PerfEFXparm3_select->setRange(0, 127);
    PerfEFXparm3_select->setValue(active_area->active_performance.perf_common.EFX_parameter[2]);
    EFXparm4_label->setText(QString("Tremolo Rate"));
    PerfEFXparm4_select->setRange(0, 127);
    PerfEFXparm4_select->setValue(active_area->active_performance.perf_common.EFX_parameter[3]);
    EFXparm5_label->setText(QString("Tremolo Separation"));
    PerfEFXparm5_select->setRange(0, 127);
    PerfEFXparm5_select->setValue(active_area->active_performance.perf_common.EFX_parameter[4]);
    EFXparm6_label->setText(QString("Chorus Phase"));
    PerfEFXparm6_select->setRange(0, 90);
    PerfEFXparm6_select->setValue(active_area->active_performance.perf_common.EFX_parameter[5]);
    EFXparm7_label->setText(QString("Effect %"));
    PerfEFXparm7_select->setRange(0, 100);
    PerfEFXparm7_select->setValue(active_area->active_performance.perf_common.EFX_parameter[6]);
    EFXparm8_label->setText(QString("Output Level"));
    PerfEFXparm8_select->setRange(0, 127);
    PerfEFXparm8_select->setValue(active_area->active_performance.perf_common.EFX_parameter[7]);
  }
  
  if (MainTabWidget->currentIndex()>1) {		// PatchEFX tab settings for either Perf or Patch
    int val=Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt();		// 1-16 if Perfmode, 0 if Patch made
    int pn = (val>0 ? val-1 : 0);
    PatchEFX_parm1_label->setText(QString("PreDelay ms"));
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
    PatchEFX_parm4_label->setText(QString("Tremolo Rate"));
    PatchEFX_parm4_select->setRange(0, 127);
    PatchEFX_parm4_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[3] :
      active_area->active_patch_patch.patch_common.EFX_parameter[3]);
    PatchEFX_parm5_label->setText(QString("Tremolo Separation"));
    PatchEFX_parm5_select->setRange(0, 127);
    PatchEFX_parm5_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[4] :
      active_area->active_patch_patch.patch_common.EFX_parameter[4]);
    PatchEFX_parm6_label->setText(QString("Chorus Phase"));
    PatchEFX_parm6_select->setRange(0, 90);
    PatchEFX_parm6_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[5] :
      active_area->active_patch_patch.patch_common.EFX_parameter[5]);
    PatchEFX_parm7_label->setText(QString("Effect %"));
    PatchEFX_parm7_select->setRange(0, 100);
    PatchEFX_parm7_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[6] :
      active_area->active_patch_patch.patch_common.EFX_parameter[6]);
    PatchEFX_parm8_label->setText(QString("Output Level"));
    PatchEFX_parm8_select->setRange(0, 127);
    PatchEFX_parm8_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[7] :
      active_area->active_patch_patch.patch_common.EFX_parameter[7]);
  }
}	// end EFX12TremoloChorus

