#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`
#include "images.h"

//Vcc --> 5V
//GND  --> GND
//SCL --> GPIO_2
//SDA --> GPIO_0

#define SCL 2
#define SDA 0

SSD1306Wire  display(0x3c, SDA, SCL);

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();


  // Initialising the UI will init the display too.
  display.init();
  display2.init();

  // This will make sure that multiple instances of a display driver
  // running on different ports will work together transparently
  display.setI2cAutoInit(true);
  display2.setI2cAutoInit(true);

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);

  display2.flipScreenVertically();
  display2.setFont(ArialMT_Plain_10);
  display2.setTextAlignment(TEXT_ALIGN_LEFT);

}

void loop() {
  display.clear();
  display.drawString(0, 0, "Hello world: " + String(millis()));
  display.display();

  display2.clear();
  display2.drawString(0, 0, "Hello world: " + String(millis()));
  display2.display();

  delay(10);
}
