#include <math.h>

double ThermistorC(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;          
 return Temp;
}

double ThermistorF(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;          
 Temp = (Temp * 9.0)/ 5.0 + 32.0; 
 return Temp;
}


void setup() {
 Serial.begin(9600);
}

void loop() {             
  int valF, valC;                
  double tempF, tempC;            
  valF=analogRead(0);      
  tempF=ThermistorF(valF);   
  valC=analogRead(0);      
  tempC=ThermistorC(valC); 
  
  Serial.print("Temperature = ");
  Serial.print(tempF);   
  Serial.print(" F; ");
  Serial.print(tempC);   
  Serial.println(" C");
  delay(1000);            
}

