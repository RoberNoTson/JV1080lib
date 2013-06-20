// create_save_dialog_actions.cpp
#include        "JVlibForm.h"
#include        <QtGui>

Save_Dialog::Save_Dialog()
{
  setupUi(this);
  connect(Save_Dialog::Save_buttonBox, SIGNAL(rejected()), this, SLOT(slotSaveDialog_cancel()));
  connect(Save_Dialog::Save_buttonBox, SIGNAL(accepted()), this, SLOT(slotSaveDialog_accept()));
  connect(Save_Dialog::Save_buttonBox, SIGNAL(helpRequested()), this, SLOT(slotSaveDialog_help()));
  connect(Save_Dialog::Save_System_button, SIGNAL(toggled(bool)), this, SLOT(slotSave_System(bool)));
  connect(Save_Dialog::Save_CurrentPerformance_button, SIGNAL(toggled(bool)), this, SLOT(slotSave_Performance(bool)));
  connect(Save_Dialog::Save_CurrentPatch_button, SIGNAL(toggled(bool)), this, SLOT(slotSave_Patch(bool)));
  connect(Save_Dialog::Save_CurrentRhythm_button, SIGNAL(toggled(bool)), this, SLOT(slotSave_Rhythm(bool)));
  connect(Save_Dialog::Save_CurrentTuning_button, SIGNAL(toggled(bool)), this, SLOT(slotSave_Tuning(bool)));
  connect(Save_Dialog::Save_UserPerformance_button, SIGNAL(toggled(bool)), this, SLOT(slotSave_UserPerformance(bool)));
  connect(Save_Dialog::Save_UserPatch_button, SIGNAL(toggled(bool)), this, SLOT(slotSave_UserPatch(bool)));
  connect(Save_Dialog::Save_UserRhythm_button, SIGNAL(toggled(bool)), this, SLOT(slotSave_UserRhythm(bool)));
  connect(Save_Dialog::Save_UserDump_button, SIGNAL(toggled(bool)), this, SLOT(slotSave_UserDump(bool)));
  if (Save_Comment_edit->text().isEmpty()) {
    Save_Comment_edit->setPlaceholderText("Optional comment describing this data");
    Save_buttonBox->setFocus();
  }
  if (Save_Name_edit->text().isEmpty()) {
//    Save_Name_edit->setFocus();
    Save_Name_edit->setPlaceholderText("Enter a valid name");
    Save_Comment_edit->setFocus();
  }
}
