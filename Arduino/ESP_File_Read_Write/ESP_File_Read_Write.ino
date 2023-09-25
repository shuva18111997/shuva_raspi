#include "FS.h"

String totalStr[10];
int count = 0;

void setup() {
  SPIFFS.begin();
  Serial.begin(115200);
  Serial.println();
  if (SPIFFS.exists("/config"))
  {
    File Readfile = SPIFFS.open("/config", "r");
    //Serial.println("Size of file " + (String)Readfile.size());
    if (Readfile)
    {
      while (Readfile.available())
      {
        totalStr[count] = Readfile .readStringUntil('\n');
        //Serial.print("String is " + totalStr[count]);
        //Serial.println("\t length is " + (String)totalStr[count].length());
        count++;
      }
      //Serial.println("StrToStr(totalStr[0]).length()= " + (String)StrToStr(totalStr[0]).length());
      //Serial.println("totalStr[0].length()= " + (String)totalStr[0].length());
      if (StrToStr(totalStr[0]) == "shuva")
      {
        //Serial.println("Name is " + totalStr[0]);
      }
      //Serial.println("totalStr[0][totalStr[0].length()]= " + totalStr[0][totalStr[0].length()]);
      char a = totalStr[0][totalStr[0].length() - 1];
      char b = totalStr[0][totalStr[0].length() - 2];
      Serial.println("char a= " + (String)a);
      Serial.println("char b= " + (String)b);
      Serial.println(a, DEC);
      Serial.println(b, DEC);
      /*if (StrToStr(totalStr[1]) == "kapa")
        {
        Serial.println("Name is " + totalStr[1]);
        }*/
    }
    Readfile.close();
  }
}

/*String StrToStr(String data)
  {
  char ch[data.length()];
  data.toCharArray(ch, data.length()); //Ekhane data.length() Lekha mane Eta niche (data.length()-1). Mane je char array ta toiri ho6e seta holo ch[(data.length()-1)].
  String st = "";
  for (int i = 0; i < (data.length() - 1); i++)  //By this->(data.length() - 1) the Problem will solved.
  {
    st += ch[i];
  }
  return st;
  }*/
////////////////////This is better///////////////////
String StrToStr(String data)
{
  String st = "";
  for (int i = 0; i < data.length(); i++)
  {
    if (byte(data[i]) > 31)  //We write '31' to eleminate the chars previous 'space', For more information see char table.
    {
      st += data[i];
    }
  }
  return st;
}

void loop()
{

}
