/*HMC5883LRegisterScanner.pde
**A sketch that attempts to read every register from a slave device
**Written by Wayne Truchsess  http://dsscircuits.com
*/

#include "Wire.h"
#define I2C 0x0D  //write the address of I2C device.

byte x;

void setup(){
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Reading Registers Please Wait...");
  baselineRegisters();
  Serial.println("Read Complete");
}
void loop()
{
 delay(1000);
 return;
}
void baselineRegisters()
{
 for(int l = 0x00;l <= 0x8F;l++){
  Wire.beginTransmission(I2C);
  Wire.write(l);
  Wire.endTransmission();
  delay(100);
  Wire.requestFrom(I2C,1);
  x = Wire.read();
  Serial.print("Register Address ");
  Serial.print(l,HEX);
  Serial.print(" = ");
  Serial.print(x,HEX);
  Serial.print("     ");
  Serial.println();
 }
}
