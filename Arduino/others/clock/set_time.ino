void setTime()
{ if(myMenu[0]==0){
    myMenu[0]=12;
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time ");
  lcd.print("  ");
    if(myMenu[0]<10)
  {
    lcd.setCursor(5, 0);
    lcd.print("0");
    lcd.print(myMenu[0]);
  }
  else
  {
    lcd.setCursor(5, 0);
    lcd.print(myMenu[0]);
  } 
  lcd.print(":"); // hour
  if(myMenu[1]<10)
  {
    lcd.setCursor(8, 0);
    lcd.print("0");
    lcd.print(myMenu[1]);
  }
  else
  {
    lcd.setCursor(8, 0);
    lcd.print(myMenu[1]);
  } 
    lcd.print(":");
}

