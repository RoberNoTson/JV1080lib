// patch_slots.cpp
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::on_Patch_Sync_button_clicked() {
  JVlibForm::statusbar->showMessage("Getting Patch data",0);
  state_table->updates_enabled=false;
  if (state_table->perf_mode) {
    getActivePerfPatches();
    setPatchParms(Patch_PerfPartNum_select->currentIndex()+1);	// will also set Tone, Pitch, etc.
  } else {
    getActivePatchMode();
    setPatchParms(0);	// will also set Tone, Pitch, etc.
  }
  EnablePatch(true);
  state_table->updates_enabled=true;
  statusbar->showMessage("Patch data loaded",0);
}

void JVlibForm::on_Patch_Name_edit_editingFinished() {
  // called after Patch name has been edited
  if (state_table->updates_enabled) {
    if (Patch_Name_edit->isModified()) {
      // change the Patch name
      QString val = Patch_Name_edit->text();
      val = val.leftJustified(12, ' ');
      // update memory and related displays with the new Name
      if (state_table->perf_mode) {
	memcpy(&active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.name[0],val.toAscii(),12);
	PatchEFX_Name_display->setText(val);
	Tone_PatchName_display->setText(val);
	switch(Patch_PerfPartNum_select->currentIndex()+1) {
	case 1: case 6: case 12:
	  Part1_PatchName_display->setText(val);
	  break;
	case 2: case 7: case 13:
	  Part2_PatchName_display->setText(val);
	  break;     
	case 3: case 8: case 14:
	  Part3_PatchName_display->setText(val);
	  break;     
	case 4: case 9: case 15:
	  Part4_PatchName_display->setText(val);
	  break;      
	case 5: case 11: case 16:
	  Part5_PatchName_display->setText(val);
	  break;
	}	// end Switch  
      } else {
	memcpy(&active_area->active_patch_patch.patch_common.name[0],val.toAscii(),12);
	SysPatchName->setText(val);
      }
      if (state_table->jv_connect) {
      // update the synth
      unsigned char buf[23];
      memset(buf,0,sizeof(buf));
      buf[4] = JV_UPD;
      if (state_table->perf_mode) {
	buf[5] = 0x02;
	buf[6] = Patch_PerfPartNum_select->currentIndex();
      } else {
	buf[5] = 0x03;
	buf[6] = 0x0;
      }
      memcpy(&buf[9], val.toAscii(), 12);
      buf[21] = chksum(buf+5, 16);
      buf[22] = 0xF7;
      if (open_ports() == EXIT_FAILURE) return;
      if (sysex_send(buf,sizeof(buf)) == EXIT_FAILURE) { close_ports(); return; }
      close_ports();	
      }
      state_table->patch_modified = true;
      Patch_Name_edit->setModified(false);
    }	// end IF Patch_Name_edit->isModified
  }	// end UPDATES_ENABLED
}	// end on_Patch_Name_edit_editingFinished

//---------------------------------------------------------------------------------------------------------------------
// switches
void JVlibForm::on_Patch_PerfPartNum_select_currentIndexChanged(int val) {
  if (val == 9) return;
  if (state_table->updates_enabled)
    setPatchParms(state_table->perf_mode ? val+1 : 0);
}

void JVlibForm::on_PatchEFX_Control1Source_select_currentIndexChanged(int val) {
  if (state_table->updates_enabled) {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.EFX_control_src_1 = val;
    else
      active_area->active_patch_patch.patch_common.EFX_control_src_1 = val;
    if (state_table->jv_connect) 
      setPatchSingleValue(0x1D, val);
  }
}
void JVlibForm::on_PatchEFX_Control1Depth_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.EFX_control_depth_1 = val+63;
    else
      active_area->active_patch_patch.patch_common.EFX_control_depth_1 = val+63;
    if (state_table->jv_connect) 
      setPatchSingleValue(0x1E, val+63);
  }
}
void JVlibForm::on_PatchEFX_Control2Source_select_currentIndexChanged(int val) {
  if (state_table->updates_enabled) {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.EFX_control_src_2 = val;
    else
      active_area->active_patch_patch.patch_common.EFX_control_src_2 = val;
    if (state_table->jv_connect) 
      setPatchSingleValue(0x1F, val);
  }
}
void JVlibForm::on_PatchEFX_Control2Depth_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.EFX_control_depth_2 = val+63;
    else
      active_area->active_patch_patch.patch_common.EFX_control_depth_2 = val+63;
    if (state_table->jv_connect) 
      setPatchSingleValue(0x20, val+63);
  }
}

