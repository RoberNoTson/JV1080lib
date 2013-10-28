// tuning.cpp
/* Contains:
 * setScaleSingleValue
 * get_scales
 * Tuning_BulkUpdate
 * TuningStdUpdate
 * Tuning_QueryTemp
 * Tuning_setScaleTuning
 */

#include	"JVlibForm.h"
#include	<QtGui>

void JVlibForm::setScaleSingleValue(int addr, int val) {
  unsigned char buf[5];
  if (state_table->jv_connect && state_table->updates_enabled) {
  memset(buf,0,sizeof(buf));
  if (state_table->patch_mode)
    buf[2] = 0x20;
  else
    buf[2] = 0x10 + Tuning_PartTune_select->value() - 1;
  buf[3] = addr;
  buf[4] = val;
  if (open_ports() == EXIT_FAILURE) return;
  if (sysex_update(&buf[0], sizeof(buf)) == EXIT_FAILURE) {
    puts("tuning udpate failed");
    close_ports();
    return;
  }
  close_ports();
  state_table->tuning_modified = true;
  }
}

int JVlibForm::get_scales() {
  // download scale tunings from JV
  if (state_table->jv_connect && state_table->updates_enabled) {
  int	x,err;
  int	Stop=0;
  unsigned char	buf[8];
  char scale_size[] = { 0x0,0x0,0x0,0x0C };
  
  JVlibForm::statusbar->showMessage("Loading scale tunings",0);
  // get 16 system_area part scales  system_area.sys_part_scale_tune[x].scale
  memset(buf,0,sizeof(buf));
  buf[7] = 0x0C;	// scale size
  if (open_ports() == EXIT_FAILURE) return EXIT_FAILURE;
  if (state_table->perf_mode) {
    // get the 16 Part scales
    for (x=0;x<16;x++) {
      printf("Scale #%d\n",x);
      buf[2] = 0x10 + x;		// scale number
      RetryB:
      if (sysex_request(buf,8) == EXIT_FAILURE) { close_ports(); return(EXIT_FAILURE); }
      err = sysex_get((unsigned char *)&system_area->sys_part_scale_tune[x].scale[0], (char *)scale_size);
      if (err == EXIT_FAILURE) { close_ports(); return(EXIT_FAILURE); }
      if (err==2 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryB; }
      if (err==3 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryB; }
      if (err != EXIT_SUCCESS) { close_ports(); return(EXIT_FAILURE); }
      Stop=0;
    }	// end FOR 16 part scales
  } else {
    // get one remaining patch scale tune
    buf[2] = 0x20;
    RetryC:
    if (sysex_request(buf,8) == EXIT_FAILURE) { close_ports(); return(EXIT_FAILURE); }
    err = sysex_get((unsigned char *)&system_area->sys_patch_scale_tune.scale[0], (char *)scale_size);
    if (err == EXIT_FAILURE) { close_ports(); return(EXIT_FAILURE); }
    if (err==2 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryC; }
    if (err==3 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryC; }
    if (err != EXIT_SUCCESS) { close_ports(); return(EXIT_FAILURE); }
    Stop=0;
  }
  close_ports();
  statusbar->showMessage("Scale tunings loaded",0);
  state_table->tuning_modified = false;
  state_table->tuning_sync = true;
  }	// end   if (state_table->jv_connect && state_table->updates_enabled)
  return(EXIT_SUCCESS);
}	// end GET_SCALES

void JVlibForm::Tuning_BulkUpdate(int pn, int offset, int val) {
  system_area->sys_part_scale_tune[pn-1].scale[offset] = val;
  Tuning_PartTune_select->setValue(pn);
  if (state_table->jv_connect)
    setScaleSingleValue(offset,val);  
}	// end Tuning_BulkUpdate

