void UP_ISR()
{
  if (millis() - preMillis1 > 250)
  {
    if (parameter == CLOCK)
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
    }
    else if (parameter == Calender)
    {
      if (calender_settings)
      {
        change_calender_parameter = 2;
        if (Calender_cnt == 1)  //Date Increment
        {
          _date++;
          if ((_month == 1) || (_month == 3) || (_month == 5) || (_month == 7) || (_month == 8) || (_month == 10) || (_month == 12)) //last date 31
          {
            if (_date > 31)
            {
              _date = 1;
            }
          }
          else if (_month == 2) //If month is Feb
          {
            if (_year % 4 != 0) //If not Leap year
            {
              if (_date > 28)
              {
                _date = 1;
              }
            }
            else  //If Leap year
            {
              if (_date > 29)
              {
                _date = 1;
              }
            }
          }
          else
          {
            if (_date > 30)
            {
              _date = 1;
            }
          }
        }
        else if (Calender_cnt == 2) //Month Increment
        {
          _month++;
          if (_month > 12)
          {
            _month = 1;
          }
        }
        else if (Calender_cnt == 3) //Year Increment
        {
          _year++;
          if (_year > 99)
          {
            _year = 16;
          }
        }
        else if (Calender_cnt == 4) //Year Increment
        {
          _weekday++;
          if (_weekday > 6)
          {
            _weekday = 0;
          }
        }
      }
      else if ((change_calender_parameter == 3) && (!calender_settings))
      {
        Set_Calender_Yes = ! Set_Calender_Yes;
        calender_change_settings = false;
      }
    }
    else if (parameter == Compass)
    {
      compass_change = false;
    }
    else if (parameter == Settings)
    {
      if (Open_Settings == 1)
      {
        Settings_Hold = false;
        Settings_Parameter--;
        if (Settings_Parameter < 1)
          Settings_Parameter = 5;
      }
      else if (Open_Settings == 2)
      {
        Settings_Hold = false;
        In_Settings_Parameter--;
        if ((Settings_Parameter == 1) && (In_Settings_Parameter < 1))
          In_Settings_Parameter = 5;
        if ((Settings_Parameter == 2) && (In_Settings_Parameter < 1))
          In_Settings_Parameter = 5;
        if ((Settings_Parameter == 3) && (In_Settings_Parameter < 1))
          In_Settings_Parameter = 4;
        if ((Settings_Parameter == 4) && (In_Settings_Parameter < 1))
          In_Settings_Parameter = 4;
      }
    }
    if (change_Parameter)
    {
      if (parameter < Max_Parameter)
      {
        parameter++;
        if ((parameter == Compass) && (EEPROM_Settings[EEPROM_Compass_Address] == 2))
        {
          parameter++;
        }
        if ((parameter == Heart_beat) && (EEPROM_Settings[EEPROM_HEARTBEAT_Address] == 2))
        {
          parameter++;
        }
      }
    }
    preMillis1 = millis();
  }
}

void DOWN_ISR()
{
  if (millis() - preMillis2 > 250)
  {
    if (parameter == CLOCK)
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
    }
    else if (parameter == Calender)
    {
      if (calender_settings)
      {
        change_calender_parameter = 2;
        if (Calender_cnt == 1)  //Date Increment
        {
          _date--;
          if ((_month == 1) || (_month == 3) || (_month == 5) || (_month == 7) || (_month == 8) || (_month == 10) || (_month == 12)) //last date 31
          {
            if (_date < 1)
            {
              _date = 31;
            }
          }
          else if (_month == 2) //If month is Feb
          {
            if (_year % 4 != 0) //If not Leap year
            {
              if (_date < 1)
              {
                _date = 28;
              }
            }
            else  //If Leap year
            {
              if (_date < 1)
              {
                _date = 29;
              }
            }
          }
          else
          {
            if (_date < 1)
            {
              _date = 30;
            }
          }
        }
        else if (Calender_cnt == 2) //Month Increment
        {
          _month--;
          if (_month < 1)
          {
            _month = 12;
          }
        }
        else if (Calender_cnt == 3) //Year Increment
        {
          _year--;
          if (_year < 16)
          {
            _year = 99;
          }
        }

        else if (Calender_cnt == 4) //Year Increment
        {
          _weekday--;
          if (_weekday < 0)
          {
            _weekday = 6;
          }
        }
      }
      else if ((change_calender_parameter == 3) && (!calender_settings))
      {
        Set_Calender_Yes = ! Set_Calender_Yes;
        calender_change_settings = false;
      }
    }
    else if (parameter == Compass)
    {
      compass_change = false;
    }
    else if (parameter == Settings)
    {
      if (Open_Settings == 1)
      {
        Settings_Hold = false;
        Settings_Parameter++;
        if (Settings_Parameter > 5)
          Settings_Parameter = 1;
      }
      else if (Open_Settings == 2)
      {
        Settings_Hold = false;
        In_Settings_Parameter++;
        if ((Settings_Parameter == 1) && (In_Settings_Parameter > 5))
          In_Settings_Parameter = 1;
        if ((Settings_Parameter == 2) && (In_Settings_Parameter > 5))
          In_Settings_Parameter = 1;
        if ((Settings_Parameter == 3) && (In_Settings_Parameter > 4))
          In_Settings_Parameter = 1;
        if ((Settings_Parameter == 4) && (In_Settings_Parameter > 4))
          In_Settings_Parameter = 1;
      }
    }
    if (change_Parameter)
    {
      if (parameter > Min_Parameter)
      {
        parameter--;
        if ((parameter == Heart_beat) && (EEPROM_Settings[EEPROM_HEARTBEAT_Address] == 2))
        {
          parameter--;
        }
        if ((parameter == Compass) && (EEPROM_Settings[EEPROM_Compass_Address] == 2))
        {
          parameter--;
        }
      }
    }
    preMillis2 = millis();
  }
}

void Left_ISR()
{
  if (millis() - preMillis4 > 250)
  {
    if (parameter == Calender)
    {
      Calender_cnt--;
      if (Calender_cnt < 1)
        Calender_cnt = 4;
    }
    preMillis4 = millis();
  }
}

void Right_ISR()
{
  if (millis() - preMillis5 > 250)
  {
    if (parameter == Calender)
    {
      Calender_cnt++;
      if (Calender_cnt > 4)
        Calender_cnt = 1;
    }
    preMillis5 = millis();
  }
}

void HOME_ISR()
{
  if (millis() - preMillis3 > 250)
  {
    if (ESP_Restart)
    {
      ESP_Restart = false;
    }
    if (parameter == -1)
    {
      parameter = 0;
    }
    else if (parameter == WiFi_Access_Parameter)
    {
      parameter = CLOCK;
    }
    else if (parameter == CLOCK)
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
    }
    else if (parameter == Calender)
    {
      if (change_calender_parameter < 3)
      {
        if (change_calender_parameter == 0)
          change_calender_parameter = 1;
        calender_settings = ! calender_settings;
        Calender_cnt = 1;
      }
      else if (change_calender_parameter == 3)
      {
        change_calender_parameter = 4;
        calender_change_settings = false;
      }
    }
    else if (parameter == Settings)
    {
      if (Open_Settings == 1)
      {
        Settings_Hold = false;
        Open_Settings = 2;
      }
      else if (Open_Settings == 2 && (EEPROM_Settings[(Settings_Parameter - 1)] != In_Settings_Parameter))
      {
        Settings_Hold = false;
        Open_Settings = 3;
      }
      else if (Open_Settings == 0)
      {
        Open_Settings = 1;
      }
    }
    preMillis3 = millis();
  }
}
