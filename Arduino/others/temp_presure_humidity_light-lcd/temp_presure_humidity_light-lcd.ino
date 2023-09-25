#include <dht11.h>
dht11 DHT;
#define DHT11_PIN A0
// Connect SCL to Analog 5
// Connect SDA to Analog 4
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
#include <Wire.h>
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;
void setup(){
  lcd.begin(16,2);
 Serial.begin(9600);
  if (!bmp.begin()) {
 Serial.println("Could not find a valid BMP085 sensor, check wiring!");
  while (1) {}
  } 
}

void loop(){
  int chk;
  int sensorValue = analogRead(A1);
 double dV = sensorValue;
 double le = (dV/1023)*100;
 int level = le;
   
 { chk = DHT.read(DHT11_PIN);   
  lcd.setCursor(0,0);
  lcd.print("HUMIDITY = ");
  lcd.print(DHT.humidity,1);
  lcd.print("%");
   lcd.setCursor(0,1);
   lcd.print("Temp = ");
    lcd.print(DHT.temperature,1);
    lcd.println(" *C        ");}
    delay(2000);
    
     {lcd.setCursor(0,0);
     lcd.clear();
    lcd.print("Presur= ");
    lcd.print(bmp.readPressure());
    lcd.println("Pa  ");
    Serial.print("Pressure= ");
    Serial.print(bmp.readPressure());
    Serial.println("Pa"); 
 
 lcd.setCursor(0,1);
 lcd.print("LIGHT LEVEL:");
 lcd.print(level);
 lcd.print("%");}
 delay(2000);
 lcd.clear();
    
}

    


