#include "DigiKeyboard.h"
void setup() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1500);
  DigiKeyboard.sendKeyPress(0, MOD_GUI_LEFT);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("Dev-C++"));
  DigiKeyboard.delay(1500);
  DigiKeyboard.println();
  DigiKeyboard.delay(4500);
  DigiKeyboard.sendKeyPress(KEY_N, MOD_CONTROL_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyPress(0, 0);
  DigiKeyboard.print(F("#include<stdio.h"));
  DigiKeyboard.sendKeyPress(KEY_ARROW_RIGHT);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyPress(0, 0);
  DigiKeyboard.println();
  DigiKeyboard.print(F("main("));
  DigiKeyboard.sendKeyPress(KEY_ARROW_RIGHT);
  DigiKeyboard.println();
  DigiKeyboard.println("{");
  DigiKeyboard.print(F("printf(\"Hi Shuva"));
  DigiKeyboard.sendKeyPress(KEY_ARROW_RIGHT);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyPress(0, 0);
  DigiKeyboard.sendKeyPress(KEY_ARROW_RIGHT);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyPress(0, 0);
  DigiKeyboard.print(";");
  DigiKeyboard.sendKeyPress(KEY_F11);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyPress(0, 0);
  DigiKeyboard.delay(1000);
  DigiKeyboard.println(F("Auto_Typing_C"));
}

void loop() {
  // put your main code here, to run repeatedly:

}
