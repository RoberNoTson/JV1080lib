// utils.cpp
// utility functions for JVlibForm
// Contains:
//	change_send()	main sysex send routine
//	change_12()	call change_send with package of 12 bytes
//	change_3()	call change_send with package of 3 bytes
//	change_2()	call change_send with package of 2 bytes
//	sysex_send()	OBE
//	sysex_request()	calls change_send with sysex request; pass the addr and size to this
//	sysex_update()	calls change_send with sysex update; pass the addr and data to this
//	sysex_get()	standalone, use after sysex_request to read "size" incoming data to the passed buffer
//	close_ports()
//	open_ports()
//	chksum()
//	hexdump()
//	funcNoteCalc()
//	Pan2Deg()
//	on_MainTabWidget_currentChanged()

#include	<QtGui>
#include	<QtSql>
#include	"JVlibForm.h"

int JVlibForm::change_send(const unsigned char *buf, int buf_size) {
  if (!state_table->jv_connect) return EXIT_FAILURE;
  // set to blocking mode
  if (!state_table->midiPorts_open)
    if (open_ports() == EXIT_FAILURE) return(EXIT_FAILURE);
  snd_rawmidi_nonblock(midiInHandle, 0);
  snd_rawmidi_drop(midiOutHandle);
  // transmit the data
  int err;
  if ((err = snd_rawmidi_write(midiOutHandle, buf, buf_size)) < 0) { 
    QMessageBox::critical(0, "JVlib", tr("Cannot write to MIDI output\n%1") .arg(snd_strerror(err)));
    return(EXIT_FAILURE);
  }
  snd_rawmidi_drain(midiOutHandle);
  close_ports();
  return(err);
}	// end CHANGE_SEND
int JVlibForm::change_12(int A, int B, int C, int D, int E, int F, int G, int H, int I, int J, int K, int L) {
  change_3(A,B,C);
  change_3(D,E,F);
  change_3(G,H,I);
  change_3(J,K,L);
  return 0;
}
int JVlibForm::change_3(int A, int B, int C) {
    unsigned char buf[3];
    buf[0] = A;
    buf[1] = B;
    buf[2] = C;
    if (open_ports() == EXIT_FAILURE) return 1;
    if (change_send(buf,3) == EXIT_FAILURE) { close_ports(); return 1; }
    return 0;
}
int JVlibForm::change_2(int A, int B) {
    unsigned char buf[2];
    buf[0] = A;
    buf[1] = B;
    if (open_ports() == EXIT_FAILURE) return 1;
    if (change_send(buf,2) == EXIT_FAILURE) { close_ports(); return 1; }
    return 0;
}
/*
int JVlibForm::sysex_send(unsigned char *buf, int buf_size) {
  // incoming buffer must contain 4 empty bytes at the beginning, then have 0x11 or 0x12 in place [4]
  if (!state_table->jv_connect) return EXIT_FAILURE;
  int	err;
  char    JV_header[4] = { 0xF0,0x41,0x10,0x6A };
  // set to blocking mode
  snd_rawmidi_nonblock(midiInHandle, 0);
  snd_rawmidi_drop(midiOutHandle);
  for (int x=0;x<4;x++) buf[x]=JV_header[x];
  // transmit the data
  if (!state_table->midiPorts_open)
    if (open_ports() == EXIT_FAILURE) return(EXIT_FAILURE);
  if ((err = snd_rawmidi_write(midiOutHandle, buf, buf_size)) < 0) { 
    QMessageBox::critical(0, "JVlib", tr("Cannot write to MIDI output\n%1") .arg(snd_strerror(err)));
    return(EXIT_FAILURE);
  }
  snd_rawmidi_drain(midiOutHandle);
  close_ports();
  return(err);  
}	// end SYSEX_SEND
*/
int JVlibForm::sysex_request(const unsigned char *buf, int buf_size) {
  if (!state_table->jv_connect) return EXIT_FAILURE;
  unsigned char *SysEx = new unsigned char[buf_size+7];
  char    JV_header[5] = { 0xF0,0x41,0x10,0x6A,0x11 };
  for (int x=0;x<5;x++) SysEx[x]=JV_header[x];
  SysEx[2] = state_table->Dev_ID-1;
  for (int x=0;x<buf_size;x++) SysEx[x+5] = buf[x];
  SysEx[buf_size+5] = chksum(&SysEx[5], buf_size);
  SysEx[buf_size+6] = 0xF7;
  // transmit the data
  int rc = JVlibForm::change_send(SysEx, buf_size+7);
  delete[] SysEx;
  return rc;
}	// end SYSEX_SEND

