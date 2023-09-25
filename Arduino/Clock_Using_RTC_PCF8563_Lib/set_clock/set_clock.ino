/* Demonstration of Rtc_Pcf8563 Set Time.
   Set the clock to a time then loop over reading time and
   output the time and date_time to the serial console.

   I used a RBBB with Arduino IDE, the pins are mapped a
   bit differently. Change for your hw
   SCK - A5, SDA - A4, INT - D3/INT1

   After loading and starting the sketch, use the serial monitor
   to see the clock output.

   setup:  see Pcf8563 data sheet.
           1x 10Kohm pullup on Pin3 INT
           No pullups on Pin5 or Pin6 (I2C internals used)
           1x 0.1pf on power
           1x 32khz chrystal

   Joe Robertson, jmr
   orbitalair@bellsouth.net
*/
#include <Wire.h>
#include <Rtc_Pcf8563.h>
#include<TimeLib.h>

//init the real time clock
Rtc_Pcf8563 rtc;
const String monthName[12] = {
  "Jan", "Feb", "Mar", "Apr", "May", "Jun",
  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

void setup()
{
  Serial.begin(9600);
  //set a time to start with.
  Set_Date_Time();
}

void loop()
{
  //both format functions call the internal getTime() so that the
  //formatted strings are at the current time/date_time.
  Serial.print(rtc.formatTime());
  Serial.print("\r\n");
  Serial.print(rtc.formatDate());
  Serial.print("\r\n");
  delay(1000);
}

void Set_Date_Time() {
  String date_time[3];
  split((String)__DATE__, ' ', date_time);
  int m;
  for (int i = 0; i < 12; i++)
  {
    if (monthName[i] == date_time[0])
    {
      m = i + 1;
      break;
    }
  }
  String y;
  y = date_time[2];
  y.remove(2); //print '20'
  date_time[2].remove(0, 2);
  if (y == "20")
    rtc.setDate(date_time[1].toInt(), 6, m, 0, date_time[2].toInt()); //day, weekday, month, century(1=1900, 0=2000), year(0-99)
  else
    rtc.setDate(date_time[1].toInt(), 6, m, 1, date_time[2].toInt()); //day, weekday, month, century(1=1900, 0=2000), year(0-99)
  for (int i = 0; i < 3; i++)
    date_time[i] = "";
  split((String)__TIME__, ':', date_time);
  rtc.setTime(date_time[0].toInt(), date_time[1].toInt(), date_time[2].toInt());  //hr, min, sec
}

void split(String str, char c, String *strArr)
{
  str.trim();
  int index = 0, j = 0;
  while (1)
  {
    index = str.indexOf(c);
    if (index >= 0) {
      for (int i = 0; i < index; i++)
      {
        strArr[j] += str.charAt(i);
        //strArr.setCharAt(i, str.charAt(i));
      }
      strArr[j].trim();
      str.remove(0, index + 1);
      str.trim();
      if (strArr[j] !=  0)
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