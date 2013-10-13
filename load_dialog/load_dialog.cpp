// load_dialog.cpp

#include "load_dialog/load_dialog.h"
#include "ui_Load_Dialog.h"
#include "JVlibForm.h"
#include <QtGui>
#include <QtSql>

QStringList Load_Dialog::Dates;
QStringList Load_Dialog::Comments;

Load_Dialog::Load_Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Load_Dialog)
{
  ui->setupUi(this);
  if (!fill_Data(DumpsQuery))
    QMessageBox::critical(this, "Load_Dialog", "Unable to initialize data");
}

Load_Dialog::~Load_Dialog()
{
  delete ui;
}

bool Load_Dialog::fill_Data(const char* buf) {
  QByteArray sysex;
  QSqlQuery query(JVlibForm::db_mysql);
  if (!query.exec(buf)) {
    QMessageBox::critical(this, "Load Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
    query.finish();
    return false;
  }
  Dates.clear();
  Comments.clear();
  ui->Load_Name_select->blockSignals(true);
  ui->Load_Name_select->clear();
  if (query.size()==0) {
    puts("0 rows found in init_LoadDialog");
    ui->Load_Name_select->blockSignals(false);
    ui->Load_Comment_display->clear();
    ui->Load_Timestamp_display->clear();
    query.finish();
    return false;
  }
  while (query.next()) {
    ui->Load_Name_select->insertItem(0,query.value(0).toString(),query.value(3));
//    Dates.prepend(query.value(1).toDateTime().toString("mm/dd/yyyy  hh:mm:ss"));
    Dates.prepend(query.value(1).toDateTime().toString(Qt::DefaultLocaleLongDate));
    Comments.prepend(query.value(2).toString());
//    printf("added %d %s %s %x\n",query.value(3).toInt(), query.value(0).toByteArray().data(), query.value(2).toByteArray().data(), (query.value(1).toDouble()));
  }
  ui->Load_Name_select->blockSignals(false);
  query.finish();
  ui->Load_Timestamp_display->setText(Dates.at(0));
  ui->Load_Comment_display->setText(Comments.at(0));
  return true;
}	// end init_LoadDialog

void Load_Dialog::clearPartLabels() {
  ui->Load_Part_1_data->clear();
  ui->Load_Part_2_data->clear();
  ui->Load_Part_3_data->clear();
  ui->Load_Part_4_data->clear();
  ui->Load_Part_5_data->clear();
  ui->Load_Part_6_data->clear();
  ui->Load_Part_7_data->clear();
  ui->Load_Part_8_data->clear();
  ui->Load_Part_9_data->clear();
  ui->Load_Part_10_data->clear();
  ui->Load_Part_11_data->clear();
  ui->Load_Part_12_data->clear();
  ui->Load_Part_13_data->clear();
  ui->Load_Part_14_data->clear();
  ui->Load_Part_15_data->clear();
  ui->Load_Part_16_data->clear();
  ui->Load_PerfPart_1_select->setChecked(false);
  ui->Load_PerfPart_2_select->setChecked(false);
  ui->Load_PerfPart_3_select->setChecked(false);
  ui->Load_PerfPart_4_select->setChecked(false);
  ui->Load_PerfPart_5_select->setChecked(false);
  ui->Load_PerfPart_6_select->setChecked(false);
  ui->Load_PerfPart_7_select->setChecked(false);
  ui->Load_PerfPart_8_select->setChecked(false);
  ui->Load_PerfPart_9_select->setChecked(false);
  ui->Load_PerfPart_10_select->setChecked(false);
  ui->Load_PerfPart_11_select->setChecked(false);
  ui->Load_PerfPart_12_select->setChecked(false);
  ui->Load_PerfPart_13_select->setChecked(false);
  ui->Load_PerfPart_14_select->setChecked(false);
  ui->Load_PerfPart_15_select->setChecked(false);
  ui->Load_PerfPart_16_select->setChecked(false);
  ui->Load_PerfPart_All_select->setChecked(false);
  ui->Load_PerfPart_1_select->setEnabled(false);
  ui->Load_PerfPart_2_select->setEnabled(false);
  ui->Load_PerfPart_3_select->setEnabled(false);
  ui->Load_PerfPart_4_select->setEnabled(false);
  ui->Load_PerfPart_5_select->setEnabled(false);
  ui->Load_PerfPart_6_select->setEnabled(false);
  ui->Load_PerfPart_7_select->setEnabled(false);
  ui->Load_PerfPart_8_select->setEnabled(false);
  ui->Load_PerfPart_9_select->setEnabled(false);
  ui->Load_PerfPart_10_select->setEnabled(false);
  ui->Load_PerfPart_11_select->setEnabled(false);
  ui->Load_PerfPart_12_select->setEnabled(false);
  ui->Load_PerfPart_13_select->setEnabled(false);
  ui->Load_PerfPart_14_select->setEnabled(false);
  ui->Load_PerfPart_15_select->setEnabled(false);
  ui->Load_PerfPart_16_select->setEnabled(false);
  ui->Load_PerfPart_All_select->setEnabled(false);
}

