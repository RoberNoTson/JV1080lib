#ifndef LOAD_DIALOG_H
#define LOAD_DIALOG_H

#include <QMainWindow>

namespace Ui {
    class LOAD_DIALOG;
}

class LOAD_DIALOG : public QMainWindow {
    Q_OBJECT
public:
    LOAD_DIALOG(QWidget *parent = 0);
    ~LOAD_DIALOG();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::LOAD_DIALOG *ui;
};

#endif // LOAD_DIALOG_H
