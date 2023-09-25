#include <ESP8266WiFi.h>

#define led 2
/*
 * Please Connect GPIO16(D0) With RESET Pin Of ESP8266-12E.
*/
bool tog = 0;
void setup()
{
  Serial.begin(9600);
  Serial.println("Wake Up From Deep Sleep Mode");
  pinMode(led, OUTPUT);
  Toggle();
  Serial.println("Going  To Deep Sleep Mode");
  ESP.deepSleep(2e6); //Deep_Sleep for 2x10^6 micro seconds OR 2 sec.
  Serial.println("Form Here Nothing will Exicute");
}
void loop()
{
  Serial.println("Void Loop will Not Work.");
}
void Toggle()
{
  tog = !tog;
  digitalWrite(led, tog);
}

