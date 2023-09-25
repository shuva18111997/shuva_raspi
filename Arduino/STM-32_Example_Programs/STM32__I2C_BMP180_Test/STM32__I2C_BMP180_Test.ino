#include <Wire.h>
#include <Adafruit_BMP085.h>
                                          //////////////////////////////////////////////////////////////////////
                                          // Connect VCC of the BMP085 sensor to 3.3V (NOT 5.0V!)             //
                                          // Connect GND to Ground                                            //
                                          // Connect SCL to i2c clock - on 'STM32':- PB6   ---->Default       //
                                          // Connect SDA to i2c data - on 'STM32':- PB7    ---->Default       //
                                          //////////////////////////////////////////////////////////////////////
          ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
          //But when the Library[#include <libmaple\i2c.h>] is use and the function[_i2c_handle_remap(I2C1,0x04);]                       //
          //is called then the port of i2c will be changed.Then ---------->                                                              //
          ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                          // Connect VCC of the BMP085 sensor to 3.3V (NOT 5.0V!)             //
                                          // Connect GND to Ground                                            //
                                          // Connect SCL to i2c clock - on 'STM32':- PB8                      //
                                          // Connect SDA to i2c data - on 'STM32':- PB9                       //
                                          //////////////////////////////////////////////////////////////////////
#include <libmaple\i2c.h>
                                          
Adafruit_BMP085 bmp;
  
void setup() {
  Serial.begin(9600);
_i2c_handle_remap(I2C1,0x04); //This function is use for change the i2c port.
  if (!bmp.begin()) {
	while (1) {Serial.println("Could not find a valid BMP085 sensor, check wiring!");}
  }
}
  
void loop() {
    Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    
    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    
    // Calculate altitude assuming 'standard' barometric
    // pressure of 1013.25 millibar = 101325 Pascal
    Serial.print("Altitude = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" meters");

    Serial.print("Pressure at sealevel (calculated) = ");
    Serial.print(bmp.readSealevelPressure());
    Serial.println(" Pa");

  // you can get a more precise measurement of altitude
  // if you know the current sea level pressure which will
  // vary with weather and such. If it is 1015 millibars
  // that is equal to 101500 Pascals.
    Serial.print("Real altitude = ");
    Serial.print(bmp.readAltitude(101500));
    Serial.println(" meters");
    
    Serial.println();
    delay(500);
}
