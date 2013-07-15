#ifndef JVlibForm_H
#define JVlibForm_H

#include	<QtGui>
#include	<QtGui/QMainWindow>
#include	<QtSql>
#include	<QThread>
#include	"ui_JVlib.h"
#include	"ui_Save_Dialog.h"
#include	"JV-struct-defs.h"
#include	"State_Table.h"
#include	<alsa/asoundlib.h>
#include	<iostream>

#ifndef MAX_RETRIES
#define	MAX_RETRIES 4	//number of times to retry after a timeout
#endif
#ifndef MAX_DEVICES
#define	MAX_DEVICES 16
#endif
#ifndef JV_REQ
#define JV_REQ 0x11
#endif
#ifndef JV_UPD
#define JV_UPD 0x12
#endif

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QDialog;
QT_END_NAMESPACE

class Save_Dialog: public QDialog, private Ui::Save_Dialog
{
  Q_OBJECT
public:
  Save_Dialog();
  
private slots:
  void slotSaveDialog_accept();
  void slotSaveDialog_cancel();
  void slotSaveDialog_help();
  void slotSave_System(bool);
  void slotSave_Performance(bool);
  void slotSave_Patch(bool);
  void slotSave_Rhythm(bool);
  void slotSave_Tuning(bool);
  void slotSave_UserPerformance(bool);
  void slotSave_UserPatch(bool);
  void slotSave_UserRhythm(bool);
  void slotSave_UserDump(bool);
  
private:
  void createSaveDialogActions();
};

class JVlibForm : public QMainWindow, private Ui::JVlibForm
{
  friend class Save_Dialog;
  
  Q_OBJECT

public:
  JVlibForm();
  ~JVlibForm();

signals:
  void	noteval(const QString *);
  
protected:
  void closeEvent(QCloseEvent *event);

private slots:
  // for menubar.cpp
  void open();
  bool save();
  bool saveAs();
  void about();
  void selectedPort();
  void HelpDoc();
  void slotConfig();
  void slotOffline();
  void slotactionCopy();
  void slotactionWrite();
  void slotactionBulk_Dump(); 
  void slotactionWhats_This();
  QString funcNoteCalc(int);
  QString Pan2Deg(int);
  
  // for System tab
  void slotSysSetPerf();
  void slotSysSetPatch();
  void slotSysSetPerformanceMode();
  void slotSysSetPatchMode();
  void slotSysSetGmMode();
  void on_SysMode_select_currentIndexChanged(int);
  int on_System_Sync_button_clicked();
  void on_SysPatchNumber_valueChanged(int);
  void on_SysPerfNumber_valueChanged(int);
  void on_SysClock_select_currentIndexChanged(int);
  void on_SysTapControl_select_currentIndexChanged(int);
  void on_SysHoldControl_select_currentIndexChanged(int);
  void on_SysPeakControl_select_currentIndexChanged(int);
  void on_SysVolumeControl_select_currentIndexChanged(int);
  void on_SysAftertouchControl_select_currentIndexChanged(int);
  void on_SysPatchRecvChannel_select_valueChanged(int);
  void on_SysControlRecvChannel_select_valueChanged(int);
  void on_System_Upload_button_clicked();
  void on_System_LoadData_button_clicked();
  void on_System_SaveData_button_clicked();
  void on_EFX_switch_stateChanged(int);
  void on_Chorus_switch_stateChanged(int);
  void on_Reverb_switch_stateChanged(int);
  void on_PatchRemain_switch_stateChanged(int);
  void on_AcceptProgramChg_switch_stateChanged(int);
  void on_AcceptBankSel_switch_stateChanged(int);
  void on_AcceptControlChange_switch_stateChanged(int);
  void on_AcceptModulation_switch_stateChanged(int);
  void on_AcceptVolumeChg_switch_stateChanged(int);
  void on_AcceptHold1Chg_switch_stateChanged(int);
  void on_AcceptBender_switch_stateChanged(int);
  void on_AcceptAftertouch_switch_stateChanged(int);
  void on_SysPreviewMode_switch_toggled(bool);
  void on_SysPreviewNote1_select_valueChanged(int);
  void on_SysPreviewNote2_select_valueChanged(int);
  void on_SysPreviewNote3_select_valueChanged(int);
  void on_SysPreviewNote4_select_valueChanged(int);
  void on_SysPreviewNote1_volume_valueChanged(int);
  void on_SysPreviewNote2_volume_valueChanged(int);
  void on_SysPreviewNote3_volume_valueChanged(int);
  void on_SysPreviewNote4_volume_valueChanged(int);
  void on_SysTestTone_button_clicked(bool);
  void on_SysPlayMidi_button_clicked();
  void on_SysPanic_button_clicked();
  void on_MainTabWidget_currentChanged(int);

  // for Performance tab
//  void slotPerfSetPerf();
  void on_PerfGroup_select_currentIndexChanged(int);
  void on_PerfNumber_select_valueChanged(int);
  void on_PerfSync_button_clicked();
  void on_PerfReverbTime_select_valueChanged(int);
  void on_PerfReverbFeedback_select_valueChanged(int);
  void on_PerfReverbLevel_select_valueChanged(int);
  void on_PerfChorusLevel_select_valueChanged(int);
  void on_PerfChorusRate_select_valueChanged(int);
  void on_PerfChorusDepth_select_valueChanged(int);
  void on_PerfChorusPreDelay_select_valueChanged(int);
  void on_PerfChorusFeedback_select_valueChanged(int);
  void on_PerfDefaultTempo_select_valueChanged(int);
  void on_PerfReverbHiFreqDamp_select_currentIndexChanged(int);
  void on_PerfReverbType_select_currentIndexChanged(int);
  void on_PerfChorusOutput_select_currentIndexChanged(int);
  void on_PerfName_edit_editingFinished();
  
