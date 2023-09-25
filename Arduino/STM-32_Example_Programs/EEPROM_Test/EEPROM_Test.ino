#include <EEPROM.h>
uint16_t addr = 0x50;
uint16_t data = 5125;
uint16_t Data;
void setup() {
  Serial.begin(9600);
  EEPROM.write(addr, data); //For Data Write.
  EEPROM.read(addr, &Data); //For Data Read.
  delay(2000);
  Serial.print("Data is ");
  Serial.println(Data);
}

void loop() {

}
