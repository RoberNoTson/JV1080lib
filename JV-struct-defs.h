// JV-1080 data structures
#ifndef	_JV1080_STRUCTURES_H
#define	_JV1080_STRUCTURES_H 1

struct SYSTEM_COMMON {	// size 0x28 
  char	panel_mode;		// 0	00=Perf, 01=Patch, 02=GM
  char	perf_num;		// 1	00-1F(user), 40-5f(PR-A), 60-7f(PR-B)
  char	patch_group;		// 2	00=Internal(user, preset, datacard), 01=PCMCard, 02=ExpansionCard
  char	patch_group_id;		// 3	0x01=User, 0x02=ExpA, 0x03=PresetA, 0x04=PresetB, 0x05=PresetC, 0x06=PresetD(GM), 0x10=ExpB, 0x62=ExpC
  char	patch_num_high;		// 4	multiply by 16
  char	patch_num_low;		// 5	add to patch_num_high
  char	master_tune;		// 6	0x3F=A440
  bool	scale_tune_switch;	// 7
  bool	EFX_switch;		// 8
  bool	chorus_switch;		// 9
  bool  reverb_switch;		// A
  bool  patch_remain;		// B
  bool	clock_source;		// C
  char	tap_control_source;
  char	hold_control_source;
  char	peak_control_source;
  bool	volume_control_source;		// 10
  char	aftertouch_control_source;	// 11
  char	sys_control_source_1;		// 12  0-95=ControlChannel, 96=Bender, 96=Aftertouch
  char	sys_control_source_2;		// 13  0-95=ControlChannel, 96=Bender, 96=Aftertouch
  bool	receive_program_change;		// 14
  bool	receive_bank_select;		// 15
  bool	receive_control_change;		// 16
  bool	receive_modulation;		// 17
  bool	receive_volume;		// 18
  bool	receive_hold_1;		// 19
  bool	receive_bender;		// 1A
  bool	receive_aftertouch;		// 1B
  char	control_channel;
  char	patch_receive_channel;
  bool	rhythm_edit_source;
  bool	preview_mode;
  char	preview_key_set_1;		// 20
  char	preview_velocity_set_1;
  char	preview_key_set_2;
  char	preview_velocity_set_2;
  char	preview_key_set_3;
  char	preview_velocity_set_3;
  char	preview_key_set_4;
  char	preview_velocity_set_4;		// 27
} __attribute__ ((packed));

// 0=C, 1=C#, 2=D,...11=B
struct SCALE_TUNE {	// size 0x0C
  char	scale[12];
} __attribute__ ((packed));

struct PERF_COMMON {	// size 0x40
  char	name[12];		// 0
  char	EFX_source;		// C
  char	EFX_type;
  char	EFX_parameter[12];	// E
  char	EFX_output;		// 1A
  char	EFX_output_level;
  char	EFX_chorus_send_level;
  char	EFX_reverb_send_level;
  char	EFX_control_src_1;
  char	EFX_control_depth_1;
  char	EFX_control_src_2;	// 20
  char	EFX_control_depth_2;
  char	chorus_level;
  char	chorus_rate;
  char	chorus_depth;
  char	chorus_pre_delay;
  char	chorus_feedback;
  char	chorus_output;
  char	reverb_type;
  char	reverb_level;
  char	reverb_time;		// 2A
  char	reverb_HF_damp;
  char	reverb_feedback;
  char	default_tempo_high;	// multiply by 16
  char	default_tempo_low;	// add to default_tempo_high
  bool	key_range_switch;	// 0x2F
  char	voice_reserve[16];	// 30
} __attribute__ ((packed));
struct PERF_PART {	// size 0x13
  bool	MIDI_receive;	// 0
  char	MIDI_channel;	// 1
  char	patch_group;	// 2
  char	patch_group_id;	// 3
  char	patch_num_high;		// 4	multiply by 16
  char	patch_num_low;		// 5	add to patch_num_high
  char	level;		// 6
  char	pan;		// 7
  char	coarse_tune;	// 8
  char	fine_tune;	// 9
  char	output;		// A
  char	output_level;	// B
  char	chorus_send_level;	// C
  char	reverb_send_level;	// D
  bool	receive_program_change;	// E
  bool	receive_volume;		// F
  bool	receive_hold_1;		// 10
  char	key_lower;		// 11
  char	key_upper;	// 12
} __attribute__ ((packed));

