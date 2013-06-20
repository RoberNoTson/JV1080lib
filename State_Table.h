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
  bool toneTVFTab_enable;
  bool toneTVATab_enable;
  bool pitchTab_enable;
  bool tuningTab_enable;
  bool tuningTab_sync;
  bool tuning_modified;
  bool midiPorts_open;	// PORTS_OPEN actively connected to the computer's midi ports
  bool db_connect;	// DB_OPEN connected to mysql database
  bool jv_connect;	// ONLINE to the synth
  bool updates_enabled;	// used to avoid re-setting memory values when controls are initialized
  bool initialized;	// an initial instance of the main form has been created.
};
#endif
