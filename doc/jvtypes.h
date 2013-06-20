#ifndef JVTYPES_H
#define JVTYPES_H

#include "jvbase.h"
#include <qcstring.h>
#include <qlist.h>

#define PATCH_LEN    0x22
#define TONE_LEN     0x75
#define PERF_LEN     0x1F
#define PERFPART_LEN 0x22

#define TONE1_OFF 0x0800
#define TONE2_OFF 0x0900
#define TONE3_OFF 0x0A00
#define TONE4_OFF 0x0B00

#define TMPPATCH_OFF 0x00082000

Q_UINT8 checksum( unsigned char *data, int len );

enum StateType
{
	Off = 0,
	On = 1
};

struct UInt16_
{
	Q_UINT8 b1;
	Q_UINT8 b2;

	UInt16_( Q_UINT8 i = 0 ) { b1 = ( ( i >> 4 ) & 0x0F ); b2 = ( i & 0x0F ); }
	Q_UINT8 toInt() const { return ( ( ( b1 << 4 ) & 0xF0 ) | ( b2 & 0x0F ) ); }
	UInt16_& operator=( const Q_UINT8& i ) { b1 = ( ( i >> 4 ) & 0x0F ); b2 = ( i & 0x0F ); return *this; }
	operator unsigned int() const { return toInt(); }
};

struct Reverb
{
	enum ReverbType
	{
		Room1    = 0,
		Room2    = 1,
		Stage1   = 2,
		Stage2   = 3,
		Hall1    = 4,
		Hall2    = 5,
		Delay    = 6,
		PanDelay = 7
	};

	Q_UINT8 reverb_type;
	Q_UINT8 reverb_level;
	Q_UINT8 reverb_time;
	Q_UINT8 reverb_feedback;
};

struct Chorus
{
	enum ChorusType
	{
		Chorus1 = 0,
		Chorus2 = 1,
		Chorus3 = 2
	};
	enum ChorusOutputType
	{
		Mix = 0,
		Rev = 0
	};

	Q_UINT8 chorus_type;
	Q_UINT8 chorus_level;
	Q_UINT8 chorus_depth;
	Q_UINT8 chorus_rate;
	Q_UINT8 chorus_feedback;
	Q_UINT8 chorus_output;
};

struct Portamento
{
	enum ModeType
	{
		Legato = 0,
		Normal = 1
	};
	enum Type
	{
		Time = 0,
		Rate = 1
	};

	Q_UINT8 pto_switch;
	Q_UINT8 pto_mode;
	Q_UINT8 pto_type;
	Q_UINT8 pto_time;
};

struct ControlDest
{
	enum DestType
	{
		OFF = 0,
		PCH = 1,
		CUT = 2,
		RES = 3,
		LEV = 4,
		PL1 = 5,
		PL2 = 6,
		FL1 = 7,
		FL2 = 8,
		AL1 = 9,
		AL2 = 10,
		L1R = 11,
		L2R = 12
	};

	Q_UINT8 dst_type;
	Q_UINT8 dst_sense;
};

struct LFO
{
	enum FormType
	{
		Triangle = 0,
		Sinus    = 1,
		Saw      = 2,
		Square   = 3,
		Random1  = 4,
		Random2  = 5
	};
	enum OffsetType
	{
		M100 = 0,
		M50  = 1,
		None = 2,
		P50  = 3,
		P100 = 4
	};
	enum PolarityType
	{
		In  = 0,
		Out = 1
	};

	Q_UINT8 lfo_form;
	Q_UINT8 lfo_offset;
	Q_UINT8 lfo_synchro;
	Q_UINT8 lfo_rate;
	UInt16_ lfo_delay;
	Q_UINT8 lfo_fadepolatiry;
	Q_UINT8 lfo_fadetime;
	Q_UINT8 lfo_pitchdepth;
	Q_UINT8 lfo_tvfdepth;
	Q_UINT8 lfo_tvadepth;
};

namespace Envelope
{
	enum Values
	{
		M100 = 0,
		M70  = 1,
		M50  = 2,
		M40  = 3,
		M30  = 4,
		M20  = 5,
		M10  = 6,
		None = 7,
		P10  = 8,
		P20  = 9,
		P30  = 10,
		P40  = 11,
		P50  = 12,
		P70  = 13,
		P100 = 14,
		P200 = 15
	};
	enum CurveTpe
	{
		Curve1 = 0,
		Curve2 = 1,
		Curve3 = 2,
		Curve4 = 3,
		Curve5 = 4,
		Curve6 = 5,
		Curve7 = 6,
	};
};

