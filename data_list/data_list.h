#ifndef DATA_LIST_H
#define DATA_LIST_H

#include <QtGui>
#include <QtSql>
#include <QDialog>

namespace Ui {
    class DATA_LIST;
}

class DATA_LIST : public QDialog {
    Q_OBJECT
public:
    DATA_LIST(QWidget *parent = 0);
    ~DATA_LIST();

private:
    Ui::DATA_LIST *ui;
    QSqlDatabase mysql;

private slots:
    void on_DataList_Select_button_clicked();
    void on_DataList_Exit_button_clicked();
};

#endif // DATA_LIST_H
