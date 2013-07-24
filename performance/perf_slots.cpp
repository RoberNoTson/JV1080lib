// perf_slots.cpp
#include	"JVlibForm.h"
#include	<QtGui>
#include	"perf_slots.h"

void JVlibForm::on_PerfGroup_select_currentIndexChanged(int val) {
  SysPerfSelect->setCurrentIndex(val);
}
void JVlibForm::on_PerfNumber_select_valueChanged(int val) {
  SysPerfNumber->setValue(val);
}

void JVlibForm::on_PerfSync_button_clicked() {
  // called when the Performance tab Sync button is clicked
  JVlibForm::statusbar->showMessage("Getting performance common",0);
  getActivePerfCommon();
  JVlibForm::statusbar->showMessage("Getting Performance parms",0);
  setPerfParms();
  EnablePerf(true);
  statusbar->showMessage("Performance loaded",0);
}	// end on_PerfSync_button_clicked

void JVlibForm::on_PerfChorusLevel_select_valueChanged(int val) {
  setPerfSingleValue(0x22, val);
}
void JVlibForm::on_PerfChorusRate_select_valueChanged(int val) {
  setPerfSingleValue(0x23, val);
}
void JVlibForm::on_PerfChorusDepth_select_valueChanged(int val) {
  setPerfSingleValue(0x24, val);
}
void JVlibForm::on_PerfChorusPreDelay_select_valueChanged(int val) {
  setPerfSingleValue(0x25, val);
}
void JVlibForm::on_PerfChorusFeedback_select_valueChanged(int val) {
  setPerfSingleValue(0x26, val);
}
void JVlibForm::on_PerfChorusOutput_select_currentIndexChanged(int val) {
  setPerfSingleValue(0x27, val);
}
void JVlibForm::on_PerfReverbType_select_currentIndexChanged(int val) {
  if (state_table->updates_enabled) {
    setPerfSingleValue(0x28, val);
    if (val > 5) {
      PerfReverbFeedback_select->setEnabled(true);
      PerfReverbFeedback_display->setEnabled(true);
    } else {
      PerfReverbFeedback_select->setEnabled(false);
      PerfReverbFeedback_display->setEnabled(false);
    }
  }	// end updates_enabled
}	// end on_PerfReverbType_select_currentIndexChanged
void JVlibForm::on_PerfReverbLevel_select_valueChanged(int val) {
  setPerfSingleValue(0x29, val);
}
void JVlibForm::on_PerfReverbTime_select_valueChanged(int val) {
  setPerfSingleValue(0x2A, val);
}
void JVlibForm::on_PerfReverbHiFreqDamp_select_currentIndexChanged(int val) {
  setPerfSingleValue(0x2B, val);
}
void JVlibForm::on_PerfReverbFeedback_select_valueChanged(int val) {
  setPerfSingleValue(0x2C, val);
}
void JVlibForm::on_PerfDefaultTempo_select_valueChanged(int val) {
  if (state_table->updates_enabled) {
    int HVal = val/16;
    int LVal = val%16;
    active_area->active_performance.perf_common.default_tempo_high = HVal;
    active_area->active_performance.perf_common.default_tempo_low = LVal;
    if (state_table->jv_connect) {
      unsigned char buf[13];
      memset(buf,0,sizeof(buf));
      buf[4] = JV_UPD;
      buf[5] = 0x01;
      buf[8] = 0x2D;
      buf[9] = HVal;
      buf[10] = LVal;
      buf[11] = chksum(buf+5, 6);
      buf[12] = 0xF7;
      if (open_ports() == EXIT_FAILURE) return;
      if (sysex_send(buf,13) == EXIT_FAILURE) {
	close_ports();
	return;
      }
      close_ports();
    }	// end state_table->jv_connect
  }	// end state_table->updates_enabled
}	// end on_PerfDefaultTempo_select_valueChanged

void JVlibForm::on_PerfName_edit_editingFinished() {
  if (state_table->updates_enabled) {
  if (PerfName_edit->isModified()) {
    QString val = PerfName_edit->text();
    // change the Performance name
    // update the System and Parts tabs with new Perf Name when updated from the Perf tab
    val = val.leftJustified(12, ' ');
    SysPerfName->setText(val);
    PartsPerfName_display->setText(val);
    // update memory and the synth with the new Name
    memcpy(&active_area->active_performance.perf_common.name[0],val.toAscii(),12);
    //  setPerfMultiValue(0x00, val.toAscii(), 12);
    unsigned char buf[23];
    if (state_table->updates_enabled) {
      memset(buf,0,sizeof(buf));
      buf[4] = JV_UPD;
      buf[5] = 0x01;
      memcpy(&buf[9], &active_area->active_performance.perf_common.name[0], 12);
      buf[21] = chksum(buf+5, 16);
      buf[22] = 0xF7;
      if (open_ports() == EXIT_FAILURE) return;
      if (sysex_send(buf,sizeof(buf)) == EXIT_FAILURE) { close_ports(); return; }
      close_ports();
    } // end IF
    PerfName_edit->setModified(false);
  }	// end PerfName_edit->isModified
 }	// end updates_enabled 
}	// end on_PerfName_edit_editingFinished
