//This example shows a simple "Hello world!" on a VGA screen.
//You need to connect a VGA screen cable to the pins specified below.
//cc by-sa 4.0 license
//bitluni

#include <ESP32Lib.h>
#include <Ressources/Font6x8.h>

//pin configuration
const int redPin = 14;
const int greenPin = 19;
const int bluePin = 27;
const int hsyncPin = 32;
const int vsyncPin = 33;

//VGA Device
VGA3Bit vga;

void setup()
{
  //initializing vga at the specified pins
  vga.init(vga.MODE640x350, redPin, greenPin, bluePin, hsyncPin, vsyncPin);
  //selecting the font
  vga.setFont(Font6x8);
  //displaying the text
  //  vga.setTextColor(vga.RGB(255, 0, 0), vga.RGB(0, 0, 255));
  
  vga.setTextColor(vga.RGB(255, 0, 0));
  vga.println("Hello Shuva");
  delay(2000);
  vga.setTextColor(vga.RGB(0, 255, 0));
  vga.println("Hello Shuva");
  delay(2000);
  vga.setTextColor(vga.RGB(0, 0, 255));
  vga.println("Hello Shuva");
  delay(2000);
}

void loop()
{
}