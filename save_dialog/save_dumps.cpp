// save_dumps.cpp
// called from Save_Dialog
// save a dump initiated from the JV
/* Contains:
 * ReceiveDump
 * SaveAllDump
 * SaveAllUserRhythmDump
 * SaveAllUserPatchDump
 * SaveAllUserPerfDump
*/ 

#include        <QtGui>
#include        <QtSql>
#include        "JVlibForm.h"
#include        "save_dialog/Save_Dialog.h"
#include        "ui_Save_Dialog.h"

bool Save_Dialog::ReceiveDump() {
  // Receive a dump initiated from the JV
  // ui->Save_Timeout_select->value() holds number of seconds to wait for first byte, and after last byte
  if (!JVlibForm::state_table->jv_connect) return false;
  int err, npfds, time, timeout;
  struct pollfd *pfds;
  unsigned char recv_buf[256];
  QByteArray buf;
  unsigned short revents;
  
  this->setCursor(Qt::WaitCursor);
  timeout = ui->Save_Timeout_select->value() * 1000; // milliseconds for poll to timeout
  // open the selected midi port
  if (!JVlibForm::state_table->midiPorts_open) {
    if (JVlibForm::open_ports() == EXIT_FAILURE) {this->setCursor(Qt::ArrowCursor); return false; }
  }
  // set up polling structs, prepare for reading data
  time=0;
  npfds = snd_rawmidi_poll_descriptors_count(JVlibForm::midiInHandle);
  pfds = new pollfd;
  snd_rawmidi_poll_descriptors(JVlibForm::midiInHandle, pfds, npfds);
  snd_rawmidi_nonblock(JVlibForm::midiInHandle,1);         // set to nonblocking mode
  memset(recv_buf,0,sizeof(recv_buf));
  int readBytes=0;
  buf.clear();
  // big loop to read data
  for (;;) {
    err = poll(pfds, npfds, timeout);
    // process poll status/errors
    if (err < 0 && errno == EINTR) { this->setCursor(Qt::ArrowCursor); return false; }
    if (err < 0) { printf("poll failed: %s", strerror(errno)); this->setCursor(Qt::ArrowCursor); return false; }
    // timeout (err=0) is the only good ways to exit this loop
    if (err == 0) {
	if (buf.isEmpty()) {
	  puts("SaveDump exceeded wait timeout, no data received"); 
	  this->setCursor(Qt::ArrowCursor);
	  return false; 
	}
	else
	  break;
      }
    if ((err = snd_rawmidi_poll_descriptors_revents(JVlibForm::midiInHandle, pfds, npfds, &revents)) < 0) {
      printf("Cannot get poll events: %s\n", snd_strerror(err));
      this->setCursor(Qt::ArrowCursor);
      return false;
    }
    if (revents & (POLLERR | POLLHUP)) { this->setCursor(Qt::ArrowCursor); return false; }
    if (!(revents & POLLIN)) { usleep(20000); continue; }       // loop if no data and still polling
    // read the incoming data
    err = snd_rawmidi_read(JVlibForm::midiInHandle, recv_buf, sizeof(recv_buf));
    if (err == -EAGAIN) { usleep(20000); continue; }
    if (err < 0) {
      printf("cannot read from port \"%s\": %s", JVlibForm::MIDI_dev, snd_strerror(err));
      delete pfds;
      this->setCursor(Qt::ArrowCursor);
      return false;        // signal possible retry to calling routine
    }
    if (err == 0) { usleep(20000); continue; }
    time = 0;   // data received, reset the timeout value
    readBytes += err;
    buf.append((const char *)&recv_buf,(int)err);
  }	// end FOR big loop
  // pause before parsing/saving data
  usleep(20000);
  delete pfds;
  if (JVlibForm::state_table->midiPorts_open) JVlibForm::close_ports();
  // validate dump format
  if (!(buf.startsWith(0xF0) && buf.endsWith(0xF7))) {
    puts("Received incomplete or corrupted data, not a valid dump");
    this->setCursor(Qt::ArrowCursor);
    return false;        // signal possible retry to calling routine
  }
  // save the data to the database
  db_insert_data("Dumps",(char *)buf.constData(), buf.size());
  this->setCursor(Qt::ArrowCursor); 
  return true;
}	// end SaveDump

