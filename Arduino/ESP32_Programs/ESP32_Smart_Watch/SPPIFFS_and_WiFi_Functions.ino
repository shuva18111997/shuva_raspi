void SPIFFS_Initialisation()
{
  if (SPIFFS.exists("/config"))
  {
    File Readfile = SPIFFS.open("/config", "r");
    if (Readfile)
    {
      for (int i = 0; i < 4; i++)
      {
        SPIFFS_Str[i] = Readfile.readStringUntil('\n');
        SPIFFS_Str[i].remove(SPIFFS_Str[i].length() - 1);
      }
      Readfile.close();
    }
    else
    {
      Error();
    }
    if (SPIFFS_Str[0] == "" || SPIFFS_Str[1] == "" || SPIFFS_Str[2] == "" || SPIFFS_Str[3] == "")
    {
      Error();
    }
  }
  else
  {
    Error();
  }
}

void Error()
{
  SPIFFS_Str[0] = "Guest";
  SPIFFS_Str[1] = "guest@123";
  SPIFFS_Str[2] = "192.168.0.100";
  SPIFFS_Str[3] = "sensor.php";
}


/***********************************WiFi_Parameter************************************************/
void Start_Server()
{
  if (EEPROM_Settings[EEPROM_WiFi_Settings_Address] < 3)
  {
    server.on("/", HTTP_POST, [](AsyncWebServerRequest * request)
    {
      WiFi_SSID = request->arg("ssid");
      WiFi_PASS = "";
      datetime = "20";
      String temp = String(nowTime.year);
      if (temp.length() < 2)
        datetime += "0";
      datetime += temp + "-";
      temp = String(nowTime.month);
      if (temp.length() < 2)
        datetime += "0";
      datetime += temp + "-";
      temp = String(nowTime.day);
      if (temp.length() < 2)
        datetime += "0";
      datetime += temp + "T";
      temp = String(nowTime.hour);
      if (temp.length() < 2)
        datetime += "0";
      datetime += temp + ":";
      temp = String(nowTime.minute);
      if (temp.length() < 2)
        datetime += "0";
      datetime += temp;
      Serial.println(datetime);
      Serial.println(WiFi_SSID);
      HomePageInit();
      request->send(200, "text/html", HomePage);
    });

    server.on("/", [](AsyncWebServerRequest * request)
    {
      WiFi_SSID = SPIFFS_Str[0];
      WiFi_PASS = SPIFFS_Str[1];
      datetime = "20";
      String temp = String(nowTime.year);
      if (temp.length() < 2)
        datetime += "0";
      datetime += temp + "-";
      temp = String(nowTime.month);
      if (temp.length() < 2)
        datetime += "0";
      datetime += temp + "-";
      temp = String(nowTime.day);
      if (temp.length() < 2)
        datetime += "0";
      datetime += temp + "T";
      temp = String(nowTime.hour);
      if (temp.length() < 2)
        datetime += "0";
      datetime += temp + ":";
      temp = String(nowTime.minute);
      if (temp.length() < 2)
        datetime += "0";
      datetime += temp;
      Serial.println(datetime);
      HomePageInit();
      request->send(200, "text/html", HomePage);
    });

    server.on("/ChangeSettings", HTTP_POST, [](AsyncWebServerRequest * request)
    {
      HomePageInit();
      request->send(200, "text/html", UpdateSettingsPage);
      datetime = request->arg("datetime");
      Serial.println(datetime);
      date_set = (datetime.substring(8, 10)).toInt();
      month_set = (datetime.substring(5, 7)).toInt();
      year_set = (datetime.substring(2, 4)).toInt();
      hour_set = (datetime.substring(11, 13)).toInt();
      min_set = (datetime.substring(14, datetime.length())).toInt();
      int _d = (datetime.substring(8, 10)).toInt();
      int _m = (datetime.substring(5, 7)).toInt();
      int _y = (datetime.substring(0, 4)).toInt();
      weekday_set  = (_d += _m < 3 ? _y-- : _y - 2, 23 * _m / 9 + _d + 4 + _y / 4 - _y / 100 + _y / 400) % 7;
      datetime_lock = true;
      delay(10);
      if ((request->arg("ssid") != SPIFFS_Str[0]) || (request->arg("password") != SPIFFS_Str[1]) || (request->arg("host_name") != SPIFFS_Str[2]) || (request->arg("file_name") != SPIFFS_Str[3]))
      {
        if (SPIFFS.exists("/config"))
        {
          File Writefile = SPIFFS.open("/config", "w");
          if (Writefile)
          {
            Writefile.println(request->arg("ssid"));
            Writefile.println(request->arg("password"));
            Writefile.println(request->arg("host_name"));
            Writefile.println(request->arg("file_name"));
            Writefile.close();
          }
        }
        ESP_Restart = true;
        SPIFFS_Initialisation();
      }
      if (request->arg("WiFi_Mode") != Web_Vars[0])
      {
        if (request->arg("WiFi_Mode") == "AP_Mode")
        {
          EEPROM.write(EEPROM_WiFi_Settings_Address, 1);  //WiFi in AP mode.
          EEPROM.write(EEPROM_Weather_App_Address, 3);
          EEPROM.commit();
          EEPROM_Settings[EEPROM_WiFi_Settings_Address] = 1;
        }
        else if (request->arg("WiFi_Mode") == "STA_Mode")
        {
          EEPROM.write(EEPROM_WiFi_Settings_Address, 2);  //WiFi in STA mode.
          EEPROM.write(EEPROM_Weather_App_Address, 3);
          EEPROM.commit();
          EEPROM_Settings[EEPROM_WiFi_Settings_Address] = 2;
        }
        else if (request->arg("WiFi_Mode") == "OFF")
        {
          EEPROM.write(EEPROM_WiFi_Settings_Address, 3);  //WiFi OFF.
          EEPROM.commit();
          EEPROM_Settings[EEPROM_WiFi_Settings_Address] = 3;
        }
        ESP_Restart = true;
      }
      if (request->arg("Data_Share") != Web_Vars[1])
      {
        if (request->arg("Data_Share") == "Web_Share")
        {
          EEPROM.write(EEPROM_Weather_App_Address, 1);
          EEPROM.write(EEPROM_WiFi_Settings_Address, 3);
          EEPROM.commit();
          EEPROM_Settings[EEPROM_Weather_App_Address] = 1;
        }
        else if (request->arg("Data_Share") == "Local_Share")
        {
          EEPROM.write(EEPROM_Weather_App_Address, 2);
          EEPROM.write(EEPROM_WiFi_Settings_Address, 3);
          EEPROM.commit();
          EEPROM_Settings[EEPROM_Weather_App_Address] = 2;
        }
        else if (request->arg("Data_Share") == "Sharing_OFF")
        {
          EEPROM.write(EEPROM_Weather_App_Address, 3);
          EEPROM.commit();
          EEPROM_Settings[EEPROM_Weather_App_Address] = 3;
        }
        ESP_Restart = true;
      }
      if (request->arg("Heart_Beat") != Web_Vars[2])
      {
        if (request->arg("Heart_Beat") == "EN")
        {
          EEPROM.write(EEPROM_HEARTBEAT_Address, 1);
          EEPROM.commit();
          EEPROM_Settings[EEPROM_HEARTBEAT_Address] = 1;
        }
        else if (request->arg("Heart_Beat") == "DIS")
        {
          EEPROM.write(EEPROM_HEARTBEAT_Address, 2);
          EEPROM.commit();
          EEPROM_Settings[EEPROM_HEARTBEAT_Address] = 2;
        }
        ESP_Restart = true;
      }
      if (request->arg("Compass") != Web_Vars[3])
      {
        if (request->arg("Compass") == "EN")
        {
          EEPROM.write(EEPROM_Compass_Address, 1);
          EEPROM.commit();
          EEPROM_Settings[EEPROM_Compass_Address] = 1;
        }
        else if (request->arg("Compass") == "DIS")
        {
          EEPROM.write(EEPROM_Compass_Address, 2);
          EEPROM.commit();
          EEPROM_Settings[EEPROM_Compass_Address] = 2;
        }
        ESP_Restart = true;
      }
    });
    server.on("/search", HTTP_GET, [](AsyncWebServerRequest * request)
    {
      WiFi_Search();
      request->send(200, "text/html", WiFiSearchPage);
    });
    server.onNotFound(notFound);
    server.begin();
  }
  if (EEPROM_Settings[EEPROM_Weather_App_Address] == 2)
  {
    server.on("/", [](AsyncWebServerRequest * request)
    {
      HomePageInit();
      request->send(200, "text/html", HomePage);
    });
    ///////////////////////////////////////////////////
    server.on("/pictures_weather", HTTP_GET, [](AsyncWebServerRequest * request) {
      request->send(SPIFFS, "/weather.jpg", "image/jpeg");
    });
    server.on("/pictures_temp", HTTP_GET, [](AsyncWebServerRequest * request) {
      request->send(SPIFFS, "/temp.jpeg", "image/jpeg");
    });
    server.on("/pictures_hum", HTTP_GET, [](AsyncWebServerRequest * request) {
      request->send(SPIFFS, "/hum.jpeg", "image/jpeg");
    });
    server.on("/pictures_pre", HTTP_GET, [](AsyncWebServerRequest * request) {
      request->send(SPIFFS, "/pre.png", "image/png");
    });
    ///////////////////////////////////////////////////
    server.on("/request", HTTP_GET, [](AsyncWebServerRequest * request)
    {
      String Data_Request = "{\"temp\":\"" + (String)BMETemp + "\",\"hum\":\"" + (String)BMEHum + "\",\"pre\":\"" + (String)BMEPre + "\"}";
      /**************************************
        {"temp":"20","hum":"66","pre":"101763"}
        String Data_Request = "{\"temp\":\"20\",\"hum\":\"66\",\"pre\":\"101763\"}";
      ***************************************/
      request->send(200, "text/plain", Data_Request);
    });
    server.onNotFound(notFound);
    server.begin();
  }
}