void JVlibForm::on_Patch_Level_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.level = val;
    else
      active_area->active_patch_patch.patch_common.level = val;
    if (state_table->jv_connect) 
      setPatchSingleValue(0x2E, val);
  }
}
void JVlibForm::on_Patch_Pan_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.pan = val+64;
    else
      active_area->active_patch_patch.patch_common.pan = val+64;
    if (state_table->jv_connect) 
      setPatchSingleValue(0x2F, val+64);
  }
}
void JVlibForm::on_Patch_AnalogFeel_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.analog_feel_depth = val;
    else
      active_area->active_patch_patch.patch_common.analog_feel_depth = val;
    if (state_table->jv_connect) 
      setPatchSingleValue(0x30, val);    
  }
}
void JVlibForm::on_Patch_PortamentoTime_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.portamento_time = val;
    else
      active_area->active_patch_patch.patch_common.portamento_time = val;
    if (state_table->jv_connect) 
      setPatchSingleValue(0x39, val);    
  }
}
void JVlibForm::on_Patch_BenderUp_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.bender_range_up = val;
    else
      active_area->active_patch_patch.patch_common.bender_range_up = val;
    if (state_table->jv_connect) 
      setPatchSingleValue(0x31, val);    
  }
}
void JVlibForm::on_Patch_BenderDown_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.bender_range_down = -1*val;
    else
      active_area->active_patch_patch.patch_common.bender_range_down = -1*val;
    if (state_table->jv_connect) 
      setPatchSingleValue(0x32, -1*val);    
  }
}
void JVlibForm::on_Patch_HoldPeak_select_currentIndexChanged(int val) {
  if (state_table->updates_enabled) {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.control_hold_peak = val;
    else
      active_area->active_patch_patch.patch_common.control_hold_peak = val;
    if (state_table->jv_connect) 
      setPatchSingleValue(0x3C, val);    
  }
}
void JVlibForm::on_Patch_C1_HoldPeak_select_currentIndexChanged(int val) {
  if (state_table->updates_enabled) {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.control_1_hold_peak = val;
    else
      active_area->active_patch_patch.patch_common.control_1_hold_peak = val;
    if (state_table->jv_connect) 
      setPatchSingleValue(0x3D, val);    
  }
}
void JVlibForm::on_Patch_C2_HoldPeak_select_currentIndexChanged(int val) {
  if (state_table->updates_enabled) {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.control_2_hold_peak = val;
    else
      active_area->active_patch_patch.patch_common.control_2_hold_peak = val;
    if (state_table->jv_connect) 
      setPatchSingleValue(0x3E, val);    
  }
}
void JVlibForm::on_Patch_C3_HoldPeak_select_currentIndexChanged(int val) {
  if (state_table->updates_enabled) {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.control_3_hold_peak = val;
    else
      active_area->active_patch_patch.patch_common.control_3_hold_peak = val;
    if (state_table->jv_connect) 
      setPatchSingleValue(0x3F, val);    
  }
}

void JVlibForm::on_Patch_Struct12_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.structure_type_1_2 = val-1;
  else
    active_area->active_patch_patch.patch_common.structure_type_1_2 = val-1;
  if (state_table->jv_connect) 
    setPatchSingleValue(0x44, val-1);    
  switch(val) {
    case 1:
      Patch_Struct12_view->setScene(scene1);
      Patch_Booster12_select->setEnabled(false);
      break;
    case 2:
      Patch_Struct12_view->setScene(scene2);
      Patch_Booster12_select->setEnabled(false);
      break;
    case 3:
      Patch_Struct12_view->setScene(scene3);
      Patch_Booster12_select->setEnabled(true);
      break;
    case 4:
      Patch_Struct12_view->setScene(scene4);
      Patch_Booster12_select->setEnabled(true);
      break;
    case 5:
      Patch_Struct12_view->setScene(scene5);
      Patch_Booster12_select->setEnabled(false);
      break;
    case 6:
      Patch_Struct12_view->setScene(scene6);
      Patch_Booster12_select->setEnabled(false);
      break;
    case 7:
      Patch_Struct12_view->setScene(scene7);
      Patch_Booster12_select->setEnabled(false);
      break;
    case 8:
      Patch_Struct12_view->setScene(scene8);
      Patch_Booster12_select->setEnabled(false);
      break;
    case 9:
      Patch_Struct12_view->setScene(scene9);
      Patch_Booster12_select->setEnabled(false);
      break;
    case 10:
      Patch_Struct12_view->setScene(scene10);
      Patch_Booster12_select->setEnabled(false);
      break;
    default:
      Patch_Struct12_view->setScene(scene1);
      Patch_Booster12_select->setEnabled(false);
      break;
  }
  Patch_Struct12_view->show();
  }	// end UPDATES_ENABLED
}	// end on_Patch_Struct12_select_valueChanged