  // for Parts tab
  void on_Part1_PatchNumber_select_valueChanged(int);
  void on_Part1_PatchGroup_select_currentIndexChanged(int);
  void on_PartsRangeLimitEnable_select_toggled(bool);
  void on_Part1_Transpose_select_valueChanged(int);
  void on_Part1_TuneAdj_select_valueChanged(int);
  void on_Part1_VoiceReserve_select_valueChanged(int);
  void on_Part1_LowLimit_select_valueChanged(int);
  void on_Part1_HighLimit_select_valueChanged(int);
  void on_Part1_Level_select_valueChanged(int);
  void on_Part1_Pan_select_valueChanged(int);
  void on_Part1_ChorusSend_select_valueChanged(int);
  void on_Part1_ReverbSend_select_valueChanged(int);
  void on_Part1_OutputLevel_select_valueChanged(int);
  void on_Part1_ReceiveMidi_enable_toggled(bool);
  void on_Part1_ReceivePrgChg_enable_toggled(bool);
  void on_Part1_ReceiveVolume_enable_toggled(bool);
  void on_Part1_ReceiveHold_enable_toggled(bool);
  void on_Part1_Output_select_currentIndexChanged(int);
  void on_Part1_MidiChannel_select_valueChanged(int);
  void on_Part1_TestTone_switch_toggled(bool);
  void on_Part2_Transpose_select_valueChanged(int);
  void on_Part2_TuneAdj_select_valueChanged(int);
  void on_Part2_VoiceReserve_select_valueChanged(int);
  void on_Part2_LowLimit_select_valueChanged(int);
  void on_Part2_HighLimit_select_valueChanged(int);
  void on_Part2_PatchNumber_select_valueChanged(int);
  void on_Part2_PatchGroup_select_currentIndexChanged(int);
  void on_Part2_Level_select_valueChanged(int);
  void on_Part2_Pan_select_valueChanged(int);
  void on_Part2_ChorusSend_select_valueChanged(int);
  void on_Part2_ReverbSend_select_valueChanged(int);
  void on_Part2_OutputLevel_select_valueChanged(int);
  void on_Part2_ReceiveMidi_enable_toggled(bool);
  void on_Part2_ReceivePrgChg_enable_toggled(bool);
  void on_Part2_ReceiveVolume_enable_toggled(bool);
  void on_Part2_ReceiveHold_enable_toggled(bool);
  void on_Part2_Output_select_currentIndexChanged(int);
  void on_Part2_MidiChannel_select_valueChanged(int);
  void on_Part2_TestTone_switch_toggled(bool);
  void on_Part3_Transpose_select_valueChanged(int);
  void on_Part3_TuneAdj_select_valueChanged(int);
  void on_Part3_VoiceReserve_select_valueChanged(int);
  void on_Part3_LowLimit_select_valueChanged(int);
  void on_Part3_HighLimit_select_valueChanged(int);
  void on_Part3_PatchNumber_select_valueChanged(int);
  void on_Part3_PatchGroup_select_currentIndexChanged(int);
  void on_Part3_Level_select_valueChanged(int);
  void on_Part3_Pan_select_valueChanged(int);
  void on_Part3_ChorusSend_select_valueChanged(int);
  void on_Part3_ReverbSend_select_valueChanged(int);
  void on_Part3_OutputLevel_select_valueChanged(int);
  void on_Part3_ReceiveMidi_enable_toggled(bool);
  void on_Part3_ReceivePrgChg_enable_toggled(bool);
  void on_Part3_ReceiveVolume_enable_toggled(bool);
  void on_Part3_ReceiveHold_enable_toggled(bool);
  void on_Part3_Output_select_currentIndexChanged(int);
  void on_Part3_MidiChannel_select_valueChanged(int);
  void on_Part3_TestTone_switch_toggled(bool);
  void on_Part4_Transpose_select_valueChanged(int);
  void on_Part4_TuneAdj_select_valueChanged(int);
  void on_Part4_VoiceReserve_select_valueChanged(int);
  void on_Part4_LowLimit_select_valueChanged(int);
  void on_Part4_HighLimit_select_valueChanged(int);
  void on_Part4_PatchNumber_select_valueChanged(int);
  void on_Part4_PatchGroup_select_currentIndexChanged(int);
  void on_Part4_Level_select_valueChanged(int);
  void on_Part4_Pan_select_valueChanged(int);
  void on_Part4_ChorusSend_select_valueChanged(int);
  void on_Part4_ReverbSend_select_valueChanged(int);
  void on_Part4_OutputLevel_select_valueChanged(int);
  void on_Part4_ReceiveMidi_enable_toggled(bool);
  void on_Part4_ReceivePrgChg_enable_toggled(bool);
  void on_Part4_ReceiveVolume_enable_toggled(bool);
  void on_Part4_ReceiveHold_enable_toggled(bool);
  void on_Part4_Output_select_currentIndexChanged(int);
  void on_Part4_MidiChannel_select_valueChanged(int);
  void on_Part4_TestTone_switch_toggled(bool);
  void on_Part5_Transpose_select_valueChanged(int);
  void on_Part5_TuneAdj_select_valueChanged(int);
  void on_Part5_VoiceReserve_select_valueChanged(int);
  void on_Part5_LowLimit_select_valueChanged(int);
  void on_Part5_HighLimit_select_valueChanged(int);
  void on_Part5_PatchNumber_select_valueChanged(int);
  void on_Part5_PatchGroup_select_currentIndexChanged(int);
  void on_Part5_Level_select_valueChanged(int);
  void on_Part5_Pan_select_valueChanged(int);
  void on_Part5_ChorusSend_select_valueChanged(int);
  void on_Part5_ReverbSend_select_valueChanged(int);
  void on_Part5_OutputLevel_select_valueChanged(int);
  void on_Part5_ReceiveMidi_enable_toggled(bool);
  void on_Part5_ReceivePrgChg_enable_toggled(bool);
  void on_Part5_ReceiveVolume_enable_toggled(bool);
  void on_Part5_ReceiveHold_enable_toggled(bool);
  void on_Part5_Output_select_currentIndexChanged(int);
  void on_Part5_MidiChannel_select_valueChanged(int);
  void on_Part5_TestTone_switch_toggled(bool);
  void on_Part6_Transpose_select_valueChanged(int);
  void on_Part6_TuneAdj_select_valueChanged(int);
  void on_Part6_VoiceReserve_select_valueChanged(int);
  void on_Part6_LowLimit_select_valueChanged(int);
  void on_Part6_HighLimit_select_valueChanged(int);
  void on_Part6_PatchNumber_select_valueChanged(int);
  void on_Part6_PatchGroup_select_currentIndexChanged(int);
  void on_Part6_Level_select_valueChanged(int);
  void on_Part6_Pan_select_valueChanged(int);
  void on_Part6_ChorusSend_select_valueChanged(int);
  void on_Part6_ReverbSend_select_valueChanged(int);
  void on_Part6_OutputLevel_select_valueChanged(int);
  void on_Part6_ReceiveMidi_enable_toggled(bool);
  void on_Part6_ReceivePrgChg_enable_toggled(bool);
  void on_Part6_ReceiveVolume_enable_toggled(bool);
  void on_Part6_ReceiveHold_enable_toggled(bool);
  void on_Part6_Output_select_currentIndexChanged(int);
  void on_Part6_MidiChannel_select_valueChanged(int);
  void on_Part6_TestTone_switch_toggled(bool);
  void on_Part7_Transpose_select_valueChanged(int);
  void on_Part7_TuneAdj_select_valueChanged(int);
  void on_Part7_VoiceReserve_select_valueChanged(int);
  void on_Part7_LowLimit_select_valueChanged(int);
  void on_Part7_HighLimit_select_valueChanged(int);
  void on_Part7_PatchNumber_select_valueChanged(int);
  void on_Part7_PatchGroup_select_currentIndexChanged(int);
  void on_Part7_Level_select_valueChanged(int);
  void on_Part7_Pan_select_valueChanged(int);
  void on_Part7_ChorusSend_select_valueChanged(int);
  void on_Part7_ReverbSend_select_valueChanged(int);
  void on_Part7_OutputLevel_select_valueChanged(int);
  void on_Part7_ReceiveMidi_enable_toggled(bool);
  void on_Part7_ReceivePrgChg_enable_toggled(bool);
  void on_Part7_ReceiveVolume_enable_toggled(bool);
  void on_Part7_ReceiveHold_enable_toggled(bool);
  void on_Part7_Output_select_currentIndexChanged(int);
  void on_Part7_MidiChannel_select_valueChanged(int);
  void on_Part7_TestTone_switch_toggled(bool);
  void on_Part8_Transpose_select_valueChanged(int);
  void on_Part8_TuneAdj_select_valueChanged(int);
  void on_Part8_VoiceReserve_select_valueChanged(int);
  void on_Part8_LowLimit_select_valueChanged(int);
  void on_Part8_HighLimit_select_valueChanged(int);
  void on_Part8_PatchNumber_select_valueChanged(int);
  void on_Part8_PatchGroup_select_currentIndexChanged(int);
  void on_Part8_Level_select_valueChanged(int);
  void on_Part8_Pan_select_valueChanged(int);
  void on_Part8_ChorusSend_select_valueChanged(int);
  void on_Part8_ReverbSend_select_valueChanged(int);
  void on_Part8_OutputLevel_select_valueChanged(int);
  void on_Part8_ReceiveMidi_enable_toggled(bool);
  void on_Part8_ReceivePrgChg_enable_toggled(bool);
  void on_Part8_ReceiveVolume_enable_toggled(bool);
  void on_Part8_ReceiveHold_enable_toggled(bool);
  void on_Part8_Output_select_currentIndexChanged(int);
  void on_Part8_MidiChannel_select_valueChanged(int);
  void on_Part8_TestTone_switch_toggled(bool);
  void on_Part9_Transpose_select_valueChanged(int);
  void on_Part9_TuneAdj_select_valueChanged(int);
  void on_Part9_VoiceReserve_select_valueChanged(int);
  void on_Part9_LowLimit_select_valueChanged(int);
  void on_Part9_HighLimit_select_valueChanged(int);
  void on_Part9_PatchNumber_select_valueChanged(int);
  void on_Part9_PatchGroup_select_currentIndexChanged(int);
  void on_Part9_Level_select_valueChanged(int);
  void on_Part9_Pan_select_valueChanged(int);
  void on_Part9_ChorusSend_select_valueChanged(int);
  void on_Part9_ReverbSend_select_valueChanged(int);
  void on_Part9_OutputLevel_select_valueChanged(int);
  void on_Part9_ReceiveMidi_enable_toggled(bool);
  void on_Part9_ReceivePrgChg_enable_toggled(bool);
  void on_Part9_ReceiveVolume_enable_toggled(bool);
  void on_Part9_ReceiveHold_enable_toggled(bool);
  void on_Part9_Output_select_currentIndexChanged(int);
  void on_Part9_MidiChannel_select_valueChanged(int);
  void on_Part9_TestTone_switch_toggled(bool);
  void on_Part10_Transpose_select_valueChanged(int);
  void on_Part10_TuneAdj_select_valueChanged(int);
  void on_Part10_VoiceReserve_select_valueChanged(int);
  void on_Part10_LowLimit_select_valueChanged(int);
  void on_Part10_HighLimit_select_valueChanged(int);
  void on_Part10_PatchNumber_select_valueChanged(int);
  void on_Part10_PatchGroup_select_currentIndexChanged(int);
  void on_Part10_Level_select_valueChanged(int);
  void on_Part10_Pan_select_valueChanged(int);
  void on_Part10_ChorusSend_select_valueChanged(int);
  void on_Part10_ReverbSend_select_valueChanged(int);
  void on_Part10_OutputLevel_select_valueChanged(int);
  void on_Part10_ReceiveMidi_enable_toggled(bool);
  void on_Part10_ReceivePrgChg_enable_toggled(bool);
  void on_Part10_ReceiveVolume_enable_toggled(bool);
  void on_Part10_ReceiveHold_enable_toggled(bool);
  void on_Part10_Output_select_currentIndexChanged(int);
  void on_Part10_MidiChannel_select_valueChanged(int);
  void on_Part10_TestTone_switch_toggled(bool);
  void on_Part11_Transpose_select_valueChanged(int);
  void on_Part11_TuneAdj_select_valueChanged(int);
  void on_Part11_VoiceReserve_select_valueChanged(int);
  void on_Part11_LowLimit_select_valueChanged(int);
  void on_Part11_HighLimit_select_valueChanged(int);
  void on_Part11_PatchNumber_select_valueChanged(int);
  void on_Part11_PatchGroup_select_currentIndexChanged(int);
  void on_Part11_Level_select_valueChanged(int);
  void on_Part11_Pan_select_valueChanged(int);
  void on_Part11_ChorusSend_select_valueChanged(int);
  void on_Part11_ReverbSend_select_valueChanged(int);
  void on_Part11_OutputLevel_select_valueChanged(int);
  void on_Part11_ReceiveMidi_enable_toggled(bool);
  void on_Part11_ReceivePrgChg_enable_toggled(bool);
  void on_Part11_ReceiveVolume_enable_toggled(bool);
  void on_Part11_ReceiveHold_enable_toggled(bool);
  void on_Part11_Output_select_currentIndexChanged(int);
  void on_Part11_MidiChannel_select_valueChanged(int);
  void on_Part11_TestTone_switch_toggled(bool);
  void on_Part12_Transpose_select_valueChanged(int);
  void on_Part12_TuneAdj_select_valueChanged(int);
  void on_Part12_VoiceReserve_select_valueChanged(int);
  void on_Part12_LowLimit_select_valueChanged(int);
  void on_Part12_HighLimit_select_valueChanged(int);
  void on_Part12_PatchNumber_select_valueChanged(int);
  void on_Part12_PatchGroup_select_currentIndexChanged(int);
  void on_Part12_Level_select_valueChanged(int);
  void on_Part12_Pan_select_valueChanged(int);
  void on_Part12_ChorusSend_select_valueChanged(int);
  void on_Part12_ReverbSend_select_valueChanged(int);
  void on_Part12_OutputLevel_select_valueChanged(int);
  void on_Part12_ReceiveMidi_enable_toggled(bool);
  void on_Part12_ReceivePrgChg_enable_toggled(bool);
  void on_Part12_ReceiveVolume_enable_toggled(bool);
  void on_Part12_ReceiveHold_enable_toggled(bool);
  void on_Part12_Output_select_currentIndexChanged(int);
  void on_Part12_MidiChannel_select_valueChanged(int);
  void on_Part12_TestTone_switch_toggled(bool);
  void on_Part13_Transpose_select_valueChanged(int);
  void on_Part13_TuneAdj_select_valueChanged(int);
  void on_Part13_VoiceReserve_select_valueChanged(int);
  void on_Part13_LowLimit_select_valueChanged(int);
  void on_Part13_HighLimit_select_valueChanged(int);
  void on_Part13_PatchNumber_select_valueChanged(int);
  void on_Part13_PatchGroup_select_currentIndexChanged(int);
  void on_Part13_Level_select_valueChanged(int);
  void on_Part13_Pan_select_valueChanged(int);
  void on_Part13_ChorusSend_select_valueChanged(int);
  void on_Part13_ReverbSend_select_valueChanged(int);
  void on_Part13_OutputLevel_select_valueChanged(int);
  void on_Part13_ReceiveMidi_enable_toggled(bool);
  void on_Part13_ReceivePrgChg_enable_toggled(bool);
  void on_Part13_ReceiveVolume_enable_toggled(bool);
  void on_Part13_ReceiveHold_enable_toggled(bool);
  void on_Part13_Output_select_currentIndexChanged(int);
  void on_Part13_MidiChannel_select_valueChanged(int);
  void on_Part13_TestTone_switch_toggled(bool);
  void on_Part14_Transpose_select_valueChanged(int);
  void on_Part14_TuneAdj_select_valueChanged(int);
  void on_Part14_VoiceReserve_select_valueChanged(int);
  void on_Part14_LowLimit_select_valueChanged(int);
  void on_Part14_HighLimit_select_valueChanged(int);
  void on_Part14_PatchNumber_select_valueChanged(int);
  void on_Part14_PatchGroup_select_currentIndexChanged(int);
  void on_Part14_Level_select_valueChanged(int);
  void on_Part14_Pan_select_valueChanged(int);
  void on_Part14_ChorusSend_select_valueChanged(int);
  void on_Part14_ReverbSend_select_valueChanged(int);
  void on_Part14_OutputLevel_select_valueChanged(int);
  void on_Part14_ReceiveMidi_enable_toggled(bool);
  void on_Part14_ReceivePrgChg_enable_toggled(bool);
  void on_Part14_ReceiveVolume_enable_toggled(bool);
  void on_Part14_ReceiveHold_enable_toggled(bool);
  void on_Part14_Output_select_currentIndexChanged(int);
  void on_Part14_MidiChannel_select_valueChanged(int);
  void on_Part14_TestTone_switch_toggled(bool);
  void on_Part15_Transpose_select_valueChanged(int);
  void on_Part15_TuneAdj_select_valueChanged(int);
  void on_Part15_VoiceReserve_select_valueChanged(int);
  void on_Part15_LowLimit_select_valueChanged(int);
  void on_Part15_HighLimit_select_valueChanged(int);
  void on_Part15_PatchNumber_select_valueChanged(int);
  void on_Part15_PatchGroup_select_currentIndexChanged(int);
  void on_Part15_Level_select_valueChanged(int);
  void on_Part15_Pan_select_valueChanged(int);
  void on_Part15_ChorusSend_select_valueChanged(int);
  void on_Part15_ReverbSend_select_valueChanged(int);
  void on_Part15_OutputLevel_select_valueChanged(int);
  void on_Part15_ReceiveMidi_enable_toggled(bool);
  void on_Part15_ReceivePrgChg_enable_toggled(bool);
  void on_Part15_ReceiveVolume_enable_toggled(bool);
  void on_Part15_ReceiveHold_enable_toggled(bool);
  void on_Part15_Output_select_currentIndexChanged(int);
  void on_Part15_MidiChannel_select_valueChanged(int);
  void on_Part15_TestTone_switch_toggled(bool);
  void on_Part16_Transpose_select_valueChanged(int);
  void on_Part16_TuneAdj_select_valueChanged(int);
  void on_Part16_VoiceReserve_select_valueChanged(int);
  void on_Part16_LowLimit_select_valueChanged(int);
  void on_Part16_HighLimit_select_valueChanged(int);
  void on_Part16_PatchNumber_select_valueChanged(int);
  void on_Part16_PatchGroup_select_currentIndexChanged(int);
  void on_Part16_Level_select_valueChanged(int);
  void on_Part16_Pan_select_valueChanged(int);
  void on_Part16_ChorusSend_select_valueChanged(int);
  void on_Part16_ReverbSend_select_valueChanged(int);
  void on_Part16_OutputLevel_select_valueChanged(int);
  void on_Part16_ReceiveMidi_enable_toggled(bool);
  void on_Part16_ReceivePrgChg_enable_toggled(bool);
  void on_Part16_ReceiveVolume_enable_toggled(bool);
  void on_Part16_ReceiveHold_enable_toggled(bool);
  void on_Part16_Output_select_currentIndexChanged(int);
  void on_Part16_MidiChannel_select_valueChanged(int);
  void on_Part16_TestTone_switch_toggled(bool);

