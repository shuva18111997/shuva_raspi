String st;
int Led = PC13;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(Led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  
}

// the loop function runs over and over again forever
/*void loop() {
  if (Serial.available())
  {
    st = "";
    st = Serial.readString();
    if (st == "on" || st == "1" || st == "ON")
    {
      digitalWrite(Led, HIGH);
    }
    else if (st == "off" || st == "0" || st == "OFF")
    {
      digitalWrite(Led, LOW);
    }
  }
}*/
