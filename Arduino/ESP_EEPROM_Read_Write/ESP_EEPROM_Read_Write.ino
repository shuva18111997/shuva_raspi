//EEPROM Write Program
#include<EEPROM.h>
void setup() {
  String s= "shuva";
  char c[5];
  s.toCharArray(c,5);
  EEPROM.begin(512);
  for (int i = 0; i < 5; i++)
  {
    EEPROM.write(i, c[i]);
    EEPROM.commit();
  }
}

void loop() {

}

/*
  //EEPROM Read Program
  #include<EEPROM.h>
  void setup() {
  char c;
  EEPROM.begin(512);
  Serial.begin(9600);
  Serial.print("Value is ");
  for (int i = 0; i < 5; i++)
  {
    Serial.print((char)EEPROM.read(i));
  }
  }

  void loop() {

  }
*/
