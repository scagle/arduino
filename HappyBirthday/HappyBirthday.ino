#include "pitches.h"
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4, 0,
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4, 0,
  NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4, 0,
  NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4
};

boolean isPlaying = false;
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 2, 2, 2, 2, 2,
  4, 4, 2, 2, 2, 2, 2,
  4, 4, 2, 2, 2, 2, 2, 2,
  4, 4, 2, 2, 2, 1
};

void setup() {
  pinMode(12, INPUT);
  play();
}
void play()
{
  isPlaying = true;
// iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 28; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(2, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(2);
  }
  isPlaying = false;
}
void loop() {

  
}
