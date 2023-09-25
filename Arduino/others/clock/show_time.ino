void showTime(){
  setTime();
  h=myMenu[0]+1;
  if(h==13){
    h=12;
  }
  m=myMenu[1];
while(1) {
  if(myMenu[2]==0){
    lcd.setCursor(14,0);
    lcd.print("AM");
  }
  else if(myMenu[2]==1){
    lcd.setCursor(14,0);
    lcd.print("PM");
  }
  for (; h <= 12; h++) {
    for (; m < 60; m++) {
      for (s = 0; s < 60; s++) {
        if (s < 10) {
          lcd.setCursor(11, 0);
          lcd.print("0");
          lcd.setCursor(12, 0);
          lcd.print(s);
          delay(1000);
        }
        else {
          lcd.setCursor(11, 0);
          lcd.print(s);
          delay(1000);
        }
      } if (m < 10) {
        lcd.setCursor(8, 0);
        lcd.print("0");
        lcd.setCursor(9, 0);
        lcd.print(m);
      }
      else {
        lcd.setCursor(8, 0);
        lcd.print(m);
      }
      if(m==59){
        m=0;
        break;
      }
    }
    if (h < 10) {
      lcd.setCursor(5, 0);
      lcd.print("0");
      lcd.setCursor(6, 0);
      lcd.print(h);
    }
    else {
      lcd.setCursor(5, 0);
      lcd.print(h);
    }
    if(h==12){
      h=1;
      break;
    }
  myMenu[2]=!myMenu[2];
  }
 }
}

