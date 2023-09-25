#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int h, m, s;
int btnSet=0;
int btnSel=1;
int counterVal=0;
int myMenu[4]; // 0=Hour, 1=Minutes, 2=AM_PM, 3=showTime
int menuCounter = 0;
void setup() {
  lcd.begin(16, 2);
  showWelcome();
  attachInterrupt(btnSet, increaseValue, RISING);
  attachInterrupt(btnSel, nextItem, RISING);
}
void loop() {
   if (menuCounter == 0)
  {
    setHour();
  }
  if (menuCounter == 1)
  {
    setMinute();
  }
  if (menuCounter == 2)
  {
    setAM_PM();
  }
  if (menuCounter == 3)
  {
    showTime();
  }
}

