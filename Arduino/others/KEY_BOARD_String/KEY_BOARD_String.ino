#include <PS2Keyboard.h>
String str;
const int DataPin = 2;
const int IRQpin =  3;

PS2Keyboard keyboard;

void setup() {
  keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);
  Serial.println("Keyboard Test:");
  Serial.println("Please type a Sring");
  Serial.println("and Press Enter");
}

void loop() {

  if (keyboard.available()) {
    char c = keyboard.read();
    str = str + c;
    if (c == PS2_ENTER)
    {
      Serial.println(str);
      for (int i = 0; i < str.length(); i++)
      {
        str = str + 0;
      }
    }
  }
}
