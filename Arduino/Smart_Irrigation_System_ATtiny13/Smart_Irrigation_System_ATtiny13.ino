#include <TinyWire.h>
#include "DS1307_ATtiny.h"

// We have to define which pins to use for SDA and SCL
const uint8_t TinyWire::SCL = 2;
const uint8_t TinyWire::SDA = 0;

// Sets the i2c clock speed in [Hz]
// Use MAX_SPEED for the highest possible clock speed
const uint32_t TinyWire::FREQ = 100000;

DS1307 clock;

int valve_pin = 1;
int Soil_Moisture = 3;

byte time_h = 20;
byte time_m = 10;

void setup()
{
  clock.begin();
//  clock.fillByYMD(2013, 1, 19); //Jan 19,2013
//  clock.fillByHMS(15, 28, 30); //15:28 30"
//  clock.fillDayOfWeek(SAT);//Saturday
//  clock.setTime();//write time to the RTC chip
  pinMode(valve_pin, OUTPUT);
  pinMode(Soil_Moisture, INPUT);
}

void loop()
{
  clock.getTime();
  digitalWrite(valve_pin, LOW);
  if ((clock.hour == time_h) && (clock.minute == time_m))
  {
    while (digitalRead(Soil_Moisture))
    {
      digitalWrite(valve_pin, HIGH);
    }
  }
}
