// save_user_rhythm.cpp
#include	"save_dialog/Save_Dialog.h"
#include	"ui_Save_Dialog.h"
#include        "JVlibForm.h"
#include        <QtGui>
#include	<QtSql>

int Save_Dialog::SaveUserRhythm(int pn, int Part) {
  // called from Save_Dialog
  int   err;
  int   Stop=0;
  unsigned char  buf[8];
  char    user1_rhythm_common[]={ 0x10,0x40,0x0,0x0 };
  char    rhythm_common_size[] = { 0x0,0x0,0x0,0x0C };
  char    rhythm_note_size[] = { 0x0,0x0,0x0,0x3A };
  struct RHYTHM temp_r;
  
  // get a User rhythm set, common and 64 notes
  memset(buf,0,sizeof(buf));
  memcpy(buf,user1_rhythm_common,4);
  if (pn==2)
    buf[1] = 0x41;
  memcpy(buf+4,rhythm_common_size,4);
  if (ui->Save_All_button->isChecked()) {
    buf[1] = 0x40;
    buf[6] = 0x01;		 //0x0c*2 +0x3A*2 = 0x8C = 0x01 0x0C
    buf[7] = 0x0C;
  }
//  if (JVlibForm::open_ports() == EXIT_FAILURE) { puts("unable to open seq port"); return false; }
  QProgressDialog progress("Getting Rhythm data...", "Abort Download", 0, 65, 0);
  progress.setWindowModality(Qt::WindowModal);
  progress.setMinimumDuration(0);
  progress.setValue(0);
  RetryG:
  if (JVlibForm::sysex_request(buf) == EXIT_FAILURE) { if (JVlibForm::state_table->midiPorts_open) JVlibForm::close_ports(); return false; }
  err = JVlibForm::sysex_get((unsigned char *)&temp_r.rhythm_common.name[0], (char *)rhythm_common_size);
  if (err == EXIT_FAILURE) { if (JVlibForm::state_table->midiPorts_open) JVlibForm::close_ports(); return false; }
  if (err==2 && Stop<MAX_RETRIES) {  Stop++; usleep(20000*Stop); goto RetryG; }
  if (err==3 && Stop<MAX_RETRIES) {  Stop++; usleep(20000*Stop); goto RetryG; }
  if (err != EXIT_SUCCESS) { if (JVlibForm::state_table->midiPorts_open) JVlibForm::close_ports(); return false; }
  Stop=0;
  // get 64 notes for this rhythm
  memcpy(buf+4,rhythm_note_size,4);
  for (int y=0;y<64;y++) {		// get 64 notes
    printf("Rhythm note #%d\n",y);
    progress.setValue(y+1);
    if (progress.wasCanceled()) break;
    buf[2] = 0x23+y;	// note address
    RetryH:
    if (JVlibForm::sysex_request(buf) == EXIT_FAILURE) { if (JVlibForm::state_table->midiPorts_open) JVlibForm::close_ports(); return false; }
    err = JVlibForm::sysex_get((unsigned char *)&temp_r.rhythm_note[y].tone, (char *)rhythm_note_size);
    if (err == EXIT_FAILURE) { if (JVlibForm::state_table->midiPorts_open) JVlibForm::close_ports(); return false; }
    if (err==2 && Stop<MAX_RETRIES) { Stop++; usleep(20000*Stop); goto RetryH; }
    if (err==3 && Stop<MAX_RETRIES) { Stop++; usleep(20000*Stop); goto RetryH; }
    if (err != EXIT_SUCCESS) { if (JVlibForm::state_table->midiPorts_open) JVlibForm::close_ports(); return false; }
    Stop=0;
  }	// end FOR 64 notes
  if (JVlibForm::state_table->midiPorts_open) JVlibForm::close_ports();
  progress.setValue(65);
  progress.reset();
  int sz = 0x0C + (0x3A*64);	// common and 64 notes
  return(db_insert_data("RhythmSets", (char *)&temp_r, sz, Part));
//  return true;
}	// end SaveUserRhythm
