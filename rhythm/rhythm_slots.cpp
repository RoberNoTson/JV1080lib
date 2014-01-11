// rhythm_slots.cpp
/* Contains:
 * on_Rhythm_Sync_button_clicked
 * on_Rhythm_KeyPress_select_valueChanged
 * on_Rhythm_Note_enable_toggled
 * on_Rhythm_WaveGroup_select_currentIndexChanged
 * on_Rhythm_WaveNumber_select_valueChanged
 * on_Rhythm_WaveGain_select_currentIndexChanged
 * on_Rhythm_BenderRange_select_valueChanged
 * on_Rhythm_MuteGroup_select_valueChanged
 * on_Rhythm_EnvMode_select_toggled
 * on_Rhythm_Volume_enable_toggled
 * on_Rhythm_Hold_enable_toggled
 * on_Rhythm_TestTone_switch_clicked
 * on_Rhythm_ListNotes_button_clicked
 * on_Rhythm_PatchGroup_select_currentIndexChanged
 * on_Rhythm_PatchNumber_select_valueChanged
 * on_Rhythm_SoundingPitch_select_valueChanged
 * on_Rhythm_Output_select_currentIndexChanged
 * on_Rhythm_OutputLevel_select_valueChanged
 * on_Rhythm_ChorusSend_select_valueChanged
 * on_Rhythm_ReverbSend_select_valueChanged
 * on_Rhythm_ReceiveMidi_enable_toggled
 * on_Rhythm_PanControl_select_currentIndexChanged
 * on_Rhythm_TuneAdj_select_valueChanged
 * on_Rhythm_RandPitchDepth_select_currentIndexChanged
 * on_Rhythm_PitchDepth_select_valueChanged
 * on_Rhythm_PitchVelocSens_select_valueChanged
 * on_Rhythm_PitchVeloTime_select_currentIndexChanged
 * on_Rhythm_PitchTime1_select_valueChanged
 * on_Rhythm_PitchTime2_select_valueChanged
 * on_Rhythm_PitchTime3_select_valueChanged
 * on_Rhythm_PitchTime4_select_valueChanged
 * on_Rhythm_PitchLvl1_select_valueChanged
 * on_Rhythm_PitchLvl2_select_valueChanged
 * on_Rhythm_PitchLvl3_select_valueChanged
 * on_Rhythm_PitchLvl4_select_valueChanged
 * on_Rhythm_TVFFilterType_select_currentIndexChanged
 * on_Rhythm_TVFCutoffFreq_select_valueChanged
 * on_Rhythm_TVFResonance_select_valueChanged
 * on_Rhythm_TVFResVelocSens_select_valueChanged
 * on_Rhythm_TVFDepth_select_valueChanged
 * on_Rhythm_TVFVelocSens_select_valueChanged
 * on_Rhythm_TVFVelTimeSens_select_currentIndexChanged
 * on_Rhythm_TVFTime1_select_valueChanged
 * on_Rhythm_TVFTime2_select_valueChanged
 * on_Rhythm_TVFTime3_select_valueChanged
 * on_Rhythm_TVFTime4_select_valueChanged
 * on_Rhythm_TVFLvl1_select_valueChanged
 * on_Rhythm_TVFLvl2_select_valueChanged
 * on_Rhythm_TVFLvl3_select_valueChanged
 * on_Rhythm_TVFLvl4_select_valueChanged
 * on_Rhythm_ToneLevel_select_valueChanged
 * on_Rhythm_TVAVelocSens_select_valueChanged
 * on_Rhythm_TVAVelTimeSens_select_currentIndexChanged
 * on_Rhythm_TVATime1_select_valueChanged
 * on_Rhythm_TVATime2_select_valueChanged
 * on_Rhythm_TVATime3_select_valueChanged
 * on_Rhythm_TVATime4_select_valueChanged
 * on_Rhythm_TVALvl1_select_valueChanged
 * on_Rhythm_TVALvl2_select_valueChanged
 * on_Rhythm_TVALvl3_select_valueChanged
 * on_Rhythm_Pan_select_valueChanged
 * on_Rhythm_PanRandDepth_select_valueChanged
 * on_Rhythm_AltPan_select_valueChanged
 */

#include        "JVlibForm.h"
#include        <QtGui>
#include	"note_list.h"

