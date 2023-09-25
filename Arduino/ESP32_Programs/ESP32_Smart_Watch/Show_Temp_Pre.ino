void Show_Temp_Pre()
{
  if ((WiFi.status() == WL_CONNECTED) && (EEPROM_Settings[EEPROM_Weather_App_Address] == 1))
  {
    if (Host_Connection_Status)
    {
      tft.setCursor(72, 0);
      tft.setTextSize(2);
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.print("online ");
      tft.fillCircle(170, 7 , 5, TFT_GREEN);
    }
    else
    {
      tft.setCursor(72, 0);
      tft.setTextSize(2);
      tft.setTextColor(TFT_RED, TFT_BLACK);
      tft.print("offline");
      tft.fillCircle(170, 7 , 5, TFT_RED);
    }
  }
  tft.setCursor(119, 45);
  tft.setTextSize(3);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  if (BMETemp < 15.00)
    TempImg = 1;
  else if (BMETemp >= 15.00 && BMETemp <= 25.00)
    TempImg = 2;
  else if (BMETemp > 25.00)
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
  tft.print(BMETemp);
  tft.setTextSize(2);
  tft.print("*C");
  tft.setCursor(115, 168);
  tft.setTextSize(3);
  tft.setTextColor(TFT_CYAN, TFT_BLACK);
  tft.print(BMEPre);
}

void Read_BME280()
{
  BMETemp = bme.readTemperature();
  BMEHum = bme.readHumidity();
  BMEPre = bme.readPressure();
}
