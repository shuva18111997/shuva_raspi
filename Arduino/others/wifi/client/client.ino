#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#define ssid "my wifi"
#define password "12345678"

#define host "192.168.4.1"

char str;
WiFiClient client;

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  if (client.connect(host, 80 ))
  {
    Serial.println("connected");
    client.stop();
  }
  else
  {
    Serial.println("Not connected");
  }
}
void loop()
{
  sendRequest();
  delay(2000);
}


void sendRequest()
{
  if (client.connect(host, 80))
  {
    client.print("GET / ");
    client.println("HTTP/1.1");
    client.print("Host: ");
    client.println(host);
    client.println("Connection: close");
    client.println();
    client.stop();
    Serial.println("Successfully send Request");
  }
  else
  {
    Serial.println("Client not connected");
  }
}