  // for EFX tab
  void on_PatchEFX_TestTone_switch_toggled(bool);
  void slotPerfEFXsource(int);
  void slotPerfEFXtype(int);
  void slotPatchEFXtype(int);
  void slotEFXoutput(int);
  void slotEFXreverbSend(int);
  void slotEFXchorusSend(int);
  void slotEFXoutputLevel(int);
  void slotEFXcontrol1Depth(int);
  void slotEFXcontrol2Depth(int);
  void slotEFXcontrolSource1(int);
  void slotEFXcontrolSource2(int);
  void slotEFXparm1(int);
  void slotEFXparm2(int);
  void slotEFXparm3(int);
  void slotEFXparm4(int);
  void slotEFXparm5(int);
  void slotEFXparm6(int);
  void slotEFXparm7(int);
  void slotEFXparm8(int);
  void slotEFXparm9(int);
  void slotEFXparmA(int);
  void slotEFXparmB(int);
  void slotEFXparmC(int);
  
  // for Patch tab
  void on_Patch_Sync_button_clicked();
  void on_Patch_Group_select_currentIndexChanged(int);
  void on_Patch_Number_select_valueChanged(int);
  void on_Patch_Name_edit_editingFinished();
  void on_Patch_Level_select_valueChanged(int);
  void on_Patch_Pan_select_valueChanged(int);
  void on_Patch_AnalogFeel_select_valueChanged(int);
  void on_Patch_PortamentoTime_select_valueChanged(int);
  void on_Patch_BenderDown_select_valueChanged(int);
  void on_Patch_BenderUp_select_valueChanged(int);
  void on_Patch_HoldPeak_select_currentIndexChanged(int);
  void on_Patch_C1_HoldPeak_select_currentIndexChanged(int);
  void on_Patch_C2_HoldPeak_select_currentIndexChanged(int);
  void on_Patch_C3_HoldPeak_select_currentIndexChanged(int);
  void on_Patch_Struct12_select_valueChanged(int);
  void on_Patch_Booster12_select_valueChanged(int);
  void on_Patch_Struct34_select_valueChanged(int);
  void on_Patch_Booster34_select_valueChanged(int);
  void on_Patch_Tone1_enable_toggled(bool);
  void on_Patch_Tone2_enable_toggled(bool);
  void on_Patch_Tone3_enable_toggled(bool);
  void on_Patch_Tone4_enable_toggled(bool);
  void on_Patch_DefaultTempo_select_valueChanged(int);
  void on_Patch_VoicePriority_switch_toggled(bool);
  void on_Patch_VoiceMode_switch_toggled(bool);
  void on_Patch_PortamentoEnable_switch_toggled(bool);
  void on_Patch_PortamentoMode_switch_toggled(bool);
  void on_Patch_PortamentoType_switch_toggled(bool);
  void on_Patch_PortamentoStart_switch_toggled(bool);
  void on_Patch_TestTone_switch_toggled(bool);
  void on_Patch_PerfPartNum_select_currentIndexChanged(int);
  void on_Patch_VelocityRange_enable_toggled(bool);
  void on_Patch_ControlSource2_select_currentIndexChanged(int);
  void on_Patch_ControlSource3_select_currentIndexChanged(int);
  void on_Patch_SoloLegato_enable_toggled(bool);
  
