void TaskCreate()
{
  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
    LOOP,   /* Task function. */
    "Task1",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    1,           /* priority of the task */
    &Task,      /* Task handle to keep track of created task */
    0);          /* pin task to core 0 */
}

void LOOP( void * pvParameters )
{
  while (1)
  {
    if ((EEPROM_Settings[EEPROM_WiFi_Settings_Address] == 1) || (EEPROM_Settings[EEPROM_Weather_App_Address] == 2))
    {
      if (WiFi_AP_Connected_Clients < WiFi.softAPgetStationNum())
      {
        Led_State = true;
        digitalWrite(Led, Led_State);
        Core0_LCD = New_Client_Connected;
        while (parameter != -1)
        {
          delay(1);
        }
        while (parameter == -1)
        {
          delay(1);
        }
        WiFi_AP_Connected_Clients = WiFi.softAPgetStationNum();
      }
      else if (WiFi_AP_Connected_Clients > WiFi.softAPgetStationNum())
      {
        Led_State = false;
        digitalWrite(Led, Led_State);
        Core0_LCD = Client_Disconnected;
        while (parameter != -1)
        {
          delay(1);
        }
        while (parameter == -1)
        {
          delay(1);
        }
        WiFi_AP_Connected_Clients = WiFi.softAPgetStationNum();
      }
      while (WiFi.softAPgetStationNum() == 0)
      {
        Led_State = !Led_State;
        digitalWrite(Led, Led_State);
        delay(500);
      }
    }
    else if ((EEPROM_Settings[EEPROM_WiFi_Settings_Address] == 2) || (EEPROM_Settings[EEPROM_Weather_App_Address] == 1))
    {
      if (WiFi.status() != WL_CONNECTED)
      {
        if (!WiFi_Connected_Skip)
        {
          Led_State = false;
          digitalWrite(Led, Led_State);
          Core0_LCD = Disonnected_from_AP;
          while (parameter != -1)
          {
            delay(1);
          }
          while (parameter == -1)
          {
            delay(1);
          }
          while ((WiFi.status() != WL_CONNECTED))
          {
            WiFi.reconnect();
            Led_State = !Led_State;
            digitalWrite(Led, Led_State);
            delay(500);
          }
        }
        else
        {
          WiFi_Connected_Skip = false;
          while ((WiFi.status() != WL_CONNECTED))
          {
            Led_State = !Led_State;
            digitalWrite(Led, Led_State);
            delay(500);
          }
          WiFi.setAutoReconnect(true);
          WiFi.persistent(true);
        }
        Led_State = true;
        digitalWrite(Led, Led_State);
        Core0_LCD = Connected_to_AP;
        while (parameter != -1)
        {
          delay(1);
        }
        while (parameter == -1)
        {
          delay(1);
        }
      }
      if ((WiFi.status() == WL_CONNECTED) && (EEPROM_Settings[EEPROM_Weather_App_Address] == 1))
      {
        lastUploadTime = millis();
        while (WiFi.status() == WL_CONNECTED)
        {
          if ((millis() - lastUploadTime) > timerDelay)
          {
            HTTPClient http;
            //http://sensorsproject.000webhostapp.com/sensor.php?Temp=35&Hum=20&Pre=101105
            http.begin("http://" + SPIFFS_Str[2] + "/" + SPIFFS_Str[3] + "?Temp=" + (String)BMETemp + "&Hum=" + (String)BMEHum + "&Pre=" + (String)BMEPre);
            if (http.GET() > 0)
            {
              Host_Connection_Status = true;
              Led_State = true;
              digitalWrite(Led, Led_State);
            }
            else
            {
              Host_Connection_Status = false;
              Led_State = false;
              digitalWrite(Led, Led_State);
            }
            http.end();
            lastUploadTime = millis();
          }
          delay(10);
        }
      }
    }
    delay(10);
  }
}
