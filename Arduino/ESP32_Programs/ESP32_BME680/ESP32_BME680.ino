#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"
#include "Adafruit_GFX.h"
#include <Adafruit_SSD1306.h>

#define SEALEVELPRESSURE_HPA (1013.25)

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Adafruit_BME680 bme; // I2C

void setup() {
  Serial.begin(115200);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(1);

  Serial.println(F("BME680 async test"));

  if (!bme.begin()) {
    Serial.println(F("Could not find a valid BME680 sensor, check wiring!"));
    display.setCursor(0, 0);
    display.println("BME680 Not Connected");
    display.display();
    while (1);
  }

  // Set up oversampling and filter initialization
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); // 320*C for 150 ms
}

void loop() {
  // Tell BME680 to begin measurement.
  unsigned long endTime = bme.beginReading();
  if (endTime == 0) {
    Serial.println(F("Failed to begin reading :(")); display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Problem");
    display.display();
    return;
  }
  if (!bme.endReading()) {
    Serial.println(F("Failed to complete reading :("));
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Problem");
    display.display();
    return;
  }
  Serial.print(F("Temperature = "));
  Serial.print(bme.temperature);
  Serial.println(F(" *C"));

  Serial.print(F("Pressure = "));
  Serial.print(bme.pressure / 100.0);
  Serial.println(F(" hPa"));

  Serial.print(F("Humidity = "));
  Serial.print(bme.humidity);
  Serial.println(F(" %"));

  Serial.print(F("Gas = "));
  Serial.print(bme.gas_resistance / 1000.0);
  Serial.println(F(" KOhms"));

  Serial.print(F("Approx. Altitude = "));
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(F(" m"));

  Serial.println();

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print(F("Tem: "));
  display.print(bme.temperature);
  display.println(F(" *C"));
  
  display.setCursor(0, 12);
  display.print(F("Pre: "));
  display.print(bme.pressure / 100.0);
  display.println(F(" hPa"));
  
  display.setCursor(0, 24);
  display.print(F("Hum: "));
  display.print(bme.humidity);
  display.println(F(" %"));
  
  display.setCursor(0, 36);
  display.print(F("Gas: "));
  display.print(bme.gas_resistance / 1000.0);
  display.println(F(" KOhms"));
  
  display.setCursor(0, 48);
  display.print(F("Alt: "));
  display.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  display.println(F(" m"));
  display.display();

  delay(2000);
}
