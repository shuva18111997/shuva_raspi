#include <SPI.h>
#include <Ethernet.h>
#include <RFID.h>
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <MFRC522x.h>
#include <ShiftLCD.h>

#define SS_PIN 8
#define RST_PIN 9
#define led 2

RFID rfid(SS_PIN, RST_PIN);
MFRC522 nfc(SS_PIN, RST_PIN);

String card;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

const char* host = "192.168.0.100";

IPAddress ip(192, 168, 0, 170);

EthernetClient client;

tmElements_t tm;
int Time = 0;
int Date = 0;

int prev1 = 0;
int prev2 = 0;
int prev3 = 0;

String mycard1 = "249,136,180,13,";
String mycard2 = "136,4,123,226,";
String mycard3 = "136,4,142,189,";

ShiftLCD lcd(5, 7, 6);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  SPI.begin();
  rfid.init();
  nfc.begin();
  pinMode(led, OUTPUT);
  lcd.print("Auto Checking");
  digitalWrite(led, 1);
  delay(500);
  digitalWrite(led, 0);
  lcd.print(".");
  delay(500);
  digitalWrite(led, 1);
  lcd.print(".");
  delay(500);
  digitalWrite(led, 0);
  lcd.print(".");
  delay(500);
  digitalWrite(led, 1);
  lcd.print(".");
  delay(500);
  digitalWrite(led, 0);
  lcd.print(".");

  Initialisation();
  lcd.clear();
}

void loop() {
  Time_print();
  Time = (tm.Hour * 100) + tm.Minute;
  Date = tm.Day;

  if (Time >= 815 && Time <= 1255)      //open on 8:15 & close on 9:55
  {
    digitalWrite(led, LOW);
    if (rfid.isCard()) {

      if (rfid.readCardSerial()) {
        for (int i = 0; i < 4; i++)
        {
          card += rfid.serNum[i];
          card += ',';
        }
      }

      if (mycard1 == card && prev1 != Date) {
        lcd.setCursor(0, 0);
        lcd.print("ETCE:07,3rd year");
        lcd.setCursor(0, 1);
        lcd.print("Shuvabrata Dey");
        delay(500);
        Serial.println("Access card 1");
        Serial.print("card uid is ");
        Serial.println(card);
        client_print(7);
        prev1 = Date;
        delay(2000);
        lcd.clear();
      }
      if (mycard2 == card && prev2 != Date) {
        lcd.setCursor(0, 0);
        lcd.print("ETCE:08,3rd year");
        lcd.setCursor(0, 1);
        lcd.print("Koushik Bhadra");
        delay(500);
        Serial.println("Access card 2");
        Serial.print("card uid is ");
        Serial.println(card);
        client_print(8);
        prev2 = Date;
        delay(1000);
        lcd.clear();
      }
      if (mycard3 == card && prev3 != Date) {
        lcd.setCursor(0, 0);
        lcd.print("ETCE:09,3rd year");
        lcd.setCursor(0, 1);
        lcd.print("Kunal Mukherjee");
        delay(500);
        Serial.println("Access card 3");
        Serial.print("card uid is ");
        Serial.println(card);
        client_print(9);
        prev3 = Date;
        delay(1000);
        lcd.clear();
      }
      card = "\0";
    }
  }
  else
  {
    Serial.println("Time Expire");
    digitalWrite(led, HIGH);
  }
}
