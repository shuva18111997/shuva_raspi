#include <Servo.h>
int fontled=13; //Red Led Connected
int leftled=12; //Blue Led Connected
int rightled=11; //Green Led Connected
char state=0; //for Bluetooth initial state
Servo myservo;

void setup(){
  myservo.attach(10); 
  pinMode(fontled,OUTPUT);
  pinMode(leftled,OUTPUT);
  pinMode(rightled,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
}

void loop(){
 if(Serial.available()>0){
  state=Serial.read();
  Serial.write(state);
 }


if(state == 'F'){ //boat goes front
  digitalWrite(fontled,HIGH);
  digitalWrite(leftled,LOW);
  digitalWrite(rightled,LOW);
//set Enable motor driver
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW); 
////////////////////////////////////////////////////
   myservo.write(90);     //servo position 90 degree        
    delay(15);   
}
else if(state=='L'){ //boat goes font left
  digitalWrite(fontled,HIGH);
  digitalWrite(leftled,HIGH);
  delay(200);
  digitalWrite(leftled,LOW);
  delay(200);
  digitalWrite(rightled,LOW);
//set Enable motor driver
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW); 
////////////////////////////////////////////////////
   myservo.write(128);    //servo position 128 degree           
    delay(15);   
}
else if(state=='R'){ //boat goes font right
  digitalWrite(fontled,HIGH);
 digitalWrite(rightled,HIGH);
 delay(200);
 digitalWrite(rightled,LOW);
 delay(200);
 digitalWrite(leftled,LOW);   
//set Enable motor driver
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW); 
////////////////////////////////////////////////////
   myservo.write(60);    //servo position 60 degree           
    delay(15);   
}
else if(state=='S'){ //boat goes stop
  //set Enable motor driver
    digitalWrite(7,LOW);
  digitalWrite(8,LOW); 
////////////////////////////////////////////////////
 myservo.write(90);         //servo position 90 degree
    delay(15);
    digitalWrite(rightled,HIGH);
    digitalWrite(fontled,LOW);  
    digitalWrite(leftled,LOW);  
    delay(500);
     digitalWrite(rightled,LOW);
    digitalWrite(fontled,HIGH);  
    digitalWrite(leftled,LOW);  
    delay(500);
     digitalWrite(rightled,LOW);
    digitalWrite(fontled,LOW);  
    digitalWrite(leftled,HIGH);  
    delay(500);
digitalWrite(rightled,LOW);
    digitalWrite(fontled,HIGH);  
    digitalWrite(leftled,LOW);  
    delay(500);
}
else if(state=='l'){ //boat goes back left
  digitalWrite(fontled,HIGH);
  digitalWrite(leftled,HIGH);
  digitalWrite(rightled,LOW);
//set Enable motor driver
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);  
////////////////////////////////////////////////////
   myservo.write(128);    //servo position 128 degree           
    delay(15);   
}
else if(state=='r'){ //boat goes back right
  digitalWrite(fontled,HIGH);
 digitalWrite(rightled,HIGH);
 digitalWrite(leftled,LOW);   
//set Enable motor driver
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);  
////////////////////////////////////////////////////
   myservo.write(60);    //servo position 45 degree           
    delay(15);   
}
if(state == 'b'){ //boat goes back
  digitalWrite(fontled,HIGH);
  digitalWrite(leftled,HIGH);
  digitalWrite(rightled,HIGH);
//set Enable motor driver
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);  
////////////////////////////////////////////////////
   myservo.write(90);     //servo position 90 degree        
    delay(15);   
}
}
