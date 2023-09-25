void setup() {
  Serial.begin(9600);
  String strArr[7];
  String str = "ab , cd , ef ";
  split(str, ',', strArr);

  for (int i = 0; i < 3 ; i++)
    Serial.println(strArr[i]);
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

void loop() {
  // put your main code here, to run repeatedly:

}
