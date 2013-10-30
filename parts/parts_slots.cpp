// parts_slots.cpp
/* Contains:
 * on_PartsRangeLimitEnable_select_toggled
 * VoiceMode_select
 */
 
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::on_PartsRangeLimitEnable_select_toggled(bool val) {
    setPerfSingleValue(0x2F ,val);
}	// end on_PartsRangeLimitEnable_select_toggled

void JVlibForm::VoiceMode_select(bool checked) {
  qobject_cast<QPushButton *>(sender())->setText(checked ? "Solo" : "Poly");
  int chan;
  // let this change update the perf_mode values, block the returning signal
  if(sender()==Part1_VoiceMode_switch) {
    chan=0;
    if(state_table->perf_mode && Patch_PerfPartNum_select->currentIndex()==chan && state_table->part1_sync)
      Patch_VoiceMode_switch->setChecked(checked);
  }
  if(sender()==Part2_VoiceMode_switch)  {
    chan=1;
    if(state_table->perf_mode && Patch_PerfPartNum_select->currentIndex()==chan && state_table->part2_sync)
      Patch_VoiceMode_switch->setChecked(checked);
  }
  if(sender()==Part3_VoiceMode_switch)  {
    chan=2;
    if(state_table->perf_mode && Patch_PerfPartNum_select->currentIndex()==chan && state_table->part3_sync)
      Patch_VoiceMode_switch->setChecked(checked);
  }
  if(sender()==Part4_VoiceMode_switch)  {
    chan=3;
    if(state_table->perf_mode && Patch_PerfPartNum_select->currentIndex()==chan && state_table->part4_sync)
      Patch_VoiceMode_switch->setChecked(checked);
  }
  if(sender()==Part5_VoiceMode_switch) {
     chan=4;
    if(state_table->perf_mode && Patch_PerfPartNum_select->currentIndex()==chan && state_table->part5_sync)
      Patch_VoiceMode_switch->setChecked(checked);
  }
  if(sender()==Part6_VoiceMode_switch) {
     chan=5;
    if(state_table->perf_mode && Patch_PerfPartNum_select->currentIndex()==chan && state_table->part6_sync)
      Patch_VoiceMode_switch->setChecked(checked);
  }
  if(sender()==Part7_VoiceMode_switch) {
     chan=6;
    if(state_table->perf_mode && Patch_PerfPartNum_select->currentIndex()==chan && state_table->part7_sync)
      Patch_VoiceMode_switch->setChecked(checked);
  }
  if(sender()==Part8_VoiceMode_switch) {
     chan=7;
    if(state_table->perf_mode && Patch_PerfPartNum_select->currentIndex()==chan && state_table->part8_sync)
      Patch_VoiceMode_switch->setChecked(checked);
  }
  if(sender()==Part9_VoiceMode_switch) {
     chan=8;
    if(state_table->perf_mode && Patch_PerfPartNum_select->currentIndex()==chan && state_table->part9_sync)
      Patch_VoiceMode_switch->setChecked(checked);
  }
  if(sender()==Part11_VoiceMode_switch) {
     chan=10;
    if(state_table->perf_mode && Patch_PerfPartNum_select->currentIndex()==chan && state_table->part11_sync)
      Patch_VoiceMode_switch->setChecked(checked);
  }
  if(sender()==Part12_VoiceMode_switch) {
     chan=11;
    if(state_table->perf_mode && Patch_PerfPartNum_select->currentIndex()==chan && state_table->part12_sync)
      Patch_VoiceMode_switch->setChecked(checked);
  }
  if(sender()==Part13_VoiceMode_switch) {
     chan=12;
    if(state_table->perf_mode && Patch_PerfPartNum_select->currentIndex()==chan && state_table->part13_sync)
      Patch_VoiceMode_switch->setChecked(checked);
  }
  if(sender()==Part14_VoiceMode_switch) {
     chan=13;
    if(state_table->perf_mode && Patch_PerfPartNum_select->currentIndex()==chan && state_table->part14_sync)
      Patch_VoiceMode_switch->setChecked(checked);
  }
  if(sender()==Part15_VoiceMode_switch) {
     chan=14;
    if(state_table->perf_mode && Patch_PerfPartNum_select->currentIndex()==chan && state_table->part15_sync)
      Patch_VoiceMode_switch->setChecked(checked);
  }
  if(sender()==Part16_VoiceMode_switch) {
     chan=15;
    if(state_table->perf_mode && Patch_PerfPartNum_select->currentIndex()==chan && state_table->part16_sync)
      Patch_VoiceMode_switch->setChecked(checked);
  }
  if (state_table->GM_mode) {
      change_3(0xB0+chan, checked ? 0x7E : 0x7F, 0x00);
  }
}	// end VoiceMode_select
