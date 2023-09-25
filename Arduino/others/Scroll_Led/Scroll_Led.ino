#include "Display_char.h"
#include <PS2Keyboard.h>

#define DataPin 2
#define IRQpin  3
PS2Keyboard keyboard;
/*Please Write Here The Display Size*/
#define coloumn 16
/*---------FOR ROW-----------*/
#define SclockPin 11
#define SdataPin 10

/*---------FOR COLOUMN-----------*/
#define clockPin 13
#define dataPin 12
#define latchPin 8

/*******PLease Enter The Charecter Shift Time******/
#define ShiftTime 70
/**************************************************/
char total[24];
int count = 0;
int value = 0;
char T[100];
int c = 0;
void setup() {
  Serial.begin(9600);
  keyboard.begin(DataPin, IRQpin);

  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  pinMode(SclockPin, OUTPUT);
  pinMode(SdataPin, OUTPUT);

  refresh();
}
void(* resetFunc) (void) = 0;
void loop()
{
  Readstring();
}
