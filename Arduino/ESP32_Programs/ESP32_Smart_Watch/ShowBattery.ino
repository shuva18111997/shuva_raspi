void ShowBattery()
{
  // ADC2 control register restoring
  WRITE_PERI_REG(SENS_SAR_READ_CTRL2_REG, 461058);
  //VERY IMPORTANT: DO THIS TO NOT HAVE INVERTED VALUES!
  SET_PERI_REG_MASK(SENS_SAR_READ_CTRL2_REG, SENS_SAR2_DATA_INV);

  if (millis() - Battery_Millis > 500)
  {
    Batt_volt = (multipler * analogRead(Battery_voltage_measure_pin));
    if (Batt_volt < 2.80)
      Batt_volt = 2.80;
    Batt_Level = map((Batt_volt * 100), 280, 418, 2, 35);
    tft.drawRect(190, 5, 40, 20, TFT_WHITE);
    tft.fillRect(230, 10, 5, 10, TFT_WHITE);
    tft.fillRect(192, 7, 35, 16, TFT_BLACK);
    if (Batt_Level <= 5)
      tft.fillRect(192, 7, Batt_Level, 16, TFT_RED);
    else
      tft.fillRect(192, 7, Batt_Level, 16, TFT_GREEN);
    Battery_Millis = millis();
  }
}
