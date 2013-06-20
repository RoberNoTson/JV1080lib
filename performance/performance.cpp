// perf_mode.cpp

#include	"JVlibForm.h"
#include	<QtGui>
#include	"performance.h"

void JVlibForm::getActivePerfCommon() {
  // download from the synth: Performance Common, Part Common (15 total)
  // called from on_PerfSync_button_clicked when Performance Sync button is clicked.
  int   err;
  int   Stop=0;
  unsigned char  buf[15];
  char       active_perf_common[]={ 0x1,0x0,0x0,0x0 };
  char    perf_common_size[] = { 0x0,0x0,0x0,0x40 };
  char	perf_part_size[] = { 0x0,0x0,0x0,0x13 };
  char    name_size[] = { 0x0,0x0,0x0,0x0C };

  // get active_area perf_common
  memset(buf,0,sizeof(buf));
  buf[4] = JV_REQ;
  memcpy(buf+5,active_perf_common,4);
  memcpy(buf+9,perf_common_size,4);
  buf[13] = chksum(buf+5, 8);
  buf[14] = 0xF7;
  // open the selected midi port
  if (open_ports() == EXIT_FAILURE) return;
  QProgressDialog progress("Getting Performance data...", "Abort Download", 0, 32, this);
  progress.setWindowModality(Qt::WindowModal);
  progress.setMinimumDuration(0);
  progress.setValue(0);
  RetryA:
  if (sysex_send(buf,15) == EXIT_FAILURE) { close_ports(); return; }
  err = sysex_get((unsigned char *)&active_area->active_performance.perf_common.name[0], (char *)perf_common_size);
  if (err == EXIT_FAILURE) { close_ports(); return; }
  if (err==2 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryA; }
  if (err==3 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryA; }
  if (err != EXIT_SUCCESS) { close_ports(); return; }
  // get Performance Part_common headers for 15 parts, skipping over the rhythm set
  memcpy(buf+9,perf_part_size,4);
  for (int x=0;x<16;x++) {
    progress.setValue(x);
    if (progress.wasCanceled()) goto breakout;
    printf("part %d\n",x+1);
//    if (x==9) continue;
    usleep(200000);
    buf[7] = 0x10+x;
    buf[13] = chksum(buf+5, 8);
    RetryB:
    if (sysex_send(buf,15) == EXIT_FAILURE) { close_ports(); return; }
    err = sysex_get((unsigned char *)&active_area->active_performance.perf_part[x].MIDI_receive, (char *)perf_part_size);
    if (err == EXIT_FAILURE) { close_ports(); return; }
    if (err==2 && Stop<MAX_RETRIES) { Stop++; sleep(1*Stop); goto RetryB; }
    if (err==3 && Stop<MAX_RETRIES) { Stop++; sleep(1*Stop); goto RetryB; }
    if (err != EXIT_SUCCESS) { close_ports(); return; }
    Stop=0;
  } // end FOR
  // get just the associated Part Patch names to match the Part_common headers
  memset(buf,0,sizeof(buf));
  buf[4] = JV_REQ;
  buf[5] = 0x2;
  buf[12] = 0xC;	// just enough space for the name, ignore the rest of patch common for now.
  buf[14] = 0xF7;
  for (int x=0;x<16;x++) {		// get patch common
    progress.setValue(x+16);
    if (progress.wasCanceled()) goto breakout;
    printf("patch %d\n",x+1);
//    if (x == 9) continue;	// skip over the rhythm set
    usleep(200000);
    buf[6] = x;		// Patch number
    buf[13] = chksum(buf+5, 8);	// checksum
    RetryC:
    if (sysex_send(buf,15) == EXIT_FAILURE) { close_ports(); return; }
    err = sysex_get((unsigned char *)&active_area->active_perf_patch[x].patch_common.name[0], (char *)name_size);
    if (err == EXIT_FAILURE) { close_ports(); return; }
    if (err==2 && Stop<MAX_RETRIES) { Stop++; sleep(1*Stop); goto RetryC; }
    if (err==3 && Stop<MAX_RETRIES) { Stop++; sleep(1*Stop); goto RetryC; }
    if (err != EXIT_SUCCESS) { close_ports(); return; }
    Stop=0;
  }
  breakout:
  close_ports();
//  getActivePatchNames();
  progress.setValue(32);
  progress.reset();
  EnableParts(true);
}	// end getActivePerfCommon

void JVlibForm::getActivePatchNames() {
  // get just the associated Part Patch names to match the Part_common headers
  int   err;
  int   Stop=0;
  unsigned char  buf[15];
  char    name_size[] = { 0x0,0x0,0x0,0x0C };
  
  memset(buf,0,sizeof(buf));
  buf[4] = JV_REQ;
  buf[5] = 0x2;
  buf[12] = 0xC;	// just enough space for the name, ignore the rest of patch common for now.
  buf[14] = 0xF7;
  // open the selected midi port
  if (open_ports() == EXIT_FAILURE) return;
  for (int x=0;x<16;x++) {		// get patch common
//    if (x == 9) continue;	// skip over the rhythm set
    usleep(200000);
    buf[6] = x;		// Patch number
    buf[13] = chksum(buf+5, 8);	// checksum
    RetryC:
    if (sysex_send(buf,15) == EXIT_FAILURE) { close_ports(); return; }
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
      unsigned char buf[12];
      memset(buf,0,sizeof(buf));
      buf[4] = JV_UPD;
      buf[5] = 0x01;
      buf[8] = addr;
      buf[9] = val;
      buf[10] = chksum(buf+5, 5);
      buf[11] = 0xF7;
      if (open_ports() == EXIT_FAILURE) return;
      if (sysex_send(buf,12) == EXIT_FAILURE) { close_ports(); return; }
      close_ports();
    }	// end jv_connect
  }	// end updates_enabled
}	// end setPerfSingleValue

void JVlibForm::EnablePerf(bool val) {
  // called after a port is selected and Performance values are downloaded from the synth
  // also called to disable controls when the Performance number or group is changed
  PerfParts_tab->setEnabled(val);
  PerfTempoBox->setEnabled(val);
  PerfEFXsource_select->setEnabled(val);
  Perf_EFX_groupBox->setEnabled(val);
  PerfReverb_box->setEnabled(val);
  PerfChorus_box->setEnabled(val);
  Patch_tab->setEnabled(val);
  PatchEFX_tab->setEnabled(val);
  Tone_tab->setEnabled(val);
  ToneEFX_tab->setEnabled(val);
  ToneTVF_tab->setEnabled(val);
  ToneTVA_tab->setEnabled(val);
  Rhythm_tab->setEnabled(val);
  Rhythm_EnableAll(false);
  Tuning_Sync_button->setEnabled(val);
  if (val) Perf_Sync_status->on();
  else Perf_Sync_status->off();
  state_table->partsTab_enable = val;
  state_table->patchTab_enable = val;
  state_table->rhythmTab_enable = val;
  state_table->patchEFXTab_enable = val;
  state_table->toneTab_enable = val;
  state_table->toneTVFTab_enable = val;
  state_table->toneTVATab_enable = val;
  state_table->patchEFXTab_enable = val;
}