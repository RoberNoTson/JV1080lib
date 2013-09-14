// save_current_perf.cpp
#include	"save_dialog/Save_Dialog.h"
#include	"ui_Save_Dialog.h"
#include        "JVlibForm.h"
#include        <QtGui>
#include	<QtSql>

void Save_Dialog::save_current_perf() {
  int patch_sz = 0x48 + (0x81*4);
  int rhythm_sz = 0x0C + (0x3A*64);
  int perf_number, patch_number;
  // Save the current Performance data
  this->setCursor(Qt::WaitCursor);
  perf_number = db_insert_data("Performances", &JVlibForm::active_area->active_performance.perf_common.name[0], 0x40+(0x13*16));
  // Process each Part that is checked, downloading the data if needed
  QSqlQuery query(JVlibForm::db_mysql);
  // process Part 1
  if (ui->Save_PerfPart_1_select->isChecked()) {
    // download the Perf Patch data if needed
    int pn = 0;
    if (!JVlibForm::state_table->part1_sync)
      JVlibForm::getSinglePerfPatch(pn);
    // save the Part Patch data with a new Name, Perf name as comment. Pass the part number as the last parm.
    patch_number = db_insert_data("Patches", &JVlibForm::active_area->active_perf_patch[pn].patch_common.name[0], patch_sz, pn+1);
    if (patch_number<0) {
      QMessageBox::critical(this, "Save Dialog", QString("Failed to insert PerfPart data\n%1") .arg(query.lastError().text()));
      query.finish();
      this->setCursor(Qt::ArrowCursor);
      return;
    }      
    // insert/update Perf_UserPatch_ref with perf_number, patch_number for Part
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_1) values("+QString::number(perf_number)+
      ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_1 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish();
      this->setCursor(Qt::ArrowCursor);
      return;
    }
  }	// end Part 1
  // process Part 2
  if (ui->Save_PerfPart_2_select->isChecked()) {
    // download the Perf Patch data if needed
    int pn = 1;
    if (!JVlibForm::state_table->part2_sync)
      JVlibForm::getSinglePerfPatch(pn);
    patch_number = db_insert_data("Patches", &JVlibForm::active_area->active_perf_patch[pn].patch_common.name[0], patch_sz, pn+1);
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_2) values("+QString::number(perf_number)+
      ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_2 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish();
      this->setCursor(Qt::ArrowCursor);
      return;
    }
  }	// end Part 2
  // process Part 3
  if (ui->Save_PerfPart_3_select->isChecked()) {
    // download the Perf Patch data if needed
    int pn = 2;
    if (!JVlibForm::state_table->part3_sync)
      JVlibForm::getSinglePerfPatch(pn);
    patch_number = db_insert_data("Patches", &JVlibForm::active_area->active_perf_patch[pn].patch_common.name[0], patch_sz, pn+1);
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_3) values("+QString::number(perf_number)+", "+
      QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_3 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish();
      this->setCursor(Qt::ArrowCursor);
      return;
    }
  }	// end Part 3
  // process Part 4
  if (ui->Save_PerfPart_4_select->isChecked()) {
    // download the Perf Patch data if needed
    int pn = 3;
    if (!JVlibForm::state_table->part4_sync)
      JVlibForm::getSinglePerfPatch(pn);
    patch_number = db_insert_data("Patches", &JVlibForm::active_area->active_perf_patch[pn].patch_common.name[0], patch_sz, pn+1);
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_4) values("+QString::number(perf_number)+", "+
      QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_4 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish();
      this->setCursor(Qt::ArrowCursor);
      return;
    }
  }	// end Part 4
  // process Part 5
  if (ui->Save_PerfPart_5_select->isChecked()) {
    // download the Perf Patch data if needed
    int pn = 4;
    if (!JVlibForm::state_table->part5_sync)
      JVlibForm::getSinglePerfPatch(pn);
    patch_number = db_insert_data("Patches", &JVlibForm::active_area->active_perf_patch[pn].patch_common.name[0], patch_sz, pn+1);
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_5) values("+QString::number(perf_number)+", "+
      QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_5 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish();
      this->setCursor(Qt::ArrowCursor);
      return;
    }
  }	// end Part 5
  // process Part 6
  if (ui->Save_PerfPart_6_select->isChecked()) {
    // download the Perf Patch data if needed
    int pn = 5;
    if (!JVlibForm::state_table->part6_sync)
      JVlibForm::getSinglePerfPatch(pn);
    patch_number = db_insert_data("Patches", &JVlibForm::active_area->active_perf_patch[pn].patch_common.name[0], patch_sz, pn+1);
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_6) values("+QString::number(perf_number)+", "+
      QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_6 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish();
      this->setCursor(Qt::ArrowCursor);
      return;
    }
  }	// end Part 6
  // process Part 7
  if (ui->Save_PerfPart_7_select->isChecked()) {
    // download the Perf Patch data if needed
    int pn = 6;
    if (!JVlibForm::state_table->part7_sync)
      JVlibForm::getSinglePerfPatch(pn);
    patch_number = db_insert_data("Patches", &JVlibForm::active_area->active_perf_patch[pn].patch_common.name[0], patch_sz, pn+1);
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_7) values("+QString::number(perf_number)+", "+
      QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_7 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish();
      this->setCursor(Qt::ArrowCursor);
      return;
    }
  }	// end Part 7
  // process Part 8
  if (ui->Save_PerfPart_8_select->isChecked()) {
    // download the Perf Patch data if needed
    int pn = 7;
    if (!JVlibForm::state_table->part8_sync)
      JVlibForm::getSinglePerfPatch(pn);
    patch_number = db_insert_data("Patches", &JVlibForm::active_area->active_perf_patch[pn].patch_common.name[0], patch_sz, pn+1);
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_8) values("+QString::number(perf_number)+", "+
      QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_8 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish();
      this->setCursor(Qt::ArrowCursor);
      return;
    }
  }	// end Part 8
  // process Part 9
  if (ui->Save_PerfPart_9_select->isChecked()) {
    // download the Perf Patch data if needed
    int pn = 8;
    if (!JVlibForm::state_table->part9_sync)
      JVlibForm::getSinglePerfPatch(pn);
    patch_number = db_insert_data("Patches", &JVlibForm::active_area->active_perf_patch[pn].patch_common.name[0], patch_sz, pn+1);
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_9) values("+QString::number(perf_number)+
      ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_9 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish();
      this->setCursor(Qt::ArrowCursor);
      return;
    }
  }	// end Part 9
  // process Part 10
  if (ui->Save_PerfPart_10_select->isChecked()) {
    // download the Perf Rhythm data if needed
    int pn = 9;
    if (!JVlibForm::state_table->rhythm_sync)
      JVlibForm::getActiveRhythm();
    patch_number = db_insert_data("RhythmSets", &JVlibForm::active_area->active_rhythm.rhythm_common.name[0], rhythm_sz, pn+1);
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_10) values("+QString::number(perf_number)+
      ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_10 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish();
      this->setCursor(Qt::ArrowCursor);
      return;
    }
  }	// end Part 10
  // process Part 11
  if (ui->Save_PerfPart_11_select->isChecked()) {
    // download the Perf Patch data if needed
    int pn = 10;
    if (!JVlibForm::state_table->part11_sync)
      JVlibForm::getSinglePerfPatch(pn);
    patch_number = db_insert_data("Patches", &JVlibForm::active_area->active_perf_patch[pn].patch_common.name[0], patch_sz, pn+1);
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_11) values("+QString::number(perf_number)+
      ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_11 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish();
      this->setCursor(Qt::ArrowCursor);
      return;
    }
  }	// end Part 11
    // process Part 12
  if (ui->Save_PerfPart_12_select->isChecked()) {
    // download the Perf Patch data if needed
    int pn = 11;
    if (!JVlibForm::state_table->part12_sync)
      JVlibForm::getSinglePerfPatch(pn);
    patch_number = db_insert_data("Patches", &JVlibForm::active_area->active_perf_patch[pn].patch_common.name[0], patch_sz, pn+1);
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_12) values("+QString::number(perf_number)+
      ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_12 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish();
      this->setCursor(Qt::ArrowCursor);
      return;
    }
  }	// end Part 12
    // process Part 13
  if (ui->Save_PerfPart_13_select->isChecked()) {
    // download the Perf Patch data if needed
    int pn = 12;
    if (!JVlibForm::state_table->part13_sync)
      JVlibForm::getSinglePerfPatch(pn);
    patch_number = db_insert_data("Patches", &JVlibForm::active_area->active_perf_patch[pn].patch_common.name[0], patch_sz, pn+1);
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_13) values("+QString::number(perf_number)+
      ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_13 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish();
      this->setCursor(Qt::ArrowCursor);
      return;
    }
  }	// end Part 13
    // process Part 1
  if (ui->Save_PerfPart_14_select->isChecked()) {
    // download the Perf Patch data if needed
    int pn = 13;
    if (!JVlibForm::state_table->part14_sync)
      JVlibForm::getSinglePerfPatch(pn);
    patch_number = db_insert_data("Patches", &JVlibForm::active_area->active_perf_patch[pn].patch_common.name[0], patch_sz, pn+1);
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_14) values("+QString::number(perf_number)+
      ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_14 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish();
      this->setCursor(Qt::ArrowCursor);
      return;
    }
  }	// end Part 14
  // process Part 15
  if (ui->Save_PerfPart_15_select->isChecked()) {
    // download the Perf Patch data if needed
    int pn = 14;
    if (!JVlibForm::state_table->part15_sync)
      JVlibForm::getSinglePerfPatch(pn);
    patch_number = db_insert_data("Patches", &JVlibForm::active_area->active_perf_patch[pn].patch_common.name[0], patch_sz, pn+1);
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_15) values("+QString::number(perf_number)+
      ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_15 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish();
      this->setCursor(Qt::ArrowCursor);
      return;
    }
  }	// end Part 15
    // process Part 16
  if (ui->Save_PerfPart_16_select->isChecked()) {
    // download the Perf Patch data if needed
    int pn = 15;
    if (!JVlibForm::state_table->part1_sync)
      JVlibForm::getSinglePerfPatch(pn);
    patch_number = db_insert_data("Patches", &JVlibForm::active_area->active_perf_patch[pn].patch_common.name[0], patch_sz, pn+1);
    QString buf = "INSERT INTO Perf_UserPatch_ref (Performance, Part_16) values("+QString::number(perf_number)+
      ", "+QString::number(patch_number)+") ON DUPLICATE KEY UPDATE Part_16 = "+QString::number(patch_number);
    if (query.exec(buf) == false) {
      QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
      query.finish();
      this->setCursor(Qt::ArrowCursor);
      return;
    }
  }	// end Part 16
  query.finish();
  this->setCursor(Qt::ArrowCursor);
  return;
}	// end save_current_perf
