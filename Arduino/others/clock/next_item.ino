void nextItem()
{
  static unsigned long lastInterruptTime = 0;
  unsigned long interruptTime = millis();

  if (interruptTime - lastInterruptTime > 200)
  {
   menuCounter++; 
   myMenu[menuCounter] = counterVal;
   counterVal = 0;
   }
  lastInterruptTime = interruptTime;
}
