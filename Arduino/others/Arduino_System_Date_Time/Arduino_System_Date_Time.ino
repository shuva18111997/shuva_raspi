#include<TimeLib.h>
void setup() {
  Serial.begin(9600);
  Serial.println("Time is "+(String)__TIME__);
  Serial.println("Date is "+(String)__DATE__);
}

void loop() {
  // put your main code here, to run repeatedly:

}
