void Clock_Show()
{
  if (!Clock_Setting)
  {
    Time nowTime = pcf.getTime();
    Clock_hour = nowTime.hour;
    Clock_min = nowTime.minute;
    Clock_sec = nowTime.second;
    tft.pushImage(0, 0, 240, 240, clock_Img[0]);
    if (Clock_hour == 12)
      Clock_hour = 0;
    else if (Clock_hour > 12)
      Clock_hour -= 12;
    Clock_hour *= 5;
    Clock_hour += map(Clock_min, 0, 59, 0, 5);
    if (Clock_hour == 12)
      Clock_hour = 0;
    drawHour(Clock_hour, TFT_WHITE, TFT_DARKGREY);
    drawMinute(Clock_min, tft.color565(0, 64, 255), tft.color565(0, 38, 153));
    drawSec(Clock_sec, TFT_RED);
    tft.fillCircle(120, 120, 3, TFT_BLACK);
    delay(900);
  }
  /**********************************************************************************/
  else
  {
    Time nowTime = pcf.getTime();
    Clock_hour = nowTime.hour;
    Clock_min = nowTime.minute;
    Clock_sec = nowTime.second;
    while (Clock_Setting)
    {
      Check_Clock_Settings = true;
      uint8_t Setting_Hour = Clock_hour;
      tft.pushImage(0, 0, 240, 240, clock_Img[0]);
      if (Setting_Hour == 12)
        Setting_Hour = 0;
      else if (Setting_Hour > 12)
        Setting_Hour -= 12;
      Setting_Hour *= 5;
      Setting_Hour += map(Clock_min, 0, 59, 0, 5);
      if (Setting_Hour == 12)
        Setting_Hour = 0;
      drawHour(Setting_Hour, TFT_WHITE, TFT_DARKGREY);
      drawMinute(Clock_min, tft.color565(255, 255, 51), tft.color565(255, 255, 0));
      tft.fillCircle(120, 120, 3, TFT_BLACK);
      while (Check_Clock_Settings)
      {
        delay(10);
      }
      Set_Clock_Yes = true;
    }
    while (Change_Clock_Settings > 1)
    {
      Check_Clock_Settings = true;
      tft.fillRect(35, 87, 160, 65, TFT_WHITE);
      tft.fillRect(35, 87, 160, 5, TFT_BLUE);
      tft.setCursor(45, 97);
      tft.setTextSize(1);
      tft.setTextColor(TFT_RED);
      tft.print("Save Changes ?");
      tft.fillRect(57, 122, 40, 20, tft.color565(0, 102, 255));
      tft.setCursor(62, 127);
      tft.setTextSize(1);
      tft.setTextColor(TFT_WHITE);
      tft.print(" Yes");
      tft.fillRect(107, 122, 40, 20, tft.color565(0, 102, 255));
      tft.setCursor(112, 127);
      tft.setTextSize(1);
      tft.setTextColor(TFT_WHITE);
      tft.print("  No");
      if (Set_Clock_Yes)
      {
        tft.drawRect(55, 120, 40, 20, tft.color565(153, 153, 102));
        tft.drawRect(56, 121, 40, 20, tft.color565(153, 153, 102));
      }
      else
      {
        tft.drawRect(107, 120, 40, 20, tft.color565(153, 153, 102));
        tft.drawRect(108, 121, 40, 20, tft.color565(153, 153, 102));
      }
      while (Check_Clock_Settings)
      {
        delay(10);
      }
    }
    if ((Change_Clock_Settings == 1) && Set_Clock_Yes)
    {
      tft.pushImage(0, 0, 240, 240, clock_Img[0]);
      pcf.stopClock();
      ////////////////////////////////////
      pcf.setHour(Clock_hour);
      pcf.setMinut(Clock_min);
      pcf.setSecond(0);
      ///////////////////////////////////
      pcf.startClock();
      tft.setCursor(30, 30);
      tft.setTextSize(3);
      tft.setTextColor(TFT_WHITE);
      tft.print("Clock Saved");
      delay(2000);
    }
  }
}

