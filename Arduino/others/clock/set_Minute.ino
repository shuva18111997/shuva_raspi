void setMinute()
{
  lcd.setCursor(0,0);
  lcd.print("Set minute:     ");
  myMenu[menuCounter] = counterVal;
  if(counterVal>59){
    counterVal=0;
  }
    lcd.setCursor(7,1);
    lcd.print(myMenu[menuCounter]); lcd.print("  ");
}
