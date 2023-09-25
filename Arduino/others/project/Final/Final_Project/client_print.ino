void client_print(int roll)
{
  if (client.connect(host, 80))
  {
    client.print("GET http://192.168.0.100/att.php?roll=");
    client.print(String(roll));
    client.println(" HTTP/1.0");
    client.println("User-Agent: Arduino 1.0");
    client.println();
    client.stop();
    delay(1000);
  }
  else {
    lcd.clear();
    lcd.print("Server is");
    lcd.setCursor(0, 1);
    lcd.print("Disconnected.......");
    Serial.println("Server is Disconnected");
    client.stop();
    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Reconnect Please");
    lcd.setCursor(0, 1);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    while (1);
  }
}
