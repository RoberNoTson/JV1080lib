// file_parser.cpp -- part of MIDI_PLAYER
// validate the midi file is formatted correctly, then parse the track data
// and load events into memory images.
// Requires "seq", "queue", "song_length_seconds" vars
// contains:
//      parseFile() -- main process that calls the other functions
//      read_riff() -- RIFF is a (potential) wrapper around SMF data, strip it off
//      read_smf()  -- this is the heavy lifting of parsing the Standard Midi File (SMF) data
//      read_track() -- called from read_smf to get midi data
//      read_id()   -- INLINE helper function
//      read_byte()   -- INLINE helper function
//      skip()   -- INLINE helper function
//      tick_comp()   -- sort helper function
//      read_32_le()   -- helper function
//      read_int()   -- helper function
//      read_var()   -- helper function

#include "midi_player.h"
#include "ui_midi_player.h"
#include <alsa/asoundlib.h>
#include <algorithm>
#include <QDebug>
#include <iostream>

#define MAKE_ID(c1, c2, c3, c4) ((c1) | ((c2) << 8) | ((c3) << 16) | ((c4) << 24))

bool MIDI_PLAYER::minor_key=false;
int MIDI_PLAYER::sf=0;  // 0=Cmajor, <0 = #flats, >0 = #sharps
int smpte_timing;
int file_offset;
int prev_tick;
FILE *file;
double BPM=0,PPQ=0;

// helper functions, most are INLINE
int MIDI_PLAYER::read_id(void) {
    return read_32_le();
}
int MIDI_PLAYER::read_byte(void) {
    ++file_offset;
    return getc(file);
}
int MIDI_PLAYER::read_32_le(void) {
    int value = read_byte();
    value |= read_byte() << 8;
    value |= read_byte() << 16;
    value |= read_byte() << 24;
    return !feof(file) ? value : -1;
}
int MIDI_PLAYER::read_int(int bytes) {
    int value = 0;
    do {
        int c = read_byte();
        if (c == EOF)
            return -1;
        value = (value << 8) | c;
    } while (--bytes);
    return value;
}
int MIDI_PLAYER::read_var(void) {
    int c = read_byte();
    int value = c & 0x7f;
    if (c & 0x80) {
        c = read_byte();
        value = (value << 7) | (c & 0x7f);
        if (c & 0x80) {
            c = read_byte();
            value = (value << 7) | (c & 0x7f);
            if (c & 0x80) {
                c = read_byte();
                value = (value << 7) | c;
                if (c & 0x80)
                    return -1;
            }
        }
    }
    return !feof(file) ? value : -1;
}   // end read_var
void MIDI_PLAYER::skip(int bytes) {
    while (bytes > 0)
        read_byte(), --bytes;
}


// start of data reading functions
int MIDI_PLAYER::read_riff(char *file_name) {
    // skip file length
    read_byte();
    read_byte();
    read_byte();
    read_byte();
    // check file type ("RMID" = RIFF MIDI)
    if (read_id() != MAKE_ID('R', 'M', 'I', 'D')) {
invalid_format:
        QMessageBox::critical(this, "MIDI Player", QString("%1: invalid file format") .arg(file_name));
        return 0;
    }
    // search for "data" chunk
    for (;;) {
        int id = read_id();
        int len = read_32_le();
        if (feof(file)) {
data_not_found:
            QMessageBox::critical(this, "MIDI Player", QString("%1: data chunk not found") .arg(file_name));
            return 0;
        }
        if (id == MAKE_ID('d', 'a', 't', 'a'))
            break;
        if (len < 0) goto data_not_found;
        skip((len + 1) & ~1);
    }
    // the "data" chunk must contain data in SMF format
    if (read_id() != MAKE_ID('M', 'T', 'h', 'd'))
        goto invalid_format;
    return read_smf(file_name);
}   // end read_riff

