String a;
int count;
char buf[100];
void setup() {

Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

}

void loop() {

while(Serial.available()) {

a= Serial.readString();// read the incoming data as string
count=a.length();
Serial.println(a);
Serial.print("Char count:");
Serial.println(count-2);
a.toCharArray(buf, count);

for(int i=0;i<count-2;i++){
  int value=(int)a[i];
Serial.println(value);
}
}
}
