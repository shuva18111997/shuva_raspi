int clockPin = 12; //IC Pin 11, Yellow Jumper
int dataPin = 11; //IC Pin 14, Blue Jumper
int latchPin = 8; //IC Pin 12, Green Jumper
char data=0x01;
void setup() {
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);
}

void loop() {
  for(int i=0;i<8;i++){
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, data);
digitalWrite(latchPin, HIGH);
delay(500);
data=data<<1;
  }
  data=0x80;
  for(int i=0;i<8;i++){
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, data);
digitalWrite(latchPin, HIGH);
delay(500);
data=data>>1;
  }
   data=0x01;
 }
