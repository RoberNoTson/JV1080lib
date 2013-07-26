// rhythm_slots.cpp
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::RhythmStdUpdate(int offset, int val) {
  if (!state_table->perf_mode) return;
  if (state_table->updates_enabled) {
    int tn = Rhythm_KeyPress_select->value();
    bool *ptr = &active_area->active_rhythm.rhythm_note[tn].tone;
    ptr[offset] = val;
    if (state_table->jv_connect) {
      unsigned char buf[12];
      memset(buf,0,sizeof(buf));
      buf[4] = JV_UPD;
      buf[5] = 0x02;
      buf[6] = 0x09;
      buf[7] = tn;
      buf[8] = offset;
      buf[9] = val;
      buf[10] = chksum(buf+5, 5);
      buf[11] = 0xF7;
      if (open_ports() == EXIT_FAILURE) return;
      if (sysex_send(buf,12) == EXIT_FAILURE) {
	close_ports(); 
	return;
      }
      close_ports();
    }	// end state_table->jv_connect
  }	// end udpates_enabled
}	// end RhythmStdUpdate

// QPushButton
void JVlibForm::on_Rhythm_Sync_button_clicked() {
  if (getActiveRhythm()) {
    setRhythmParms(60);
    Rhythm_Sync_status->on();
    Rhythm_EnableAll(true);
  }
}
void JVlibForm::on_Rhythm_KeyPress_select_valueChanged(int val) {
  Rhythm_KeyPress_display->setText(funcNoteCalc(val));
  setRhythmParms(val);
}
void JVlibForm::on_Rhythm_Note_enable_toggled(bool val) {
  RhythmStdUpdate(0x00,val);  
}

void JVlibForm::on_Rhythm_WaveGroup_select_currentIndexChanged(int val) {
  if (state_table->updates_enabled) {
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
      unsigned char buf[13];
      memset(buf,0,sizeof(buf));
      buf[4] = JV_UPD;
      buf[5] = 0x02;
      buf[6] = 0x09;
      buf[7] = Rhythm_KeyPress_select->value();
      buf[8] = 0x01;
      buf[9] = active_area->active_rhythm.rhythm_note[tn].wave_group;
      buf[10] = active_area->active_rhythm.rhythm_note[tn].wave_group_id;
      buf[11] = chksum(buf+5, 6);
      buf[12] = 0xF7;
      if (open_ports() == EXIT_FAILURE) return;
      if (sysex_send(buf,13) == EXIT_FAILURE) {
        close_ports(); 
        return;
      }
      close_ports();
    }	// end jv_connect
    Rhythm_WaveName_display->setText(RhythmName_query());
    state_table->rhythm_modified = true;
  }	// end if state_table->updates_enabled
}	// end on_Rhythm_WaveGroup_select_currentIndexChanged

void JVlibForm::on_Rhythm_WaveNumber_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
    int tn = Rhythm_KeyPress_select->value() - 35;
    int Hval = (val-1)/16;
    int Lval = (val-1)%16;
    active_area->active_rhythm.rhythm_note[tn].wave_num_high = Hval;
    active_area->active_rhythm.rhythm_note[tn].wave_num_low = Lval;
    if (state_table->jv_connect) {
    // update the synth
      unsigned char buf[13];
      memset(buf,0,sizeof(buf));
      buf[4] = JV_UPD;
      buf[5] = 0x02;
      buf[6] = 0x09;
      buf[7] = Rhythm_KeyPress_select->value();
      buf[8] = 0x03;
      buf[9] = Hval;
      buf[10] = Lval;
      buf[11] = chksum(buf+5, 6);
      buf[12] = 0xF7;
      if (open_ports() == EXIT_FAILURE) return;
      if (sysex_send(buf,13) == EXIT_FAILURE) {
        close_ports(); 
        return;
      }
      close_ports();
      state_table->rhythm_modified = true;
    }   // end state_table->jv_connect
  Rhythm_WaveName_display->setText(RhythmName_query());
  }	// end udpates_enabled
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
  RhythmStdUpdate(0x10,val/2 + 25);
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
  RhythmStdUpdate(0x1D,val);
}
void JVlibForm::on_Rhythm_TVFDepth_select_valueChanged(int val) {
  RhythmStdUpdate(0x1E,val+63);
}
void JVlibForm::on_Rhythm_TVFVelocSens_select_valueChanged(int val) {
  RhythmStdUpdate(0x1F,val/2 + 25);
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
  RhythmStdUpdate(0x2A,val/2 + 25);
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
 if (state_table->jv_connect) {
  unsigned char buf[6];
  if ((Rhythm_TestTone_switch->isCheckable()&&val) || (Rhythm_TestTone_switch->isCheckable()==false)) {
    buf[0] = 0x99;
    buf[1] = Rhythm_KeyPress_select->value();
    buf[2] = 127;
    if (open_ports() == EXIT_FAILURE) return;
    if (change_send(buf,3) == EXIT_FAILURE) { close_ports(); return; }
    close_ports();
    if (Rhythm_TestTone_switch->isCheckable())
      Rhythm_TestTone_switch->setText("Stop");
  } 
  if (Rhythm_TestTone_switch->isCheckable() && val==false) {
    buf[0] = 0xB9;
    buf[1] = 0x7B;
    buf[2] = 0;
    if (open_ports() == EXIT_FAILURE) return;
    if (change_send(buf,3) == EXIT_FAILURE) { close_ports(); return; }
    close_ports();
    Rhythm_TestTone_switch->setText("Play Note");
  }
 }	// end state_table->jv_connect
  Rhythm_TestTone_switch->setText(val ? QString::fromUtf8("Stop") : QString::fromUtf8("Play Note") );
}	// end on_Rhythm_TestTone_switch_clicked
