int ledpin=13;
char state=0;
int flag=0;

void setup()
{
  pinMode(ledpin,OUTPUT);
  digitalWrite(ledpin,LOW);
  Serial.begin(9600);
}

void loop()
{
 if(Serial.available()>0)
 {
  state=Serial.read();
 
  Serial.write(state);
  flag=0;  
 }
if(state == '0'){
  digitalWrite(ledpin,LOW);
  if(flag==0)
  {
 
    flag =1;
  }
}
else if(state=='1'){
  digitalWrite(ledpin,HIGH);

  flag=1;
}
}