bool Save_Dialog::SaveAllUserRhythmDump() {
  // dump All User Rhythm Sets         8878 bytes
  // F0 41 10 6A 11 10 40 00 00 00 02 00 00 2E F7
  unsigned char temp_r[8878];
  unsigned char  buf[8];
  memset(buf,0,sizeof(buf));
  buf[0] = 0x10;
  buf[1] = 0x40;
  buf[5] = 0x02;
  this->setCursor(Qt::WaitCursor);
  if (JVlibForm::sysex_request(buf) == EXIT_FAILURE) { 
    this->setCursor(Qt::ArrowCursor);
    if (JVlibForm::state_table->midiPorts_open) { JVlibForm::close_ports(); return false; }
  }
  memset(temp_r,0,sizeof(temp_r));
  if (bulk_get(temp_r, sizeof(temp_r)) != EXIT_SUCCESS) { 
    if (JVlibForm::state_table->midiPorts_open) JVlibForm::close_ports();
    puts("bulk_get failure");
    this->setCursor(Qt::ArrowCursor); 
    return false;
  }
  this->setCursor(Qt::ArrowCursor); 
  return(db_insert_data("Dumps", (char *)&temp_r, (int)sizeof(temp_r)));
}
bool Save_Dialog::SaveAllUserPatchDump() {
  // dump All User Patches             82304 bytes
  // F0 41 10 6A 11 11 00 00 00 01 00 00 00 6E F7
  unsigned char temp_r[82304];
  unsigned char  buf[8];
  memset(buf,0,sizeof(buf));
  buf[0] = 0x11;
  buf[4] = 0x01;
  this->setCursor(Qt::WaitCursor);
  if (JVlibForm::sysex_request(buf) == EXIT_FAILURE) { 
    this->setCursor(Qt::ArrowCursor);
    if (JVlibForm::state_table->midiPorts_open) { JVlibForm::close_ports(); return false; }
  }
  memset(temp_r,0,sizeof(temp_r));
  if (bulk_get(temp_r, sizeof(temp_r)) != EXIT_SUCCESS) { 
    if (JVlibForm::state_table->midiPorts_open) JVlibForm::close_ports();
    puts("bulk_get failure");
    this->setCursor(Qt::ArrowCursor); 
    return false;
  }
  this->setCursor(Qt::ArrowCursor); 
  return(db_insert_data("Dumps", (char *)&temp_r, (int)sizeof(temp_r)));
}
bool Save_Dialog::SaveAllUserPerfDump() {
  // dump All User Perfs              17760 bytes
  // F0 41 10 6A 11 10 00 00 00 00 20 00 00 50 F7
  unsigned char temp_r[17760];
  unsigned char  buf[8];
  memset(buf,0,sizeof(buf));
  buf[0] = 0x10;
  buf[5] = 0x20;
  this->setCursor(Qt::WaitCursor);
  if (JVlibForm::sysex_request(buf) == EXIT_FAILURE) { 
    this->setCursor(Qt::ArrowCursor);
    if (JVlibForm::state_table->midiPorts_open) { JVlibForm::close_ports(); return false; }
  }
  memset(temp_r,0,sizeof(temp_r));
  if (bulk_get(temp_r, sizeof(temp_r)) != EXIT_SUCCESS) { 
    if (JVlibForm::state_table->midiPorts_open) JVlibForm::close_ports();
    puts("bulk_get failure");
    this->setCursor(Qt::ArrowCursor); 
    return false;
  }
  this->setCursor(Qt::ArrowCursor); 
  return(db_insert_data("Dumps", (char *)&temp_r, (int)sizeof(temp_r)));
}

bool Save_Dialog::SaveAllDump() {
  // dump All User (everything)      108942 bytes
  //  F0 41 10 6A 11 10 00 00 00 02 00 00 00 6E F7
  unsigned char temp_r[108942];
  unsigned char  buf[8];
  memset(buf,0,sizeof(buf));
  buf[0] = 0x10;
  buf[4] = 0x20;
  this->setCursor(Qt::WaitCursor);
  if (JVlibForm::sysex_request(buf) == EXIT_FAILURE) { 
    this->setCursor(Qt::ArrowCursor);
    if (JVlibForm::state_table->midiPorts_open) { JVlibForm::close_ports(); return false; }
  }
  memset(temp_r,0,sizeof(temp_r));
  if (bulk_get(temp_r, sizeof(temp_r)) != EXIT_SUCCESS) { 
    if (JVlibForm::state_table->midiPorts_open) JVlibForm::close_ports();
    puts("bulk_get failure");
    this->setCursor(Qt::ArrowCursor); 
    return false;
  }
  this->setCursor(Qt::ArrowCursor); 
  return(db_insert_data("Dumps", (char *)&temp_r, (int)sizeof(temp_r)));
}