// QPushButton
void JVlibForm::on_Rhythm_Sync_button_clicked() {
  if (getActiveRhythm()) {
    setRhythmParms(69);
    Rhythm_Sync_status->on();
    Rhythm_EnableAll(true);
    if (state_table->patchEFXTab_enable) {
      MainTabWidget->setTabEnabled(5, false);
      state_table->patchEFXTab_enable = false;
    }
    if (state_table->toneTab_enable) {
      MainTabWidget->setTabEnabled(6,false);
      state_table->toneTab_enable = false;
    }	      
    state_table->rhythm_sync = true;
    System_Upload_button->setEnabled(true);
    state_table->rhythm_modified = false;
    state_table->updates_enabled=true;
  }	// end if getActiveRhythm
  else {
    if (state_table->patchEFXTab_enable) {
      MainTabWidget->setTabEnabled(6, false);
      state_table->patchEFXTab_enable = false;
    }
    if (state_table->toneEFXTab_enable) {
      MainTabWidget->setTabEnabled(7,false);
      state_table->toneEFXTab_enable = false;
    }
    if (state_table->toneTVFTab_enable) {
      MainTabWidget->setTabEnabled(8,false);
      state_table->toneTVFTab_enable = false;
    }
    if (state_table->toneTVATab_enable) {
      MainTabWidget->setTabEnabled(9,false);
      state_table->toneTVATab_enable = false;
    }
    if (state_table->pitchTab_enable) {
      MainTabWidget->setTabEnabled(10,false);
      state_table->pitchTab_enable = false;
    }
    if (state_table->rhythm_sync) {
      state_table->rhythm_sync=false;
      System_Upload_button->setEnabled(false);
      Rhythm_EnableAll(false);
    }
    state_table->updates_enabled=false;
  }	// end getActiveRhythm failed
}	// end on_Rhythm_Sync_button_clicked

void JVlibForm::on_Rhythm_KeyPress_select_valueChanged(int val) {
  Rhythm_KeyPress_display->setText(funcNoteCalc(val));
  setRhythmParms(val);
}
void JVlibForm::on_Rhythm_Note_enable_toggled(bool val) {
  RhythmStdUpdate(0x00,val);  
}

void JVlibForm::on_Rhythm_WaveGroup_select_currentIndexChanged(int val) {
  if (!state_table->updates_enabled) return;
    int tn = Rhythm_KeyPress_select->value() - 35;
    active_area->active_rhythm.rhythm_note[tn].wave_group = (val<2?0:2);
    switch(val) {
        case 0:
          active_area->active_rhythm.rhythm_note[tn].wave_group_id = 0x01;
          break;
	case 1: case 2:
          active_area->active_rhythm.rhythm_note[tn].wave_group_id = 0x02;
          break;
        case 3:
          active_area->active_rhythm.rhythm_note[tn].wave_group_id = 0x10;
          break;
        case 4:
          active_area->active_rhythm.rhythm_note[tn].wave_group_id = 0x62;
          break;
	default:
          active_area->active_rhythm.rhythm_note[tn].wave_group_id = 0x00;
          break;
    }	// end switch
    if (state_table->jv_connect) {
      // update the synth
      unsigned char buf[6];
      buf[0] = 0x02;
      buf[1] = 0x09;
      buf[2] = Rhythm_KeyPress_select->value();
      buf[3] = 0x01;
      buf[4] = active_area->active_rhythm.rhythm_note[tn].wave_group;
      buf[5] = active_area->active_rhythm.rhythm_note[tn].wave_group_id;
      if (sysex_update(&buf[0],6) == EXIT_FAILURE) {
        return;
      }
    }	// end jv_connect
    Rhythm_WaveName_display->setText(RhythmName_query());
    state_table->rhythm_modified = true;
}	// end on_Rhythm_WaveGroup_select_currentIndexChanged

void JVlibForm::on_Rhythm_WaveNumber_select_valueChanged(int val) {
  if (!state_table->updates_enabled) return;
    int tn = Rhythm_KeyPress_select->value() - 35;
    int Hval = (val-1)/16;
    int Lval = (val-1)%16;
    active_area->active_rhythm.rhythm_note[tn].wave_num_high = Hval;
    active_area->active_rhythm.rhythm_note[tn].wave_num_low = Lval;
    if (state_table->jv_connect) {
    // update the synth
      unsigned char buf[6];
      buf[0] = 0x02;
      buf[1] = 0x09;
      buf[2] = Rhythm_KeyPress_select->value();
      buf[3] = 0x03;
      buf[4] = Hval;
      buf[5] = Lval;
      if (sysex_update(&buf[0],6) == EXIT_FAILURE) {
        return;
      }
      state_table->rhythm_modified = true;
    }   // end state_table->jv_connect
  Rhythm_WaveName_display->setText(RhythmName_query());
}	// end on_Rhythm_WaveNumber_select_valueChanged

