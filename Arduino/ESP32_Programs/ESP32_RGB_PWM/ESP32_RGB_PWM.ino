/*
  ESP32 LED PWM Controller
The ESP32 has a LED PWM controller with 16 independent channels
that can be configured to generate PWM signals with different properties.

Here’s the steps you’ll have to follow to dim an LED with PWM using the Arduino IDE:

1. First, you need to choose a PWM channel.
There are 16 channels from 0 to 15.

2. Then, you need to set the PWM signal frequency.
For an LED, a frequency of 5000 Hz is fine to use.

3. You also need to set the signal’s duty cycle resolution: you have
resolutions from 1 to 16 bits.  We’ll use 8-bit resolution,
which means you can control the LED brightness using a value from 0 to 255.

4. Next, you need to specify to which GPIO or GPIOs the signal will appear upon. For that you’ll use the following function:

ledcAttachPin(GPIO, channel)
This function accepts two arguments. The first is the GPIO
that will output the signal, and the second is the channel that will generate the signal.

5. Finally, to control the LED brightness using PWM,
you use the following function:

ledcWrite(channel, dutycycle)
This function accepts as arguments the channel that is generating the PWM signal,
and the duty cycle.
*/
#define red_pin 13
#define green_pin 12
#define blue_pin 14

#define R_value 255
#define G_value 255
#define B_value 0

void setup() 
{
  // assign RGB led pins to channels
  ledcAttachPin(red_pin, 1); 
  ledcAttachPin(green_pin, 2);
  ledcAttachPin(blue_pin, 3);
  
  // Initialize channels 
  // channels 0-15, resolution 1-16 bits, freq limits depend on resolution
  // ledcSetup(uint8_t channel, uint32_t freq, uint8_t resolution_bits);
  ledcSetup(1, 12000, 8); // 12 kHz PWM, 8-bit resolution
  ledcSetup(2, 12000, 8);
  ledcSetup(3, 12000, 8);

  ledcWrite(1, 255 - R_value);
  ledcWrite(2, 255 - green_pin);
  ledcWrite(3, 255 - B_value);
 
}

void loop() 
{
  
}