void notFound(AsyncWebServerRequest *request)
{
  request->send(404, "text/html", PageNotFound);
}

void Core0_Show_LCD()
{
  if (Core0_LCD == New_Client_Connected)
  {
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 30);
    tft.setTextSize(2);
    tft.setTextColor(TFT_BLUE);
    tft.println("--------------------");
    tft.println("New Client Connected");
    tft.println("--------------------\n");
    tft.setTextColor(TFT_GREEN);
    tft.print("URL: ");
    tft.setTextColor(TFT_RED);
    tft.println(WiFi.softAPIP());
    tft.setTextColor(TFT_BLUE);
    tft.println("\n         OR");
    tft.setTextColor(TFT_GREEN);
    tft.print("\nHTTP://");
    tft.println("ESP.local");
    tft.fillRect(100, 200, 40, 20, tft.color565(0, 102, 255));
    tft.setCursor(109, 202);
    tft.setTextColor(TFT_WHITE);
    tft.print("OK");
  }
  else if (Core0_LCD == Client_Disconnected)
  {
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 30);
    tft.setTextSize(2);
    tft.setTextColor(TFT_BLUE);
    tft.println("--------------------");
    tft.println("Client  Disconnected");
    tft.println("--------------------\n");
    tft.setTextColor(TFT_RED);
    tft.println("    Reconnect to");
    tft.setCursor(0, 150);
    tft.setTextColor(TFT_BLUE);
    tft.print("     SSID: ");
    tft.setTextColor(TFT_GREEN);
    tft.println(WiFi_AP_SSID);
    tft.setTextColor(TFT_BLUE);
    tft.print("    PASS: ");
    tft.setTextColor(TFT_GREEN);
    tft.println(WiFi_AP_Password);
    tft.fillRect(100, 200, 40, 20, tft.color565(0, 102, 255));
    tft.setCursor(109, 202);
    tft.setTextColor(TFT_WHITE);
    tft.print("OK");
  }
  else if (Core0_LCD == Connected_to_AP)
  {
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 30);
    tft.setTextSize(2);
    tft.setTextColor(TFT_BLUE);
    tft.println("--------------------");
    tft.println("   Connected to AP");
    tft.println("--------------------\n");
    if (EEPROM_Settings[EEPROM_WiFi_Settings_Address] == 2)
    {
      tft.setTextColor(TFT_GREEN);
      tft.print("URL: ");
      tft.setTextColor(TFT_RED);
      tft.println(WiFi.localIP());
      tft.setTextColor(TFT_BLUE);
      tft.println("\n         OR");
      tft.setTextColor(TFT_GREEN);
      tft.print("\nHTTP://");
      tft.println("ESP.local");
    }
    else if (EEPROM_Settings[EEPROM_Weather_App_Address] == 1)
    {
      tft.setTextColor(TFT_BLUE);
      tft.println("Sending Data to the");
      tft.println("--------------------");
      tft.setTextSize(1);
      tft.print("URL: ");
      tft.setTextColor(TFT_GREEN);
      tft.println(SPIFFS_Str[2]);
      tft.setTextSize(2);
      tft.setTextColor(TFT_BLUE);
      tft.println("--------------------");
    }
    tft.fillRect(100, 200, 40, 20, tft.color565(0, 102, 255));
    tft.setCursor(109, 202);
    tft.setTextColor(TFT_WHITE);
    tft.print("OK");
  }
  else if (Core0_LCD == Disonnected_from_AP)
  {
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 30);
    tft.setTextSize(2);
    tft.setTextColor(TFT_BLUE);
    tft.println("--------------------");
    tft.println("  AP Disconnected");
    tft.println("--------------------\n");
    tft.setTextColor(TFT_RED);
    tft.println("    Reconnect to");
    tft.setCursor(0, 150);
    int ssid_length = SPIFFS_Str[0].length() + 6;
    if (ssid_length <= 20)
    {
      ssid_length = (20 - ssid_length) / 2;
      for (int i = 0; i < ssid_length; i++)
        tft.print(" ");
    }
    tft.print("SSID: ");
    tft.setTextColor(TFT_GREEN);
    tft.println(ssid);
    tft.fillRect(100, 200, 40, 20, tft.color565(0, 102, 255));
    tft.setCursor(109, 202);
    tft.setTextColor(TFT_WHITE);
    tft.print("OK");
  }
  WiFi_Start_Millis = millis();
  while ((parameter == -1) && (millis() - WiFi_Start_Millis < 5000))
  {
    if (EEPROM_Settings[EEPROM_Weather_App_Address] < 3)
    {
      Read_BME280();
    }
    delay(1);
  }
}
