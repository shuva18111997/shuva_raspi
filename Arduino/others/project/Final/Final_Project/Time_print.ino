void Time_print()
{
  RTC.read(tm);
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  ////////////////Hour////////////////////
  if (tm.Hour < 10)
  {
    lcd.setCursor(6, 0);
    lcd.print("0");
    lcd.print(tm.Hour);
  }
  else
  {
    lcd.setCursor(6, 0);
    lcd.print(tm.Hour);
  }
  //////////////////////////////////////////
  ////////////Minute///////////////////////
  lcd.print(":");
  if (tm.Minute < 10)
  {
    lcd.setCursor(9, 0);
    lcd.print("0");
    lcd.print(tm.Minute);
  }
  else
  {
    lcd.setCursor(9, 0);
    lcd.print(tm.Minute);
  }
  //////////////////////////////////////////
  //////////////Second/////////////////////
  lcd.print(":");
  if (tm.Second < 10)
  {
    lcd.setCursor(12, 0);
    lcd.print("0");
    lcd.print(tm.Second);
  }
  else
  {
    lcd.setCursor(12, 0);
    lcd.print(tm.Second);
  }
  //////////////////////////////////////////
  lcd.setCursor(0, 1);
  lcd.print("date: ");
  if (tm.Day < 10)
  {
    lcd.setCursor(6, 1);
    lcd.print("0");
    lcd.print(tm.Day);
  }
  else
  {
    lcd.setCursor(6, 1);
    lcd.print(tm.Day);
  }
  lcd.print("/");
  if (tm.Month < 10)
  {
    lcd.setCursor(9, 1);
    lcd.print("0");
    lcd.print(tm.Month);
  }
  else
  {
    lcd.setCursor(9, 1);
    lcd.print(tm.Month);
  }
}

