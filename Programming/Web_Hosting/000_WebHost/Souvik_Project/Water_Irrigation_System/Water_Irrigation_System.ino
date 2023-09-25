#include <Wire.h>
#include "SSD1306Wire.h"
#include <dht11.h>
#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>


#define ssid "SOUVIK MONDAL"
#define password "121234a."

dht11 DHT;
#define DHT11_PIN 14

#define SDA 5
#define SCL 4
SSD1306Wire  display(0x3c, SDA, SCL);

#define LED LED_BUILTIN
#define Pump 12

#define soil_moisture_sensor A0
int sensor_reading = 0;
int Threshold = -1;

ESP8266WebServer server(80);
bool state;

String Temp;
String Hum;
String Moisture;

void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
  pinMode(Pump, OUTPUT);
  digitalWrite(Pump, LOW);

  display.init();
  display.clear();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);

  display.drawString(0, 0, "\nSmart Irrigation System\nby Souvik Mondal");
  display.display();
  delay(2000);
  display.setFont(ArialMT_Plain_16);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Threshold = -1;
}
int conn_cont = 1;
void loop() {
  if (WiFi.status() != WL_CONNECTED)
  {
    display.clear();
    display.drawString(0, 0, "Connecting");
    display.display();
    conn_cont = 1;
    while (WiFi.status() != WL_CONNECTED)
    {
      Serial.println(conn_cont);
      if (conn_cont == 1)
      {
        display.drawString(0, 0, "Connecting.  ");
        display.display();
      }
      else if (conn_cont == 2)
      {
        display.drawString(0, 0, "Connecting.. ");
        display.display();
      }
      else if (conn_cont == 3)
      {
        display.drawString(0, 0, "Connecting...");
        display.display();
      }
      conn_cont++;
      if (conn_cont > 3)
      {
        conn_cont = 1;
        display.clear();
      }
      state = !state;
      digitalWrite(LED, state);
      delay(500);
    }
  }
  else
  {
    SensorRead();
    SendRequest();
    if ((analogRead(A0) >= 0 ) && (analogRead(A0) <= Threshold))
    {
      digitalWrite(Pump, HIGH);
    }
    else
    {
      digitalWrite(Pump, LOW);
    }
    delay(500);
  }
}

void SensorRead()
{
  int chk;
  Serial.print("DHT11, \t");
  chk = DHT.read(DHT11_PIN);    // READ DATA
  // DISPLAT DATA
  Temp = (String)DHT.temperature;
  Hum = (String)DHT.humidity;
  Moisture = (String)analogRead(soil_moisture_sensor);
  Serial.print(Hum);
  Serial.print(",\t");
  Serial.print(Temp);
  Serial.print(",\t");
  Serial.println(Moisture);
}

void SendRequest()
{
  HTTPClient http;
  String dataSend = "http://souvikmondaliot.000webhostapp.com/sensor.php?Temp=" + Temp + "&Hum=" + Hum + "&Moisture=" + Moisture;
  //https://souvikmondaliot.000webhostapp.com/sensor.php?Temp=36&Hum=25&Moisture=10
  http.begin(dataSend);
  Serial.println(dataSend);
  int httpCode = http.GET();
  Serial.println(httpCode);
  if (httpCode == 200)
  {
    digitalWrite(LED, LOW);
    Serial.print("Send\t\t");
    String payload = http.getString();
    Serial.println(payload);
    if (payload.toInt() <= 1024)
    {
      Threshold = payload.toInt();
    }
    ShowDisplay();
  }
  else
  {
    digitalWrite(LED, HIGH);
    digitalWrite(Pump, LOW);
    display.clear();
    display.drawString(0, 0, "Failed to connect");
    display.display();
    Serial.println("Failed");
  }
  http.end();
}
void ShowDisplay()
{
  display.clear();
  display.drawString(0, 0, "Temp:- " + Temp + " *c\nHum:- " + Hum + "%\nMois:- " + Moisture);
  display.display();
}
