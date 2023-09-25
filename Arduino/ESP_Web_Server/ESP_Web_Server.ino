#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>

const char* ssid = "my wifi";
const char* password = "12345678";

ESP8266WebServer server(80);

void setup() {
  // put your setup code here, to run once:
  SPIFFS.begin();

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  server.on("/", []() {
    File file = SPIFFS.open("/index.html", "r");
    server.streamFile(file, "text/html");
    file.close();
  });
 
  server.on("/on1", []() {
    //As ESP8266 is inverted output
    //thus HIGH means off
    digitalWrite(2, HIGH);
  
  });
  server.on("/off1", []() {
    //thus LOW means on
    digitalWrite(2, LOW);
    
  });
  server.on("/on2", []() {
    //As ESP8266 is inverted output
    //thus HIGH means off
    digitalWrite(4, HIGH);
  
  });
  server.on("/off2", []() {
    //As ESP8266 is inverted output
    //thus HIGH means off
    digitalWrite(4, LOW);
  
  });
  server.on("/on3", []() {
    //As ESP8266 is inverted output
    //thus HIGH means off
    digitalWrite(5, HIGH);
  
  });
  server.on("/off3", []() {
    //As ESP8266 is inverted output
    //thus HIGH means off
    digitalWrite(5, LOW);
  
  });
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  yield();
}
