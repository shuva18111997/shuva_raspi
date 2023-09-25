void checkButton() {
  const unsigned long LONG_DELTA = 1000ul;
  const unsigned long DEBOUNCE_DELTA = 30ul;
  static int lastButtonStatus = HIGH;
  int buttonStatus;
  static unsigned long longTime = 0ul, shortTime = 0ul;
  boolean Released = true, Transition = false;
  boolean timeoutShort = false, timeoutLong = false;

  buttonStatus = digitalRead(btn);
  timeoutShort = (millis() > shortTime);
  timeoutLong = (millis() > longTime);

  if (buttonStatus != lastButtonStatus) {
    shortTime = millis() + DEBOUNCE_DELTA;
    longTime = millis() + LONG_DELTA;
  }

  Transition = (buttonStatus != lastButtonStatus);
  Released = (Transition && (buttonStatus == HIGH));

  lastButtonStatus = buttonStatus;

  if ( ! Transition) {
    resultButton =  STATE_NORMAL | resultButton;
    return;
  }

  if (timeoutLong && Released)
  {
    resultButton = STATE_LONG | resultButton;
  }
  else if (timeoutShort && Released)
  {
    resultButton = STATE_SHORT | resultButton;
  }
  else
  {
    resultButton = STATE_NORMAL | resultButton;
  }

  if (resultButton == STATE_SHORT)
  {
    if (millis() - preMillis > 250)
    {
      if (prog == 1)
      {
        if (page > 0)
          page++;
        if (page == 4)
        {
          page = 1;
        }
      }
      /*else if(prog==2)
      {
        //other program.
      }*/
    }
  }
  else if (resultButton == STATE_LONG)
  {
    if (millis() - preMillis > 250)
    {
      prog++;
      if (prog == 3)
      {
        prog = 1;
      }
      if (SPIFFS.exists("/programFile"))
      {
        File Writefile = SPIFFS.open("/programFile", "w");
        if (Writefile)
        {
          Writefile.print(prog);
        }
      }
      ESP.reset();
    }
  }
}

void Reset()
{
  if (millis() - HoldBtnMillis > 3000)
  {
    if (SPIFFS.exists("/config"))
    {
      File Writefile = SPIFFS.open("/config", "w");
      if (Writefile)
      {
        Writefile.println("");
        Writefile.println("");
      }
    }
    ESP.reset();
    HoldBtnMillis = millis();
  }
}
