#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>
#include<math.h>
#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


const char* ssid = "my wifi";
const char* password = "12345678";

ESP8266WebServer server(80);

String light="";
String temp="";
String hum="";
void setup() {
  // put your setup code here, to run once:
  SPIFFS.begin();
  Serial.begin(9600);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
  server.on("/", []() {
    File file = SPIFFS.open("/index.html", "r");
    server.streamFile(file, "text/html");
    file.close();
  });
  server.on("/pic.jpg", []() {
    File file = SPIFFS.open("/pic.jpg", "r");
    server.streamFile(file, "image/jpeg");
    file.close();
  });
  server.on("/on1", []() {
    File file = SPIFFS.open("/index.html", "r");
    server.streamFile(file, "text/html");
    file.close();
    digitalWrite(2, HIGH);
  
  });
  server.on("/off1", []() {
   File file = SPIFFS.open("/index.html", "r");
    server.streamFile(file, "text/html");
    file.close();
    digitalWrite(2, LOW);
    
  });
  server.on("/on2", []() {
    File file = SPIFFS.open("/index.html", "r");
    server.streamFile(file, "text/html");
    file.close();
    digitalWrite(4, HIGH);
  
  });
  server.on("/off2", []() {
   File file = SPIFFS.open("/index.html", "r");
    server.streamFile(file, "text/html");
    file.close();
    digitalWrite(4, LOW);
  
  });
  server.on("/on3", []() {
    File file = SPIFFS.open("/index.html", "r");
    server.streamFile(file, "text/html");
    file.close();
    digitalWrite(5, HIGH);
  
  });
  server.on("/off3", []() {
    File file = SPIFFS.open("/index.html", "r");
    server.streamFile(file, "text/html");
    file.close();
    digitalWrite(5, LOW);
  
  });

    server.on("/light", []() {
  int sensorValue = analogRead(A0);
  double dV = sensorValue;
 double le = (dV/1023)*100; 
  int level = le;
 light="LIGHT LEVEL:"+String((int)level)+"%";
  server.send(200,"text/plain",light);
 });

    server.on("/temp", []() {
       dht.begin();
      float t = dht.readTemperature();
      temp="TEMPERATURE is:"+String((int)t)+"*C";
      Serial.print("Temp:");
      Serial.print(t);
      Serial.println("*C");
      server.send(200,"text/plain",temp);
  });

    server.on("/hum", []() {
       dht.begin();
       float h = dht.readHumidity();
      hum="HUMIDITY:"+String((int)h)+"%";
      Serial.print("HUMIDITY:");
      Serial.print(h);
      Serial.println("%");
  server.send(200,"text/plain",hum);
  });
    
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  yield();
}
