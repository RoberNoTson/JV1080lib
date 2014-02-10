#ifndef JV_COPY_H
#define JV_COPY_H

#include <QDialog>
#include <QtGui>

namespace Ui {
    class JV_COPY;
}

class JV_COPY : public QDialog {
    Q_OBJECT
public:
    JV_COPY(QWidget *parent = 0);
    ~JV_COPY();

private slots:
  void on_Copy_buttonBox_accepted();
  void on_Copy_buttonBox_rejected();
  void on_Copy_buttonBox_helpRequested();
  void on_Copy_Source_type_currentIndexChanged(int);
  void on_Copy_Source_select_currentIndexChanged(QString);
  void on_Copy_Source_value_valueChanged(int);
  void on_Copy_Source_Subtype_value_valueChanged(int);
  void on_Copy_Dest_Subtype_value_valueChanged(int);
  
private:
    Ui::JV_COPY *ui;

};

#endif // JV_COPY_H
