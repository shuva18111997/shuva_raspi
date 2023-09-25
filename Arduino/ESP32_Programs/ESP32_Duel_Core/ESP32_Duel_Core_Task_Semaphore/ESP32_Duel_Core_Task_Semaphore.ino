TaskHandle_t Task1;
TaskHandle_t Task2;

SemaphoreHandle_t batton;

// LED pins
const int led1 = 2;
const int led2 = 4;

int count;

void setup() {
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  batton = xSemaphoreCreateMutex();
  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
    Task1code,   /* Task function. */
    "Task1",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    0,           /* priority of the task [Lowest number Lowest Priority]*/
    &Task1,      /* Task handle to keep track of created task */
    0);          /* pin task to core 0 */
  delay(500);

  //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
    Task2code,   /* Task function. */
    "Task2",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    1,           /* priority of the task */
    &Task2,      /* Task handle to keep track of created task */
    1);          /* pin task to core 1 */
  delay(500);
}

//Task1code: blinks an LED every 1000 ms
void Task1code( void * pvParameters ) {
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());

  for (;;) {
    xSemaphoreTake(batton, portMAX_DELAY);
    //From here code not worked
    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led1, LOW);
    delay(1000);
    Serial.print("Core0 count print ");
    Serial.println(count);
    xSemaphoreGive(batton);
    delay(50);
  }
}
//Task2code: blinks an LED every 700 ms
void Task2code( void * pvParameters ) {
  Serial.print("Task2 running on core ");
  Serial.println(xPortGetCoreID());

  for (;;) {
    xSemaphoreTake(batton, portMAX_DELAY);
    digitalWrite(led2, HIGH);
    delay(500);
    digitalWrite(led2, LOW);
    delay(500);
    count++;
    Serial.print("\t\tCore1 count print ");
    Serial.println(count);
    xSemaphoreGive(batton);
    delay(50);
  }
}

void loop() {

}
