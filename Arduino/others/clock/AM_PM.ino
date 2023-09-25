void setAM_PM(){
  lcd.setCursor(0,0);
  lcd.print("Set AM OR PM:     ");
  myMenu[menuCounter] = counterVal;
  if(counterVal>2){
    counterVal=0;
  }
  if(counterVal==0){
    lcd.setCursor(7,1);
  lcd.print("AM     ");
  }
  else if(counterVal==1){
    lcd.setCursor(7,1);
  lcd.print("PM     ");
  }
   }
