// part_1.cpp
// contains slots and functions for Parts Tab Part 1 
// slots will set Part 1 displays to reflect a local control change and update active_area memory, then update the synth 

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::on_Part1_TestTone_switch_toggled(bool val) {
  unsigned char buf[6];
  if (val) {
    buf[0] = 0x90 + (state_table->GM_mode ? 0 : active_area->active_performance.perf_part[0].MIDI_channel);
    buf[1] = SysPreviewNote1_select->value();
    buf[2] = SysPreviewNote1_volume->value();
    if (open_ports() == EXIT_FAILURE) return;
    if (change_send(buf,3) == EXIT_FAILURE) { close_ports(); return; }
    close_ports();
  } else {
    buf[0] = 0xB0 + (state_table->GM_mode? 0 : active_area->active_performance.perf_part[0].MIDI_channel);
    buf[1] = 0x7B;
    buf[2] = 0;
    buf[3] = 0xB0 + (state_table->GM_mode? 0 : active_area->active_performance.perf_part[0].MIDI_channel);
    buf[4] = 0x79;
    buf[5] = 0;
    if (open_ports() == EXIT_FAILURE) return;
    if (change_send(buf,6) == EXIT_FAILURE) { close_ports(); return; }
    close_ports();
  }
  Part1_TestTone_switch->setText(val ? QString::fromUtf8("Stop") : QString::fromUtf8("Play Tone") );
}

//---------------------------------------------------------------------------------------------------------------------
// switches
void JVlibForm::on_Part1_ReceiveMidi_enable_toggled(bool val) {
  setPartSingleValue(0,0,val);
}
void JVlibForm::on_Part1_MidiChannel_select_valueChanged(int val) {
  setPartSingleValue(0,1,val-1);
}
void JVlibForm::on_Part1_Level_select_valueChanged(int val) {
  Part1_Level_select->setStatusTip(QString::number(val));
  if (state_table->perf_mode) setPartSingleValue(0,6,val);
  if (state_table->GM_mode && state_table->updates_enabled) change_3(0xB0,0x07,val);
}
void JVlibForm::on_Part1_Pan_select_valueChanged(int val) {
  Part1_Pan_select->setStatusTip(QString("Pan value: ")+QString::number(val));
  if (state_table->perf_mode) setPartSingleValue(0,7,val);
  if (state_table->GM_mode && state_table->updates_enabled) change_3(0xB0,0x0A,val);
}
void JVlibForm::on_Part1_Transpose_select_valueChanged(int val) { 
  // val is between -48,+48 half-steps
  if (state_table->perf_mode) setPartSingleValue(0, 0x8, val+48);
  // GM wants val between 10h,70h (16->112)
  if (state_table->GM_mode && state_table->updates_enabled) change_12(0xB0,0x65,0x00,0xB0,0x64,0x02,0xB0,0x06,(val+64),0xB0,0x26,0x00);
}
void JVlibForm::on_Part1_TuneAdj_select_valueChanged(int val) { 
  // val is between -50,+50 cents
  if (state_table->perf_mode) setPartSingleValue(0, 0x9, val+50);
  // GM wants val between 20h,60h (32->96)
  if (state_table->GM_mode && state_table->updates_enabled) change_12(0xB0,0x65,0x00,0xB0,0x64,0x01,0xB0,0x06,(val+50)*65/101+32,0xB0,0x26,0x00);
}
void JVlibForm::on_Part1_Output_select_currentIndexChanged(int val) {
  setPartSingleValue(0,0xA,val);
}
void JVlibForm::on_Part1_OutputLevel_select_valueChanged(int val) {
  setPartSingleValue(0,0xB,val);
}
void JVlibForm::on_Part1_ChorusSend_select_valueChanged(int val) {
  if (state_table->perf_mode) setPartSingleValue(0,0xC,val);
  if (state_table->GM_mode && state_table->updates_enabled) change_3(0xB0,0x5D,val);
}
void JVlibForm::on_Part1_ReverbSend_select_valueChanged(int val) {
  if (state_table->perf_mode) setPartSingleValue(0,0xD,val);
  if (state_table->GM_mode && state_table->updates_enabled) change_3(0xB0,0x5B,val);
}
void JVlibForm::on_Part1_ReceivePrgChg_enable_toggled(bool val) {
  setPartSingleValue(0,0xE,val);
  if (Patch_PerfPartNum_select->currentIndex()==0 && state_table->patch_sync) {
    Patch_Group_select->setEnabled(val);
    Patch_Number_select->setEnabled(val);
    Patch_Name_edit->setEnabled(val);
  }
}
void JVlibForm::on_Part1_ReceiveVolume_enable_toggled(bool val) {
  setPartSingleValue(0,0xF,val);
}
void JVlibForm::on_Part1_ReceiveHold_enable_toggled(bool val) {
  setPartSingleValue(0,0x10,val);
}
void JVlibForm::on_Part1_LowLimit_select_valueChanged(int val) { 
  Part1_LowLimit_display->setText(funcNoteCalc(val));
  if (val>Part1_HighLimit_select->value()) on_Part1_HighLimit_select_valueChanged(val);
  setPartSingleValue(0, 0x11, val);
}
void JVlibForm::on_Part1_HighLimit_select_valueChanged(int val) { 
  Part1_HighLimit_display->setText(funcNoteCalc(val));
  if (val<Part1_LowLimit_select->value()) on_Part1_LowLimit_select_valueChanged(val);
  setPartSingleValue(0, 0x12, val);
}
void JVlibForm::on_Part1_VoiceReserve_select_valueChanged(int val) { 
  setVoiceCounters();
  setPerfSingleValue(0x30+0,val);
}

