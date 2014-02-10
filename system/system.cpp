// system.cpp
/* Includes:
 * getSysPatchName()
 * getSysPerfName()
 * setSysGmMode()
 * setSysSingleValue()
 * EnableSys()
 */

#include	"JVlibForm.h"
#include	<QtGui>
#include	<QDebug>

char    name_size[] = { 0x0,0x0,0x0,0x0C };

// Functions
void JVlibForm::getSysPatchName() {
  // get the current active Patch name from the active area
  if (!state_table->jv_connect) return;
  int	err;
  int	Stop=0;
  unsigned char buf[8];
  char r_buf[16];
  memset(buf,0,sizeof(buf));
  buf[0] = 0x03;	// addr of active patch-mode patch
  buf[7] =0x0C;
  RetryA:
  if (sysex_request(buf) == EXIT_FAILURE) return;
  err = sysex_get((unsigned char *)&r_buf, (char *)&name_size);
  if (err == EXIT_FAILURE) return;
  if (err==2 && Stop<MAX_RETRIES) { if (debug) qDebug() << "Retrying"; Stop++; sleep(1*Stop); goto RetryA; }
  if (err==3 && Stop<MAX_RETRIES) { if (debug) qDebug() << "Retrying"; Stop++; sleep(1*Stop); goto RetryA; }
  if (err != EXIT_SUCCESS) return;
  SysPatchName->setEnabled(true);
  SysPatchName->setText(QString::fromAscii(r_buf,12));
  Patch_Name_edit->setText(SysPatchName->text());
  strncpy(state_table->patch_name, r_buf, 12);
  strncpy(state_table->patch_group, (const char *)SysPatchSelect->currentText().toAscii().data(), 12);
  state_table->patch_num = SysPatchNumber->value();
}
  
void JVlibForm::getSysPerfName() {
  // get the current active Performance name from the synth
  if (!state_table->jv_connect) return;
  int	err;
  int	Stop=0;
  unsigned char buf[8];
  char r_buf[16];
  memset(buf,0,sizeof(buf));
  buf[0] = 0x01;	// address of active_area->perf_common.name
  buf[7] = 0x0C;
  RetryA:
  if (sysex_request(buf) == EXIT_FAILURE) return;
  err = sysex_get((unsigned char *)r_buf, (char *)&name_size);
  if (err == EXIT_FAILURE) return;
  if (err==2 && Stop<MAX_RETRIES) { if (debug) qDebug() << "Retrying"; Stop++; sleep(1*Stop); goto RetryA; }
  if (err==3 && Stop<MAX_RETRIES) { if (debug) qDebug() << "Retrying"; Stop++; sleep(1*Stop); goto RetryA; }
  if (err != EXIT_SUCCESS) return;
  SysPerfName->setText(QString::fromAscii(r_buf,12));
  SysPerfName->setEnabled(true);
  PerfName_edit->setText(SysPerfName->text());
  PartsPerfName_display->setText(SysPerfName->text());
  strncpy(state_table->perf_name, r_buf, 12);
  strncpy(state_table->perf_group, (const char *)SysPerfSelect->currentText().toAscii().data(), 12);
  state_table->perf_num = SysPerfNumber->value();
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
    if (state_table->performanceTab_enable) {
      MainTabWidget->setTabEnabled(1,false);	// Performance tab
      state_table->performanceTab_enable = false;
    }
    if (state_table->patchTab_enable) {
      MainTabWidget->setTabEnabled(3,false);	// Patch tab
      state_table->patchTab_enable = false;
    }
    if (state_table->tuningTab_enable) {
      MainTabWidget->setTabEnabled(11,false);	// Tuning tab
      state_table->tuningTab_enable = false;
    }
    if (!state_table->partsTab_enable) {
      MainTabWidget->setTabEnabled(2,true);		// Parts tab
      state_table->partsTab_enable = true;
    }
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
    unsigned char buf[5];
    memset(buf,0,sizeof(buf));
    buf[3] = addr;
    buf[4] = val;
    if (sysex_update(&buf[0],5) == EXIT_FAILURE) {
      return;
    }
  }	// end jv_connect
  else  {	// System settings modified but synth not updated
    System_Sync_status->off();
  }
}
}	// end setSysSingleValue

void JVlibForm::EnableSys(bool val) {
  // called from on_System_Sync_button_clicked() after a valid port is selected and System Common is downloaded
  SysSwitchBox->setEnabled(val);
  SysPreviewBox->setEnabled(val);
  SysSourceBox->setEnabled(val);
  SysTestTone_button->setEnabled(val);
  SysPanic_button->setEnabled(val);
  SysMode_select->setEnabled(val);
  System_Sync_button->setEnabled(val);
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
  }
}	// end EnableSys
