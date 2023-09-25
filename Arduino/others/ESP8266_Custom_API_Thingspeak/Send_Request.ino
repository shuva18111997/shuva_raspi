void page1()
{
  display.clearDisplay();
  display.setCursor(0, 20);
  String str = sendRequest("Time");
  if (str != "NULL")
  {
    str.remove(0, 20);
    Serial.println(str);
  }
  String strArr[2];
  split(str, ' ', strArr);
  display.print(strArr[0]);
  if (strArr[1] == "AM")
    display.print("am");
  else if (strArr[1] == "PM")
    display.print("pm");
  display.display();
}

void page2()
{
  display.clearDisplay();
  display.setCursor(0, 20);
  String str = sendRequest("Date");
  if (str != "NULL")
    Serial.println(str);
  str.remove(0, 32);
  str.remove((str.length() - 7));
  String strArr[7];
  String StrArr[2];
  split(str, ',', strArr);
  split(strArr[1], ' ', StrArr);
  StrArr[0].remove(3);
  strArr[2].remove(0, 2);
  display.println(" " + StrArr[1] + "/" + StrArr[0] + "/" + strArr[2]);
  String s;
  for (int i = 0; i < 3; i++)
  {
    s += strArr[0][i];
  }
  display.print("    " + s);
  display.display();
}

void page3()
{
  display.clearDisplay();
  display.setCursor(0, 17);
  display.print("Tem: ");
  String temp = sendRequest("Temp");
  display.print((String)temp[0] + (String)temp[1]);
  display.println(" *C");

  display.print("Hum: ");
  String hum = sendRequest("Hum");
  display.print((String)hum[0] + (String)hum[1]);
  display.println(" %");

  display.display();
}
