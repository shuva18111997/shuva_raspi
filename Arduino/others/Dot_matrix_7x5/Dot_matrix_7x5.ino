int row[7]={13,12,11,10,9,8,7};  //data Lines(data 1)
int column[5]={6,5,4,3,2};  //select Lines(select 0)
void setup() {
for(int i=0;i<=7;i++){
  pinMode(row[i],OUTPUT);
  digitalWrite(row[i],0);
  
}
for(int i=0;i<=5;i++){
  pinMode(column[i],OUTPUT);
  digitalWrite(column[i],1);
}
}

void loop() {
for(int i=0;i<5;i++){
  digitalWrite(column[i],0);
  selectLine(i);
  delay(4);
  digitalWrite(column[i],1);
}
}
