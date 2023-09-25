#include<avr/pgmspace.h>

const char *const str[] PROGMEM = {"abc", "cde"};
const PROGMEM int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
const char PROGMEM c[] = {'a', 'b', 'c'};
int cnt;

void setup() {
  Serial.begin(9600);
  Serial.println((char *)pgm_read_word(&(str[0])));
  /************************************************/
  Serial.println("********************************************");
  while (cnt < sizeof(c))
  {
    Serial.println((char)pgm_read_byte_near(c + cnt));
    cnt++;
  }
  cnt = 0;
  Serial.println("********************************************");
  while (cnt < (sizeof(x)/2))
  {
    Serial.println(pgm_read_word_near(x + cnt));
    cnt++;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
