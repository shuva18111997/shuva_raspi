void showWelcome(){
  lcd.setCursor(0,0);
  lcd.print("Hello shuva!");
  lcd.setCursor(0,1);
  lcd.print("Clock Ready");
  delay(2000);
  lcd.clear();
}
