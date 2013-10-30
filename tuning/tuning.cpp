// tuning.cpp
/* Contains:
 * setScaleSingleValue
 * get_scales
 * Tuning_BulkUpdate
 * TuningStdUpdate
 * Tuning_QueryTemp
 */

#include	"JVlibForm.h"
#include	<QtGui>

void JVlibForm::setScaleSingleValue(int addr, int val) {
  unsigned char buf[5];
  if (!state_table->jv_connect || !state_table->updates_enabled) return;
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

int JVlibForm::get_scales() {
  // download scale tunings from JV
  if (!state_table->jv_connect || !state_table->updates_enabled)   return(EXIT_FAILURE);
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
  } 
  else if (state_table->patch_mode) {
    // get one patch scale tune
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
  statusbar->showMessage("Scale tunings downloaded",0);
  state_table->tuning_modified = false;
  state_table->tuning_sync = true;
  return(EXIT_SUCCESS);
}	// end GET_SCALES

void JVlibForm::Tuning_BulkUpdate(int pn, int offset, int val) {
  system_area->sys_part_scale_tune[pn-1].scale[offset] = val;
  Tuning_PartTune_select->setValue(pn);
  if (state_table->jv_connect)
    setScaleSingleValue(offset,val);  
}	// end Tuning_BulkUpdate

void JVlibForm::TuningStdUpdate(int offset, int val) {
  if (!state_table->updates_enabled) return;
    if (state_table->patch_mode) {
      system_area->sys_patch_scale_tune.scale[offset] = val;
      if (state_table->jv_connect)
	setScaleSingleValue(offset,val);
    } 
    if (state_table->perf_mode) {
//      if (Tuning_PartNoneTuning_select->isChecked()) {
//	system_area->sys_part_scale_tune[Tuning_PartTune_select->value()-1].scale[offset] = val;
//	if (state_table->jv_connect)
//	  setScaleSingleValue(offset,val);
//      } else {
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
//      }	// end ELSE PartAllTuning checked
    }	// end IF perf mode
    state_table->tuning_modified = true;
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
//  Tuning_setScaleTuning(Tuning_BaseKey_select->currentIndex());
  on_Tuning_BaseKey_select_currentIndexChanged(Tuning_BaseKey_select->currentIndex());
}	// end Tuning_QueryTemp
