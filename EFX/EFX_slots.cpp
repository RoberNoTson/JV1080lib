// EFX_slots.cpp

#include        "JVlibForm.h"
#include        <QtGui>
#include        "EFX.h"
#include	"EFX_slots.h"

// EFX SOURCE -- only Performance EFX has a Source selection
void JVlibForm::slotPerfEFXsource(int val) {
 if (state_table->updates_enabled) {
  active_area->active_performance.perf_common.EFX_source = val;
  setPerfSingleValue(addr_Perf_EFX_source ,val);
  Perf_EFX_groupBox->setEnabled(val?false:true);
 }
}

void JVlibForm::on_PatchEFX_TestTone_switch_toggled(bool val) {
  if (state_table->jv_connect) {
  unsigned char buf[6];
  int pn = state_table->perf_mode ? (Patch_PerfPartNum_select->currentIndex()) : 0;
  if (val) {
    buf[0] = 0x90 + (state_table->perf_mode ? active_area->active_performance.perf_part[pn].MIDI_channel : 
      system_area->sys_common.patch_receive_channel);
    buf[1] = SysPreviewNote1_select->value();
    buf[2] = SysPreviewNote1_volume->value();
    if (open_ports() == EXIT_FAILURE) return;
    if (change_send(buf,3) == EXIT_FAILURE) { close_ports(); return; }
    close_ports();
  } else {
    buf[0] = 0xB0 + (state_table->perf_mode ? active_area->active_performance.perf_part[pn].MIDI_channel : 
      system_area->sys_common.patch_receive_channel);
    buf[1] = 0x7B;
    buf[2] = 0;
    buf[3] = 0xB0 + (state_table->perf_mode ? active_area->active_performance.perf_part[pn].MIDI_channel : 
      system_area->sys_common.patch_receive_channel);
    buf[4] = 0x79;
    buf[5] = 0;
  if (open_ports() == EXIT_FAILURE) return;
  if (change_send(buf,6) == EXIT_FAILURE) { close_ports(); return; }
  close_ports();
  }
  PatchEFX_TestTone_switch->setText(val ? QString::fromUtf8("Stop") : QString::fromUtf8("Play Patch") );
  }
}

//EFX_TYPE
void JVlibForm::slotPerfEFXtype(int val) {
  // called when EFX type is changed on the Performance Tab
 if (state_table->updates_enabled) {
  int	err;
  int	Stop=0;
  unsigned char buf[16];
    // update type
    active_area->active_performance.perf_common.EFX_type = val;
    if (state_table->jv_connect) {
      setPerfSingleValue(addr_Perf_EFX_type, active_area->active_performance.perf_common.EFX_type);
      // download the related parms for the new type
      memset(buf,0,sizeof(buf));
      buf[4] = JV_REQ;
      buf[5] = 0x01;	// addr of active performance
      buf[8] = 0x0E;	// addr_Perf_EFX_parameter;
      buf[12] = 0x0C;	// number of parms to download
      buf[13] = chksum(buf+5, 8);	// checksum  
      buf[14] = 0xF7;
      if (open_ports() == EXIT_FAILURE) return;
      RetryA:
      if (sysex_send(buf,15) == EXIT_FAILURE) { close_ports(); return; }
      err = sysex_get((unsigned char *)&active_area->active_performance.perf_common.EFX_parameter[0], (char *)&EFX_parm_size);
      if (err == EXIT_FAILURE) return;
      if (err==2 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryA; }
      if (err==3 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryA; }
      if (err != EXIT_SUCCESS) { close_ports(); return; }
      close_ports();
    }	// end state_table->jv_connect
  } 	// state_table->updates_enabled
  setPerfEFXparms();
}	// end slotPerfEFXtype

