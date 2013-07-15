// Save_Dialog.h
class Save_Dialog: public QDialog, private Ui::Save_Dialog
{
  Q_OBJECT
public:
  Save_Dialog();
  
private slots:
  void slotSaveDialog_accept();
  void slotSaveDialog_cancel();
  void slotSaveDialog_help();
  void slotSave_System(bool);
  void slotSave_Performance(bool);
  void slotSave_Patch(bool);
  void slotSave_Rhythm(bool);
  void slotSave_Tuning(bool);
  void slotSave_UserPerformance(bool);
  void slotSave_UserPatch(bool);
  void slotSave_UserRhythm(bool);
  void slotSave_UserDump(bool);
  
private:
  void createSaveDialogActions();
};
