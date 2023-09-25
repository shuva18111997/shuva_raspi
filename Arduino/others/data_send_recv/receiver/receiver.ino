const uint8_t buffersize=4;
uint8_t buffer[buffersize];
uint8_t s=0x2d;
uint8_t c;
int readcounter;
void setup(){
  while(!Serial);
  Serial.begin(115200);
}
void loop(){
  while(Serial.available()){
    c=Serial.read();
    if(c==s){
      readcounter=0;
    }
    buffer[readcounter]=c;
    readcounter++;
  }
  if(readcounter>=buffersize){
    readcounter=0;
  }
  byte a=buffer[1];
  byte b=buffer[2];
  byte c=buffer[3];
  Serial.print("a= ");
  Serial.println(a);
  Serial.print("b= ");
  Serial.println(b);
  Serial.print("c= ");
  Serial.println(c);
  Serial.println("");
  Serial.println("");
  delay(500);
}