void JVlibForm::on_Patch_Booster12_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.booster_level_1_2 = val/6;
  else
    active_area->active_patch_patch.patch_common.booster_level_1_2 = val/6;
  if (state_table->jv_connect) 
    setPatchSingleValue(0x45, val/6);    
  }
}
void JVlibForm::on_Patch_Struct34_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.structure_type_3_4 = val-1;
  else
    active_area->active_patch_patch.patch_common.structure_type_3_4 = val-1;
  if (state_table->jv_connect) 
    setPatchSingleValue(0x46, val-1);    
  switch(val) {
    case 1:
      Patch_Struct34_view->setScene(scene1);
      Patch_Booster34_select->setEnabled(false);
      break;
    case 2:
      Patch_Struct34_view->setScene(scene2);
      Patch_Booster34_select->setEnabled(false);
      break;
    case 3:
      Patch_Struct34_view->setScene(scene3);
      Patch_Booster34_select->setEnabled(true);
      break;
    case 4:
      Patch_Struct34_view->setScene(scene4);
      Patch_Booster34_select->setEnabled(true);
      break;
    case 5:
      Patch_Struct34_view->setScene(scene5);
      Patch_Booster34_select->setEnabled(false);
      break;
    case 6:
      Patch_Struct34_view->setScene(scene6);
      Patch_Booster34_select->setEnabled(false);
      break;
    case 7:
      Patch_Struct34_view->setScene(scene7);
      Patch_Booster34_select->setEnabled(false);
      break;
    case 8:
      Patch_Struct34_view->setScene(scene8);
      Patch_Booster34_select->setEnabled(false);
      break;
    case 9:
      Patch_Struct34_view->setScene(scene9);
      Patch_Booster34_select->setEnabled(false);
      break;
    case 10:
      Patch_Struct34_view->setScene(scene10);
      Patch_Booster34_select->setEnabled(false);
      break;
    default:
      Patch_Struct34_view->setScene(scene1);
      Patch_Booster34_select->setEnabled(false);
      break;
  }
  Patch_Struct34_view->show();
  }	// end UPDATES_ENABLED
}	// end on_Patch_Struct34_select_valueChanged

void JVlibForm::on_Patch_Booster34_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.booster_level_3_4 = val/6;
  else
    active_area->active_patch_patch.patch_common.booster_level_3_4 = val/6;
  if (state_table->jv_connect) 
    setPatchSingleValue(0x47, val/6);
  }
}
//void JVlibForm::slotPatch_DefaultTempo(int val) {
void JVlibForm::on_Patch_DefaultTempo_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
    int HVal = val/16;
    int LVal = val%16;
  if (state_table->perf_mode) {
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.default_tempo_high = HVal;
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.default_tempo_low = LVal;
  } else {
    active_area->active_patch_patch.patch_common.default_tempo_high = HVal;
    active_area->active_patch_patch.patch_common.default_tempo_low = LVal;
  }
  if (state_table->jv_connect) {
    unsigned char buf[13];
    buf[4] = JV_UPD;
    buf[5] = (state_table->perf_mode?0x02:0x03);	// are we in Perf or Patch mode?
    buf[6] = 0x00 + (state_table->perf_mode ? Patch_PerfPartNum_select->currentIndex() : 0);	// select the Perf Part, if in that mode
    buf[7] = 0x00;
    buf[8] = 0x2C;
    buf[9] = HVal;
    buf[10] = LVal;
    buf[11] = chksum(buf+5, 6);
    buf[12] = 0xF7;
    if (open_ports() == EXIT_FAILURE) return;
    if (sysex_send(buf,13) == EXIT_FAILURE) {
      close_ports(); 
      return;
    close_ports();
    }
  }	// end state_table->jv_connect
  state_table->patch_modified = true;
 }	// end state_table->updates_enabled
}	// end slotPatchDefaultTempo
  
