#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>
#include<math.h>

const char* ssid = "my wifi";
const char* password = "12345678";

ESP8266WebServer server(80);
double ThermistorC(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;          
 return Temp;
}

void setup() {
 
  // put your setup code here, to run once:
  SPIFFS.begin();
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
  Serial.begin(9600);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  
   server.begin();
     server.on("/", []() {
String webpage;     
      webpage += "<html>";
      webpage += "<head>";
      webpage += "<meta http-equiv=refresh content=1 />";
      webpage += "</head>";
      webpage += "<body bgcolor=lime>";
      webpage += "<center>";
      webpage += "<h1>";
      webpage += "<font color=red>Temp in celcious is: </font>";
      int valC;                
  double tempC;            
  valC=analogRead(0);      
  tempC=ThermistorC(valC);
  tempC=tempC+0.73;
      webpage += String((double)tempC);
      webpage += "<font color=blue>*C</font>";
      webpage += "</h1>";
      webpage += "</center>";
      webpage += "</body>";
      webpage += "</html>";
      server.send(200, "text/html", webpage);
        });
}

void loop() {
  int valC;                
  double tempC;            
  valC=analogRead(0);      
  tempC=ThermistorC(valC);
  tempC=tempC+0.73;
  Serial.print("Temperature :- ");
      Serial.print(tempC);
      Serial.println("*C");
      delay(500);
  server.handleClient();
  yield();
}
   
