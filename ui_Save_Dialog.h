/********************************************************************************
** Form generated from reading UI file 'Save_Dialog.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVE_DIALOG_H
#define UI_SAVE_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Save_Dialog
{
public:
    QDialogButtonBox *Save_buttonBox;
    QLineEdit *Save_Comment_edit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *Save_Name_edit;
    QGroupBox *groupBox;
    QRadioButton *Save_System_button;
    QRadioButton *Save_CurrentPerformance_button;
    QRadioButton *Save_CurrentPatch_button;
    QRadioButton *Save_UserDump_button;
    QRadioButton *Save_CurrentRhythm_button;
    QLabel *label_3;
    QLabel *label_4;
    QRadioButton *Save_UserPerformance_button;
    QRadioButton *Save_UserPatch_button;
    QRadioButton *Save_UserRhythm_button;
    QRadioButton *Save_CurrentTuning_button;

    void setupUi(QDialog *Save_Dialog)
    {
        if (Save_Dialog->objectName().isEmpty())
            Save_Dialog->setObjectName(QString::fromUtf8("Save_Dialog"));
        Save_Dialog->setWindowModality(Qt::NonModal);
        Save_Dialog->resize(470, 373);
        Save_Dialog->setModal(true);
        Save_buttonBox = new QDialogButtonBox(Save_Dialog);
        Save_buttonBox->setObjectName(QString::fromUtf8("Save_buttonBox"));
        Save_buttonBox->setGeometry(QRect(0, 310, 461, 32));
        Save_buttonBox->setOrientation(Qt::Horizontal);
        Save_buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Help|QDialogButtonBox::Save);
        Save_Comment_edit = new QLineEdit(Save_Dialog);
        Save_Comment_edit->setObjectName(QString::fromUtf8("Save_Comment_edit"));
        Save_Comment_edit->setGeometry(QRect(10, 280, 451, 22));
        Save_Comment_edit->setMaxLength(255);
        Save_Comment_edit->setPlaceholderText(QString::fromUtf8("Optional description"));
        label = new QLabel(Save_Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 260, 71, 16));
        label_2 = new QLabel(Save_Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 210, 52, 14));
        Save_Name_edit = new QLineEdit(Save_Dialog);
        Save_Name_edit->setObjectName(QString::fromUtf8("Save_Name_edit"));
        Save_Name_edit->setGeometry(QRect(10, 230, 451, 22));
        Save_Name_edit->setMaxLength(255);
        Save_Name_edit->setPlaceholderText(QString::fromUtf8("Enter a valid name"));
        groupBox = new QGroupBox(Save_Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 301, 201));
        groupBox->setTitle(QString::fromUtf8("Save"));
        Save_System_button = new QRadioButton(groupBox);
        Save_System_button->setObjectName(QString::fromUtf8("Save_System_button"));
        Save_System_button->setGeometry(QRect(200, 50, 81, 21));
        Save_System_button->setAutoFillBackground(true);
        Save_System_button->setChecked(true);
        Save_CurrentPerformance_button = new QRadioButton(groupBox);
        Save_CurrentPerformance_button->setObjectName(QString::fromUtf8("Save_CurrentPerformance_button"));
        Save_CurrentPerformance_button->setGeometry(QRect(10, 50, 111, 21));
        Save_CurrentPerformance_button->setAutoFillBackground(true);
        Save_CurrentPatch_button = new QRadioButton(groupBox);
        Save_CurrentPatch_button->setObjectName(QString::fromUtf8("Save_CurrentPatch_button"));
        Save_CurrentPatch_button->setGeometry(QRect(10, 80, 101, 21));
        Save_CurrentPatch_button->setAutoFillBackground(true);
        Save_UserDump_button = new QRadioButton(groupBox);
        Save_UserDump_button->setObjectName(QString::fromUtf8("Save_UserDump_button"));
        Save_UserDump_button->setGeometry(QRect(130, 140, 51, 21));
        Save_UserDump_button->setAutoFillBackground(true);
        Save_CurrentRhythm_button = new QRadioButton(groupBox);
        Save_CurrentRhythm_button->setObjectName(QString::fromUtf8("Save_CurrentRhythm_button"));
        Save_CurrentRhythm_button->setGeometry(QRect(10, 110, 101, 21));
        Save_CurrentRhythm_button->setAutoFillBackground(true);
        Save_CurrentRhythm_button->setText(QString::fromUtf8("    Rhythm"));
        Save_CurrentRhythm_button->setChecked(false);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 20, 51, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setFrameShape(QFrame::Box);
        label_3->setText(QString::fromUtf8("Current"));
        label_3->setTextFormat(Qt::RichText);
        label_3->setScaledContents(true);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 20, 41, 21));
        label_4->setFont(font);
        label_4->setFrameShape(QFrame::Box);
        label_4->setText(QString::fromUtf8("User"));
        label_4->setTextFormat(Qt::RichText);
        Save_UserPerformance_button = new QRadioButton(groupBox);
        Save_UserPerformance_button->setObjectName(QString::fromUtf8("Save_UserPerformance_button"));
        Save_UserPerformance_button->setGeometry(QRect(110, 50, 41, 21));
        Save_UserPerformance_button->setLayoutDirection(Qt::RightToLeft);
        Save_UserPerformance_button->setAutoFillBackground(true);
        Save_UserPatch_button = new QRadioButton(groupBox);
        Save_UserPatch_button->setObjectName(QString::fromUtf8("Save_UserPatch_button"));
        Save_UserPatch_button->setGeometry(QRect(110, 80, 41, 21));
        Save_UserPatch_button->setLayoutDirection(Qt::RightToLeft);
        Save_UserPatch_button->setAutoFillBackground(true);
        Save_UserRhythm_button = new QRadioButton(groupBox);
        Save_UserRhythm_button->setObjectName(QString::fromUtf8("Save_UserRhythm_button"));
        Save_UserRhythm_button->setGeometry(QRect(110, 110, 41, 21));
        Save_UserRhythm_button->setLayoutDirection(Qt::RightToLeft);
        Save_UserRhythm_button->setAutoFillBackground(true);
        Save_CurrentTuning_button = new QRadioButton(groupBox);
        Save_CurrentTuning_button->setObjectName(QString::fromUtf8("Save_CurrentTuning_button"));
        Save_CurrentTuning_button->setGeometry(QRect(10, 140, 81, 21));
        Save_CurrentTuning_button->setAutoFillBackground(true);
        Save_CurrentTuning_button->setText(QString::fromUtf8("Tuning"));
        Save_CurrentTuning_button->setChecked(false);

        retranslateUi(Save_Dialog);

        QMetaObject::connectSlotsByName(Save_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Save_Dialog)
    {
        Save_Dialog->setWindowTitle(QApplication::translate("Save_Dialog", "Save Data", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Save_Dialog", "Comment", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Save_Dialog", "Name", 0, QApplication::UnicodeUTF8));
        Save_System_button->setText(QApplication::translate("Save_Dialog", "System", 0, QApplication::UnicodeUTF8));
        Save_CurrentPerformance_button->setText(QApplication::translate("Save_Dialog", "  Performance", 0, QApplication::UnicodeUTF8));
        Save_CurrentPatch_button->setText(QApplication::translate("Save_Dialog", "    Patch", 0, QApplication::UnicodeUTF8));
        Save_UserDump_button->setText(QApplication::translate("Save_Dialog", "All", 0, QApplication::UnicodeUTF8));
        Save_UserPerformance_button->setText(QString());
        Save_UserPatch_button->setText(QString());
        Save_UserRhythm_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Save_Dialog: public Ui_Save_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVE_DIALOG_H
