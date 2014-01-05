// part_10.cpp
/* Contains:
 * on_Part10_TestTone_switch_toggled
 * on_Part10_ReceiveMidi_enable_toggled
 * on_Part10_MidiChannel_select_valueChanged
 * on_Part10_Level_select_valueChanged
 * on_Part10_Pan_select_valueChanged
 * on_Part10_Transpose_select_valueChanged
 * on_Part10_TuneAdj_select_valueChanged
 * on_Part10_Output_select_currentIndexChanged
 * on_Part10_OutputLevel_select_valueChanged
 * on_Part10_ChorusSend_select_valueChanged
 * on_Part10_ReverbSend_select_valueChanged
 * on_Part10_ReceivePrgChg_enable_toggled
 * on_Part10_ReceiveVolume_enable_toggled
 * on_Part10_ReceiveHold_enable_toggled
 * on_Part10_LowLimit_select_valueChanged
 * on_Part10_HighLimit_select_valueChanged
 * on_Part10_VoiceReserve_select_valueChanged
 * on_Part10_PatchGroup_select_currentIndexChanged
 * on_Part10_PatchNumber_select_valueChanged
 */

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::on_Part10_TestTone_switch_toggled(bool val) {
  PartsToneSwitch(Part10_MidiChannel_select->value()-1, val);
  Part10_TestTone_switch->setText(val ? QString::fromUtf8("Stop") : QString::fromUtf8("Play Patch") );
}

//---------------------------------------------------------------------------------------------------------------------
// switches
void JVlibForm::on_Part10_ReceiveMidi_enable_toggled(bool val) {
  Rhythm_TestTone_switch->setEnabled(val && state_table->rhythm_sync);
  Rhythm_ReceiveMidi_enable->blockSignals(true);
  Rhythm_ReceiveMidi_enable->setChecked(val);
  Rhythm_ReceiveMidi_enable->blockSignals(false);
  setPartSingleValue(9,0,val);
}
void JVlibForm::on_Part10_MidiChannel_select_valueChanged(int val) {
  if (state_table->perf_mode) setPartSingleValue(9,1,val-1);
}
void JVlibForm::on_Part10_Level_select_valueChanged(int val) {
  Part10_Level_select->setStatusTip(QString::number(val));
  if (state_table->perf_mode) setPartSingleValue(9,6,val);
  if (state_table->GM_mode && state_table->updates_enabled) change_3(0xB0+Part10_MidiChannel_select->value()-1,0x07,val);
}
void JVlibForm::on_Part10_Pan_select_valueChanged(int val) {
//  Part10_Pan_select->setStatusTip(QString("Pan value: ")+QString::number(val));
  if (state_table->perf_mode) setPartSingleValue(9,7,val+64);
  if (state_table->GM_mode && state_table->updates_enabled) change_3(0xB0+Part10_MidiChannel_select->value()-1,0x0A,val+64);
}
void JVlibForm::on_Part10_Transpose_select_valueChanged(int val) { 
  // val is between -48,+48 half-steps
  if (state_table->perf_mode) setPartSingleValue(9, 0x8, val+48);
  // GM wants val between 10h,70h (16->112)
  if (state_table->GM_mode && state_table->updates_enabled) change_12(0xB0+Part10_MidiChannel_select->value()-1,0x65,0x00,0xB0+Part10_MidiChannel_select->value()-1,0x64,0x02,0xB0+Part10_MidiChannel_select->value()-1,0x06,(val+64),0xB0+Part10_MidiChannel_select->value()-1,0x26,0x00);
}
void JVlibForm::on_Part10_TuneAdj_select_valueChanged(int val) { 
  // val is between -50,+50 cents
  if (state_table->perf_mode) setPartSingleValue(9, 0x9, val+50);
  // GM wants val between 20h,60h (32->96)
  if (state_table->GM_mode && state_table->updates_enabled) change_12(0xB0+Part10_MidiChannel_select->value()-1,0x65,0x00,0xB0+Part10_MidiChannel_select->value()-1,0x64,0x01,0xB0+Part10_MidiChannel_select->value()-1,0x06,(val+50)*65/101+32,0xB0+Part10_MidiChannel_select->value()-1,0x26,0x00);
}
void JVlibForm::on_Part10_Output_select_currentIndexChanged(int val) {
  if (state_table->perf_mode) setPartSingleValue(9,0xA,val);
}
void JVlibForm::on_Part10_OutputLevel_select_valueChanged(int val) {
  if (state_table->perf_mode) setPartSingleValue(9,0xB,val);
}
void JVlibForm::on_Part10_ChorusSend_select_valueChanged(int val) {
  if (state_table->perf_mode) setPartSingleValue(9,0xC,val);
  if (state_table->GM_mode && state_table->updates_enabled) change_3(0xB0+Part10_MidiChannel_select->value()-1,0x5D,val);
}
void JVlibForm::on_Part10_ReverbSend_select_valueChanged(int val) {
  if (state_table->perf_mode) setPartSingleValue(9,0xD,val);
  if (state_table->GM_mode && state_table->updates_enabled) change_3(0xB0+Part10_MidiChannel_select->value()-1,0x5B,val);
}
void JVlibForm::on_Part10_ReceivePrgChg_enable_toggled(bool val) {
    setPartSingleValue(9,0xE,val);
}
void JVlibForm::on_Part10_ReceiveVolume_enable_toggled(bool val) {
  if (state_table->perf_mode) setPartSingleValue(9,0xF,val);
}
void JVlibForm::on_Part10_ReceiveHold_enable_toggled(bool val) {
  if (state_table->perf_mode) setPartSingleValue(9,0x10,val);
}
void JVlibForm::on_Part10_LowLimit_select_valueChanged(int val) { 
  Part10_LowLimit_display->setText(funcNoteCalc(val));
  if (val>Part10_HighLimit_select->value()) on_Part10_HighLimit_select_valueChanged(val);
  setPartSingleValue(9, 0x11, val);
}
void JVlibForm::on_Part10_HighLimit_select_valueChanged(int val) { 
  Part10_HighLimit_display->setText(funcNoteCalc(val));
  if (val<Part10_LowLimit_select->value()) on_Part10_LowLimit_select_valueChanged(val);
  setPartSingleValue(9, 0x12, val);
}
void JVlibForm::on_Part10_VoiceReserve_select_valueChanged(int val) { 
  if (setVoiceCounters(10))
    setPerfSingleValue(0x30+9,val);
}