void JVlibForm::slotPatchEFXtype(int val) {
  // called when the EFX type is changed on the PatchEFX Tab
 if (state_table->updates_enabled) {
  int	err;
  int	Stop=0;
  unsigned char buf[16];
  if (state_table->patch_mode) {
    active_area->active_patch_patch.patch_common.EFX_type = val;
    if (state_table->jv_connect) {
      setPatchSingleValue(addr_Patch_EFX_type, active_area->active_patch_patch.patch_common.EFX_type);
      // download the related parms for the new type
      memset(buf,0,sizeof(buf));
      buf[4] = JV_REQ;
      buf[5] = 0x03;	// addr of active Patch
      buf[8] = 0x0D;	// addr_Patch_EFX parameters
      buf[12] = 0x0C;	// number of parms to download
      buf[13] = chksum(buf+5, 8);	// checksum  
      buf[14] = 0xF7;
      if (open_ports() == EXIT_FAILURE) return;
      RetryB:
      if (sysex_send(buf,15) == EXIT_FAILURE) { close_ports(); return; }
      err = sysex_get((unsigned char *)&active_area->active_patch_patch.patch_common.EFX_parameter[0], (char *)&EFX_parm_size);
      if (err == EXIT_FAILURE) return;
      if (err==2 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryB; }
      if (err==3 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryB; }
      if (err != EXIT_SUCCESS) { close_ports(); return; }
      close_ports();
    }	// end state_table->jv_connect
  } else {	// do perf_mode update
    int pn = Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()-1;
    active_area->active_perf_patch[pn].patch_common.EFX_type = val;
    if (state_table->jv_connect) {
      setPatchSingleValue(addr_Patch_EFX_type, active_area->active_perf_patch[pn].patch_common.EFX_type);
      // download the related parms for the new type
      memset(buf,0,sizeof(buf));
      buf[4] = JV_REQ;
      buf[5] = 0x02;	// addr of active Patch
      buf[6] = pn;
      buf[8] = 0x0D;	// addr_Patch_EFX parameters
      buf[12] = 0x0C;	// number of parms to download
      buf[13] = chksum(buf+5, 8);	// checksum  
      buf[14] = 0xF7;
      if (open_ports() == EXIT_FAILURE) return;
      RetryF:
      if (sysex_send(buf,15) == EXIT_FAILURE) { close_ports(); return; }
      err = sysex_get((unsigned char *)&active_area->active_perf_patch[pn].patch_common.EFX_parameter[0], (char *)&EFX_parm_size);
      if (err == EXIT_FAILURE) return;
      if (err==2 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryF; }
      if (err==3 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryF; }
      if (err != EXIT_SUCCESS) { close_ports(); return; }
      close_ports();      
    }	// end state_table->jv_connect
  }	// end ELSE perf_mode
 }	// end Updates_enabled
  // update the on-screen display for the current parms
  setPatchEFXparms();
}	// end slotPatchEFXtype

