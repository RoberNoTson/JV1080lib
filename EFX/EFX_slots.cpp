// EFX_slots.cpp
/* Contains:
 * on_PerfEFXsource_select_currentIndexChanged
 * on_PatchEFX_TestTone_switch_toggled
 * on_PerfEFXtype_select_currentIndexChanged
 * on_PatchEFX_Type_select_currentIndexChanged
 * on_PerfEFXoutput_select_currentIndexChanged
 * on_PerfEFXoutputLevel_select_valueChanged
 * on_PerfEFXchorusSend_select_valueChanged
 * on_PerfEFXreverbSend_select_valueChanged
 * on_PerfControlSource1_select_currentIndexChanged
 * on_PerfControl1Depth_select_valueChanged
 * on_PerfControlSource2_select_currentIndexChanged
 * on_PerfControl2Depth_select_valueChanged
 * on_PerfEFXparm1_select_valueChanged
 * on_PerfEFXparm2_select_valueChanged
 * on_PerfEFXparm3_select_valueChanged
 * on_PerfEFXparm4_select_valueChanged
 * on_PerfEFXparm5_select_valueChanged
 * on_PerfEFXparm6_select_valueChanged
 * on_PerfEFXparm7_select_valueChanged
 * on_PerfEFXparm8_select_valueChanged
 * on_PerfEFXparm9_select_valueChanged
 * on_PerfEFXparmA_select_valueChanged
 * on_PerfEFXparmB_select_valueChanged
 * on_PerfEFXparmC_select_valueChanged
 */

#include        "JVlibForm.h"
#include        <QtGui>
#include	"EFX/EFX_slots.h"

// EFX SOURCE -- only Performance EFX has a Source selection
void JVlibForm::on_PerfEFXsource_select_currentIndexChanged(int val) {
 if (!state_table->updates_enabled) return;
  active_area->active_performance.perf_common.EFX_source = val;
  setPerfSingleValue(addr_Perf_EFX_source ,val);
  Perf_EFX_groupBox->setEnabled(val?false:true);
}

void JVlibForm::on_PatchEFX_TestTone_switch_toggled(bool val) {
  if (!state_table->jv_connect) return;
  int pn = state_table->perf_mode ? (Patch_PerfPartNum_select->currentIndex()) : 0;
  if (val) {
    change_3(0x90 + (state_table->perf_mode ? active_area->active_performance.perf_part[pn].MIDI_channel : 
      system_area->sys_common.patch_receive_channel), SysPreviewNote1_select->value(), SysPreviewNote1_volume->value());
  } 
  else {
    change_3(0xB0 + (state_table->perf_mode ? active_area->active_performance.perf_part[pn].MIDI_channel : 
      system_area->sys_common.patch_receive_channel), 0x7B, 0x0);
  }
  PatchEFX_TestTone_switch->setText(val ? QString::fromUtf8("Stop") : QString::fromUtf8("Play Patch") );
}

//EFX_TYPE
void JVlibForm::on_PerfEFXtype_select_currentIndexChanged(int val) {
  // called when EFX type is changed on the Performance Tab
 if (!state_table->updates_enabled) return;
  int	err;
  int	Stop=0;
  unsigned char buf[8];
  // update type
  active_area->active_performance.perf_common.EFX_type = val;
  if (!state_table->jv_connect) return;
  setPerfSingleValue(addr_Perf_EFX_type, active_area->active_performance.perf_common.EFX_type);
  // download the related parms for the new type
  memset(buf,0,sizeof(buf));
  buf[0] = 0x01;	// addr of active performance
  buf[3] = 0x0E;	// addr_Perf_EFX_parameter;
  buf[7] = 0x0C;	// number of parms to download
  if (open_ports() == EXIT_FAILURE) return;
  RetryA:
  if (sysex_request(buf) == EXIT_FAILURE) { close_ports(); return; }
  err = sysex_get((unsigned char *)&active_area->active_performance.perf_common.EFX_parameter[0], (char *)&EFX_parm_size);
  if (err == EXIT_FAILURE) return;
  if (err==2 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryA; }
  if (err==3 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryA; }
  if (err != EXIT_SUCCESS) { close_ports(); return; }
  close_ports();
  setPerfEFXparms();
}	// end slotPerfEFXtype

