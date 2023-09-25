void Show_Settings()
{
  while (Open_Settings == 1)
  {
    change_Parameter = false;
    Settings_Hold = true;
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0);
    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE);
    tft.print("Settings");
    /*************************************************/
    tft.setCursor(0, 25);
    tft.setTextSize(3);
    if (Settings_Parameter == 1)
      tft.setTextColor(TFT_RED);
    else
      tft.setTextColor(TFT_BLUE);
    tft.println("1.WiFi");
    tft.setCursor(0, 65);
    if (Settings_Parameter == 2)
      tft.setTextColor(TFT_RED);
    else
      tft.setTextColor(TFT_BLUE);
    tft.println("2.Data Share");
    tft.setCursor(0, 105);
    if (Settings_Parameter == 3)
      tft.setTextColor(TFT_RED);
    else
      tft.setTextColor(TFT_BLUE);
    tft.println("3.Heart_Beat");
    tft.setCursor(0, 145);
    if (Settings_Parameter == 4)
      tft.setTextColor(TFT_RED);
    else
      tft.setTextColor(TFT_BLUE);
    tft.println("4.Compass");
    tft.setCursor(0, 185);
    if (Settings_Parameter == 5)
      tft.setTextColor(TFT_RED);
    else
      tft.setTextColor(TFT_BLUE);
    tft.println("5.Close");
    while (Settings_Hold)
    {
      if (EEPROM_Settings[EEPROM_Weather_App_Address] < 3)
      {
        Read_BME280();
      }
      delay(50);
    }
  }
  while (Open_Settings == 2)
  {
    Settings_Hold = true;
    if (Settings_Parameter == 1)
    {
      tft.fillScreen(TFT_BLACK);
      tft.setCursor(0, 0);
      tft.setTextSize(2);
      tft.setTextColor(TFT_WHITE);
      tft.print("WiFi Settings");

      tft.setCursor(0, 25);
      tft.setTextSize(3);
      if (EEPROM_Settings[EEPROM_WiFi_Settings_Address] == 1)
        tft.setTextColor(TFT_GREEN);
      else
      {
        if (In_Settings_Parameter == 1)
          tft.setTextColor(TFT_RED);
        else
          tft.setTextColor(TFT_BLUE);
      }
      tft.println("Access point");
      tft.setCursor(0, 65);
      if (EEPROM_Settings[EEPROM_WiFi_Settings_Address] == 2)
        tft.setTextColor(TFT_GREEN);
      else
      {
        if (In_Settings_Parameter == 2)
          tft.setTextColor(TFT_RED);
        else
          tft.setTextColor(TFT_BLUE);
      }
      tft.println("Station");
      tft.setCursor(0, 105);
      if (EEPROM_Settings[EEPROM_WiFi_Settings_Address] == 3)
        tft.setTextColor(TFT_GREEN);
      else
      {
        if (In_Settings_Parameter == 3)
          tft.setTextColor(TFT_RED);
        else
          tft.setTextColor(TFT_BLUE);
      }
      tft.println("OFF");
      tft.setCursor(0, 145);
      if (In_Settings_Parameter == 4)
        tft.setTextColor(TFT_RED);
      else
        tft.setTextColor(TFT_BLUE);
      tft.println("BACK");
      tft.setCursor(0, 185);
      if (In_Settings_Parameter == 5)
        tft.setTextColor(TFT_RED);
      else
        tft.setTextColor(TFT_BLUE);
      tft.println("EXIT");
    }
    else if (Settings_Parameter == 2)
    {
      tft.fillScreen(TFT_BLACK);
      tft.setCursor(0, 0);
      tft.setTextSize(2);
      tft.setTextColor(TFT_WHITE);
      tft.print("Data Share Settings");

      tft.setCursor(0, 25);
      tft.setTextSize(3);
      if (EEPROM_Settings[EEPROM_Weather_App_Address] == 1)
        tft.setTextColor(TFT_GREEN);
      else
      {
        if (In_Settings_Parameter == 1)
          tft.setTextColor(TFT_RED);
        else
          tft.setTextColor(TFT_BLUE);
      }
      tft.println("Web Share");
      tft.setCursor(0, 65);
      if (EEPROM_Settings[EEPROM_Weather_App_Address] == 2)
        tft.setTextColor(TFT_GREEN);
      else
      {
        if (In_Settings_Parameter == 2)
          tft.setTextColor(TFT_RED);
        else
          tft.setTextColor(TFT_BLUE);
      }
      tft.println("Local Share");
      tft.setCursor(0, 105);
      if (EEPROM_Settings[EEPROM_Weather_App_Address] == 3)
        tft.setTextColor(TFT_GREEN);
      else
      {
        if (In_Settings_Parameter == 3)
          tft.setTextColor(TFT_RED);
        else
          tft.setTextColor(TFT_BLUE);
      }
      tft.println("Sharing OFF");
      tft.setCursor(0, 145);
      if (In_Settings_Parameter == 4)
        tft.setTextColor(TFT_RED);
      else
        tft.setTextColor(TFT_BLUE);
      tft.println("BACK");
      tft.setCursor(0, 185);
      if (In_Settings_Parameter == 5)
        tft.setTextColor(TFT_RED);
      else
        tft.setTextColor(TFT_BLUE);
      tft.println("EXIT");
    }
    else if (Settings_Parameter == 3)
    {
      tft.fillScreen(TFT_BLACK);
      tft.setCursor(0, 0);
      tft.setTextSize(2);
      tft.setTextColor(TFT_WHITE);
      tft.print("Heart_Beat Settings");

      tft.setCursor(0, 25);
      tft.setTextSize(3);
      if (EEPROM_Settings[EEPROM_HEARTBEAT_Address] == 1)
        tft.setTextColor(TFT_GREEN);
      else
      {
        if (In_Settings_Parameter == 1)
          tft.setTextColor(TFT_RED);
        else
          tft.setTextColor(TFT_BLUE);
      }
      tft.println("ENABLE");
      tft.setCursor(0, 65);
      if (EEPROM_Settings[EEPROM_HEARTBEAT_Address] == 2)
        tft.setTextColor(TFT_GREEN);
      else
      {
        if (In_Settings_Parameter == 2)
          tft.setTextColor(TFT_RED);
        else
          tft.setTextColor(TFT_BLUE);
      }
      tft.println("DISABLE");
      tft.setCursor(0, 105);
      if (In_Settings_Parameter == 3)
        tft.setTextColor(TFT_RED);
      else
        tft.setTextColor(TFT_BLUE);
      tft.println("BACK");
      tft.setCursor(0, 145);
      if (In_Settings_Parameter == 4)
        tft.setTextColor(TFT_RED);
      else
        tft.setTextColor(TFT_BLUE);
      tft.println("EXIT");
    }
    else if (Settings_Parameter == 4)
    {
      tft.fillScreen(TFT_BLACK);
      tft.setCursor(0, 0);
      tft.setTextSize(2);
      tft.setTextColor(TFT_WHITE);
      tft.print("Compass Settings");

      tft.setCursor(0, 25);
      tft.setTextSize(3);
      if (EEPROM_Settings[EEPROM_Compass_Address] == 1)
        tft.setTextColor(TFT_GREEN);
      else
      {
        if (In_Settings_Parameter == 1)
          tft.setTextColor(TFT_RED);
        else
          tft.setTextColor(TFT_BLUE);
      }
      tft.println("ENABLE");
      tft.setCursor(0, 65);
      if (EEPROM_Settings[EEPROM_Compass_Address] == 2)
        tft.setTextColor(TFT_GREEN);
      else
      {
        if (In_Settings_Parameter == 2)
          tft.setTextColor(TFT_RED);
        else
          tft.setTextColor(TFT_BLUE);
      }
      tft.println("DISABLE");
      tft.setCursor(0, 105);
      if (In_Settings_Parameter == 3)
        tft.setTextColor(TFT_RED);
      else
        tft.setTextColor(TFT_BLUE);
      tft.println("BACK");
      tft.setCursor(0, 145);
      if (In_Settings_Parameter == 4)
        tft.setTextColor(TFT_RED);
      else
        tft.setTextColor(TFT_BLUE);
      tft.println("EXIT");
    }
    else if (Settings_Parameter == 5)
    {
      change_Parameter = true;
      Open_Settings = 0;
      tft.fillScreen(TFT_BLACK);
      tft.pushImage(60, 60, 120, 120, Settings_Img);
      Settings_Parameter = 1;
      In_Settings_Parameter = 1;
      Settings_Hold = false;
    }
    while (Settings_Hold)
    {
      if (EEPROM_Settings[EEPROM_Weather_App_Address] < 3)
      {
        Read_BME280();
      }
      delay(50);
    }
  }
  while (Open_Settings == 3)
  {
    if (Settings_Parameter == 1)
    {
      if (In_Settings_Parameter == 1)
      {
        EEPROM.write(EEPROM_WiFi_Settings_Address, 1);  //WiFi in AP mode.
        EEPROM.write(EEPROM_Weather_App_Address, 3);
        EEPROM.commit();
        delay(500);
        ESP.restart();
      }
      else if (In_Settings_Parameter == 2)
      {
        EEPROM.write(EEPROM_WiFi_Settings_Address, 2);  //WiFi in STA mode.
        EEPROM.write(EEPROM_Weather_App_Address, 3);
        EEPROM.commit();
        delay(500);
        ESP.restart();
      }
      else if (In_Settings_Parameter == 3)
      {
        EEPROM.write(EEPROM_WiFi_Settings_Address, 3);  //WiFi OFF.
        EEPROM.commit();
        delay(500);
        ESP.restart();
      }
      else if (In_Settings_Parameter == 4)
      {
        Open_Settings = 1;
        In_Settings_Parameter = 1;
      }
      else if (In_Settings_Parameter == 5)
      {
        change_Parameter = true;
        Open_Settings = 0;
        tft.fillScreen(TFT_BLACK);
        tft.pushImage(60, 60, 120, 120, Settings_Img);
        Settings_Parameter = 1;
        In_Settings_Parameter = 1;
      }
    }
    else if (Settings_Parameter == 2)
    {
      if (In_Settings_Parameter == 1)
      {
        EEPROM.write(EEPROM_Weather_App_Address, 1);
        EEPROM.write(EEPROM_WiFi_Settings_Address, 3);
        EEPROM.commit();
        delay(500);
        ESP.restart();
      }
      else if (In_Settings_Parameter == 2)
      {
        EEPROM.write(EEPROM_Weather_App_Address, 2);
        EEPROM.write(EEPROM_WiFi_Settings_Address, 3);
        EEPROM.commit();
        delay(500);
        ESP.restart();
      }
      else if (In_Settings_Parameter == 3)
      {
        EEPROM.write(EEPROM_Weather_App_Address, 3);
        EEPROM.commit();
        delay(500);
        ESP.restart();
      }
      else if (In_Settings_Parameter == 4)
      {
        Open_Settings = 1;
        In_Settings_Parameter = 1;
      }
      else if (In_Settings_Parameter == 5)
      {
        change_Parameter = true;
        Open_Settings = 0;
        tft.fillScreen(TFT_BLACK);
        tft.pushImage(60, 60, 120, 120, Settings_Img);
        Settings_Parameter = 1;
        In_Settings_Parameter = 1;
      }
    }
    if (Settings_Parameter == 3)
    {
      if (In_Settings_Parameter == 1)
      {
        EEPROM.write(EEPROM_HEARTBEAT_Address, 1);
        EEPROM.commit();
        delay(500);
        ESP.restart();
      }
      else if (In_Settings_Parameter == 2)
      {
        EEPROM.write(EEPROM_HEARTBEAT_Address, 2);
        EEPROM.commit();
        delay(500);
        ESP.restart();
      }
      else if (In_Settings_Parameter == 3)
      {
        Open_Settings = 1;
        In_Settings_Parameter = 1;
      }
      else if (In_Settings_Parameter == 4)
      {
        change_Parameter = true;
        Open_Settings = 0;
        tft.fillScreen(TFT_BLACK);
        tft.pushImage(60, 60, 120, 120, Settings_Img);
        Settings_Parameter = 1;
        In_Settings_Parameter = 1;
      }
    }
    if (Settings_Parameter == 4)
    {
      if (In_Settings_Parameter == 1)
      {
        EEPROM.write(EEPROM_Compass_Address, 1);
        EEPROM.commit();
        delay(500);
        ESP.restart();
      }
      else if (In_Settings_Parameter == 2)
      {
        EEPROM.write(EEPROM_Compass_Address, 2);
        EEPROM.commit();
        delay(500);
        ESP.restart();
      }
      else if (In_Settings_Parameter == 3)
      {
        Open_Settings = 1;
        In_Settings_Parameter = 1;
      }
      else if (In_Settings_Parameter == 4)
      {
        change_Parameter = true;
        Open_Settings = 0;
        tft.fillScreen(TFT_BLACK);
        tft.pushImage(60, 60, 120, 120, Settings_Img);
        Settings_Parameter = 1;
        In_Settings_Parameter = 1;
      }
    }
  }
}
