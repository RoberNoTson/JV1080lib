// load_dialog_slots.cpp
// Functions:
/* on_Load_buttonBox_accepted
 * on_Load_buttonBox_rejected
 * on_Load_buttonBox_helpRequested
 * on_Load_CurrentPerformance_button_toggled
 * on_Load_CurrentPatch_button_clicked
 * on_Load_CurrentRhythm_button_clicked
 * on_Load_CurrentTuning_button_clicked
 * on_Load_System_button_clicked
 * on_Load_UserPerformance_button_toggled
 * on_Load_UserPatch_button_clicked
 * on_Load_UserRhythm_button_clicked
 * on_Load_LoadDump_button_clicked
 * on_Load_PerfPart_All_select_clicked
 * on_Load_Name_select_currentIndexChanged
 */

#include "load_dialog/load_dialog.h"
#include "ui_Load_Dialog.h"
#include "JVlibForm.h"
#include <QtGui>
#include <QtSql>

const char* Load_Dialog::DumpsQuery = "select name, date, comment, SerNumber from Dumps where name like \"Full%\" order by date";
const char* Load_Dialog::SystemQuery = "select name, date, comment, SerNumber from Dumps where name like \"Sys%\" order by date";
const char* Load_Dialog::PatchQuery = "select name, date, comment, SerNumber from Patches order by date";
const char* Load_Dialog::PerfQuery = "select name, date, comment, SerNumber from Performances order by date";
const char* Load_Dialog::RhythmQuery = "select name, date, comment, SerNumber from RhythmSets order by date";
const char* Load_Dialog::TuningQuery = "select name, date, comment, SerNumber from Tuning order by date";

void Load_Dialog::on_Load_buttonBox_accepted()
{

    this->close();
}

void Load_Dialog::on_Load_buttonBox_rejected()
{
    this->close();
}

void Load_Dialog::on_Load_buttonBox_helpRequested()
{
    QMessageBox::critical(this, "Load Dialog", "Help not yet available for this function");
}


void Load_Dialog::on_Load_CurrentPerformance_button_toggled(bool checked)
{
  clearPartLabels();
  ui->Load_PerfPart_All_select->setEnabled(checked);
  ui->Load_PerfPart_box->setEnabled(checked);
  if (!checked) return;
  ui->Load_UpdateLocal_select->setChecked(true);
  ui->Load_PerfPart_All_select->setEnabled(false);
  if (!fill_Data(PerfQuery))
    QMessageBox::critical(this, "Load_Dialog", "Unable to load current Perf data");
  on_Load_Name_select_currentIndexChanged(ui->Load_Name_select->currentIndex());   
  
}	// end on_Load_CurrentPerformance_button_clicked

void Load_Dialog::on_Load_CurrentPatch_button_clicked(bool checked)
{
  if (!checked) return;
  ui->Load_UpdateLocal_select->setChecked(true);
  if (!fill_Data(PatchQuery))
    QMessageBox::critical(this, "Load_Dialog", "Unable to load current Patch data");
}

void Load_Dialog::on_Load_CurrentRhythm_button_clicked(bool checked)
{
  if (!checked) return;
  ui->Load_UpdateLocal_select->setChecked(true);
  if (!fill_Data(RhythmQuery))
    QMessageBox::critical(this, "Load_Dialog", "Unable to load current Rhythm data");
}

void Load_Dialog::on_Load_CurrentTuning_button_clicked(bool checked)
{
  if (checked) {
    if (!fill_Data(TuningQuery))
      QMessageBox::critical(this, "Load_Dialog", "Unable to load current Tuning data");
  }
}

void Load_Dialog::on_Load_System_button_clicked(bool checked)
{
  if (!checked) return;
  ui->Load_UpdateLocal_select->setChecked(true);
  if (!fill_Data(SystemQuery))
    QMessageBox::critical(this, "Load_Dialog", "Unable to load System data");
}

void Load_Dialog::on_Load_UserPerformance_button_toggled(bool checked)
{
  if (!checked) return;
  ui->Load_UpdateLocal_select->setChecked(false);
  if (!fill_Data(PerfQuery))
    QMessageBox::critical(this, "Load_Dialog", "Unable to load User Perf data");
}

void Load_Dialog::on_Load_UserPatch_button_clicked(bool checked)
{
  if (!checked) return;
  ui->Load_UpdateLocal_select->setChecked(false);
  if (!fill_Data(PatchQuery))
    QMessageBox::critical(this, "Load_Dialog", "Unable to load User Patch data");
}

void Load_Dialog::on_Load_UserRhythm_button_clicked(bool checked)
{
  if (!checked) return;
  ui->Load_UpdateLocal_select->setChecked(false);
  if (!fill_Data(RhythmQuery))
    QMessageBox::critical(this, "Load_Dialog", "Unable to load User Rhythm data");
}

void Load_Dialog::on_Load_LoadDump_button_clicked(bool checked)
{
  if (!checked) return;
  ui->Load_UpdateLocal_select->setChecked(false);
  if (!fill_Data(DumpsQuery))
    QMessageBox::critical(this, "Load_Dialog", "Unable to load dumps data");
}

