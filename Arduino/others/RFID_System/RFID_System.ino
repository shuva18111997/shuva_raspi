#include<ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <BMx280I2C.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include<Servo.h>
#include <SPI.h>
#include <MFRC522.h>

#define SDA 5
#define SCL 4
#define I2C_ADDRESS 0x76

#define red_pin 2
#define green_pin 15
#define blue_pin 0

BMx280I2C bmx280(I2C_ADDRESS);
Adafruit_SSD1306 display(56);

char ssid[50] = "shuva";
char pass[50] = "shuva@123";

#define SS_PIN 1
#define RST_PIN 3

Servo servo;
MFRC522 rfid(SS_PIN, RST_PIN);
ESP8266WebServer server(80);

float Temp, Hum;
long Pre;
unsigned long preMillis_Send_Request, preMillis_show_data_to_screen;
String lastRGBValue;
String card;
bool door_open = false;
String mycard = "249 136 180 013";
String key_chain = "85 179 226 82";

void setup() {
  servo.attach(16);
  servo.write(0);
  delay(250);
  servo.detach();

  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);

  analogWrite(red_pin, 0);
  analogWrite(green_pin, 0);
  analogWrite(blue_pin, 0);
  SPI.begin();
  rfid.PCD_Init();
  Wire.begin(SDA, SCL);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.setTextSize(1); //If the size is '1' then the display holds 21 charecters.
  display.println("   Home Automation");
  display.println("  Made By Shuvabrata");
  display.display();
  delay(2000);
  /**********************************************/
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  Display("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    RFID_Access();
    delay(10);
  }
  Display("Connected\n" + WiFi.localIP().toString());
  delay(2000);
  sendRequest();
  /**********************************************/
  if (!bmx280.begin())
  {
    Display("begin() failed. check your BMx280 Interface and I2C Address.");
    while (1) {
      RFID_Access();
      delay(10);
    }
  }
  //by default sensing is disabled and must be enabled by setting a non-zero
  //oversampling setting.
  bmx280.writeOversamplingPressure(BMx280MI::OSRS_P_x16);
  bmx280.writeOversamplingTemperature(BMx280MI::OSRS_T_x16);
  bmx280.writeOversamplingHumidity(BMx280MI::OSRS_H_x16);
  /********************************************************/
  server.on("/", handleRoot);
  server.onNotFound(handleNotFound);
  server.begin();
}

void loop() {
  //start a measurement
  if (!bmx280.measure())
  {
    Display("could not start measurement, is a measurement already running?");
    return;
  }

  if (!bmx280.hasValue())
    return;

  Temp = bmx280.getTemperature();
  Pre = bmx280.getPressure();
  Hum = bmx280.getHumidity();
  if (millis() - preMillis_show_data_to_screen > 1000)
  {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Temperature: " + (String)Temp);
    display.println("Pressure: " + (String)Pre);
    display.println("Humidity: " + (String)Hum);
    display.display();
  }
  /*******************************************************/
  if (WiFi.status() != WL_CONNECTED)
  {
    Display("WiFi is DisConnected");
    Display("Try to Reconnect...");
    while (WiFi.status() != WL_CONNECTED) {
      RFID_Access();
      delay(10);
    }
    Display("Connected");
  }
  RFID_Access();
  if (millis() - preMillis_Send_Request > 50000)
  {
    sendRequest();
    preMillis_Send_Request = millis();
  }
  /************************************************/
  RFID_Access();
  /************************************************/
  server.handleClient();
  yield();
}

void sendRequest()
{
  int httpCode;
  /*HTTPClient Door_Control_http;
    Door_Control_http.begin("http://io.adafruit.com/api/v2/shuva/feeds/door?X-AIO-Key=56e0d91495c64a758fd29da65ddf3ade");
    httpCode = Door_Control_http.GET();
    if (httpCode > 0)
    {
    const size_t capacity = 2 * JSON_ARRAY_SIZE(0) + JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(2) + 2 * JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(23) + 550;

    DynamicJsonBuffer jsonBuffer(capacity);
    JsonObject& root = jsonBuffer.parseObject(Door_Control_http.getString());

    if (root["last_value"] == "open")
    {
      door_open = true;
    }
    else if (root["last_value"] == "close")
    {
      door_open = false;
    }
    }
    else
    {
    Display("Not Connect to Door Control Server. Error: http Code " + (String)httpCode);
    }
    Door_Control_http.end();*/
  /*******************************************RGB Control****************************************************/
  /*HTTPClient Control_RGB_http;
    Control_RGB_http.begin("http:io.adafruit.com/api/v2/shuva/feeds/rgb?X-AIO-Key=56e0d91495c64a758fd29da65ddf3ade");
    httpCode = Control_RGB_http.GET();
    if (httpCode == 200)
    {
    const size_t capacity = 2 * JSON_ARRAY_SIZE(0) + JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(2) + 2 * JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(23) + 550;
    DynamicJsonBuffer jsonBuffer(capacity);
    JsonObject& root = jsonBuffer.parseObject(Control_RGB_http.getString());

    String RGBValue = root["last_value"];
    if (RGBValue != lastRGBValue) {
      RGBValue.remove(0, 1);
      String RedValue = RGBValue.substring(0, 2);
      analogWrite(red, 0);
      String GreenValue = RGBValue.substring(2, 4);
      analogWrite(green, 255);
      String BlueValue = RGBValue.substring(4, 6);
      analogWrite(blue, 255);
    }
    }*/
  /*******************************************BME280********************************************************/
  HTTPClient Send_Data_http;
  // http://sensorsproject.000webhostapp.com/sensor.php?Temp=35&Hum=20&Pre=101105
  RFID_Access();
  if (Send_Data_http.begin("http://sensorsproject.000webhostapp.com/sensor.php?Temp=" + (String)(int)Temp + "&Hum=" + (String)(int)Hum + "&Pre=" + (String)Pre))
  {
    RFID_Access();
    httpCode = Send_Data_http.GET();
    RFID_Access();
    /*if (httpCode == 200)
      {
      RFID_Access();
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println("Temperature: " + (String)Temp);
      display.println("Pressure: " + (String)Pre);
      display.println("Humidity: " + (String)Hum);
      display.display();
      }
      else
      {
      RFID_Access();
      Display("Data Not Send");
      }*/
  }
  else
    return;
  RFID_Access();
  Send_Data_http.end();
  RFID_Access();
  /***************************************************************************************************************************/
}

void Display(String print_data_to_OLED)
{
  display.clearDisplay();
  display.setCursor(0, 10);
  display.println(print_data_to_OLED);
  display.display();
}

String ReadCard(byte *buffer, byte bufferSize) {
  String card_uid;
  for (byte i = 0; i < bufferSize; i++) {
    card_uid += buffer[i] < 0x10 ? " 0" : " ";
    card_uid += buffer[i];
  }
  return card_uid;
}
