// tuning.cpp

#include	"JVlibForm.h"
#include	<QtGui>

void JVlibForm::setScaleSingleValue(int addr, int val) {
  unsigned char buf[12];
  if (state_table->jv_connect && state_table->updates_enabled) {
  memset(buf,0,sizeof(buf));
  buf[4] = JV_UPD;
  if (state_table->patch_mode)
    buf[7] = 0x20;
  else
    buf[7] = 0x10 + Tuning_PartTune_select->value() - 1;
  buf[8] = addr;
  buf[9] = val;
  buf[10] = chksum(buf+5, 5);
  buf[11] = 0xF7;
  if (open_ports() == EXIT_FAILURE) return;
  if (sysex_send(buf,12) == EXIT_FAILURE) {
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
  unsigned char	buf[15];
  char scale_size[] = { 0x0,0x0,0x0,0x0C };
  
  // open the selected midi port
  JVlibForm::statusbar->showMessage("Loading scale tunings",0);
  // get 16 system_area part scales  system_area.sys_part_scale_tune[x].scale
  memset(buf,0,sizeof(buf));
  buf[4] = JV_REQ;
  buf[12] = 0x0C;	// scale size
  buf[14] = 0xF7;
  if (open_ports() == EXIT_FAILURE) return EXIT_FAILURE;
  if (state_table->perf_mode) {
    // get the 16 Part scales
    for (x=0;x<16;x++) {
      printf("Scale #%d\n",x);
      buf[7] = 0x10 + x;		// scale number
      buf[13] = chksum(buf+5, 8);	// checksum
      RetryB:
      if (sysex_send(buf,15) == EXIT_FAILURE) { close_ports(); return(EXIT_FAILURE); }
      err = sysex_get((unsigned char *)&system_area->sys_part_scale_tune[x].scale[0], (char *)scale_size);
      if (err == EXIT_FAILURE) { close_ports(); return(EXIT_FAILURE); }
      if (err==2 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryB; }
      if (err==3 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; sleep(1*Stop); goto RetryB; }
      if (err != EXIT_SUCCESS) { close_ports(); return(EXIT_FAILURE); }
      Stop=0;
    }	// end FOR 16 part scales
  } else {
    // get one remaining patch scale tune
    buf[7] = 0x20;
    buf[13] = chksum(buf+5, 8);	// checksum  
    RetryC:
    if (sysex_send(buf,15) == EXIT_FAILURE) { close_ports(); return(EXIT_FAILURE); }
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
  return EXIT_SUCCESS;
}	// end GET_SCALES

