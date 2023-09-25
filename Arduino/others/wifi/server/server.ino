#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>

#define led 2

#define ssid "my wifi"
#define password "12345678"

ESP8266WebServer server(80);
bool tog = 0;
void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  pinMode(led, OUTPUT);

  server.on("/", handleclient);
  server.begin();
}
void loop()
{
  server.handleClient();
  yield();
}
void handleclient()
{
  tog = !tog;
  digitalWrite(led, tog);
}

