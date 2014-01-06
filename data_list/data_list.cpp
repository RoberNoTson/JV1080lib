#include "data_list.h"
#include "ui_data_list.h"
#include "JVlibForm.h"
#include <QtGui>
#include <QtSql>

DATA_LIST::DATA_LIST(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DATA_LIST)
{
    ui->setupUi(this);
}

DATA_LIST::~DATA_LIST()
{
  delete ui;
}

void DATA_LIST::on_DataList_Exit_button_clicked()
{
    this->close();
}

void DATA_LIST::on_DataList_Select_button_clicked()
{
    QString Results;
    Results.append("<table>");
    ui->DataList_Result_list->clear();
    QSqlQuery query(JVlibForm::db_mysql);
    switch(ui->DataList_Type_button->currentIndex()) {
      case 0:	// Patches
	if (ui->DataList_Family_select->currentIndex()) {
	  query.prepare("select group_area, number, name, instr_family from patch_list where name like ? and instr_family like ? order by group_area, number");
	  query.bindValue(1, ui->DataList_Family_select->currentIndex()>0?"%"+ui->DataList_Family_select->currentText()+"%":"%");
	}
	else {
	  query.prepare("select group_area, number, name, instr_family from patch_list where name like ? order by group_area, number");
	}
	query.bindValue(0, "%"+ui->DataList_Name_edit->text()+"%");
	break;
      case 1:	// Tones/Wave
	if (ui->DataList_Family_select->currentIndex()) {
	  query.prepare("select group_area, number, name, Instruments from wave_list where name like ? and Instruments like ? order by group_area, number");
	  query.bindValue(1, ui->DataList_Family_select->currentIndex()>0?"%"+ui->DataList_Family_select->currentText()+"%":"%");
	}
	else {
	  query.prepare("select group_area, number, name, Instruments from wave_list where name like ? order by group_area, number");
	}
	query.bindValue(0, "%"+ui->DataList_Name_edit->text()+"%");
	break;
      case 2:	// Dumps
	query.prepare("select SerNumber, name, date, comment from Dumps where name like ? order by name, date");
	query.bindValue(0, "%"+ui->DataList_Name_edit->text()+"%");
	break;
      case 3:	// Saved Performances
	query.prepare("select SerNumber, name, date, comment from Performances where name like ? order by name, date");
	query.bindValue(0, "%"+ui->DataList_Name_edit->text()+"%");
	break;
      case 4:	// Saved Patches
	query.prepare("select SerNumber, name, date, comment from Patches where name like ? order by name, date");
	query.bindValue(0, "%"+ui->DataList_Name_edit->text()+"%");
	break;
      case 5:	// Saved Rhythm Sets
	query.prepare("select SerNumber, name, date, comment from RhythmSets where name like ? order by name, date");
	query.bindValue(0, "%"+ui->DataList_Name_edit->text()+"%");
	break;
      case 6:	// Saved Tunings
	query.prepare("select SerNumber, name, date, comment from Tuning where name like ? order by name, date");
	query.bindValue(0, "%"+ui->DataList_Name_edit->text()+"%");
	break;
      default:
	break;
    }	// end switch TYPE
    
    if (query.exec()==false) { 
      Results.append("<tr><td>Unknown query error</td></tr>");
      puts("data_list query error - failed");
      query.finish();
      Results.append("</table>");
      ui->DataList_Result_list->setHtml(Results);    
      return;
    }
    if (query.size()==0) { 
      Results.append("<tr><td>No data found</td></tr>");
    }
    else {
      while (query.next()) {
        Results.append("<tr>");
        for (int x=0;x<4;x++) {
            Results.append("<td width=25%>"+query.value(x).toString()+"</td>");
        }
        Results.append("</tr>");
      }
    }
    query.finish();
    Results.append("</table>");
    ui->DataList_Result_list->setHtml(Results);    
}
