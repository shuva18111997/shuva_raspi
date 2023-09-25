/*
All the pins are working means blinking properly.
But the GPIO ->{36,39,34,35} are not blinking.
*/
//This GPIO ->{36,39,34,35} pins are only for INPUT.

int led[25] = {1, 2, 3, 4, 5, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 23, 25, 26, 27, 32, 33, 34, 35, 36, 39};

void setup() {
  for (int i = 0; i < 25; i++)
    pinMode(led[i], OUTPUT);
}

void loop() {
  for (int i = 0; i < 25; i++)
    digitalWrite(led[i], HIGH);
  delay(500);
  for (int i = 0; i < 25; i++)
    digitalWrite(led[i], LOW);
  delay(500);
}
