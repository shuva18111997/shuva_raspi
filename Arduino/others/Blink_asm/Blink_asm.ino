/*Delay using Assembly language of Arduino.
 * the ports of arduino are 8bits so we declare the ports alose B(xxxxxxxx)8 bits.
 * DDR means which are the input or which are the output pins of that partucular port.
 * 0 means INPUT pin And 1 means OUTPUT pin.
 * available ports are B,C,D.All are 8 bits port.
 * B=(Digital pin 8-13), C=(Analog pins) , D=(Digital pin 0-7)
 * PORT means declare the bit High or Low.
 */
void setup() {                
    DDRB = B100000 ;   //declare INPUT or OUTPUT pin '0' means INPUT and '1' means OUTPUT pin
   // DDRB = DDRB | B00100000;
    //PORTD = B10000000;

}


void loop() {
  
  PORTB = B100000;    //declare HIGH or LOW
  delay(1000); 
  PORTB = B00000;     //declare HIGH or LOW
  delay(1000);       
}

