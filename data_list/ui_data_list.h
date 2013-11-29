/********************************************************************************
** Form generated from reading UI file 'data_list.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATA_LIST_H
#define UI_DATA_LIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DATA_LIST
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QComboBox *DataList_Family_select;
    QLineEdit *DataList_Name_edit;
    QPushButton *DataList_Select_button;
    QPushButton *DataList_Exit_button;
    QComboBox *DataList_Type_button;
    QLabel *label_3;
    QTextEdit *DataList_Result_list;

    void setupUi(QDialog *DATA_LIST)
    {
        if (DATA_LIST->objectName().isEmpty())
            DATA_LIST->setObjectName(QString::fromUtf8("DATA_LIST"));
        DATA_LIST->resize(600, 414);
#ifndef QT_NO_STATUSTIP
        DATA_LIST->setStatusTip(QString::fromUtf8("Item Count "));
#endif // QT_NO_STATUSTIP
        groupBox = new QGroupBox(DATA_LIST);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 561, 101));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 91, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 30, 81, 16));
        DataList_Family_select = new QComboBox(groupBox);
        DataList_Family_select->setObjectName(QString::fromUtf8("DataList_Family_select"));
        DataList_Family_select->setGeometry(QRect(130, 50, 131, 25));
        DataList_Name_edit = new QLineEdit(groupBox);
        DataList_Name_edit->setObjectName(QString::fromUtf8("DataList_Name_edit"));
        DataList_Name_edit->setGeometry(QRect(10, 50, 113, 25));
        DataList_Name_edit->setText(QString::fromUtf8(""));
        DataList_Select_button = new QPushButton(groupBox);
        DataList_Select_button->setObjectName(QString::fromUtf8("DataList_Select_button"));
        DataList_Select_button->setGeometry(QRect(380, 50, 80, 25));
        DataList_Exit_button = new QPushButton(groupBox);
        DataList_Exit_button->setObjectName(QString::fromUtf8("DataList_Exit_button"));
        DataList_Exit_button->setGeometry(QRect(470, 50, 80, 25));
        DataList_Type_button = new QComboBox(groupBox);
        DataList_Type_button->setObjectName(QString::fromUtf8("DataList_Type_button"));
        DataList_Type_button->setGeometry(QRect(270, 50, 101, 25));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 30, 52, 14));
        DataList_Result_list = new QTextEdit(DATA_LIST);
        DataList_Result_list->setObjectName(QString::fromUtf8("DataList_Result_list"));
        DataList_Result_list->setGeometry(QRect(20, 120, 561, 271));
        DataList_Result_list->setAcceptDrops(false);
        DataList_Result_list->setFrameShadow(QFrame::Raised);
        DataList_Result_list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        DataList_Result_list->setUndoRedoEnabled(false);
        DataList_Result_list->setLineWrapMode(QTextEdit::NoWrap);
        DataList_Result_list->setTabStopWidth(4);
        DataList_Result_list->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        retranslateUi(DATA_LIST);

        QMetaObject::connectSlotsByName(DATA_LIST);
    } // setupUi

    void retranslateUi(QDialog *DATA_LIST)
    {
        DATA_LIST->setWindowTitle(QApplication::translate("DATA_LIST", "Data List", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DATA_LIST", "Filters", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DATA_LIST", "Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DATA_LIST", "Inst Family", 0, QApplication::UnicodeUTF8));
        DataList_Family_select->clear();
        DataList_Family_select->insertItems(0, QStringList()
         << QApplication::translate("DATA_LIST", "Any", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DATA_LIST", "Keyboards", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DATA_LIST", "Strings", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DATA_LIST", "Winds", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DATA_LIST", "Brass", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DATA_LIST", "Percussion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DATA_LIST", "ChromPerc", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DATA_LIST", "Voice", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DATA_LIST", "Synth", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DATA_LIST", "Guitars", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DATA_LIST", "Bass", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DATA_LIST", "Ensemble", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DATA_LIST", "Ethnic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DATA_LIST", "SFX", 0, QApplication::UnicodeUTF8)
        );
        DataList_Name_edit->setPlaceholderText(QApplication::translate("DATA_LIST", "full / partial name", 0, QApplication::UnicodeUTF8));
        DataList_Select_button->setText(QApplication::translate("DATA_LIST", "Search", 0, QApplication::UnicodeUTF8));
        DataList_Exit_button->setText(QApplication::translate("DATA_LIST", "Exit", 0, QApplication::UnicodeUTF8));
        DataList_Type_button->clear();
        DataList_Type_button->insertItems(0, QStringList()
         << QApplication::translate("DATA_LIST", "Performance", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DATA_LIST", "Patch", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DATA_LIST", "Tone/Wave", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DATA_LIST", "Rhythm", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("DATA_LIST", "Type", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DATA_LIST: public Ui_DATA_LIST {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_LIST_H