//---------------------------------------------------------------------------------------------------------------------
// EFX OUTPUT
void JVlibForm::slotEFXoutput(int val) {
 if (state_table->updates_enabled) {
  if (sender() == PerfEFXoutput_select) {
    active_area->active_performance.perf_common.EFX_output = val;
    if (state_table->jv_connect) 
      setPerfSingleValue(addr_Perf_EFX_output ,val);
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_output = val;
    else
      active_area->active_patch_patch.patch_common.EFX_output = val;
    if (state_table->jv_connect) 
      setPatchSingleValue(addr_Patch_EFX_output,val);
  } 
 }
}
// EFX OUTPUT LEVEL
void JVlibForm::slotEFXoutputLevel(int val) {
 if (state_table->updates_enabled) {
 if (sender() == PerfEFXoutputLevel_select) {
  active_area->active_performance.perf_common.EFX_output_level = val;
  if (state_table->jv_connect) 
    setPerfSingleValue(addr_Perf_EFX_output_level,val);
 } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_output_level = val;
    else
      active_area->active_patch_patch.patch_common.EFX_output_level = val;
    if (state_table->jv_connect) 
      setPatchSingleValue(addr_Patch_EFX_output_level,val);
  }    
 } 
}
// EFX CHORUS SEND
void JVlibForm::slotEFXchorusSend(int val) {
 if (state_table->updates_enabled) {
 if (sender() == PerfEFXchorusSend_select) {
  active_area->active_performance.perf_common.EFX_chorus_send_level = val;
  if (state_table->jv_connect) 
    setPerfSingleValue(addr_Perf_EFX_chorus_send_level,val);
 } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_chorus_send_level = val;
    else
      active_area->active_patch_patch.patch_common.EFX_chorus_send_level = val;
    if (state_table->jv_connect) 
      setPatchSingleValue(addr_Patch_EFX_chorus_send_level,val);
  }    
 } 
}
// EFX REVERB SEND
void JVlibForm::slotEFXreverbSend(int val) {
 if (state_table->updates_enabled) {
 if (sender() == PerfEFXreverbSend_select) {
  active_area->active_performance.perf_common.EFX_reverb_send_level = val;
  if (state_table->jv_connect) 
    setPerfSingleValue(addr_Perf_EFX_reverb_send_level,val);
 } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_reverb_send_level = val;
    else
      active_area->active_patch_patch.patch_common.EFX_reverb_send_level = val;
    if (state_table->jv_connect) 
      setPatchSingleValue(addr_Patch_EFX_reverb_send_level,val);
  }     
 }
}
// EFX CONTROL 1 SOURCE
void JVlibForm::slotEFXcontrolSource1(int val) {
 if (state_table->updates_enabled) {
  if (sender() == PerfControlSource1_select) {
    active_area->active_performance.perf_common.EFX_control_src_1 = val;
    if (state_table->jv_connect) 
      setPerfSingleValue(addr_Perf_EFX_control_src_1,val);
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_control_src_1 = val;
    else
      active_area->active_patch_patch.patch_common.EFX_control_src_1 = val;
    if (state_table->jv_connect)
      setPatchSingleValue(addr_Patch_EFX_control_src_1,val);
  } 
 }	// end UPDATES_ENABLED
}	// end slotEFXcontrolSource1
// EFX CONTROL 1 DEPTH
void JVlibForm::slotEFXcontrol1Depth(int val) {
 if (state_table->updates_enabled) {
  if (sender() == PerfControl1Depth_select) {
    active_area->active_performance.perf_common.EFX_control_depth_1 = val+63;
    if (state_table->jv_connect) 
      setPerfSingleValue(addr_Perf_EFX_control_depth_1,val+63);
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_control_depth_1 = val+63;
    else
      active_area->active_patch_patch.patch_common.EFX_control_depth_1 = val+63;
    if (state_table->jv_connect) 
      setPatchSingleValue(addr_Patch_EFX_control_depth_1,val+63);
  }
 }	// end UPDATES_ENABLED
}	// end slotEFXcontrol1Depth
// EFX CONTROL 2 SOURCE
void JVlibForm::slotEFXcontrolSource2(int val) {
 if (state_table->updates_enabled) {
  if (sender() == PerfControlSource2_select) {
    active_area->active_performance.perf_common.EFX_control_src_2 = val;
    if (state_table->jv_connect) 
      setPerfSingleValue(addr_Perf_EFX_control_src_2,val);
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_control_src_2 = val;
    else
      active_area->active_patch_patch.patch_common.EFX_control_src_2 = val;
    if (state_table->jv_connect)
      setPatchSingleValue(addr_Patch_EFX_control_src_2,val);
  } 
 }	// end UPDATES_ENABLED
}	// end slotEFXcontrolSource2
// EFX CONTROL 2 DEPTH
void JVlibForm::slotEFXcontrol2Depth(int val) {
 if (state_table->updates_enabled) {
  if (sender() == PerfControl2Depth_select) {
    active_area->active_performance.perf_common.EFX_control_depth_2 = val+63;
  if (state_table->jv_connect) 
    setPerfSingleValue(addr_Perf_EFX_control_depth_2,val+63);
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_control_depth_2 = val+63;
    else
      active_area->active_patch_patch.patch_common.EFX_control_depth_2 = val+63;
  if (state_table->jv_connect) 
    setPatchSingleValue(addr_Patch_EFX_control_depth_2,val+63);
  }
 }
}
//---------------------------------------------------------------------------------------------------------------------
// Individual Parm changes handled starting here, to set the memory values to the new displayed control value
// The called process will update the display and the synth 
// EFX Parms
void JVlibForm::slotEFXparm1(int val) {
 if (state_table->updates_enabled) {
  if (sender() == PerfEFXparm1_select) {
    active_area->active_performance.perf_common.EFX_parameter[0] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_parameter[0] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[0] = val;
  }
  setEFXdisplayParm_1();	// in EFXdisplayParm1.cpp
 }
}
void JVlibForm::slotEFXparm2(int val) {
 if (state_table->updates_enabled) {
  if (sender() == PerfEFXparm2_select) {
    active_area->active_performance.perf_common.EFX_parameter[1] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_parameter[1] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[1] = val;
  }
  setEFXdisplayParm_2();
  }
}
void JVlibForm::slotEFXparm3(int val) {
 if (state_table->updates_enabled) {
  if (sender() == PerfEFXparm3_select) {
    active_area->active_performance.perf_common.EFX_parameter[2] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_parameter[2] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[2] = val;
  }
  setEFXdisplayParm_3();
  }
}

