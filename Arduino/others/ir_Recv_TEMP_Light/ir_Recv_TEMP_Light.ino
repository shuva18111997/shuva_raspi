#include <IRremote.h>
#include<math.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
double ThermistorF(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;          
 Temp = (Temp * 9.0)/ 5.0 + 32.0; 
 return Temp;
}

double ThermistorC(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;          
 return Temp;
}
int RECV_PIN = A2;
int led1 =13;
int led2 =12;
int led3 =11;
int led4 =10;
int led5 =10;
int ledState[] = {0,0,0,0,0};
IRrecv irrecv(RECV_PIN);

decode_results results;
#define code1 642546947

#define code2 33444015

#define code3 33478695

#define code4 761297281

#define code5 33486855

#define code6 -2014664387

#define code7 33446055

#define code8 757721508

#define code9 -183198237

#define code10 33441975

#define code11 -281335461

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
 
  pinMode(13 , OUTPUT);
  pinMode(12 , OUTPUT);
  pinMode(11 , OUTPUT);
  pinMode(10 , OUTPUT);
  pinMode(9 , OUTPUT);
  irrecv.enableIRIn(); 
  
  lcd.setCursor(0, 0);
  lcd.print("Light  Fan   TV ");
  
  lcd.setCursor(0, 1);
  lcd.print("OFF    OFF   OFF");
  
}

