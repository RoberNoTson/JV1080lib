// tone.cpp
#include	"JVlibForm.h"
#include	<QtGui>

void JVlibForm::setWaveChooser() {
  // point InstrFamily to the correct value based on selected Group/Number
  // then fill WaveChooser based on that index value and point to the matching index
   QSqlQuery WaveQuery(mysql);
   QString buf = "";
   WaveQuery.prepare("Select Instruments from wave_list where group_area = ? and number = ?");
   switch(Tone_Group_select->currentIndex()) {
     case 0:
       WaveQuery.bindValue(0, "Internal A");
       break;
     case 1:
       WaveQuery.bindValue(0, "Internal B");
       break;
     case 2:
       WaveQuery.bindValue(0, "Expansion A");
       break;
     case 3:
       WaveQuery.bindValue(0, "Expansion B");
       break;
     case 4:
       WaveQuery.bindValue(0, "Expansion C");
       break;
     default:
       printf("Error! Tone_Group_select currentIndex is %d\n",Tone_Group_select->currentIndex());
       return;
       break;       
   }       
   WaveQuery.bindValue(1, Tone_Number_select->value());
   if (WaveQuery.exec() == false) {
     puts("Query exec failed in setWaveChooser");
     return;
   }
   if (WaveQuery.size()==0) {
         puts("0 rows found in setWaveChooser()"); 
	 return;
   }
   WaveQuery.first();
   buf = WaveQuery.value(0).toString();
   WaveQuery.finish();
   // setting the index will call on_Tone_InstrFamily_select_currentIndexChanged() to fill Tone_WaveChooser_select with valid waves from the database
   Tone_InstrFamily_select->setCurrentIndex(Tone_InstrFamily_select->findText(buf));
   // set WaveChooser to the entry matching the displayed Tone_Group/Number
   buf = Tone_Group_select->currentText()+QString(" ")+QString::number(Tone_Number_select->value());
//printf("WaveChooser searching for %s\n",(char *) buf.toAscii().constData());
   int x = Tone_WaveChooser_select->findText(buf, Qt::MatchContains);
   if (x<0) puts("Index NOT FOUND in setWaveChooser");
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
   switch(Tone_Group_select->currentIndex()) {
     case 0:
       WaveQuery.bindValue(0, "Internal A");
       break;
     case 1:
       WaveQuery.bindValue(0, "Internal B");
       break;
     case 2:
       WaveQuery.bindValue(0, "Expansion A");
       break;
     case 3:
       WaveQuery.bindValue(0, "Expansion B");
       break;
     case 4:
       WaveQuery.bindValue(0, "Expansion C");
       break;
     default:
       WaveQuery.bindValue(0, "Internal A");
       break;       
   }       
   WaveQuery.bindValue(1, Tone_Number_select->value());
   if (WaveQuery.exec() == false) {
     puts("Query exec failed");
     return buf;
   }
   if (WaveQuery.size()==0) {
         puts("0 rows found in WaveName_query"); 
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
