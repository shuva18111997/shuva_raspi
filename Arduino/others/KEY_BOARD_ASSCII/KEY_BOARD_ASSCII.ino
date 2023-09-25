#include <PS2Keyboard.h>

const int DataPin = 2;
const int IRQpin =  3;

PS2Keyboard keyboard;

void setup() {
  keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);
  Serial.println("Keyboard Test:");
}

void loop() {
  if (keyboard.available()) {
    char c = keyboard.read();
    Serial.println(c,DEC);
  }
}
