// save_user_patch.cpp
#include	"save_dialog/Save_Dialog.h"
#include	"ui_Save_Dialog.h"
#include        "JVlibForm.h"
#include        <QtGui>
#include	<QtSql>

int Save_Dialog::SaveUserPatch(int pn, int Part) {
  // called from Save_Dialog
  int err;
  int Stop=0;
  int sz = 0x48 + (0x81*4);	// common and 4 tones
  unsigned char  buf[16];
  char user1_patch_common[]={ 0x11,0x00,0x00,0x00 };
  char patch_common_size[] = { 0x00,0x00,0x00,0x48 };
  char patch_tone_size[] = { 0x00,0x00,0x01,0x01 };
  struct PATCH temp_r;
  
  // get a User patch, common and 4 tones
  memset(buf,0,sizeof(buf));
  buf[4] = JV_REQ;
  memcpy(buf+5,user1_patch_common,4);
  buf[6] = pn - 1;
  memcpy(buf+9,patch_common_size,4);
  buf[13] = JVlibForm::chksum(buf+5,8);
  buf[14] = 0xF7;
  if (JVlibForm::open_ports() == EXIT_FAILURE) return false;
  RetryG:
  if (JVlibForm::sysex_send(buf,15) == EXIT_FAILURE) { JVlibForm::close_ports(); return false; }
  err = JVlibForm::sysex_get((unsigned char *)&temp_r.patch_common.name[0], (char *)patch_common_size);
  if (err == EXIT_FAILURE) { JVlibForm::close_ports(); return false; }
  if (err==2 && Stop<MAX_RETRIES) {  Stop++; usleep(20000*Stop); goto RetryG; }
  if (err==3 && Stop<MAX_RETRIES) {  Stop++; usleep(20000*Stop); goto RetryG; }
  if (err != EXIT_SUCCESS) { JVlibForm::close_ports(); return false; }
  Stop=0;
  // get 4 tones for this patch
  memcpy(buf+9,patch_tone_size,4);
  for (int y=0;y<4;y++) {
    buf[7] = 0x10+(y*2);	// tone address
    buf[13] = JVlibForm::chksum(buf+5, 8);	// checksum
    RetryH:
    if (JVlibForm::sysex_send(buf,15) == EXIT_FAILURE) { JVlibForm::close_ports(); return false; }
    err = JVlibForm::sysex_get((unsigned char *)&temp_r.patch_tone[y].tone, (char *)patch_tone_size);
    if (err == EXIT_FAILURE) { JVlibForm::close_ports(); return false; }
    if (err==2 && Stop<MAX_RETRIES) { Stop++; usleep(20000*Stop); goto RetryH; }
    if (err==3 && Stop<MAX_RETRIES) { Stop++; usleep(20000*Stop); goto RetryH; }
    if (err != EXIT_SUCCESS) { JVlibForm::close_ports(); return false; }
    Stop=0;
  }	// end FOR 4 tones
  JVlibForm::close_ports();
  return(db_insert_data("Patches", (char *)&temp_r, sz, Part));
}	// end SaveUserPatch
