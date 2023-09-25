#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  tft.begin();
  tft.setSwapBytes(true);
  tft.fillScreen(TFT_BLACK);
  
  tft.setCursor(0, 0);
  tft.setTextSize(1);
  tft.setTextColor(TFT_RED);
  tft.print("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcd");  //40 Characters.

  tft.setCursor(0, 15);
  tft.setTextSize(2);
  tft.setTextColor(TFT_YELLOW);
  tft.print("ABCDEFGHIJKLMNOPQRST");  //20 Characters.

  tft.setCursor(0, 35);
  tft.setTextSize(3);
  tft.setTextColor(TFT_BLUE);
  tft.print("ABCDEFGHIJKLM"); //13 Characters.

  tft.setCursor(0, 70);
  tft.setTextSize(4);
  tft.setTextColor(TFT_GREEN);  //10 Characters.
  tft.print("ABCDEFGHIJ");

  tft.setCursor(0, 130);
  tft.setTextSize(5);
  tft.setTextColor(TFT_PINK);
  tft.print("ABCDEFGH");  //8 Characters.
}

void loop() {
  // put your main code here, to run repeatedly:

}
