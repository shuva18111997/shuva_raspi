TaskHandle_t Task1;

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
    1,           /* priority of the task */
    &Task1,      /* Task handle to keep track of created task */
    0);          /* pin task to core 0 */

  delay(500);
}

void loop() {
  xSemaphoreTake(batton, portMAX_DELAY);
  digitalWrite(led2, HIGH);
  delay(500);
  digitalWrite(led2, LOW);
  delay(500);
  count++;
  Serial.print("Loop count print ");
  Serial.println(count);
  xSemaphoreGive(batton);
  delay(10);  //make some delay to receive the batton to the another Task.
}

void Task1code( void * pvParameters ) {
  for (;;) {
    xSemaphoreTake(batton, portMAX_DELAY);
    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led1, LOW);
    delay(1000);
    Serial.print("\t\tCore0 count print ");
    Serial.println(count);
    xSemaphoreGive(batton);
    delay(10);  //make some delay to receive the batton to the another Task.
  }
}
