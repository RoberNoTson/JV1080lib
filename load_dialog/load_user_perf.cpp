// load_user_perf.cpp
#include "load_dialog/load_dialog.h"
#include "ui_Load_Dialog.h"
#include "JVlibForm.h"

void Load_Dialog::load_user_perf() {
  // pull data from db into QByteArray
  int SerNum = (ui->Load_Name_select->itemData(ui->Load_Name_select->currentIndex())).toInt();
  QSqlQuery query(JVlibForm::db_mysql);
  query.prepare("select sysex from Performances where SerNumber = ?");
  query.bindValue(0, SerNum);
  if (query.exec() == false) {
    puts("query error");
    query.finish();
    return;
  }
  if (query.size() == 0) {
    query.finish();
    return;
  }
  query.next();
  QByteArray SysEx;
  SysEx = query.value(0).toByteArray();
  unsigned char* buf = new unsigned char[256];
  memset(buf,0,sizeof(buf));
  if (ui->Load_UpdateLocal_select->isChecked()) {
    memcpy(&JVlibForm::active_area->active_performance.perf_common.name[0], SysEx.constData(), SysEx.size());
  }
  buf[0] = 0x10;	// addr for User Performances
  buf[1] = ui->Load_PerfNumber_select->value() - 1;    // addr for Perf User
  memcpy((void *)&buf[4], SysEx.constData(),0x40);  // perf common data
  if (JVlibForm::open_ports() == EXIT_FAILURE) return;
  this->setCursor(Qt::WaitCursor);
  usleep(20000);
  JVlibForm::sysex_update(buf, 0x40+4);
  // load the Perf Part data
  for (int x=0;x<16;x++) {
    buf[2] = 0x10 + x;
    memcpy((void *)&buf[4], SysEx.mid(0x40+(0x13*x)), 0x13);
  usleep(25000);
    JVlibForm::sysex_update(buf, 0x13+4);
  }
  JVlibForm::close_ports();
  // load any requested User Patches related to this Performance
  // Process Part 1
  if (ui->Load_PerfPart_1_select->isChecked()) {
    query.prepare("select Part_1 from Perf_UserPatch_ref where Performance = ?");
    query.bindValue(0, SerNum);
    if (query.exec() == false) {
      puts("query error - failed");
      query.finish();
      return;
    }
    query.next();    
    if (query.size() == 0) {	// this indicates an error, since there should be a value returned
      puts("query error - empty");
      query.finish();
      return;
    }
    int PartSN = query.value(0).toInt();
    int patch_number = ui->Load_Part_1_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    printf("Loading User Patch SerNumber %d to User Patch # %d\n", PartSN, patch_number);    
    if (PartSN>0 && patch_number>0 && patch_number<129) load_user_patch(PartSN, patch_number);
  }	// end Part 1
  
  // Process Part 2
  if (ui->Load_PerfPart_2_select->isChecked()) {
    query.prepare("select Part_2 from Perf_UserPatch_ref where Performance = ?");
    query.bindValue(0, SerNum);
    if (query.exec() == false) {
      puts("query error - failed");
      query.finish();
      return;
    }
    query.next();    
    if (query.size() == 0) {	// this indicates an error, since there should be a value returned
      puts("query error - empty");
      query.finish();
      return;
    }
    int PartSN = query.value(0).toInt();
    int patch_number = ui->Load_Part_2_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    printf("Loading User Patch SerNumber %d to User Patch # %d\n", PartSN, patch_number);    
    if (PartSN>0 && patch_number>0 && patch_number<129) load_user_patch(PartSN, patch_number);
  }	// end Part 2
  
  // Process Part 3
  if (ui->Load_PerfPart_3_select->isChecked()) {
    query.prepare("select Part_3 from Perf_UserPatch_ref where Performance = ?");
    query.bindValue(0, SerNum);
    if (query.exec() == false) {
      puts("query error - failed");
      query.finish();
      return;
    }
    query.next();    
    if (query.size() == 0) {	// this indicates an error, since there should be a value returned
      puts("query error - empty");
      query.finish();
      return;
    }
    int PartSN = query.value(0).toInt();
    int patch_number = ui->Load_Part_3_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    printf("Loading User Patch SerNumber %d to User Patch # %d\n", PartSN, patch_number);    
    if (PartSN>0 && patch_number>0 && patch_number<129) load_user_patch(PartSN, patch_number);
  }	// end Part 3
  
  // Process Part 4
  if (ui->Load_PerfPart_4_select->isChecked()) {
    query.prepare("select Part_4 from Perf_UserPatch_ref where Performance = ?");
    query.bindValue(0, SerNum);
    if (query.exec() == false) {
      puts("query error - failed");
      query.finish();
      return;
    }
    query.next();    
    if (query.size() == 0) {	// this indicates an error, since there should be a value returned
      puts("query error - empty");
      query.finish();
      return;
    }
    int PartSN = query.value(0).toInt();
    int patch_number = ui->Load_Part_4_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    printf("Loading User Patch SerNumber %d to User Patch # %d\n", PartSN, patch_number);    
    if (PartSN>0 && patch_number>0 && patch_number<129) load_user_patch(PartSN, patch_number);
  }	// end Part 4
  
  // Process Part 5
  if (ui->Load_PerfPart_5_select->isChecked()) {
    query.prepare("select Part_5 from Perf_UserPatch_ref where Performance = ?");
    query.bindValue(0, SerNum);
    if (query.exec() == false) {
      puts("query error - failed");
      query.finish();
      return;
    }
    query.next();    
    if (query.size() == 0) {	// this indicates an error, since there should be a value returned
      puts("query error - empty");
      query.finish();
      return;
    }
    int PartSN = query.value(0).toInt();
    int patch_number = ui->Load_Part_5_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    printf("Loading User Patch SerNumber %d to User Patch # %d\n", PartSN, patch_number);    
    if (PartSN>0 && patch_number>0 && patch_number<129) load_user_patch(PartSN, patch_number);
  }	// end Part 5
  
  // Process Part 6
  if (ui->Load_PerfPart_6_select->isChecked()) {
    query.prepare("select Part_6 from Perf_UserPatch_ref where Performance = ?");
    query.bindValue(0, SerNum);
    if (query.exec() == false) {
      puts("query error - failed");
      query.finish();
      return;
    }
    query.next();    
    if (query.size() == 0) {	// this indicates an error, since there should be a value returned
      puts("query error - empty");
      query.finish();
      return;
    }
    int PartSN = query.value(0).toInt();
    int patch_number = ui->Load_Part_6_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    printf("Loading User Patch SerNumber %d to User Patch # %d\n", PartSN, patch_number);    
    if (PartSN>0 && patch_number>0 && patch_number<129) load_user_patch(PartSN, patch_number);
  }	// end Part 6
  
  // Process Part 7
  if (ui->Load_PerfPart_7_select->isChecked()) {
    query.prepare("select Part_7 from Perf_UserPatch_ref where Performance = ?");
    query.bindValue(0, SerNum);
    if (query.exec() == false) {
      puts("query error - failed");
      query.finish();
      return;
    }
    query.next();    
    if (query.size() == 0) {	// this indicates an error, since there should be a value returned
      puts("query error - empty");
      query.finish();
      return;
    }
    int PartSN = query.value(0).toInt();
    int patch_number = ui->Load_Part_7_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    printf("Loading User Patch SerNumber %d to User Patch # %d\n", PartSN, patch_number);    
    if (PartSN>0 && patch_number>0 && patch_number<129) load_user_patch(PartSN, patch_number);
  }	// end Part 7
  
  // Process Part 8
  if (ui->Load_PerfPart_8_select->isChecked()) {
    query.prepare("select Part_8 from Perf_UserPatch_ref where Performance = ?");
    query.bindValue(0, SerNum);
    if (query.exec() == false) {
      puts("query error - failed");
      query.finish();
      return;
    }
    query.next();    
    if (query.size() == 0) {	// this indicates an error, since there should be a value returned
      puts("query error - empty");
      query.finish();
      return;
    }
    int PartSN = query.value(0).toInt();
    int patch_number = ui->Load_Part_8_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    printf("Loading User Patch SerNumber %d to User Patch # %d\n", PartSN, patch_number);    
    if (PartSN>0 && patch_number>0 && patch_number<129) load_user_patch(PartSN, patch_number);
  }	// end Part 8
  
  // Process Part 9
  if (ui->Load_PerfPart_9_select->isChecked()) {
    query.prepare("select Part_9 from Perf_UserPatch_ref where Performance = ?");
    query.bindValue(0, SerNum);
    if (query.exec() == false) {
      puts("query error - failed");
      query.finish();
      return;
    }
    query.next();    
    if (query.size() == 0) {	// this indicates an error, since there should be a value returned
      puts("query error - empty");
      query.finish();
      return;
    }
    int PartSN = query.value(0).toInt();
    int patch_number = ui->Load_Part_9_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    printf("Loading User Patch SerNumber %d to User Patch # %d\n", PartSN, patch_number);    
    if (PartSN>0 && patch_number>0 && patch_number<129) load_user_patch(PartSN, patch_number);
  }	// end Part 9
  
  // Process Part 11
  if (ui->Load_PerfPart_11_select->isChecked()) {
    query.prepare("select Part_11 from Perf_UserPatch_ref where Performance = ?");
    query.bindValue(0, SerNum);
    if (query.exec() == false) {
      puts("query error - failed");
      query.finish();
      return;
    }
    query.next();    
    if (query.size() == 0) {	// this indicates an error, since there should be a value returned
      puts("query error - empty");
      query.finish();
      return;
    }
    int PartSN = query.value(0).toInt();
    int patch_number = ui->Load_Part_11_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    printf("Loading User Patch SerNumber %d to User Patch # %d\n", PartSN, patch_number);    
    if (PartSN>0 && patch_number>0 && patch_number<129) load_user_patch(PartSN, patch_number);
  }	// end Part 11
  
  // Process Part 12
  if (ui->Load_PerfPart_12_select->isChecked()) {
    query.prepare("select Part_12 from Perf_UserPatch_ref where Performance = ?");
    query.bindValue(0, SerNum);
    if (query.exec() == false) {
      puts("query error - failed");
      query.finish();
      return;
    }
    query.next();    
    if (query.size() == 0) {	// this indicates an error, since there should be a value returned
      puts("query error - empty");
      query.finish();
      return;
    }
    int PartSN = query.value(0).toInt();
    int patch_number = ui->Load_Part_12_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    printf("Loading User Patch SerNumber %d to User Patch # %d\n", PartSN, patch_number);    
    if (PartSN>0 && patch_number>0 && patch_number<129) load_user_patch(PartSN, patch_number);
  }	// end Part 12
  
  // Process Part 13
  if (ui->Load_PerfPart_13_select->isChecked()) {
    query.prepare("select Part_13 from Perf_UserPatch_ref where Performance = ?");
    query.bindValue(0, SerNum);
    if (query.exec() == false) {
      puts("query error - failed");
      query.finish();
      return;
    }
    query.next();    
    if (query.size() == 0) {	// this indicates an error, since there should be a value returned
      puts("query error - empty");
      query.finish();
      return;
    }
    int PartSN = query.value(0).toInt();
    int patch_number = ui->Load_Part_13_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    printf("Loading User Patch SerNumber %d to User Patch # %d\n", PartSN, patch_number);    
    if (PartSN>0 && patch_number>0 && patch_number<129) load_user_patch(PartSN, patch_number);
  }	// end Part 13
  
  // Process Part 14
  if (ui->Load_PerfPart_14_select->isChecked()) {
    query.prepare("select Part_14 from Perf_UserPatch_ref where Performance = ?");
    query.bindValue(0, SerNum);
    if (query.exec() == false) {
      puts("query error - failed");
      query.finish();
      return;
    }
    query.next();    
    if (query.size() == 0) {	// this indicates an error, since there should be a value returned
      puts("query error - empty");
      query.finish();
      return;
    }
    int PartSN = query.value(0).toInt();
    int patch_number = ui->Load_Part_14_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    printf("Loading User Patch SerNumber %d to User Patch # %d\n", PartSN, patch_number);    
    if (PartSN>0 && patch_number>0 && patch_number<129) load_user_patch(PartSN, patch_number);
  }	// end Part 14
  
  // Process Part 15
  if (ui->Load_PerfPart_15_select->isChecked()) {
    query.prepare("select Part_15 from Perf_UserPatch_ref where Performance = ?");
    query.bindValue(0, SerNum);
    if (query.exec() == false) {
      puts("query error - failed");
      query.finish();
      return;
    }
    query.next();    
    if (query.size() == 0) {	// this indicates an error, since there should be a value returned
      puts("query error - empty");
      query.finish();
      return;
    }
    int PartSN = query.value(0).toInt();
    int patch_number = ui->Load_Part_15_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    printf("Loading User Patch SerNumber %d to User Patch # %d\n", PartSN, patch_number);    
    if (PartSN>0 && patch_number>0 && patch_number<129) load_user_patch(PartSN, patch_number);
  }	// end Part 15
  
  // Process Part 16
  if (ui->Load_PerfPart_16_select->isChecked()) {
    query.prepare("select Part_16 from Perf_UserPatch_ref where Performance = ?");
    query.bindValue(0, SerNum);
    if (query.exec() == false) {
      puts("query error - failed");
      query.finish();
      return;
    }
    query.next();    
    if (query.size() == 0) {	// this indicates an error, since there should be a value returned
      puts("query error - empty");
      query.finish();
      return;
    }
    int PartSN = query.value(0).toInt();
    int patch_number = ui->Load_Part_16_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    printf("Loading User Patch SerNumber %d to User Patch # %d\n", PartSN, patch_number);    
    if (PartSN>0 && patch_number>0 && patch_number<129) load_user_patch(PartSN, patch_number);
  }	// end Part 16
  
  // Process Part 10
  if (ui->Load_PerfPart_10_select->isChecked()) {
    query.prepare("select Part_10 from Perf_UserPatch_ref where Performance = ?");
    query.bindValue(0, SerNum);
    if (query.exec() == false) {
      puts("query error - failed");
      query.finish();
      return;
    }
    query.next();    
    if (query.size() == 0) {	// this indicates an error, since there should be a value returned
      puts("query error - empty");
      query.finish();
      return;
    }
    int PartSN = query.value(0).toInt();
    int patch_number = ui->Load_Part_10_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    printf("Loading User Rhythm SerNumber %d to User Rhythm # %d\n", PartSN, patch_number);    
    if (PartSN>0 && patch_number<3 && patch_number>0) load_user_rhythm(PartSN, patch_number);
  }	// end Part 10
  
  this->setCursor(Qt::ArrowCursor);
  delete[] buf;
  query.finish();
}	// end load_user_perf
