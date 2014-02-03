#ifndef JV_COPY_H
#define JV_COPY_H

#include <QDialog>

namespace Ui {
    class JV_COPY;
}

class JV_COPY : public QDialog {
    Q_OBJECT
public:
    JV_COPY(QWidget *parent = 0);
    ~JV_COPY();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::JV_COPY *ui;
};

#endif // JV_COPY_H
