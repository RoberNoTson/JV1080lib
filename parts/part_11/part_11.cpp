// part_11.cpp
// contains slots and functions for Parts Tab Part 11
// slots will set Part 11 displays to reflect a local control change and update active_area memory, then update the synth 

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::on_Part11_TestTone_switch_toggled(bool val) {
  unsigned char buf[6];
  if (val) {
  buf[0] = 0x90 + active_area->active_performance.perf_part[10].MIDI_channel;
  buf[1] = SysPreviewNote1_select->value();
  buf[2] = SysPreviewNote1_volume->value();
  if (open_ports() == EXIT_FAILURE) return;
  if (change_send(buf,3) == EXIT_FAILURE) { close_ports(); return; }
  close_ports();
  } else {
    buf[0] = 0xB0 + active_area->active_performance.perf_part[10].MIDI_channel;
    buf[1] = 0x7B;
    buf[2] = 0;
    buf[3] = 0xB0 + active_area->active_performance.perf_part[10].MIDI_channel;
    buf[4] = 0x79;
    buf[5] = 0;
  if (open_ports() == EXIT_FAILURE) return;
  if (change_send(buf,6) == EXIT_FAILURE) { close_ports(); return; }
  close_ports();
  }
  Part11_TestTone_switch->setText(val ? QString::fromUtf8("Stop") : QString::fromUtf8("Play Tone") );
}

//---------------------------------------------------------------------------------------------------------------------
// switches
void JVlibForm::on_Part11_ReceiveMidi_enable_toggled(bool val) {
  setPartSingleValue(10,0,val);
}
void JVlibForm::on_Part11_MidiChannel_select_valueChanged(int val) {
  setPartSingleValue(10,1,val-1);
}
void JVlibForm::on_Part11_Level_select_valueChanged(int val) {
  setPartSingleValue(10,6,val);
  QString str;
  Part11_Level_select->setStatusTip(str.setNum(val));
}
void JVlibForm::on_Part11_Pan_select_valueChanged(int val) {
  setPartSingleValue(10,7,val);
  QString str;
  Part11_Level_select->setStatusTip(str.setNum(val));
}
void JVlibForm::on_Part11_Transpose_select_valueChanged(int val) { 
  // val is between -48,+48 half-steps
//  Part11_Transpose_display->display(val); 
  setPartSingleValue(10, 0x8, val+48);
}
void JVlibForm::on_Part11_TuneAdj_select_valueChanged(int val) { 
  // val is between -50,+50 cents
//  Part11_TuneAdj_display->display(val);
  setPartSingleValue(10, 0x9, val+50);
}
void JVlibForm::on_Part11_Output_select_currentIndexChanged(int val) {
  setPartSingleValue(10,0xA,val);
}
void JVlibForm::on_Part11_OutputLevel_select_valueChanged(int val) {
  setPartSingleValue(10,0xB,val);
}
void JVlibForm::on_Part11_ChorusSend_select_valueChanged(int val) {
  setPartSingleValue(10,0xC,val);
}
void JVlibForm::on_Part11_ReverbSend_select_valueChanged(int val) {
  setPartSingleValue(10,0xD,val);
}
void JVlibForm::on_Part11_ReceivePrgChg_enable_toggled(bool val) {
  setPartSingleValue(10,0xE,val);
  if (Patch_PerfPartNum_select->currentIndex()==10 && state_table->patch_sync) {
    Patch_Group_select->setEnabled(val);
    Patch_Number_select->setEnabled(val);
    Patch_Name_edit->setEnabled(val);
  }
}
void JVlibForm::on_Part11_ReceiveVolume_enable_toggled(bool val) {
  setPartSingleValue(10,0xF,val);
}
void JVlibForm::on_Part11_ReceiveHold_enable_toggled(bool val) {
  setPartSingleValue(10,0x10,val);
}
void JVlibForm::on_Part11_LowLimit_select_valueChanged(int val) { 
  Part11_LowLimit_display->setText(funcNoteCalc(val));
  if (val>Part11_HighLimit_select->value()) on_Part11_HighLimit_select_valueChanged(val);
  setPartSingleValue(10, 0x11, val);
}
void JVlibForm::on_Part11_HighLimit_select_valueChanged(int val) { 
  Part11_HighLimit_display->setText(funcNoteCalc(val));
  if (val<Part11_LowLimit_select->value()) on_Part11_LowLimit_select_valueChanged(val);
  setPartSingleValue(10, 0x12, val);
}
void JVlibForm::on_Part11_VoiceReserve_select_valueChanged(int val) { 
  setVoiceCounters();
  setPerfSingleValue(0x30+10,val);
}

