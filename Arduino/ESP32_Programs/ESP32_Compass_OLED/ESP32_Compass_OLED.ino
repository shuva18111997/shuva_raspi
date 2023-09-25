#include <QMC5883L.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

QMC5883L compass;

void setup()
{
  Wire.begin();

  compass.init();
  compass.setSamplingRate(50);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(20, 30);
  display.println("Calibrate Compass");

  display.display();
  delay(2000);
}

void loop()
{
  int heading = compass.readHeading();
  if (heading == 0) {
    /* Still calibrating, so measure but don't print */
  } else {
    display.clearDisplay();
    display.setTextSize(3);
    display.setCursor(50, 10);
    if (heading < 10)
      display.print("0");
    else if (heading >= 100)
      display.setCursor(40, 10);
    display.print(heading);
    display.setTextSize(2);
    display.setCursor(55, 40);
    if (((heading > 0) && (heading < 23)) || ((heading >= 338) && (heading <= 360)))
    {
      display.setCursor(60, 40);
      display.println("N");
    }
    else if ((heading >= 23) && (heading < 68))
      display.println("NE");
    else if ((heading >= 68) && (heading < 112))
    {
      display.setCursor(60, 40);
      display.println("E");
    }
    else if ((heading >= 112) && (heading < 157))
      display.println("SE");
    else if ((heading >= 157) && (heading < 202))
      display.println("S");
    else if ((heading >= 202) && (heading < 246))
      display.println("SW");
    else if ((heading >= 246) && (heading < 292))
      display.println("W");
    else if ((heading >= 292) && (heading < 338))
      display.println("NW");
    display.display();
    Serial.println(heading);
  }
  delay(250);
}