void loop(){
   int valF, valC;                
  double tempF, tempC;            
  valF=analogRead(0);      
  tempF=ThermistorF(valF);   
  valC=analogRead(0);      
  tempC=ThermistorC(valC); 
  int sensorValue = analogRead(A1);
 double dV = sensorValue;
 double le = (dV/1023)*100;
 int level = le;
   
  if (irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(decCode);
    
   
    switch (decCode){
    
      
      case code1:
        if (ledState[1] == 1) {
          digitalWrite(13, LOW);
         ledState[1]  = 0;
          lcd.setCursor(0, 1);
          lcd.print("OFF");
          
        } else {
          digitalWrite(13, HIGH);
          ledState[1]  = 1;
          lcd.setCursor(0, 1);
          lcd.print("ON     "); 
         
        }  break;
      case code2:
        if (ledState[1] == 1) {
          digitalWrite(13, LOW);
         ledState[1]  = 0;
         lcd.setCursor(0, 1);
          lcd.print("OFF"); 
          
        } else {
          digitalWrite(13, HIGH);
          ledState[1]  = 1;
          lcd.setCursor(0, 1);
          lcd.print("ON     ");
         
        }  
         break;
      case code3:
        if (ledState[2] == 1) {
          digitalWrite(12, LOW);
         ledState[2]  = 0;
         lcd.setCursor(7, 1);
          lcd.print("OFF"); 
          
        } else {
          digitalWrite(12, HIGH);
          ledState[2]  = 1;
           lcd.setCursor(7, 1);
          lcd.print("ON  ");
         
        }  break;
      case code4:
        if (ledState[2] == 1) {
          digitalWrite(12, LOW);
         ledState[2]  = 0;
          lcd.setCursor(7, 1);
          lcd.print("OFF");
          
        } else {
          digitalWrite(12, HIGH);
          ledState[2]  = 1;
           lcd.setCursor(7, 1);
          lcd.print("ON  ");
         
        }  
        break;
      case code5:
        if (ledState[3] == 1) {
          digitalWrite(11, LOW);
         ledState[3]  = 0;
          lcd.setCursor(13, 1);
          lcd.print("OFF");
          
        } else {
          digitalWrite(11, HIGH);
          ledState[3]  = 1;
          lcd.setCursor(13, 1);
          lcd.print("ON    ");
         
        }  break;
      case code6:
        if (ledState[3] == 1) {
          digitalWrite(11, LOW);
         ledState[3]  = 0;
          lcd.setCursor(13, 1);
          lcd.print("OFF");
          
        } else {
          digitalWrite(11, HIGH);
          ledState[3]  = 1;
          lcd.setCursor(13, 1);
          lcd.print("ON    ");
         
        }  
        break;
      case code7:
        if (ledState[4] == 1) {
          digitalWrite(10, LOW);
         ledState[4]  = 0;
  lcd.clear();       
  lcd.setCursor(0,0);
  lcd.print("TEMP= ");
  lcd.print(tempC);
  lcd.print(" C");
 lcd.setCursor(0,1);
 lcd.print("LIGHT LEVEL:");
 lcd.print(level);
 lcd.print("%");
 delay(5000);
 lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Light  Fan   TV "); 
 if (ledState[1] == 1) {
   lcd.setCursor(0, 1);
          lcd.print("ON     ");
 }
  else {
  lcd.setCursor(0, 1);
          lcd.print("OFF     "); 
  }
if (ledState[2] == 1) {
  lcd.setCursor(7, 1);
  lcd.print("ON  "); 
} else {
  lcd.setCursor(7, 1);
          lcd.print("OFF"); 
  
}
 if (ledState[3] == 1) {
    lcd.setCursor(13, 1);
          lcd.print("ON    ");
 } else {
  lcd.setCursor(13, 1);
          lcd.print("OFF");
 }

         
        } else {
          digitalWrite(10, HIGH);
          ledState[4]  = 1;
         lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Light  Fan   TV "); 
 if (ledState[1] == 1) {
   lcd.setCursor(0, 1);
          lcd.print("ON     ");
 }
  else {
  lcd.setCursor(0, 1);
          lcd.print("OFF     "); 
  }
if (ledState[2] == 1) {
  lcd.setCursor(7, 1);
  lcd.print("ON  "); 
} else {
  lcd.setCursor(7, 1);
          lcd.print("OFF"); 
  
}
 if (ledState[3] == 1) {
    lcd.setCursor(13, 1);
          lcd.print("ON    ");
 } else {
  lcd.setCursor(13, 1);
          lcd.print("OFF");
 }  
      
 
   
         
        }  
        break;
      case code8:
        if (ledState[4] == 1) {
          digitalWrite(10, LOW);
         ledState[4]  = 0;
          lcd.clear(); 
          lcd.setCursor(0,0);
  lcd.print("TEMP= ");
  lcd.print(tempC);
  lcd.print(" C");
 lcd.setCursor(0,1);
 lcd.print("LIGHT LEVEL:");
 lcd.print(level);
 lcd.print("%");
 delay(5000);
 lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Light  Fan   TV "); 
 if (ledState[1] == 1) {
   lcd.setCursor(0, 1);
          lcd.print("ON     ");
 }
  else {
  lcd.setCursor(0, 1);
          lcd.print("OFF     "); 
  }
if (ledState[2] == 1) {
  lcd.setCursor(7, 1);
  lcd.print("ON  "); 
} else {
  lcd.setCursor(7, 1);
          lcd.print("OFF"); 
  
}
 if (ledState[3] == 1) {
    lcd.setCursor(13, 1);
          lcd.print("ON    ");
 } else {
  lcd.setCursor(13, 1);
          lcd.print("OFF");
 }
    
          
        } else {
          digitalWrite(10, HIGH);
          ledState[4]  = 1;
      lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Light  Fan   TV "); 
 if (ledState[1] == 1) {
   lcd.setCursor(0, 1);
          lcd.print("ON     ");
 }
  else {
  lcd.setCursor(0, 1);
          lcd.print("OFF     "); 
  }
if (ledState[2] == 1) {
  lcd.setCursor(7, 1);
  lcd.print("ON  "); 
} else {
  lcd.setCursor(7, 1);
          lcd.print("OFF"); 
  
}
 if (ledState[3] == 1) {
    lcd.setCursor(13, 1);
          lcd.print("ON    ");
 } else {
  lcd.setCursor(13, 1);
          lcd.print("OFF");
 }
         
        }
        break;
        case code9:
        if (ledState[5] == 1) {
          digitalWrite(9, LOW);
         ledState[5]  = 0;
          
          
        } else {
          digitalWrite(9, HIGH);
          ledState[5]  = 1;
          
         
        }
break;
        case code10:
         if (ledState[1,2,3] ==1)
        { digitalWrite(13,LOW);
         digitalWrite(12,LOW);
         digitalWrite(11,LOW);
        ledState[1] = 0;
        ledState[2] = 0;
        ledState[3] = 0;
        lcd.setCursor(0,1);
        lcd.print("OFF    OFF   OFF");
        }
      else
    {  digitalWrite(13,HIGH);
         digitalWrite(12,HIGH);
         digitalWrite(11,HIGH);
        ledState[1] = 1;
        ledState[2] = 1;
        ledState[3] = 1;
    lcd.setCursor(0,1);
    lcd.print("ON     ON    ON ");
    }
      break;
        case code11:
         if (ledState[1,2,3] ==1)
        { digitalWrite(13,LOW);
         digitalWrite(12,LOW);
         digitalWrite(11,LOW);
        ledState[1] = 0;
        ledState[2] = 0;
        ledState[3] = 0;
        lcd.setCursor(0,1);
        lcd.print("OFF    OFF   OFF");
        }
      else
    {  digitalWrite(13,HIGH);
         digitalWrite(12,HIGH);
         digitalWrite(11,HIGH);
        ledState[1] = 1;
        ledState[2] = 1;
        ledState[3] = 1;
    lcd.setCursor(0,1);
    lcd.print("ON     ON    ON ");
    }
          
        
       
  }
  Serial.println(decCode);
  irrecv.resume();

}
   
}
 
