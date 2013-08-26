// State_Table.h
#ifndef _JV1080_STATE_TABLE_H
#define _JV1080_STATE_TABLE_H 1

struct STATE_TABLE {
  bool perf_mode;
  bool patch_mode;
  bool GM_mode;
  bool systemTab_enable;
  bool system_sync;	// System Tab settings have been downloaded and are synchronized with the synth
  bool system_modified;	// System Tab settings have been modified locally. The synth was updated if the jv_connect and updates_enabled values are "true"
  bool performanceTab_enable;
  bool performance_sync;
  bool performance_modified;
  bool partsTab_enable;
  bool parts_modified;
  bool part1_sync;
  bool part2_sync;
  bool part3_sync;
  bool part4_sync;
  bool part5_sync;
  bool part6_sync;
  bool part7_sync;
  bool part8_sync;
  bool part9_sync;
  bool part10_sync;
  bool part11_sync;
  bool part12_sync;
  bool part13_sync;
  bool part14_sync;
  bool part15_sync;
  bool part16_sync;
  bool patchTab_enable;
  bool patch_sync;
  bool patch_modified;
  bool rhythmTab_enable;
  bool rhythm_sync;
  bool rhythm_modified;
  bool patchEFXTab_enable;
  bool toneTab_enable;
  bool tone_sync;
  bool tone_modified;
  bool toneEFXTab_enable;
  bool toneTVFTab_enable;
  bool toneTVATab_enable;
  bool pitchTab_enable;
  bool tuningTab_enable;
  bool tuning_sync;
  bool tuning_modified;
  bool midiPorts_open;	// PORTS_OPEN actively connected to the computer's midi ports
  bool db_connect;	// DB_OPEN connected to mysql database
  bool jv_connect;	// ONLINE to the synth
  bool updates_enabled;	// used to avoid re-setting memory values when controls are initialized
  bool initialized;	// an initial instance of the main form has been created.
};
#endif
