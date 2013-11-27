#ifndef PATCH_LIST_H
#define PATCH_LIST_H

#include <QtGui>
#include <QtSql>
#include <QDialog>

namespace Ui {
    class PATCH_LIST;
}

class PATCH_LIST : public QDialog {
    Q_OBJECT
public:
    PATCH_LIST(QWidget *parent = 0);
    ~PATCH_LIST();

private:
    Ui::PATCH_LIST *ui;
    QSqlDatabase mysql;

private slots:
    void on_PatchList_Select_button_clicked();
    void on_PatchList_Exit_button_clicked();
};

#endif // PATCH_LIST_H
