#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int i, good, k;
byte data_in;
String data = "";
bool tog;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.setCursor(0, 0);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.println("RF 433MHZ Test");
  display.setTextSize(4);
  display.display();

  attachInterrupt(1, data_incoming, RISING);
  pinMode(3, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(115200);
}//setup

void loop()
{
  if (data.length() > 4)
  {
    display.setCursor(0, 0);
    display.clearDisplay();
    display.println(data);
    display.display();
    data = "";
    digitalWrite(13, tog);
    tog = ! tog;
  }
}

void data_incoming() {
  for (i = 0; i < 100; i++) {
    delayMicroseconds(20);
    good = 1;
    if (digitalRead(3) == LOW) {
      good = 0;
      i = 100;
    }
  }//for

  if (good == 1) {
    detachInterrupt(1);
    while (1) {
      if (digitalRead(3) == LOW) {
        delayMicroseconds(750);

        for (i = 0; i < 8; i++) {
          if (digitalRead(3) == HIGH)
            bitWrite(data_in, i, 1);
          else
            bitWrite(data_in, i, 0);
          delayMicroseconds(1000);
        }//for

        if (data_in == '*')
        {
          Serial.println();
        }
        else if ((data_in == ' ') || ((data_in >= 'A') && (data_in <= 'Z')) || ((data_in >= 'a') && (data_in <= 'Z')))
        {
          //Serial.print(char(data_in));
          data += (char)data_in;
        }
        else if (data_in == '#')
        {
          Serial.println(data);
        }

        break;//secondtwhile
      }
    }
  }
  attachInterrupt(1, data_incoming, RISING);
}//routine
