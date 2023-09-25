#include <MPU6050_tockn.h>
#include <Wire.h>
#define XLED 13
#define YLED 12
MPU6050 mpu6050(Wire);

long timer = 0;

void setup() {

  pinMode(XLED, OUTPUT);
  pinMode(YLED, OUTPUT);

  digitalWrite(XLED, HIGH);
  digitalWrite(YLED, HIGH);

  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();

}

void loop() {
  mpu6050.update();

  //Serial.print("accX : ");Serial.print(mpu6050.getAccX());
  //Serial.print("\taccY : ");Serial.println(mpu6050.getAccY());
  //Serial.print("\taccZ : ");Serial.println(mpu6050.getAccZ());

  if (mpu6050.getAccX() >= 0.70) {      //RIGHT
    digitalWrite(XLED, HIGH);
    Serial.println("RIGHT");
  }
  else if (mpu6050.getAccX() <= -0.60) {     //LEFT
    digitalWrite(XLED, LOW);
    Serial.println("LEFT");
  }
  else if (mpu6050.getAccY() <= -0.60) {    //UP
    digitalWrite(YLED, HIGH);
    Serial.println("UP");
  }
  else if (mpu6050.getAccY() >= 0.60) {    //DOWN
    digitalWrite(YLED, LOW);
    Serial.println("DOWN");
  }
  else
  {
    //digitalWrite(XLED, LOW);
    //digitalWrite(YLED, HIGH);
    Serial.println("NO SIDE");
  }
}
