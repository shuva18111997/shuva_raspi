void RFID_Access()
{
  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if ( ! rfid.PICC_ReadCardSerial())
    return;
  card = ReadCard(rfid.uid.uidByte, rfid.uid.size);
  card.trim();
  if (mycard == card) {
    display.clearDisplay();
    display.setCursor(0, 10);
    display.println("Access Master card");
    display.display();
    door_open = !door_open;
    if (door_open)
    {
      servo.attach(16);
      servo.write(90);
      delay(250);
      servo.detach();
      Display("Door Open");
    }
    else
    {
      servo.attach(16);
      servo.write(0);
      delay(250);
      servo.detach();
      Display("Door Close");
    }
  }
  else if (key_chain == card) {
    display.clearDisplay();
    display.setCursor(0, 10);
    display.println("Access key_chain");
    display.display();
    door_open = !door_open;
    if (door_open)
    {
      servo.attach(16);
      servo.write(90);
      delay(250);
      servo.detach();
      Display("Door Open");
    }
    else
    {
      servo.attach(16);
      servo.write(0);
      delay(250);
      servo.detach();
      Display("Door Close");
    }
  }
  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
  card = "";
}
