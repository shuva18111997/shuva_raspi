#include <WiFi.h>
#include <WiFiUdp.h>

const char *ssid = "ESP32";
const char *pass = "";
#define led 2
unsigned int localPort = 2000; // local port to listen for UDP packets

IPAddress ServerIP(192, 168, 4, 1);
//IPAddress ClientIP(192,168,4,2);

// A UDP instance to let us send and receive packets over UDP
WiFiUDP udp;

char packetBuffer[9];   //Where we get the UDP data
//======================================================================
//                Setup
//======================================================================
void setup()
{
  Serial.begin(9600);
  Serial.println();
  pinMode(led, OUTPUT);
  WiFi.softAP(ssid, pass);    //Create Access point

  //Start UDP
  Serial.println("Starting UDP");
  udp.begin(localPort);
}
//======================================================================
//                MAIN LOOP
//======================================================================
void loop()
{
  int cb = udp.parsePacket();
  if (!cb)
  {
    //If serial data is recived send it to UDP
    if (Serial.available() > 0)
    {
      udp.beginPacket(ServerIP, 2000);  //Send Data to Master unit
      //Send UDP requests are to port 2000

      uint8_t a;
      a = Serial.parseInt(); //Serial Byte Read
      udp.print(a); //Send one byte to ESP8266
      udp.endPacket();
    }
  }
  else {
    // We've received a UDP packet, send it to serial
    udp.read(packetBuffer, 1); // read the packet into the buffer, we are reading only one byte
    Serial.print(packetBuffer);
    if (packetBuffer[0] == '1')
    {
      digitalWrite(led, HIGH);
    }
    else if (packetBuffer[0] == '0')
    {
      digitalWrite(led, LOW);
    }
    delay(20);
  }
}
