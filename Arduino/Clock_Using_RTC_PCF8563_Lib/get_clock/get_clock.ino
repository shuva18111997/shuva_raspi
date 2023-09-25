#include <Rtc_Pcf8563.h>

Rtc_Pcf8563 rtc;
void setup() {
  Serial.begin(9600);
}

void loop() {
  rtc.getDateTime();
  Serial.println("Time : "+(String)rtc.getHour()+":"+rtc.getMinute()+":"+rtc.getSecond());
  Serial.println("Date : "+(String)rtc.getDay()+"/"+(String)rtc.getMonth()+"/"+(String)rtc.getYear());
  delay(1000);
}