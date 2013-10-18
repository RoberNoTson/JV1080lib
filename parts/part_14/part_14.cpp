// part_14.cpp
// contains slots and functions for Parts Tab Part 14
// slots will set Part 14 displays to reflect a local control change and update active_area memory, then update the synth 

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::on_Part14_TestTone_switch_toggled(bool val) {
  PartsToneSwitch(Part14_MidiChannel_select->value()-1, val);
  Part14_TestTone_switch->setText(val ? QString::fromUtf8("Stop") : QString::fromUtf8("Play Patch") );
}

//---------------------------------------------------------------------------------------------------------------------
// switches
void JVlibForm::on_Part14_ReceiveMidi_enable_toggled(bool val) {
  if (state_table->perf_mode) setPartSingleValue(13,0,val);
}
void JVlibForm::on_Part14_MidiChannel_select_valueChanged(int val) {
  if (state_table->perf_mode) setPartSingleValue(13,1,val-1);
}
void JVlibForm::on_Part14_Level_select_valueChanged(int val) {
  Part14_Level_select->setStatusTip(QString::number(val));
  if (state_table->perf_mode) setPartSingleValue(13,6,val);
  if (state_table->GM_mode && state_table->updates_enabled) change_3(0xB0+Part14_MidiChannel_select->value()-1,0x07,val);
}
void JVlibForm::on_Part14_Pan_select_valueChanged(int val) {
  Part14_Pan_select->setStatusTip(QString("Pan value: ")+QString::number(val));
  if (state_table->perf_mode) setPartSingleValue(13,7,val);
  if (state_table->GM_mode && state_table->updates_enabled) change_3(0xB0+Part14_MidiChannel_select->value()-1,0x0A,val);
}
void JVlibForm::on_Part14_Transpose_select_valueChanged(int val) { 
  // val is between -48,+48 half-steps
  if (state_table->perf_mode) setPartSingleValue(13, 0x8, val+48);
  // GM wants val between 10h,70h (16->112)
  if (state_table->GM_mode && state_table->updates_enabled) change_12(0xB0+Part14_MidiChannel_select->value()-1,0x65,0x00,0xB0+Part14_MidiChannel_select->value()-1,0x64,0x02,0xB0+Part14_MidiChannel_select->value()-1,0x06,(val+64),0xB0+Part14_MidiChannel_select->value()-1,0x26,0x00);
}
void JVlibForm::on_Part14_TuneAdj_select_valueChanged(int val) { 
  // val is between -50,+50 cents
  if (state_table->perf_mode) setPartSingleValue(13, 0x9, val+50);
  // GM wants val between 20h,60h (32->96)
  if (state_table->GM_mode && state_table->updates_enabled) change_12(0xB0+Part14_MidiChannel_select->value()-1,0x65,0x00,0xB0+Part14_MidiChannel_select->value()-1,0x64,0x01,0xB0+Part14_MidiChannel_select->value()-1,0x06,(val+50)*65/101+32,0xB0+Part14_MidiChannel_select->value()-1,0x26,0x00);
}
void JVlibForm::on_Part14_Output_select_currentIndexChanged(int val) {
  if (state_table->perf_mode) setPartSingleValue(13,0xA,val);
}
void JVlibForm::on_Part14_OutputLevel_select_valueChanged(int val) {
  if (state_table->perf_mode) setPartSingleValue(13,0xB,val);
}
void JVlibForm::on_Part14_ChorusSend_select_valueChanged(int val) {
  if (state_table->perf_mode) setPartSingleValue(13,0xC,val);
  if (state_table->GM_mode && state_table->updates_enabled) change_3(0xB0+Part14_MidiChannel_select->value()-1,0x5D,val);
}
void JVlibForm::on_Part14_ReverbSend_select_valueChanged(int val) {
  if (state_table->perf_mode) setPartSingleValue(13,0xD,val);
  if (state_table->GM_mode && state_table->updates_enabled) change_3(0xB0+Part14_MidiChannel_select->value()-1,0x5B,val);
}
void JVlibForm::on_Part14_ReceivePrgChg_enable_toggled(bool val) {
  if (state_table->perf_mode) {
    setPartSingleValue(13,0xE,val);
    Part14_PatchGroup_select->setEnabled(val && AcceptBankSel_switch->isChecked());
    Part14_PatchNumber_select->setEnabled(val && AcceptProgramChg_switch->isChecked());
    if (Patch_PerfPartNum_select->currentIndex()==13 && state_table->patch_sync) {
      Patch_Group_select->setEnabled(val && AcceptBankSel_switch->isChecked());
      Patch_Number_select->setEnabled(val && AcceptProgramChg_switch->isChecked());
      Patch_Name_edit->setEnabled(val);
    }
  }
}
void JVlibForm::on_Part14_ReceiveVolume_enable_toggled(bool val) {
  if (state_table->perf_mode) setPartSingleValue(13,0xF,val);
}
void JVlibForm::on_Part14_ReceiveHold_enable_toggled(bool val) {
  if (state_table->perf_mode) setPartSingleValue(13,0x10,val);
}
void JVlibForm::on_Part14_LowLimit_select_valueChanged(int val) { 
  Part14_LowLimit_display->setText(funcNoteCalc(val));
  if (val>Part14_HighLimit_select->value()) on_Part14_HighLimit_select_valueChanged(val);
  setPartSingleValue(13, 0x11, val);
}
void JVlibForm::on_Part14_HighLimit_select_valueChanged(int val) { 
  Part14_HighLimit_display->setText(funcNoteCalc(val));
  if (val<Part14_LowLimit_select->value()) on_Part14_LowLimit_select_valueChanged(val);
  setPartSingleValue(13, 0x12, val);
}
void JVlibForm::on_Part14_VoiceReserve_select_valueChanged(int val) { 
  setVoiceCounters();
  setPerfSingleValue(0x30+13,val);
}

