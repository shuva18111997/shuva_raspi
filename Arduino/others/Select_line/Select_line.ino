int clockPin = 13; //IC Pin 11, Yellow Jumper
int dataPin = 12; //IC Pin 14, Blue Jumper
int latchPin = 8; //IC Pin 12, Green Jumper


int SclockPin = 11; //IC Pin 11, Yellow Jumper
int SdataPin = 10; //IC Pin 14, Blue Jumper

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  pinMode(SclockPin, OUTPUT);
  pinMode(SdataPin, OUTPUT);
}

void loop()
{
  Select(15, 1);
  delay(500);
  Select(15, 0);
  delay(500);
  Select(0, 1);
  delay(500);
  Select(0, 0);
  delay(500);
  Select(5, 1);
  delay(500);
  Select(5, 0);
  delay(500);
  Select(9, 1);
  delay(500);
  Select(9, 0);
  delay(500);
}

void Select(int led, int state)
{
  byte data[8] = {
  B1,
  B10,
  B100,
  B1000,
  B10000,
  B100000,
  B1000000,
  B10000000
};

  if (led < 7)
  {
    if (state == 1)
    {
      digitalWrite(latchPin, LOW);
      shiftOut(SdataPin, SclockPin, LSBFIRST, B11111111);
      shiftOut(dataPin, clockPin, LSBFIRST, ~data[led]);      //For the last 8 leds
      shiftOut(dataPin, clockPin, LSBFIRST, ~0x00);     //For the first 8 leds
      digitalWrite(latchPin, HIGH);
    }
    else
    {
      digitalWrite(latchPin, LOW);
      shiftOut(SdataPin, SclockPin, LSBFIRST, B11111111);
      shiftOut(dataPin, clockPin, LSBFIRST, ~0x00);      //For the last 8 leds
      shiftOut(dataPin, clockPin, LSBFIRST, ~0x00);     //For the first 8 leds
      digitalWrite(latchPin, HIGH); 
    }
  }
  if (led > 7 && led < 16)
  { 
    led=map(led ,7 ,15 ,0 ,7);
    if (state == 1)
    {
      digitalWrite(latchPin, LOW);
      shiftOut(SdataPin, SclockPin, LSBFIRST, B11111111);
      shiftOut(dataPin, clockPin, LSBFIRST, ~0x00);      //For the last 8 leds
      shiftOut(dataPin, clockPin, LSBFIRST, ~data[led]);     //For the first 8 leds
      digitalWrite(latchPin, HIGH);
    }
    else
    {
      digitalWrite(latchPin, LOW);
      shiftOut(SdataPin, SclockPin, LSBFIRST, B11111111);
      shiftOut(dataPin, clockPin, LSBFIRST, ~0x00);      //For the last 8 leds
      shiftOut(dataPin, clockPin, LSBFIRST, ~0x00);     //For the first 8 leds
      digitalWrite(latchPin, HIGH);
    }
  }
}
