// save_dumps.cpp
// called from Save_Dialog
// save a dump initiated from the JV

#include        <QtGui>
#include        <QtSql>
#include        "JVlibForm.h"
#include        "save_dialog/Save_Dialog.h"
#include        "ui_Save_Dialog.h"

bool Save_Dialog::SaveDump() {
  // ui->Save_Timeout_select->value() holds number of seconds to wait for first byte, and after last byte
  if (!JVlibForm::state_table->jv_connect) return false;
  int err, npfds, time, timeout, Stop=0;
  struct pollfd *pfds;
  unsigned char recv_buf[256];
  QByteArray buf;
  unsigned short revents;
  snd_rawmidi_status_t *ptr;
  
  this->setCursor(Qt::WaitCursor);
  timeout = ui->Save_Timeout_select->value() * 1000;
  // open the selected midi port
  if (JVlibForm::open_ports() == EXIT_FAILURE) {this->setCursor(Qt::ArrowCursor); return false; }
  // set up polling structs, prepare for reading data
  time=0;
  npfds = snd_rawmidi_poll_descriptors_count(midiInHandle);
  pfds = new pollfd;
  snd_rawmidi_poll_descriptors(midiInHandle, pfds, npfds);
  snd_rawmidi_nonblock(midiInHandle,1);         // set to nonblocking mode
  memset(recv_buf,0xF7,sizeof(recv_buf));
  read=0;
  buf.clear();
  // big loop to read data
  for (;;) {
    err = poll(pfds, npfds, timeout);
    // process poll status/errors
    if (err < 0 && errno == EINTR) { this->setCursor(Qt::ArrowCursor); return false; }
    if (err < 0) { printf("poll failed: %s", strerror(errno)); this->setCursor(Qt::ArrowCursor); return false; }
    // timeout is the only good ways to exit this loop
    if (err == 0) {
      time += 200;
      if (timeout && time >= timeout) {
	if (buf.isEmpty()) {
	  puts("SaveDump exceeded wait timeout, no data received"); 
	  this->setCursor(Qt::ArrowCursor);
	  return false; 
	}
	else
	  break;
      }
      usleep(40000); continue;
    }
    if ((err = snd_rawmidi_poll_descriptors_revents(midiInHandle, pfds, npfds, &revents)) < 0) {
      printf("Cannot get poll events: %s\n", snd_strerror(err));
      this->setCursor(Qt::ArrowCursor);
      return false;
    }
    if (revents & (POLLERR | POLLHUP)) { this->setCursor(Qt::ArrowCursor); return false; }
    if (!(revents & POLLIN)) { usleep(40000); continue; }       // loop if no data and still polling
    // read the incoming data
    err = snd_rawmidi_read(midiInHandle, recv_buf, sizeof(recv_buf));
    if (err == -EAGAIN) { usleep(40000); continue; }
    if (err < 0) {
      printf("cannot read from port \"%s\": %s", MIDI_dev, snd_strerror(err));
      delete pfds;
      this->setCursor(Qt::ArrowCursor);
      return false;        // signal possible retry to calling routine
    }
    if (err == 0) { usleep(40000); continue; }
    time = 0;   // data received, reset the timeout value
    read += err;
    buf += recv_buf;
  }	// end FOR big loop
  
  // pause before parsing/saving data
  usleep(40000);
  delete pfds;
  // save the data
  
  
  this->setCursor(Qt::ArrowCursor); 
  return true;
}	// end SaveDump
