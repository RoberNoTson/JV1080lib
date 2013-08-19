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

