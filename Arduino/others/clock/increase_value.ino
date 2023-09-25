void increaseValue()
{
static unsigned long lastInterruptTime = 0;
unsigned long interruptTime = millis();
   if (interruptTime - lastInterruptTime > 200){
    counterVal++;
  }
   lastInterruptTime = interruptTime;
}
