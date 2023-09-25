#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
  //mySwitch.enableReceive(PB12); //for STM32 interrupt pin on #PB12
}

void loop() {
  if (mySwitch.available()) {
    
    Serial.print("Received ");
    Serial.println( mySwitch.getReceivedValue() );

    mySwitch.resetAvailable();
  }
}
