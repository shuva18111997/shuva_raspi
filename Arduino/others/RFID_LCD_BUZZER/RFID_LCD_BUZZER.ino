/* Simple RFID Arduino Sketch(RC522)
 
Created by Yvan / https://Brainy-Bits.com
This code is in the public domain...
You can: copy it, use it, modify it, share it or just plain ignore it!
Thx!
 
The MFRC522 Library used, was created by LJOS here: https://github.com/ljos/MFRC522 
The FastLED Library used, was created by focalintent here: https://github.com/FastLED/FastLED/releases
 
*/
 
#include <MFRC522.h>  // Include of the RC522 Library
#include "FastLED.h"  // Include of the FastLED library
#include <SPI.h>  // Used for communication via SPI with the Module
 
// WS2812 RGB Stick connection
#define led_pin 0  // Pin 5 connected to DIN of RGB Stick
#define NUM_LEDS 1  // # of WS2812 LEDs on stick
CRGB leds[NUM_LEDS];  // FastLED Library Init
 
#define SDAPIN 10  // RFID Module SDA Pin is connected to the UNO 10 Pin
#define RESETPIN 9 // RFID Module RST Pin is connected to the UNO 9 Pin
 
#define Buzzer 8  // Pin 8 connected to + pin of the Buzzer
 
byte FoundTag;  // Variable used to check if Tag was found
byte ReadTag;  // Variable used to store anti-collision value to read Tag information
byte TagData[MAX_LEN];  // Variable used to store Full Tag Data
byte TaglcdNumber[5];  // Variable used to store only Tag lcd Number
byte GoodTaglcdNumber[5] = {0xF9, 0x88, 0xB4, 0x0D};  //  The Tag lcd number we are looking for My card UID F9 88 B4 0D
 
MFRC522 nfc(SDAPIN, RESETPIN);  // Init of the library using the UNO pins declared above
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);   
void setup() {
  pinMode(Buzzer, OUTPUT);  // Set buzzer pin to an Output pin
  digitalWrite(Buzzer, LOW);  // Buzzer Off at startup
  SPI.begin();
  lcd.begin(16,2);
  Serial.begin (9600);
  FastLED.addLeds<NEOPIXEL,led_pin>(leds, NUM_LEDS);  // Setup FastLED Library
  FastLED.clear();
 
// Start to find an RFID Module
  
  Serial.print("Looking for RFID Reader");
  delay(1000);
  nfc.begin();
  byte version = nfc.getFirmwareVersion();  // Variable to store Firmware version of the Module
 
// If can't find an RFID Module  
  if (! version) {  
    lcd.setCursor(0,0);
    lcd.print("Didn't find RC522 board.");
    delay(100);
    while(1); //Wait until a RFID Module is found
  }
 
// If found, print the information about the RFID Module
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Found For TAG");
  delay(100);
  Serial.print("Firmware version: 0x");
  Serial.print(version, HEX);
  delay(1000);
}
 
void loop() {
  
  // Light up starting LED's
  for (int x = 0; x < 8; x++) {
    leds[x] = CRGB::Blue;
  }
  FastLED.setBrightness(50);
  FastLED.show();  
 
  String GoodTag="False";  // Variable used to confirm good Tag Detected
  
// Check to see if a Tag was detected
// If yes, then the variable FoundTag will contain "MI_OK"
  FoundTag = nfc.requestTag(MF1_REQIDL, TagData);
 
  if (FoundTag == MI_OK) {
    delay(200);
    
// Get anti-collision value to properly read information from the Tag
    ReadTag = nfc.antiCollision(TagData);
    memcpy(TaglcdNumber, TagData, 4);  // Write the Tag information in the TaglcdNumber variable
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tag detected");
    delay(500);
    Serial.print("Serial Number:  ");
    for (int i = 0; i < 4; i++) {  // Loop to print lcd number to lcd monitor
      Serial.print(TaglcdNumber[i], HEX);
      delay(100);
    }
    
   
 
// Check if detected Tag has the right lcd number we are looking for   
    for(int i=0; i < 4; i++){
      if (GoodTaglcdNumber[i] != TaglcdNumber[i]) {
        break;  // if not equal, then break out of the "for" loop
      }
      if (i == 3) {  // if we made it to 4 loops then the Tag lcd numbers are matching
       GoodTag="TRUE";
      } 
    }
    if (GoodTag == "TRUE"){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Success!!!!!!!");
      delay(100);
      for(int x = 0; x < 8; x++) {
        leds[x] = CRGB::Green;
      }
      FastLED.show();
        for (int y = 0; y < 3; y++){
          digitalWrite (Buzzer, HIGH) ;// Buzzer On
          delay (50) ;// Delay 1ms          
          digitalWrite (Buzzer, LOW) ;// Buzzer Off
          delay (50) ;// delay 1ms
      }
      delay(1500);
    }
    else {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("TAG NOT ACCEPTED");
      delay(1000);
       
      for(int x = 0; x < 8; x++) {
        leds[x] = CRGB::Red;
      }
      FastLED.show();
      for (int y = 0; y < 3; y++){
          digitalWrite (Buzzer, HIGH) ;// Buzzer On
          delay (300) ;// Delay 1ms          
          digitalWrite (Buzzer, LOW) ;// Buzzer Off
          delay (400) ;// delay 1ms
      }
      delay(500);  
       lcd.clear();
          lcd.setCursor(0,0);
      lcd.print("Enter Right TAG");
      delay(1000);  
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Found For TAG");
      delay(100);
      
    }
  }
}
