int led = 2;
bool state;
#include <ESP8266WiFi.h>
#include <WebSocketsClient.h>

WebSocketsClient webSocket;

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {

  switch (type) {
    case WStype_DISCONNECTED:
      Serial.printf("[WSc] Disconnected!\n");
      break;
    case WStype_CONNECTED: {
        Serial.printf("[WSc] Connected to url: %s\n", payload);

        // send message to server when Connected
        webSocket.sendTXT("Connected");
      }
      break;
    case WStype_TEXT:
      Serial.printf("[WSc] get text: %s\n", payload);

      // send message to server
      webSocket.sendTXT("Hello from ESP8266");
      break;
    case WStype_PING:
      // pong will be send automatically
      Serial.printf("[WSc] get ping\n");
      break;
    case WStype_PONG:
      // answer to a ping we send
      Serial.printf("[WSc] get pong\n");
      break;
  }

}

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin("ESP32", "");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    state = !state;
    digitalWrite(led, state);
    delay(500);
  }
  Serial.println("\nConnected to ");
  // server address, port and URL
  webSocket.begin("192.168.4.1", 81, "/");

  // event handler
  webSocket.onEvent(webSocketEvent);

  // try ever 5000 again if connection has failed
  webSocket.setReconnectInterval(5000);

  // start heartbeat (optional)
  // ping server every 15000 ms
  // expect pong from server within 3000 ms
  // consider connection disconnected if pong is not received 2 times
  webSocket.enableHeartbeat(15000, 3000, 2);

}

void loop() {
  webSocket.loop();
}
