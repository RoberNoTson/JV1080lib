// parts.cpp
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::EnableParts(bool val) {
//  JVlibForm::PartsPartList_select->setEnabled(val);
  JVlibForm::PartsRangeLimitEnable_select->setEnabled(val);
  Patch_PerfPartNum_select->setEnabled(val);
  JVlibForm::PartsBox_1->setEnabled(val);
  JVlibForm::PartsBox_2->setEnabled(val);
  JVlibForm::PartsBox_3->setEnabled(val);
  JVlibForm::PartsBox_4->setEnabled(val);
  JVlibForm::PartsBox_5->setEnabled(val);
  JVlibForm::PartsBox_6->setEnabled(val);
  JVlibForm::PartsBox_7->setEnabled(val);
  JVlibForm::PartsBox_8->setEnabled(val);
  JVlibForm::PartsBox_9->setEnabled(val);
  JVlibForm::PartsBox_10->setEnabled(val);
  JVlibForm::PartsBox_11->setEnabled(val);
  JVlibForm::PartsBox_12->setEnabled(val);
  JVlibForm::PartsBox_13->setEnabled(val);
  JVlibForm::PartsBox_14->setEnabled(val);
  JVlibForm::PartsBox_15->setEnabled(val);
  JVlibForm::PartsBox_16->setEnabled(val);
}

void JVlibForm::setPartSingleValue(int partnum, int addr, int val) {
  if (state_table->updates_enabled) {
    char *ptr = (char *)&active_area->active_performance.perf_part[partnum].MIDI_receive;
    ptr[addr] = val;
    if (state_table->jv_connect) {
      unsigned char buf[12];
      memset(buf,0,sizeof(buf));
      buf[4] = JV_UPD;
      buf[5] = 0x01;
      buf[7] = 0x10+partnum;
      buf[8] = addr;
      buf[9] = val;
      buf[10] = chksum(buf+5, 5);
      buf[11] = 0xF7;
      if (open_ports() == EXIT_FAILURE) return;
      if (sysex_send(buf,12) == EXIT_FAILURE) { close_ports(); return; }
      close_ports();
    }	// end state_table->jv_connect
  }  // end if updates enabled
}	// end setPartSingleValue

QString JVlibForm::getPartPatchName(int val) {
  // passes Part offset (0-15) as val
  // returns Patch name as QSTring
  unsigned char buf[16];
  char    name_size[] = { 0x0,0x0,0x0,0x0C };
  
  memset(buf,0,sizeof(buf));
  buf[4] = JV_REQ;
  buf[5] = 0x02;	// base address of active_area->perf_part
  buf[6] = val;		// offset to part info
  buf[12] = 0x0C;		// size of patch name
  buf[13] = chksum(buf+5, 8);	// checksum  
  buf[14] = 0xF7;
  if (open_ports() == EXIT_FAILURE) return("");
  int	Stop=0;
  RetryA:
  if (sysex_send(buf,15) == EXIT_FAILURE) { close_ports(); puts("1 getPartPatchName failed!"); return(""); }
  int err = sysex_get((unsigned char *)&active_area->active_perf_patch[val].patch_common.name[0], (char *)&name_size);
  if (err == EXIT_FAILURE) { close_ports(); puts("2 getPartPatchName failed!"); return(""); }
  if (err==2 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; usleep(25000*Stop); goto RetryA; }
  if (err==3 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; usleep(25000*Stop); goto RetryA; }
  if (err != EXIT_SUCCESS) { close_ports(); puts("3 getPartPatchName failed!"); return(""); }
  close_ports();
  return QString::fromAscii(&active_area->active_perf_patch[val].patch_common.name[0],12);
}	// end getPartPatchName

int JVlibForm::toggleControlChannel(int val) {
  // if val = current ctl chnl, change to something else,
  // otherwise set it to that channel.
  int pn = val-1;
  if (pn == system_area->sys_common.control_channel) {
    SysControlRecvChannel_select->setValue(val>1?pn:16);
    return val;
  }
  return 0;
}	// end toggleControlChannel

void JVlibForm::setVoiceCounters() {
  Parts_ReservedVoices_display->display(Part1_VoiceReserve_select->value()+
    Part2_VoiceReserve_select->value()+
    Part3_VoiceReserve_select->value()+
    Part4_VoiceReserve_select->value()+
    Part5_VoiceReserve_select->value()+
    Part6_VoiceReserve_select->value()+
    Part7_VoiceReserve_select->value()+
    Part8_VoiceReserve_select->value()+
    Part9_VoiceReserve_select->value()+
    Part10_VoiceReserve_select->value()+
    Part11_VoiceReserve_select->value()+
    Part12_VoiceReserve_select->value()+
    Part13_VoiceReserve_select->value()+
    Part14_VoiceReserve_select->value()+
    Part15_VoiceReserve_select->value()+
    Part16_VoiceReserve_select->value());
  Parts_AvaliableVoices_display->display(64 - Parts_ReservedVoices_display->intValue()); 
}