//---------------------------------------------------------------------------------------------------------------------
void JVlibForm::on_Part14_PatchGroup_select_currentIndexChanged(int val) {
  // called after a change in the Patch group or number for this part to update the Patch Name and active_area memory
 if (state_table->updates_enabled) {
  int MSB,LSB;
  int CtlChl = toggleControlChannel(14);
  // change onscreen control to set maximum value for the parm type
  Part14_SetPatchMax();	
  // update perf_part.patch_num_high/low
  int pn = Part14_PatchNumber_select->value() - 1;
  int Hval = pn<128?0:1;
  int Lval = (pn%128);
  active_area->active_performance.perf_part[13].patch_num_high = Hval;
  active_area->active_performance.perf_part[13].patch_num_low = Lval;
  // update patch_group and group_id
  switch(val) {
    case 0:	// User patch
      active_area->active_performance.perf_part[13].patch_group = 0x0;
      active_area->active_performance.perf_part[13].patch_group_id = 0x01;
      MSB = 0x50;
      LSB = 0;
      break;
    case 1:	// Exp A
      active_area->active_performance.perf_part[13].patch_group = 0x02;
      active_area->active_performance.perf_part[13].patch_group_id = 0x02;
      MSB = 0x54;
      LSB = Hval;
      break;
    case 2:	// PresetA
      active_area->active_performance.perf_part[13].patch_group = 0x00;
      active_area->active_performance.perf_part[13].patch_group_id = 0x03;
      MSB = 0x51;
      LSB = 0x0;
      break;
    case 3:	// PresetB
      active_area->active_performance.perf_part[13].patch_group = 0x00;
      active_area->active_performance.perf_part[13].patch_group_id = 0x04;
      MSB = 0x51;
      LSB = 0x1;
      break;
    case 4:	// PresetC
      active_area->active_performance.perf_part[13].patch_group = 0x00;
      active_area->active_performance.perf_part[13].patch_group_id = 0x05;
      MSB = 0x51;
      LSB = 0x2;
      break;
    case 5:	// PresetD
      active_area->active_performance.perf_part[13].patch_group = 0x00;
      active_area->active_performance.perf_part[13].patch_group_id = 0x06;
      MSB = 0x51;
      LSB = 0x3;
      break;
    case 6:	// Exp B
      active_area->active_performance.perf_part[13].patch_group = 0x02;
      active_area->active_performance.perf_part[13].patch_group_id = 0x10;
      MSB = 0x54;
      LSB = Hval+2;
      break;
    case 7:	// Exp C
      active_area->active_performance.perf_part[13].patch_group = 0x02;
      active_area->active_performance.perf_part[13].patch_group_id = 0x62;
      MSB = 0x54;
      LSB = Hval+4;
      break;
    default:
      active_area->active_performance.perf_part[13].patch_group = 0x00;
      active_area->active_performance.perf_part[13].patch_group_id = 0x00;
      MSB = 0x00;
      LSB = 0x00;
      break;
  }	// end switch set Patch group
  // update JV
  if (state_table->updates_enabled) {
    change_3(0xB0 + Part14_MidiChannel_select->value()-1, 0, MSB);
    change_3(0xB0 + Part14_MidiChannel_select->value()-1, 0x20, LSB);
    // Program Change - patch number is required for this
    change_2(0xC0 + Part14_MidiChannel_select->value()-1, Lval);
  }  // end state_table->updates_enabled
  Part14_PatchName_display->setText(getPartPatchName(13));
  if (CtlChl) SysControlRecvChannel_select->setValue(CtlChl);
 }	// end state_table->updates_enabled  
}	// end on_Part14_PatchGroup_select_currentIndexChanged

