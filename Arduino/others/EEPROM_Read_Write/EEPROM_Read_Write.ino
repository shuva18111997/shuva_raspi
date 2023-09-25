/*
//EEPROM Write Program  
#include<EEPROM.h>
void setup() {
  Serial.begin(9600);
  String s= "shuva";
  char c[5];
  s.toCharArray(c,6);
  //for(int i=0;i<5;i++)
  //{Serial.print("c[");Serial.print(i);Serial.print("]= ");Serial.print(c[i]);Serial.println();}
  for (int i = 0; i < sizeof(c); i++)
  {
    EEPROM.write(i, c[i]);
  }
}

void loop() {

}

*/
//EEPROM Read Program  
#include<EEPROM.h>
void setup() {
  char c;
  Serial.begin(9600);
  Serial.print("Value is ");
  for (int i = 0; i < 5; i++)
  {
    Serial.print((char)EEPROM.read(i));
  }
}

void loop() {

}

