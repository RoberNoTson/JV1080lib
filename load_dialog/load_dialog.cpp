// load_dialog.cpp
/* Contains:
 * Load_Dialog()
 * ~Load_Dialog()
 * fill_Data()
 * clearPartLabels()
 */


#include "load_dialog/load_dialog.h"
#include "ui_Load_Dialog.h"
#include "JVlibForm.h"
#include <QtGui>
#include <QtSql>

QStringList Load_Dialog::Dates;
QStringList Load_Dialog::Comments;

Load_Dialog::Load_Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Load_Dialog)
{
  if (!JVlibForm::state_table->jv_connect) {
    QMessageBox::critical(0, "Load_Dialog", "Not connected to the JV-1080");
    return;
  }
  // see if we can get database access
  if (!JVlibForm::state_table->db_connect) {
    QMessageBox::critical(0, "Load_Dialog", "Not connected to the database");
    return;
  }
  ui->setupUi(this);
  if (!fill_Data(DumpsQuery)) {
    QMessageBox::critical(0, "Load_Dialog", "Unable to initialize data");
    return;
  }
  ui->Load_CurrentPerformance_button->setEnabled(JVlibForm::state_table->perf_mode);
  ui->Load_CurrentRhythm_button->setEnabled(JVlibForm::state_table->perf_mode);
  ui->Load_CurrentPatch_button->setEnabled(JVlibForm::state_table->patch_mode);
  // check if we can write to User memory, else disable those buttons
  unsigned char oldCh, newCh;
  unsigned char buf[8];
  unsigned char newBuf[5]; // = { 0x10, 0x00, 0x00, 0x00, 0x7F };
  char oneSize[4];
  memset(buf,0,8);
  memset(oneSize,0,3);
  memset(newBuf,0,5);
  buf[0] = 0x10;
  buf[7] = 1;
  oneSize[3] = 1;
  newBuf[0] = 0x10;
  newBuf[4] = 0x7F;
  if (JVlibForm::open_ports() == EXIT_FAILURE) return;
  JVlibForm::sysex_request(buf, 8);
  JVlibForm::sysex_get(&oldCh, oneSize);
  JVlibForm::sysex_update(newBuf, 5);
  JVlibForm::sysex_request(buf, 8);
  JVlibForm::sysex_get(&newCh, oneSize);
  if (newCh == oldCh) {	// did not update
    ui->Load_UserPerformance_button->setEnabled(false);
    ui->Load_UserPatch_button->setEnabled(false);
    ui->Load_UserRhythm_button->setEnabled(false);
    ui->Load_LoadDump_button->setEnabled(false);
    QMessageBox::critical(this, "Load_Dialog", "Exclusive protect is ON, User memory cannot be written");
  }
  else {
    newBuf[4] = oldCh;
    JVlibForm::sysex_update(newBuf, 5);
    JVlibForm::sysex_request(buf, 8);
    JVlibForm::sysex_get(&newCh, oneSize);
    if (newCh != oldCh)  // OOPS, did not replace the original char
      QMessageBox::critical(this, "Load_Dialog", "Unable to undo testing, User 1 Performance name is corrupted");
  }
  JVlibForm::close_ports();
}

Load_Dialog::~Load_Dialog()
{
  delete ui;
}

