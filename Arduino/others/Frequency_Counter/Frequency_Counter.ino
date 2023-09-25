#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
int counterPin=8;
int count=0;
float Ht;
float Lt;
float Time;
float frequency;
void setup() {
lcd.begin(16,2);
Serial.begin(9600);
pinMode(counterPin,INPUT);
lcd.setCursor(0,0);
lcd.print("FREQUENCY");
lcd.setCursor(7,1);
lcd.print("COUNTER");
delay(2000);
lcd.clear();
}

void loop() {
Ht=pulseIn(counterPin,HIGH);
Lt=pulseIn(counterPin,LOW);
Time=Ht+Lt;
frequency=(1/Time)*1000000;
if(frequency>999){
  frequency=frequency/1000;
  Serial.print("frequency= ");
Serial.print(frequency);
Serial.println("KHz");
lcd.setCursor(0,0);
lcd.print("Frequency  ");
lcd.setCursor(3,1);
lcd.print(frequency);
lcd.setCursor(9,1);
lcd.print("KHz");
delay(250);
lcd.clear();
}
else if(frequency>999999){
  frequency=frequency/1000000;
  Serial.print("frequency= ");
Serial.print(frequency);
Serial.println("MHz");
lcd.setCursor(0,0);
lcd.print("Frequency  ");
lcd.setCursor(3,1);
lcd.print(frequency);
lcd.setCursor(9,1);
lcd.print("MHz");
delay(250);
lcd.clear();
}
else{
Serial.print("frequency= ");
Serial.print(frequency);
Serial.println("Hz");
lcd.setCursor(0,0);
lcd.print("Frequency  ");
lcd.setCursor(3,1);
lcd.print(frequency);
lcd.setCursor(9,1);
lcd.print("Hz");
delay(100);
lcd.clear();
}
 }
