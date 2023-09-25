#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(0);

#define SDA 4
#define SCL 5

void setup() {

  Wire.begin(SDA, SCL);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Hello World!");

  display.display();

  /*delay(2500);
    display.clearDisplay();
    display.display();*/
}

void loop() {
}
