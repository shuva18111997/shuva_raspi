#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LED 2
bool state;

const char* ssid = "shuva";
const char* password = "shuva@123";

String openWeatherMapApiKey = "e9935677a9486f65d41b829c565dc127";

String city = "Bally";
String countryCode = "IN";

unsigned long lastTime = 0;
unsigned long timerDelay = 10000;

String jsonBuffer;

int conn_cont = 1;

void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.display();

  pinMode(LED, OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
}

void loop() {
  if (WiFi.status() != WL_CONNECTED)
  {
    conn_cont = 1;
    while (WiFi.status() != WL_CONNECTED)
    {
      Serial.println(conn_cont);
      if (conn_cont == 1)
      {
        display.clearDisplay();
        display.setCursor(0, 0);
        display.print("ssid:- ");
        display.println((String)ssid);
        display.print("pass:- ");
        display.println((String)password);
        display.print("Connecting   ");
        display.display();
      }
      else if (conn_cont == 2)
      {
        display.clearDisplay();
        display.setCursor(0, 0);
        display.print("ssid:- ");
        display.println((String)ssid);
        display.print("pass:- ");
        display.println((String)password);
        display.print("Connecting.  ");
        display.display();
      }
      else if (conn_cont == 3)
      {
        display.clearDisplay();
        display.setCursor(0, 0);
        display.print("ssid:- ");
        display.println((String)ssid);
        display.print("pass:- ");
        display.println((String)password);
        display.print("Connecting.. ");
        display.display();
      }
      else if (conn_cont == 4)
      {
        display.clearDisplay();
        display.setCursor(0, 0);
        display.print("ssid:- ");
        display.println((String)ssid);
        display.print("pass:- ");
        display.println((String)password);
        display.print("Connecting...");
        display.display();
      }
      conn_cont++;
      if (conn_cont > 4)
      {
        conn_cont = 1;
      }
      state = !state;
      digitalWrite(LED, state);
      delay(500);
    }
  }
  else
  {
    if ((millis() - lastTime) > timerDelay) {
      String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," + countryCode + "&units=metric&APPID=" + openWeatherMapApiKey;

      jsonBuffer = httpGETRequest(serverPath.c_str());
      Serial.println(jsonBuffer);
      JSONVar myObject = JSON.parse(jsonBuffer);

      // JSON.typeof(jsonVar) can be used to get the type of the var
      if (JSON.typeof(myObject) == "undefined") {
        Serial.println("Parsing input failed!");
        return;
      }

      Serial.print("JSON object = ");
      Serial.println(myObject);

      display.clearDisplay();
      display.setCursor(0, 0);
      display.print("Temperature: ");
      display.print(myObject["main"]["temp"]);
      display.println(" *C");
      display.print("Pressure: ");
      display.print(myObject["main"]["pressure"]);
      display.println(" mb");
      display.print("Humidity: ");
      display.print(myObject["main"]["humidity"]);
      display.println(" %");
      display.print("Wind Speed: ");
      display.print(myObject["wind"]["speed"]);
      display.println(" m/s");
      display.display();

      lastTime = millis();
    }
  }
}
//#############################################################

String httpGETRequest(const char* serverName) {
  HTTPClient http;

  // Your Domain name with URL path or IP address with path
  http.begin(serverName);

  // Send HTTP POST request
  int httpResponseCode = http.GET();

  String payload = "{}";

  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}
