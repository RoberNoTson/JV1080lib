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

void JVlibForm::PartsToneSwitch(int chan, bool val) {
  if (val) {
    change_3(0x90 + chan, SysPreviewNote1_select->value(), SysPreviewNote1_volume->value());
  } 
  else {
    change_3(0xB0 + chan, 0x7B, 0);
    change_3(0xB0 + chan, 0x79, 0);
  }  
}

void JVlibForm::setPartSingleValue(int partnum, int addr, int val) {
  if (state_table->updates_enabled) {
    char *ptr = (char *)&active_area->active_performance.perf_part[partnum].MIDI_receive;
    ptr[addr] = val;
    if (state_table->jv_connect) {
      unsigned char buf[5];
      memset(buf,0,sizeof(buf));
      buf[0] = 0x01;
      buf[2] = 0x10+partnum;
      buf[3] = addr;
      buf[4] = val;
      if (open_ports() == EXIT_FAILURE) return;
      if (sysex_update(&buf[0],5) == EXIT_FAILURE) { close_ports(); return; }
      close_ports();
    }	// end state_table->jv_connect
  }  // end if updates enabled
}	// end setPartSingleValue

QString JVlibForm::getPartPatchName(int val) {
  // passes Part offset (0-15) as val
  // returns Patch name as QSTring
  if (!state_table->GM_mode) {
  unsigned char buf[8];
  char    name_size[] = { 0x0,0x0,0x0,0x0C };  
  memset(buf,0,sizeof(buf));
  buf[0] = 0x02;	// base address of active_area->perf_part
  buf[1] = val;		// offset to part info
  buf[7] = 0x0C;		// size of patch name
  if (open_ports() == EXIT_FAILURE) return("");
  int	Stop=0;
  RetryA:
  if (sysex_request(buf,8) == EXIT_FAILURE) { close_ports(); puts("1 getPartPatchName failed!"); return(""); }
  int err = sysex_get((unsigned char *)&active_area->active_perf_patch[val].patch_common.name[0], (char *)&name_size);
  if (err == EXIT_FAILURE) { close_ports(); puts("2 getPartPatchName failed!"); return(""); }
  if (err==2 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; usleep(25000*Stop); goto RetryA; }
  if (err==3 && Stop<MAX_RETRIES) { if (debug) puts("Retrying"); Stop++; usleep(25000*Stop); goto RetryA; }
  if (err != EXIT_SUCCESS) { close_ports(); puts("3 getPartPatchName failed!"); return(""); }
  close_ports();
  return QString::fromAscii(&active_area->active_perf_patch[val].patch_common.name[0],12);
  }	// end Perf or Patch mode
  if (state_table->GM_mode) {
    // select name from patch_list where group_area = "Preset D" and number = partX_PatchNumber_select->value()
    int x = 0;
    switch(val) {
      case 0:
	x = Part1_PatchNumber_select->value();
	break;
      case 1:
	x = Part2_PatchNumber_select->value();
	break;
      case 2:
	x = Part3_PatchNumber_select->value();
	break;
      case 3:
	x = Part4_PatchNumber_select->value();
	break;
      case 4:
	x = Part5_PatchNumber_select->value();
	break;
      case 5:
	x = Part6_PatchNumber_select->value();
	break;
      case 6:
	x = Part7_PatchNumber_select->value();
	break;
      case 7:
	x = Part8_PatchNumber_select->value();
	break;
      case 8:
	x = Part9_PatchNumber_select->value();
	break;
      case 9:
	x = Part10_PatchNumber_select->value();
	break;
      case 10:
	x = Part11_PatchNumber_select->value();
	break;
      case 11:
	x = Part12_PatchNumber_select->value();
	break;
      case 12:
	x = Part13_PatchNumber_select->value();
	break;
      case 13:
	x = Part14_PatchNumber_select->value();
	break;
      case 14:
	x = Part15_PatchNumber_select->value();
	break;
      case 15:
	x = Part16_PatchNumber_select->value();
	break;
    }	// end switch
    // bind 'x' to query
    QSqlQuery query(mysql);
    query.prepare("Select name from patch_list where group_area = 'Preset D' and number = ?");
    query.bindValue(0, x);
    if (query.exec() == false) {
      puts("Query exec failed in Tuning_QueryTemp");
      query.finish();
      return "";
    }
    if (query.size()==0) {
      puts("0 rows found in Tuning_QueryTemp");
      query.finish();
      return "";
    }
    if (query.size() > 1) {
      puts("Too many rows found in Tuning_QueryTemp");
      query.finish();
      return "";
    }
    if (query.first())
      return query.value(0).toByteArray();
    else {
      puts("query.first failed in Tuning_QueryTemp");
      query.finish();
      return "";
    }
    query.finish();
  }	// end GM mode
  return "na";
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