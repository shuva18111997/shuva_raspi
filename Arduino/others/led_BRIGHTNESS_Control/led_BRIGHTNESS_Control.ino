int led =9;
int brightness =0;
int fadeamount =5;
void setup()
{Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(A0,INPUT);
  
}
void loop()
{
  analogWrite(led,brightness);
  brightness =analogRead(A0);
 { Serial.println(brightness);
  delay(500);}
}
