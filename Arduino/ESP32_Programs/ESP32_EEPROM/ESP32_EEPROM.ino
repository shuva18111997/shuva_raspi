#include "EEPROM.h"
#define EEPROM_SIZE 512  //Highest Address of EEPROM From Flash
void setup() {
  Serial.begin(9600);
  if (!EEPROM.begin(EEPROM_SIZE))
  {
    Serial.println("failed to initialise EEPROM");
    while (1);
  }

  EEPROM.write(EEPROM_SIZE, 's');
  Serial.println("Address read --> " + (String)EEPROM.read(EEPROM_SIZE));
}

void loop() {

}