void JVlibForm::slotEFXparm4(int val) {
 if (state_table->updates_enabled) {
  if (sender() == PerfEFXparm4_select) {
    active_area->active_performance.perf_common.EFX_parameter[3] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_parameter[3] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[3] = val;
  }
  setEFXdisplayParm_4();
  }
}

void JVlibForm::slotEFXparm5(int val) {
 if (state_table->updates_enabled) {
  if (sender() == PerfEFXparm5_select) {
    active_area->active_performance.perf_common.EFX_parameter[4] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_parameter[4] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[4] = val;
  }
  setEFXdisplayParm_5();
  }
}

void JVlibForm::slotEFXparm6(int val) {
 if (state_table->updates_enabled) {
  if (sender() == PerfEFXparm6_select) {
    active_area->active_performance.perf_common.EFX_parameter[5] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_parameter[5] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[5] = val;
  }
  setEFXdisplayParm_6();
  }
}

void JVlibForm::slotEFXparm7(int val) {
 if (state_table->updates_enabled) {
  if (sender() == PerfEFXparm7_select) {
    active_area->active_performance.perf_common.EFX_parameter[6] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_parameter[6] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[6] = val;
  }
  setEFXdisplayParm_7();
  }
}

void JVlibForm::slotEFXparm8(int val) {
 if (state_table->updates_enabled) {
  if (sender() == PerfEFXparm8_select) {
    active_area->active_performance.perf_common.EFX_parameter[7] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_parameter[7] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[7] = val;
  }
  setEFXdisplayParm_8();
  }
}

void JVlibForm::slotEFXparm9(int val) {
 if (state_table->updates_enabled) {
  if (sender() == PerfEFXparm9_select) {
    active_area->active_performance.perf_common.EFX_parameter[8] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_parameter[8] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[8] = val;
  }
  setEFXdisplayParm_9();
  }
}

void JVlibForm::slotEFXparmA(int val) {
 if (state_table->updates_enabled) {
  if (sender() == PerfEFXparmA_select) {
    active_area->active_performance.perf_common.EFX_parameter[9] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_parameter[9] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[9] = val;
  }
  setEFXdisplayParm_A();
  }
}

void JVlibForm::slotEFXparmB(int val) {
 if (state_table->updates_enabled) {
  if (sender() == PerfEFXparmB_select) {
    active_area->active_performance.perf_common.EFX_parameter[10] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_parameter[10] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[10] = val;
  }
  setEFXdisplayParm_B();
  }
}

void JVlibForm::slotEFXparmC(int val) {
 if (state_table->updates_enabled) {
  if (sender() == PerfEFXparmC_select) {
    active_area->active_performance.perf_common.EFX_parameter[11] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.EFX_parameter[11] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[11] = val;
  }
  setEFXdisplayParm_C();
  }
}

