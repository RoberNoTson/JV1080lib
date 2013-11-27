#include "patch_list.h"
#include "ui_patch_list.h"
#include "JVlibForm.h"
#include <QtGui>
#include <QtSql>

PATCH_LIST::PATCH_LIST(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PATCH_LIST)
{
    ui->setupUi(this);
}

PATCH_LIST::~PATCH_LIST()
{
  delete ui;
}

void PATCH_LIST::on_PatchList_Exit_button_clicked()
{
    this->close();
}

void PATCH_LIST::on_PatchList_Select_button_clicked()
{
    QString Results;
    Results.append("<table>");
    ui->PatchList_Result_list->clear();
    QSqlQuery query(JVlibForm::db_mysql);
    if (ui->PatchList_Family_select->currentIndex()) {
      query.prepare("select group_area, number, name, instr_family from patch_list where name like ? and instr_family like ? order by group_area, number");
      query.bindValue(1, ui->PatchList_Family_select->currentIndex()>0?"%"+ui->PatchList_Family_select->currentText()+"%":"%");
    }
    else {
      query.prepare("select group_area, number, name, instr_family from patch_list where name like ? order by group_area, number");
    }
    query.bindValue(0, "%"+ui->PatchList_Name_edit->text()+"%");
    if (query.exec()==false) { puts("patch_list query error - failed"); query.finish(); return; }
    if (query.size()==0) { ui->PatchList_Result_list->setHtml("No data found"); query.finish(); return; }
    while (query.next()) {
        Results.append("<tr>");
        for (int x=0;x<4;x++) {
            Results.append("<td width=25%>"+query.value(x).toString()+"</td>");
        }
        Results.append("</tr>");
    }
    query.finish();
    Results.append("</table>");
    ui->PatchList_Result_list->setHtml(Results);    
}