struct PATCH_COMMON {	// size 0x48
  char	name[12];		// 0
  char	EFX_type;		// C
  char	EFX_parameter[12];	// D
  char	EFX_output;		// 19
  char	EFX_output_level;
  char	EFX_chorus_send_level;
  char	EFX_reverb_send_level;
  char	EFX_control_src_1;
  char	EFX_control_depth_1;
  char	EFX_control_src_2;
  char	EFX_control_depth_2;	// 20
  char	chorus_level;
  char	chorus_rate;
  char	chorus_depth;
  char	chorus_pre_delay;
  char	chorus_feedback;
  char	chorus_output;
  char	reverb_type;
  char	reverb_level;
  char	reverb_time;
  char	reverb_HF_damp;
  char	reverb_feedback;
  char	default_tempo_high;
  char	default_tempo_low;	// 0x2D
  char	level;
  char	pan;
  char	analog_feel_depth;	// 30
  char	bender_range_up;
  char	bender_range_down;
  bool	key_assign_mode;
  bool	legato;
  bool	portamento;		// 35
  bool	portamento_mode;
  bool	portamento_type;
  bool	portamento_start;
  char	portamento_time;
  char	patch_control_src_2;	// 0x3A
  char	patch_control_src_3;
  char	control_hold_peak;
  char	control_1_hold_peak;
  char	control_2_hold_peak;
  char	control_3_hold_peak;
  bool	velocity_range;		// 40
  char	octave_shift;
  char	stretch_tune_depth;
  bool	voice_priority;
  char	structure_type_1_2;
  char	booster_level_1_2;
  char	structure_type_3_4;
  char	booster_level_3_4;	// 47
} __attribute__ ((packed));
struct PATCH_TONE {	// size 0x81 (0x0101 in 7bit form)
  bool	tone;	// 0
  char	wave_group;	// 1	0x00 IntA 0x00 IntB 0x02 ExpA 0x02 ExpB 0x02 ExpC
  char	wave_group_id;	// 2	0x01 IntA 0x02 IntB 0x02 ExpA 0x10 ExpB 0x62 ExpC
  char	wave_num_high;	// 3  val * 16
  char	wave_num_low;	// 4  val + wave_num_high
  char	wave_gain;	// 5
  bool	FXM;	// 6
  char	FXM_color;	// 7
  char	FXM_depth;	// 8
  char	tone_delay_mode;	// 9
  char	tone_delay_time;	// A
  char	veloc_xfade_depth;	// B
  char	veloc_range_lower;	// C
  char	veloc_range_upper;	// D
  char	key_range_lower;	// E
  char	key_range_upper;	// F
  bool	redamper_control;	// 10
  bool	volume_control;		// 11
  bool	hold_1_control;		// 12
  bool	bender_control;		// 13
  bool	pan_control;		// 14
  char	cont_1_dest_1;		// 15
  char	cont_1_depth_1;		// 16
  char	cont_1_dest_2;		// 17
  char	cont_1_depth_2;		// 18
  char	cont_1_dest_3;		// 19
  char	cont_1_depth_3;		// 1A
  char	cont_1_dest_4;		// 1B
  char	cont_1_depth_4;		// 1C
  char	cont_2_dest_1;		// 1D
  char	cont_2_depth_1;		// 1E
  char	cont_2_dest_2;		// 1F
  char	cont_2_depth_2;		// 20
  char	cont_2_dest_3;
  char	cont_2_depth_3;
  char	cont_2_dest_4;
  char	cont_2_depth_4;
  char	cont_3_dest_1;
  char	cont_3_depth_1;
  char	cont_3_dest_2;
  char	cont_3_depth_2;
  char	cont_3_dest_3;
  char	cont_3_depth_3;
  char	cont_3_dest_4;
  char	cont_3_depth_4;
  char	LFO_1_waveform;
  bool	LFO_1_key_trigger;
  char	LFO_1_rate;
  char	LFO_1_level_offset;	// 30
  char	LFO_1_delay_time;
  char	LFO_1_fade_mode;
  char	LFO_1_fade_time;
  char	LFO_1_ext_sync;
  char	LFO_2_waveform;
  bool	LFO_2_key_trigger;
  char	LFO_2_rate;
  char	LFO_2_level_offset;
  char	LFO_2_delay_time;
  char	LFO_2_fade_mode;
  char	LFO_2_fade_time;
  char	LFO_2_ext_sync;
  char	coarse_tune;
  char	fine_tune;
  char	random_pitch_depth;
  char	pitch_keyfollow;	// 40
  char	P_ENV_depth;
  char	P_ENV_veloc_sens;
  char	P_ENV_veloc_time1_sens;
  char	P_ENV_veloc_time4_sens;
  char	P_ENV_veloc_time_keyfollow;
  char	P_ENV_time[4];
  char	P_ENV_level[4];
  char	pitch_LFO_1_depth;
  char	pitch_LFO_2_depth;
  char	filter_type;		// 50
  char	cutoff_freq;
  char	cutoff_keyfollow;
  char	resonance;
  char	resonance_veloc_sens;
  char	F_ENV_depth;
  char	F_ENV_veloc_curve;
  char	F_ENV_veloc_sens;
  char	F_ENV_veloc_time_1_sens;
  char	F_ENV_veloc_time_4_sens;
  char	F_ENV_time_keyfollow;
  char	F_ENV_time[4];
  char	F_ENV_level[4];		// 5F
  char	filter_LFO_1_depth;	// 63
  char	filter_LFO_2_depth;
  char	tone_level;
  char	bias_direction;
  char	bias_point;
  char	bias_level;
  char	A_ENV_veloc_curve;
  char	A_ENV_veloc_sens;
  char	A_ENV_veloc_time_1_sens;
  char	A_ENV_veloc_time_4_sens;
  char	A_ENV_time_keyfollow;
  char	A_ENV_time[4];		// 6E
  char	A_ENV_level[3];		// 72
  char	amplitude_LFO_1_depth;	// 75
  char	amplitude_LFO_2_depth;
  char	tone_pan;
  char	pan_keyfollow;
  char	random_pan_depth;
  char	alt_pan_depth;
  char	pan_LFO_1_depth;
  char	pan_LFO_2_depth;
  char	output;
  char	output_level;
  char	chorus_level;
  char	reverb_level;		//80
} __attribute__ ((packed));