  // for PatchEFX tab
  void on_PatchEFX_ReverbHiFreqDamp_select_currentIndexChanged(int);
  void on_PatchEFX_ReverbLevel_select_valueChanged(int);
  void on_PatchEFX_ReverbTime_select_valueChanged(int);
  void on_PatchEFX_ReverbType_select_currentIndexChanged(int);
  void on_PatchEFX_ReverbFeedback_select_valueChanged(int);
  void on_PatchEFX_ChorusLevel_select_valueChanged(int);
  void on_PatchEFX_ChorusRate_select_valueChanged(int);
  void on_PatchEFX_ChorusDepth_select_valueChanged(int);
  void on_PatchEFX_ChorusPreDelay_select_valueChanged(int);
  void on_PatchEFX_ChorusFeedback_select_valueChanged(int);
  void on_PatchEFX_ChorusOutput_select_currentIndexChanged(int);
  void on_PatchEFX_Control1Source_select_currentIndexChanged(int);
  void on_PatchEFX_Control2Source_select_currentIndexChanged(int);
  void on_PatchEFX_Control1Depth_select_valueChanged(int);
  void on_PatchEFX_Control2Depth_select_valueChanged(int);

  // for Tone tab
  void on_Tone_TestTone_switch_toggled(bool);
  void on_ToneSync_button_clicked();
  void on_Tone_ToneNumber_select_valueChanged();
  void on_Tone_Number_select_valueChanged(int);
  void on_Tone_Group_select_currentIndexChanged(int);
  void on_Tone_InstrFamily_select_currentIndexChanged(int);
  void on_Tone_WaveChooser_select_currentIndexChanged(int);
  void on_Tone_Output_select_currentIndexChanged(int);
  void on_Tone_C1D1_select_currentIndexChanged(int);
  void on_Tone_C1D2_select_currentIndexChanged(int);
  void on_Tone_C1D3_select_currentIndexChanged(int);
  void on_Tone_C1D4_select_currentIndexChanged(int);
  void on_Tone_C2D1_select_currentIndexChanged(int);
  void on_Tone_C2D2_select_currentIndexChanged(int);
  void on_Tone_C2D3_select_currentIndexChanged(int);
  void on_Tone_C2D4_select_currentIndexChanged(int);
  void on_Tone_C3D1_select_currentIndexChanged(int);
  void on_Tone_C3D2_select_currentIndexChanged(int);
  void on_Tone_C3D3_select_currentIndexChanged(int);
  void on_Tone_C3D4_select_currentIndexChanged(int);
  void on_Tone_WaveGain_select_currentIndexChanged(int);
  void on_Tone_DelayMode_select_currentIndexChanged(int);
  void on_Tone_ChorusSend_select_valueChanged(int);
  void on_Tone_ReverbSend_select_valueChanged(int);
  void on_Tone_OutputLevel_select_valueChanged(int);
  void on_Tone_Level_select_valueChanged(int);
  void on_Tone_VeloXfadeDepth_select_valueChanged(int);
  void on_Tone_VeloLowerRange_select_valueChanged(int);
  void on_Tone_DelayTime_select_valueChanged(int);
  void on_Tone_VeloUpperRange_select_valueChanged(int);
  void on_Tone_C1D1Depth_select_valueChanged(int);
  void on_Tone_C1D2Depth_select_valueChanged(int);
  void on_Tone_C1D3Depth_select_valueChanged(int);
  void on_Tone_C1D4Depth_select_valueChanged(int);
  void on_Tone_C2D1Depth_select_valueChanged(int);
  void on_Tone_C2D2Depth_select_valueChanged(int);
  void on_Tone_C2D3Depth_select_valueChanged(int);
  void on_Tone_C2D4Depth_select_valueChanged(int);
  void on_Tone_C3D1Depth_select_valueChanged(int);
  void on_Tone_C3D2Depth_select_valueChanged(int);
  void on_Tone_C3D3Depth_select_valueChanged(int);
  void on_Tone_C3D4Depth_select_valueChanged(int);
  void on_Tone_ReceiveVolume_enable_toggled(bool);
  void on_Tone_ReceiveHold_enable_toggled(bool);
  void on_Tone_ReceiveReDamper_enable_toggled(bool);
  void on_Tone_ReceiveBender_enable_toggled(bool);
  void on_Tone_FXM_enable_toggled(bool);
  void on_Tone_FXMColor_select_currentIndexChanged(int);
  void on_Tone_FXMDepth_select_currentIndexChanged(int);
  