void JVlibForm::on_Rhythm_WaveGain_select_currentIndexChanged(int val) {
  RhythmStdUpdate(0x05,val);
}
void JVlibForm::on_Rhythm_BenderRange_select_valueChanged(int val) {
  RhythmStdUpdate(0x06,val);
}
void JVlibForm::on_Rhythm_MuteGroup_select_valueChanged(int val) {
  RhythmStdUpdate(0x07,val);
}
void JVlibForm::on_Rhythm_EnvMode_select_toggled(bool val) {
  if (val) Rhythm_EnvMode_select->setText("Sustain");
  else Rhythm_EnvMode_select->setText("No Sustain");
  Rhythm_TestTone_switch->setCheckable(val);
  RhythmStdUpdate(0x08,val);
}
void JVlibForm::on_Rhythm_Volume_enable_toggled(bool val) {
  RhythmStdUpdate(0x09,val);
}
void JVlibForm::on_Rhythm_Hold_enable_toggled(bool val) {
  RhythmStdUpdate(0x0A,val);
}
void JVlibForm::on_Rhythm_PanControl_select_currentIndexChanged(int val) {
  RhythmStdUpdate(0x0B,val);
}
void JVlibForm::on_Rhythm_SoundingPitch_select_valueChanged(int val) {
  Rhythm_SoundingPitch_display->setText(funcNoteCalc(val));
  RhythmStdUpdate(0x0C,val);
}
void JVlibForm::on_Rhythm_TuneAdj_select_valueChanged(int val) {
  RhythmStdUpdate(0x0D,val+50);
}
void JVlibForm::on_Rhythm_RandPitchDepth_select_currentIndexChanged(int val) {
  RhythmStdUpdate(0x0E,val);
}
void JVlibForm::on_Rhythm_PitchDepth_select_valueChanged(int val) {
  RhythmStdUpdate(0x0F,val+12);
}
void JVlibForm::on_Rhythm_PitchVelocSens_select_valueChanged(int val) {
  RhythmStdUpdate(0x10,val/2 + 50);
}
void JVlibForm::on_Rhythm_PitchVeloTime_select_currentIndexChanged(int val) {
  RhythmStdUpdate(0x11,val);
}
void JVlibForm::on_Rhythm_PitchTime1_select_valueChanged(int val) {
  RhythmStdUpdate(0x12,val);
}
void JVlibForm::on_Rhythm_PitchTime2_select_valueChanged(int val) {
  RhythmStdUpdate(0x13,val);
}
void JVlibForm::on_Rhythm_PitchTime3_select_valueChanged(int val) {
  RhythmStdUpdate(0x14,val);
}
void JVlibForm::on_Rhythm_PitchTime4_select_valueChanged(int val) {
  RhythmStdUpdate(0x15,val);
}
void JVlibForm::on_Rhythm_PitchLvl1_select_valueChanged(int val) {
  RhythmStdUpdate(0x16,val+63);
}
void JVlibForm::on_Rhythm_PitchLvl2_select_valueChanged(int val) {
  RhythmStdUpdate(0x17,val+63);
}
void JVlibForm::on_Rhythm_PitchLvl3_select_valueChanged(int val) {
  RhythmStdUpdate(0x18,val+63);
}
void JVlibForm::on_Rhythm_PitchLvl4_select_valueChanged(int val) {
  RhythmStdUpdate(0x19,val+63);
}
void JVlibForm::on_Rhythm_TVFFilterType_select_currentIndexChanged(int val) {
  RhythmStdUpdate(0x1A,val);
}
void JVlibForm::on_Rhythm_TVFCutoffFreq_select_valueChanged(int val) {
  RhythmStdUpdate(0x1B,val);
}
void JVlibForm::on_Rhythm_TVFResonance_select_valueChanged(int val) {
  RhythmStdUpdate(0x1C,val);
}
void JVlibForm::on_Rhythm_TVFResVelocSens_select_valueChanged(int val) {
  RhythmStdUpdate(0x1D,val/2 + 50);
}
void JVlibForm::on_Rhythm_TVFDepth_select_valueChanged(int val) {
  RhythmStdUpdate(0x1E,val+63);
}
void JVlibForm::on_Rhythm_TVFVelocSens_select_valueChanged(int val) {
  RhythmStdUpdate(0x1F,val/2 + 50);
}
void JVlibForm::on_Rhythm_TVFVelTimeSens_select_currentIndexChanged(int val) {
  RhythmStdUpdate(0x20,val);
}
void JVlibForm::on_Rhythm_TVFTime1_select_valueChanged(int val) {
  RhythmStdUpdate(0x21,val);
}
void JVlibForm::on_Rhythm_TVFTime2_select_valueChanged(int val) {
  RhythmStdUpdate(0x22,val);
}
void JVlibForm::on_Rhythm_TVFTime3_select_valueChanged(int val) {
  RhythmStdUpdate(0x23,val);
}
void JVlibForm::on_Rhythm_TVFTime4_select_valueChanged(int val) {
  RhythmStdUpdate(0x24,val);
}
void JVlibForm::on_Rhythm_TVFLvl1_select_valueChanged(int val) {
  RhythmStdUpdate(0x25,val);
}
void JVlibForm::on_Rhythm_TVFLvl2_select_valueChanged(int val) {
  RhythmStdUpdate(0x26,val);
}
void JVlibForm::on_Rhythm_TVFLvl3_select_valueChanged(int val) {
  RhythmStdUpdate(0x27,val);
}
void JVlibForm::on_Rhythm_TVFLvl4_select_valueChanged(int val) {
  RhythmStdUpdate(0x28,val);
}
void JVlibForm::on_Rhythm_ToneLevel_select_valueChanged(int val) {
  RhythmStdUpdate(0x29,val);
}
void JVlibForm::on_Rhythm_TVAVelocSens_select_valueChanged(int val) {
  RhythmStdUpdate(0x2A,val/2 + 50);
}
void JVlibForm::on_Rhythm_TVAVelTimeSens_select_currentIndexChanged(int val) {
  RhythmStdUpdate(0x2B,val);
}
void JVlibForm::on_Rhythm_TVATime1_select_valueChanged(int val) {
  RhythmStdUpdate(0x2C,val);
}
void JVlibForm::on_Rhythm_TVATime2_select_valueChanged(int val) {
  RhythmStdUpdate(0x2D,val);
}
void JVlibForm::on_Rhythm_TVATime3_select_valueChanged(int val) {
  RhythmStdUpdate(0x2E,val);
}
void JVlibForm::on_Rhythm_TVATime4_select_valueChanged(int val) {
  RhythmStdUpdate(0x2F,val);
}
void JVlibForm::on_Rhythm_TVALvl1_select_valueChanged(int val) {
  RhythmStdUpdate(0x30,val);
}
void JVlibForm::on_Rhythm_TVALvl2_select_valueChanged(int val) {
  RhythmStdUpdate(0x31,val);
}
void JVlibForm::on_Rhythm_TVALvl3_select_valueChanged(int val) {
  RhythmStdUpdate(0x32,val);
}
void JVlibForm::on_Rhythm_Pan_select_valueChanged(int val) {
  RhythmStdUpdate(0x33,val+64);
  Rhythm_Pan_display->setText(Pan2Deg(val));
}
void JVlibForm::on_Rhythm_PanRandDepth_select_valueChanged(int val) {
  RhythmStdUpdate(0x34,val);
}
void JVlibForm::on_Rhythm_AltPan_select_valueChanged(int val) {
  RhythmStdUpdate(0x35,val+63);
  Rhythm_AltPan_display->setText(Pan2Deg(val));
}
void JVlibForm::on_Rhythm_Output_select_currentIndexChanged(int val) {
  RhythmStdUpdate(0x36,val);
}
void JVlibForm::on_Rhythm_OutputLevel_select_valueChanged(int val) {
  RhythmStdUpdate(0x37,val);
}
void JVlibForm::on_Rhythm_ChorusSend_select_valueChanged(int val) {
  RhythmStdUpdate(0x38,val);
}
void JVlibForm::on_Rhythm_ReverbSend_select_valueChanged(int val) {
  RhythmStdUpdate(0x39,val);
}

