// create_playmidi_actions.cpp

#include        "JVlibForm.h"
#include <alsa/asoundlib.h>
#include <QTimer>

// STATIC vars
snd_seq_t *JVlibForm::seq=0;
int JVlibForm::queue=0;
snd_seq_addr_t *JVlibForm::ports=0;
double JVlibForm::song_length_seconds=0;

void JVlibForm::createPlayMidi() {
  seqTimer = new QTimer(this);
  memset(port_name,0,sizeof(port_name));
  init_seq();
  queue = snd_seq_alloc_named_queue(seq, "midi_player");
  check_snd("create queue", queue);
  snd_seq_queue_status_malloc(&status);
//  close_seq();
  pid = 0;
}