struct Pitch
{
	enum RandDepthType
	{
		Rand0    = 0,
		Rand5    = 1,
		Rand10   = 2,
		Rand20   = 3,
		Rand30   = 4,
		Rand40   = 5,
		Rand50   = 6,
		Rand70   = 7,
		Rand100  = 8,
		Rand200  = 9,
		Rand300  = 10,
		Rand400  = 11,
		Rand500  = 12,
		Rand600  = 13,
		Rand800  = 14,
		Rand1200 = 15,
	};

	Q_UINT8 pitch_coarse;
	Q_UINT8 pitch_fine;
	Q_UINT8 pitch_randdepth;
	Q_UINT8 pitch_keyfollow;
	struct
	{
		Q_UINT8 vel_levelsense;
		Q_UINT8 vel_ontimesense;
		Q_UINT8 vel_offtimesense;
		Q_UINT8 time_keyfollow;
		Q_UINT8 depth;
		Q_UINT8 T1;
		Q_UINT8 L1;
		Q_UINT8 T2;
		Q_UINT8 L2;
		Q_UINT8 T3;
		Q_UINT8 L3;
		Q_UINT8 T4;
		Q_UINT8 L4;
	} pitch_env;
};

struct TVF
{
	enum ModeType
	{
		Off      = 0,
		LowPass  = 1,
		HighPass = 2
	};
	enum ResonanceType
	{
		Soft = 0,
		Hard = 1
	};

	Q_UINT8 tvf_mode;
	Q_UINT8 tvf_cutoff;
	Q_UINT8 tvf_resonance;
	Q_UINT8 tvf_resonancemode;
	Q_UINT8 tvf_cutoffkeyfollow;
	struct
	{
		Q_UINT8 vel_curve;
		Q_UINT8 vel_levelsense;
		Q_UINT8 vel_ontimesense;
		Q_UINT8 vel_offtimesense;
		Q_UINT8 time_keyfollow;
		Q_UINT8 depth;
		Q_UINT8 T1;
		Q_UINT8 L1;
		Q_UINT8 T2;
		Q_UINT8 L2;
		Q_UINT8 T3;
		Q_UINT8 L3;
		Q_UINT8 T4;
		Q_UINT8 L4;
	} tvf_env;
};

struct TVA
{
	enum DelayMode
	{
		Normal   = 0,
		Hold     = 1,
		PlayMate = 2
	};

	Q_UINT8 tva_level;
	Q_UINT8 tva_levelkeyfollow;
	UInt16_ tva_pan;
	Q_UINT8 tva_pankeyfollow;
	Q_UINT8 tva_tonedelaymode;
	UInt16_ tva_tonedelaytime;
	struct
	{
		Q_UINT8 vel_curve;
		Q_UINT8 vel_levelsense;
		Q_UINT8 vel_ontimesense;
		Q_UINT8 vel_offtimesense;
		Q_UINT8 time_keyfollow;
		Q_UINT8 T1;
		Q_UINT8 L1;
		Q_UINT8 T2;
		Q_UINT8 L2;
		Q_UINT8 T3;
		Q_UINT8 L3;
		Q_UINT8 T4;
	} tva_env;
};

class Tone : public JVObject
{
public:
	enum GroupType
	{
		Internal      = 0,
		ExpansionCard = 1,
		PCMCard       = 2
	};

	Tone() : JVObject( JVObject::ToneObject ) { data.tone_outputbus = data.tone_damper = 0x00; }

	struct _data {
	Q_UINT8 tone_wavegroup;
	UInt16_ tone_wavenumber;
	Q_UINT8 tone_waveswitch;
	Q_UINT8 tone_fxmswitch;
	Q_UINT8 tone_fxmdepth;
	Q_UINT8 tone_velrangelower;
	Q_UINT8 tone_velrangeupper;
	Q_UINT8 tone_volumeswitch;
	Q_UINT8 tone_hold1switch;
	ControlDest tone_modulation[ 4 ];
	ControlDest tone_aftertouch[ 4 ];
	ControlDest tone_expression[ 4 ];
	LFO tone_lfo[ 2 ];
	Pitch tone_pitch;
	TVF tone_tvf;
	TVA tone_tva;
	Q_UINT8 tone_drylevel;
	Q_UINT8 tone_reverblevel;
	Q_UINT8 tone_choruslevel;
	Q_UINT8 tone_outputbus;
	Q_UINT8 tone_damper;
	} data;

