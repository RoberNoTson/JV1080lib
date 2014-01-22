// save_dialog.cpp
// utility functions for Save_Dialog
/* Contains:
 * Save_Dialog()
 * ~Save_Dialog()
 * clearPartLabels()
 * db_insert_data()
 * bulk_get
*/

#include	"save_dialog/Save_Dialog.h"
#include	"ui_Save_Dialog.h"
#include        "JVlibForm.h"
#include        <QtGui>
#include	<QtSql>

Save_Dialog::Save_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Save_Dialog)
{
  ui->setupUi(this);
  ui->Save_CurrentPerformance_button->setEnabled(JVlibForm::state_table->perf_mode && JVlibForm::state_table->performance_sync);
  ui->Save_CurrentPatch_button->setEnabled(JVlibForm::state_table->patch_mode && JVlibForm::state_table->patch_sync);
  ui->Save_CurrentRhythm_button->setEnabled(JVlibForm::state_table->perf_mode && JVlibForm::state_table->rhythm_sync);
  ui->Save_System_button->setEnabled(JVlibForm::state_table->system_sync);
  ui->Save_CurrentTuning_button->setEnabled(JVlibForm::state_table->tuning_sync && JVlibForm::state_table->tuning_type==CustomTemp);
  ui->Save_Date_edit->setDate(QDate::currentDate());
  if (ui->Save_Comment_edit->text().isEmpty()) {
    ui->Save_Comment_edit->setPlaceholderText("Optional comment describing this data");
    ui->Save_buttonBox->setFocus();
  }
  if (ui->Save_Name_edit->text().isEmpty()) {
    ui->Save_Name_edit->setPlaceholderText("Enter a valid name");
    ui->Save_Comment_edit->setFocus();
  }
  if (ui->Save_CurrentPerformance_button->isEnabled() && JVlibForm::state_table->perf_mode)
    ui->Save_CurrentPerformance_button->setChecked(true);
  else if (ui->Save_CurrentPatch_button->isEnabled() && JVlibForm::state_table->patch_mode)
    ui->Save_CurrentPatch_button->setChecked(true);
  else if (ui->Save_System_button->isEnabled())
    ui->Save_System_button->setChecked(true);
  else 
    ui->Save_ReceiveUserDump_button->setChecked(true);
  if (JVlibForm::state_table->tuning_type == CustomTemp &&  ui->Save_CurrentTuning_button->isEnabled())
    ui->Save_CurrentTuning_button->setChecked(true);
}

Save_Dialog::~Save_Dialog() {
  delete ui;
}

void Save_Dialog::clearPartLabels() {
  ui->Save_Part_1_data->clear();
  ui->Save_Part_2_data->clear();
  ui->Save_Part_3_data->clear();
  ui->Save_Part_4_data->clear();
  ui->Save_Part_5_data->clear();
  ui->Save_Part_6_data->clear();
  ui->Save_Part_7_data->clear();
  ui->Save_Part_8_data->clear();
  ui->Save_Part_9_data->clear();
  ui->Save_Part_10_data->clear();
  ui->Save_Part_11_data->clear();
  ui->Save_Part_12_data->clear();
  ui->Save_Part_13_data->clear();
  ui->Save_Part_14_data->clear();
  ui->Save_Part_15_data->clear();
  ui->Save_Part_16_data->clear();
}

int Save_Dialog::db_insert_data(QString table_name, char *ptr, int sz, int part_num) {
  if (!sz || ptr==NULL) return -1;	// invalid parms, return with error
  QByteArray sysex(ptr,sz);	// reserve space for sysex data
  QSqlQuery query(JVlibForm::db_mysql);
  QString buf = "insert into "+table_name+" values(DEFAULT, '"+ui->Save_Name_edit->text()+"', ?, DEFAULT, ";
  if (!part_num) {	// default = 0 in headerfile
    if (table_name=="Tuning")
      buf += "DEFAULT, ";
    // no partnum and not Tuning data, must be System, Current Patch or Current Perf RhythmSet, or a UserDump
    buf += "'"+ui->Save_Comment_edit->text()+"'"+","+QString::number(qChecksum(ptr,sz))+")";
    query.prepare(buf);
    query.bindValue(0,sysex);
  }
  else {
    QString part_name;
    switch(part_num) {
      case 1:
	part_name = ui->Save_Part_1_data->text().simplified();
	break;
      case 2:
	part_name = ui->Save_Part_2_data->text().simplified();
	break;
      case 3:
	part_name = ui->Save_Part_3_data->text().simplified();
	break;
      case 4:
	part_name = ui->Save_Part_4_data->text().simplified();
	break;
      case 5:
	part_name = ui->Save_Part_5_data->text().simplified();
	break;
      case 6:
	part_name = ui->Save_Part_6_data->text().simplified();
	break;
      case 7:
	part_name = ui->Save_Part_7_data->text().simplified();
	break;
      case 8:
	part_name = ui->Save_Part_8_data->text().simplified();
	break;
      case 9:
	part_name = ui->Save_Part_9_data->text().simplified();
	break;
      case 10:
	part_name = ui->Save_Part_10_data->text().simplified();
	break;
      case 11:
	part_name = ui->Save_Part_11_data->text().simplified();
	break;
      case 12:
	part_name = ui->Save_Part_12_data->text().simplified();
	break;
      case 13:
	part_name = ui->Save_Part_13_data->text().simplified();
	break;
      case 14:
	part_name = ui->Save_Part_14_data->text().simplified();
	break;
      case 15:
	part_name = ui->Save_Part_15_data->text().simplified();
	break;
      case 16:
	part_name = ui->Save_Part_16_data->text().simplified();
	break;
    }	// end switch partnum
    if (part_num != 10 )	// process a normal Perf Part patch
      buf = "insert into Patches values(DEFAULT, '"+part_name+"', ?, DEFAULT, 'Part "+QString::number(part_num)+" of Performance "+ui->Save_Name_edit->text()+"', "+QString::number(qChecksum(ptr,sz))+")";
    else	// process a Perf Rhythm set
      buf = "insert into RhythmSets values(DEFAULT, '"+part_name+"', ?, DEFAULT, 'Part 10 of Performance "+ui->Save_Name_edit->text()+"', "+QString::number(qChecksum(ptr,sz))+")";
    query.prepare(buf);
    query.bindValue(0,sysex);
  }	// end else partnum>0
  if (query.exec() == false) {
    puts("Query exec failed");
    printf("%s\n",query.executedQuery().toAscii().data());
    QMessageBox::critical(this, "Save Dialog", QString("Query exec failed\n%1") .arg(query.lastError().text()));
    query.finish();
    return -1;
  }
  if (table_name != "Patches" && table_name != "Performances" && table_name != "RhythmSets") {
    query.finish();
    return 0;
  }
  int x  = query.lastInsertId().toInt();	// save the new SerNumber for xref table
  query.finish();
  return x;
}	// end db_insert_data