//---------------------------------------------------------------------------------------------------------------------
void JVlibForm::on_Part10_PatchGroup_select_currentIndexChanged(int val) {
  // called after a change in the Patch group or number for this part to update the Patch Name and active_area memory
 if (!state_table->updates_enabled) return;
  switch(val) {
    case 0:	// User patch
      Part10_PatchNumber_select->setMaximum(128);
      active_area->active_performance.perf_part[9].patch_group = 0x0;
      active_area->active_performance.perf_part[9].patch_group_id = 0x01;
      break;
    case 1:	// PresetA
      Part10_PatchNumber_select->setMaximum(128);
      active_area->active_performance.perf_part[9].patch_group = 0x00;
      active_area->active_performance.perf_part[9].patch_group_id = 0x03;
      break;
    case 2:	// PresetB
      Part10_PatchNumber_select->setMaximum(128);
      active_area->active_performance.perf_part[9].patch_group = 0x00;
      active_area->active_performance.perf_part[9].patch_group_id = 0x04;
      break;
    case 3:	// PresetC
      Part10_PatchNumber_select->setMaximum(128);
      active_area->active_performance.perf_part[9].patch_group = 0x00;
      active_area->active_performance.perf_part[9].patch_group_id = 0x05;
      break;
    case 4:	// PresetD
      Part10_PatchNumber_select->setMaximum(128);
      active_area->active_performance.perf_part[9].patch_group = 0x00;
      active_area->active_performance.perf_part[9].patch_group_id = 0x06;
      break;
    case 5:	// Exp B
      Part10_PatchNumber_select->setMaximum(256);
      active_area->active_performance.perf_part[9].patch_group = 0x02;
      active_area->active_performance.perf_part[9].patch_group_id = 0x10;
      break;
    default:
      Part10_PatchNumber_select->setMaximum(128);
      active_area->active_performance.perf_part[9].patch_group = 0x00;
      active_area->active_performance.perf_part[9].patch_group_id = 0x00;
      break;
  }	// end switch set Patch group
  // update perf_part.patch_num_high/low
  int pn = Part10_PatchNumber_select->value() - 1;
  active_area->active_performance.perf_part[9].patch_num_high = pn/16;
  active_area->active_performance.perf_part[9].patch_num_low = pn%16;
  if (!state_table->jv_connect) return;
  // update JV  
  unsigned char	buf[8];
  memset(buf,0,sizeof(buf));
  buf[0] = 0x01;
  buf[2] = 0x10 + 0x09;
  buf[3] = 0x02;
  memcpy((void *)&buf[4], (const void *)&active_area->active_performance.perf_part[9].patch_group,4);
  if (sysex_update((const unsigned char*)&buf,8) == EXIT_FAILURE) {
    puts("OOPS 2!"); return;
  }
 Part10_PatchName_display->setText(getPartPatchName(9));
  if (state_table->rhythm_sync) {state_table->rhythm_sync=false; Rhythm_EnableAll(false);}
  if (Patch_PerfPartNum_select->currentIndex()==9) {
    state_table->updates_enabled=false;
    Patch_Number_select->setValue(Part10_PatchNumber_select->value());
    Patch_Group_select->setCurrentIndex(Part10_PatchGroup_select->currentIndex());
    Patch_Name_edit->setText(Part10_PatchName_display->text());
    state_table->updates_enabled=true;
  }
  // update Rhythm_tab
  Rhythm_PatchName_display->setText(Part10_PatchName_display->text());
  Rhythm_PatchGroup_select->blockSignals(true);
  Rhythm_PatchGroup_select->setCurrentIndex(val);
  Rhythm_PatchGroup_select->blockSignals(false);
}	// end on_Part10_PatchGroup_select_currentIndexChanged

void JVlibForm::on_Part10_PatchNumber_select_valueChanged(int val) {
  if (state_table->rhythm_sync) {state_table->rhythm_sync=false; Rhythm_EnableAll(false);}
  if (state_table->perf_mode) {
    on_Part10_PatchGroup_select_currentIndexChanged(Part10_PatchGroup_select->currentIndex());
    Rhythm_PatchNumber_select->blockSignals(true);
    Rhythm_PatchNumber_select->setValue(val);
    Rhythm_PatchNumber_select->blockSignals(false);
    Part10_PatchName_display->setText(getPartPatchName(9));
    Rhythm_PatchName_display->setText(Part10_PatchName_display->text());
  }
  if (state_table->GM_mode) {
      Part10_PatchName_display->setText(Part10_PatchNumber_select->value()==1 ? "GM Drum Set" : "BrushDrumSet");
  }
}	// end on_Part10_PatchNumber_select_valueChanged

