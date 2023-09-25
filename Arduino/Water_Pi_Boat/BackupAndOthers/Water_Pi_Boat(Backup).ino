#include<Servo.h>
Servo servo;
#define ServoPin 5

#define RGB_red 10  //pwm
#define RGB_green 6 //pwm
#define RGB_blue 9  //pwm

#define NRF_CE 8  //digital output
#define NRF_CSN 7 //digital output

#define BLE_or_NRF 2  //digital input

#define Motor_Control 3 //pwm

#define servo_pin 5

#define Battery_Voltage_Measure A0  //analog input


void setup() {
  pinMode(RGB_red, OUTPUT);
  pinMode(RGB_green, OUTPUT);
  pinMode(RGB_blue, OUTPUT);
  pinMode(Motor_Control, OUTPUT);
  digitalWrite(Motor_Control, HIGH);
}

void loop() {
  servo.attach(ServoPin);
  servo.write(0);
  delay(500);
  servo.detach();
  digitalWrite(RGB_red, LOW);
  digitalWrite(RGB_green, HIGH);
  digitalWrite(RGB_blue, HIGH);
  delay(3000);
  servo.attach(ServoPin);
  servo.write(90);
  delay(500);
  servo.detach();
  digitalWrite(RGB_red, HIGH);
  digitalWrite(RGB_green, LOW);
  digitalWrite(RGB_blue, HIGH);
  delay(3000);
  servo.attach(ServoPin);
  servo.write(180);
  delay(500);
  servo.detach();
  digitalWrite(RGB_red, HIGH);
  digitalWrite(RGB_green, HIGH);
  digitalWrite(RGB_blue, LOW);
  delay(3000);
}
