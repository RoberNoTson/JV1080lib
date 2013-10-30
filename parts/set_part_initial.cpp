// set_part_initial.cpp
/* Contains:
 * setPartsParms
 */

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setPartsParms() {
  // called after Performance tab Sync button is clicked and synth settings are downloaded to the active area
  // sets controls/displays so they match the synth, based on what is in the active area
  
  state_table->updates_enabled = false;
  // these can be set in Performance mode or GM mode
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
  connect(Part1_VoiceMode_switch, SIGNAL(toggled(bool)), this, SLOT(VoiceMode_select(bool)));
  connect(Part2_VoiceMode_switch, SIGNAL(toggled(bool)), this, SLOT(VoiceMode_select(bool)));
  connect(Part3_VoiceMode_switch, SIGNAL(toggled(bool)), this, SLOT(VoiceMode_select(bool)));
  connect(Part4_VoiceMode_switch, SIGNAL(toggled(bool)), this, SLOT(VoiceMode_select(bool)));
  connect(Part5_VoiceMode_switch, SIGNAL(toggled(bool)), this, SLOT(VoiceMode_select(bool)));
  connect(Part6_VoiceMode_switch, SIGNAL(toggled(bool)), this, SLOT(VoiceMode_select(bool)));
  connect(Part7_VoiceMode_switch, SIGNAL(toggled(bool)), this, SLOT(VoiceMode_select(bool)));
  connect(Part8_VoiceMode_switch, SIGNAL(toggled(bool)), this, SLOT(VoiceMode_select(bool)));
  connect(Part9_VoiceMode_switch, SIGNAL(toggled(bool)), this, SLOT(VoiceMode_select(bool)));
  connect(Part11_VoiceMode_switch, SIGNAL(toggled(bool)), this, SLOT(VoiceMode_select(bool)));
  connect(Part12_VoiceMode_switch, SIGNAL(toggled(bool)), this, SLOT(VoiceMode_select(bool)));
  connect(Part13_VoiceMode_switch, SIGNAL(toggled(bool)), this, SLOT(VoiceMode_select(bool)));
  connect(Part14_VoiceMode_switch, SIGNAL(toggled(bool)), this, SLOT(VoiceMode_select(bool)));
  connect(Part15_VoiceMode_switch, SIGNAL(toggled(bool)), this, SLOT(VoiceMode_select(bool)));
  connect(Part16_VoiceMode_switch, SIGNAL(toggled(bool)), this, SLOT(VoiceMode_select(bool)));
  // following items only apply in Perf mode, not GM
  if (state_table->perf_mode) {
    setVoiceCounters();
    PartsPerfName_display->setText(PerfName_edit->text());
    PartsPerfGroup_display->setText(PerfGroup_select->currentText());
    PartsPerfNumber_display->setText(QString::number(PerfNumber_select->value()));
    PartsRangeLimitEnable_select->setChecked(active_area->active_performance.perf_common.key_range_switch);
    // update Patch tab items
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
  }	// end if perf_mode
  // following items only apply in GM mode, not Perf
  if (state_table->GM_mode) {
    
  }
  state_table->updates_enabled = true;
}	// end setPartsParms

