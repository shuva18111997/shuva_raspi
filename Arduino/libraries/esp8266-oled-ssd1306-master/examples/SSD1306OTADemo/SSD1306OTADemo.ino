#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>

const char *ssid         = "[Your SSID]";
const char *password     = "[Your Password]";

#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`

//Vcc --> 5V
//GND  --> GND
//SCL --> GPIO_2
//SDA --> GPIO_0

#define SCL 2
#define SDA 0

SSD1306Wire  display(0x3c, SDA, SCL);

void setup() {
  WiFi.begin ( ssid, password );

  // Wait for connection
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 10 );
  }

  display.init();
  display.flipScreenVertically();
  display.setContrast(255);

  ArduinoOTA.begin();
  ArduinoOTA.onStart([]() {
    display.clear();
    display.setFont(ArialMT_Plain_10);
    display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
    display.drawString(display.getWidth()/2, display.getHeight()/2 - 10, "OTA Update");
    display.display();
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    display.drawProgressBar(4, 32, 120, 8, progress / (total / 100) );
    display.display();
  });

  ArduinoOTA.onEnd([]() {
    display.clear();
    display.setFont(ArialMT_Plain_10);
    display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
    display.drawString(display.getWidth()/2, display.getHeight()/2, "Restart");
    display.display();
  });

  // Align text vertical/horizontal center
  display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
  display.setFont(ArialMT_Plain_10);
  display.drawString(display.getWidth()/2, display.getHeight()/2, "Ready for OTA:\n" + WiFi.localIP().toString());
  display.display();
}

void loop() {
  ArduinoOTA.handle();
}
