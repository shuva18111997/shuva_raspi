void setup() {
  Serial.begin(9600);
  Serial.println("Going to restart after 5 sec...");
  delay(5000);
  hard_restart();
  //or
  ESP.restart();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void hard_restart()
{
  esp_task_wdt_init(1,true);
  esp_task_wdt_add(NULL);
  while(1);
}
