int data = 0xFF;
int  delayms=100;
int dataPin=2;
int clkPin=3;
void setup() {
pinMode(dataPin,OUTPUT);
pinMode(clkPin,OUTPUT);
delay(500);
}

void loop() {
shiftOut(dataPin,clkPin,MSBFIRST,data);
delay(delayms);
shiftOut(dataPin,clkPin,MSBFIRST,~data);
delay(delayms);
}
