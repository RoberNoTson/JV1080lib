#include "jv_copy.h"
#include "ui_jv_copy.h"
#include "JVlibForm.h"
#include        <QtGui>
#include	<QtSql>

JV_COPY::JV_COPY(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JV_COPY)
{
    ui->setupUi(this);
}

JV_COPY::~JV_COPY()
{
    delete ui;
}

void JV_COPY::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
