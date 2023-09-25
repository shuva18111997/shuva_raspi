void refresh()
{
  int d1 = 0x01;
  int d2 = 0x80;
  int t = 20;
  for (int i = 0; i < 8; i++) {
    digitalWrite(latchPin, LOW);
    shiftOut(SdataPin, SclockPin, LSBFIRST, ~0x00);
    shiftOut(dataPin, clockPin, LSBFIRST, ~d1);      //For the last 8 leds
    shiftOut(dataPin, clockPin, LSBFIRST, ~0x00);     //For the first 8 leds
    digitalWrite(latchPin, HIGH);
    delay(t);
    d1 = d1 << 1;
  }
  d1 = 0x01;
  for (int i = 0; i < 8; i++) {
    digitalWrite(latchPin, LOW);
    shiftOut(SdataPin, SclockPin, LSBFIRST, ~0x00);
    shiftOut(dataPin, clockPin, LSBFIRST, ~0x00);      //For the last 8 leds
    shiftOut(dataPin, clockPin, LSBFIRST, ~d1);     //For the first 8 leds
    digitalWrite(latchPin, HIGH);
    delay(t);
    d1 = d1 << 1;
  }
  for (int i = 0; i < 8; i++) {
    digitalWrite(latchPin, LOW);
    shiftOut(SdataPin, SclockPin, LSBFIRST, ~0x00);
    shiftOut(dataPin, clockPin, LSBFIRST, ~0x00);      //For the last 8 leds
    shiftOut(dataPin, clockPin, LSBFIRST, ~d2);     //For the first 8 leds
    digitalWrite(latchPin, HIGH);
    delay(t);
    d2 = d2 >> 1;
  }
  d2 = 0x80;
  for (int i = 0; i < 8; i++) {
    digitalWrite(latchPin, LOW);
    shiftOut(SdataPin, SclockPin, LSBFIRST, ~0x00);
    shiftOut(dataPin, clockPin, LSBFIRST, ~d2);      //For the last 8 leds
    shiftOut(dataPin, clockPin, LSBFIRST, ~0x00);     //For the first 8 leds
    digitalWrite(latchPin, HIGH);
    delay(t);
    d2 = d2 >> 1;
  }
  for (int i = 0; i < 16; i++) {
    digitalWrite(latchPin, LOW);
    shiftOut(SdataPin, SclockPin, LSBFIRST, 0x00);
    shiftOut(dataPin, clockPin, LSBFIRST, ~0x00);      //For the last 8 leds
    shiftOut(dataPin, clockPin, LSBFIRST, ~0x00);     //For the first 8 leds
    digitalWrite(latchPin, HIGH);
    delay(t);
  }
}

