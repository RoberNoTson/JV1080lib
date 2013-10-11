// load_dialog.cpp

#include "load_dialog/load_dialog.h"
#include "ui_Load_Dialog.h"
#include "JVlibForm.h"
#include <QtGui>
#include <QtSql>

Load_Dialog::Load_Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Load_Dialog)
{
  ui->setupUi(this);
  if (!init_data())
    this->close;
}

Load_Dialog::~Load_Dialog()
{
  delete ui;
}

bool Load_Dialog::init_data() {
  QByteArray sysex;
  QSqlQuery query(JVlibForm::db_mysql);
  QString buf = "select name, date, comment from Dumps where name like \"Full%\" order by date";
  if (!query.exec(buf)) {
    QMessageBox::critical(this, "Load Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
    query.finish();
    return false;
  }
  
  
  query.finish();
  return true;
}