int MIDI_PLAYER::read_smf(char *file_name) {
    // read midi data into memory, parsing it into events
    // the starting position is immediately after the "MThd" id
   int  header_len = read_int(4);   // header length
    if (header_len < 6) {
invalid_format:
        QMessageBox::critical(this, "MIDI Player", QString("%1: invalid file format") .arg(file_name));
        return 0;
    }
    int type = read_int(2);     // midi type 0 or 1
    if (type != 0 && type != 1) {
        QMessageBox::critical(this, "MIDI Player", QString("%1: type %2 format is not supported") .arg(file_name) .arg(type));
        return 0;
    }
    int num_tracks = read_int(2);       // number of tracks
    if (num_tracks < 1 || num_tracks > 1000) {
        QMessageBox::critical(this, "MIDI Player", QString("%1: invalid number of tracks (%2)") .arg(file_name) .arg(num_tracks));
        num_tracks = 0;
        return 0;
    }
    int time_division = read_int(2);    // time division
    qDebug() << "time_division/ppq: " << time_division;
    if (time_division < 0)
        goto invalid_format;
    // interpret and set tempo
    snd_seq_queue_tempo_t *queue_tempo;
    snd_seq_queue_tempo_alloca(&queue_tempo);
    smpte_timing = !!(time_division & 0x8000);
    if (!smpte_timing) {
        // time_division is ticks per quarter
        snd_seq_queue_tempo_set_tempo(queue_tempo, 500000); // default: 120 bpm
        snd_seq_queue_tempo_set_ppq(queue_tempo, time_division);
    } else {
        // upper byte is negative frames per second
        int i = 0x80 - ((time_division >> 8) & 0x7f);
        // lower byte is ticks per frame
        time_division &= 0xff;
        // now pretend that we have quarter-note based timing
        switch (i) {
        case 24:
            snd_seq_queue_tempo_set_tempo(queue_tempo, 500000);
            snd_seq_queue_tempo_set_ppq(queue_tempo, 12 * time_division);
            break;
        case 25:
            snd_seq_queue_tempo_set_tempo(queue_tempo, 400000);
            snd_seq_queue_tempo_set_ppq(queue_tempo, 10 * time_division);
            break;
        case 29: // 30 drop-frame
            snd_seq_queue_tempo_set_tempo(queue_tempo, 100000000);
            snd_seq_queue_tempo_set_ppq(queue_tempo, 2997 * time_division);
            break;
        case 30:
            snd_seq_queue_tempo_set_tempo(queue_tempo, 500000);
            snd_seq_queue_tempo_set_ppq(queue_tempo, 15 * time_division);
            break;
        default:
            QMessageBox::critical(this, "MIDI Player", QString("%1: invalid number of SMPTE frames per second (%2)") .arg(file_name) .arg(i));
            return 0;
        }
    }
    int err = snd_seq_set_queue_tempo(seq, queue, queue_tempo);
    if (err < 0) {
        QMessageBox::critical(this, "MIDI Player", QString("Cannot set queue tempo (%1/%2") .arg(snd_seq_queue_tempo_get_tempo(queue_tempo)) .arg(snd_seq_queue_tempo_get_ppq(queue_tempo)));
        return 0;
    }
    PPQ = snd_seq_queue_tempo_get_ppq(queue_tempo);
    qDebug() << "Initial Tempo: " << snd_seq_queue_tempo_get_tempo(queue_tempo);
    if (PPQ != time_division) qDebug() << "New ppq: " << PPQ;
    BPM = static_cast<double>(1000000/static_cast<double>(snd_seq_queue_tempo_get_tempo(queue_tempo))*60);
    song_length_seconds = prev_tick = 0;
    // read len data from track unless EOF or new track found
    for (int j = 0; j < num_tracks; ++j) {
        qDebug() << "Process track" << j+1 << "of" << num_tracks;
        int len;
        // verify data is valid
        for (;;) {
            int id = read_id();
            len = read_int(4);      // track length
            if (feof(file)) {
                QMessageBox::critical(this, "MIDI Player", QString("%1: unexpected end of file") .arg(file_name));
                return 0;
            }
            if (len < 0 || len >= 0x10000000) {
                QMessageBox::critical(this, "MIDI Player", QString("%1: invalid chunk length %2") .arg(file_name) .arg(len));
                return 0;
            }
            if (id == MAKE_ID('M', 'T', 'r', 'k'))
                break;            // found start of a new track, loop back and process it
            skip(len);
        }   // end FOR (infinite)
        // do the actual reading of midi data from the file
        if (!read_track(file_offset + len, file_name))
            return 0;
    }   // end FOR j
    // sort the event vector in tick order
    std::sort(all_events.begin(), all_events.end(), tick_comp);
    if (song_length_seconds == 0) {
        song_length_seconds = (60000/(BPM*PPQ)) * all_events.back().tick / 1000 ;
        qDebug() << "Song length: " << song_length_seconds;
    }
    else {
        song_length_seconds += (60000/(BPM*PPQ)) * (all_events.back().tick-prev_tick) / 1000 ;
        qDebug() << "Song length: " << song_length_seconds;
    }
    return 1;   // good return, all data read ok
}   // end read_smf

