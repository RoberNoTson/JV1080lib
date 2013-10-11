// load_dialog.cpp

#include "load_dialog/load_dialog.h"
#include "ui_Load_Dialog.h"
#include "JVlibForm.h"
#include <QtGui>
#include <QtSql>

const char DumpsQuery[] = "select name, date, comment from Dumps where name like \"Full%\" order by date";

Load_Dialog::Load_Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Load_Dialog)
{
  ui->setupUi(this);
  if (!init_LoadDialog()) 
    QMessageBox::critical(this, "Load_Dialog", "Unable to initialize data");
}

Load_Dialog::~Load_Dialog()
{
  delete ui;
}

bool Load_Dialog::init_LoadDialog() {
  QByteArray sysex;
  QSqlQuery query(JVlibForm::db_mysql);
  if (!query.exec(DumpsQuery)) {
    QMessageBox::critical(this, "Load Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
    query.finish();
    return false;
  }
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
    ui->Load_Name_select->insertItem(0,query.value(0).toString());
  }
  ui->Load_Name_select->blockSignals(false);
  query.previous();
  ui->Load_Timestamp_display->setText(query.value(1).toString());
  ui->Load_Comment_display->setText(query.value(2).toString());    
  query.finish();
  return true;
}	// end init_LoadDialog

