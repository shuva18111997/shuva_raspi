const uint8_t buffersize=4;
uint8_t buffer[buffersize];
void setup() {
  while(!Serial);
  Serial.begin(115200);
  buffer[0]=0x2d;
}

void loop() {
  int a=analogRead(A0);
  int b=analogRead(A1);
  int c=analogRead(A2);
  buffer[1]=a/4;
  buffer[2]=b/4;
  buffer[3]=c/4;
  Serial.write(buffer,buffersize);
  delay(100);
}
