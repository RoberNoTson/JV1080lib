// rhythm.cpp
/* Contains:
 * RhythmStdUpdate
 * getActiveRhythm
 * RhythmName_query
 * Rhythm_EnableAll
 */

#include	"JVlibForm.h"
#include	<QtGui>

void JVlibForm::RhythmStdUpdate(int offset, int val) {
//  if (!state_table->perf_mode) return;
  if (!state_table->updates_enabled) return;
  int tn = Rhythm_KeyPress_select->value();
  char *ptr;
  ptr = (char *)&active_area->active_rhythm.rhythm_note[tn-35].tone;
  ptr[offset] = val;
  if (!state_table->jv_connect) return;
  unsigned char buf[5];
  buf[0] = 0x02;
  buf[1] = 0x09;
  buf[2] = tn;
  buf[3] = offset;
  buf[4] = val;
  if (sysex_update(&buf[0],5) == EXIT_FAILURE) {
    return;
  }
}	// end RhythmStdUpdate

bool JVlibForm::getActiveRhythm() {
  // called when Rhythm Sync button is clicked.
  int   err;
  int   Stop=0;
  unsigned char  buf[8];
  char       active_rhythm_common[]={ 0x2,0x9,0x0,0x0 };
  char    rhythm_common_size[] = { 0x0,0x0,0x0,0x0C };
  char    rhythm_note_size[] = { 0x0,0x0,0x0,0x3A };
  char	perf_part_size[] = { 0x0,0x0,0x0,0x13 };

  // get active_area rhythm set, common and 64 notes; plus the Part_10 PerfPart settings
  memset(buf,0,sizeof(buf));
  memcpy(buf,active_rhythm_common,4);
  memcpy(buf+4,rhythm_common_size,4);
  if (open_ports() == EXIT_FAILURE) return false;
  puts("Getting Rhythm Common");
  QProgressDialog progress("Getting Rhythm data...", "Abort Download", 0, 65, 0);
  progress.setWindowModality(Qt::WindowModal);
  progress.setMinimumDuration(0);
  progress.setValue(0);
  RetryG:
  if (sysex_request(buf) == EXIT_FAILURE) { close_ports(); progress.reset(); return false; }
  err = sysex_get((unsigned char *)&active_area->active_rhythm.rhythm_common.name[0], (char *)rhythm_common_size);
  if (err == EXIT_FAILURE) { close_ports(); progress.reset(); return false; }
  if (err==2 && Stop<MAX_RETRIES) {  Stop++; usleep(20000*Stop); goto RetryG; }
  if (err==3 && Stop<MAX_RETRIES) {  Stop++; usleep(20000*Stop); goto RetryG; }
  if (err != EXIT_SUCCESS) { close_ports(); progress.reset(); return false; }
  Stop=0;
  // get 64 notes for active_area rhythm
  memcpy(buf+4,rhythm_note_size,4);
  for (int y=0;y<64;y++) {		// get 4 tones
    printf("Rhythm note #%d\n",y);
    progress.setValue(y+1);
    if (progress.wasCanceled()) break;
    buf[2] = 0x23+y;	// tone address
    RetryH:
    if (sysex_request(buf) == EXIT_FAILURE) { close_ports(); progress.reset(); return false; }
    err = sysex_get((unsigned char *)&active_area->active_rhythm.rhythm_note[y].tone, (char *)rhythm_note_size);
    if (err == EXIT_FAILURE) { close_ports(); progress.reset(); return false; }
    if (err==2 && Stop<MAX_RETRIES) { Stop++; usleep(20000*Stop); goto RetryH; }
    if (err==3 && Stop<MAX_RETRIES) { Stop++; usleep(20000*Stop); goto RetryH; }
    if (err != EXIT_SUCCESS) { close_ports(); progress.reset(); return false; }
    Stop=0;
  }	// end FOR 64 notes
  memset(buf,0,sizeof(buf));
  buf[0] = 1;
  buf[2] = 0x19;
  buf[7] = 0x13;
  RetryA:
  if (sysex_request(buf) == EXIT_FAILURE) { close_ports(); progress.reset(); return false; }
  err = sysex_get((unsigned char *)&active_area->active_performance.perf_part[9].MIDI_receive, (char *)perf_part_size);
  if (err == EXIT_FAILURE) { close_ports(); progress.reset(); return false; }
  if (err==2 && Stop<MAX_RETRIES) { Stop++; usleep(20000*Stop); goto RetryA; }
  if (err==3 && Stop<MAX_RETRIES) { Stop++; usleep(20000*Stop); goto RetryA; }
  if (err != EXIT_SUCCESS) { close_ports(); progress.reset(); return false; }
  close_ports();
  progress.setValue(65);
  progress.reset();
  return true;
}	// end getActiveRhythm

