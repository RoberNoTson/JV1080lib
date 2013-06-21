// set_initial.cpp
// for Parts tab
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setPartsParms() {
  // called after Performance tab Sync button is clicked and synth settings are downloaded to the active area
  // sets controls/displays so they match the synth, based on what is in the active area
  
  state_table->updates_enabled = false;
  PartsPerfName_display->setText(PerfName_edit->text());
  PartsPerfGroup_display->setText(PerfGroup_select->currentText());
  PartsPerfNumber_display->setText(QString::number(PerfNumber_select->value()));
  PartsRangeLimitEnable_select->setChecked(active_area->active_performance.perf_common.key_range_switch);
  setPart1_Parms();
  setPart2_Parms();
  setPart3_Parms();
  setPart4_Parms();
  setPart5_Parms();
  setPart6_Parms();
  setPart7_Parms();
  setPart8_Parms();
  setPart9_Parms();
  setPart10_Parms();
  setPart11_Parms();
  setPart12_Parms();
  setPart13_Parms();
  setPart14_Parms();
  setPart15_Parms();
  setPart16_Parms();
  setVoiceCounters();
  Patch_Sync_button->setEnabled(true);
  if (Patch_PerfPartNum_select->itemText(0)=="0")
    Patch_PerfPartNum_select->removeItem(0);
  Patch_PerfPartNum_select->setCurrentIndex(0);

  Patch_Group_select->setCurrentIndex(Part1_PatchGroup_select->currentIndex());
  Patch_Number_select->setValue(Part1_PatchNumber_select->value());
  Patch_Name_edit->setText(Part1_PatchName_display->text());
  Patch_PerfPartNum_select->setEnabled(true);
  Patch_Group_select->setEnabled(false);
  Patch_Number_select->setEnabled(false);
  Patch_Name_edit->setEnabled(false);
  state_table->updates_enabled = true;
}	// end setPartsParms

