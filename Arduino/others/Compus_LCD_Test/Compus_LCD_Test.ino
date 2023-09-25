#include <QMC5883L.h>
#include<LiquidCrystal.h>

QMC5883L compass;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup()
{
  compass.init();
  compass.setSamplingRate(50);

  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.println("QMC5883L Compass Demo");
  Serial.println("Turn compass in all directions to calibrate....");
  lcd.home();
  lcd.print("Starting...");
  delay(1000);
  compass.resetCalibration();
}

void loop()
{
  int heading = compass.readHeading();
  if (heading == 0) {
    /* Still calibrating, so measure but don't print */
  } else {
    lcd.clear();
    lcd.home();
    lcd.print(heading);
    Serial.println(heading);
  }
}
