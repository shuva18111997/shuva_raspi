void api_Thingspeak()
{
  if ((page > 0) && (WiFi.status() != WL_CONNECTED))
  {
    ConnectingToAP();
  }
  if (page > 0)
  {
    if (page == 1)
    {
      page1();
    }
    else if (page == 2)
    {
      page2();
    }
    else if (page == 3)
    {
      page3();
    }
  }
  else
  {
    server.handleClient();
  }
}

String sendRequest(String s)
{
  HTTPClient http;
  if (s == "Temp")
    http.begin("http://api.thingspeak.com/apps/thinghttp/send_request?api_key=WONCERSWYNBODMUG");  //For Temp.
  else if (s == "Hum")
    http.begin("http://api.thingspeak.com/apps/thinghttp/send_request?api_key=HMVMLM7GBTDZROVJ");  //For Hum.
  else if (s == "Time")
    http.begin("http://api.thingspeak.com/apps/thinghttp/send_request?api_key=Q900Z1ZEOQ5B2N40");  //For Time.
  else if (s == "Date")
    http.begin("http://api.thingspeak.com/apps/thinghttp/send_request?api_key=FWD7FNMBUBSGMO5Z");  //For Date.
  int httpCode = http.GET();
  Serial.println(httpCode);
  if (httpCode == 200)
  {
    digitalWrite(led, state);
    state = !state;
    return http.getString();
  }
  else
  {
    Serial.println(http.errorToString(httpCode).c_str());
    digitalWrite(led, HIGH);
    return "NULL";
  }
  http.end();
}

void split(String str, char c, String *strArr)
{
  int index, j;
  while (1)
  {
    index = str.indexOf(c);
    if (index >= 0) {
      for (int i = 0; i < index; i++)
      {
        strArr[j] += str[i];
      }
      strArr[j].trim();
      str.remove(0, index + 1);
      j++;
    }
    else
    {
      for (int i = 0; i < str.length(); i++)
      {
        strArr[j] += str[i];
      }
      strArr[j].trim();
      break;
    }
  }
}
