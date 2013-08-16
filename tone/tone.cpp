// tone.cpp
#include	"JVlibForm.h"
#include	<QtGui>
#include	<QDebug>

void JVlibForm::setWaveChooser() {
  // point InstrFamily to the correct value based on selected Group/Number
  // then fill WaveChooser based on that index value and point to the matching index
   QSqlQuery WaveQuery(mysql);
   QString buf = "";
   WaveQuery.prepare("Select distinct(Instruments) from wave_list where group_area = ? and number = ?");
   WaveQuery.bindValue(0, Tone_Group_select->currentText());
   WaveQuery.bindValue(1, Tone_Number_select->value());
//printf("setWaveChooser bound group_area = %s and number = %d\nShould bind %s, %d\n", WaveQuery.boundValue(0).toByteArray().data(), WaveQuery.boundValue(1).toInt(), Tone_Group_select->currentText().toAscii().data(), Tone_Number_select->value());
   // run the Query
   if (WaveQuery.exec() == false) {
     qDebug() << "Query exec failed in setWaveChooser";
     QMessageBox::critical(this, "JVlib", QString("Query failed in setWaveChooser for query\n%1") .arg(WaveQuery.executedQuery()));
     return;
   }
   if (WaveQuery.size()==0) {
      qDebug() << "0 rows found in setWaveChooser()"; 
      QMessageBox::critical(this, "JVlib", QString("0 rows returned in setWaveChooser for query\n%1") .arg(WaveQuery.executedQuery()));
      return;
   }
   if (WaveQuery.size()>1) {
        qDebug() << "Too many rows found in setWaveChooser()"; 
	QMessageBox::critical(this, "JVlib", QString("Too many rows returned in setWaveChooser for query\n%1") .arg(WaveQuery.executedQuery()));
	return;
   }
//printf("setWaveChooser queried for %s\n",WaveQuery.lastQuery().toAscii().data());
   WaveQuery.first();
   buf = WaveQuery.value(0).toString();
   WaveQuery.finish();
   
//printf("WaveChooser setting Instrument family to %s\n",buf.toAscii().data());
   // setting the index will call on_Tone_InstrFamily_select_currentIndexChanged() to fill Tone_WaveChooser_select with valid waves from the database
   int x = Tone_InstrFamily_select->findText(buf);
   if (x < 0) {
     printf("setWaveChooser did not find InstrFamily %s\n",buf.toAscii().data());
     QMessageBox::critical(this, "JVlib", QString("Text NOT FOUND in setWaveChooser\n%1") .arg(buf));
     return;     
   }
   Tone_InstrFamily_select->setCurrentIndex(x);
//printf("WaveChooser set InstrFam index to %d\n",x);

   // set WaveChooser to the entry matching the displayed Tone_Group/Number
   buf = Tone_Group_select->currentText()+QString(" ")+QString::number(Tone_Number_select->value());
//printf("searching WaveChooser for %s\n",buf.toAscii().data());
   
   x = Tone_WaveChooser_select->findText(buf, Qt::MatchEndsWith);
   if (x<0) {
     qDebug() << "setWaveChooser did not find requested text";
     QMessageBox::critical(this, "JVlib", QString("Text NOT FOUND in setWaveChooser\n%1") .arg(buf));
     return;
   }
//printf("WaveChooser setting its Index to %d\n", x);
   // have to block the SIGNAL when we set WaveChooser to prevent an infinite loop
   Tone_WaveChooser_select->blockSignals(true);
   Tone_WaveChooser_select->setCurrentIndex(x);
   Tone_WaveChooser_select->blockSignals(false);
   Tone_WaveName_display->setText(WaveName_query());
}	// end setWaveChooser

QString JVlibForm::WaveName_query() {
   QSqlQuery WaveQuery(mysql);
   QString buf = "";
   WaveQuery.prepare("Select name from wave_list where group_area = ? and number = ?");
   WaveQuery.bindValue(0, Tone_Group_select->currentText());
   WaveQuery.bindValue(1, Tone_Number_select->value());
   if (WaveQuery.exec() == false) {
     qDebug() << "Query exec failed";
     QMessageBox::critical(this, "JVlib", QString("0 rows returned in setWaveChooser for query\n%1") .arg(WaveQuery.executedQuery()));
     return buf;
   }
   if (WaveQuery.size()==0) {
        qDebug() << "0 rows found in WaveName_query";
	QMessageBox::critical(this, "JVlib", QString("Query failed in setWaveChooser for query\n%1") .arg(WaveQuery.executedQuery()));
	return buf;
   }
   WaveQuery.first();
   buf = WaveQuery.value(0).toString();
   buf = buf.leftJustified(12, ' ');
   WaveQuery.finish();
   return buf;
}

void JVlibForm::Enable_Tone(bool val) {
  Tone_Number_select->setEnabled(val);
  Tone_Group_select->setEnabled(val);
  Tone_WaveName_display->setEnabled(val);
  Tone_Output_select->setEnabled(val);
  Tone_InstrFamily_select->setEnabled(val);
  Tone_WaveChooser_select->setEnabled(val);
  Tone_C1D1_select->setEnabled(val);
  Tone_C1D2_select->setEnabled(val);
  Tone_C1D3_select->setEnabled(val);
  Tone_C1D4_select->setEnabled(val);
  Tone_C2D1_select->setEnabled(val);
  Tone_C2D2_select->setEnabled(val);
  Tone_C2D3_select->setEnabled(val);
  Tone_C2D4_select->setEnabled(val);
  Tone_C3D1_select->setEnabled(val);
  Tone_C3D2_select->setEnabled(val);
  Tone_C3D3_select->setEnabled(val);
  Tone_C3D4_select->setEnabled(val);
  Tone_WaveGain_select->setEnabled(val);
  Tone_DelayMode_select->setEnabled(val);
  Tone_ChorusSend_select->setEnabled(val);
  Tone_ReverbSend_select->setEnabled(val);
  Tone_OutputLevel_select->setEnabled(val);
  Tone_Level_select->setEnabled(val);
  Tone_VeloXfadeDepth_select->setEnabled(val);
  Tone_VeloLowerRange_select->setEnabled(val);
  Tone_DelayTime_select->setEnabled(val);
  Tone_VeloUpperRange_select->setEnabled(val);
  Tone_C1D1Depth_select->setEnabled(val);
  Tone_C1D2Depth_select->setEnabled(val);
  Tone_C1D3Depth_select->setEnabled(val);
  Tone_C1D4Depth_select->setEnabled(val);
  Tone_C2D1Depth_select->setEnabled(val);
  Tone_C2D2Depth_select->setEnabled(val);
  Tone_C2D3Depth_select->setEnabled(val);
  Tone_C2D4Depth_select->setEnabled(val);
  Tone_C3D1Depth_select->setEnabled(val);
  Tone_C3D2Depth_select->setEnabled(val);
  Tone_C3D3Depth_select->setEnabled(val);
  Tone_C3D4Depth_select->setEnabled(val);
  Tone_ReceiveVolume_enable->setEnabled(val);
  Tone_ReceiveHold_enable->setEnabled(val);
  Tone_ReceiveReDamper_enable->setEnabled(val);
  Tone_ReceiveBender_enable->setEnabled(val);
  Enable_ToneEFX(val);
  if (val) Tone_Sync_status->on();
  else Tone_Sync_status->off();
  state_table->tone_sync = val;
  state_table->toneTab_enable = val;
}	// end Enable_Tone
