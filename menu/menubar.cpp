// menubar.cpp
#include	"JVlibForm.h"
#include	<QtGui>

bool JVlibForm::maybeSave() {
  if (state_table->system_modified ||
    state_table->performance_modified ||
    state_table->parts_modified ||
    state_table->patch_modified ||
    state_table->rhythm_modified ||
    state_table->tone_modified ||
    state_table->tuning_modified) {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, "JVlib", "The settings have been modified.\nDo you want to save your changes?", 
	    QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (ret == QMessageBox::Save)
          return save();
        else if (ret == QMessageBox::Cancel)
          return false;
  }
  return true;
}

void JVlibForm::loadFile(const QString &fileName) {
  QFile file(fileName);
  QDataStream datastream;
  char *inAddr = NULL;
  int dataSize = 0;
    
  if (!file.open(QFile::ReadOnly | QFile::Text)) {
    QMessageBox::warning(this, "JVlib",
                            tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
    return;
  }
  switch(MainTabWidget->currentIndex()) {
    case 0:
      inAddr = &system_area->sys_common.panel_mode;
      // dataSize = file.size();
      dataSize = 0x28;
      break;
    default:
      inAddr = NULL;
      dataSize = 0;
      break;
  }
  datastream.readRawData(inAddr, dataSize);
  file.close();
  setCurrentFile(fileName);
  statusBar()->showMessage("File loaded", 2000);
}	// loadFile

bool JVlibForm::saveFile(const QString &fileName) {
  QFile file(fileName);
    
  if (!file.open(QFile::WriteOnly | QFile::Text)) {
    QMessageBox::warning(this, "JVlib", tr("Cannot write file %1:\n%2.") .arg(fileName) .arg(file.errorString()));
    return false;
  }
  QDataStream datastream(&file);
  char *inAddr = NULL;
  int dataSize;
  switch(MainTabWidget->currentIndex()) {
    case 0:
      inAddr = &system_area->sys_common.panel_mode;
      dataSize = 0x28;
      break;
    default:
      inAddr = NULL;
      dataSize = 0;
      break;
  }
  datastream.writeRawData(inAddr, dataSize);
  file.close();
  setCurrentFile(fileName);
  statusBar()->showMessage("File saved", 2000);
  state_table->system_modified = false;
  state_table->performance_modified = false;
  state_table->parts_modified = false;
  state_table->patch_modified = false;
  state_table->rhythm_modified = false;
  state_table->tone_modified = false;
  state_table->tuning_modified = false;
  return true;
}	//saveFile

void JVlibForm::setCurrentFile(const QString &fileName) {
    curFile = fileName;
    setWindowModified(false);

    QString shownName = curFile;
    if (curFile.isEmpty())
        shownName = "untitled.jv";
    setWindowFilePath(shownName);
}	// setCurrentFile

QString JVlibForm::strippedName(const QString &fullFileName) {
    return QFileInfo(fullFileName).fileName();
}

void JVlibForm::getPort() {
  signed int card_num=-1;
  signed int dev_num=-1;
  signed int subdev_num=-1;
  int err,i;
  char	buf[64];
  char	str[64];
  snd_rawmidi_info_t  *rawMidiInfo;
  snd_ctl_t *cardHandle;

  PortBox->clear();
  err = snd_card_next(&card_num);
  if (err < 0) {
    // no MIDI cards found in the system
    memset(MIDI_dev,0,sizeof(MIDI_dev));
    snd_card_next(&card_num);
    return;
  }
  while (card_num >= 0) {
    // Open this card's control interface. We specify only the card number -- not
    // any device nor sub-device too
    sprintf(str, "hw:%i", card_num);
    if ((err = snd_ctl_open(&cardHandle, str, 0)) < 0) break;
    dev_num = -1;
    err = snd_ctl_rawmidi_next_device(cardHandle, &dev_num);
    if (err < 0) { 
      // card exists, but no midi device was found
      snd_card_next(&card_num);
      continue;
    }
    while (dev_num >= 0) {
      snd_rawmidi_info_alloca(&rawMidiInfo);
      memset(rawMidiInfo, 0, snd_rawmidi_info_sizeof());
      // Tell ALSA which device (number) we want info about
      snd_rawmidi_info_set_device(rawMidiInfo, dev_num);
      // Get info on the MIDI outs of this device
      snd_rawmidi_info_set_stream(rawMidiInfo, SND_RAWMIDI_STREAM_OUTPUT);
      i = -1;
      subdev_num = 1;
      // More subdevices?
      while (++i < subdev_num) {
	// Tell ALSA to fill in our snd_rawmidi_info_t with info on this subdevice
	snd_rawmidi_info_set_subdevice(rawMidiInfo, i);
	if ((err = snd_ctl_rawmidi_info(cardHandle, rawMidiInfo)) < 0) continue;
	// Print out how many subdevices (once only)
	if (!i) {
	  subdev_num = snd_rawmidi_info_get_subdevices_count(rawMidiInfo);
	}
	// got a valid card, dev and subdev
	// Tell ALSA to fill in our snd_rawmidi_info_t with info on this subdevice
	memset(buf,0,sizeof(buf));
	sprintf(buf,"hw:%i,%i,%i %s %i", card_num, dev_num, i, snd_rawmidi_info_get_name(rawMidiInfo),dev_num*16+i+1);
	PortBox->insertItem(9999, QString::fromAscii(buf));
      }	// end WHILE subdev_num
      snd_ctl_rawmidi_next_device(cardHandle, &dev_num);
    }	// end WHILE dev_num
    snd_ctl_close(cardHandle);
    err = snd_card_next(&card_num);
  }	// end WHILE card_num
}	// end get_port()

