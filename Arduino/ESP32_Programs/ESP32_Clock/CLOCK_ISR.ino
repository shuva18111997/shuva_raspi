void UP_ISR()
{
  if (millis() - preMillis1 > 250)
  {
    if (Clock_Setting)
    {
      Change_Clock_Settings = 3;
      Check_Clock_Settings = false;
      Clock_min--;
      if (Clock_min == 255)
      {
        Clock_min = 59;
        Clock_hour--;
        if (Clock_hour == 255)
          Clock_hour = 23;
      }
    }
    else
    {
      if (Change_Clock_Settings > 1)
      {
        Check_Clock_Settings = false;
        Set_Clock_Yes = ! Set_Clock_Yes;
      }
    }
    preMillis1 = millis();
  }
}

void DOWN_ISR()
{
  if (millis() - preMillis2 > 250)
  {
    if (Clock_Setting)
    {
      Change_Clock_Settings = 3;
      Check_Clock_Settings = false;
      Clock_min++;
      if (Clock_min > 59)
      {
        Clock_min = 0;
        Clock_hour++;
        if (Clock_hour > 23)
          Clock_hour = 0;
      }
    }
    else
    {
      if (Change_Clock_Settings > 1)
      {
        Check_Clock_Settings = false;
        Set_Clock_Yes = ! Set_Clock_Yes;
      }
    }
    preMillis2 = millis();
  }
}

void HOME_ISR()
{
  if (millis() - preMillis3 > 250)
  {
    if (Change_Clock_Settings != 2)
      Clock_Setting = ! Clock_Setting;
    if (!Clock_Setting)
    {
      Change_Clock_Settings--;
      if (Change_Clock_Settings < 0)
        Change_Clock_Settings = 0;
    }
    Check_Clock_Settings = false;
    preMillis3 = millis();
  }
}
