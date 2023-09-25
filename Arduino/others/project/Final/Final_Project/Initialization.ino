void Initialisation()
{
  if (RTC.read(tm))
  {
    Serial.println("Time Module is OK");
    lcd.clear();
    lcd.print("Time Module: OK");
  }
  uint8_t version = nfc.getFirmwareVersion();
  if (version != 0x92)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("MRC522 NOT FOUND");
    //////////////////////////////////////////
    Serial.println("Check your connection");
    /////////////////////////////////////////
    while (1);
  }
  else
  {
    lcd.setCursor(0, 1);
    lcd.print("Firmware is 0x");
    lcd.setCursor(14, 1);
    lcd.print(version, HEX);
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("MFRC522 is OK.");
    lcd.print("         ");
    ////////////////////////////////////
    Serial.print("Found chip MFRC522 ");
    Serial.print("Firmware ver. 0x");
    Serial.println(version, HEX);
    delay(3000);
    lcd.clear();
    lcd.print("Wait For");
    lcd.setCursor(0, 1);
    lcd.print("connecting.......");
  }
  /////////////////////////////////////////////////////////////////////
  if (Ethernet.begin(mac) == 0)
  {
    Ethernet.begin(mac, ip);
  }
  if (client.connect(host, 80))
  {
    client.stop();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("connecting");
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    lcd.print(".");
    delay(500);
    digitalWrite(led, HIGH);
    lcd.print(".");
    delay(500);
    digitalWrite(led, LOW);
    lcd.print(".");
    delay(500);
    digitalWrite(led, HIGH);
    lcd.print(".");
    delay(500);
    digitalWrite(led, LOW);
    lcd.setCursor(0, 1);
    lcd.print("  System start");
    delay(1000);
    ///////////////////////////////////////////
    Serial.println("connecting...");
    Serial.println("System start");
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Not Connected!!!");
    lcd.setCursor(0, 1);
    lcd.print("Please Reconnect");
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    while (1);
  }
}

