#ifndef INI_CONF_H
#define INI_CONF_H

#include <QDialog>
#include <QtGui>

namespace Ui {
    class INI_CONF;
}

class INI_CONF : public QDialog {
    Q_OBJECT
public:
    INI_CONF(QWidget *parent = 0);
    ~INI_CONF();
    void setData(QString);

protected:

private:
    Ui::INI_CONF *ui;
    static QString CFGfile;
    static QString bakHost;
    static QString bakDatabase;
    static QString bakUsername;
    static QString bakPassword;
    static QString bakStartOnline;
    static QString bakDumpDir;
    static QString bakHelpDir;
    static QString bakTempDir;
    static QString bakPortname;
    QSettings settings;

private slots:
    void on_ShowPassword_select_toggled(bool checked);
    void on_buttonBox_clicked(QAbstractButton* button);
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
    void on_StartOnline_select_toggled(bool checked);
    void on_DumpDir_edit_editingFinished();
    void on_HelpDir_edit_editingFinished();
    void on_TempDir_edit_editingFinished();
    void on_Host_edit_editingFinished();
    void on_Portname_edit_editingFinished();
    void on_Password_edit_editingFinished();
    void on_Database_edit_editingFinished();
    void on_Username_edit_editingFinished();
};

#endif // INI_CONF_H
