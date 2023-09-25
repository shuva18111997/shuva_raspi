//when stm32 is program on usb bootloader.
//The Serial -> is use for usb print.
//The Serial1 -> is use for (PA_10 & PA_9) print.
//The Serial2 -> is use for (PA_3 & PA_2) print.
//The Serial3 -> is use for (PB_11 & PB_10) print.
//if stm32 is program on serial then Serial3 will not work.It gives an error.
void setup() {
Serial.begin(9600);
Serial1.begin(9600);
Serial2.begin(9600);
Serial3.begin(9600);
}

void loop() {
Serial.println("shuva");
Serial1.println("shuva");
Serial2.println("shuva");
Serial3.println("shuva");
}