void JVlibForm::on_Patch_VoicePriority_switch_toggled(bool val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.voice_priority = val;
  else
    active_area->active_patch_patch.patch_common.voice_priority = val;
  Patch_VoicePriority_switch->setText(val==0 ? QString("Last") : QString("Loudest"));
  if (state_table->jv_connect) 
    setPatchSingleValue(0x43, val);
  }
}
void JVlibForm::on_Patch_VoiceMode_switch_toggled(bool val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.key_assign_mode = val;
  else
    active_area->active_patch_patch.patch_common.key_assign_mode = val;
  Patch_VoiceMode_switch->setText(val==false ? QString("Poly") : QString("Solo"));
  Patch_SoloLegato_enable->setEnabled(val);
  if (state_table->jv_connect) 
    setPatchSingleValue(0x33, val);
  }
}
void JVlibForm::on_Patch_SoloLegato_enable_toggled(bool val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.legato = val;
  else
    active_area->active_patch_patch.patch_common.legato = val;
  if (state_table->jv_connect) 
    setPatchSingleValue(0x34, val);
  }
}  
void JVlibForm::on_Patch_PortamentoEnable_switch_toggled(bool val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.portamento = val;
  else
    active_area->active_patch_patch.patch_common.portamento = val;
  Patch_PortamentoEnable_switch->setText(val==0 ? QString("Off") : QString("On"));
  if (state_table->jv_connect) 
    setPatchSingleValue(0x35, val);
  }
}
void JVlibForm::on_Patch_PortamentoMode_switch_toggled(bool val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.portamento_mode = val;
  else
    active_area->active_patch_patch.patch_common.portamento_mode = val;
  Patch_PortamentoMode_switch->setText(val==0 ? QString("Normal") : QString("Legato"));
  if (state_table->jv_connect) 
    setPatchSingleValue(0x36, val);
  }
}
void JVlibForm::on_Patch_PortamentoType_switch_toggled(bool val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.portamento_type = val;
  else
    active_area->active_patch_patch.patch_common.portamento_type = val;
  Patch_PortamentoType_switch->setText(val==0 ? QString("Rate") : QString("Time"));
  if (state_table->jv_connect) 
    setPatchSingleValue(0x37, val);
  }
}
void JVlibForm::on_Patch_PortamentoStart_switch_toggled(bool val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.portamento_start = val;
  else
    active_area->active_patch_patch.patch_common.portamento_start = val;
  Patch_PortamentoStart_switch->setText(val==0 ? QString("Pitch") : QString("Note"));
  if (state_table->jv_connect) 
    setPatchSingleValue(0x38, val);
  }
}
void JVlibForm::on_Patch_ControlSource2_select_currentIndexChanged(int val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.patch_control_src_2 = val;
  else
    active_area->active_patch_patch.patch_common.patch_control_src_2 = val;
  if (state_table->jv_connect) 
    setPatchSingleValue(0x3A, val);
  }
}
void JVlibForm::on_Patch_ControlSource3_select_currentIndexChanged(int val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.patch_control_src_3 = val;
  else
    active_area->active_patch_patch.patch_common.patch_control_src_3 = val;
  if (state_table->jv_connect) 
    setPatchSingleValue(0x3B, val);
  }
}
void JVlibForm::on_Patch_VelocityRange_enable_toggled(bool val) {
  if (state_table->updates_enabled) {
    if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.velocity_range = val;
    else
      active_area->active_patch_patch.patch_common.velocity_range = val;
  if (state_table->jv_connect) 
    setPatchSingleValue(0x40, val);      
  }
}

