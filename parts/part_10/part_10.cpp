// part_10.cpp
// contains slots and functions for Parts Tab Part 10, Rhythm set is slightly different from other parts.
// slots will set Part 10 displays to reflect a local control change and update active_area memory, then update the synth 

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::on_Part10_TestTone_switch_toggled(bool val) {
  unsigned char buf[6];
  if (val) {
  buf[0] = 0x90 + active_area->active_performance.perf_part[9].MIDI_channel;
  buf[1] = SysPreviewNote1_select->value();
  buf[2] = SysPreviewNote1_volume->value();
  if (open_ports() == EXIT_FAILURE) return;
  if (change_send(buf,3) == EXIT_FAILURE) { close_ports(); return; }
  close_ports();
  } else {
    buf[0] = 0xB0 + active_area->active_performance.perf_part[9].MIDI_channel;
    buf[1] = 0x7B;
    buf[2] = 0;
    buf[3] = 0xB0 + active_area->active_performance.perf_part[9].MIDI_channel;
    buf[4] = 0x79;
    buf[5] = 0;
  if (open_ports() == EXIT_FAILURE) return;
  if (change_send(buf,6) == EXIT_FAILURE) { close_ports(); return; }
  close_ports();
  }
  Part10_TestTone_switch->setText(val ? QString::fromUtf8("Stop") : QString::fromUtf8("Play Tone") );
}

//---------------------------------------------------------------------------------------------------------------------
// switches
void JVlibForm::on_Part10_ReceiveMidi_enable_toggled(bool val) {
  setPartSingleValue(9,0,val);
}
void JVlibForm::on_Part10_MidiChannel_select_valueChanged(int val) {
  setPartSingleValue(9,1,val-1);
}
void JVlibForm::on_Part10_Level_select_valueChanged(int val) {
  setPartSingleValue(9,6,val);
  QString str;
  Part10_Level_select->setStatusTip(str.setNum(val));
}
void JVlibForm::on_Part10_Pan_select_valueChanged(int val) {
  setPartSingleValue(9,7,val);
  QString str;
  Part10_Level_select->setStatusTip(str.setNum(val));
}
void JVlibForm::on_Part10_Transpose_select_valueChanged(int val) { 
  // val is between -48,+48 half-steps
//  Part10_Transpose_display->display(val); 
  setPartSingleValue(9, 0x8, val+48);
}
void JVlibForm::on_Part10_TuneAdj_select_valueChanged(int val) { 
  // val is between -50,+50 cents
//  Part10_TuneAdj_display->display(val);
  setPartSingleValue(9, 0x9, val+50);
}
void JVlibForm::on_Part10_Output_select_currentIndexChanged(int val) {
  setPartSingleValue(9,0xA,val);
}
void JVlibForm::on_Part10_OutputLevel_select_valueChanged(int val) {
  setPartSingleValue(9,0xB,val);
}
void JVlibForm::on_Part10_ChorusSend_select_valueChanged(int val) {
  setPartSingleValue(9,0xC,val);
}
void JVlibForm::on_Part10_ReverbSend_select_valueChanged(int val) {
  setPartSingleValue(9,0xD,val);
}
void JVlibForm::on_Part10_ReceivePrgChg_enable_toggled(bool val) {
  setPartSingleValue(9,0xE,val);
  if (Patch_PerfPartNum_select->currentIndex()==9 && state_table->patch_sync) {
    Patch_Group_select->setEnabled(val);
    Patch_Number_select->setEnabled(val);
    Patch_Name_edit->setEnabled(val);
  }
}
void JVlibForm::on_Part10_ReceiveVolume_enable_toggled(bool val) {
  setPartSingleValue(9,0xF,val);
}
void JVlibForm::on_Part10_ReceiveHold_enable_toggled(bool val) {
  setPartSingleValue(9,0x10,val);
}
void JVlibForm::on_Part10_LowLimit_select_valueChanged(int val) { 
  Part10_LowLimit_display->setText(funcNoteCalc(val));
  setPartSingleValue(9, 0x11, val);
}
void JVlibForm::on_Part10_HighLimit_select_valueChanged(int val) { 
  Part10_HighLimit_display->setText(funcNoteCalc(val));
  setPartSingleValue(9, 0x12, val);
}
void JVlibForm::on_Part10_VoiceReserve_select_valueChanged(int val) { 
  setPerfSingleValue(0x30+9,val);
}

//---------------------------------------------------------------------------------------------------------------------
void JVlibForm::on_Part10_PatchGroup_select_currentIndexChanged(int val) {
  // called after a change in the Patch group or number for this part to update the Patch Name and active_area memory
 if (state_table->updates_enabled) {
  int MSB,LSB;
  unsigned char buf[8];
  int CtlChl = toggleControlChannel(10);

  // change onscreen control to set maximum value for the parm type
  Part10_PatchNumber_select->setMaximum(2);
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
    buf[0] = 0xB0+active_area->active_performance.perf_part[9].MIDI_channel;
    buf[1] = 0x0;
    buf[2] = MSB;
    buf[3] = 0xB0+active_area->active_performance.perf_part[9].MIDI_channel;
    buf[4] = 0x20;
    buf[5] = LSB;
    // Program Change - Performance number
    buf[6] = 0xC0+active_area->active_performance.perf_part[9].MIDI_channel;
    buf[7] = pn;
    if (open_ports() == EXIT_FAILURE) return;
    if (change_send(buf,8) == EXIT_FAILURE) { close_ports(); return; }
    close_ports();
  }  // end state_table->updates_enabled
  Part10_PatchName_display->setText(getPartPatchName(9));
  if (CtlChl) SysControlRecvChannel_select->setValue(CtlChl);
 }	// end state_table->updates_enabled  
}	// end on_Part10_PatchGroup_select_currentIndexChanged

void JVlibForm::on_Part10_PatchNumber_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
    int CtlChl = toggleControlChannel(10);
    int pn = val-1;
    unsigned char buf[2];
    active_area->active_performance.perf_part[9].patch_num_high = 0;
    active_area->active_performance.perf_part[9].patch_num_low = pn;
    if (state_table->jv_connect) {
      // update JV
      buf[0] = 0xC0 + active_area->active_performance.perf_part[9].MIDI_channel;
      buf[1] = pn;
      if (open_ports() == EXIT_FAILURE) return;
      if (change_send(buf,2) == EXIT_FAILURE) { close_ports(); return; }
      close_ports();
    }  // end state_table->jv_connect
    Part10_PatchName_display->setText(getPartPatchName(9));
    if (CtlChl) SysControlRecvChannel_select->setValue(CtlChl);
  }	// end updates_enabled
}	// end on_Part10_PatchNumber_select_valueChanged

