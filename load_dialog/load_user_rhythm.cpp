// load_user_rhythm.cpp
#include "load_dialog/load_dialog.h"
#include "ui_Load_Dialog.h"
#include "JVlibForm.h"

void Load_Dialog::load_user_rhythm(int SerNum, int pn) {
  // pull rhythm and note data by SerNumber from db into QByteArray, load into User Rhythm #pn
  // sizes: common=0x0C, note[64]=0x3A
  if (pn<1 || pn>2 ) {
    printf("Invalid Rhythm number passed: %d\n", pn);
    return;	// invalid
  }
  QSqlQuery query(JVlibForm::db_mysql);
  query.prepare("select sysex from RhythmSets where SerNumber = ?");
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
  unsigned char* buf = new unsigned char[0x3A];
  memset(buf,0,sizeof(buf));
  if (ui->Load_UpdateLocal_select->isChecked()) {
    if (JVlibForm::state_table->perf_mode) // needs to go into temporary rhythm
      memcpy(&JVlibForm::active_area->active_rhythm.rhythm_common.name[0], SysEx.constData(), SysEx.size());
  }
  buf[0] = 0x10;	// addr for User Rhythms
  buf[1] = pn==1 ? 0x40 : 0x41;	// User Rhythm number to load
  memcpy((void *)&buf[4], SysEx.constData(),0x0C);  // common data
  if (JVlibForm::open_ports() == EXIT_FAILURE) return;
  this->setCursor(Qt::WaitCursor);
  usleep(20000);
  JVlibForm::sysex_update(buf, 0x0C+4);
  // load the note data
  for (int x=0;x<64;x++) {
    buf[2] = 0x23 + x;
    memcpy((void *)&buf[4], SysEx.mid(0x0C+(0x3A*x)), 0x3A);
    usleep(25000);
    JVlibForm::sysex_update(buf, 0x3A+4);
  }
  JVlibForm::close_ports();
  delete[] buf;
  query.finish();
  this->setCursor(Qt::ArrowCursor);


  
  
}	// end load_user_rhythm