  // for toneEFX tab
  void on_ToneEFX_LFO1Target_select_currentIndexChanged();
  void on_ToneEFX_LFO2Target_select_currentIndexChanged();
  void on_ToneEFX_TestTone_switch_toggled(bool);
  void on_ToneEFX_LFO1FadeTime_select_valueChanged(int);
  void on_ToneEFX_LFO2FadeTime_select_valueChanged(int);
  void on_ToneEFX_LFO1Delay_select_valueChanged(int);
  void on_ToneEFX_LFO1Rate_select_valueChanged(int);
  void on_ToneEFX_LFO2Rate_select_valueChanged(int);
  void on_ToneEFX_LFO2Delay_select_valueChanged(int);
  void on_ToneEFX_LFO1KeyTrigger_enable_toggled(bool);
  void on_ToneEFX_LFO2KeyTrigger_enable_toggled(bool);
  void on_ToneEFX_LFO1LevelOffset_select_currentIndexChanged(int);
  void on_ToneEFX_LFO2LevelOffset_select_currentIndexChanged(int);
  void on_ToneEFX_LF01Waveform_select_currentIndexChanged(int);
  void on_ToneEFX_LFO1FadeMode_select_currentIndexChanged(int);
  void on_ToneEFX_LFO1ExtSync_select_currentIndexChanged(int);
  void on_ToneEFX_LF02Waveform_select_currentIndexChanged(int);
  void on_ToneEFX_LFO2FadeMode_select_currentIndexChanged(int);
  void on_ToneEFX_LFO2ExtSync_select_currentIndexChanged(int);
  void on_ToneEFX_PanControl_select_currentIndexChanged(int);
  void on_ToneEFX_Pan_select_valueChanged(int);
  void on_ToneEFX_PanKeyFollow_select_currentIndexChanged(int);
  void on_ToneEFX_PanRandDepth_select_valueChanged(int);
  void on_ToneEFX_AltPan_select_valueChanged(int);
  void on_ToneEFX_PanLFO1Depth_select_valueChanged(int);
  void on_ToneEFX_PanLFO2Depth_select_valueChanged(int);

  // for ToneENV tab
  void on_ToneTVF_TestTone_switch_toggled(bool);
  void on_ToneTVA_TestTone_switch_toggled(bool);
  void on_ToneTVA_Time1_select_valueChanged(int);
  void on_ToneTVA_Time2_select_valueChanged(int);
  void on_ToneTVA_Time3_select_valueChanged(int);
  void on_ToneTVA_Time4_select_valueChanged(int);
  void on_ToneTVA_Lvl1_select_valueChanged(int);
  void on_ToneTVA_Lvl2_select_valueChanged(int);
  void on_ToneTVA_Lvl3_select_valueChanged(int);
  void on_ToneTVA_LFO1Depth_select_valueChanged(int);
  void on_ToneTVA_LFO2Depth_select_valueChanged(int);
  void on_ToneTVA_VelocSens_select_valueChanged(int);
  void on_ToneTVA_BiasPoint_select_valueChanged(int);
  void on_ToneTVA_BiasDirection_select_currentIndexChanged(int);
  void on_ToneTVA_Time1Sens_select_currentIndexChanged(int);
  void on_ToneTVA_Time4Sens_select_currentIndexChanged(int);
  void on_ToneTVA_VelocityCurve_select_currentIndexChanged(int);
  void on_ToneTVA_TimeKeyfollow_select_currentIndexChanged(int);
  void on_ToneTVA_BiasLvl_select_currentIndexChanged(QString);
  void on_ToneTVF_Time1_select_valueChanged(int);
  void on_ToneTVF_Time2_select_valueChanged(int);
  void on_ToneTVF_Time3_select_valueChanged(int);
  void on_ToneTVF_Time4_select_valueChanged(int);
  void on_ToneTVF_Lvl1_select_valueChanged(int);
  void on_ToneTVF_Lvl2_select_valueChanged(int);
  void on_ToneTVF_Lvl3_select_valueChanged(int);
  void on_ToneTVF_Lvl4_select_valueChanged(int);
  void on_ToneTVF_LFO1Depth_select_valueChanged(int);
  void on_ToneTVF_LFO2Depth_select_valueChanged(int);
  void on_ToneTVF_VelocSens_select_valueChanged(int);
  void on_ToneTVF_ResVelocSens_select_valueChanged(int);
  void on_ToneTVF_Resonance_select_valueChanged(int);
  void on_ToneTVF_Depth_select_valueChanged(int);
  void on_ToneTVF_TimeKeyfollow_select_currentIndexChanged(int);
  void on_ToneTVF_Time1Sens_select_currentIndexChanged(int);
  void on_ToneTVF_Time4Sens_select_currentIndexChanged(int);
  void on_ToneTVF_VelocityCurve_select_currentIndexChanged(int);
  void on_ToneTVF_FilterType_select_currentIndexChanged(int);
  void on_ToneTVF_CutoffKeyfollow_select_currentIndexChanged(int);
  void on_ToneTVF_CutoffFreq_select_valueChanged(int);
  
