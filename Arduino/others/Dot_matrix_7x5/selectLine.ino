void selectLine(int i)
{ 
  if(i==0){
   for(int a=0;a<7;a++){
    digitalWrite(row[a],data0[a]);
    }
  }
  if(i==1){
   for(int a=0;a<7;a++){
    digitalWrite(row[a],data1[a]);
    }
  }
  if(i==2){
   for(int a=0;a<7;a++){
    digitalWrite(row[a],data2[a]);
    }
  }
  if(i==3){
   for(int a=0;a<7;a++){
    digitalWrite(row[a],data3[a]);
    }
  }
  if(i==4){
   for(int a=0;a<7;a++){
    digitalWrite(row[a],data4[a]);
    }
  }
}

