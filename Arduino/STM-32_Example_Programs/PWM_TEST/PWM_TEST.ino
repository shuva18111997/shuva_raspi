//////////////////////////////////////////////////////////////////////////////////////
//*****WORKING PWM PINS ARE {PB9,PB8,PB7,PB6,PA11,PA10,PA9,PA8} & {PA0,PA1,PA2,PA3,PA6,PA7,PB0,PB1}*****//
//////////////////////////////////////////////////////////////////////////////////////

int ledPin = PB6;
void setup() {
  pinMode(ledPin, PWM);   // setup the pin as HIGH RESOLUTION 16-bit PWM (range from 0 to 65535).
  //pinMode(ledPin, OUTPUT);  // setup the pin as NORMAl 8-bit PWM (range from 0 to 255).
}

void loop()  {
  // Fade in from min to max in increments of 1280 points:
  for (int fadeValue = 0; fadeValue <= 65535; fadeValue += 1280) {
    // Sets the value (range from 0 to 65535):
    pwmWrite(ledPin, fadeValue);
    // Wait for 30 milliseconds to see the dimming effect:
    delay(30);
  }

  // Fade out from max to min in increments of 1280 points:
  for (int fadeValue = 65535 ; fadeValue >= 0; fadeValue -= 1280) {
    // Sets the value (range from 0 to 1280):
    pwmWrite(ledPin, fadeValue);
    // Wait for 30 milliseconds to see the dimming effect:
    delay(30);
  }
}
/*
void loop()  {
  for (int fadeValue = 0; fadeValue <= 255; fadeValue += 2) {
    // Sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // Wait for 10 milliseconds to see the dimming effect:
    delay(10);
  }

  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 2) {
    // Sets the value (range from 255 to 0):
    analogWrite(ledPin, fadeValue);
    // Wait for 10 milliseconds to see the dimming effect:
    delay(10);
  }
}*/