void JVlibForm::on_Patch_Tone1_enable_toggled(bool val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_tone[0].tone = val;
  else
    active_area->active_patch_patch.patch_tone[0].tone = val;
  Tone_ToneNumber_select->setMaximum(Patch_Tone4_enable->isChecked()?4:Patch_Tone3_enable->isChecked()?3:Patch_Tone2_enable->isChecked()?2:1);
  if (state_table->jv_connect) 
    setToneSingleValue(0, 0x00, val);
  }
}
void JVlibForm::on_Patch_Tone2_enable_toggled(bool val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_tone[1].tone = val;
  else
    active_area->active_patch_patch.patch_tone[1].tone = val;
  Tone_ToneNumber_select->setMaximum(Patch_Tone4_enable->isChecked()?4:Patch_Tone3_enable->isChecked()?3:Patch_Tone2_enable->isChecked()?2:1);
  if (state_table->jv_connect) 
    setToneSingleValue(1, 0x00, val);    
  }
}
void JVlibForm::on_Patch_Tone3_enable_toggled(bool val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_tone[2].tone = val;
  else
    active_area->active_patch_patch.patch_tone[2].tone = val;
  }
  Tone_ToneNumber_select->setMaximum(Patch_Tone4_enable->isChecked()?4:Patch_Tone3_enable->isChecked()?3:Patch_Tone2_enable->isChecked()?2:1);
  if (state_table->jv_connect) 
    setToneSingleValue(2, 0x00, val);    
}
void JVlibForm::on_Patch_Tone4_enable_toggled(bool val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_tone[3].tone = val;
  else
    active_area->active_patch_patch.patch_tone[3].tone = val;
  if (val) Tone_ToneNumber_select->setMaximum(4);
  else	Tone_ToneNumber_select->setMaximum(Patch_Tone3_enable->isChecked()?3:Patch_Tone2_enable->isChecked()?2:1);
  if (state_table->jv_connect) 
    setToneSingleValue(3, 0x00, val);
  }
}

void JVlibForm::on_PatchEFX_ReverbHiFreqDamp_select_currentIndexChanged(int val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.reverb_HF_damp = val;
    else
      active_area->active_patch_patch.patch_common.reverb_HF_damp = val;
  if (state_table->jv_connect) 
    setPatchSingleValue(0x2A, val);
  }
}
void JVlibForm::on_PatchEFX_ReverbLevel_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.reverb_level = val;
    else
      active_area->active_patch_patch.patch_common.reverb_level = val;
  if (state_table->jv_connect) 
    setPatchSingleValue(0x28, val);
  }
}
void JVlibForm::on_PatchEFX_ReverbTime_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.reverb_time = val;
    else
      active_area->active_patch_patch.patch_common.reverb_time = val;
  if (state_table->jv_connect) 
    setPatchSingleValue(0x29, val);
  }
}
void JVlibForm::on_PatchEFX_ReverbType_select_currentIndexChanged(int val) {
  PatchEFX_ReverbFeedback_select->setEnabled(PatchEFX_ReverbType_select->currentIndex()>5?true:false);  
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.reverb_type = val;
    else
      active_area->active_patch_patch.patch_common.reverb_type = val;
  if (state_table->jv_connect) 
    setPatchSingleValue(0x27, val);
  }
}
void JVlibForm::on_PatchEFX_ReverbFeedback_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.reverb_feedback = val;
    else
      active_area->active_patch_patch.patch_common.reverb_feedback = val;
  if (state_table->jv_connect) 
    setPatchSingleValue(0x2B, val);
  }
}
void JVlibForm::on_PatchEFX_ChorusLevel_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.chorus_level = val;
    else
      active_area->active_patch_patch.patch_common.chorus_level = val;
  if (state_table->jv_connect) 
    setPatchSingleValue(0x21, val);
  }
}
void JVlibForm::on_PatchEFX_ChorusRate_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.chorus_rate = val;
    else
      active_area->active_patch_patch.patch_common.chorus_rate = val;
  if (state_table->jv_connect) 
    setPatchSingleValue(0x22, val);
  }
}
void JVlibForm::on_PatchEFX_ChorusDepth_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.chorus_depth= val;
    else
      active_area->active_patch_patch.patch_common.chorus_depth = val;
  if (state_table->jv_connect) 
    setPatchSingleValue(0x23, val);
  }
}
void JVlibForm::on_PatchEFX_ChorusPreDelay_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.chorus_pre_delay = val;
    else
      active_area->active_patch_patch.patch_common.chorus_pre_delay = val;
  if (state_table->jv_connect) 
    setPatchSingleValue(0x24, val);
  }
}
void JVlibForm::on_PatchEFX_ChorusFeedback_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.chorus_feedback = val;
    else
      active_area->active_patch_patch.patch_common.chorus_feedback = val;
  if (state_table->jv_connect) 
    setPatchSingleValue(0x25, val);
  }
}
void JVlibForm::on_PatchEFX_ChorusOutput_select_currentIndexChanged(int val) {
  if (state_table->updates_enabled) {
  if (state_table->perf_mode)
      active_area->active_perf_patch[Patch_PerfPartNum_select->itemText(Patch_PerfPartNum_select->currentIndex()).toInt()].patch_common.chorus_output = val;
    else
      active_area->active_patch_patch.patch_common.chorus_output = val;
  if (state_table->jv_connect) 
    setPatchSingleValue(0x26, val);
  }
}

