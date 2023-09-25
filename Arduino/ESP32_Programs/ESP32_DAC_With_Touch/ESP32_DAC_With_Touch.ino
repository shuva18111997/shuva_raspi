/*
* LAB Name: ESP32 Audio Music With DAC Example
* Author: Khaled Magdy
* DeepBlueMbedded 2023
* For More Info Visit: www.DeepBlueMbedded.com
*/
 
#include <driver/dac.h>
 
// Define The TouchPAD Pins (You Can Add More Or Less)
#define TOUCHPAD_1 12
#define TOUCHPAD_2 13
#define TOUCHPAD_3 14
#define TOUCHPAD_4 15
 
// Define The Touch Threshold Value For Your TouchPADs
#define TOUCH_THR 20
 
// Array To Hold TouchPADs Readings (4 TouchPADs)
int TOUCHPAD_Values[4] = {0};
 
// Timer0 Configuration Pointer (Handle)
hw_timer_t *Timer0_Cfg = NULL;
 
// Variable To Control The TMR0 Auto-Reload Register Value In Order To Change The TimerInterrupt Interval
// Which Enable Us To Control The Output WaveForm's Frequency
uint64_t TMR0_ARR_Val = 10;
 
// Sine LookUpTable & Index Variable
uint8_t SampleIdx = 0;
const uint8_t sineLookupTable[100] = {
128, 136, 143, 151, 159, 167, 174, 182,
189, 196, 202, 209, 215, 220, 226, 231,
235, 239, 243, 246, 249, 251, 253, 254,
255, 255, 255, 254, 253, 251, 249, 246,
243, 239, 235, 231, 226, 220, 215, 209,
202, 196, 189, 182, 174, 167, 159, 151,
143, 136, 128, 119, 112, 104, 96, 88,
81, 73, 66, 59, 53, 46, 40, 35,
29, 24, 20, 16, 12, 9, 6, 4,
2, 1, 0, 0, 0, 1, 2, 4,
6, 9, 12, 16, 20, 24, 29, 35,
40, 46, 53, 59, 66, 73, 81, 88,
96, 104, 112, 119};
 
// The Timer0 ISR Function (Executes Every Timer0 Interrupt Interval)
void IRAM_ATTR Timer0_ISR()
{
  // Send SineTable Values To DAC One By One
  dac_output_voltage(DAC_CHANNEL_1, sineLookupTable[SampleIdx++]);
  if(SampleIdx == 100)
  {
    SampleIdx = 0;
  }
}
 
void setup()
{
  // Configure Timer0 Interrupt
  Timer0_Cfg = timerBegin(0, 80, true);
  timerAttachInterrupt(Timer0_Cfg, &Timer0_ISR, true);
  timerAlarmWrite(Timer0_Cfg, TMR0_ARR_Val, true);
  timerAlarmEnable(Timer0_Cfg);
  // Disable DAC1 Channel's Output
  dac_output_disable(DAC_CHANNEL_1);
}
 
void loop()
{
  // Read The Touch PADs
  TOUCHPAD_Values[0] = touchRead(TOUCHPAD_1);
  TOUCHPAD_Values[1] = touchRead(TOUCHPAD_2);
  TOUCHPAD_Values[2] = touchRead(TOUCHPAD_3);
  TOUCHPAD_Values[3] = touchRead(TOUCHPAD_4);
 
  if(TOUCHPAD_Values[0] < TOUCH_THR)  // Play 200Hz Tone
  {
    TMR0_ARR_Val = 50;
    dac_output_enable(DAC_CHANNEL_1);
  }
  else if(TOUCHPAD_Values[1] < TOUCH_THR) // Play 500Hz Tone
  {
    TMR0_ARR_Val = 20;
    dac_output_enable(DAC_CHANNEL_1);
  }
  else if(TOUCHPAD_Values[2] < TOUCH_THR) // Play 1000Hz Tone
  {
    TMR0_ARR_Val = 10;
    dac_output_enable(DAC_CHANNEL_1);
  }
  else if(TOUCHPAD_Values[3] < TOUCH_THR)  // Play 1428Hz Tone
  {
    TMR0_ARR_Val = 7;
    dac_output_enable(DAC_CHANNEL_1);
  }
  else
  {
    dac_output_disable(DAC_CHANNEL_1);
  }
  // Update The Timer Interrupt Interval According To The Desired Tone
  timerAlarmWrite(Timer0_Cfg, TMR0_ARR_Val, true);
}
