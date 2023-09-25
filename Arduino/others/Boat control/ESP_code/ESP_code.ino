#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>

const char* ssid = "my wifi";
const char* password = "12345678";

ESP8266WebServer server(80);


void setup() {
  // put your setup code here, to run once:
  SPIFFS.begin();
  Serial.begin(9600);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  
  server.on("/", []() {
    File file = SPIFFS.open("/index.html", "r");
    server.streamFile(file, "text/html");
    file.close();
  });
  
  server.on("/F-Left", []() {
    File file = SPIFFS.open("/index.html", "r");
    server.streamFile(file, "text/html");
    file.close();
    
  Serial.write("L");
  });
  server.on("/B-Left", []() {
   File file = SPIFFS.open("/index.html", "r");
    server.streamFile(file, "text/html");
    file.close();
 
    Serial.write("l");
  });
  server.on("/FONT", []() {
    File file = SPIFFS.open("/index.html", "r");
    server.streamFile(file, "text/html");
    file.close();
    
    Serial.write("F");
  });
  server.on("/STOP", []() {
   File file = SPIFFS.open("/index.html", "r");
    server.streamFile(file, "text/html");
    file.close();
    
    Serial.write("S");
  });
server.on("/BACK", []() {
   File file = SPIFFS.open("/index.html", "r");
    server.streamFile(file, "text/html");
    file.close();
    
    Serial.write("b");
  });
  server.on("/F-Right", []() {
   File file = SPIFFS.open("/index.html", "r");
    server.streamFile(file, "text/html");
    file.close();
    
    Serial.write("R");
  });
   server.on("/B-Right", []() {
    File file = SPIFFS.open("/index.html", "r");
    server.streamFile(file, "text/html");
    file.close();
   
    Serial.write("r");
  });
  

 server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  yield();
}
