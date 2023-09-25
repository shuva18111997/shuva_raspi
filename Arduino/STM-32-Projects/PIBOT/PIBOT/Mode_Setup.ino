//////////////////////Initial Mode Checking//////////////////////
void Init_mode_Check()
{
  if (EData == 0)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Choose Mode By");
    lcd.setCursor(0, 1);
    lcd.print("You Control");
    Change_Mode = false;
    delay(2000);
  }
  else if (EData == 1)
  {
    BLE_Mode();
  }
  else if (EData == 2)
  {
    WiFi_Mode();
  }
  else if (EData == 3)
  {
    NRF_Mode();
  }
  else if (EData == 4)
  {
    RF_Mode();
  }
  else if (EData == 5)
  {
    LINE_FOLLOWER_Mode();
  }
}
//////////////////////////Mode Setup////////////////////
void BLE_setup()
{
  lcd.clear();
  lcd.home();
  lcd.print("Bluetooth Mode");
  lcd.setCursor(0, 1);
  if (mode == 0)
  {
    BLE_EN = false;
    lcd.print("DISABLE");
  }
  else
  {
    BLE_EN = true;
    lcd.print("ENABLE");
  }
}
////////////////////////////////////////
void WiFi_setup()
{
  lcd.clear();
  lcd.home();
  lcd.print("WiFi Mode");
  lcd.setCursor(0, 1);
  if (mode == 0)
  {
    WiFi_EN = false;
    lcd.print("DISABLE");
  }
  else
  {
    WiFi_EN = true;
    lcd.print("ENABLE");
  }
}
////////////////////////////////////////
void NRF_setup()
{
  lcd.clear();
  lcd.home();
  lcd.print("NRF Mode");
  lcd.setCursor(0, 1);
  if (mode == 0)
  {
    NRF_EN = false;
    lcd.print("DISABLE");
  }
  else
  {
    NRF_EN = true;
    lcd.print("ENABLE");
  }
}
////////////////////////////////////////
void RF_setup()
{
  lcd.clear();
  lcd.home();
  lcd.print("RF Mode");
  lcd.setCursor(0, 1);
  if (mode == 0)
  {
    RF_EN = false;
    lcd.print("DISABLE");
  }
  else
  {
    RF_EN = true;
    lcd.print("ENABLE");
  }
}
////////////////////////////////////////
void LINE_FOLLOWER_setup()
{
  lcd.clear();
  lcd.home();
  lcd.print("LINE FOLLOWER");
  lcd.setCursor(0, 1);
  if (mode == 0)
  {
    LINE_FOLLOWER_EN = false;
    lcd.print("DISABLE");
  }
  else
  {
    LINE_FOLLOWER_EN = true;
    lcd.print("ENABLE");
  }
}
//////////////////////////Mode Change////////////////////
void BLE_CHANGE()
{
  if (BLE_EN)
  {
    EEPROM.write(Eaddr, 1);
    BLE_Mode();
  }
}
////////////////////////////////////////
void WiFi_CHANGE()
{
  if (WiFi_EN)
  {
    EEPROM.write(Eaddr, 2);
    WiFi_Mode();
  }
}
////////////////////////////////////////
void NRF_CHANGE()
{
  if (NRF_EN)
  {
    EEPROM.write(Eaddr, 3);
    NRF_Mode();
  }
}
////////////////////////////////////////
void RF_CHANGE()
{
  if (RF_EN)
  {
    EEPROM.write(Eaddr, 4);
    RF_Mode();
  }
}
////////////////////////////////////////
void LINE_FOLLOWER_CHANGE()
{
  if (LINE_FOLLOWER_EN)
  {
    EEPROM.write(Eaddr, 5);
    LINE_FOLLOWER_Mode();
  }
}
//////////////////////////Check Mode////////////////////
void checkMode()
{
  ////////////For Buzzer///////////
  if(cnt!=preCnt)
  {
    BUZZ_CTRL("ON");
    delay(40);
    BUZZ_CTRL("OFF");
    preCnt=cnt;
  }
  ///////////////////////////
  if (cnt >= 3)
  {
    Select_Mode = true;
  }
  while (Select_Mode)
  {
    lcd.clear();
    lcd.home();
    lcd.print("Mode Chnage??");
    lcd.setCursor(0, 1);
    if (UD_cnt)
    {
      lcd.print("YES");
    }
    else
    {
      lcd.print("NO");
    }
  if(UD_cnt!=preUD_cnt)
  {
    BUZZ_CTRL("ON");
    delay(40);
    BUZZ_CTRL("OFF");
    preUD_cnt=UD_cnt;
  }
    if (count == 10)
    {
      BUZZ_CTRL("ON");
      delay(40);
      BUZZ_CTRL("OFF");
      if (UD_cnt)
      {
        EEPROM.write(Eaddr, 0);
        nvic_sys_reset();  //RESET The controller.
      }
      else
      {
        Select_Mode = false;
        cnt = 0;
        btn1St = true, btn2St = true, btn3St = true, btn4St = true;
        UD_cnt = false;
        count = 0;
        lcd.clear();
      }
    }
    delay(100);
  }
}
//////////////////////////////////////////////////////
