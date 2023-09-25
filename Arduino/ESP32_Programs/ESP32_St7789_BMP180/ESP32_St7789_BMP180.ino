#include <TFT_eSPI.h>
#include "Lib.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>

TFT_eSPI tft = TFT_eSPI();
Adafruit_BMP085 bmp;

int PreTempImg, TempImg;

void setup() {
  tft.begin();
  tft.setSwapBytes(true);
  tft.fillScreen(TFT_BLACK);

  if (!bmp.begin()) {
    tft.setCursor(2, 30);
    tft.setTextSize(2);
    tft.setTextColor(TFT_RED);
    tft.println("BMP Not Started");
    while (1) {
      delay(500);
    }
  }
  ImagePush();
}

void loop() {
  tft.setCursor(123, 45);
  tft.setTextSize(3);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  if (bmp.readTemperature() < 15.00)
    TempImg = 1;
  else if (bmp.readTemperature() >= 15.00 && bmp.readTemperature() <= 25.00)
    TempImg = 2;
  else if (bmp.readTemperature() > 25.00)
    TempImg = 3;
  if (TempImg != PreTempImg)
  {
    if (TempImg == 1)
      tft.pushImage(20, 17, 85, 85, TempCold);
    else if (TempImg == 2)
      tft.pushImage(20, 17, 85, 85, TempModarate);
    else if (TempImg == 3)
      tft.pushImage(20, 17, 85, 85, TempHot);
    PreTempImg = TempImg;
  }
  tft.print(bmp.readTemperature());
  tft.setCursor(115, 168);
  tft.setTextSize(3);
  tft.setTextColor(TFT_CYAN, TFT_BLACK);
  tft.print(bmp.readPressure());
  delay(50);
}

void ImagePush()
{
  tft.drawLine(0, 120, 240, 120, TFT_WHITE);
  tft.pushImage(20, 140, 85, 85, PreImage);
}