  // for Pitch tab
  void on_Pitch_TestTone_switch_toggled(bool);
  void on_Pitch_StretchTuning_select_valueChanged(int);
  void on_Pitch_HighLimit_select_valueChanged(int);
  void on_Pitch_LowLimit_select_valueChanged(int);
  void on_Pitch_TimeKeyfollow_select_currentIndexChanged(int);
  void on_Pitch_RandPitchDepth_select_currentIndexChanged(int);
  void on_Pitch_Depth_select_valueChanged(int);
  void on_Pitch_TuneAdj_select_valueChanged(int);
  void on_Pitch_Transpose_select_valueChanged(int);
  void on_Pitch_OctaveShift_select_currentIndexChanged(int);
  void on_Pitch_KeyFollow_select_currentIndexChanged(int);
  void on_Pitch_Time1_select_valueChanged(int);
  void on_Pitch_Time2_select_valueChanged(int);
  void on_Pitch_Time3_select_valueChanged(int);
  void on_Pitch_Time4_select_valueChanged(int);
  void on_Pitch_Lvl1_select_valueChanged(int);
  void on_Pitch_Lvl2_select_valueChanged(int);
  void on_Pitch_Lvl3_select_valueChanged(int);
  void on_Pitch_Lvl4_select_valueChanged(int);
  void on_Pitch_LFO1Depth_select_valueChanged(int);
  void on_Pitch_LFO2Depth_select_valueChanged(int);
  void on_Pitch_VelocSens_select_valueChanged(int);
  void on_Pitch_Time1Sens_select_currentIndexChanged(int);
  void on_Pitch_Time4Sens_select_currentIndexChanged(int);
  
  // for Tuning tab
  void on_Tuning_ScaleTuning_enable_toggled(bool);
  void on_Tuning_Sync_button_clicked();
  void on_Tuning_PartTune_select_valueChanged(int);
  void on_Tuning_MasterTune_select_valueChanged(double);
  void slotTuning_TempButtons(int);
  void on_Tuning_LoadCustomTemp_button_clicked();
  void on_Tuning_SaveCustomTemp_button_clicked();
  void on_Tuning_BaseKey_select_currentIndexChanged(int);
  void on_Tuning_PartTuneA_select_valueChanged(int);
  void on_Tuning_PartTuneAs_select_valueChanged(int);
  void on_Tuning_PartTuneB_select_valueChanged(int);
  void on_Tuning_PartTuneC_select_valueChanged(int);
  void on_Tuning_PartTuneCs_select_valueChanged(int);
  void on_Tuning_PartTuneD_select_valueChanged(int);
  void on_Tuning_PartTuneDs_select_valueChanged(int);
  void on_Tuning_PartTuneE_select_valueChanged(int);
  void on_Tuning_PartTuneF_select_valueChanged(int);
  void on_Tuning_PartTuneFs_select_valueChanged(int);
  void on_Tuning_PartTuneG_select_valueChanged(int);
  void on_Tuning_PartTuneGs_select_valueChanged(int);
  void Tuning_QueryTemp(int);
  void Tuning_setScaleTuning(int);
  
  // for Rhythm tab
  void on_Rhythm_Sync_button_clicked();
  void on_Rhythm_EnvMode_select_toggled(bool);
  void on_Rhythm_Note_enable_toggled(bool);
  void on_Rhythm_Hold_enable_toggled(bool);
  void on_Rhythm_Volume_enable_toggled(bool);
  void on_Rhythm_WaveGroup_select_currentIndexChanged(int);
  void on_Rhythm_WaveGain_select_currentIndexChanged(int);
  void on_Rhythm_Output_select_currentIndexChanged(int);
  void on_Rhythm_PanControl_select_currentIndexChanged(int);
  void on_Rhythm_RandPitchDepth_select_currentIndexChanged(int);
  void on_Rhythm_TVAVelTimeSens_select_currentIndexChanged(int);
  void on_Rhythm_TVFFilterType_select_currentIndexChanged(int);
  void on_Rhythm_TVFVelTimeSens_select_currentIndexChanged(int);
  void on_Rhythm_WaveNumber_select_valueChanged(int);
  void on_Rhythm_MuteGroup_select_valueChanged(int);
  void on_Rhythm_PanRandDepth_select_valueChanged(int);
  void on_Rhythm_PitchDepth_select_valueChanged(int);
  void on_Rhythm_TVFDepth_select_valueChanged(int);
  void on_Rhythm_KeyPress_select_valueChanged(int);
  void on_Rhythm_OutputLevel_select_valueChanged(int);
  void on_Rhythm_ChorusSend_select_valueChanged(int);
  void on_Rhythm_ReverbSend_select_valueChanged(int);
  void on_Rhythm_Pan_select_valueChanged(int);
  void on_Rhythm_AltPan_select_valueChanged(int);
  void on_Rhythm_PitchTime1_select_valueChanged(int);
  void on_Rhythm_PitchTime2_select_valueChanged(int);
  void on_Rhythm_PitchTime3_select_valueChanged(int);
  void on_Rhythm_PitchTime4_select_valueChanged(int);
  void on_Rhythm_PitchLvl1_select_valueChanged(int);
  void on_Rhythm_PitchLvl2_select_valueChanged(int);
  void on_Rhythm_PitchLvl3_select_valueChanged(int);
  void on_Rhythm_PitchLvl4_select_valueChanged(int);
  void on_Rhythm_PitchVelocSens_select_valueChanged(int);
  void on_Rhythm_TVATime1_select_valueChanged(int);
  void on_Rhythm_TVATime2_select_valueChanged(int);
  void on_Rhythm_TVATime3_select_valueChanged(int);
  void on_Rhythm_TVATime4_select_valueChanged(int);
  void on_Rhythm_TVALvl1_select_valueChanged(int);
  void on_Rhythm_TVALvl2_select_valueChanged(int);
  void on_Rhythm_TVALvl3_select_valueChanged(int);
  void on_Rhythm_TVAVelocSens_select_valueChanged(int);
  void on_Rhythm_TVFTime1_select_valueChanged(int);
  void on_Rhythm_TVFTime2_select_valueChanged(int);
  void on_Rhythm_TVFTime3_select_valueChanged(int);
  void on_Rhythm_TVFTime4_select_valueChanged(int);
  void on_Rhythm_TVFLvl2_select_valueChanged(int);
  void on_Rhythm_TVFLvl3_select_valueChanged(int);
  void on_Rhythm_TVFLvl4_select_valueChanged(int);
  void on_Rhythm_TVFLvl1_select_valueChanged(int);
  void on_Rhythm_TVFResVelocSens_select_valueChanged(int);
  void on_Rhythm_TVFCutoffFreq_select_valueChanged(int);
  void on_Rhythm_TVFResonance_select_valueChanged(int);
  void on_Rhythm_TVFVelocSens_select_valueChanged(int);
  void on_Rhythm_SoundingPitch_select_valueChanged(int);
  void on_Rhythm_BenderRange_select_valueChanged(int);
  void on_Rhythm_PitchVeloTime_select_currentIndexChanged(int);
  void on_Rhythm_ToneLevel_select_valueChanged(int);
  void on_Rhythm_TuneAdj_select_valueChanged(int);
  void on_Rhythm_TestTone_switch_clicked(bool);
  
private:
  // shared variables
  QString curFile;
  QVBoxLayout *PortBoxLayout;
  QComboBox *PortBox;
  QGraphicsScene *scene1;
  QGraphicsScene *scene2;
  QGraphicsScene *scene3;
  QGraphicsScene *scene4;
  QGraphicsScene *scene5;
  QGraphicsScene *scene6;
  QGraphicsScene *scene7;
  QGraphicsScene *scene8;
  QGraphicsScene *scene9;
  QGraphicsScene *scene10;
  snd_rawmidi_t *midiInHandle;
  snd_rawmidi_t *midiOutHandle;
  struct SYSTEM_AREA *system_area;
  struct ACTIVE_AREA *active_area;
  static struct SYSTEM_AREA *sys_area;
  static struct ACTIVE_AREA *act_area;
  static struct STATE_TABLE *state_table;
  int debug;
  QSqlDatabase mysql;
  static QSqlDatabase db_mysql;
  QPen dotLine;
  QPen redLine;
  QPen blackLine;
  
