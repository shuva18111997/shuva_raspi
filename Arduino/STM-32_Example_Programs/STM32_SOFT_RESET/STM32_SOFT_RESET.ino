void setup() {
  Serial.begin(9600);
  Serial.print("Welcome...");
  delay(3000);
  Serial.print("Going to Reset.\nBye Bye**");
  nvic_sys_reset();  //RESET The controller.
}

void loop() {
  // put your main code here, to run repeatedly:

}
