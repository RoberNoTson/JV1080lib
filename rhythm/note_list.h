#ifndef NOTE_LIST_H
#define NOTE_LIST_H

#include <QtGui>
#include <QtSql>
#include <QDialog>

namespace Ui {
    class NOTE_LIST;
}

class NOTE_LIST : public QDialog {
    Q_OBJECT
public:
    NOTE_LIST(QWidget *parent = 0);
    ~NOTE_LIST();

private:
    Ui::NOTE_LIST *ui;
    QSqlDatabase mysql;
    void Fill_List();

private slots:
    void on_NoteList_Select_button_clicked();
    void on_NoteList_Exit_button_clicked();
    QString funcNoteCalc(int);
};

#endif // NOTE_LIST_H
