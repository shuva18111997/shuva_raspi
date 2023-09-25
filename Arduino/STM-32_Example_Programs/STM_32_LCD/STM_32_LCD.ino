#include<LiquidCrystal.h>
LiquidCrystal lcd(PA2, PA1, PA0, PC15, PC14, PC13);
void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("shuva");
  delay(500);
}

void loop() {
  
}
