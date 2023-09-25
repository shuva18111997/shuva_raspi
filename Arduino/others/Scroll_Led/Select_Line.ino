void Select(int line, int Data)
{
  byte data[8] = {
    B10000000,
    B01000000,
    B00100000,
    B00010000,
    B00001000,
    B00000100,
    B00000010,
    B00000001
  };

  if (line < 8)
  {
    digitalWrite(latchPin, LOW);
    shiftOut(SdataPin, SclockPin, LSBFIRST, Data);
    shiftOut(dataPin, clockPin, LSBFIRST, ~0x00);      //For the last 8 leds
    shiftOut(dataPin, clockPin, LSBFIRST, ~data[line]);     //For the first 8 leds
    digitalWrite(latchPin, HIGH);
  }
  if (line > 7 && line < 16)
  {
    line -= 8;
    digitalWrite(latchPin, LOW);
    shiftOut(SdataPin, SclockPin, LSBFIRST, Data);
    shiftOut(dataPin, clockPin, LSBFIRST, ~data[line]);      //For the last 8 leds
    shiftOut(dataPin, clockPin, LSBFIRST, ~0x00);     //For the first 8 leds
    digitalWrite(latchPin, HIGH);
  }
}
