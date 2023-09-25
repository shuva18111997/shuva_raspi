#include "EEPROM.h"
#include "soc/sens_reg.h" //This Lib is for WiFi & ADC_Read conflict.
#include <PriUint64.h>
uint64_t reg_b;
#include <WiFi.h>
void setup() {
  Serial.begin(9600);
  reg_b = READ_PERI_REG(SENS_SAR_READ_CTRL2_REG);
  Serial.println(PriUint64<DEC>(reg_b));  //461058
  int sizeOf = sizeof(PriUint64<DEC>(reg_b));
  Serial.println(sizeOf);

  Serial.println("---------------------------------------------");

  WiFi.softAP("shuva", "12345678");
  reg_b = READ_PERI_REG(SENS_SAR_READ_CTRL2_REG);
  Serial.println(PriUint64<DEC>(reg_b));  //
  sizeOf = sizeof(PriUint64<DEC>(reg_b));
  Serial.println(sizeOf);
}

void loop() {
  // put your main code here, to run repeatedly:

}
