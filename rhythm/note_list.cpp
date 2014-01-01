#include "note_list.h"
#include "ui_note_list.h"
#include "JVlibForm.h"
#include <QtGui>
#include <QtSql>

NOTE_LIST::NOTE_LIST(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NOTE_LIST)
{
  ui->setupUi(this);
}

NOTE_LIST::~NOTE_LIST()
{
  delete ui;
}

void NOTE_LIST::on_NoteList_Exit_button_clicked()
{
    this->close();
}

void NOTE_LIST::on_NoteList_Select_button_clicked()
{
  if (ui->NoteList_Type_button->currentIndex()==0) {
    Fill_List();
    return;
  }
  QString NoteResults, NoteGroup, NoteName;
  int Num;
  NoteResults.clear();
  ui->NoteList_Result_list->clear();
  NoteResults.append("<table>");
  QSqlQuery query(JVlibForm::db_mysql);
/*    
    switch(ui->NoteList_Type_button->currentIndex()) {
      case 0:
	query.prepare("select SerNumber, name, date, comment from Performances where name like ? order by name, date");
	query.bindValue(0, "%"+ui->NoteList_Name_edit->text()+"%");
	break;
      case 1:
	if (ui->NoteList_Family_select->currentIndex()) {
	  query.prepare("select group_area, number, name, instr_family from patch_list where name like ? and instr_family like ? order by group_area, number");
	  query.bindValue(1, ui->NoteList_Family_select->currentIndex()>0?"%"+ui->NoteList_Family_select->currentText()+"%":"%");
	}
	else {
	  query.prepare("select group_area, number, name, instr_family from patch_list where name like ? order by group_area, number");
	}
	query.bindValue(0, "%"+ui->NoteList_Name_edit->text()+"%");
	break;
      case 2:
	if (ui->NoteList_Family_select->currentIndex()) {
	  query.prepare("select group_area, number, name, Instruments from wave_list where name like ? and Instruments like ? order by group_area, number");
	  query.bindValue(1, ui->NoteList_Family_select->currentIndex()>0?"%"+ui->NoteList_Family_select->currentText()+"%":"%");
	}
	else {
	  query.prepare("select group_area, number, name, Instruments from wave_list where name like ? order by group_area, number");
	}
	query.bindValue(0, "%"+ui->NoteList_Name_edit->text()+"%");
	break;
      case 3:
	query.prepare("select SerNumber, name, date, comment from RhythmSets where name like ? order by name, date");
	query.bindValue(0, "%"+ui->NoteList_Name_edit->text()+"%");
	break;
    }	// end switch TYPE
    if (query.exec()==false) { puts("note_list query error - failed"); query.finish(); return; }
    if (query.size()==0) { ui->NoteList_Result_list->setHtml("No data found"); query.finish(); return; }
    while (query.next()) {
        NoteResults.append("<tr>");
        for (int x=0;x<4;x++) {
            NoteResults.append("<td width=25%>"+query.value(x).toString()+"</td>");
        }
        NoteResults.append("</tr>");
    }
    query.finish();
*/    
  for (int x=0x23;x<0x63;x++) {
    NoteGroup.clear();
    switch(JVlibForm::active_area->active_rhythm.rhythm_note[x].wave_group_id) {
    case 1:     // Int A
      NoteGroup = "Internal A";
      break;
    case 2:     // Int B or Exp A
      NoteGroup = JVlibForm::active_area->active_rhythm.rhythm_note[x].wave_group==0 ? "Internal B" : "Expansion A";
      break;
    case 10:    // Exp B
      NoteGroup = "Expansion B";
      break;
    case 62:    // Exp C
      NoteGroup = "Expansion C";
      break;      
    }     // end switch NoteGroup

    NoteResults.append("</table>");
    ui->NoteList_Result_list->setHtml(NoteResults);    
  }	// end for
}	// end on_NoteList_Select_button_clicked

QString NOTE_LIST::funcNoteCalc(int val) {
  char note_name[] = "C C#D D#E F F#G G#A A#B ";
  char note_octave[] = "-1 0 1 2 3 4 5 6 7 8 9";
  char note_buffer[5];

  memcpy(note_buffer,&note_name[(val%12)*2],2);
  memcpy(note_buffer+3,&note_octave[(val/12)*2],2);
  note_buffer[2] = 0x20;
  return QString::fromAscii(note_buffer,5);
}       // end funcNoteCalc

void NOTE_LIST::Fill_List() {
  if (!JVlibForm::state_table->rhythm_sync) return;
  if (!JVlibForm::state_table->db_connect) return;
  int Num;
  QString NoteResults = "<table>";
  QString NoteName;
  QString NoteGroup;
  ui->NoteList_Result_list->clear();
  QSqlQuery query(JVlibForm::db_mysql);
  for (int y=0x23;y<0x63;y++) {
    NoteGroup.clear();
    int x = y-0x23;
    switch(JVlibForm::active_area->active_rhythm.rhythm_note[x].wave_group_id) {
      case 0x1:     // Int A
      NoteGroup = "Internal A";
      break;
      case 0x2:     // Int B or Exp A
      NoteGroup = JVlibForm::active_area->active_rhythm.rhythm_note[x].wave_group==0 ? "Internal B" : "Expansion A";
      break;
      case 0x10:    // Exp B
      NoteGroup = "Expansion B";
      break;
      case 0x62:    // Exp C
      NoteGroup = "Expansion C";
      break;
      default:
      NoteGroup = "default";
      break;
    }     // end switch NoteGroup
    Num = JVlibForm::active_area->active_rhythm.rhythm_note[x].wave_num_high*16;
    Num += JVlibForm::active_area->active_rhythm.rhythm_note[x].wave_num_low;
    Num++;
    query.prepare("Select name from wave_list where group_area = ? and number = ?");
    query.bindValue(0, NoteGroup);
    query.bindValue(1, Num);
    if (query.exec() == false) { puts("Query exec failed"); return; }
    if (query.size()==0) { puts("0 rows found in Rhythm NoteName_query"); return; }
    query.first();
    NoteName = query.value(0).toString();
    NoteName = NoteName.leftJustified(12, ' ');
    // output the results
    NoteResults.append("<tr><td width=30%>"+funcNoteCalc(y)+"</td>");
    NoteResults.append("<td width=30%>"+NoteGroup+" "+QString::number(Num)+"</td>");
    NoteResults.append("<td width=30%>"+NoteName);
    NoteResults.append("</td></tr>");
  }       // end FOR
  query.finish();   
  NoteResults.append("</table>");
  ui->NoteList_Result_list->setHtml(NoteResults);
}