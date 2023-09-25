#define red 11
#define green 10
#define blue 9

#define R_VALUE 200
#define G_VALUE 255
#define B_VALUE 255

void setup() {
  analogWrite(red, 255 - R_VALUE);
  analogWrite(green, 255 - G_VALUE);
  analogWrite(blue, 255 - B_VALUE);
  
  /*
  analogWrite(red, R_VALUE);
  analogWrite(green, G_VALUE);
  analogWrite(blue, B_VALUE);
  */
}

void loop() {
  
}
