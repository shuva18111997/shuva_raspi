#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>
#include <IRremoteESP8266.h>
#include "DHT.h"
#define DHTPIN 14
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


const char* ssid = "my wifi";
const char* password = "12345678";

ESP8266WebServer server(80);
String light="";
String temp="";
String hum="";
int RECV_PIN =12;
IRrecv irrecv(RECV_PIN);
decode_results results;
int led1 =2;
int led2 =4;
int led3 =5;
int ledState[] = {0,0,0,0,0};
String state;

#define code1 642546947

#define code2 33444015

#define code3 33478695

#define code4 761297281

#define code5 33486855

#define code6 -2014664387

#define code10 33441975

#define code11 -281335461

void setup() {
  // put your setup code here, to run once:
  SPIFFS.begin();
irrecv.enableIRIn();
  Serial.begin(9600);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  pinMode(2, OUTPUT);//load
  pinMode(4, OUTPUT);//load
  pinMode(5, OUTPUT);//load
  pinMode(A0, INPUT);//light sensor
  pinMode(14, INPUT);//DHT11
  pinMode(12, INPUT);//IR Sensor
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
      server.send(200,"text/plain",temp);
  });

    server.on("/hum", []() {
       dht.begin();
       float h = dht.readHumidity();
      hum="HUMIDITY:"+String((int)h)+"%";
  server.send(200,"text/plain",hum);
  });
    
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  yield();
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = Serial.read(); //Conduct a serial read
  state += c; //build the string- either "On" or "off"
  }  
  if (state.length() > 0) {
   Serial.println(state); 
  if(state=="1") 
  {
    digitalWrite(2, HIGH);
    
      } 
  
  else if(state =="A") 
  {
    digitalWrite(2, LOW);
     }
 if(state == "2") 
  {
    digitalWrite(4, HIGH);
    
      } 
  
  else if(state =="B") 
  {
    digitalWrite(4, LOW);
     }
      if(state == "3") 
  {
    digitalWrite(5, HIGH);
    
      } 
  
  else if(state =="C") 
  {
    digitalWrite(5, LOW);
     }

state ="";} //Reset the variable

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 if (irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(decCode);

    
switch (decCode){


 case code1:
        if (ledState[1] == 1) {
          digitalWrite(2, LOW);
         ledState[1]  = 0; 
        } else {
          digitalWrite(2, HIGH);
          ledState[1]  = 1;
        } 
        break;
        case code2:
        if (ledState[1] == 1) {
          digitalWrite(2, LOW);
         ledState[1]  = 0;}
         else {
          digitalWrite(2, HIGH);
          ledState[1]  = 1;} 
         break;
        case code3:
        if (ledState[2] == 1) {
          digitalWrite(4, LOW);
         ledState[2]  = 0;; 
          
        } else {
          digitalWrite(4, HIGH);
          ledState[2]  = 1;
         
        }  break;
      case code4:
        if (ledState[2] == 1) {
          digitalWrite(4, LOW);
         ledState[2]  = 0;;
          
        } else {
          digitalWrite(4, HIGH);
          ledState[2]  = 1;
        }  
        break;
      case code5:
        if (ledState[3] == 1) {
          digitalWrite(5, LOW);
         ledState[3]  = 0;
        } else {
          digitalWrite(5, HIGH);
          ledState[3]  = 1;
        }  break;
      case code6:
        if (ledState[3] == 1) {
          digitalWrite(5, LOW);
         ledState[3]  = 0;
        } else {
          digitalWrite(5, HIGH);
          ledState[3]  = 1;}
        break;
        case code10:
         if (ledState[1,2,3] ==1)
        { digitalWrite(2,LOW);
         digitalWrite(4,LOW);
         digitalWrite(5,LOW);
        ledState[1] = 0;
        ledState[2] = 0;
        ledState[3] = 0;
        }
      else
    {  digitalWrite(2,HIGH);
         digitalWrite(4,HIGH);
         digitalWrite(5,HIGH);
        ledState[1] = 1;
        ledState[2] = 1;
        ledState[3] = 1;
        }
      break;
        case code11:
         if (ledState[1,2,3] ==1)
        { digitalWrite(2,LOW);
         digitalWrite(4,LOW);
         digitalWrite(5,LOW);
        ledState[1] = 0;
        ledState[2] = 0;
        ledState[3] = 0;
        }
      else
    {  digitalWrite(2,HIGH);
         digitalWrite(4,HIGH);
         digitalWrite(5,HIGH);
        ledState[1] = 1;
        ledState[2] = 1;
        ledState[3] = 1;
   }    
  }
Serial.println(decCode);
  irrecv.resume();

}
  
}