void JVlibForm::on_PatchEFX_Type_select_currentIndexChanged(int val) {
  // called when the EFX type is changed on the PatchEFX Tab
 if (!state_table->updates_enabled) return;
  int	err;
  int	Stop=0;
  unsigned char buf[8];
  if (state_table->patch_mode) {
    active_area->active_patch_patch.patch_common.EFX_type = val;
    if (state_table->jv_connect) {
      setPatchSingleValue(addr_Patch_EFX_type, active_area->active_patch_patch.patch_common.EFX_type);
      // download the related parms for the new type
      memset(buf,0,sizeof(buf));
      buf[0] = 0x03;	// addr of active Patch
      buf[3] = 0x0D;	// addr_Patch_EFX parameters
      buf[7] = 0x0C;	// number of parms to download
      if (open_ports() == EXIT_FAILURE) return;
      RetryB:
      if (sysex_request(buf) == EXIT_FAILURE) { close_ports(); return; }
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
      buf[0] = 0x02;	// addr of active Patch
      buf[1] = pn;
      buf[3] = 0x0D;	// addr_Patch_EFX parameters
      buf[7] = 0x0C;	// number of parms to download
      if (open_ports() == EXIT_FAILURE) return;
      RetryF:
      if (sysex_request(buf) == EXIT_FAILURE) { close_ports(); return; }
      err = sysex_get((unsigned char *)&active_area->active_perf_patch[pn].patch_common.EFX_parameter[0], (char *)&EFX_parm_size);
      if (err == EXIT_FAILURE) return;
      if (err==2 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryF; }
      if (err==3 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryF; }
      if (err != EXIT_SUCCESS) { close_ports(); return; }
      close_ports();      
    }	// end state_table->jv_connect
  }	// end ELSE perf_mode
  // update the on-screen display for the current parms
  setPatchEFXparms();
}	// end slotPatchEFXtype

//---------------------------------------------------------------------------------------------------------------------
// EFX OUTPUT
void JVlibForm::on_PerfEFXoutput_select_currentIndexChanged(int val) {
 if (!state_table->updates_enabled) return;
    active_area->active_performance.perf_common.EFX_output = val;
    if (state_table->jv_connect) 
      setPerfSingleValue(addr_Perf_EFX_output ,val);
}
// EFX OUTPUT LEVEL
void JVlibForm::on_PerfEFXoutputLevel_select_valueChanged(int val) {
 if (!state_table->updates_enabled) return;
  active_area->active_performance.perf_common.EFX_output_level = val;
  if (state_table->jv_connect) 
    setPerfSingleValue(addr_Perf_EFX_output_level,val);
}
// EFX CHORUS SEND
void JVlibForm::on_PerfEFXchorusSend_select_valueChanged(int val) {
 if (!state_table->updates_enabled) return;
  active_area->active_performance.perf_common.EFX_chorus_send_level = val;
  if (state_table->jv_connect) 
    setPerfSingleValue(addr_Perf_EFX_chorus_send_level,val);
}
// EFX REVERB SEND
void JVlibForm::on_PerfEFXreverbSend_select_valueChanged(int val) {
 if (!state_table->updates_enabled) return;
  active_area->active_performance.perf_common.EFX_reverb_send_level = val;
  if (state_table->jv_connect) 
    setPerfSingleValue(addr_Perf_EFX_reverb_send_level,val);
}
// EFX CONTROL 1 SOURCE
void JVlibForm::on_PerfControlSource1_select_currentIndexChanged(int val) {
 if (!state_table->updates_enabled) return;
    active_area->active_performance.perf_common.EFX_control_src_1 = val;
    if (state_table->jv_connect) 
      setPerfSingleValue(addr_Perf_EFX_control_src_1,val);
}	// end slotEFXcontrolSource1
// EFX CONTROL 1 DEPTH
void JVlibForm::on_PerfControl1Depth_select_valueChanged(int val) {
 if (!state_table->updates_enabled) return;
    active_area->active_performance.perf_common.EFX_control_depth_1 = val+63;
    if (state_table->jv_connect) 
      setPerfSingleValue(addr_Perf_EFX_control_depth_1,val+63);
}	// end slotEFXcontrol1Depth
// EFX CONTROL 2 SOURCE
void JVlibForm::on_PerfControlSource2_select_currentIndexChanged(int val) {
 if (!state_table->updates_enabled) return;
    active_area->active_performance.perf_common.EFX_control_src_2 = val;
    if (state_table->jv_connect) 
      setPerfSingleValue(addr_Perf_EFX_control_src_2,val);
}	// end slotEFXcontrolSource2
// EFX CONTROL 2 DEPTH
void JVlibForm::on_PerfControl2Depth_select_valueChanged(int val) {
 if (!state_table->updates_enabled) return;
    active_area->active_performance.perf_common.EFX_control_depth_2 = val+63;
  if (state_table->jv_connect) 
    setPerfSingleValue(addr_Perf_EFX_control_depth_2,val+63);
}	// end on_PerfControl2Depth_select_valueChanged