void Load_Dialog::on_Load_PerfPart_All_select_clicked(bool val)
{
  ui->Load_PerfPart_1_select->setChecked(val && ui->Load_PerfPart_1_select->isEnabled());
  ui->Load_PerfPart_2_select->setChecked(val && ui->Load_PerfPart_2_select->isEnabled());
  ui->Load_PerfPart_3_select->setChecked(val && ui->Load_PerfPart_3_select->isEnabled());
  ui->Load_PerfPart_4_select->setChecked(val && ui->Load_PerfPart_4_select->isEnabled());
  ui->Load_PerfPart_5_select->setChecked(val && ui->Load_PerfPart_5_select->isEnabled());
  ui->Load_PerfPart_6_select->setChecked(val && ui->Load_PerfPart_6_select->isEnabled());
  ui->Load_PerfPart_7_select->setChecked(val && ui->Load_PerfPart_7_select->isEnabled());
  ui->Load_PerfPart_8_select->setChecked(val && ui->Load_PerfPart_8_select->isEnabled());
  ui->Load_PerfPart_9_select->setChecked(val && ui->Load_PerfPart_9_select->isEnabled());
  ui->Load_PerfPart_10_select->setChecked(val && ui->Load_PerfPart_10_select->isEnabled());
  ui->Load_PerfPart_11_select->setChecked(val && ui->Load_PerfPart_11_select->isEnabled());
  ui->Load_PerfPart_12_select->setChecked(val && ui->Load_PerfPart_12_select->isEnabled());
  ui->Load_PerfPart_13_select->setChecked(val && ui->Load_PerfPart_13_select->isEnabled());
  ui->Load_PerfPart_14_select->setChecked(val && ui->Load_PerfPart_14_select->isEnabled());
  ui->Load_PerfPart_15_select->setChecked(val && ui->Load_PerfPart_15_select->isEnabled());
  ui->Load_PerfPart_16_select->setChecked(val && ui->Load_PerfPart_16_select->isEnabled());
}

void Load_Dialog::on_Load_Name_select_currentIndexChanged(int index)
{
  ui->Load_Timestamp_display->setText(Dates.at(index));
  ui->Load_Comment_display->setText(Comments.at(index));
  // get PerfPart values
  if (ui->Load_UserPerformance_button->isChecked() || ui->Load_CurrentPerformance_button->isChecked()) {
    clearPartLabels();
    int SerNum = (ui->Load_Name_select->itemData(index)).toInt();
    QSqlQuery query(JVlibForm::db_mysql);
    query.prepare("select Part_1, Part_2, Part_3, Part_4, Part_5, Part_6, Part_7, Part_8, \
      Part_9, Part_10, Part_11, Part_12, Part_13, Part_14, Part_15, Part_16 \
      from Perf_UserPatch_ref where Performance = ? limit 1");
    query.bindValue(0,SerNum);
    printf("querying Perf_UserPatch_ref for Perf SerNum %d\n", SerNum);
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
    QSqlQuery part_query(JVlibForm::db_mysql);
    part_query.prepare("select name from Patches where SerNumber = ?");
    for (int x=0;x<16;x++) {
      if (query.isNull(x)) continue;
      switch(x+1) {
	case 1:
	  ui->Load_PerfPart_1_select->setEnabled(true);
	  ui->Load_PerfPart_All_select->setEnabled(true);
	  part_query.bindValue(0,query.value(0).toInt());
	  if (part_query.exec()) part_query.next();
	  ui->Load_Part_1_data->setText(part_query.value(0).toString().simplified());
	  break;
	case 2:
	  ui->Load_PerfPart_2_select->setEnabled(true);
	  ui->Load_PerfPart_All_select->setEnabled(true);
	  part_query.bindValue(0,query.value(1).toInt());
	  if (part_query.exec()) part_query.next();
	  ui->Load_Part_2_data->setText(part_query.value(0).toString().simplified());
	  break;
	case 3:
	  ui->Load_PerfPart_3_select->setEnabled(true);
	  ui->Load_PerfPart_All_select->setEnabled(true);
	  part_query.bindValue(0,query.value(2).toInt());
	  if (part_query.exec()) part_query.next();
	  ui->Load_Part_3_data->setText(part_query.value(0).toString().simplified());
	  break;
	case 4:
	  ui->Load_PerfPart_4_select->setEnabled(true);
	  ui->Load_PerfPart_All_select->setEnabled(true);
	  part_query.bindValue(0,query.value(3).toInt());
	  if (part_query.exec()) part_query.next();
	  ui->Load_Part_4_data->setText(part_query.value(0).toString().simplified());
	  break;
	case 5:
	  ui->Load_PerfPart_5_select->setEnabled(true);
	  break;
	case 6:
	  ui->Load_PerfPart_6_select->setEnabled(true);
	  break;
	case 7:
	  ui->Load_PerfPart_7_select->setEnabled(true);
	  break;
	case 8:
	  ui->Load_PerfPart_8_select->setEnabled(true);
	  break;
	case 9:
	  ui->Load_PerfPart_9_select->setEnabled(true);
	  break;
	case 10:
	  ui->Load_PerfPart_10_select->setEnabled(true);
	  break;
	case 11:
	  ui->Load_PerfPart_11_select->setEnabled(true);
	  break;
	case 12:
	  ui->Load_PerfPart_12_select->setEnabled(true);
	  break;
	case 13:
	  ui->Load_PerfPart_13_select->setEnabled(true);
	  break;
	case 14:
	  ui->Load_PerfPart_14_select->setEnabled(true);
	  break;
	case 15:
	  ui->Load_PerfPart_15_select->setEnabled(true);
	  break;
	case 16:
	  ui->Load_PerfPart_16_select->setEnabled(true);
	  break;	  
      }	// end Switch
    }	// end FOR PerfParts
    part_query.finish();
    query.finish();
    return;
  }	// end if PerfPart
}	// end on_Load_Name_select_currentIndexChanged