bool Load_Dialog::fill_Data(const char* buf) {
  QByteArray sysex;
  QSqlQuery query(JVlibForm::db_mysql);
  if (!query.exec(buf)) {
    QMessageBox::critical(this, "Load Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
    query.finish();
    return false;
  }
  Dates.clear();
  Comments.clear();
  ui->Load_Name_select->blockSignals(true);
  ui->Load_Name_select->clear();
  if (query.size()==0) {
    puts("0 rows found in init_LoadDialog");
    ui->Load_Name_select->blockSignals(false);
    ui->Load_Comment_display->clear();
    ui->Load_Timestamp_display->clear();
    query.finish();
    return false;
  }
  while (query.next()) {
    ui->Load_Name_select->insertItem(0,query.value(0).toString(),query.value(3));
//    Dates.prepend(query.value(1).toDateTime().toString("mm/dd/yyyy  hh:mm:ss"));
    Dates.prepend(query.value(1).toDateTime().toString(Qt::DefaultLocaleLongDate));
    Comments.prepend(query.value(2).toString());
//    printf("added %d %s %s %x\n",query.value(3).toInt(), query.value(0).toByteArray().data(), query.value(2).toByteArray().data(), (query.value(1).toDouble()));
  }
  ui->Load_Name_select->blockSignals(false);
  query.finish();
  ui->Load_Timestamp_display->setText(Dates.at(0));
  ui->Load_Comment_display->setText(Comments.at(0));
  return true;
}	// end fill_Data

void Load_Dialog::clearPartLabels() {
  ui->Load_Part_1_data->clear();
  ui->Load_Part_2_data->clear();
  ui->Load_Part_3_data->clear();
  ui->Load_Part_4_data->clear();
  ui->Load_Part_5_data->clear();
  ui->Load_Part_6_data->clear();
  ui->Load_Part_7_data->clear();
  ui->Load_Part_8_data->clear();
  ui->Load_Part_9_data->clear();
  ui->Load_Part_10_data->clear();
  ui->Load_Part_11_data->clear();
  ui->Load_Part_12_data->clear();
  ui->Load_Part_13_data->clear();
  ui->Load_Part_14_data->clear();
  ui->Load_Part_15_data->clear();
  ui->Load_Part_16_data->clear();
  ui->Load_PerfPart_1_select->setChecked(false);
  ui->Load_PerfPart_2_select->setChecked(false);
  ui->Load_PerfPart_3_select->setChecked(false);
  ui->Load_PerfPart_4_select->setChecked(false);
  ui->Load_PerfPart_5_select->setChecked(false);
  ui->Load_PerfPart_6_select->setChecked(false);
  ui->Load_PerfPart_7_select->setChecked(false);
  ui->Load_PerfPart_8_select->setChecked(false);
  ui->Load_PerfPart_9_select->setChecked(false);
  ui->Load_PerfPart_10_select->setChecked(false);
  ui->Load_PerfPart_11_select->setChecked(false);
  ui->Load_PerfPart_12_select->setChecked(false);
  ui->Load_PerfPart_13_select->setChecked(false);
  ui->Load_PerfPart_14_select->setChecked(false);
  ui->Load_PerfPart_15_select->setChecked(false);
  ui->Load_PerfPart_16_select->setChecked(false);
  ui->Load_PerfPart_All_select->setChecked(false);
  ui->Load_PerfPart_1_select->setEnabled(false);
  ui->Load_PerfPart_2_select->setEnabled(false);
  ui->Load_PerfPart_3_select->setEnabled(false);
  ui->Load_PerfPart_4_select->setEnabled(false);
  ui->Load_PerfPart_5_select->setEnabled(false);
  ui->Load_PerfPart_6_select->setEnabled(false);
  ui->Load_PerfPart_7_select->setEnabled(false);
  ui->Load_PerfPart_8_select->setEnabled(false);
  ui->Load_PerfPart_9_select->setEnabled(false);
  ui->Load_PerfPart_10_select->setEnabled(false);
  ui->Load_PerfPart_11_select->setEnabled(false);
  ui->Load_PerfPart_12_select->setEnabled(false);
  ui->Load_PerfPart_13_select->setEnabled(false);
  ui->Load_PerfPart_14_select->setEnabled(false);
  ui->Load_PerfPart_15_select->setEnabled(false);
  ui->Load_PerfPart_16_select->setEnabled(false);
  ui->Load_PerfPart_All_select->setEnabled(false);
}	// end clearPartLabels()

int Load_Dialog::hexdump(unsigned char *buffer, int data_size) {
  int	y,offset;
  offset=0;
  y=data_size%16;
  for (int x=0;x<data_size-y;x+=16) {
    // Print the offset in the file, followed by the bytes themselves
    printf ("0x%06x : ", offset);
    for (int i = 0; i < 16; i++) {
      printf ("%02x ", buffer[x+i]);
    }
    printf ("  |  ");
    for (int i = 0; i < 16; i++) {
	if (isprint(buffer[x+i])) {
	putchar(buffer[x+i]);
	} else {
	printf (".");
	}
    }
    puts("");
    // Keep count of our position in the file
    offset += 16;
  }
  // print any remaining partial lines
  if (y) {
    // Print the offset in the file, followed by the bytes themselves
    printf ("0x%06x : ", offset);
    for (int i = data_size-y; i < data_size; i++) {
      printf ("%02x ", buffer[i]);
    }
    for (int i=0;i<16-y;i++) printf("   ");
    printf ("  |  ");
    for (int i = data_size-y; i < data_size; i++) {
      if (isprint(buffer[i])) {
	putchar(buffer[i]);
      } else {
	printf (".");
      }
    }
    puts("");
  }	// end IF
  return EXIT_SUCCESS;
}	// end HEXDUMP

