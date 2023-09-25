#define DataPin 3
#define ClockPin 4

#define SecondDisplay 1
#define ThirdDisplay 0

/*float r1 = 98799.0;
  float r2 = 9870.0;
  float resistance = (r2 / (r1 + r2));  //0.09082627060155150042790492228694
  float temp = (4.74/1024.0); //0.00462890625*/
// Actual Reasult 0.5096439850873860182370820668693
#define Analog_Pin A1

#define _delay 8

int voltage;

byte Num_Aray[10] = {
  B00000010,  //0
  B10011110,  //1
  B00100100,  //2
  B00001100,  //3
  B11011000,  //4
  B01001000,  //5
  B01000000,  //6
  B00011110,  //7
  B00000000,  //8
  B00001000   //9
};

void setup() {
  pinMode(DataPin, OUTPUT);
  pinMode(ClockPin, OUTPUT);
  pinMode(SecondDisplay, OUTPUT);
  pinMode(ThirdDisplay, OUTPUT);
  digitalWrite(SecondDisplay, LOW);
  digitalWrite(ThirdDisplay, LOW);
}

void loop() {
  voltage = 0;
  for (byte i = 0; i < 20; i++)
  {
    voltage += ((analogRead(Analog_Pin) * 51) / 100); //some adjust here.
  }
  voltage = voltage / 20;
  ShowDisplay();
}

void ShowDisplay()
{
  shiftOut(DataPin, ClockPin, LSBFIRST, (Num_Aray[(voltage / 100)] | B00000001));
  delay(_delay);
  voltage = voltage % 100;
  shiftOut(DataPin, ClockPin, LSBFIRST, Num_Aray[(voltage / 10)]);
  digitalWrite(SecondDisplay, HIGH);
  delay(_delay);
  digitalWrite(SecondDisplay, LOW);
  shiftOut(DataPin, ClockPin, LSBFIRST, Num_Aray[(voltage % 10)]);
  digitalWrite(ThirdDisplay, HIGH);
  delay(_delay);
  digitalWrite(ThirdDisplay, LOW);
}
