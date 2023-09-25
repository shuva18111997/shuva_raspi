int Clock = PB13;
int latch = PB14;
int data = PB15;
int Data = B11110000;
void setup() {
  pinMode(Clock, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(data, OUTPUT);
  digitalWrite(latch, LOW);
  delay(10);
  shiftOut(data, Clock, MSBFIRST, Data);
  digitalWrite(latch, HIGH);
  delay(50);
}
void loop() {
  
}
