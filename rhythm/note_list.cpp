/* note_list.cpp
 * Contains:
 * NOTE_LIST
 * ~NOTE_LIST
 * on_NoteList_Exit_button_clicked
 * on_NoteList_Select_button_clicked
 * funcNoteCalc
 * Current_List
 */

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

QString NOTE_LIST::funcNoteCalc(int val) {
  char note_name[] = "C_C#D_D#E_F_F#G_G#A_A#B_";
  char note_octave[] = "-1_0_1_2_3_4_5_6_7_8_9";
  char note_buffer[5];

  memcpy(note_buffer,&note_name[(val%12)*2],2);
  memcpy(note_buffer+2,&note_octave[(val/12)*2],2);
  return QString::fromAscii(note_buffer,4);
}       // end funcNoteCalc

void NOTE_LIST::on_NoteList_Select_button_clicked()
{
  if (!JVlibForm::state_table->rhythm_sync) return;
  if (!JVlibForm::state_table->db_connect) return;
  int Num;
  QString NoteResults = "<table>";
  QString NoteName, NoteGroup;
  ui->NoteList_RhythmSet->setText(QString::fromAscii(&JVlibForm::active_area->active_rhythm.rhythm_common.name[0],12));
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
    NoteResults.append("<tr><td width=20%>"+funcNoteCalc(y)+"</td>");
    NoteResults.append("<td width=40%>"+NoteGroup+" "+QString::number(Num)+"</td>");
    NoteResults.append("<td width=40%>"+NoteName);
//    NoteResults.append("<td width=25%>"+RhythmSet);
    NoteResults.append("</td></tr>");
  }       // end FOR
  query.finish();   
  NoteResults.append("</table>");
  ui->NoteList_Result_list->setHtml(NoteResults);
}