  QGraphicsScene *ToneTVA_Env_scene;
  QGraphicsSimpleTextItem *ToneTVA_Env_OffText;
  QGraphicsSimpleTextItem *ToneTVA_Env_t1Text;
  QGraphicsSimpleTextItem *ToneTVA_Env_t2Text;
  QGraphicsSimpleTextItem *ToneTVA_Env_t3Text;
  QGraphicsSimpleTextItem *ToneTVA_Env_t4Text;
  QGraphicsSimpleTextItem *ToneTVA_Env_sndText;
  QLineF ToneTVA_Env_t1;
  QLineF ToneTVA_Env_t2;
  QLineF ToneTVA_Env_t3;
  QLineF ToneTVA_Env_t4;
  QLineF ToneTVA_Env_sustain;
  QLineF ToneTVA_Env_offLine;
  QLineF ToneTVA_Env_t1Mark;
  QLineF ToneTVA_Env_t2Mark;
  QLineF ToneTVA_Env_t3Mark;
  QLineF ToneTVA_Env_t4Mark;
  QGraphicsLineItem *ToneTVA_Env_ptrT1;
  QGraphicsLineItem *ToneTVA_Env_ptrT3;
  QGraphicsLineItem *ToneTVA_Env_ptrT4;
  QGraphicsLineItem *ToneTVA_Env_ptrT2;
  QGraphicsLineItem *ToneTVA_Env_ptrSustain;
  
  QGraphicsScene *ToneTVA_Bias_scene;
  QLine ToneTVA_Bias_bpMark;
  QLine ToneTVA_Bias_HiLine;
  QLine ToneTVA_Bias_LowLine;
  QGraphicsLineItem *ToneTVA_Bias_ptrHiLine;
  QGraphicsLineItem *ToneTVA_Bias_ptrLowLine;
  QGraphicsLineItem *ToneTVA_Bias_ptrbpMark;
  QGraphicsSimpleTextItem *ToneTVA_Bias_bpText;

  QGraphicsScene *ToneTVF_Env_scene;
  QGraphicsSimpleTextItem *ToneTVF_Env_OffText;
  QGraphicsSimpleTextItem *ToneTVF_Env_t1Text;
  QGraphicsSimpleTextItem *ToneTVF_Env_t2Text;
  QGraphicsSimpleTextItem *ToneTVF_Env_t3Text;
  QGraphicsSimpleTextItem *ToneTVF_Env_t4Text;
  QGraphicsSimpleTextItem *ToneTVF_Env_sndText;
  QLineF ToneTVF_Env_t1;
  QLineF ToneTVF_Env_t2;
  QLineF ToneTVF_Env_t3;
  QLineF ToneTVF_Env_t4;
  QLineF ToneTVF_Env_sustain;
  QLineF ToneTVF_Env_offLine;
  QLineF ToneTVF_Env_t1Mark;
  QLineF ToneTVF_Env_t2Mark;
  QLineF ToneTVF_Env_t3Mark;
  QLineF ToneTVF_Env_t4Mark;
  QGraphicsLineItem *ToneTVF_Env_ptrT1;
  QGraphicsLineItem *ToneTVF_Env_ptrT3;
  QGraphicsLineItem *ToneTVF_Env_ptrT4;
  QGraphicsLineItem *ToneTVF_Env_ptrT2;
  QGraphicsLineItem *ToneTVF_Env_ptrSustain;

  QGraphicsScene *Pitch_Env_scene;
  QGraphicsSimpleTextItem *Pitch_Env_OffText;
  QGraphicsSimpleTextItem *Pitch_Env_t1Text;
  QGraphicsSimpleTextItem *Pitch_Env_t2Text;
  QGraphicsSimpleTextItem *Pitch_Env_t3Text;
  QGraphicsSimpleTextItem *Pitch_Env_t4Text;
  QGraphicsSimpleTextItem *Pitch_Env_sndText;
  QLineF Pitch_Env_t1;
  QLineF Pitch_Env_t2;
  QLineF Pitch_Env_t3;
  QLineF Pitch_Env_t4;
  QLineF Pitch_Env_sustain;
  QLineF Pitch_Env_offLine;
  QLineF Pitch_Env_t1Mark;
  QLineF Pitch_Env_t2Mark;
  QLineF Pitch_Env_t3Mark;
  QLineF Pitch_Env_t4Mark;
  QGraphicsLineItem *Pitch_Env_ptrT1;
  QGraphicsLineItem *Pitch_Env_ptrT3;
  QGraphicsLineItem *Pitch_Env_ptrT4;
  QGraphicsLineItem *Pitch_Env_ptrT2;
  QGraphicsLineItem *Pitch_Env_ptrSustain;
  
  QLineF LFO1_FadeUpLine;
  QLineF LFO1_FadeDownLine;
  QLineF LFO1_EffectUpLine;
  QLineF LFO1_EffectDownLine;
  QLineF LFO1_FadeStartLine;
  QLineF LFO1_FadeEndLine;
  QLineF LFO1_OffLine;
  QGraphicsLineItem *LFO1_ptrFadeUp;
  QGraphicsLineItem *LFO1_ptrFadeDown;
  QGraphicsLineItem *LFO1_ptrEffectUp;
  QGraphicsLineItem *LFO1_ptrEffectDown;
  QGraphicsLineItem *LFO1_ptrOffLine;
  QGraphicsSimpleTextItem *LFO1_OffText;
  QGraphicsSimpleTextItem *LFO1_DelayText;
  QGraphicsSimpleTextItem *LFO1_FadeText;
  QGraphicsSimpleTextItem *LFO1_EffectText;
  inline void LFO1_setOffIn();
  inline void LFO1_setOffOut();
  void LFO1_FillEffect();
  QGraphicsScene *LFO1_scene;
  
  QLineF LFO2_FadeUpLine;
  QLineF LFO2_FadeDownLine;
  QLineF LFO2_EffectUpLine;
  QLineF LFO2_EffectDownLine;
  QLineF LFO2_FadeStartLine;
  QLineF LFO2_FadeEndLine;
  QLineF LFO2_OffLine;
  QGraphicsLineItem *LFO2_ptrFadeUp;
  QGraphicsLineItem *LFO2_ptrFadeDown;
  QGraphicsLineItem *LFO2_ptrEffectUp;
  QGraphicsLineItem *LFO2_ptrEffectDown;
  QGraphicsLineItem *LFO2_ptrOffLine;
  QGraphicsSimpleTextItem *LFO2_OffText;
  QGraphicsSimpleTextItem *LFO2_DelayText;
  QGraphicsSimpleTextItem *LFO2_FadeText;
  QGraphicsSimpleTextItem *LFO2_EffectText;
  inline void LFO2_setOffIn();
  inline void LFO2_setOffOut();
  void LFO2_FillEffect();
  QGraphicsScene *LFO2_scene;