int JVlibForm::sysex_update(const unsigned char *buf, int buf_size) {
  if (!state_table->jv_connect) return EXIT_FAILURE;
  unsigned char *SysEx = new unsigned char[buf_size+7];
  char    JV_header[5] = { 0xF0,0x41,0x10,0x6A,0x12 };
  for (int x=0;x<5;x++) SysEx[x]=JV_header[x];
  SysEx[2] = state_table->Dev_ID-1;
  for (int x=0;x<buf_size;x++) SysEx[x+5] = buf[x];
  SysEx[buf_size+5] = chksum(&SysEx[5], buf_size);
  SysEx[buf_size+6] = 0xF7;
  // transmit the data
//JVlibForm::hexdump(SysEx, buf_size+7);
  int rc = change_send(SysEx, buf_size+7);
  delete[] SysEx;
  return rc;
}	// end SYSEX_SEND

int JVlibForm::sysex_get(unsigned char *buf, char *req_size) {
  if (!state_table->jv_connect) return EXIT_FAILURE;
  int	data_size,x,buf_size,read;
  register int err;
  int npfds, time;
  int timeout = 2000;
  struct pollfd *pfds;
  unsigned char	recv_buf[256];
  unsigned char hold_buf[512];
  unsigned short revents;
  snd_rawmidi_status_t *ptr;
  
  if (!state_table->midiPorts_open)
    if (open_ports() == EXIT_FAILURE) return(EXIT_FAILURE);
  // calculate data size
  data_size = req_size[0] * 0x80*0x80*0x80;
  data_size += req_size[1] * 0x80*0x80;
  data_size += req_size[2] * 0x80;
  data_size += req_size[3];
  buf_size=data_size+11;
  // set up polling structs, prepare for reading data
  time=0;
  npfds = snd_rawmidi_poll_descriptors_count(midiInHandle);
  pfds = new pollfd;
  snd_rawmidi_poll_descriptors(midiInHandle, pfds, npfds);
  snd_rawmidi_nonblock(midiInHandle,1);		// set to nonblocking mode
  memset(recv_buf,0,sizeof(recv_buf));
  read=0;
  // big loop to read data
  for (;;) {
    err = poll(pfds, npfds, 200);
    // process poll status/errors
    if (err < 0 && errno == EINTR) break;
    if (err < 0) { printf("poll failed: %s", strerror(errno)); break; }
    // timeout (or correct amount of data) are the only good ways to exit this loop
    if (err == 0) {
      time += 200;
      if (timeout && time >= timeout) {puts("#### TIMEOUT ####"); break; }
      usleep(40000); continue;
    }
    if ((err = snd_rawmidi_poll_descriptors_revents(midiInHandle, pfds, npfds, &revents)) < 0) {
      printf("Cannot get poll events: %s\n", snd_strerror(err));
      break;
    }
    if (revents & (POLLERR | POLLHUP)) break;
    if (!(revents & POLLIN)) { usleep(40000); continue; }	// loop if no data and still polling
    // read the incoming data
    err = snd_rawmidi_read(midiInHandle, recv_buf, sizeof(recv_buf));
    if (err == -EAGAIN) { usleep(40000); continue; }
    if (err < 0) {
      printf("cannot read from port \"%s\": %s", MIDI_dev, snd_strerror(err));
      delete pfds;
      return(2);	// signal possible retry to calling routine
    }
    if (err == 0) { usleep(40000); continue; }
    time = 0;	// data received, reset the timeout value
    memcpy(hold_buf+read, recv_buf, err);
    read += err;
    if (read >= buf_size) break;
  }	// end FOR bigloop
  // pause before parsing data and returning
  usleep(40000);
  // validate the data received
  if ((x=chksum((unsigned char *)&hold_buf[5], buf_size-7)) != hold_buf[buf_size-2]) { 
    // We need to get a snd_rawmidi_status_t struct
    if ((err = snd_rawmidi_status_malloc(&ptr)) < 0)
      printf("Can't get snd_rawmidi_status_t: %s\n", snd_strerror(err));
    else {
      // Tell ALSA to fill in our snd_rawmidi_status_t struct with this device's status
      if ((err = snd_rawmidi_status(midiInHandle, ptr)) < 0)
	  printf("Can't get status: %s\n", snd_strerror(err));
      else {
	err = snd_rawmidi_status_get_xruns(ptr);
	if (err != 0) printf("There are %i overrun errors\n", err);
      }
      // Free the snd_rawmidi_status_t struct when done
      snd_rawmidi_status_free(ptr);
    }
    delete pfds;
    return(3);	// signal possible retry to calling routine
  }
  if (hold_buf[buf_size-1] != 0xF7) { 
    puts("#### Incomplete data received! ####");
    // We need to get a snd_rawmidi_status_t struct
    if ((err = snd_rawmidi_status_malloc(&ptr)) < 0)
      printf("Can't get snd_rawmidi_status_t: %s\n", snd_strerror(err));
    else {
      // Tell ALSA to fill in our snd_rawmidi_status_t struct with this device's status
      if ((err = snd_rawmidi_status(midiInHandle, ptr)) < 0)
	  printf("Can't get status: %s\n", snd_strerror(err));
      else {
	err = snd_rawmidi_status_get_xruns(ptr);
	if (err != 0) printf("There are %i overrun errors\n", err);
      }
      // Free the snd_rawmidi_status_t struct when done
      snd_rawmidi_status_free(ptr);
    }
    delete pfds;
    return(2);	// signal possible retry to calling routine
  }
  // valid data, copy to the request buffer
  memcpy(buf, (char *)hold_buf+9, data_size);
  delete pfds;
  return EXIT_SUCCESS;
}	// end SYSEX_GET

