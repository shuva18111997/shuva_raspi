void BLE_CTRL(String state)
{
  if (state == "ON")
  {
    Data |= B00000001;
    digitalWrite(LCD_latch, 0);
    delay(10);
    shiftOut(data, Clock, MSBFIRST, Data);
    digitalWrite(latch, HIGH);
    digitalWrite(latch, LOW);
  }
  else if (state == "OFF")
  {
    Data &= ~B00000001;
    digitalWrite(LCD_latch, 0);
    delay(10);
    shiftOut(data, Clock, MSBFIRST, Data);
    digitalWrite(latch, HIGH);
    digitalWrite(latch, LOW);
  }
}

void WiFi_CTRL(String state)
{
  if (state == "ON")
  {
    Data &= ~B00000010;
    digitalWrite(LCD_latch, 0);
    delay(10);
    shiftOut(data, Clock, MSBFIRST, Data);
    digitalWrite(latch, HIGH);
    digitalWrite(latch, LOW);
  }
  else if (state == "OFF")
  {
    Data |= B00000010;
    digitalWrite(LCD_latch, 0);
    delay(10);
    shiftOut(data, Clock, MSBFIRST, Data);
    digitalWrite(latch, HIGH);
    digitalWrite(latch, LOW);
  }
}

void IR_CTRL(String state)
{
  if (state == "ON")
  {
    Data &= ~B00000100;
    digitalWrite(LCD_latch, 0);
    delay(10);
    shiftOut(data, Clock, MSBFIRST, Data);
    digitalWrite(latch, HIGH);
    digitalWrite(latch, LOW);
  }
  else if (state == "OFF")
  {
    Data |= B00000100;
    digitalWrite(LCD_latch, 0);
    delay(10);
    shiftOut(data, Clock, MSBFIRST, Data);
    digitalWrite(latch, HIGH);
    digitalWrite(latch, LOW);
  }
}

void BUZZ_CTRL(String state)
{
  if (state == "ON")
  {
    Data |= B00001000;
    digitalWrite(LCD_latch, 0);
    delay(10);
    shiftOut(data, Clock, MSBFIRST, Data);
    digitalWrite(latch, HIGH);
    digitalWrite(latch, LOW);
  }
  else if (state == "OFF")
  {
    Data &= ~B00001000;
    digitalWrite(LCD_latch, 0);
    delay(10);
    shiftOut(data, Clock, MSBFIRST, Data);
    digitalWrite(latch, HIGH);
    digitalWrite(latch, LOW);
  }
}

void RF_CTRL(String state)
{
  if (state == "ON")
  {
    Data |= B00010000;
    digitalWrite(LCD_latch, 0);
    delay(10);
    shiftOut(data, Clock, MSBFIRST, Data);
    digitalWrite(latch, HIGH);
    digitalWrite(latch, LOW);
  }
  else if (state == "OFF")
  {
    Data &= ~B00010000;
    digitalWrite(LCD_latch, 0);
    delay(10);
    shiftOut(data, Clock, MSBFIRST, Data);
    digitalWrite(latch, HIGH);
    digitalWrite(latch, LOW);
  }
}

void LINE_FOLLOWER_CTRL(String state)
{
  if (state == "ON")
  {
    Data |= B00100000;
    digitalWrite(LCD_latch, 0);
    delay(10);
    shiftOut(data, Clock, MSBFIRST, Data);
    digitalWrite(latch, HIGH);
    digitalWrite(latch, LOW);
  }
  else if (state == "OFF")
  {
    Data &= ~B00100000;
    digitalWrite(LCD_latch, 0);
    delay(10);
    shiftOut(data, Clock, MSBFIRST, Data);
    digitalWrite(latch, HIGH);
    digitalWrite(latch, LOW);
  }
}

void ALL_CTRL(String state)
{
  if (state == "ON")
  {
    Data = B11111001;
    digitalWrite(LCD_latch, 0);
    delay(10);
    shiftOut(data, Clock, MSBFIRST, Data);
    digitalWrite(latch, HIGH);
    digitalWrite(latch, LOW);
  }
  else if (state == "OFF")
  {
    Data = ~B11111001;
    digitalWrite(LCD_latch, 0);
    delay(10);
    shiftOut(data, Clock, MSBFIRST, Data);
    digitalWrite(latch, HIGH);
    digitalWrite(latch, LOW);
  }
}
