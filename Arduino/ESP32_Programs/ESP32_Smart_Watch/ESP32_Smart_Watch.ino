#ifdef ESP32
// This Lib are declare before the "TFT_eSPI.h" Lib. Either the error message "File not declare in the scope" will Occur.
#include "SPIFFS.h"
#include <TFT_eSPI.h>
#include "Lib.h"
#include <esp_int_wdt.h>
#include <esp_task_wdt.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <PCF8563.h>
#include <QMC5883L.h>
#include "EEPROM.h"
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESPmDNS.h>
#include <HTTPClient.h>
#include<Ticker.h>
#include "soc/sens_reg.h" //This Lib is for WiFi & ADC_Read conflict.

#else
#error "Board not found"
#endif
//////////////////////Duel_Core///////////////////
TaskHandle_t Task;
int Core0_LCD = 0;
///////////////////////////parameter//////////////////////////
#define WiFi_Access_Parameter 0
#define CLOCK 1
#define Temp_and_Pre 2
#define Hum 3
#define Compass 4
#define Heart_beat 5
#define Calender 6
#define Settings 7 //Settings_Img
int parameter = CLOCK, preParameter = CLOCK;
bool change_Parameter = true;
#define Max_Parameter 7
#define Min_Parameter 1
//////////////////////Interrupt and millis/////////////////////
#define UpBtn 34
#define DownBtn 35
#define HomeBtn 4
#define LeftBtn 39
#define RightBtn  36
unsigned long preMillis1, preMillis2, preMillis3, preMillis4, preMillis5;
/////////////////////Led/////////////////////
#define Led 2
bool Led_State = false;
/////////////////////CLOCK/////////////////////
PCF8563 pcf;
Time nowTime;
uint8_t Clock_hour, Clock_min, Clock_sec;
bool Clock_Setting = false, Check_Clock_Settings = false, Set_Clock_Yes = true;
int Change_Clock_Settings;
unsigned long Clock_Change_Millis;
/////////////////BME280///////////////////////
Adafruit_BME280 bme; // I2C
////////////////////////BME280_Temp_Pre/////////////////////
int PreTempImg, TempImg;
float BMETemp, BMEHum;
long BMEPre;
unsigned long Read_BME280_Time;
///////////////////TFT_Screen/////////////////////////////////
TFT_eSPI tft = TFT_eSPI();
//////////////////Battery///////////////////
#define Battery_voltage_measure_pin 27
#define multipler 0.0017094017094017
#define FullCharge 4.18
float Batt_volt;
int Batt_Level;
unsigned long Battery_Millis;
//////////////////Calender/////////////////////
uint8_t _date, _month, _year;
int8_t _weekday;
String monthSet[] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
String daySet[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
bool calender_settings = false, Calender_change_color = true, calender_change_settings = false, Set_Calender_Yes = true;
int Calender_cnt = 1, change_calender_parameter;
//////////////////Compass/////////////////////
#define QMC5883L_Address 0xD
#define Compass_Calibration_time 5000
QMC5883L compass;
int heading, preHeding;
unsigned long preCompassMillis;
bool compass_change = true, Compass_one_time = true;
//////////////////Settings////////////////////
bool Settings_Hold = false;
int Open_Settings, Settings_Parameter = 1, In_Settings_Parameter = 1;
/////////////EEPROM////////////////////////
#define EEPROM_SIZE 4
#define EEPROM_WiFi_Settings_Address 0
#define EEPROM_Weather_App_Address 1
#define EEPROM_HEARTBEAT_Address 2
#define EEPROM_Compass_Address 3
byte EEPROM_Settings[EEPROM_SIZE] = {3, 3, 1, 1};
/////////////////////WiFi_Credentials///////////////////
#define WiFi_AP_SSID "ESP32"
#define WiFi_AP_Password "12345678"
char ssid[50];
char pass[50];
String HomePage;
String UpdateSettingsPage;
String PageNotFound;
String WiFiSearchPage;
String WiFi_SSID;
String WiFi_PASS;
bool ESP_Restart = false;
String Web_Vars[4];
String datetime;
bool datetime_lock = false;
int date_set, month_set, year_set, hour_set, min_set, weekday_set;
AsyncWebServer server(80); // server port 80
unsigned long WiFi_Start_Millis;
bool WiFi_Connected_Skip = false;
int WiFi_AP_Connected_Clients = 0;
//For AP mode
#define New_Client_Connected 1
#define Client_Disconnected 2
//For STA mode
#define Connected_to_AP 3
#define Disonnected_from_AP 4
bool Host_Connection_Status = false;
#define timerDelay 5000L
unsigned long lastUploadTime = 0;
//////////////////////SPIFFS////////////////////////
String SPIFFS_Str[4];
///////////////Heart_Beat_Sensor/////////////////
#define Heart_beat_Sonsor 13
#define Heart_beat_Indicator 12
volatile int heart_rate;
volatile int analog_data;
volatile int time_between_beats = 600;
volatile boolean pulse_signal = false;
volatile int beat[10];         //heartbeat values will be sotred in this array
volatile int peak_value = 512;
volatile int trough_value = 512;
volatile int thresh = 525;
volatile int amplitude = 100;
volatile boolean first_heartpulse = true;
volatile boolean second_heartpulse = false;
volatile unsigned long samplecounter = 0;   //This counter will tell us the pulse timing
volatile unsigned long lastBeatTime = 0;
Ticker timer;
////////////////////////////////////////////////////

void setup() {
  Serial.begin(115200);
  ///////////////////TFT_Display/////////////////////
  tft.begin();
  tft.setSwapBytes(true);
  /////////////////////Interrupt/////////////////////
  pinMode(UpBtn, INPUT_PULLUP);
  pinMode(DownBtn, INPUT_PULLUP);
  pinMode(HomeBtn, INPUT_PULLUP);
  pinMode(LeftBtn, INPUT_PULLUP);
  pinMode(RightBtn, INPUT_PULLUP);
  attachInterrupt(UpBtn, UP_ISR, FALLING);
  attachInterrupt(DownBtn, DOWN_ISR, FALLING);
  attachInterrupt(HomeBtn, HOME_ISR, FALLING);
  attachInterrupt(LeftBtn, Left_ISR, FALLING);
  attachInterrupt(RightBtn, Right_ISR, FALLING);
  /////////////////////Led/////////////////////
  pinMode(Led, OUTPUT);
  digitalWrite(Led, Led_State);
  //////////////////////EEPROM////////////////////////
  if (!EEPROM.begin(EEPROM_SIZE))
  {
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0);
    tft.setTextSize(2);
    tft.setTextColor(TFT_RED);
    tft.println("EEPROM Not Started");
    while (1) {
      delay(500);
    }
  }
  for (int i = 0; i < EEPROM_SIZE; i++)
  {
    byte eeprom_read = EEPROM.read(i);
    if (eeprom_read < 1 || eeprom_read > 3)
    {
      EEPROM.write(i, EEPROM_Settings[i]);  //write the default value
    }
    else
    {
      EEPROM_Settings[i] = eeprom_read; //or, read the value
    }
  }
  /////////////////////CLOCK/////////////////////
  pcf.init();
  ////////////////////////BMP180/////////////////////
  if (!bme.begin(0x76, &Wire)) {
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0);
    tft.setTextSize(2);
    tft.setTextColor(TFT_RED);
    tft.println("BMP Not Started");
    while (1) {
      delay(500);
    }
  }
  ///////////////Heart_Beat_Sensor/////////////////
  pinMode(Heart_beat_Indicator, OUTPUT);
  digitalWrite(Heart_beat_Indicator, HIGH);
  //////////////////Hotspot_or_WiFi_Active////////////////////
  if ((EEPROM_Settings[EEPROM_WiFi_Settings_Address] < 3) || (EEPROM_Settings[EEPROM_Weather_App_Address] < 3))
  {
    //////////////////////SPIFFS////////////////////////
    SPIFFS.begin();
    SPIFFS_Initialisation();
  }
  //////////////////Hotspot_or_WiFi_Active////////////////////
  if ((EEPROM_Settings[EEPROM_WiFi_Settings_Address] < 3) || (EEPROM_Settings[EEPROM_Weather_App_Address] == 2))
  {
    /////////////////////WiFi_mDns///////////////////
    if (!MDNS.begin("ESP")) { //esp.local/
      tft.fillScreen(TFT_BLACK);
      tft.setCursor(0, 0);
      tft.setTextSize(2);
      tft.setTextColor(TFT_RED);
      tft.println("MDNS not responded");
      while (1)
      {
        delay(500);
      }
    }
  }
  /////////////////////WiFi_AP///////////////////
  if ((EEPROM_Settings[EEPROM_WiFi_Settings_Address] == 1) || (EEPROM_Settings[EEPROM_Weather_App_Address] == 2))
  {
    WiFi.softAP(WiFi_AP_SSID, WiFi_AP_Password);
    Led_State = true;
    digitalWrite(Led, Led_State);
    tft.fillScreen(TFT_BLACK);
    tft.pushImage(80, 30, 80, 80, HotsPot_Img);
    tft.setTextSize(2);
    tft.setCursor(0, 120);
    tft.setTextColor(TFT_WHITE);
    if (EEPROM_Settings[EEPROM_WiFi_Settings_Address] == 2)
      tft.println("   Settings Mode");
    else if (EEPROM_Settings[EEPROM_Weather_App_Address] == 2)
      tft.println("  Data Sharing Mode");
    tft.setCursor(0, 150);
    tft.setTextColor(TFT_BLUE);
    tft.print("     SSID: ");
    tft.setTextColor(TFT_GREEN);
    tft.println(WiFi_AP_SSID);
    tft.setTextColor(TFT_BLUE);
    tft.print("    PASS: ");
    tft.setTextColor(TFT_GREEN);
    tft.println(WiFi_AP_Password);
    tft.fillRect(100, 200, 40, 20, tft.color565(0, 102, 255));
    tft.setCursor(109, 202);
    tft.setTextColor(TFT_WHITE);
    tft.print("OK");
    Start_Server();
    parameter = WiFi_Access_Parameter;
    change_Parameter = false;
    WiFi_Start_Millis = millis();
    while ((parameter == WiFi_Access_Parameter) && (millis() - WiFi_Start_Millis < 5000))
    {
      delay(1);
    }
    parameter = CLOCK;
    change_Parameter = true;
  }
  /////////////////////WiFi_STA///////////////////
  if ((EEPROM_Settings[EEPROM_WiFi_Settings_Address] == 2) || (EEPROM_Settings[EEPROM_Weather_App_Address] == 1))
  {
    SPIFFS_Str[0].toCharArray(ssid, SPIFFS_Str[0].length() + 1); //We write here 'data.length()' but the array takes 'data.length()-1'
    SPIFFS_Str[1].toCharArray(pass, SPIFFS_Str[1].length() + 1); //We write here 'data.length()' but the array takes 'data.length()-1'
    WiFi.begin(ssid, pass);
    tft.fillScreen(TFT_BLACK);
    tft.pushImage(60, 20, 120, 82, WiFi_Img);
    tft.setTextSize(2);
    tft.setCursor(0, 120);
    tft.setTextColor(TFT_WHITE);
    if (EEPROM_Settings[EEPROM_WiFi_Settings_Address] == 2)
      tft.println("   Settings Mode");
    else if (EEPROM_Settings[EEPROM_Weather_App_Address] == 1)
      tft.println("  Data Sharing Mode");
    tft.fillRect(100, 200, 40, 20, tft.color565(0, 102, 255));
    tft.setCursor(109, 202);
    tft.setTextColor(TFT_WHITE);
    tft.print("OK");
    tft.setCursor(0, 150);
    int ssid_length = SPIFFS_Str[0].length() + 6;
    if (ssid_length <= 20)
    {
      ssid_length = (20 - ssid_length) / 2;
      for (int i = 0; i < ssid_length; i++)
        tft.print(" ");
      tft.setTextColor(TFT_BLUE);
      tft.print("SSID: ");
      tft.setTextColor(TFT_GREEN);
      tft.println(ssid);
    }
    else
    {
      tft.setTextColor(TFT_BLUE);
      tft.print("SSID: ");
      tft.setTextColor(TFT_GREEN);
      for (int i = 0; i < 11; i++)
        tft.print(ssid[i]);
      tft.println("...");
    }
    tft.setTextColor(TFT_BLUE);
    tft.print("   Connecting");
    parameter = WiFi_Access_Parameter;
    change_Parameter = false;
    int c = 0;
    while ((parameter == WiFi_Access_Parameter) && (WiFi.status() != WL_CONNECTED))
    {
      c++;
      tft.setCursor(156, 166);
      tft.setTextColor(TFT_BLUE, TFT_BLACK);
      if (c == 1)
        tft.print("    ");
      else if (c == 2)
        tft.print(".   ");
      else if (c == 3)
        tft.print("..  ");
      else if (c == 4)
        tft.print("... ");
      else if (c == 5)
      {
        tft.print("....");
        c = 0;
      }
      Led_State = !Led_State;
      digitalWrite(Led, Led_State);
      delay(500);
    }
    if (WiFi.status() != WL_CONNECTED)
      WiFi_Connected_Skip = true;
    else
    {
      WiFi_Connected_Skip = false;
      WiFi.setAutoReconnect(true);
      WiFi.persistent(true);
      Start_Server();
      Core0_LCD = Connected_to_AP;
    }
    parameter = CLOCK;
    change_Parameter = true;
  }
  if ((EEPROM_Settings[EEPROM_WiFi_Settings_Address] < 3) || (EEPROM_Settings[EEPROM_Weather_App_Address] < 3))
  {
    TaskCreate();
  }
}

