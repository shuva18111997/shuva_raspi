int value = 0;
int btn = PA2;  //STM_32 INTERRUPT Pins :- PB9,PB8,PB7,PB6,PB5,PB4,PB3.
unsigned long premillis = 0;
void setup() {
  pinMode(PC13, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(btn, ValueChange, RISING);
}

void loop() {
  Serial.println("value = " + (String)value);
  delay(500);
}

void ValueChange()
{
  static unsigned long premillis = 0;
  if (millis() - premillis > 200)
  {
    value++;
  }
  premillis = millis();
}

