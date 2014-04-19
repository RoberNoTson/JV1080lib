// performance.cpp
/* Contains:
 * getActivePerfCommon
 * getActivePatchNames
 * setPerfSingleValue
 * EnablePerf
 */

#include	"JVlibForm.h"
#include	<QtGui>
#include	"performance.h"

void JVlibForm::getActivePerfCommon() {
  // download from the synth: Performance Common, Part Common (15 total)
  // called from on_PerfSync_button_clicked when Performance Sync button is clicked.
  int   err;
  int   Stop=0;
  unsigned char  buf[8];
  char       active_perf_common[]={ 0x1,0x0,0x0,0x0 };
  char    perf_common_size[] = { 0x0,0x0,0x0,0x40 };
  char	perf_part_size[] = { 0x0,0x0,0x0,0x13 };
  char    name_size[] = { 0x0,0x0,0x0,0x0C };

  // get active_area perf_common
  memset(buf,0,sizeof(buf));
  memcpy(buf+0,active_perf_common,4);
  memcpy(buf+4,perf_common_size,4);
  // open the selected midi port
  if (open_ports() == EXIT_FAILURE) return;
  QProgressDialog progress("Getting Performance data...", "Abort Download", 0, 32, this);
  progress.setWindowModality(Qt::WindowModal);
  progress.setMinimumDuration(0);
  progress.setValue(0);
  RetryA:
  if (sysex_request(buf) == EXIT_FAILURE) { close_ports(); return; }
  err = sysex_get((unsigned char *)&active_area->active_performance.perf_common.name[0], (char *)perf_common_size);
  if (err == EXIT_FAILURE) { close_ports(); return; }
  if (err==2 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryA; }
  if (err==3 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryA; }
  if (err != EXIT_SUCCESS) { close_ports(); return; }
  // get Performance Part_common headers for 16 parts
  memcpy(buf+4,perf_part_size,4);
  for (int x=0;x<16;x++) {
    progress.setValue(x);
    if (progress.wasCanceled()) goto breakout;
    printf("part %d\n",x+1);
    usleep(200000);
    buf[2] = 0x10+x;
    RetryB:
    if (sysex_request(buf) == EXIT_FAILURE) { close_ports(); return; }
    err = sysex_get((unsigned char *)&active_area->active_performance.perf_part[x].MIDI_receive, (char *)perf_part_size);
    if (err == EXIT_FAILURE) { close_ports(); return; }
    if (err==2 && Stop<MAX_RETRIES) { Stop++; sleep(1*Stop); goto RetryB; }
    if (err==3 && Stop<MAX_RETRIES) { Stop++; sleep(1*Stop); goto RetryB; }
    if (err != EXIT_SUCCESS) { close_ports(); return; }
    Stop=0;
  } // end FOR
  // get just the associated Part Patch names to match the Part_common headers
  memset(buf,0,sizeof(buf));
  buf[0] = 0x2;
  buf[7] = 0xC;	// just enough space for the name, ignore the rest of patch common for now.
  for (int x=0;x<16;x++) {		// get patch common
    progress.setValue(x+16);
    if (progress.wasCanceled()) goto breakout;
    printf("patch name %d\n",x+1);
    usleep(200000);
    buf[1] = x;		// Patch number
    RetryC:
    if (sysex_request(buf) == EXIT_FAILURE) { close_ports(); return; }
    err = sysex_get((unsigned char *)&active_area->active_perf_patch[x].patch_common.name[0], (char *)name_size);
    if (err == EXIT_FAILURE) { close_ports(); return; }
    if (err==2 && Stop<MAX_RETRIES) { Stop++; sleep(1*Stop); goto RetryC; }
    if (err==3 && Stop<MAX_RETRIES) { Stop++; sleep(1*Stop); goto RetryC; }
    if (err != EXIT_SUCCESS) { close_ports(); return; }
    Stop=0;
  }
  breakout:
  close_ports();
  progress.setValue(32);
  progress.reset();
  EnableParts(true);
}	// end getActivePerfCommon

void JVlibForm::getActivePatchNames() {
  // get just the associated Part Patch names to match the Part_common headers
  int   err;
  int   Stop=0;
  unsigned char  buf[8];
  char    name_size[] = { 0x0,0x0,0x0,0x0C };
  
  memset(buf,0,sizeof(buf));
  buf[0] = 0x2;
  buf[7] = 0xC;	// just enough space for the name, ignore the rest of patch common for now.
  // open the selected midi port
  if (open_ports() == EXIT_FAILURE) return;
  for (int x=0;x<16;x++) {		// get patch common
    usleep(200000);
    buf[1] = x;		// Patch number
    RetryC:
    if (sysex_request(buf) == EXIT_FAILURE) { close_ports(); return; }
    err = sysex_get((unsigned char *)&active_area->active_perf_patch[x].patch_common.name[0], (char *)name_size);
    if (err == EXIT_FAILURE) { close_ports(); return; }
    if (err==2 && Stop<MAX_RETRIES) { Stop++; sleep(1*Stop); goto RetryC; }
    if (err==3 && Stop<MAX_RETRIES) { Stop++; sleep(1*Stop); goto RetryC; }
    if (err != EXIT_SUCCESS) { close_ports(); return; }
    Stop=0;
  }
  close_ports();
}	// end getActivePatchNames

void JVlibForm::setPerfSingleValue(int addr, int val) {
  if (state_table->updates_enabled) {
    char *ptr = (char *)&active_area->active_performance.perf_common.name[0];
    ptr[addr] = val;
    if (state_table->jv_connect) {
      unsigned char buf[5];
      buf[0] = 0x01;
      buf[1] = 0;
      buf[2] = 0;
      buf[3] = addr;
      buf[4] = val;
//      if (open_ports() == EXIT_FAILURE) return;
      if (sysex_update(&buf[0],5) == EXIT_FAILURE) return; //{ close_ports(); return; }
//      close_ports();
    }	// end jv_connect
  }	// end updates_enabled
}	// end setPerfSingleValue

void JVlibForm::EnablePerf(bool val) {
  // called after a port is selected and Performance values are downloaded from the synth
  // also called to disable controls when the Performance number or group is changed
  setPerfTabs(val);
  PerfTempoBox->setEnabled(val);
  PerfEFXsource_select->setEnabled(val);
  Perf_EFX_groupBox->setEnabled(val);
  PerfReverb_box->setEnabled(val);
  PerfChorus_box->setEnabled(val);
  Patch_tab->setEnabled(val);
  Rhythm_EnableAll(false);
//  Tuning_Sync_button->setEnabled(val);
  if (val) Perf_Sync_status->on();
  else Perf_Sync_status->off();
  state_table->performance_sync = val;
  System_Upload_button->setEnabled(val);
  actionWrite->setEnabled(val);
  actionCopy->setEnabled(val);
}