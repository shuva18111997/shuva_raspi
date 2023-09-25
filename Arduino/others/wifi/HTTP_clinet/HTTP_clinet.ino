#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#define ssid "my wifi"
#define password "12345678"

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
}

void loop()
{
  sendRequest();
  delay(2000);
}

void sendRequest()
{
  HTTPClient http;
  http.begin("http://192.168.4.1/");
  Serial.print("[HTTP] GET...\n");

  /*int httpCode = http.GET();
  Serial.printf("value of httpCode is %d",httpCode);*/
  http.end();
}