//---------------------------------------------------------------------------------------------------------------------
void JVlibForm::on_Part1_PatchGroup_select_currentIndexChanged(int val) {
  // called after a change in the Patch group or number for this part to update the Patch Name and active_area memory
 if (state_table->updates_enabled) {
  int MSB,LSB;
  unsigned char buf[8];
  int CtlChl = toggleControlChannel(1);
  
  // change onscreen control to set maximum value for the parm type
  Part1_SetPatchMax();	
  // update perf_part.patch_num_high/low
  int pn = Part1_PatchNumber_select->value() - 1;
  int Hval = pn<128?0:1;
  int Lval = (pn%128);
  active_area->active_performance.perf_part[0].patch_num_high = Hval;
  active_area->active_performance.perf_part[0].patch_num_low = Lval;
  // update patch_group and group_id
  switch(val) {
    case 0:	// User patch
      active_area->active_performance.perf_part[0].patch_group = 0x0;
      active_area->active_performance.perf_part[0].patch_group_id = 0x01;
      MSB = 0x50;
      LSB = 0;
      break;
    case 1:	// Exp A
      active_area->active_performance.perf_part[0].patch_group = 0x02;
      active_area->active_performance.perf_part[0].patch_group_id = 0x02;
      MSB = 0x54;
      LSB = Hval;
      break;
    case 2:	// PresetA
      active_area->active_performance.perf_part[0].patch_group = 0x00;
      active_area->active_performance.perf_part[0].patch_group_id = 0x03;
      MSB = 0x51;
      LSB = 0x0;
      break;
    case 3:	// PresetB
      active_area->active_performance.perf_part[0].patch_group = 0x00;
      active_area->active_performance.perf_part[0].patch_group_id = 0x04;
      MSB = 0x51;
      LSB = 0x1;
      break;
    case 4:	// PresetC
      active_area->active_performance.perf_part[0].patch_group = 0x00;
      active_area->active_performance.perf_part[0].patch_group_id = 0x05;
      MSB = 0x51;
      LSB = 0x2;
      break;
    case 5:	// PresetD
      active_area->active_performance.perf_part[0].patch_group = 0x00;
      active_area->active_performance.perf_part[0].patch_group_id = 0x06;
      MSB = 0x51;
      LSB = 0x3;
      break;
    case 6:	// Exp B
      active_area->active_performance.perf_part[0].patch_group = 0x02;
      active_area->active_performance.perf_part[0].patch_group_id = 0x10;
      MSB = 0x54;
      LSB = Hval+2;
      break;
    case 7:	// Exp C
      active_area->active_performance.perf_part[0].patch_group = 0x02;
      active_area->active_performance.perf_part[0].patch_group_id = 0x62;
      MSB = 0x54;
      LSB = Hval+4;
      break;
    default:
      active_area->active_performance.perf_part[0].patch_group = 0x00;
      active_area->active_performance.perf_part[0].patch_group_id = 0x00;
      MSB = 0x00;
      LSB = 0x00;
      break;
  }	// end switch set Patch group
  // update JV
  if (state_table->updates_enabled) {
    buf[0] = 0xB0+active_area->active_performance.perf_part[0].MIDI_channel;
    buf[1] = 0x0;
    buf[2] = MSB;
    buf[3] = 0xB0+active_area->active_performance.perf_part[0].MIDI_channel;
    buf[4] = 0x20;
    buf[5] = LSB;
    // Program Change - patch number is required for this
    buf[6] = 0xC0+active_area->active_performance.perf_part[0].MIDI_channel;
    buf[7] = Lval;
    if (open_ports() == EXIT_FAILURE) return;
    if (change_send(buf,8) == EXIT_FAILURE) { close_ports(); return; }
    close_ports();
  }  // end state_table->updates_enabled
  Part1_PatchName_display->setText(getPartPatchName(0));
  if (CtlChl) SysControlRecvChannel_select->setValue(CtlChl);
 }	// end state_table->updates_enabled  
}	// end on_Part1_PatchGroup_select_currentIndexChanged