void	JVlibForm::close_ports() {
  if (state_table->midiPorts_open == true) {
    snd_rawmidi_close(midiInHandle);
    snd_rawmidi_close(midiOutHandle);
    state_table->midiPorts_open = false;
  }
}  // end CLOSE_PORTS

int JVlibForm::open_ports() {
  int err;
  if (state_table->midiPorts_open) return EXIT_SUCCESS;
  if (strlen(MIDI_dev)) {
    if ((err = snd_rawmidi_open(&midiInHandle, &midiOutHandle, MIDI_dev, 0)) < 0) {
	QMessageBox::critical(0, "JVlib", tr("Cannot open MIDI port %1\n%2") .arg(MIDI_dev) .arg(snd_strerror(err)));
	return EXIT_FAILURE;
    }
    // dummy read to activate the ports
    if ((err = snd_rawmidi_read(midiInHandle, NULL, 0)) < 0) { 
	QMessageBox::critical(0, "JVlib", tr("Cannot read from MIDI port %1\n%2") .arg(MIDI_dev) .arg(snd_strerror(err)));
	close_ports();
	return EXIT_FAILURE;
      }
    } else {
      QMessageBox::critical(0, "JVlib", tr("No MIDI port selected"));
      return EXIT_FAILURE;
    }
    state_table->midiPorts_open = true;
  return EXIT_SUCCESS;
}	// end OPEN_PORTS

short int JVlibForm::chksum(unsigned char *buf, int buf_size) {
  int x,sum;
  sum=0;
  for(x=0;x<buf_size;x++) sum += buf[x];
  sum %= 0x80;
  sum = 0x80-sum;
  sum &= 0x7F;
  return sum;
}	// end CHKSUM

void JVlibForm::hexdump(unsigned char *buffer, int data_size) {
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
  return;
}	// end HEXDUMP

QString JVlibForm::funcNoteCalc(int val) {
  char note_name[] = "C C#D D#E F F#G G#A A#B ";
  char note_octave[] = "-1 0 1 2 3 4 5 6 7 8 9";
  char note_buffer[4];

  memcpy(note_buffer,&note_name[(val%12)*2],2);
  memcpy(note_buffer+2,&note_octave[(val/12)*2],2);
  QString QNoteBuf = QString::fromAscii(note_buffer,4);
  emit noteval(&QNoteBuf);
  return QNoteBuf;
}	// end funcNoteCalc

QString JVlibForm::Pan2Deg(int val) {
  // val ranges between -64 to +63, where 0 is center
  QString buf = "";
  if (val == 0)
    buf = "Center";
  else if (val < 0)
    buf = "L"+QString::number((val*90)/(-64))+QString(" Deg.");
  else 
    buf = "R"+QString::number((val)*90/63)+QString(" Deg.");
  return buf;
}	// end Pan2Deg

void JVlibForm::on_MainTabWidget_currentChanged(int val) {
  // set focus for each Tab when it is selected
  switch(val) {
    case 0:
      SysMode_select->setFocus();
      break;
    case 1:
      PerfSync_button->setFocus();
      break;
    case 2:
      PartsPerfName_display->setFocus();
      break;
    case 3:
      Patch_Sync_button->setFocus();
      break;
    case 4:
      Rhythm_Sync_button->setFocus();
    case 5:
      PatchEFX_Type_select->setFocus();
      break;
    case 6:
      ToneSync_button->setFocus();
      break;
    case 7:
      ToneEFX_PanControl_select->setFocus();
      break;
    case 8:
      ToneTVF_FilterType_select->setFocus();
      break;
    case 9:
      break;
    case 10:
      Pitch_KeyFollow_select->setFocus();
      break;
    case 11:
      Tuning_MasterTune_select->setFocus();
      break;
    default:
      SysMode_select->setFocus();
      break;
  }
}	// end on_MainTabWidget_currentChanged
