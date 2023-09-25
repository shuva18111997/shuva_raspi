void Check_Parameter_Change()
{
  if (parameter != preParameter)
  {
    if (parameter == CLOCK)
    {
      /*******Nothing Requered*******/
    }
    else if (parameter == Temp_and_Pre)
    {
      tft.fillScreen(TFT_BLACK);
      tft.drawLine(0, 120, 240, 120, TFT_WHITE);
      tft.pushImage(20, 140, 85, 85, PreImage);
      PreTempImg = 0;
    }
    else if (parameter == Hum)
    {
      timer.detach();
      tft.pushImage(0, 0, 240, 240, HumImg);
    }
    else if (parameter == Compass)
    {
      digitalWrite(Heart_beat_Indicator, HIGH);
      timer.detach();
      compass_change = true;
    }
    else if (parameter == Heart_beat)
    {
      tft.pushImage(0, 0, 240, 240, Heart_Beat_Img);
      tft.setCursor(0, 0);
      tft.setTextSize(2);
      tft.setTextColor(TFT_WHITE);
      tft.println("EXTENSION");
      timer.attach_ms(2, Show_Heart_Rate);
    }
    else if (parameter == Calender)
    {
      digitalWrite(Heart_beat_Indicator, HIGH);
      timer.detach();
      change_calender_parameter = 1;
    }
    else if (parameter == Settings)
    {
      tft.fillScreen(TFT_BLACK);
      tft.pushImage(60, 60, 120, 120, Settings_Img);
      Settings_Parameter = 1;
      In_Settings_Parameter = 1;
    }
    preParameter = parameter;
  }
}