void JVlibForm::on_Rhythm_TestTone_switch_clicked(bool val) {
  if (!state_table->jv_connect) return;
  if ((Rhythm_TestTone_switch->isCheckable()&&val) || (Rhythm_TestTone_switch->isCheckable()==false)) {
    change_3(0x99, Rhythm_KeyPress_select->value(), 127);
    if (Rhythm_TestTone_switch->isCheckable())
      Rhythm_TestTone_switch->setText("Stop");
  } 
  if (Rhythm_TestTone_switch->isCheckable() && val==false) {
    change_3(0xB9, 0x7B, 0x0);
    Rhythm_TestTone_switch->setText("Play Note");
  }
  Rhythm_TestTone_switch->setText(val ? QString::fromUtf8("Stop") : QString::fromUtf8("Play Note") );
}	// end on_Rhythm_TestTone_switch_clicked

void JVlibForm::on_Rhythm_ListNotes_button_clicked() {
  // rhythmNote_list
//  NOTE_LIST Note_List;
  Note_List.show();
  Note_List.raise();
  Note_List.activateWindow();
/*  
  QString Group;
  int Num;
  QString WaveName;
  QSqlQuery NameQuery(mysql);
  
  NameQuery.prepare("Select name from wave_list where group_area = ? and number = ?");
  for (int x=0;x<64;x++) {
    Group.clear();
    switch(active_area->active_rhythm.rhythm_note[x].wave_group_id) {
      case 0x1:	// Int A
	Group = "Internal A";
	break;
      case 0x2:	// Int B or Exp A
	Group = active_area->active_rhythm.rhythm_note[x].wave_group==0 ? "Internal B" : "Expansion A";
	break;
      case 0x10:	// Exp B
	Group = "Expansion B";
	break;
      case 0x62:	// Exp C
	Group = "Expansion C";
	break;      
    }	// end switch Group
    Num = active_area->active_rhythm.rhythm_note[x].wave_num_high*16;
    Num += active_area->active_rhythm.rhythm_note[x].wave_num_low;
    Num++;
    NameQuery.bindValue(0, Group);
    NameQuery.bindValue(1, Num);
    if (NameQuery.exec() == false) { puts("Query exec failed"); return; }
    if (NameQuery.size()==0) { printf("0 rows found in WaveName_query for %s %d\n",Group.toAscii().data(), Num); continue; }
    NameQuery.first();
    WaveName = NameQuery.value(0).toString();
    WaveName = WaveName.leftJustified(12, ' ');
    // output the results
    Group.prepend(funcNoteCalc(x+35)+"   ");
    Group.append(" "+QString::number(Num));
    Group.append("    "+WaveName);
printf("%s\n",Group.toAscii().data());   
  }	// end FOR
  NameQuery.finish();
*/
}	// end on_Rhythm_ListNotes_button_clicked

