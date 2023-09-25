void Show_Calender()
{
  if (!calender_settings)
  {
    if ((change_calender_parameter == 2) && (_date != nowTime.day || _month != nowTime.month || _year != nowTime.year || _weekday != nowTime.weekday))
    {
      change_calender_parameter = 3;
      Set_Calender_Yes = true;
      while (change_calender_parameter == 3)
      {
        calender_change_settings = true;
        /****************POPUP**********************/
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
        if (Set_Calender_Yes)
        {
          tft.drawRect(55, 120, 40, 20, tft.color565(153, 153, 102));
          tft.drawRect(56, 121, 40, 20, tft.color565(153, 153, 102));
        }
        else
        {
          tft.drawRect(107, 120, 40, 20, tft.color565(153, 153, 102));
          tft.drawRect(108, 121, 40, 20, tft.color565(153, 153, 102));
        }
        /*******************************************/
        while (calender_change_settings)
        {
          delay(10);
        }
      }
      if ((change_calender_parameter == 4) && Set_Calender_Yes)
      {
        date_set = _date;
        month_set = _month;
        year_set = _year;
        hour_set = nowTime.hour;
        min_set = nowTime.minute;
        weekday_set = _weekday;
        datetime_lock = true;
        delay(10);
        tft.fillScreen(TFT_BLUE);
        tft.setCursor(30, 30);
        tft.setTextSize(3);
        tft.setTextColor(TFT_WHITE);
        tft.print("Date Saved");
        delay(2000);
      }
    }
    if (change_calender_parameter != 0 || _date != nowTime.day || _month != nowTime.month || _year != nowTime.year || _weekday != nowTime.weekday)
    {
      change_calender_parameter = 0;
      _date = nowTime.day;
      _weekday = nowTime.weekday;
      _month = nowTime.month;
      _year = nowTime.year;
      tft.pushImage(0, 0, 240, 240, CalenderImg);
      tft.setFreeFont(&FreeMonoBold9pt7b);
      tft.setCursor(85, 72);
      tft.setTextSize(2);
      tft.setTextColor(TFT_WHITE);
      tft.print(monthSet[nowTime.month - 1]);
      /**********************************/
      tft.setCursor(85, 175);
      tft.setTextSize(2);
      tft.setTextColor(TFT_BLUE);
      tft.print(daySet[nowTime.weekday]);
      /**********************************/
      tft.setCursor(160, 75);
      tft.setTextSize(1);
      tft.setTextColor(TFT_WHITE);
      tft.print("20");
      tft.print(nowTime.year);
      /**********************************/
      tft.setFreeFont();
      tft.setCursor(90, 100);
      tft.setTextSize(5);
      tft.setTextColor(TFT_RED);
      if (_date < 10)
        tft.print("0");
      tft.print(nowTime.day);
    }
    change_Parameter = true;
    delay(1000);
  }
  else
  {
    change_Parameter = false;
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(80, 0);
    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE);
    tft.print("Settings");
    while (calender_settings)
    {
      Calender_change_color = ! Calender_change_color;
      tft.setCursor(0, 110);
      tft.setTextSize(5);
      tft.setTextColor(TFT_YELLOW, TFT_BLACK);
      if (Calender_cnt == 1)
      {
        if (Calender_change_color)
          tft.setTextColor(0x39C4, TFT_BLACK);
        else
          tft.setTextColor(TFT_YELLOW, TFT_BLACK);
      }
      if (_date < 10)
        tft.print("0");
      tft.print(_date);
      tft.setTextColor(TFT_YELLOW, TFT_BLACK);
      tft.print("/");
      if (Calender_cnt == 2)
      {
        if (Calender_change_color)
          tft.setTextColor(0x39C4, TFT_BLACK);
        else
          tft.setTextColor(TFT_YELLOW, TFT_BLACK);
      }
      if (_month < 10)
        tft.print("0");
      tft.print(_month);
      tft.setTextColor(TFT_YELLOW, TFT_BLACK);
      tft.print("/");
      if (Calender_cnt == 3)
      {
        if (Calender_change_color)
          tft.setTextColor(0x39C4, TFT_BLACK);
        else
          tft.setTextColor(TFT_YELLOW, TFT_BLACK);
      }
      tft.print(_year);
      tft.setTextColor(TFT_YELLOW, TFT_BLACK);
      if (Calender_cnt == 4)
      {
        if (Calender_change_color)
          tft.setTextColor(0x39C4, TFT_BLACK);
        else
          tft.setTextColor(TFT_YELLOW, TFT_BLACK);
      }
      tft.setCursor(85, 160);
      tft.setTextSize(3);
      tft.print(daySet[_weekday]);
      delay(500);
    }
  }
}
