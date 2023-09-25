#include<ESP8266WiFi.h>
#include<WiFiUdp.h>
const char*ssid= "my wifi";
const char*password = "39039820";
uint16_t port = 8888;
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];

WiFiUDP udp;
void setup(){
  Serial.begin(115200);
  delay(10);
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
  Serial.println();
  Serial.print("Connecting to");
  Serial.println(ssid);
  WiFi.begin(ssid,password);
  while(WiFi.status()!= WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conected");
  IPAddress myIp = WiFi.localIP();
  Serial.println(myIp);
  udp.begin(port);
}


void loop(){
  int packetSize =udp.parsePacket();
  if(packetSize){
    String note ="ID.1";
    note +="Recived Packet Size";
    note+=packetSize;
    note +="From:";
    Serial.println(note);
    IPAddress remote =udp.remoteIP();
    for(int i=0;i<4;i++)
    {
      Serial.print(remote[i],DEC);
      if(i<3)
      {
        Serial.print(".");
        
      }
    }
    note="port:";
    note+=udp.remotePort();
    udp.read(packetBuffer,UDP_TX_PACKET_MAX_SIZE);
    note+="Contents.";
    note+=packetBuffer;
    Serial.println(note);
  }
  //change packetBuffer[0]=='1'for packetBuffer[0]=='2' to match your switch NUMBER
  if(packetBuffer[0]=='1'&&packetBuffer[2]=='2'&&packetBuffer[8]=='1')
  digitalWrite(2,HIGH);
  if(packetBuffer[0]=='1'&&packetBuffer[2]=='2'&&packetBuffer[8]=='0')
  digitalWrite(2,LOW);
  memset(packetBuffer,0,UDP_TX_PACKET_MAX_SIZE);

    
    
  }
  
 


