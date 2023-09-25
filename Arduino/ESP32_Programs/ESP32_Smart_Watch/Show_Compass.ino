void Show_Compass()
{
  if (!Wire.requestFrom(QMC5883L_Address, 1, true))
  {
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0);
    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE);
    tft.println("EXTENSION");
    tft.setCursor(0, 80);
    tft.setTextSize(3);
    tft.setTextColor(TFT_RED);
    tft.println("    Please");
    tft.setTextColor(TFT_BLUE);
    tft.print(" Connect the ");
    tft.setTextColor(TFT_GREEN);
    tft.print("   Compass");
    Compass_one_time = true;
    while (!Wire.requestFrom(QMC5883L_Address, 1, true) && compass_change)
    {
      delay(10);
    }
  }
  else
  {
    if (Compass_one_time)
    {
      compass.init();
      compass.setSamplingRate(50);
      tft.pushImage(0, 0, 240, 240, Compass_Calibration);
      if (compass.ready())
      {
        heading = compass.readHeading();
      }
      preCompassMillis = millis();
      while ((millis() - preCompassMillis < Compass_Calibration_time) && compass_change)
      {
        delay(10);
      }
      Compass_one_time = false;
    }
    while (Wire.requestFrom(QMC5883L_Address, 1, true) && compass_change)
    {
      if (compass.ready())
      {
        heading = compass.readHeading();
        if (heading == 0)
        {
          tft.pushImage(0, 0, 240, 240, Compass_Calibration);
        }
        else if ((heading > 0) && ((heading > (preHeding + 2)) || (heading < (preHeding - 2))))
        {
          tft.pushImage(0, 0, 240, 240, Compass_Img);

          uint16_t X0 = 120 + cos((360 - heading) * 0.0174532925) * 50;
          uint16_t Y0 = 120 + sin((360 - heading) * 0.0174532925) * 50;

          uint16_t X1 = 120 + cos(((360 - heading) + 90) * 0.0174532925) * 8;
          uint16_t Y1 = 120 + sin(((360 - heading) + 90) * 0.0174532925) * 8;

          uint16_t X2 = 120 + cos(((360 - heading) - 90) * 0.0174532925) * 8;
          uint16_t Y2 = 120 + sin(((360 - heading) - 90) * 0.0174532925) * 8;

          tft.fillTriangle(X0, Y0, X1, Y1, X2, Y2, TFT_RED);

          X0 = 120 + cos(((360 - heading) + 180) * 0.0174532925) * 50;
          Y0 = 120 + sin(((360 - heading) + 180) * 0.0174532925) * 50;

          tft.fillTriangle(X0, Y0, X1, Y1, X2, Y2, TFT_BLUE);
          tft.fillCircle(120, 120, 8, TFT_WHITE);
          tft.fillCircle(120, 120, 3, TFT_BLACK);
          preHeding = heading;
        }
      }
      if (EEPROM_Settings[EEPROM_Weather_App_Address] < 3)
      {
        if (millis() - Read_BME280_Time > 2)
        {
          Read_BME280();
          Read_BME280_Time = millis();
        }
      }
    }
  }
}
