#define data_pin 2

void setup(){
  pinMode(data_pin, OUTPUT);
}

void loop(){
  
 
  rf_send('S');
  rf_send('H');
  rf_send('U');
  rf_send('V');
  rf_send('A');
  rf_send('#');
  delay(2000);
  //v++;
}

void rf_send(byte input){
  int i;
  
  for(i=0; i<20; i++){
  digitalWrite(data_pin, HIGH);
  delayMicroseconds(500);
  digitalWrite(data_pin, LOW);
  delayMicroseconds(500);
}

  digitalWrite(data_pin, HIGH);
  delayMicroseconds(3000);
  digitalWrite(data_pin, LOW);
  delayMicroseconds(500);
  
    
  for(i=0; i<8; i++){
  if(bitRead(input,i)==1)
  digitalWrite(data_pin, HIGH);
  else
  digitalWrite(data_pin, LOW);
  delayMicroseconds(500);
  
  if(bitRead(input,i)==1)
  digitalWrite(data_pin, LOW);
  else
  digitalWrite(data_pin, HIGH);
  delayMicroseconds(500);
}//i

  
  digitalWrite(data_pin, LOW);
}
