#ifndef LOAD_DIALOG_H
#define LOAD_DIALOG_H

#include <QtGui>
#include <QDialog>

namespace Ui {
    class Load_Dialog;
}

class Load_Dialog : public QDialog {
    Q_OBJECT
public:
    Load_Dialog(QWidget *parent = 0);
    ~Load_Dialog();

protected:

private:
    Ui::Load_Dialog *ui;
    bool init_LoadDialog();
    
private slots:
    void on_Load_buttonBox_helpRequested();
    void on_Load_buttonBox_rejected();
    void on_Load_buttonBox_accepted();
};

#endif // LOAD_DIALOG_H
