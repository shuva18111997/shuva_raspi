#include <Wire_slave.h>
#include <USBComposite.h>
#include "MPU6050_Lib.h"
#define XLED PB10
#define YLED PC14

accel_t_gyro_union accel_t_gyro;

void setup()
{
  int error;
  uint8_t c;

  pinMode(XLED, OUTPUT);
  pinMode(YLED, OUTPUT);

  Serial.begin(9600);
  USBHID_begin_with_serial(HID_KEYBOARD);
  Keyboard.begin();
  Wire.begin();

  digitalWrite(XLED, HIGH);
  digitalWrite(YLED, HIGH);

  error = MPU6050_read (MPU6050_WHO_AM_I, &c, 1);
  Serial.print(F("WHO_AM_I : "));
  Serial.print(c, HEX);
  Serial.print(F(", error = "));
  Serial.println(error, DEC);

  // According to the datasheet, the 'sleep' bit
  // should read a '1'.
  // That bit has to be cleared, since the sensor
  // is in sleep mode at power-up.
  error = MPU6050_read (MPU6050_PWR_MGMT_1, &c, 1);
  Serial.print(F("PWR_MGMT_1 : "));
  Serial.print(c, HEX);
  Serial.print(F(", error = "));
  Serial.println(error, DEC);


  // Clear the 'sleep' bit to start the sensor.
  MPU6050_write_reg (MPU6050_PWR_MGMT_1, 0);
  delay(2000);
}

void Error()
{
  int error;
  error = MPU6050_read (MPU6050_ACCEL_XOUT_H, (uint8_t *) &accel_t_gyro, sizeof(accel_t_gyro));
  uint8_t swap;
#define SWAP(x,y) swap = x; x = y; y = swap

  SWAP (accel_t_gyro.reg.x_accel_h, accel_t_gyro.reg.x_accel_l);
  SWAP (accel_t_gyro.reg.y_accel_h, accel_t_gyro.reg.y_accel_l);
  SWAP (accel_t_gyro.reg.z_accel_h, accel_t_gyro.reg.z_accel_l);
}

void print()
{
  Serial.println(F(""));
  Serial.println(F("MPU-6050"));
  Serial.print(F("accel x,y,z: "));
  Serial.print(accel_t_gyro.value.x_accel / 1000, DEC);
  Serial.print(F(", "));
  Serial.print(accel_t_gyro.value.y_accel / 1000, DEC);
  Serial.print(F(", "));
  Serial.print(accel_t_gyro.value.z_accel / 1000, DEC);
  Serial.println(F(""));
}

void printSide()
{
  int x, y, z;
  x = accel_t_gyro.value.x_accel / 1000;
  y = accel_t_gyro.value.y_accel / 1000;
  z = accel_t_gyro.value.z_accel / 1000;
  if (x >= 10)
  {
    Serial.println("UP");
    digitalWrite(XLED, HIGH);
    Keyboard.print("w");
  }
  else if (x <= -10)
  {
    Serial.println("DOWN");
    digitalWrite(XLED, LOW);
    Keyboard.print("s");
  }
  else if (y >= 10)
  {
    Serial.println("RIGHT");
    digitalWrite(YLED, HIGH);
    Keyboard.print("w");
    Keyboard.print("d");
  }
  else if (y <= -10)
  {
    Serial.println("LEFT");
    digitalWrite(YLED, LOW);
    Keyboard.print("w");
    Keyboard.print("a");
  }
  else if (z >= 10)
  {
    Serial.println("No side");
  }
  else if (x == 0 && y == 0 && z == 0)
  {
    Serial.println("Something is wrong");
  }
}

void loop()
{
  Error();
  //print();
  printSide();
  delay(100);
}