  // generic functions
  void setInitial();
  int  sysex_get(unsigned char *, char *);
  int  sysex_send(unsigned char *, int);
  int  change_send(unsigned char *, int);
  void createStatusBar();
  void close_ports();
  int  open_ports();
  short chksum(unsigned char *, int);
  int hexdump(unsigned char *, int);
  int db_connect(const QString, const QString);
  void	readConfigFile();

  // for menubar.cpp
  void createMenuActions();
  bool maybeSave();
  void loadFile(const QString&);
  bool saveFile(const QString&);
  void setCurrentFile(const QString&);
  QString strippedName(const QString&);
  
  // for system.cpp
  void getPort();
  void setSysSingleValue(int, int);
  void downloadClicked();
  void setSystemParms();
  void getSysPerfName();
  void getSysPatchName();
  void setSysGmMode(bool);
  char MIDI_dev[32];
  char  sysex_get_data[5];
  char  sysex_send_data[5];
  void EnableSys(bool);
  QString NoteName(int);
  void createSysActions();
  
  // for performance.cpp
  void EnablePerf(bool);
  void setPerfSingleValue(int, int);
  void getActivePerfCommon();
  void getActivePerfPatches();
  void getActivePatchNames();
  void getActivePatchMode();
  void setPerfParms();
  void enable_4(bool);
  void enable_6(bool);
  void enable_7(bool);
  void enable_8(bool);
  void enable_9(bool);
  void enable_A(bool);
  void enable_B(bool);
  void enable_C(bool);
  
  // for EFX.cpp
  void setPerfEFXparms();
  void setPatchEFXparms();
  void displayEFXparms();
  void EFX01stereoEQ();
  void EFX02overdrive();
  void EFX03distortion();
  void EFX04phaser();
  void EFX05spectrum();
  void EFX06enhancer();
  void EFX07autoWah();
  void EFX08rotary();
  void EFX09compressor();
  void EFX10limiter();
  void EFX11HexaChorus();
  void EFX12TremoloChorus();
  void EFX13Space_D();
  void EFX14StereoChorus();
  void EFX15StereoFlanger();
  void EFX16StepFlanger();
  void EFX17StereoDelay();
  void EFX18ModulationDelay();
  void EFX19TripleTapDelay();
  void EFX20QuadrupleTapDelay();
  void EFX21TimeControlDelay();
  void EFX22VoicePitchShifter();
  void EFX23FeedbackPitchShifter();
  void EFX24Reverb();
  void EFX25GateReverb();
  void EFX26OverdriveSeriesChorus();
  void EFX27OverdriveSeriesFlanger();
  void EFX28OverdriveSeriesDelay();
  void EFX29DistortionSeriesChorus();
  void EFX30DistortionSeriesFlanger();
  void EFX31DistortionSeriesDelay();
  void EFX32EnhancerSeriesChorus();
  void EFX33EnhancerSeriesFlanger();
  void EFX34EnhancerSeriesDelay();
  void EFX35ChorusSeriesDelay();
  void EFX36FlangerSeriesDelay();
  void EFX37ChorusSeriesFlanger();
  void EFX38ChorusParallelDelay();
  void EFX39FlangerParallelDelay();
  void EFX40ChorusParallelFlanger();

  void setEFXdisplayParm_1();
  void setEFXdisplayParm_2();
  void setEFXdisplayParm_3();
  void setEFXdisplayParm_4();
  void setEFXdisplayParm_5();
  void setEFXdisplayParm_6();
  void setEFXdisplayParm_7();
  void setEFXdisplayParm_8();
  void setEFXdisplayParm_9();
  void setEFXdisplayParm_A();
  void setEFXdisplayParm_B();
  void setEFXdisplayParm_C();
  
  // for parts.cpp
  void EnableParts(bool);
  void setPartsParms();
  void setPart1_Parms();
  void setPart2_Parms();
  void setPart3_Parms();
  void setPart4_Parms();
  void setPart5_Parms();
  void setPart6_Parms();
  void setPart7_Parms();
  void setPart8_Parms();
  void setPart9_Parms();
  void setPart10_Parms();
  void setPart11_Parms();
  void setPart12_Parms();
  void setPart13_Parms();
  void setPart14_Parms();
  void setPart15_Parms();
  void setPart16_Parms();
  void setPartSingleValue(int,int,int);
  void setVoiceCounters();
  void createPartActions();
  QString getPartPatchName(int);
  int toggleControlChannel(int);
  
  int Part1PartNum();
  void Part1_SetPatchMax();
  QString Part1_getPatchName(int);
  int Part2PartNum();
  void Part2_SetPatchMax();
  QString Part2_getPatchName(int);
  int Part3PartNum();
  void Part3_SetPatchMax();
  QString Part3_getPatchName(int);
  int Part4PartNum();
  void Part4_SetPatchMax();
  QString Part4_getPatchName(int);
  int Part5PartNum();
  void Part5_SetPatchMax();
  QString Part5_getPatchName(int);
  int Part6PartNum();
  void Part6_SetPatchMax();
  QString Part6_getPatchName(int);
  int Part7PartNum();
  void Part7_SetPatchMax();
  QString Part7_getPatchName(int);
  int Part8PartNum();
  void Part8_SetPatchMax();
  QString Part8_getPatchName(int);
  int Part9PartNum();
  void Part9_SetPatchMax();
  QString Part9_getPatchName(int);
  int Part10PartNum();
  QString Part10_getPatchName(int);
  int Part11PartNum();
  void Part11_SetPatchMax();
  QString Part11_getPatchName(int);
  int Part12PartNum();
  void Part12_SetPatchMax();
  QString Part12_getPatchName(int);
  int Part13PartNum();
  void Part13_SetPatchMax();
  QString Part13_getPatchName(int);
  int Part14PartNum();
  void Part14_SetPatchMax();
  QString Part14_getPatchName(int);
  int Part15PartNum();
  void Part15_SetPatchMax();
  QString Part15_getPatchName(int);
  int Part16PartNum();
  void Part16_SetPatchMax();
  QString Part16_getPatchName(int);
  
  // for patch.cpp
  void EnablePatch(bool);
  void setPatchParms(int);
  void setPatchSingleValue(int, int);
  void Patch_setPatchMax();

  // for tone.cpp
  inline void ToneStdUpdate(int, int);
  void setToneSingleValue(int, int, int);
  QString WaveName_query();
  void createToneActions();
  void setToneParms(int);
  void Enable_Tone(bool);
  void setWaveChooser();
  
  // for toneEFX.cpp
  inline void ToneEFXStdUpdate(int, int);
  void setToneEFXParms(int);
  void Enable_ToneEFX(bool);
  
  // for toneENV.cpp
  inline void ToneENVStdUpdate(int, int);
  void createToneENVactions();
  void setToneENVParms(int);
  void ToneTVF_enable(bool);
  
  // for Pitch
  inline void PitchStdUpdate(int, int);
  void createPitchActions();
  void setPitchParms(int);

  // for Tuning
  inline void TuningStdUpdate(int, int);
  void setScaleSingleValue(int, int);
  void setScaleTunings(int);
  int get_scales();
  QButtonGroup *Tuning_ButtonGroup;
  QByteArray Tuning_currentTuning;
  void Tuning_BulkUpdate(int, int, int);

  // for Rhythm
  bool getActiveRhythm();
  inline void RhythmStdUpdate(int, int);
  void createRhythmActions();
  void setRhythmParms(int);
  QString RhythmName_query();
  void Rhythm_EnableAll(bool);
  
  // for Config_Dialog
  
};	// end class JVlibForm

#endif