bool MIDI_PLAYER::tick_comp(const struct event& e1, const struct event& e2) { return e1.tick<e2.tick; }
int MIDI_PLAYER::read_track(int track_end, char *file_name) {
// read one complete track from the file, parse it into events
    int tick = 0;
    unsigned char last_cmd = 0;
    unsigned char port = 0;
    struct event Event;
    // the current file position is after the track ID and length
    while (file_offset < track_end) {
        unsigned char cmd;
        int len, c;

        int delta_ticks = read_var();
        if (delta_ticks < 0)
            break;
        tick += delta_ticks;
        c = read_byte();
        if (c < 0)
            break;      // bad data, exit with rc
        if (c & 0x80) {
            // have command
            cmd = c;
            if (cmd < 0xf0)
                last_cmd = cmd;
        } else {
            // running status
            ungetc(c, file);
            file_offset--;
            cmd = last_cmd;
            if (!cmd)
                goto _error;
        }
        unsigned int x = cmd >> 4;
        static unsigned char cmd_type[0xf];
        switch(x) {
        case 0x8:
            cmd_type[x] = SND_SEQ_EVENT_NOTEOFF;
            break;
        case 0x9:
            cmd_type[x] = SND_SEQ_EVENT_NOTEON;
            break;
        case 0xA:
            cmd_type[x] = SND_SEQ_EVENT_KEYPRESS;
            break;
        case 0xB:
            cmd_type[x] = SND_SEQ_EVENT_CONTROLLER;
            break;
        case 0xC:
            cmd_type[x] = SND_SEQ_EVENT_PGMCHANGE;
            break;
        case 0xD:
            cmd_type[x] = SND_SEQ_EVENT_CHANPRESS;
            break;
        case 0xE:
            cmd_type[x] = SND_SEQ_EVENT_PITCHBEND;
            break;
        }
        switch(x) {
        case 0x8: // channel msg with 2 parameter bytes
        case 0x9:
        case 0xa:
        case 0xb:
        case 0xe:
            Event.type = cmd_type[cmd >> 4];
            Event.port = port;
            Event.tick = tick;
            Event.data.d[0] = cmd & 0x0f;
            Event.data.d[1] = read_byte() & 0x7f;
            Event.data.d[2] = read_byte() & 0x7f;
            all_events.push_back(Event);
            break;
        case 0xc: // channel msg with 1 parameter byte
        case 0xd:
            Event.type = cmd_type[cmd >> 4];
            Event.port = port;
            Event.tick = tick;
            Event.data.d[0] = cmd & 0x0f;
            Event.data.d[1] = read_byte() & 0x7f;
            all_events.push_back(Event);
            break;
        case 0xf:
            switch (cmd) {
            case 0xf0: // sysex
            case 0xf7: // continued sysex, or escaped commands
                len = read_var();
                if (len < 0) goto _error;
                if (cmd == 0xf0) ++len;
                Event.type = SND_SEQ_EVENT_SYSEX;
                Event.port = port;
                Event.tick = tick;
                Event.data.length = len;
                if (cmd == 0xf0) {
                    Event.sysex.push_back(0xf0);
                    c = 1;
                } else {
                    c = 0;
                }
                for (; c < len; ++c)
                    Event.sysex.push_back(read_byte());
                all_events.push_back(Event);
                break;
            case 0xff: // meta event
                c = read_byte();
                len = read_var();
                if (len < 0) goto _error;
                switch (c) {
                case 0x21: // port number
                    if (len < 1) goto _error;
                    port = read_byte();
                    skip(len - 1);
                    break;
                case 0x2f: // end of track
                    skip(track_end - file_offset);
                    return 1;   // this is the successful exit point, end of the track
                case 0x51: // tempo
                    if (len < 3) goto _error;
                    if (smpte_timing) {
                        // SMPTE timing doesn't change
                        skip(len);
                    } else {
                        Event.type = SND_SEQ_EVENT_TEMPO;
                        Event.port = port;
                        Event.tick = tick;
                        Event.data.tempo = read_byte() << 16;
                        Event.data.tempo |= read_byte() << 8;
                        Event.data.tempo |= read_byte();
                        all_events.push_back(Event);
                        skip(len - 3);
                        song_length_seconds += (60000/(BPM*PPQ)) * (tick-prev_tick) / 1000 ;
                        prev_tick = tick;
                        BPM = static_cast<double>(1000000/static_cast<double>(Event.data.tempo)*60);
                        qDebug() << "New tempo: " << Event.data.tempo;
                        qDebug() << " BPM: " << BPM << " at tick " << Event.tick;
                        qDebug() << "New song_len: " << song_length_seconds;
                    }
                    break;
                case 0x59:  // Key Signature
                    if (len<2) goto _error;
                    sf = read_byte();
                    minor_key = read_byte();
//                    qDebug() << "Key: " << sf << (minor_key?" minor":" Major");
                    break;
                default: // ignore all other meta events
                    skip(len);
                    break;
                }   // end SWITCH (meta-event byte value)
                break;
            default: // invalid Fx command
                goto _error;
            }   // end SWITCH (cmd)
            break;
        default: // cannot happen
            goto _error;
        }   // end switch
    }   // end WHILE (one complete track)
_error:
    QMessageBox::critical(this, "MIDI Player", QString("%1: invalid MIDI data (offset %2)") .arg(file_name) .arg(file_offset));
    return 0;
}   // end read_track

int MIDI_PLAYER::parseFile(char *file_name) {
    // parse the midi file
    file = fopen(file_name, "rb");
    if (!file) {
        QMessageBox::critical(this, "MIDI Player", QString("Cannot open %s - %s") .arg(file_name) .arg(strerror(errno)));
        return 0;
    }
    file_offset = 0;
    int ok = 0;
    // validate and load the midi data into memory for playing
    switch (read_id()) {
    case MAKE_ID('M', 'T', 'h', 'd'):
        ok = read_smf(file_name);
        break;
    case MAKE_ID('R', 'I', 'F', 'F'):
        ok = read_riff(file_name);
        break;
    default:
        QMessageBox::critical(this, "MIDI Player", QString("%1 is not a Standard MIDI File") .arg(file_name));
        break;
    }
    fclose(file);   // all data loaded or invalid file
    return ok;
}   // end parseFile