void drawSec(int sec , uint16_t color)
{
  //Deg to Rad Convertion:
  // 1 Deg = 0.0174532925 rad
  // 1 Rad = 57.2958 deg
  // Deg * (pi / 180) = Rad

  uint16_t x0 = 120 + cos(((sec * 6) + 270) * 0.0174532925) * 85;
  uint16_t y0 = 120 + sin(((sec * 6) + 270) * 0.0174532925) * 85;

  uint16_t x1 = 120 + cos(((sec * 6) + (270 + 180)) * 0.0174532925) * 20;
  uint16_t y1 = 120 + sin(((sec * 6) + (270 + 180)) * 0.0174532925) * 20;

  tft.drawLine(x0, y0, x1, y1, color);
}

void drawMinute(int Min , uint16_t color1 , uint16_t color2)
{
  //Deg to Rad Convertion:
  // 1 Deg = 0.0174532925 rad
  // 1 Rad = 57.2958 deg
  // Deg * (pi / 180) = Rad

  uint16_t x0 = 120 + cos(((Min * 6) + 270) * 0.0174532925) * 70;
  uint16_t y0 = 120 + sin(((Min * 6) + 270) * 0.0174532925) * 70;

  uint16_t x1 = 120 + cos(((Min * 6) + (270 - 90)) * 0.0174532925) * 8;
  uint16_t y1 = 120 + sin(((Min * 6) + (270 - 90)) * 0.0174532925) * 8;

  uint16_t x2 = 120 + cos(((Min * 6) + (270 + 90)) * 0.0174532925) * 8;
  uint16_t y2 = 120 + sin(((Min * 6) + (270 + 90)) * 0.0174532925) * 8;

  uint16_t x3 = 120 + cos(((Min * 6) + (270 + 180)) * 0.0174532925) * 20;
  uint16_t y3 = 120 + sin(((Min * 6) + (270 + 180)) * 0.0174532925) * 20;

  //Upper
  tft.fillTriangle(x0, y0, 120, 120, x1, y1, color1);
  tft.fillTriangle(x0, y0, 120, 120, x2, y2, color2);
  tft.drawLine(x0, y0, x3, y3, color1);
  //Lower
  tft.fillTriangle(x3, y3, 120, 120, x1, y1, color1);
  tft.fillTriangle(x3, y3, 120, 120, x2, y2, color2);
}

void drawHour(int Hour , uint16_t color1 , uint16_t color2)
{
  //Deg to Rad Convertion:
  // 1 Deg = 0.0174532925 rad
  // 1 Rad = 57.2958 deg
  // Deg * (pi / 180) = Rad

  uint16_t x0 = 120 + cos(((Hour * 6) + 270) * 0.0174532925) * 55;
  uint16_t y0 = 120 + sin(((Hour * 6) + 270) * 0.0174532925) * 55;

  uint16_t x1 = 120 + cos(((Hour * 6) + (270 - 90)) * 0.0174532925) * 10;
  uint16_t y1 = 120 + sin(((Hour * 6) + (270 - 90)) * 0.0174532925) * 10;

  uint16_t x2 = 120 + cos(((Hour * 6) + (270 + 90)) * 0.0174532925) * 10;
  uint16_t y2 = 120 + sin(((Hour * 6) + (270 + 90)) * 0.0174532925) * 10;

  uint16_t x3 = 120 + cos(((Hour * 6) + (270 + 180)) * 0.0174532925) * 20;
  uint16_t y3 = 120 + sin(((Hour * 6) + (270 + 180)) * 0.0174532925) * 20;

  //Upper
  tft.fillTriangle(x0, y0, 120, 120, x1, y1, color1);
  tft.fillTriangle(x0, y0, 120, 120, x2, y2, color2);
  tft.drawLine(x0, y0, x3, y3, color1);
  //Lower
  tft.fillTriangle(x3, y3, 120, 120, x1, y1, color1);
  tft.fillTriangle(x3, y3, 120, 120, x2, y2, color2);
}