//---------------------------------------------------------------------------------------------------------------------
void JVlibForm::on_Part11_PatchGroup_select_currentIndexChanged(int val) {
  // called after a change in the Patch group or number for this part to update the Patch Name and active_area memory
 if (state_table->updates_enabled) {
  int MSB,LSB;
  unsigned char buf[8];
  int CtlChl = toggleControlChannel(11);
  
  // change onscreen control to set maximum value for the parm type
  Part11_SetPatchMax();	
  // update perf_part.patch_num_high/low
  int pn = Part11_PatchNumber_select->value() - 1;
  int Hval = pn<128?0:1;
  int Lval = (pn%128);
  active_area->active_performance.perf_part[10].patch_num_high = Hval;
  active_area->active_performance.perf_part[10].patch_num_low = Lval;
  // update patch_group and group_id
  switch(val) {
    case 0:	// User patch
      active_area->active_performance.perf_part[10].patch_group = 0x0;
      active_area->active_performance.perf_part[10].patch_group_id = 0x01;
      MSB = 0x50;
      LSB = 0;
      break;
    case 1:	// Exp A
      active_area->active_performance.perf_part[10].patch_group = 0x02;
      active_area->active_performance.perf_part[10].patch_group_id = 0x02;
      MSB = 0x54;
      LSB = Hval;
      break;
    case 2:	// PresetA
      active_area->active_performance.perf_part[10].patch_group = 0x00;
      active_area->active_performance.perf_part[10].patch_group_id = 0x03;
      MSB = 0x51;
      LSB = 0x0;
      break;
    case 3:	// PresetB
      active_area->active_performance.perf_part[10].patch_group = 0x00;
      active_area->active_performance.perf_part[10].patch_group_id = 0x04;
      MSB = 0x51;
      LSB = 0x1;
      break;
    case 4:	// PresetC
      active_area->active_performance.perf_part[10].patch_group = 0x00;
      active_area->active_performance.perf_part[10].patch_group_id = 0x05;
      MSB = 0x51;
      LSB = 0x2;
      break;
    case 5:	// PresetD
      active_area->active_performance.perf_part[10].patch_group = 0x00;
      active_area->active_performance.perf_part[10].patch_group_id = 0x06;
      MSB = 0x51;
      LSB = 0x3;
      break;
    case 6:	// Exp B
      active_area->active_performance.perf_part[10].patch_group = 0x02;
      active_area->active_performance.perf_part[10].patch_group_id = 0x10;
      MSB = 0x54;
      LSB = Hval+2;
      break;
    case 7:	// Exp C
      active_area->active_performance.perf_part[10].patch_group = 0x02;
      active_area->active_performance.perf_part[10].patch_group_id = 0x62;
      MSB = 0x54;
      LSB = Hval+4;
      break;
    default:
      active_area->active_performance.perf_part[10].patch_group = 0x00;
      active_area->active_performance.perf_part[10].patch_group_id = 0x00;
      MSB = 0x00;
      LSB = 0x00;
      break;
  }	// end switch set Patch group
  // update JV
  if (state_table->updates_enabled) {
    buf[0] = 0xB0+active_area->active_performance.perf_part[10].MIDI_channel;
    buf[1] = 0x0;
    buf[2] = MSB;
    buf[3] = 0xB0+active_area->active_performance.perf_part[10].MIDI_channel;
    buf[4] = 0x20;
    buf[5] = LSB;
    // Program Change - Performance number
    buf[6] = 0xC0+active_area->active_performance.perf_part[10].MIDI_channel;
    buf[7] = Lval;
    if (open_ports() == EXIT_FAILURE) return;
    if (change_send(buf,8) == EXIT_FAILURE) { close_ports(); return; }
    close_ports();
  }  // end state_table->updates_enabled
  Part11_PatchName_display->setText(getPartPatchName(10));
  if (CtlChl) SysControlRecvChannel_select->setValue(CtlChl);
 }	// end state_table->updates_enabled  
}	// end on_Part11_PatchGroup_select_currentIndexChanged

void JVlibForm::Part11_SetPatchMax() {
  // set the Maximum possible value for Patch Number based on the current Patch Group
  switch(Part11_PatchGroup_select->currentIndex()) {
    case 0:	// User
      Part11_PatchNumber_select->setMaximum(128);
      break;
    case 1:	// Exp A
      Part11_PatchNumber_select->setMaximum(255);
      break;
    case 2:	// PresetA
      Part11_PatchNumber_select->setMaximum(128);
      break;
    case 3:	// PresetB
      Part11_PatchNumber_select->setMaximum(128);
      break;
    case 4:	// PresetC
      Part11_PatchNumber_select->setMaximum(128);
      break;
    case 5:	// PresetD
      Part11_PatchNumber_select->setMaximum(128);
      break;
    case 6:	// Exp B
      Part11_PatchNumber_select->setMaximum(256);
      break;
    case 7:	// Exp C
      Part11_PatchNumber_select->setMaximum(100);
      break;
    default:
      Part11_PatchNumber_select->setMaximum(128);
      break;
  }
}	// end Part11_SetPatchMax
void JVlibForm::on_Part11_PatchNumber_select_valueChanged(int val) {
  if (active_area->active_performance.perf_part[10].patch_group) {
    on_Part11_PatchGroup_select_currentIndexChanged(Part11_PatchGroup_select->currentIndex());
    return;
  }
  if (state_table->updates_enabled) {
    int CtlChl = toggleControlChannel(11);
    int pn = val-1;
    unsigned char buf[2];
    active_area->active_performance.perf_part[10].patch_num_high = 0;
    active_area->active_performance.perf_part[10].patch_num_low = pn;
    if (state_table->jv_connect) {
      // update JV
      buf[0] = 0xC0 + active_area->active_performance.perf_part[10].MIDI_channel;
      buf[1] = pn;
      if (open_ports() == EXIT_FAILURE) return;
      if (change_send(buf,2) == EXIT_FAILURE) { close_ports(); return; }
      close_ports();
    }  // end state_table->jv_connect
    Part11_PatchName_display->setText(getPartPatchName(10));
    if (CtlChl) SysControlRecvChannel_select->setValue(CtlChl);
  }	// end updates_enabled
}	// end on_Part11_PatchNumber_select_valueChanged

