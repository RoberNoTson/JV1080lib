// Save_Dialog.h
#ifndef SAVE_DIALOG_H
#define SAVE_DIALOG_H

#include <QtGui>
#include <QDialog>
#include <QtSql>

namespace Ui {
    class Save_Dialog;
}

class Save_Dialog : public QDialog {
  
  Q_OBJECT
  
public:
  Save_Dialog(QWidget *parent = 0);
  ~Save_Dialog();
  void setData(QSqlDatabase);
  
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
  Ui::Save_Dialog *ui;
  void createSaveDialogActions();
  static QSqlDatabase db_mysql;
};
#endif	// SAVE_DIALOG_H
