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
 * Part10_SetPatchMax
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
  if (state_table->perf_mode) setPartSingleValue(9,0,val);
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
  Part10_Pan_select->setStatusTip(QString("Pan value: ")+QString::number(val));
  if (state_table->perf_mode) setPartSingleValue(9,7,val);
  if (state_table->GM_mode && state_table->updates_enabled) change_3(0xB0+Part10_MidiChannel_select->value()-1,0x0A,val);
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
  if (state_table->perf_mode) {
    setPartSingleValue(9,0xE,val);
    Part10_PatchGroup_select->setEnabled(val && AcceptBankSel_switch->isChecked());
    Part10_PatchNumber_select->setEnabled(val && AcceptProgramChg_switch->isChecked());
    if (Patch_PerfPartNum_select->currentIndex()==9 && state_table->patch_sync) {
      Patch_Group_select->setEnabled(val && AcceptBankSel_switch->isChecked());
      Patch_Number_select->setEnabled(val && AcceptProgramChg_switch->isChecked());
      Patch_Name_edit->setEnabled(val);
    }
  }
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
  setVoiceCounters();
  setPerfSingleValue(0x30+9,val);
}

//---------------------------------------------------------------------------------------------------------------------
void JVlibForm::on_Part10_PatchGroup_select_currentIndexChanged(int val) {
  // called after a change in the Patch group or number for this part to update the Patch Name and active_area memory
 if (!state_table->updates_enabled) return;
  int MSB,LSB;
  int CtlChl = toggleControlChannel(10);
  // change onscreen control to set maximum value for the parm type
//  Part10_PatchNumber_select->setMaximum(2);
  // update perf_part.patch_num_high/low
  int pn = Part10_PatchNumber_select->value() - 1;
  active_area->active_performance.perf_part[9].patch_num_high = 0;
  active_area->active_performance.perf_part[9].patch_num_low = pn;
  // update patch_group and group_id
  switch(val) {
    case 0:	// User patch
      active_area->active_performance.perf_part[9].patch_group = 0x0;
      active_area->active_performance.perf_part[9].patch_group_id = 0x01;
      MSB = 0x50;
      LSB = 0x00;
      break;
    case 1:	// PresetA
      active_area->active_performance.perf_part[9].patch_group = 0x00;
      active_area->active_performance.perf_part[9].patch_group_id = 0x03;
      MSB = 0x51;
      LSB = 0x00;
      break;
    case 2:	// PresetB
      active_area->active_performance.perf_part[9].patch_group = 0x00;
      active_area->active_performance.perf_part[9].patch_group_id = 0x04;
      MSB = 0x51;
      LSB = 0x01;
      break;
    case 3:	// PresetC
      active_area->active_performance.perf_part[9].patch_group = 0x00;
      active_area->active_performance.perf_part[9].patch_group_id = 0x05;
      MSB = 0x51;
      LSB = 0x02;
      break;
    case 4:	// PresetD
      active_area->active_performance.perf_part[9].patch_group = 0x00;
      active_area->active_performance.perf_part[9].patch_group_id = 0x06;
      MSB = 0x51;
      LSB = 0x03;
      break;
    case 5:	// Exp B
      active_area->active_performance.perf_part[9].patch_group = 0x02;
      active_area->active_performance.perf_part[9].patch_group_id = 0x10;
      MSB = 0x54;
      LSB = 0x02;
      break;
    default:
      active_area->active_performance.perf_part[9].patch_group = 0x00;
      active_area->active_performance.perf_part[9].patch_group_id = 0x00;
      MSB = 0x00;
      LSB = 0x00;
      break;
  }	// end switch set Patch group
  // update JV
  if (state_table->updates_enabled) {
    change_3(0xB0 + Part10_MidiChannel_select->value()-1, 0, MSB);
    change_3(0xB0 + Part10_MidiChannel_select->value()-1, 0x20, LSB);
    // Program Change - patch number is required for this
    change_2(0xC0 + Part10_MidiChannel_select->value()-1, pn);
  }  // end state_table->updates_enabled
  Part10_PatchName_display->setText(getPartPatchName(9));
  // update Rhythm_tab
//  if (state_table->perf_mode) 
    Rhythm_PatchName_display->setText(Part10_PatchName_display->text());
//  if (state_table->perf_mode) {
    Rhythm_PatchGroup_select->blockSignals(true);
    Rhythm_PatchGroup_select->setCurrentIndex(val);
    Rhythm_PatchGroup_select->blockSignals(false);
//  }    
  if (CtlChl) SysControlRecvChannel_select->setValue(CtlChl);
}	// end on_Part10_PatchGroup_select_currentIndexChanged

void JVlibForm::on_Part10_PatchNumber_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
    int pn = val-1;
    int CtlChl=0;
//    if (state_table->perf_mode) {
      CtlChl = toggleControlChannel(10);
      active_area->active_performance.perf_part[9].patch_num_high = 0;
      active_area->active_performance.perf_part[9].patch_num_low = pn;
//    }
    if (state_table->jv_connect)
      change_2(0xC0 + Part10_MidiChannel_select->value()-1, pn);
    if (state_table->perf_mode) 
      if (CtlChl) SysControlRecvChannel_select->setValue(CtlChl);
//    if (state_table->perf_mode) {
      Rhythm_PatchNumber_select->blockSignals(true);
      Rhythm_PatchNumber_select->setValue(val);
      Rhythm_PatchNumber_select->blockSignals(false);
      Part10_PatchName_display->setText(getPartPatchName(9));
      Rhythm_PatchName_display->setText(Part10_PatchName_display->text());
//    }
    if (state_table->GM_mode) {
      Part10_PatchName_display->setText(Part10_PatchNumber_select->value()==1 ? "GM Drum Set" : "BrushDrumSet");
    }
  }	// end updates_enabled
}	// end on_Part10_PatchNumber_select_valueChanged

