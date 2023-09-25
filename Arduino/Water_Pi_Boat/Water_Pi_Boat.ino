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

char ch = 0;
#define Start 1
#define Stop 0
bool Motor_Status = Stop;

#define M 90
#define L 0
#define R 180
int Servo_Status = M;

void setup() {
  Serial.begin(9600);
  pinMode(RGB_red, OUTPUT);
  pinMode(RGB_green, OUTPUT);
  pinMode(RGB_blue, OUTPUT);
  pinMode(Motor_Control, OUTPUT);
}

void loop() {
  if (Serial.available())
  {
    ch = Serial.read();
    if (ch == 'A')
    {
      Font();
    }
    else if (ch == 'C')
    {
      Left();
    }
    else if (ch == 'B')
    {
      Right();
    }
    else
    {
      StopAll();
    }
    //ch = 0;
  }
  else
  {
    if (Motor_Status == Start)
    {
      digitalWrite(Motor_Control, LOW);
      Motor_Status = Stop;
    }
    if (Servo_Status != M)
    {
      servo.attach(ServoPin);
      servo.write(M);
      delay(500);
      servo.detach();
      Servo_Status = M;
    }
    digitalWrite(RGB_red, LOW);
    digitalWrite(RGB_green, HIGH);
    digitalWrite(RGB_blue, HIGH);
    delay(1000);
    digitalWrite(RGB_red, HIGH);
    digitalWrite(RGB_green, LOW);
    digitalWrite(RGB_blue, HIGH);
    delay(1000);
    digitalWrite(RGB_red, HIGH);
    digitalWrite(RGB_green, HIGH);
    digitalWrite(RGB_blue, LOW);
    delay(1000);
  }
}
void Font()
{
  if (Motor_Status == Stop)
  {
    digitalWrite(Motor_Control, HIGH);
    Motor_Status = Start;
    digitalWrite(RGB_red, LOW);
    digitalWrite(RGB_green, HIGH);
    digitalWrite(RGB_blue, HIGH);
  }
  if (Servo_Status != M)
  {
    servo.attach(ServoPin);
    servo.write(M);
    delay(500);
    servo.detach();
    Servo_Status = M;
  }
}
void Left()
{
  if (Motor_Status == Stop)
  {
    digitalWrite(Motor_Control, HIGH);
    Motor_Status = Start;
    digitalWrite(RGB_red, HIGH);
    digitalWrite(RGB_green, LOW);
    digitalWrite(RGB_blue, HIGH);
  }
  if (Servo_Status != L)
  {
    servo.attach(ServoPin);
    servo.write(L);
    delay(500);
    servo.detach();
    Servo_Status = L;
  }
}
void Right()
{
  if (Motor_Status == Stop)
  {
    digitalWrite(Motor_Control, HIGH);
    Motor_Status = Start;
    digitalWrite(RGB_red, HIGH);
    digitalWrite(RGB_green, HIGH);
    digitalWrite(RGB_blue, LOW);
  }
  if (Servo_Status != R)
  {
    servo.attach(ServoPin);
    servo.write(R);
    delay(500);
    servo.detach();
    Servo_Status = R;
  }
}
void StopAll()
{
  if (Motor_Status == Start)
  {
    digitalWrite(Motor_Control, LOW);
    Motor_Status = Stop;
    digitalWrite(RGB_red, HIGH);
    digitalWrite(RGB_green, LOW);
    digitalWrite(RGB_blue, LOW);
  }
  if (Servo_Status != M)
  {
    servo.attach(ServoPin);
    servo.write(M);
    delay(500);
    servo.detach();
    Servo_Status = M;
  }
}