//---------------------------------------------------------------------------------------------------------------------
// Patch Group/Number

void JVlibForm::on_Patch_Group_select_currentIndexChanged(int val) {
  if (state_table->updates_enabled) {
    int ppn = Patch_PerfPartNum_select->currentIndex();
    int pn = Patch_Number_select->value()-1;
    int Hnum = (pn/16);
    int MSB,LSB;
    switch(val) {
      case 0:	// User
	if (state_table->perf_mode) {
	  active_area->active_performance.perf_part[ppn].patch_group = 0x00;
	  active_area->active_performance.perf_part[ppn].patch_group_id = 0x01;
	} else {
	  system_area->sys_common.patch_group = 0x00;
	  system_area->sys_common.patch_group_id = 0x01;
	}
	MSB = 0x50;
	LSB = 0;
	Patch_Number_select->setMaximum(128);
	break;
      case 1:	// Expansion A
	if (state_table->perf_mode) {
	  active_area->active_performance.perf_part[ppn].patch_group = 0x02;
	  active_area->active_performance.perf_part[ppn].patch_group_id = 0x02;
	} else {
	  system_area->sys_common.patch_group = 0x02;
	  system_area->sys_common.patch_group_id = 0x02;
	}
	MSB = 0x54;
	LSB = Hnum?1:0;
	Patch_Number_select->setMaximum(255);
	break;
      case 2:	// PresetA
	if (state_table->perf_mode) {
	  active_area->active_performance.perf_part[ppn].patch_group = 0x00;
	  active_area->active_performance.perf_part[ppn].patch_group_id = 0x03;
	} else {
	  system_area->sys_common.patch_group = 0x00;
	  system_area->sys_common.patch_group_id = 0x03;
	}
	MSB = 0x51;
	LSB = 0x0;
	Patch_Number_select->setMaximum(128);
	break;
      case 3:	// PresetB
	if (state_table->perf_mode) {
	  active_area->active_performance.perf_part[ppn].patch_group = 0x00;
	  active_area->active_performance.perf_part[ppn].patch_group_id = 0x04;
	} else {
	  system_area->sys_common.patch_group = 0x00;
	  system_area->sys_common.patch_group_id = 0x04;
	}
	MSB = 0x51;
	LSB = 0x1;
	Patch_Number_select->setMaximum(128);
	break;
      case 4:	// PresetC
	if (state_table->perf_mode) {
	  active_area->active_performance.perf_part[ppn].patch_group = 0x00;
	  active_area->active_performance.perf_part[ppn].patch_group_id = 0x05;
	} else {
	  system_area->sys_common.patch_group = 0x00;
	  system_area->sys_common.patch_group_id = 0x05;
	}
	MSB = 0x51;
	LSB = 0x2;
	Patch_Number_select->setMaximum(128);
	break;
      case 5:	// PresetD
	if (state_table->perf_mode) {
	  active_area->active_performance.perf_part[ppn].patch_group = 0x00;
	  active_area->active_performance.perf_part[ppn].patch_group_id = 0x06;
	} else {
	  system_area->sys_common.patch_group = 0x00;
	  system_area->sys_common.patch_group_id = 0x06;
	}
	MSB = 0x51;
	LSB = 0x3;
	Patch_Number_select->setMaximum(128);
	break;
      case 6:	// Exp B
	if (state_table->perf_mode) {
	  active_area->active_performance.perf_part[ppn].patch_group = 0x02;
	  active_area->active_performance.perf_part[ppn].patch_group_id = 0x10;
	} else {
	  system_area->sys_common.patch_group = 0x02;
	  system_area->sys_common.patch_group_id = 0x10;
	}
	MSB = 0x54;
	LSB = Hnum?3:2;
	Patch_Number_select->setMaximum(255);
	break;
      case 7:	// Exp C
	if (state_table->perf_mode) {
	  active_area->active_performance.perf_part[ppn].patch_group = 0x02;
	  active_area->active_performance.perf_part[ppn].patch_group_id = 0x62;
	} else {
	  system_area->sys_common.patch_group = 0x02;
	  system_area->sys_common.patch_group_id = 0x62;
	}
	MSB = 0x54;
	LSB = Hnum?5:4;
	Patch_Number_select->setMaximum(255);
	break;
      default:
	if (state_table->perf_mode) {
	  active_area->active_performance.perf_part[ppn].patch_group = 0x00;
	  active_area->active_performance.perf_part[ppn].patch_group_id = 0x00;
	} else {
	  system_area->sys_common.patch_group = 0x00;
	  system_area->sys_common.patch_group_id = 0x00;
	}
	MSB = 0;
	LSB = 0;
	Patch_Number_select->setMaximum(128);
	break;
    } // end Switch
    if (state_table->jv_connect) {
    // update JV
    unsigned char buf[8];
    buf[0] = 0xB0 + (state_table->perf_mode ? 
      active_area->active_performance.perf_part[ppn].MIDI_channel
      : system_area->sys_common.patch_receive_channel);
    buf[1] = 0x0;
    buf[2] = MSB;
    buf[3] = 0xB0 + (state_table->perf_mode ? 
      active_area->active_performance.perf_part[ppn].MIDI_channel
      : system_area->sys_common.patch_receive_channel);
    buf[4] = 0x20;
    buf[5] = LSB;
    buf[6] = 0xC0 + (state_table->perf_mode ? 
      active_area->active_performance.perf_part[ppn].MIDI_channel
      : system_area->sys_common.patch_receive_channel);
    buf[7] = pn;
    if (open_ports() == EXIT_FAILURE) return;
    if (change_send(buf,8) == EXIT_FAILURE) { puts("Send failed"); close_ports(); return; }
    close_ports();
    }
    EnablePatch(false);
    if (state_table->patch_mode) {
      getSysPatchName();
      PatchEFX_Group_display->setText(Patch_Group_select->currentText());
      SysPatchSelect->setCurrentIndex(Patch_Group_select->currentIndex());
      SysPatchNumber->setValue(Patch_Number_select->value());
    } else {
      Patch_Name_edit->setText(getPartPatchName(ppn));
    }
    PatchEFX_Number_display->setText(QString::number(Patch_Number_select->value()));	// in case it changed due to a different Maximum
    PatchEFX_Name_display->setText(Patch_Name_edit->text());
  }	// end state_table->updates_enabled
}	// end on_Patch_Group_select_currentIndexChanged

