String st;
int Led = PC13;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(Led, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  if(Serial.available())
  {
    st=Serial.readString();
  }
  digitalWrite(Led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);                       // wait for a second
  digitalWrite(Led, LOW);    // turn the LED off by making the voltage LOW
  delay(50);                       // wait for a second
  Serial.println("Hi "+st);
}
