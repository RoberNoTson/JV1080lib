// system.cpp

#include	"JVlibForm.h"
#include	"system.h"
#include	<QtGui>
#include	<QDebug>

// Functions
void JVlibForm::getSysPatchName() {
  // get the current active Patch name from the active area
  if (state_table->jv_connect) {
  int	err;
  int	Stop=0;
  unsigned char buf[16];
  char r_buf[16];
  memset(buf,0,sizeof(buf));
  buf[4] = JV_REQ;
  buf[5] = 0x03;	// addr of active patch-mode patch
  buf[12] = name_size[3];
  buf[13] = chksum(buf+5, 8);	// checksum  
  buf[14] = 0xF7;
  // open the selected midi port
  if (open_ports() == EXIT_FAILURE) return;
  RetryA:
  if (sysex_send(buf,15) == EXIT_FAILURE) { close_ports(); return; }
  err = sysex_get((unsigned char *)&r_buf, (char *)&name_size);
  if (err == EXIT_FAILURE) return;
  if (err==2 && Stop<MAX_RETRIES) { if (debug) qDebug() << "Retrying"; Stop++; sleep(1*Stop); goto RetryA; }
  if (err==3 && Stop<MAX_RETRIES) { if (debug) qDebug() << "Retrying"; Stop++; sleep(1*Stop); goto RetryA; }
  if (err != EXIT_SUCCESS) { close_ports(); return; }
  close_ports();
  SysPatchName->setEnabled(true);
  SysPatchName->setText(QString::fromAscii(r_buf,12));
  Patch_Name_edit->setText(SysPatchName->text());
  PatchEFX_Name_display->setText(SysPatchName->text());
  }
}
  
void JVlibForm::getSysPerfName() {
  // get the current active Performance name from the synth
  if (state_table->jv_connect) {
    int	err;
    int	Stop=0;
    unsigned char buf[16];
    char r_buf[256];
    memset(buf,0,sizeof(buf));
    buf[4] = JV_REQ;
    buf[5] = 0x01;	// address of active_area->perf_common.name
    buf[12] = name_size[3];
    buf[13] = chksum(buf+5, 8);	// checksum  
    buf[14] = 0xF7;
    // open the selected midi port
    if (open_ports() == EXIT_FAILURE) return;
    RetryA:
    if (sysex_send(buf,15) == EXIT_FAILURE) {
      close_ports(); 
      return;
    }
    err = sysex_get((unsigned char *)r_buf, (char *)&name_size);
    if (err == EXIT_FAILURE) return;
    if (err==2 && Stop<MAX_RETRIES) { if (debug) qDebug() << "Retrying"; Stop++; sleep(1*Stop); goto RetryA; }
    if (err==3 && Stop<MAX_RETRIES) { if (debug) qDebug() << "Retrying"; Stop++; sleep(1*Stop); goto RetryA; }
    if (err != EXIT_SUCCESS) { close_ports(); return; }
    close_ports();
    SysPerfName->setText(QString::fromAscii(r_buf,12));
    SysPerfName->setEnabled(true);
    PerfName_edit->setText(SysPerfName->text());
    PartsPerfName_display->setText(SysPerfName->text());
  }	// end state_table->jv_connect
}	// end getSysPerfName

