// player.cpp   -- part of JVlibForm
// play memory image midi data to the alsa seq port
// requires access to "seq","queue", "ports" static vars
// contains:
//      check_snd()
//      play_midi()

#include        "JVlibForm.h"
#include <alsa/asoundlib.h>
#include <vector>
#include <QTimer>

// INLINE function
void JVlibForm::check_snd(const char *operation, int err) {
    // error handling for ALSA functions
    if (err < 0)
        QMessageBox::critical(this, "MIDI Player", QString("Cannot %1\n%2") .arg(operation) .arg(snd_strerror(err)));
}

void JVlibForm::play_midi(unsigned int startTick) {
    int end_delay = 2, err;
    // set data in (snd_seq_event_t ev) and output the event
    // common settings for all events
    snd_seq_event_t ev;
    snd_seq_ev_clear(&ev);
    ev.queue = queue;
    ev.source.port = 0;
    ev.flags = SND_SEQ_TIME_STAMP_TICK;
    // parse each event
    for (std::vector<event>::iterator Event=all_events.begin(); Event!=all_events.end(); ++Event)  {
        // skip over everything except TEMPO, CONTROLLER, PROGRAM, VELOCITY changes until startTick is reached.
        if (Event->tick<startTick &&
            (Event->type!=SND_SEQ_EVENT_TEMPO ||
             Event->type!=SND_SEQ_EVENT_CONTROLLER ||
             Event->type!=SND_SEQ_EVENT_PGMCHANGE ||
             Event->type!=SND_SEQ_EVENT_CHANPRESS ||
             Event->type!=SND_SEQ_EVENT_SYSEX ||
             Event->type!=SND_SEQ_EVENT_KEYSIGN)) 
	{
          continue;
	}
        ev.time.tick = Event->tick;
        ev.type = Event->type;
        ev.dest = ports[0];
        switch (ev.type) {
        case SND_SEQ_EVENT_NOTEON:
        case SND_SEQ_EVENT_NOTEOFF:
        case SND_SEQ_EVENT_KEYPRESS:
            snd_seq_ev_set_fixed(&ev);
            ev.data.note.channel = Event->data.d[0];
            ev.data.note.note = Event->data.d[1]+(Event->data.d[0]==9?0: System_MIDI_Transpose->value());
            ev.data.note.velocity = Event->data.d[2];
            break;
        case SND_SEQ_EVENT_CONTROLLER:
            snd_seq_ev_set_fixed(&ev);
            ev.data.control.channel = Event->data.d[0];
            ev.data.control.param = Event->data.d[1];
            ev.data.control.value = Event->data.d[2];
            break;
        case SND_SEQ_EVENT_PGMCHANGE:
        case SND_SEQ_EVENT_CHANPRESS:
            snd_seq_ev_set_fixed(&ev);
            ev.data.control.channel = Event->data.d[0];
            ev.data.control.value = Event->data.d[1];
            break;
        case SND_SEQ_EVENT_PITCHBEND:
            snd_seq_ev_set_fixed(&ev);
            ev.data.control.channel = Event->data.d[0];
            ev.data.control.value =
                ((Event->data.d[1]) |
                 ((Event->data.d[2]) << 7)) - 0x2000;
            break;
        case SND_SEQ_EVENT_SYSEX:
            snd_seq_ev_set_variable(&ev, Event->data.length, &Event->sysex);
            break;
        case SND_SEQ_EVENT_TEMPO:
            snd_seq_ev_set_fixed(&ev);
            ev.dest.client = SND_SEQ_CLIENT_SYSTEM;
            ev.dest.port = SND_SEQ_PORT_SYSTEM_TIMER;
            ev.data.queue.queue = queue;
            ev.data.queue.param.value = Event->data.tempo;
            break;
        case SND_SEQ_EVENT_KEYSIGN:
	  if (System_MIDI_KeySig->text().size() && Event->data.d[2]==minor_key && Event->data.d[1]==sf) break;
            System_MIDI_KeySig->clear();
            if (Event->data.d[2]) {	// minor key
                switch(Event->data.d[1]) {
                case 0:
                    System_MIDI_KeySig->setText("a minor");
                    break;
                case 1:
                    System_MIDI_KeySig->setText("e minor");
                    break;
                case 2:
                    System_MIDI_KeySig->setText("b minor");
                    break;
                case 3:
                    System_MIDI_KeySig->setText("f# minor");
                    break;
                case 4:
                    System_MIDI_KeySig->setText("c# minor");
                    break;
                case 5:
                    System_MIDI_KeySig->setText("g# minor");
                    break;
                case 6:
                    System_MIDI_KeySig->setText("d# minor");
                    break;
                case 7:
                    System_MIDI_KeySig->setText("a# minor");
                    break;
                case 0xff:
                    System_MIDI_KeySig->setText("d minor");
                    break;
                case 0xfe:
                    System_MIDI_KeySig->setText("g minor");
                    break;
                case 0xfd:
                    System_MIDI_KeySig->setText("c minor");
                    break;
                case 0xFC:
                    System_MIDI_KeySig->setText("f minor");
                    break;
                case 0xFB:
                    System_MIDI_KeySig->setText("bf minor");
                    break;
                case 0xFA:
                    System_MIDI_KeySig->setText("ef minor");
                    break;
                case 0xF9:
                    System_MIDI_KeySig->setText("af minor");
                    break;
		default:
		  System_MIDI_KeySig->clear();
		  System_MIDI_KeySig->setText("n/a");
		  break;
                }
            }
            else {	// major key
                switch(Event->data.d[1]) {
                case 0:
                    System_MIDI_KeySig->setText("C Major");
                    break;
                case 1:
                    System_MIDI_KeySig->setText("G Major");
                    break;
                case 2:
                    System_MIDI_KeySig->setText("D Major");
                    break;
                case 3:
                    System_MIDI_KeySig->setText("A Major");
                    break;
                case 4:
                    System_MIDI_KeySig->setText("E Major");
                    break;
                case 5:
                    System_MIDI_KeySig->setText("B Major");
                    break;
                case 6:
                    System_MIDI_KeySig->setText("F# Major");
                    break;
                case 7:
                    System_MIDI_KeySig->setText("C# Major");
                    break;
                case 0xFF:
                    System_MIDI_KeySig->setText("F Major");
                    break;
                case 0xFE:
                    System_MIDI_KeySig->setText("Bf Major");
                    break;
                case 0xFD:
                    System_MIDI_KeySig->setText("Ef Major");
                    break;
                case 0xFC:
                    System_MIDI_KeySig->setText("Af Major");
                    break;
                case 0xFB:
                    System_MIDI_KeySig->setText("Df Major");
                    break;
                case 0xFA:
                    System_MIDI_KeySig->setText("Gf Major");
                    break;
                case 0xF9:
                    System_MIDI_KeySig->setText("Cf Major");
                    break;
		default:
		  System_MIDI_KeySig->clear();
		  System_MIDI_KeySig->setText("n/a");
		  break;
                }
            }
            break;
        default:
            QMessageBox::critical(this, "MIDI Player", QString("Invalid event type %1") .arg(ev.type));
	    return;
        }   // end SWITCH ev.type
        // this blocks when the output pool has been filled
        err = snd_seq_event_output(seq, &ev);
        check_snd("output event", err);
    }	// end for (read loop)

    // schedule queue stop at end of song
    snd_seq_ev_set_fixed(&ev);
    ev.type = SND_SEQ_EVENT_STOP;
    ev.time.tick = all_events.back().tick;
    ev.dest.client = SND_SEQ_CLIENT_SYSTEM;
    ev.dest.port = SND_SEQ_PORT_SYSTEM_TIMER;
    ev.data.queue.queue = queue;
    err = snd_seq_event_output(seq, &ev);
    check_snd("output event", err);
    // make sure that the sequencer sees all our events
    err = snd_seq_drain_output(seq);
    check_snd("drain output", err);

    // There are three possibilities for how to wait until all events have been played:
    // 1) send an event back to us (like pmidi does), and wait for it;
    // 2) wait for the EVENT_STOP notification for our queue which is sent
    //    by the system timer port (this would require a subscription);
    // 3) wait until the output pool is empty.
    // The last is the simplest.
    err = snd_seq_sync_output_queue(seq);
    check_snd("sync output", err);
    // give the last notes time to die away
    if (end_delay > 0)
        sleep(end_delay);
}   // end play_midi
