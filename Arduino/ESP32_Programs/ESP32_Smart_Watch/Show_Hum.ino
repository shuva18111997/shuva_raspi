void Show_Hum()
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
  tft.setCursor(28, 122);
  tft.setTextSize(3);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.print(BMEHum);
}
