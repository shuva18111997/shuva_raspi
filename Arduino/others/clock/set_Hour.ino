void setHour()
{
  
  lcd.setCursor(0,0);
  lcd.print("Set hour:       "); 
  myMenu[menuCounter] = counterVal;
  if(counterVal>12){
    counterVal=1;
  }
  if(counterVal==0){
    lcd.setCursor(7,1);
  lcd.print("12       ");
  }
 else if(counterVal>0)
  lcd.setCursor(7,1);
  lcd.print(myMenu[menuCounter]); lcd.print("    ");
}
