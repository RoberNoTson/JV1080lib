// create_playmidi_actions.cpp

#include        "JVlibForm.h"
#include <alsa/asoundlib.h>
#include <QTimer>

// INLINE functions
void JVlibForm::check_snd(const char *operation, int err)
{
    if (err < 0)
        QMessageBox::critical(this, "MIDI Player", QString("Cannot %1\n%2") .arg(operation) .arg(snd_strerror(err)));
}

void JVlibForm::createPlayMidi() {
  seqTimer = new QTimer(this);
  memset(SEQ_dev,0,sizeof(SEQ_dev));
  init_seq();
  queue = snd_seq_alloc_named_queue(seq, "midi_player");
  check_snd("create queue", queue);
  snd_seq_queue_status_malloc(&status);
  pid = 0;
  SysPlayMidi_button->setEnabled(false);
}