void loop() {
  if (ESP_Restart)
  {
    if (parameter == Heart_beat)
    {
      timer.detach();
    }
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(5);
    tft.setCursor(0, 60);
    tft.setTextColor(TFT_RED);
    tft.println(" Reboot");
    tft.fillRect(100, 200, 40, 20, tft.color565(0, 102, 255));
    tft.setCursor(109, 202);
    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE);
    tft.print("OK");
    while (ESP_Restart)
    {
      delay(1);
    }
    delay(500);
    ESP.restart();
  }
  if (Core0_LCD > 0)
  {
    if (parameter == Heart_beat)
    {
      timer.detach();
    }
    int _parameter = parameter;
    change_Parameter = false;
    parameter = -1;
    Core0_Show_LCD();
    if (parameter == Heart_beat)
    {
      timer.attach_ms(2, Show_Heart_Rate);
    }
    change_Parameter = true;
    parameter = _parameter;
    preParameter = 0;
    Core0_LCD = 0;
  }
  Check_Parameter_Change();
  if (parameter == CLOCK)
  {
    Show_Clock();
  }
  else if (parameter == Temp_and_Pre)
  {
    Show_Temp_Pre();
    ShowBattery();
  }
  else if (parameter == Hum)
  {
    Show_Hum();
    ShowBattery();
  }
  else if (parameter == Compass)
  {
    Show_Compass();
  }
  else if (parameter == Calender)
  {
    Show_Calender();
  }
  else if (parameter == Settings)
  {
    Show_Settings();
  }
  if (millis() - Read_BME280_Time > 2)
  {
    Read_BME280();
    Read_BME280_Time = millis();
  }
  if (!datetime_lock)
  {
    nowTime = pcf.getTime();
  }
  else
  {
    pcf.stopClock();
    pcf.setYear(year_set);
    pcf.setMonth(month_set);
    pcf.setDay(date_set);
    pcf.setHour(hour_set);
    pcf.setMinut(min_set);
    pcf.setSecond(0);
    pcf.setWeekDay(weekday_set);
    pcf.startClock();
    delay(10);
    datetime_lock = false;
  }
}
