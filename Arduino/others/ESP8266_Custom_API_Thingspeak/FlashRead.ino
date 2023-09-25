void FlashRead()
{
  if (SPIFFS.exists("/programFile"))
  {
    File Readfile = SPIFFS.open("/programFile", "r");
    if (Readfile)
    {
      prog = String(Readfile.readStringUntil('\n')).toInt();
    }
  }
  if (prog == 1)
  {
    if (SPIFFS.exists("/config"))
    {
      File Readfile = SPIFFS.open("/config", "r");
      if (Readfile)
      {
        SSIDStr = Readfile.readStringUntil('\n');
        PASSStr = Readfile.readStringUntil('\n');

        Readfile.close();
      }
    }

    if ((SSIDStr.length() > 1))
    {
      SSIDStr.toCharArray(ssid, SSIDStr.length());
      PASSStr.toCharArray(pass, PASSStr.length());

      WiFi.mode(WIFI_STA);
      WiFi.begin(ssid, pass);
      page = 1;
    }
    else
    {
      WiFi.mode(WIFI_AP);
      WiFi.softAP(APssid, APpassword);

      digitalWrite(led, LOW);
      display.setCursor(0, 30);
      display.print("AP Started");
      display.print("  " + APssid);
      display.display();

      server.on("/", serchWiFi);
      server.on("/SSID_Set", handleclient);
      server.on("/SettingChange", Updated);
      server.begin();
    }
  }
  /*else if(prog ==x)
    {
    InitCode();
    }*/
}

void ConnectingToAP()
{
  display.clearDisplay();
  display.setCursor(0, 30);
  display.print("Connectingto ");
  display.print(SSIDStr);
  display.display();

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    state = !state;
    digitalWrite(led, state);
    delay(500);
  }
  digitalWrite(led, LOW);

  display.clearDisplay();
  display.setCursor(0, 17);
  display.println("Connected");
  display.setTextSize(1);
  display.print(WiFi.localIP());
  display.setTextSize(2);
  display.display();
  delay(800);
}