void JVlibForm::setSysGmMode(bool GM) {
  // enable/disable items for GM mode
  if (GM) {
    state_table->GM_mode = true;
    SysPatch_box->setEnabled(false);
    SysPerformance_box->setEnabled(false);
    PerfGroup_select->setEnabled(false);
    PerfNumber_select->setEnabled(false);
    PerfName_edit->setEnabled(false);
    EnablePerf(false);
    EnablePatch(false);
    SysClock_select->setCurrentIndex(1);
    SysControlRecvChannel_select->setEnabled(false);
    SysPatchRecvChannel_select->setEnabled(false);
    SysClock_select->setEnabled(false);
    AcceptBankSel_switch->setChecked(false);
    AcceptBankSel_switch->setEnabled(false);
    SysControlSource1_select->setCurrentIndex(2);
    SysVolumeControl_select->setCurrentIndex(1);
    SysAftertouchControl_select->setCurrentIndex(0);
    setPerfTabs(false);
    setPatchTabs(false);
    PerfGroup_select->setEnabled(false);
    PerfNumber_select->setEnabled(false);
    PerfName_edit->setEnabled(false);
    SysPerformance_box->setEnabled(false);
    MainTabWidget->setTabEnabled(1,false);	// Performance tab
    MainTabWidget->setTabEnabled(3,false);	// Patch tab
    MainTabWidget->setTabEnabled(11,false);	// Tuning tab
    MainTabWidget->setTabEnabled(2,true);		// Parts tab
    state_table->performanceTab_enable = false;
    state_table->patchTab_enable = false;
    state_table->partsTab_enable = true;
    EnableParts(true);
    setPartsParms();
    PartsPerfName_display->setText("GM");
    PartsPerfGroup_display->setText("GM");
    PartsPerfNumber_display->clear();
  } else {
    state_table->GM_mode = false;
    // enable valid widgets
    SysClock_select->setEnabled(true);
    AcceptBankSel_switch->setEnabled(true);
    SysControlRecvChannel_select->setEnabled(true);
    SysPatchRecvChannel_select->setEnabled(true);
    SysClock_select->setEnabled(true);
  }
}	// end setSysGmMode

void JVlibForm::setSysSingleValue(int addr, int val) {
if (state_table->updates_enabled) {
  state_table->system_modified = true;
  if (state_table->jv_connect) {
    unsigned char buf[12];
    memset(buf,0,sizeof(buf));
    buf[4] = JV_UPD;
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
  }	// end jv_connect
  else  {	// System settings modified but synth not updated
    System_Sync_status->off();
  }
}
}	// end setSysSingleValue

void JVlibForm::EnableSys(bool val) {
  // called from slotDownloadClicked after a valid port is selected and System Common is downloaded
  SysSwitchBox->setEnabled(val);
  SysPreviewBox->setEnabled(val);
  SysSourceBox->setEnabled(val);
  SysTestTone_button->setEnabled(val);
  System_Upload_button->setEnabled(val);
  SysPanic_button->setEnabled(val);
  SysMode_select->setEnabled(val);
  System_Sync_button->setEnabled(val);
//  SysPlayMidi_button->setEnabled(val);
  Tuning_MasterTune_select->setEnabled(val);
  if (state_table->perf_mode) {
    SysPerformance_box->setEnabled(val);
    SysPerfName->setEnabled(val);
    SysPerfNumber->setEnabled(val);
    PerfSync_button->setEnabled(val);
    PerfGroup_select->setEnabled(val);
    PerfNumber_select->setEnabled(val);
    PerfName_edit->setEnabled(val);
    SysPatch_box->setEnabled(!val);
    SysPatchName->setEnabled(!val);
    SysPatchNumber->setEnabled(!val);
    Patch_Sync_button->setEnabled(!val);
    Patch_Group_select->setEnabled(!val);
    Patch_Number_select->setEnabled(!val);
    Patch_Name_edit->setEnabled(!val);
  }
  else if (state_table->patch_mode) {
    SysPerformance_box->setEnabled(!val);
    SysPerfName->setEnabled(!val);
    SysPerfNumber->setEnabled(!val);
    PerfSync_button->setEnabled(!val);
    PerfGroup_select->setEnabled(!val);
    PerfNumber_select->setEnabled(!val);
    PerfName_edit->setEnabled(!val);
    SysPatch_box->setEnabled(val);
    SysPatchName->setEnabled(val);
    SysPatchNumber->setEnabled(val);
    Patch_Sync_button->setEnabled(val);
    Patch_Group_select->setEnabled(val);
    Patch_Number_select->setEnabled(val);
    Patch_Name_edit->setEnabled(val);
  }
}	// end EnableSys
