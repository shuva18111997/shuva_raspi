#define scl A5
#define sda A4

#define scl_high digitalWrite(scl, HIGH);
#define scl_low digitalWrite(scl, LOW);

#define sda_high digitalWrite(sda, HIGH);
#define sda_low digitalWrite(sda, LOW);

void setup() {
  pinMode(scl, OUTPUT);
  pinMode(sda, OUTPUT);

  //initial condition
  scl_high;
  sda_high;
  delay(2000);

  //start condition
  sda_low;
  delay(500);
  scl_low;
  delay(500);

  //send 1
  send_1();
  //send 0
  send_0();
  //send 1
  send_1();
  //send 0
  send_0();
  //send 0
  send_0();
  //send 0
  send_0();
  //send 0
  send_0();
  //send 0
  send_0();

}


void send_1()
{
  sda_high;
  delay(500);
  scl_high;
  delay(10);
  scl_low;
  delay(500);
}

void send_0()
{
  sda_low;
  delay(500);
  scl_high;
  delay(10);
  scl_low;
  delay(500);
  sda_high;
}

void loop() {
  // put your main code here, to run repeatedly:

}
