// save_user_perf.cpp
// called from Save_Dialog
// save a User performance and the related User Patches, if any, up to 16

#include	"save_dialog/Save_Dialog.h"
#include	"ui_Save_Dialog.h"
#include        "JVlibForm.h"
#include        <QtGui>
#include	<QtSql>

int Save_Dialog::SaveUserPerf() {
  int err;
  int Stop=0;
  int perf_number;
//  int patch_sz = 0x48 + (0x81*4);
//  int rhythm_sz = 0x0C + (0x3A*64);
  unsigned char  buf[8];
  char user1_perf_common[]={ 0x10,0x00,0x00,0x00 };
  char perf_common_size[] = { 0x00,0x00,0x00,0x40 };
  char perf_part_size[] = { 0x00,0x00,0x00,0x13 };
  struct PERFORMANCE temp_r;
  
  // get the Performance common and Part data from JV
  this->setCursor(Qt::WaitCursor);
  memset(buf,0,sizeof(buf));
  buf[0] = user1_perf_common[0];
  buf[1] = ui->Save_PerfNumber_select->value() - 1;
  memcpy(buf+4,perf_common_size,4);
  // open the selected midi port
  if (JVlibForm::open_ports() == EXIT_FAILURE) {this->setCursor(Qt::ArrowCursor); return false; }
  RetryG:
  if (JVlibForm::sysex_request(buf,8) == EXIT_FAILURE) { JVlibForm::close_ports(); this->setCursor(Qt::ArrowCursor); return false; }
  err = JVlibForm::sysex_get((unsigned char *)&temp_r.perf_common.name[0], (char *)perf_common_size);
  if (err == EXIT_FAILURE) { JVlibForm::close_ports(); this->setCursor(Qt::ArrowCursor); return false; }
  if (err==2 && Stop<MAX_RETRIES) {  Stop++; usleep(20000*Stop); goto RetryG; }
  if (err==3 && Stop<MAX_RETRIES) {  Stop++; usleep(20000*Stop); goto RetryG; }
  if (err != EXIT_SUCCESS) { JVlibForm::close_ports(); this->setCursor(Qt::ArrowCursor); return false; }
  Stop=0;
  // get Parts
  memcpy(buf+4,perf_part_size,4);
  for (int x=0;x<16;x++) {
    usleep(200000);
    buf[2] = 0x10+x;
    RetryB:
    if (JVlibForm::sysex_request(buf,8) == EXIT_FAILURE) { JVlibForm::close_ports(); this->setCursor(Qt::ArrowCursor); return false; }
    err = JVlibForm::sysex_get((unsigned char *)&temp_r.perf_part[x].MIDI_receive, (char *)perf_part_size);
    if (err == EXIT_FAILURE) { JVlibForm::close_ports(); this->setCursor(Qt::ArrowCursor); return false; }
    if (err==2 && Stop<MAX_RETRIES) { Stop++; sleep(1*Stop); goto RetryB; }
    if (err==3 && Stop<MAX_RETRIES) { Stop++; sleep(1*Stop); goto RetryB; }
    if (err != EXIT_SUCCESS) { JVlibForm::close_ports(); this->setCursor(Qt::ArrowCursor); return false; }
    Stop=0;
  } // end FOR
  JVlibForm::close_ports();
  perf_number = db_insert_data(QString::fromAscii("Performances"), (char *)&temp_r, 0x40+(0x13*16));
  
  // save the related User Patches that are checked
  QSqlQuery query(JVlibForm::db_mysql);
  
  // process Part 1
  if (ui->Save_PerfPart_1_select->isChecked()) {
    int pn = ui->Save_Part_1_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    int patch_number = 0;	// reset value to 0
    if (pn) patch_number = SaveUserPatch(pn,1);	// parms are UserPatch #, Part #
    if (!patch_number) { query.finish(); this->setCursor(Qt::ArrowCursor); return false; }
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_1) values("+QString::number(perf_number)+
    ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_1 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish(); this->setCursor(Qt::ArrowCursor); return false;
    }
  }	// end Part 1
  // process Part 2
  if (ui->Save_PerfPart_2_select->isChecked()) {
    int pn = ui->Save_Part_2_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    int patch_number = 0;
    if (pn) patch_number = SaveUserPatch(pn,2);
    if (!patch_number) { query.finish(); this->setCursor(Qt::ArrowCursor); return false; }
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_2) values("+QString::number(perf_number)+
    ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_2 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish(); this->setCursor(Qt::ArrowCursor); return false;
    }
  }	// end Part 2
  // process Part 3
  if (ui->Save_PerfPart_3_select->isChecked()) {
    int pn = ui->Save_Part_3_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    int patch_number = 0;	// reset value to 0
    if (pn) patch_number = SaveUserPatch(pn,3);	// parms are UserPatch #, Part #
    if (!patch_number) { query.finish(); this->setCursor(Qt::ArrowCursor); return false; }
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_3) values("+QString::number(perf_number)+
    ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_3 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish(); this->setCursor(Qt::ArrowCursor); return false;
    }
  }	// end Part 3
  // process Part 4
  if (ui->Save_PerfPart_4_select->isChecked()) {
    int pn = ui->Save_Part_4_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    int patch_number = 0;	// reset value to 0
    if (pn) patch_number = SaveUserPatch(pn,4);	// parms are UserPatch #, Part #
    if (!patch_number) { query.finish(); this->setCursor(Qt::ArrowCursor); return false; }
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_4) values("+QString::number(perf_number)+
    ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_4 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish(); this->setCursor(Qt::ArrowCursor); return false;
    }
  }	// end Part 4
  // process Part 5
  if (ui->Save_PerfPart_5_select->isChecked()) {
    int pn = ui->Save_Part_5_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    int patch_number = 0;	// reset value to 0
    if (pn) patch_number = SaveUserPatch(pn,5);	// parms are UserPatch #, Part #
    if (!patch_number) { query.finish(); this->setCursor(Qt::ArrowCursor); return false; }
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_5) values("+QString::number(perf_number)+
    ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_5 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish(); this->setCursor(Qt::ArrowCursor); return false;
    }
  }	// end Part 5
  // process Part 6
  if (ui->Save_PerfPart_6_select->isChecked()) {
    int pn = ui->Save_Part_6_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    int patch_number = 0;	// reset value to 0
    if (pn) patch_number = SaveUserPatch(pn,6);	// parms are UserPatch #, Part #
    if (!patch_number) { query.finish(); this->setCursor(Qt::ArrowCursor); return false; }
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_6) values("+QString::number(perf_number)+
    ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_6 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish(); this->setCursor(Qt::ArrowCursor); return false;
    }
  }	// end Part 6
  // process Part 7
  if (ui->Save_PerfPart_7_select->isChecked()) {
    int pn = ui->Save_Part_7_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    int patch_number = 0;	// reset value to 0
    if (pn) patch_number = SaveUserPatch(pn,7);	// parms are UserPatch #, Part #
    if (!patch_number) { query.finish(); this->setCursor(Qt::ArrowCursor); return false; }
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_7) values("+QString::number(perf_number)+
    ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_7 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish(); this->setCursor(Qt::ArrowCursor); return false;
    }
  }	// end Part 7
  // process Part 8
  if (ui->Save_PerfPart_8_select->isChecked()) {
    int pn = ui->Save_Part_8_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    int patch_number = 0;	// reset value to 0
    if (pn) patch_number = SaveUserPatch(pn,8);	// parms are UserPatch #, Part #
    if (!patch_number) { query.finish(); this->setCursor(Qt::ArrowCursor); return false; }
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_8) values("+QString::number(perf_number)+
    ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_8 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish(); this->setCursor(Qt::ArrowCursor); return false;
    }
  }	// end Part 8
  // process Part 9
  if (ui->Save_PerfPart_9_select->isChecked()) {
    int pn = ui->Save_Part_9_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    int patch_number = 0;	// reset value to 0
    if (pn) patch_number = SaveUserPatch(pn,9);	// parms are UserPatch #, Part #
    if (!patch_number) { query.finish(); this->setCursor(Qt::ArrowCursor); return false; }
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_9) values("+QString::number(perf_number)+
    ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_9 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish(); this->setCursor(Qt::ArrowCursor); return false;
    }
  }	// end Part 9
  // process Part 11
  if (ui->Save_PerfPart_11_select->isChecked()) {
    int pn = ui->Save_Part_11_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    int patch_number = 0;	// reset value to 0
    if (pn) patch_number = SaveUserPatch(pn,11);	// parms are UserPatch #, Part #
    if (!patch_number) { query.finish(); this->setCursor(Qt::ArrowCursor); return false; }
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_11) values("+QString::number(perf_number)+
    ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_11 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish(); this->setCursor(Qt::ArrowCursor); return false;
    }
  }	// end Part 11
  // process Part 12
  if (ui->Save_PerfPart_12_select->isChecked()) {
    int pn = ui->Save_Part_12_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    int patch_number = 0;	// reset value to 0
    if (pn) patch_number = SaveUserPatch(pn,12);	// parms are UserPatch #, Part #
    if (!patch_number) { query.finish(); this->setCursor(Qt::ArrowCursor); return false; }
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_12) values("+QString::number(perf_number)+
    ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_12 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish(); this->setCursor(Qt::ArrowCursor); return false;
    }
  }	// end Part 12
  // process Part 13
  if (ui->Save_PerfPart_13_select->isChecked()) {
    int pn = ui->Save_Part_13_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    int patch_number = 0;	// reset value to 0
    if (pn) patch_number = SaveUserPatch(pn,13);	// parms are UserPatch #, Part #
    if (!patch_number) { query.finish(); this->setCursor(Qt::ArrowCursor); return false; }
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_13) values("+QString::number(perf_number)+
    ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_13 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish(); this->setCursor(Qt::ArrowCursor); return false;
    }
  }	// end Part 13
  // process Part 14
  if (ui->Save_PerfPart_14_select->isChecked()) {
    int pn = ui->Save_Part_14_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    int patch_number = 0;	// reset value to 0
    if (pn) patch_number = SaveUserPatch(pn,14);	// parms are UserPatch #, Part #
    if (!patch_number) { query.finish(); this->setCursor(Qt::ArrowCursor); return false; }
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_14) values("+QString::number(perf_number)+
    ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_14 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish(); this->setCursor(Qt::ArrowCursor); return false;
    }
  }	// end Part 14
  // process Part 15
  if (ui->Save_PerfPart_15_select->isChecked()) {
    int pn = ui->Save_Part_15_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    int patch_number = 0;	// reset value to 0
    if (pn) patch_number = SaveUserPatch(pn,15);	// parms are UserPatch #, Part #
    if (!patch_number) { query.finish(); this->setCursor(Qt::ArrowCursor); return false; }
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_15) values("+QString::number(perf_number)+
    ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_15 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish(); this->setCursor(Qt::ArrowCursor); return false;
    }
  }	// end Part 15
  // process Part 16
  if (ui->Save_PerfPart_16_select->isChecked()) {
    int pn = ui->Save_Part_16_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    int patch_number = 0;	// reset value to 0
    if (pn) patch_number = SaveUserPatch(pn,16);	// parms are UserPatch #, Part #
    if (!patch_number) { query.finish(); this->setCursor(Qt::ArrowCursor); return false; }
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_16) values("+QString::number(perf_number)+
    ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_16 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish(); this->setCursor(Qt::ArrowCursor); return false;
    }
  }	// end Part 16
  // process Part 10 - Rhythm Set
  if (ui->Save_PerfPart_10_select->isChecked()) {
    int pn = ui->Save_Part_10_data->text().section(' ',1,1,QString::SectionSkipEmpty).toInt();
    int patch_number = 0;	// reset value to 0
    if (pn) patch_number = SaveUserRhythm(pn,10);
    if (!patch_number) { query.finish(); this->setCursor(Qt::ArrowCursor); return false; }
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_10) values("+QString::number(perf_number)+
    ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_10 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish(); this->setCursor(Qt::ArrowCursor); return false;
    }    
  }	// end Part 10
  
  query.finish();
  this->setCursor(Qt::ArrowCursor);
  return true;
}
