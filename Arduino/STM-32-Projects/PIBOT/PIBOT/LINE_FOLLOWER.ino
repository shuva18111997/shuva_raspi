void LINE_FOLLOWER_Mode()
{
  Change_Mode = true;
  LINE_FOLLOWER_CTRL("ON");
  IR_CTRL("ON");
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Enjoy with");
  lcd.setCursor(1, 1);
  lcd.print("Line Follower");
  delay(2000);
  lcd.clear();
  while (1)
  {
    LineRead();
    lcd.setCursor(2, 0);
    for (int i = 7; i >= 0 ; i--)
      lcd.print(D[i]);
    delay(50);
    checkMode();
  }
}

void LineRead()
{
  for (int i = 0; i < 8; i++)
  {
    if (analogRead(D_bit[i]) >= 3200)
    {
      D[i] = true;
    }
    else
    {
      D[i] = false;
    }
  }
}