struct RHYTHM_COMMON {	// size 0x0C
  char	name[12];
} __attribute__ ((packed));
struct RHYTHM_NOTE{	// size 0x3A
  bool	tone;		// 0
  char	wave_group;	// 1
  char	wave_group_id;	// 2
  char	wave_num_high;	// 3
  char	wave_num_low;	// 4
  char	wave_gain;	// 5
  char	bender_range;	// 6
  char	mute_group;
  bool	envelope_mode;
  bool	volume_control;
  bool	hold_1_control;	// A
  char	pan_control;
  char	source_key;
  char	fine_tune;
  char	random_pitch_depth;
  char	P_ENV_depth;
  char	P_ENV_veloc_sens;	// 10
  char	P_ENV_veloc_time_sens;	// 11
  char	P_ENV_time[4];		// 12
  char	P_ENV_level[4];		// 16
  char	filter_type;		// 1A
  char	cutoff_freq;
  char	resonance;
  char	resonance_veloc_sens;
  char	F_ENV_depth;
  char	F_ENV_veloc_sens;
  char	F_ENV_veloc_time_sens;	// 20
  char	F_ENV_time[4];		// 21
  char	F_ENV_level[4];		// 25
  char	tone_level;		// 29
  char	A_ENV_veloc_sens;
  char	A_ENV_veloc_time_sens;
  char	A_ENV_time[4];		// 2C
  char	A_ENV_level[3];		// 30
  char	tone_pan;		// 33
  char	random_pan_depth;
  char	alt_pan_depth;
  char	output;
  char	output_level;
  char	chorus_level;
  char	reverb_level;		// 39
} __attribute__ ((packed));

struct SYSTEM_AREA {			// hardware and top-level controls 
  struct SYSTEM_COMMON sys_common;
  struct SCALE_TUNE sys_part_scale_tune[16];
  struct SCALE_TUNE sys_patch_scale_tune;
} __attribute__ ((packed));

struct PERFORMANCE {
  struct PERF_COMMON perf_common;
  struct PERF_PART perf_part[16];
} __attribute__ ((packed));

struct PATCH {
  struct PATCH_COMMON patch_common;
  struct PATCH_TONE patch_tone[4];
} __attribute__ ((packed));

struct RHYTHM {
  struct RHYTHM_COMMON rhythm_common;
  struct RHYTHM_NOTE rhythm_note[64];
} __attribute__ ((packed));

struct ACTIVE_AREA {		// active area that produces midi sounds
  struct PERFORMANCE active_performance;	// common and 16 parts
  struct PATCH active_perf_patch[15];	// common and 4 tones, 15 sets
  struct RHYTHM active_rhythm;		// common and 64 notes (this is channel 10 of the patches)
  struct PATCH active_patch_patch;	// common and 4 tones
} __attribute__ ((packed));

#endif	// _JV1080_STRUCTURES_H
