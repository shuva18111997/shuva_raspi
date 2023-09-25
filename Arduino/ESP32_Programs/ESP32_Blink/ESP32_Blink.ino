#define led 2
void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, 1);
  delay(500);
  digitalWrite(led, 0);
  delay(500);
}
