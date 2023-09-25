//The program modified but taken from this link:- https://dronebotworkshop.com/eeprom-arduino/

/*
  64k bit flash  -- (64 x1024)/8 =  8192bytes  location (0x00 -> 0x1FFF)
  128k bit flash -- (128 x1024)/8 = 16384bytes  location (0x00 -> 0x3FFF)
  256k bit flash -- (256 x1024)/8 = 32768 bytes location (0x00 -> 0x7FFF)
  512k bit flash -- (512 x1024)/8 = 65536 bytes location (0x00 -> 0xFFFF)
*/

#include "Wire.h"

// EEPROM I2C Address
#define EEPROM_I2C_ADDRESS 0x50

#define EEPROM_max_location 0x1FFF    //For AT24C64

void setup()
{
  // Connect to I2C bus as master
  Wire.begin();

  // Setup Serial Monitor
  Serial.begin(9600);
  byte cnt = 0;
  for (int i = 0; i <= EEPROM_max_location; i++)
  {
    writeEEPROM(i, cnt++, EEPROM_I2C_ADDRESS);
  }

  // Print to Serial Monitor
  for (int i = 0; i <= EEPROM_max_location; i++)
  {
    Serial.print("ADDR = ");
    Serial.print(i);
    Serial.print("\t");
    Serial.println(readEEPROM(i, EEPROM_I2C_ADDRESS));
  }
}

void loop()
{

  // Nothing in loop

}

// Function to write to EEPROOM
void writeEEPROM(int address, byte val, int i2c_address)
{
  // Begin transmission to I2C EEPROM
  Wire.beginTransmission(i2c_address);

  // Send memory address as two 8-bit bytes
  Wire.write((int)(address >> 8));   // MSB
  Wire.write((int)(address & 0xFF)); // LSB

  // Send data to be stored
  Wire.write(val);

  // End the transmission
  Wire.endTransmission();

  // Add 5ms delay for EEPROM
  delay(5);
}

// Function to read from EEPROM
byte readEEPROM(int address, int i2c_address)
{
  // Define byte for received data
  byte rcvData = 0xFF;

  // Begin transmission to I2C EEPROM
  Wire.beginTransmission(i2c_address);

  // Send memory address as two 8-bit bytes
  Wire.write((int)(address >> 8));   // MSB
  Wire.write((int)(address & 0xFF)); // LSB

  // End the transmission
  Wire.endTransmission();

  // Request one byte of data at current memory address
  Wire.requestFrom(i2c_address, 1);

  // Read the data and assign to variable
  rcvData =  Wire.read();

  // Return the data as function output
  return rcvData;
}
