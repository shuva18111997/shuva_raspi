#include <Wire_slave.h>
#include "MPU6050_Lib.h"
#define XLED PB10
#define YLED PC14

accel_t_gyro_union accel_t_gyro;

void setup()
{
  int error;
  uint8_t c;

  Serial.begin(9600); pinMode(XLED, OUTPUT);
  pinMode(YLED, OUTPUT);

  digitalWrite(XLED, HIGH);
  digitalWrite(YLED, HIGH);

  // Initialize the 'Wire' class for the I2C-bus.
  Wire.begin();


  // default at power-up:
  //    Gyro at 250 degrees second
  //    Acceleration at 2g
  //    Clock source at internal 8MHz
  //    The device is in sleep mode.
  //

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
  }
  else if (x <= -10)
  {
    Serial.println("DOWN");
    digitalWrite(XLED, LOW);
  }
  else if (y >= 10)
  {
    Serial.println("RIGHT");
    digitalWrite(YLED, HIGH);
  }
  else if (y <= -10)
  {
    Serial.println("LEFT");
    digitalWrite(YLED, LOW);
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
}
