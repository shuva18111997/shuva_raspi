//Simple sketch by Eli Glass 7-3-13
//Simple led on/off with moiton sensor program
//Ok we need to declare the variables and pins.
//i have no variables but need to declare the pin the
//led is plugged into and the pin the motion sensor is on
//change the pin number to match what pins you use on your arduino
int motion = A0;
int motionLed = 13;

void setup() {
//ok i need to state what each pin will be doing. the led pin will
//be an output and the motion pin will be an input.
  pinMode(motion, INPUT);
  pinMode(motionLed, OUTPUT);
}

void loop()
{
  //what will happen in the sketch
  //if motion is detected we want to turn the led light on
  //if no motion is detected turn the led off
  //you also need to declare a variable to hold the sensor data
  long sensor = digitalRead(motion);
  //then the if statement to control the led
  if(sensor == HIGH){
     digitalWrite (motionLed, HIGH);
   }
   else
   {
      digitalWrite (motionLed, LOW);
   }
  
}

