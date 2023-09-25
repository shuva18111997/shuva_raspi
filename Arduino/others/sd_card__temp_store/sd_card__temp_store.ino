/*
  SD card read/write

 This example shows how to read and write data to and from an SD card file
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4

 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

#include <SPI.h>
#include <SD.h>
#include<math.h>
File myFile;
double ThermistorC(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;          
 return Temp;
}
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
}

void loop() {
  int valC;                
  double tempC; 
  valC=analogRead(0);      
  tempC=ThermistorC(valC);
 myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile) {
    Serial.print("temperature is: ");
    Serial.print(tempC);
    Serial.println("*C");
    myFile.print("temperature is: ");
    myFile.print(tempC);
    myFile.println("*C");
    myFile.close();
    delay(1000);
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}
