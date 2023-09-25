void Init()
{
  //pinMode(Clock, OUTPUT);
  //pinMode(data, OUTPUT);
  pinMode(latch, OUTPUT);
  digitalWrite(LCD_latch, 0);

  ALL_CTRL("OFF");

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(btn4, INPUT_PULLUP);

  attachInterrupt(btn1, BtnUpCtrl, FALLING);
  attachInterrupt(btn2, BtnDownCtrl, FALLING);
  attachInterrupt(btn3, BtnLeftCtrl, FALLING);
  attachInterrupt(btn4, BtnRightCtrl, FALLING);

  //***Motor Pin Declaration***//
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  lcd.begin(16, 2);

  lcd.home();
  lcd.print("Hello I am PIBOT");
  lcd.setCursor(1, 1);
  lcd.print("Made by shuva");
  delay(2000);

  //*******Take EEPROM Data*******//
  EEPROM.read(Eaddr, &EData);
  if (EData != 5) //check if the mode is 'Line_Follower_mode'. Then it will not calibrate the compass.
  {
    Wire.begin();
    if (!Wire.requestFrom(QMC5883L_Address, 1, true))
    {
      lcd.clear();
      lcd.home();
      lcd.print("compass Not");
      lcd.setCursor(0,1);
      lcd.print("Found");
      while(!Wire.requestFrom(QMC5883L_Address, 1, true))
      {
        delay(10);
      }
    }
    compass.init();
    compass.setSamplingRate(50);

    //*******Compus Calibrate*******//
    lcd.clear();
    lcd.home();
    lcd.print("Compus Calibrate");

    BUZZ_CTRL("ON");
    Right_Own(120);
    delay(500);
    Stop();

    BUZZ_CTRL("OFF");
    delay(500);
    BUZZ_CTRL("ON");

    Left_Own(120);
    delay(500);
    BUZZ_CTRL("OFF");
    Stop();
  }
  delay(500);
  //******************************//
}