void JVlibForm::Part14_SetPatchMax() {
  // set the Maximum possible value for Patch Number based on the current Patch Group
  switch(Part14_PatchGroup_select->currentIndex()) {
    case 0:	// User
      Part14_PatchNumber_select->setMaximum(128);
      break;
    case 1:	// Exp A
      Part14_PatchNumber_select->setMaximum(255);
      break;
    case 2:	// PresetA
      Part14_PatchNumber_select->setMaximum(128);
      break;
    case 3:	// PresetB
      Part14_PatchNumber_select->setMaximum(128);
      break;
    case 4:	// PresetC
      Part14_PatchNumber_select->setMaximum(128);
      break;
    case 5:	// PresetD
      Part14_PatchNumber_select->setMaximum(128);
      break;
    case 6:	// Exp B
      Part14_PatchNumber_select->setMaximum(256);
      break;
    case 7:	// Exp C
      Part14_PatchNumber_select->setMaximum(100);
      break;
    default:
      Part14_PatchNumber_select->setMaximum(128);
      break;
  }
}	// end Part14_SetPatchMax
void JVlibForm::on_Part14_PatchNumber_select_valueChanged(int val) {
  if (active_area->active_performance.perf_part[13].patch_group) {
    on_Part14_PatchGroup_select_currentIndexChanged(Part14_PatchGroup_select->currentIndex());
    return;
  }
  if (state_table->updates_enabled) {
    int pn = val-1;
    int CtlChl=0;
    if (state_table->perf_mode) {
      CtlChl = toggleControlChannel(14);
      active_area->active_performance.perf_part[13].patch_num_high = 0;
      active_area->active_performance.perf_part[13].patch_num_low = pn;
    }
    if (state_table->jv_connect)
      change_2(0xC0 + Part14_MidiChannel_select->value()-1, pn);
    if (state_table->perf_mode) 
      if (CtlChl) SysControlRecvChannel_select->setValue(CtlChl);
    Part14_PatchName_display->setText(getPartPatchName(13));
  }	// end updates_enabled
}	// end on_Part14_PatchNumber_select_valueChanged