void JVlibForm::on_Rhythm_PatchGroup_select_currentIndexChanged(int val) {
  if (state_table->rhythm_sync) {
    state_table->rhythm_sync=false;
    Rhythm_EnableAll(false);
    System_Upload_button->setEnabled(false);
  }
  if (state_table->perf_mode) {
    Part10_PatchGroup_select->setCurrentIndex(val);
    return;
  }
  if (!state_table->rhythm_mode) return;
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
  active_area->active_performance.perf_part[9].patch_num_high = 0;
  active_area->active_performance.perf_part[9].patch_num_low = Rhythm_PatchNumber_select->value() - 1;
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
  Rhythm_PatchName_display->setText(getPartPatchName(9));
}

void JVlibForm::on_Rhythm_PatchNumber_select_valueChanged(int val) {
  if (state_table->rhythm_sync) {
    state_table->rhythm_sync=false;
    Rhythm_EnableAll(false);
    System_Upload_button->setEnabled(false);
  }
  if (state_table->perf_mode) {
    Part10_PatchNumber_select->setValue(val);
    return;
  }
  if (!state_table->rhythm_mode) return;
  active_area->active_performance.perf_part[9].patch_num_high = 0;
  active_area->active_performance.perf_part[9].patch_num_low = val - 1;
  on_Rhythm_PatchGroup_select_currentIndexChanged(Rhythm_PatchGroup_select->currentIndex());
}

void JVlibForm::on_Rhythm_ReceiveMidi_enable_toggled(bool val) {
  Part10_ReceiveMidi_enable->setChecked(val);
}
