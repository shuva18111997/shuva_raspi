int btnSet=0;
int togBtnSet=false;
int counter=0;
void setup() {
Serial.begin(9600);
attachInterrupt(btnSet, increaseValue, RISING);
}

void increaseValue(){
static unsigned long lastInterruptTime = 0;
unsigned long interruptTime = millis();
   if (interruptTime - lastInterruptTime > 100)//ekhane 100ms er com somoy er age jodi button press kora hoy
                                               //tahole counter er value barbe na.
  {
    // Toggle the variable
    togBtnSet = !togBtnSet;//eta kono kaje lag6e na
    // Increase the counterVal by 1
    counter++;
  }
  // Setting lastInterruptTime equal to the timestamp
  // so we know we moved on
  lastInterruptTime = interruptTime;
Serial.println(counter);
if(counter==12){
  counter=0;
}
}
void loop(){
 }
