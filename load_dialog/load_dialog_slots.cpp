// load_dialog_slots.cpp
#include "load_dialog/load_dialog.h"
#include "ui_Load_Dialog.h"
#include "JVlibForm.h"
#include <QtGui>
#include <QtSql>

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
    QMessageBox::critical(this, "Save Dialog", "Help not yet available for this function");
}
