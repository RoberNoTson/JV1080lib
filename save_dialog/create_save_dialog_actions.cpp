// create_save_dialog_actions.cpp
#include        "JVlibForm.h"
#include        <QtGui>
#include	"save_dialog/Save_Dialog.h"
#include	"ui_Save_Dialog.h"

Save_Dialog::Save_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Save_Dialog)
{
  ui->setupUi(this);
  connect(ui->Save_Dialog::Save_buttonBox, SIGNAL(rejected()), this, SLOT(ui->slotSaveDialog_cancel()));
  connect(ui->Save_Dialog::Save_buttonBox, SIGNAL(accepted()), this, SLOT(ui->slotSaveDialog_accept()));
  connect(ui->Save_Dialog::Save_buttonBox, SIGNAL(helpRequested()), this, SLOT(ui->slotSaveDialog_help()));
  connect(ui->Save_Dialog::Save_System_button, SIGNAL(toggled(bool)), this, SLOT(ui->slotSave_System(bool)));
  connect(ui->Save_Dialog::Save_CurrentPerformance_button, SIGNAL(toggled(bool)), this, SLOT(ui->slotSave_Performance(bool)));
  connect(ui->Save_Dialog::Save_CurrentPatch_button, SIGNAL(toggled(bool)), this, SLOT(ui->slotSave_Patch(bool)));
  connect(ui->Save_Dialog::Save_CurrentRhythm_button, SIGNAL(toggled(bool)), this, SLOT(ui->slotSave_Rhythm(bool)));
  connect(ui->Save_Dialog::Save_CurrentTuning_button, SIGNAL(toggled(bool)), this, SLOT(ui->slotSave_Tuning(bool)));
  connect(ui->Save_Dialog::Save_UserPerformance_button, SIGNAL(toggled(bool)), this, SLOT(ui->slotSave_UserPerformance(bool)));
  connect(ui->Save_Dialog::Save_UserPatch_button, SIGNAL(toggled(bool)), this, SLOT(ui->slotSave_UserPatch(bool)));
  connect(ui->Save_Dialog::Save_UserRhythm_button, SIGNAL(toggled(bool)), this, SLOT(ui->slotSave_UserRhythm(bool)));
  connect(ui->Save_Dialog::Save_UserDump_button, SIGNAL(toggled(bool)), this, SLOT(ui->slotSave_UserDump(bool)));
  if (ui->Save_Comment_edit->text().isEmpty()) {
    ui->Save_Comment_edit->setPlaceholderText("Optional comment describing this data");
    ui->Save_buttonBox->setFocus();
  }
  if (ui->Save_Name_edit->text().isEmpty()) {
//    Save_Name_edit->setFocus();
    ui->Save_Name_edit->setPlaceholderText("Enter a valid name");
    ui->Save_Comment_edit->setFocus();
  }
}
