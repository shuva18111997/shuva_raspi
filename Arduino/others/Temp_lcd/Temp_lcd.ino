#include <math.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);   //defining lcd pins

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

void setup() {
 lcd.begin(16,2);
}

void loop() {             
  int valF, valC;                
  double tempF, tempC;            
  valF=analogRead(0);      
  tempF=ThermistorF(valF);   
  valC=analogRead(0);      
  tempC=ThermistorC(valC); 
  
 
  lcd.setCursor(0,0);
  lcd.print("TEMP= ");
  lcd.print(tempC);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("TEMP= ");
  lcd.print(tempF);
  lcd.print(" F");
  delay(1000);            
}

