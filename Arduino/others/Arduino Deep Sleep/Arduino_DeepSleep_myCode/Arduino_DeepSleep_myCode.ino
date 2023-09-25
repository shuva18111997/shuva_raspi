/*Links :- 1)https://playground.arduino.cc/Learning/ArduinoSleepCode/
  2) https://github.com/RalphBacon/Arduino-Deep-Sleep
*/
#include <avr/sleep.h>
#define wakePin 3
#define ledPin 13
char c;
void setup() {
  Serial.begin(9600);
  pinMode(wakePin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  attachInterrupt(1, WakeUP, FALLING);
  /* Set the type of sleep mode we want. Can be one of (in order of power saving):
    SLEEP_MODE_IDLE (Timer 0 will wake up every millisecond to keep millis running)
    SLEEP_MODE_ADC
    SLEEP_MODE_PWR_SAVE (TIMER 2 keeps running)
    SLEEP_MODE_EXT_STANDBY
    SLEEP_MODE_STANDBY (Oscillator keeps running, makes for faster wake-up)
    SLEEP_MODE_PWR_DOWN (Deep sleep)
  */
  set_sleep_mode (SLEEP_MODE_PWR_DOWN);
  sleep_enable(); //Enable sleep mode
}

void WakeUP()
{
  //sleep_disable();  //Disable sleep mode
  /*If "sleep_disable" is written here so the sleep_cpu will not
  work. if nothing will be written. then it can agian going to deep sleep mode.
  */
}

void loop() {
  while (Serial.available())
  {
    c = Serial.read();
    if (c == 's')
    {
      Serial.println("Going to Sleep now");
      sleep_cpu();
    }
  }
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
}
