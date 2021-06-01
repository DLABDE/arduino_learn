#include "pitches.h"

int melody[] = {
  NOTE_E8, NOTE_E2, NOTE_E2, NOTE_E1, NOTE_E1, NOTE_E2, NOTE_E1, NOTE_E4
};

int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 4
};

void setup() {

}

void loop() {
  for (int thisNote = 0; thisNote < 8; thisNote++) 
  {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(2, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(2);
  }
  delay(1500);
}