void JVlibForm::Part1_SetPatchMax() {
  // set the Maximum possible value for Patch Number based on the current Patch Group
  switch(Part1_PatchGroup_select->currentIndex()) {
    case 0:	// User
      Part1_PatchNumber_select->setMaximum(128);
      break;
    case 1:	// Exp A
      Part1_PatchNumber_select->setMaximum(255);
      break;
    case 2:	// PresetA
      Part1_PatchNumber_select->setMaximum(128);
      break;
    case 3:	// PresetB
      Part1_PatchNumber_select->setMaximum(128);
      break;
    case 4:	// PresetC
      Part1_PatchNumber_select->setMaximum(128);
      break;
    case 5:	// PresetD
      Part1_PatchNumber_select->setMaximum(128);
      break;
    case 6:	// Exp B
      Part1_PatchNumber_select->setMaximum(256);
      break;
    case 7:	// Exp C
      Part1_PatchNumber_select->setMaximum(100);
      break;
    default:
      Part1_PatchNumber_select->setMaximum(128);
      break;
  }
}	// end Part1_SetPatchMax

void JVlibForm::on_Part1_PatchNumber_select_valueChanged(int val) {
  if (state_table->perf_mode && active_area->active_performance.perf_part[0].patch_group) {
    on_Part1_PatchGroup_select_currentIndexChanged(Part1_PatchGroup_select->currentIndex());
    return;
  }
  if (state_table->updates_enabled) {
    int pn = val-1;
    unsigned char buf[2];
    if (!state_table->GM_mode) {
      int CtlChl = toggleControlChannel(1);
      active_area->active_performance.perf_part[0].patch_num_high = 0;
      active_area->active_performance.perf_part[0].patch_num_low = pn;
      if (state_table->jv_connect) {
	// update JV
	buf[0] = 0xC0 + active_area->active_performance.perf_part[0].MIDI_channel;
	buf[1] = pn;
	if (open_ports() == EXIT_FAILURE) return;
	if (change_send(buf,2) == EXIT_FAILURE) { close_ports(); return; }
	close_ports();
      }  // end state_table->jv_connect
      if (CtlChl) SysControlRecvChannel_select->setValue(CtlChl);
    }	// end non-GM mode
    if (state_table->GM_mode) {
      if (state_table->jv_connect) {
	buf[0] = 0xC0 + 0;
	buf[1] = pn;
	if (open_ports() == EXIT_FAILURE) return;
	if (change_send(buf,2) == EXIT_FAILURE) { close_ports(); return; }
	close_ports();
      }  // end state_table->jv_connect
    }	// end GM mode
    Part1_PatchName_display->setText(getPartPatchName(0));
  }	// end updates_enabled
}	// end on_Part1_PatchNumber_select_valueChanged

