#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <Adafruit_SSD1306.h>
#include "FS.h"

Adafruit_SSD1306 display(15);
ESP8266WebServer server(80);

#define addrUSER 0
#define addrPASS 20

const String APssid = "myWiFi";
const String APpassword = "12345678";

#define SDA 5
#define SCL 4

#define STATE_NORMAL 0
#define STATE_SHORT 1
#define STATE_LONG 2
volatile int  resultButton = 0;

#define led 2
#define btn D7
#define Holdbtn D3

bool state;
int page = 0;
int prog;
unsigned long preMillis;
unsigned long HoldBtnMillis;

String SSIDStr;
String PASSStr;

char ssid[10] = "shuva";
char pass[10] = "shuva@123";

void setup() {
  Serial.begin(115200);
  SPIFFS.begin();
  pinMode(led, OUTPUT);

  attachInterrupt(Holdbtn, Reset, RISING);
  pinMode(btn, INPUT_PULLUP);
  attachInterrupt(btn, checkButton, CHANGE);

  Wire.begin(SDA, SCL);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.clearDisplay();
  display.display();

  FlashRead();
  delay(100);
}

void loop() {
  while (prog == 1)
  {
    api_Thingspeak();
  }
  while (prog == 2)
  {
    display.clearDisplay();
    display.setCursor(0, 20);
    display.setTextSize(1);
    display.println("2nd program");
    display.display();
  }
}
