// EFX18ModulationDelay.cpp

#include	"JVlibForm.h"
#include	<QtGui>
#include	"EFX/EFX.h"

void JVlibForm::EFX18ModulationDelay() {
      enable_4(true);
      enable_6(true);
      enable_7(true);
      enable_8(true);
      enable_9(true);
      enable_A(true);
      enable_B(true);
      enable_C(true);
      
  if (state_table->perf_mode && MainTabWidget->currentIndex()==1) {	// get Performance EFX settings
      EFXparm1_label->setText(QString("Feedback Mode"));
      PerfEFXparm1_select->setRange(0, 1);
      PerfEFXparm1_select->setValue(active_area->active_performance.perf_common.EFX_parameter[0]);
      EFXparm2_label->setText(QString("Left Delay Time"));
      PerfEFXparm2_select->setRange(0, 127);
      PerfEFXparm2_select->setValue(active_area->active_performance.perf_common.EFX_parameter[1]);
      EFXparm3_label->setText(QString("Right Delay Time"));
      PerfEFXparm3_select->setRange(0, 127);
      PerfEFXparm3_select->setValue(active_area->active_performance.perf_common.EFX_parameter[2]);
      EFXparm4_label->setText(QString("Feedback"));
      PerfEFXparm4_select->setRange(0, 98);
      PerfEFXparm4_select->setValue(active_area->active_performance.perf_common.EFX_parameter[3]);
      EFXparm5_label->setText(QString("High Freq Dampen"));
      PerfEFXparm5_select->setRange(0, 17);
      PerfEFXparm5_select->setValue(active_area->active_performance.perf_common.EFX_parameter[4]);
      EFXparm6_label->setText(QString("Modulation Rate"));
      PerfEFXparm6_select->setRange(0, 127);
      PerfEFXparm6_select->setValue(active_area->active_performance.perf_common.EFX_parameter[5]);
      EFXparm7_label->setText(QString("Modulation Depth"));
      PerfEFXparm7_select->setRange(0, 127);
      PerfEFXparm7_select->setValue(active_area->active_performance.perf_common.EFX_parameter[6]);
      EFXparm8_label->setText(QString("Phase"));
      PerfEFXparm8_select->setRange(0, 90);
      PerfEFXparm8_select->setValue(active_area->active_performance.perf_common.EFX_parameter[7]);
      EFXparm9_label->setText(QString("Low Gain"));
      PerfEFXparm9_select->setRange(0, 30);
      PerfEFXparm9_select->setValue(active_area->active_performance.perf_common.EFX_parameter[8]);
      EFXparmA_label->setText(QString("High Gain"));
      PerfEFXparmA_select->setRange(0, 30);
      PerfEFXparmA_select->setValue(active_area->active_performance.perf_common.EFX_parameter[9]);
      EFXparmB_label->setText(QString("Balance"));
      PerfEFXparmB_select->setRange(0, 100);
      PerfEFXparmB_select->setValue(active_area->active_performance.perf_common.EFX_parameter[10]);
      EFXparmC_label->setText("Output Level");
      PerfEFXparmC_select->setRange(0, 127);
      PerfEFXparmC_select->setValue(active_area->active_performance.perf_common.EFX_parameter[11]);
  }
  
  if (MainTabWidget->currentIndex()>1) {		// PatchEFX tab settings for either Perf or Patch
    int val=Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt();		// 1-16 if Perfmode, 0 if Patch made
    int pn = (val>0 ? val-1 : 0);
      PatchEFX_parm1_label->setText(QString("Feedback Mode"));
      PatchEFX_parm1_select->setRange(0, 1);
    PatchEFX_parm1_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[0] :
      active_area->active_patch_patch.patch_common.EFX_parameter[0]);
      PatchEFX_parm2_label->setText(QString("Left Delay Time"));
      PatchEFX_parm2_select->setRange(0, 127);
    PatchEFX_parm2_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[1] :
      active_area->active_patch_patch.patch_common.EFX_parameter[1]);
      PatchEFX_parm3_label->setText(QString("Right Delay Time"));
      PatchEFX_parm3_select->setRange(0, 127);
    PatchEFX_parm3_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[2] :
      active_area->active_patch_patch.patch_common.EFX_parameter[2]);
      PatchEFX_parm4_label->setText(QString("Feedback"));
      PatchEFX_parm4_select->setRange(0, 98);
    PatchEFX_parm4_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[3] :
      active_area->active_patch_patch.patch_common.EFX_parameter[3]);
      PatchEFX_parm5_label->setText(QString("High Freq Dampen"));
      PatchEFX_parm5_select->setRange(0, 17);
    PatchEFX_parm5_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[4] :
      active_area->active_patch_patch.patch_common.EFX_parameter[4]);
      PatchEFX_parm6_label->setText(QString("Modulation Rate"));
      PatchEFX_parm6_select->setRange(0, 127);
    PatchEFX_parm6_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[5] :
      active_area->active_patch_patch.patch_common.EFX_parameter[5]);
      PatchEFX_parm7_label->setText(QString("Modulation Depth"));
      PatchEFX_parm7_select->setRange(0, 127);
    PatchEFX_parm7_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[6] :
      active_area->active_patch_patch.patch_common.EFX_parameter[6]);
      PatchEFX_parm8_label->setText(QString("Phase"));
      PatchEFX_parm8_select->setRange(0, 90);
    PatchEFX_parm8_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[7] :
      active_area->active_patch_patch.patch_common.EFX_parameter[7]);
      PatchEFX_parm9_label->setText(QString("Low Gain"));
      PatchEFX_parm9_select->setRange(0, 30);
    PatchEFX_parm9_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[8] :
      active_area->active_patch_patch.patch_common.EFX_parameter[8]);
      PatchEFX_parmA_label->setText(QString("High Gain"));
      PatchEFX_parmA_select->setRange(0, 30);
    PatchEFX_parmA_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[9] :
      active_area->active_patch_patch.patch_common.EFX_parameter[9]);
      PatchEFX_parmB_label->setText(QString("Balance"));
      PatchEFX_parmB_select->setRange(0, 100);
    PatchEFX_parmB_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[10] :
      active_area->active_patch_patch.patch_common.EFX_parameter[10]);
      PatchEFX_parmC_label->setText("Output Level");
      PatchEFX_parmC_select->setRange(0, 127);
    PatchEFX_parmC_select->setValue(val>0 ?
      active_area->active_perf_patch[pn].patch_common.EFX_parameter[11] :
      active_area->active_patch_patch.patch_common.EFX_parameter[11]);
  }
}	// end EFX18ModulationDelay
