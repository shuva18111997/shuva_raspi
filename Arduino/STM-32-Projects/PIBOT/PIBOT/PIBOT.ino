#include <ShiftLCD.h>
#include <QMC5883L.h>
#include <EEPROM.h>
#include <SPI.h>
#include<Wire.h>
#include <nRF24L01-STM.h>
#include <RF24-STM.h>

QMC5883L compass;
#define QMC5883L_Address 0xD

#define Eaddr 0x50
uint16_t EData;

#define pipeIn 0x5124568 //IMPORTANT: The same as in the transmitter

#define NRF_CE_pin PA4
#define NRF_CSN_pin PC15

#define LED_pin PC13
#define BUZZ_pin PC14

#define btn1  PB4 //UP
#define btn2  PA15  //DOWN
#define btn3  PB3 //LEFT
#define btn4  PB5 //RIGHT

#define IN1 PB0  //PWM
#define IN2 PB8 //PWM
#define IN3 PB1  //PWM
#define IN4 PB9 //PWM

#define trigPin PA13
#define echoPin PA14

#define BLE_Status PA8

int D_bit[8] = {PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7};
bool D[8];

#define Clock  PB13
#define latch  PB14
#define data  PB15

#define LCD_latch PC14

ShiftLCD lcd(data, Clock, LCD_latch); //(Data,Clock,Latch)

volatile int count = 0;
volatile int preCount = 0;
volatile int mode = 0;
volatile int preMode = 0;
volatile int cnt = 0;
volatile int preCnt = 0;
volatile bool UD_cnt = false;
volatile bool preUD_cnt = false;
bool btn1St = true, btn2St = true, btn3St = true, btn4St = true;

bool Change_Mode = false;
bool Select_Mode = false;

bool BLE_EN = false;
bool WiFi_EN = false;
bool NRF_EN = false;
bool RF_EN = false;
bool LINE_FOLLOWER_EN = false;

int Motor_Speed = 250;
bool Self_Rotation = false;
bool R1 = true, R2 = true, R3 = true, R4 = true;

bool _FState = false;
int _FAng;
int _PWM1, _PWM2;
int Data = B00000000; //from LSB:- Bit_1 = BLE, Bit_2 = WiFi, Bit_3 = IR, Bit_4 = BUZZER(+), Bit_5 = RF, Bit_6 = LINE_FOLLOWER, Bit_7 = BUZZER(+)

void setup() {
  Serial.begin(9600);
  pinMode(LED_pin, OUTPUT);
  Init();
  Init_mode_Check();
}

void loop() {
  if (count == 0)
  {
    if (!Change_Mode)
    {
      LINE_FOLLOWER_CHANGE();
      BLE_setup();
      WiFi_CHANGE();
    }
  }
  else if (count == 1)
  {
    if (!Change_Mode)
    {
      BLE_CHANGE();
      WiFi_setup();
      NRF_CHANGE();
    }
  }
  else if (count == 2)
  {
    if (!Change_Mode)
    {
      WiFi_CHANGE();
      NRF_setup();
      RF_CHANGE();
    }
  }
  else if (count == 3)
  {
    if (!Change_Mode)
    {
      NRF_CHANGE();
      RF_setup();
      LINE_FOLLOWER_CHANGE();
    }
  }
  else if (count == 4)
  {
    if (!Change_Mode)
    {
      RF_CHANGE();
      LINE_FOLLOWER_setup();
      BLE_CHANGE();
    }
  }
  //FOR BUZZER
  if (count != preCount)
  {
    BUZZ_CTRL("ON");
    delay(40);
    BUZZ_CTRL("OFF");
    preCount = count;
  }
  if (mode != preMode)
  {
    BUZZ_CTRL("ON");
    delay(40);
    BUZZ_CTRL("OFF");
    preMode = mode;
  }
  delay(100);
}
