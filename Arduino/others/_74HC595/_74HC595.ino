int Clock=8;
int latch=9;
int data=10;
void setup() {
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
}
void loop() {
  for(int Data=0;Data<=255;Data++){
    pinMode(latch,LOW);
    delay(10);
    shiftOut(data,Clock,MSBFIRST,Data);
    pinMode(latch,HIGH);
    delay(50);
  }
}
