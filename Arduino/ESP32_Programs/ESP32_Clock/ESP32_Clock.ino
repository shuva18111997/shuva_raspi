#include <TFT_eSPI.h>
#include <SPI.h>
#include "Lib.h"
#include <PCF8563.h>

#define UpBtn 34
#define DownBtn 35
#define HomeBtn 27

unsigned long preMillis1, preMillis2, preMillis3;

bool state1, preState1, state2, preState2, state3, preState3;

PCF8563 pcf;
TFT_eSPI tft = TFT_eSPI();

uint8_t Clock_hour, Clock_min, Clock_sec;
bool Clock_Setting = false, Check_Clock_Settings = false, Set_Clock_Yes = true;
int Change_Clock_Settings;
void setup() {
  pinMode(UpBtn, INPUT_PULLUP);
  pinMode(DownBtn, INPUT_PULLUP);
  pinMode(HomeBtn, INPUT_PULLUP);
  attachInterrupt(UpBtn, UP_ISR, FALLING);
  attachInterrupt(DownBtn, DOWN_ISR, FALLING);
  attachInterrupt(HomeBtn, HOME_ISR, FALLING);
  pcf.init();
  tft.begin();
  tft.setSwapBytes(true);
}

void loop() {
  Clock_Show();
}
