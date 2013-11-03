// load_user_patch.cpp
#include "load_dialog/load_dialog.h"
#include "ui_Load_Dialog.h"
#include "JVlibForm.h"

void Load_Dialog::load_user_patch(int SerNum, int pn) {
  // pull patch and tone data by SerNumber from db into QByteArray, load into User Patch #pn
  // sizes: common=0x48, tone[4]=0x81
  if (pn<1 || pn>128 ) {
    printf("Invalid Patch number passed: %d\n", pn);
    return;	// invalid
  }
  QSqlQuery query(JVlibForm::db_mysql);
  query.prepare("select sysex from Patches where SerNumber = ?");
  query.bindValue(0, SerNum);
  if (query.exec() == false) {
    puts("query error - failed");
    query.finish();
    return;
  }
  if (query.size() == 0) {	// this is an error
    puts("query error - empty");
    query.finish();
    return;
  }
  query.next();
  QByteArray SysEx;
  SysEx = query.value(0).toByteArray();
  unsigned char* buf = new unsigned char[256];
  memset(buf,0,sizeof(buf));
  if (ui->Load_UpdateLocal_select->isChecked()) {
//    if (JVlibForm::state_table->perf_mode) // needs to go into temporary patch[16]
//      memcpy(&JVlibForm::active_area->active_perf_patch[pn-1].patch_common.name[0], SysEx.constData(), SysEx.size());
    if (JVlibForm::state_table->patch_mode) 
      memcpy(&JVlibForm::active_area->active_patch_patch.patch_common.name[0], SysEx.constData(), SysEx.size());
  }
  buf[0] = 0x11;	// addr for User Patches
  buf[1] = pn-1;	// User Patch number to load
  memcpy((void *)&buf[4], SysEx.constData(),0x48);  // patch common data
  if (JVlibForm::open_ports() == EXIT_FAILURE) return;
  this->setCursor(Qt::WaitCursor);
  usleep(20000);
  JVlibForm::sysex_update(buf, 0x48+4);
  // load the tone data
  for (int x=0;x<4;x++) {
    buf[2] = 0x10 + (x*2);
    memcpy((void *)&buf[4], SysEx.mid(0x48+(0x81*x)), 0x81);
    usleep(25000);
    JVlibForm::sysex_update(buf, 0x81+4);
  }
  JVlibForm::close_ports();
  delete[] buf;
  query.finish();
  this->setCursor(Qt::ArrowCursor);
}	// end load_user_patch