//---------------------------------------------------------------------------------------------------------------------
// Individual Parm changes handled starting here, to set the memory values to the new displayed control value
// The called process will update the display and the synth 
// EFX Parms
void JVlibForm::on_PerfEFXparm1_select_valueChanged(int val) {
 if (!state_table->updates_enabled) return;
  int pn = 0;
  if (sender() == PerfEFXparm1_select) {
    active_area->active_performance.perf_common.EFX_parameter[pn] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.EFX_parameter[pn] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[pn] = val;
  }
  setEFXdisplayParm_1();	// in EFXdisplayParm1.cpp
}
void JVlibForm::on_PerfEFXparm2_select_valueChanged(int val) {
 if (!state_table->updates_enabled) return;
  int pn = 1;
  if (sender() == PerfEFXparm2_select) {
    active_area->active_performance.perf_common.EFX_parameter[pn] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.EFX_parameter[pn] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[pn] = val;
  }
  setEFXdisplayParm_2();
}
void JVlibForm::on_PerfEFXparm3_select_valueChanged(int val) {
 if (!state_table->updates_enabled) return;
  int pn = 2;
  if (sender() == PerfEFXparm3_select) {
    active_area->active_performance.perf_common.EFX_parameter[pn] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.EFX_parameter[pn] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[pn] = val;
  }
  setEFXdisplayParm_3();
}

void JVlibForm::on_PerfEFXparm4_select_valueChanged(int val) {
 if (!state_table->updates_enabled) return;
  int pn = 3;
  if (sender() == PerfEFXparm4_select) {
    active_area->active_performance.perf_common.EFX_parameter[pn] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.EFX_parameter[pn] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[pn] = val;
  }
  setEFXdisplayParm_4();
}

void JVlibForm::on_PerfEFXparm5_select_valueChanged(int val) {
 if (!state_table->updates_enabled) return;
  int pn = 4;
  if (sender() == PerfEFXparm5_select) {
    active_area->active_performance.perf_common.EFX_parameter[pn] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.EFX_parameter[pn] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[pn] = val;
  }
  setEFXdisplayParm_5();
}

void JVlibForm::on_PerfEFXparm6_select_valueChanged(int val) {
 if (!state_table->updates_enabled) return;
  int pn = 5;
  if (sender() == PerfEFXparm6_select) {
    active_area->active_performance.perf_common.EFX_parameter[pn] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.EFX_parameter[pn] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[pn] = val;
  }
  setEFXdisplayParm_6();
}

void JVlibForm::on_PerfEFXparm7_select_valueChanged(int val) {
 if (!state_table->updates_enabled) return;
  int pn = 6;
  if (sender() == PerfEFXparm7_select) {
    active_area->active_performance.perf_common.EFX_parameter[pn] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.EFX_parameter[pn] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[pn] = val;
  }
  setEFXdisplayParm_7();
}

void JVlibForm::on_PerfEFXparm8_select_valueChanged(int val) {
 if (!state_table->updates_enabled) return;
  int pn = 7;
  if (sender() == PerfEFXparm8_select) {
    active_area->active_performance.perf_common.EFX_parameter[pn] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.EFX_parameter[pn] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[pn] = val;
  }
  setEFXdisplayParm_8();
}

void JVlibForm::on_PerfEFXparm9_select_valueChanged(int val) {
 if (!state_table->updates_enabled) return;
  int pn = 8;
  if (sender() == PerfEFXparm9_select) {
    active_area->active_performance.perf_common.EFX_parameter[pn] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.EFX_parameter[pn] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[pn] = val;
  }
  setEFXdisplayParm_9();
}

void JVlibForm::on_PerfEFXparmA_select_valueChanged(int val) {
 if (!state_table->updates_enabled) return;
  int pn = 9;
  if (sender() == PerfEFXparmA_select) {
    active_area->active_performance.perf_common.EFX_parameter[pn] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.EFX_parameter[pn] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[pn] = val;
  }
  setEFXdisplayParm_A();
}

void JVlibForm::on_PerfEFXparmB_select_valueChanged(int val) {
 if (!state_table->updates_enabled) return;
  int pn = 10;
  if (sender() == PerfEFXparmB_select) {
    active_area->active_performance.perf_common.EFX_parameter[pn] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.EFX_parameter[pn] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[pn] = val;
  }
  setEFXdisplayParm_B();
}

void JVlibForm::on_PerfEFXparmC_select_valueChanged(int val) {
 if (!state_table->updates_enabled) return;
  int pn = 11;
  if (sender() == PerfEFXparmC_select) {
    active_area->active_performance.perf_common.EFX_parameter[pn] = val;
  } else {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.EFX_parameter[pn] = val;
    else
      active_area->active_patch_patch.patch_common.EFX_parameter[pn] = val;
  }
  setEFXdisplayParm_C();
}

