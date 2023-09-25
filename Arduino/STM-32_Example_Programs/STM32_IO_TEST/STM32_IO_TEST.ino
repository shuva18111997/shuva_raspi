//int led[15] = {PC13, PC14, PC15, PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PB0, PB1, PB10, PB11};
int led[17] = {PB9, PB8, PB7, PB6, PB5, PB4, PB3, PA15, PA12, PA11, PA10, PA9, PA8, PB15, PB14, PB13, PB12};
void setup() {
  afio_cfg_debug_ports(AFIO_DEBUG_NONE);  //Eta use kore PB4,PB3,PB15 er sommosa mite6e.
  for (int i = 0; i < 15; i++)
    pinMode(led[i], OUTPUT);
}

void loop() {
  for (int i = 0; i < 15; i++)
    digitalWrite(led[i], 1);
  delay(500);
  for (int i = 0; i < 15; i++)
    digitalWrite(led[i], 0);
  delay(500);
}
/***********************************LED Test*******************************************/
//[LEFT]ALL_OK = PC13, PC14, PC15, PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PB0, PB1, PB10, PB11
//[RIGHT]ALL_OK = PB9, PB8, PB7, PB6, PB5, PB4, PB3, PA15, PA12, PA11, PA10, PA9, PA8, PB15, PB14
//problem = PB4(Halka jole ache)
//problem = PB3(akdom nive ache)
//problem = PA15(Halka jole ache)
//problem = PB13 , PB12(akdom nive ache)
/***************************************************************************************/

