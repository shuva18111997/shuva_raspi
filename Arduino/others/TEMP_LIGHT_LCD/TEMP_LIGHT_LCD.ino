#include<LiquidCrystal.h>
#include<math.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
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
void setup() {{ //initialise for at least 2s
  lcd.begin(16, 2);
  lcd.print("INITIALISING");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");  
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");  
  delay(500);
}
  

}

void loop() {{             
  int valF, valC;                
  double tempF, tempC;            
  valF=analogRead(0);      
  tempF=ThermistorF(valF);   
  valC=analogRead(0);      
  tempC=ThermistorC(valC); 
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEMP= ");
  lcd.print(tempC);
  lcd.print(" C");
  lcd.setCursor(0,6);
  lcd.print("TEMP= ");
  lcd.print(tempF);
  lcd.print(" F");
   
  delay(2000);            
}
{
 int sensorValue = analogRead(A1);
 double dV = sensorValue;
 double le = (dV/1023)*100;
 int level = le;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("LIGHT LEVEL:");
 lcd.print(level);
 lcd.print("%");
 lcd.setCursor(0, 1);
  
 if ((level >= 0) && (level <= 5))
 {
  lcd.print("DARK"); 
 }
 else if ((level > 5) && (level <= 20))
 {
  lcd.print("DIM"); 
 }
 else if ((level > 20) && (level <= 30))
 {
  lcd.print("LIGHT");
 } 
 else if ((level > 30) && (level <= 50))
 {
  lcd.print("BRIGHT"); 
 }
 else
 {
  lcd.print("VERY BRIGHT"); 
 }
  
 delay(2000); 
}}

 
