// Save_Dialog.h
#ifndef SAVE_DIALOG_H
#define SAVE_DIALOG_H

#include <QtGui>
#include <QDialog>

namespace Ui {
    class Save_Dialog;
}

class Save_Dialog : public QDialog {
  
  Q_OBJECT
  
public:
  Save_Dialog(QWidget *parent = 0);
  ~Save_Dialog();
  
private slots:
  void on_Save_buttonBox_accepted();
  void on_Save_buttonBox_rejected();
  void on_Save_buttonBox_helpRequested();
  void on_Save_System_button_toggled(bool);
  void on_Save_CurrentPerformance_button_toggled(bool);
  void on_Save_CurrentPatch_button_toggled(bool);
  void on_Save_CurrentRhythm_button_toggled(bool);
  void on_Save_CurrentTuning_button_toggled(bool);
  void on_Save_UserPerformance_button_toggled(bool);
  void on_Save_UserPatch_button_toggled(bool);
  void on_Save_UserRhythm_button_toggled(bool);
  void on_Save_UserDump_button_toggled(bool);
  void on_Save_PerfPatch_All_select_toggled(bool);
  void on_Save_RhythmNumber_select_valueChanged();

private:
  Ui::Save_Dialog *ui;
  int db_insert_data(QString, char *, int, int=0);
  void save_current_perf();
  int SaveUserRhythm();
};
#endif	// SAVE_DIALOG_H
