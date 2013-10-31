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
    static const char* DumpsQuery;
    static const char* SystemQuery;
    static const char* PatchQuery;
    static const char* PerfQuery;
    static const char* RhythmQuery;
    static const char* TuningQuery;
    static QStringList Dates;
    static QStringList Comments;

protected:

private:
    Ui::Load_Dialog *ui;
    bool fill_Data(const char *);
    void clearPartLabels();
    void load_current_perf();
    void load_current_patch(int, int=0);
    void load_current_rhythm(int);
    void load_user_perf();
    void load_user_patch(int, int=0);
    void load_user_rhythm(int, int=0);
    void load_tuning();
    void load_system();
    void load_dump();
    int hexdump(unsigned char *, int);
    
private slots:
    void on_Load_PerfPart_All_select_clicked(bool checked);
    void on_Load_LoadDump_button_toggled(bool checked);
    void on_Load_UserRhythm_button_toggled(bool checked);
    void on_Load_UserPatch_button_toggled(bool checked);
    void on_Load_UserPerformance_button_toggled(bool checked);
    void on_Load_System_button_toggled(bool checked);
    void on_Load_CurrentTuning_button_toggled(bool checked);
    void on_Load_CurrentRhythm_button_toggled(bool checked);
    void on_Load_CurrentPatch_button_toggled(bool checked);
    void on_Load_CurrentPerformance_button_toggled(bool checked);
    void on_Load_buttonBox_helpRequested();
    void on_Load_buttonBox_rejected();
    void on_Load_buttonBox_accepted();
    void on_Load_Name_select_currentIndexChanged(int);
};

#endif // LOAD_DIALOG_H
