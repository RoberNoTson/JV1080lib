#include "load_dialog.h"
#include "ui_load_dialog.h"

LOAD_DIALOG::LOAD_DIALOG(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LOAD_DIALOG)
{
    ui->setupUi(this);
}

LOAD_DIALOG::~LOAD_DIALOG()
{
    delete ui;
}

void LOAD_DIALOG::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
