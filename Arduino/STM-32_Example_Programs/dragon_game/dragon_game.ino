#include <USBComposite.h>

USBHID HID;
HIDKeyboard Keyboard(HID);

int data = 0;
int threshold = 1020;

void setup() {
  Serial.begin(9600);
  HID.begin(HID_KEYBOARD);
  while (!USBComposite);
  Keyboard.begin();
  pinMode(PC13, INPUT);
  pinMode(PA8, OUTPUT);
}

void loop() {
  data = analogRead(PA0);
  Serial.println(data);
  threshold = analogRead(PA1);
  if(data > threshold) //1020
  {
    Keyboard.write(KEY_UP_ARROW);
    digitalWrite(PA8, HIGH);
  }
  else
  {
    digitalWrite(PA8, LOW);
  }
}
