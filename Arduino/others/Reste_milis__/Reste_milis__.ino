unsigned long time;
unsigned long timer;
void setup() {
  Serial.begin(9600);
  while (time <= 10000)
  {
    time = millis();
    Serial.println(time / 1000);
    delay(1000);
  }
  setMillis(5000.0);  //Reset the millis() timer Set it to (0.0). But we set it to 5000 ms.
  Serial.println("New time start");
}

void loop() {
  timer = millis();
  Serial.println(timer / 1000);
  delay(1000);
}
//This function is set the timer to a specific time.
void setMillis(unsigned long new_millis)
{
  extern volatile unsigned long timer0_millis;
  uint8_t oldSREG = SREG;
  cli();
  timer0_millis = new_millis;
  SREG = oldSREG;
}