void JVlibForm::TuningStdUpdate(int offset, int val) {
  if (state_table->updates_enabled) {
    if (state_table->patch_mode) {
      system_area->sys_patch_scale_tune.scale[offset] = val;
      if (state_table->jv_connect)
	setScaleSingleValue(offset,val);
    } else {
      if (Tuning_PartNoneTuning_select->isChecked()) {
	system_area->sys_part_scale_tune[Tuning_PartTune_select->value()-1].scale[offset] = val;
	if (state_table->jv_connect)
	  setScaleSingleValue(offset,val);
      } else {
	if (Tuning_Part1Tuning_select->isChecked()) Tuning_BulkUpdate(1,offset,val);
	if (Tuning_Part2Tuning_select->isChecked()) Tuning_BulkUpdate(2,offset,val);
	if (Tuning_Part3Tuning_select->isChecked()) Tuning_BulkUpdate(3,offset,val);
	if (Tuning_Part4Tuning_select->isChecked()) Tuning_BulkUpdate(4,offset,val);
	if (Tuning_Part5Tuning_select->isChecked()) Tuning_BulkUpdate(5,offset,val);
	if (Tuning_Part6Tuning_select->isChecked()) Tuning_BulkUpdate(6,offset,val);
	if (Tuning_Part7Tuning_select->isChecked()) Tuning_BulkUpdate(7,offset,val);
	if (Tuning_Part8Tuning_select->isChecked()) Tuning_BulkUpdate(8,offset,val);
	if (Tuning_Part9Tuning_select->isChecked()) Tuning_BulkUpdate(9,offset,val);
	if (Tuning_Part10Tuning_select->isChecked()) Tuning_BulkUpdate(10,offset,val);
	if (Tuning_Part11Tuning_select->isChecked()) Tuning_BulkUpdate(11,offset,val);
	if (Tuning_Part12Tuning_select->isChecked()) Tuning_BulkUpdate(12,offset,val);
	if (Tuning_Part13Tuning_select->isChecked()) Tuning_BulkUpdate(13,offset,val);
	if (Tuning_Part14Tuning_select->isChecked()) Tuning_BulkUpdate(14,offset,val);
	if (Tuning_Part15Tuning_select->isChecked()) Tuning_BulkUpdate(15,offset,val);
	if (Tuning_Part16Tuning_select->isChecked()) Tuning_BulkUpdate(16,offset,val);
      }	// end ELSE PartAllTuning checked
    }	// end ELSE perf mode
    state_table->tuning_modified = true;
  }	// end state_table->updates_enabled
}	// end TuningStdUpdate

void JVlibForm::Tuning_QueryTemp(int val) {
  // fill Tuning_currentTuning from database
  // and call Tuning_setScaleTuning to update displays, which will update the synth
  QSqlQuery query(mysql);
  query.prepare("Select cents from Tuning where SerNumber = ?");
  query.bindValue(0, val);
  if (query.exec() == false) {
    puts("Query exec failed in Tuning_QueryTemp");
    query.finish();
    return;
  }
  if (query.size()==0) {
    puts("0 rows found in Tuning_QueryTemp");
    query.finish();
    return;
  } 
  if (query.size() > 1) {
    puts("Too many rows found in Tuning_QueryTemp");
    query.finish();
    return;
  }
  if (query.first())
    Tuning_currentTuning = query.value(0).toByteArray();
  else {
    puts("query.first failed in Tuning_QueryTemp");
    query.finish();
    return;
  }
  query.finish();
  Tuning_setScaleTuning(Tuning_BaseKey_select->currentIndex());
}	// end Tuning_QueryTemp

void JVlibForm::Tuning_setScaleTuning(int val) {
  // set individual scale note tunings from the QByteArray Tuning_currentTuning
  // uses val = Tuning_BaseKey_select->currentIndex()
  // updating the display will update the synth
  int x=0;
  // set x = to where 'C' falls in the chosen key
  switch(val) {
    case 0: case 19:	// C Maj, a min
      x=0;
      break;
    case 2: case 21:	// D-flat Maj, b-flat min
      x=11;
      break;
    case 4: case 23:	// D 
      x=10;
      break;
    case 6: case 1:	// E-flat
      x=9;
      break;
    case 8: case 3:	// E
      x=8;
      break;
    case 10: case 5:	// F
      x=7;
      break;
    case 12: case 7:	// F#
      x=6;
      break;
    case 14: case 9:	// G
      x=5;
      break;
    case 16: case 11:	// A-flat
      x=4;
      break;
    case 18: case 13:	// A
      x=3;
      break;
    case 20: case 15:	// B-flat
      x=2;
      break;
    case 22: case 17:	// B
      x=1;
      break;

  }	// end Switch
  // x is the offset for C
  Tuning_PartTuneC_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
  Tuning_PartTuneCs_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
  Tuning_PartTuneD_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
  Tuning_PartTuneDs_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
  Tuning_PartTuneE_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
  Tuning_PartTuneF_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
  Tuning_PartTuneFs_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
  Tuning_PartTuneG_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
  Tuning_PartTuneGs_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
  Tuning_PartTuneA_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
  Tuning_PartTuneAs_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64); x++;
  Tuning_PartTuneB_select->setValue(Tuning_currentTuning.at(x>11 ? x - 12 : x)-64);
}	// end Tuning_setScaleTuning