	JVEditor* createEditor( QWidget* );
};

class Patch : public JVObject
{
public:
	enum KeyAssignType
	{
		Poly = 0,
		Solo = 1
	};
	enum PortamentoModeType
	{
		Legato = 0,
		Normal = 0
	};
	enum PortamentoType
	{
		Time = 0,
		Rate = 1
	};

	Patch() : JVObject( JVObject::PatchObject ) {}

	struct _data {
	Q_UINT8 patch_name[ 12 ];
	Q_UINT8 patch_velocityswitch;
	Reverb patch_reverb;
	Chorus patch_chorus;
	Q_UINT8 patch_analogfeel;
	Q_UINT8 patch_level;
	Q_UINT8 patch_pan;
	Q_UINT8 patch_benddown;
	Q_UINT8 patch_bendup;
	Q_UINT8 patch_keyassign;
	Q_UINT8 patch_sololegato;
	Portamento patch_portamento;
	} data;
	Tone patch_tones[ 4 ];

	unsigned int patch_offset;

	JVEditor* createEditor( QWidget* );
	QByteArray toSysex( SysexIface*, Q_UINT32 = 0xFFFFFFFF );
	SysexRequest* sendRequest( bool useAddr = true );
	Q_UINT32 objectOffset() const;
	QString objectName() const;

	unsigned int readSysex( unsigned char *data, unsigned int len );
	Patch* clone();
};

class PerformancePart : public JVObject
{
public:
	PerformancePart() : JVObject( JVObject::PartObject ) {}

	struct _data {
	/* Transmit */
	Q_UINT8 part_tx_switch;
	Q_UINT8 part_tx_channel;
	UInt16_ part_tx_progchange;
	UInt16_ part_tx_volume;
	UInt16_ part_tx_pan;
	Q_UINT8 part_tx_keyrangelower;
	Q_UINT8 part_tx_keyrangeupper;
	Q_UINT8 part_tx_keytranspose;
	Q_UINT8 part_tx_velsense;
	Q_UINT8 part_tx_velmax;
	Q_UINT8 part_tx_velcurve;
	/* Internal */
	Q_UINT8 part_int_switch;
	Q_UINT8 part_int_keyrangelower;
	Q_UINT8 part_int_keyrangeupper;
	Q_UINT8 part_int_keytranspose;
	Q_UINT8 part_int_velsense;
	Q_UINT8 part_int_velmax;
	Q_UINT8 part_int_velcurve;
	/* Receive */
	Q_UINT8 part_rx_switch;
	Q_UINT8 part_rx_channel;
	UInt16_ part_patchnumber;
	Q_UINT8 part_level;
	Q_UINT8 part_pan;
	Q_UINT8 part_coarse;
	Q_UINT8 part_fine;
	Q_UINT8 part_reverbswitch;
	Q_UINT8 part_chorusswitch;
	Q_UINT8 part_rx_progchange;
	Q_UINT8 part_rx_volume;
	Q_UINT8 part_rx_hold1;
	} data;
	
	JVEditor* createEditor( QWidget* );
};

class Performance : public JVObject
{
public:
	enum KeyModeType
	{
		Layer  = 0,
		Zone   = 1,
		Single = 2
	};

	Performance() : JVObject( JVObject::PerformanceObject ) {}

	struct _data {
	Q_UINT8 perf_name[ 12 ];
	Q_UINT8 perf_keymode;
	Reverb perf_reverb;
	Chorus perf_chorus;
	Q_UINT8 perf_voicereserve[ 8 ];
	} data;
	PerformancePart perf_parts[ 8 ];

	unsigned int perf_offset;

	JVEditor* createEditor( QWidget* );
	QByteArray toSysex( SysexIface*, Q_UINT32 = 0xFFFFFFFF );
	SysexRequest* sendRequest( bool useAddr = true );
	Q_UINT32 objectOffset() const;
	QString objectName() const;

	unsigned int readSysex( unsigned char *data, unsigned int len );
	Performance* clone();
};

class Bank : public JVObject
{
public:
	Bank() : JVObject( JVObject::BankObject ) { bank_objects.setAutoDelete( true ); }

	QList<JVObject> bank_objects;

	JVEditor* createEditor( QWidget* );
	QByteArray toSysex( SysexIface*, Q_UINT32 = 0xFFFFFFFF );
	SysexRequest* sendRequest( bool useAddr = true );
};

#endif /* JVTYPES_H */
