#include "DigiKeyboard.h"
#define dtime 300
void setup() {
  delay(3000);
}

void loop() {
  delay(200);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(dtime);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(dtime);
  DigiKeyboard.println("cmd");
  DigiKeyboard.delay(dtime);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(dtime);
  DigiKeyboard.println("notepad");
  DigiKeyboard.delay(dtime);
  DigiKeyboard.println("haha!haha!");
  DigiKeyboard.delay(dtime);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
}