void JVlibForm::on_Patch_Number_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
    int pn = val-1;
    int ppn = Patch_PerfPartNum_select->currentIndex();
    int Hpn = pn/16;
    int Lpn = pn%16;
    unsigned char buf[2];
    if (state_table->perf_mode) {
      active_area->active_performance.perf_part[ppn].patch_num_high = Hpn;
      active_area->active_performance.perf_part[ppn].patch_num_low = Lpn;
    } else {
      system_area->sys_common.patch_num_high = Hpn;
      system_area->sys_common.patch_num_low = Lpn;
    }	// end IF...ELSE
    if (state_table->jv_connect) {
    // update JV
    buf[0] = 0xC0 + (state_table->perf_mode ? 
      active_area->active_performance.perf_part[ppn].MIDI_channel
      : system_area->sys_common.patch_receive_channel);
    buf[1] = pn;
    if (open_ports() == EXIT_FAILURE) return;
    if (change_send(buf,2) == EXIT_FAILURE) { close_ports(); return; }
    close_ports();
    }
    EnablePatch(false);
  if (state_table->patch_mode) {
    SysPatchNumber->setValue(Patch_Number_select->value());
    getSysPatchName();
  } else {
    Patch_Name_edit->setText(getPartPatchName(ppn));
  }
  PatchEFX_Number_display->setText(QString::number(Patch_Number_select->value()));
  PatchEFX_Name_display->setText(Patch_Name_edit->text());
  }	// end state_table->updates_enabled
}	// end on_Patch_Number_select_valueChanged

void JVlibForm::on_Patch_TestTone_switch_toggled(bool val) {
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
  Patch_TestTone_switch->setText(val ? QString::fromUtf8("Stop") : QString::fromUtf8("Play Patch") );
  }
}