QString JVlibForm::RhythmName_query() {
  if (state_table->db_connect) {
   QString buf = "";
   QSqlQuery WaveQuery(mysql);
   WaveQuery.prepare("Select name from wave_list where group_area = ? and number = ?");
   switch(Rhythm_WaveGroup_select->currentIndex()) {
     case 0:
       WaveQuery.bindValue(0, "Internal A");
       break;
     case 1:
       WaveQuery.bindValue(0, "Internal B");
       break;
     case 2:
       WaveQuery.bindValue(0, "Expansion A");
       break;
     case 3:
       WaveQuery.bindValue(0, "Expansion B");
       break;
     case 4:
       WaveQuery.bindValue(0, "Expansion C");
       break;
     default:
       WaveQuery.bindValue(0, "Internal A");
       break;       
   }
   WaveQuery.bindValue(1, Rhythm_WaveNumber_select->value());
   if (WaveQuery.exec() == false) {
     puts("Query exec failed");
     return buf;
   }
   if (WaveQuery.size()==0) {
         puts("0 rows found in WaveName_query"); 
         return buf;
   }
   WaveQuery.first();
   buf = WaveQuery.value(0).toString();
   buf = buf.leftJustified(12, ' ');
   WaveQuery.finish();
   return buf;
  }	// end db_connect
  return QString("n/a");
}	// end RhythmName_query

void JVlibForm::Rhythm_EnableAll(bool val) {
  if (!val) Rhythm_Sync_status->off();
  Rhythm_Note_enable->setEnabled(val);
  Rhythm_Hold_enable->setEnabled(val);
  Rhythm_Volume_enable->setEnabled(val);
  Rhythm_WaveGroup_select->setEnabled(val);
  Rhythm_WaveNumber_select->setEnabled(val);
  Rhythm_WaveGain_select->setEnabled(val);
  Rhythm_Output_select->setEnabled(val);
  Rhythm_EnvMode_select->setEnabled(val);
  Rhythm_MuteGroup_select->setEnabled(val);
  Rhythm_OutputLevel_select->setEnabled(val);
  Rhythm_ChorusSend_select->setEnabled(val);
  Rhythm_ReverbSend_select->setEnabled(val);
  Rhythm_PanControl_select->setEnabled(val);
  Rhythm_Pan_select->setEnabled(val);
  Rhythm_AltPan_select->setEnabled(val);
  Rhythm_PanRandDepth_select->setEnabled(val);
  Rhythm_PitchTime1_select->setEnabled(val);
  Rhythm_PitchTime2_select->setEnabled(val);
  Rhythm_PitchTime3_select->setEnabled(val);
  Rhythm_PitchTime4_select->setEnabled(val);
  Rhythm_PitchLvl1_select->setEnabled(val);
  Rhythm_PitchLvl2_select->setEnabled(val);
  Rhythm_PitchLvl3_select->setEnabled(val);
  Rhythm_PitchLvl4_select->setEnabled(val);
  Rhythm_PitchVelocSens_select->setEnabled(val);
  Rhythm_PitchVeloTime_select->setEnabled(val);
  Rhythm_PitchDepth_select->setEnabled(val);
  Rhythm_RandPitchDepth_select->setEnabled(val);
  Rhythm_TuneAdj_select->setEnabled(val);
  Rhythm_BenderRange_select->setEnabled(val);
  Rhythm_TVATime1_select->setEnabled(val);
  Rhythm_TVATime2_select->setEnabled(val);
  Rhythm_TVATime3_select->setEnabled(val);
  Rhythm_TVATime4_select->setEnabled(val);
  Rhythm_TVALvl1_select->setEnabled(val);
  Rhythm_TVALvl2_select->setEnabled(val);
  Rhythm_TVALvl3_select->setEnabled(val);
  Rhythm_TVAVelocSens_select->setEnabled(val);
  Rhythm_TVAVelTimeSens_select->setEnabled(val);
  Rhythm_TVFDepth_select->setEnabled(val);
  Rhythm_TVFFilterType_select->setEnabled(val);
  Rhythm_TVFVelTimeSens_select->setEnabled(val);
  Rhythm_TVFTime1_select->setEnabled(val);
  Rhythm_TVFTime2_select->setEnabled(val);
  Rhythm_TVFTime3_select->setEnabled(val);
  Rhythm_TVFTime4_select->setEnabled(val);
  Rhythm_TVFLvl2_select->setEnabled(val);
  Rhythm_TVFLvl3_select->setEnabled(val);
  Rhythm_TVFLvl4_select->setEnabled(val);
  Rhythm_TVFLvl1_select->setEnabled(val);
  Rhythm_TVFResVelocSens_select->setEnabled(val);
  Rhythm_TVFCutoffFreq_select->setEnabled(val);
  Rhythm_TVFResonance_select->setEnabled(val);
  Rhythm_TVFVelocSens_select->setEnabled(val);
  Rhythm_SoundingPitch_select->setEnabled(val);
  Rhythm_KeyPress_select->setEnabled(val);
  Rhythm_ToneLevel_select->setEnabled(val);
  Rhythm_ListNotes_button->setEnabled(val);
  Rhythm_TestTone_switch->setEnabled(val && active_area->active_performance.perf_part[9].MIDI_receive);
}	// end Rhythm_EnableAll