bool Save_Dialog::bulk_get(unsigned char *buf, int sz) {
  if (!JVlibForm::state_table->jv_connect) return EXIT_FAILURE;
  if (!JVlibForm::state_table->midiPorts_open) JVlibForm::open_ports();
  int   read;
  register int err;
  int npfds, time;
  int timeout = 4000;
  struct pollfd *pfds;
  unsigned char recv_buf[256];
  QByteArray hold_buf;
  unsigned short revents;
  snd_rawmidi_status_t *ptr;
  // set up polling structs, prepare for reading data
  time=0;
  npfds = snd_rawmidi_poll_descriptors_count(JVlibForm::midiInHandle);
  pfds = new pollfd;
  snd_rawmidi_poll_descriptors(JVlibForm::midiInHandle, pfds, npfds);
  snd_rawmidi_nonblock(JVlibForm::midiInHandle,1);		// set to nonblocking mode
  read=0;
  hold_buf.clear();
  // big loop to read data
  puts("receiving Bulk Dump");
  for (;;) {
    memset(recv_buf,0,sizeof(recv_buf));
    err = poll(pfds, npfds, 200);
    // process poll status/errors
    if (err < 0) { printf("poll failed: %s", strerror(errno)); break; }
    // timeout (or correct amount of data) are the only good ways to exit this loop
    if (err == 0) {
      time += 200;
      if (timeout && time >= timeout) {puts("#### TIMEOUT ####"); break; }
      usleep(20000); continue;
    }
    if ((err = snd_rawmidi_poll_descriptors_revents(JVlibForm::midiInHandle, pfds, npfds, &revents)) < 0) {
      printf("Cannot get poll events: %s\n", snd_strerror(err));
      break;
    }
    if (revents & (POLLERR | POLLHUP)) {
      puts("Input polling interrupted or hardware error");
      break;
    }
    if (!(revents & POLLIN)) { usleep(20000); continue; }	// loop if no data and still polling
    // read the incoming data
    err = snd_rawmidi_read(JVlibForm::midiInHandle, recv_buf, sizeof(recv_buf));
    if (err == -EAGAIN) { usleep(20000); continue; }
    if (err < 0) {
      printf("cannot read from port \"%s\": %s", JVlibForm::MIDI_dev, snd_strerror(err));
      delete pfds;
      return EXIT_FAILURE;	// signal possible retry to calling routine
    }
    if (err == 0) { usleep(20000); continue; }
    time = 0;	// data received, reset the timeout value
    hold_buf.append((char *)recv_buf, err);
    read += err;
printf("Read %d bytes\n",read);
    if (read >= sz) break;
  }	// end FOR bigloop
  // pause before parsing data and returning
  usleep(20000);
  // validate the data received
  if (read != sz) {
    puts("#### Incomplete data received! ####");
    // get a snd_rawmidi_status_t struct
    if ((err = snd_rawmidi_status_malloc(&ptr)) < 0)
      printf("Can't get snd_rawmidi_status_t: %s\n", snd_strerror(err));
    else {
      // Tell ALSA to fill in our snd_rawmidi_status_t struct with this device's status
      if ((err = snd_rawmidi_status(JVlibForm::midiInHandle, ptr)) < 0)
	  printf("Can't get status: %s\n", snd_strerror(err));
      else {
	err = snd_rawmidi_status_get_xruns(ptr);
	if (err != 0) printf("There are %i overrun errors\n", err);
      }
      // Done, free the snd_rawmidi_status_t struct
      snd_rawmidi_status_free(ptr);
    }
    delete pfds;
    return EXIT_FAILURE;	// signal possible retry to calling routine
  }
  // validate dump format
  if (!(hold_buf.startsWith(0xF0) && hold_buf.endsWith(0xF7))) {
    puts("Received incomplete or corrupted data, not a valid dump");
    return false;        // signal possible retry to calling routine
  }
  // save valid data
  memcpy(buf, (char *)hold_buf.constData(), sz);
  delete pfds;
  JVlibForm::close_ports();
  puts("Bulk Dump received");
  return EXIT_SUCCESS;
}	// end bulk_get

