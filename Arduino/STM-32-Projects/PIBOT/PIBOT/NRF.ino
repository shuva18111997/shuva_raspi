void NRF_Mode()
{
  char c[1] = "";
  bool Go_Front = true;
  RF24 radio(PA4, PC15);
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);

  radio.openReadingPipe(1, pipeIn);
  //we start the radio comunication
  radio.startListening();

  lcd.clear();
  lcd.home();
  lcd.print("Enjoy NRF MODE");
  delay(2000);
  Change_Mode = true;
  while (1)
  {
    while (radio.available())
    {
      c[0] = '\0';
      digitalWrite(LED_pin, LOW);
      radio.read(&c, sizeof(c));
      //Serial.println(c[0]);
      if (c[0] == 0x7F)
      {
        break;
      }
      else
      {
        if (Self_Rotation)
        {
          lcd.setCursor(1, 1);
          lcd.print("Self_Rotation");
        }
        else
        {
          lcd.setCursor(1, 1);
          lcd.print("              ");
        }
        if (c[0] == 'Z')
        {
          Self_Rotation = true;
        }
        else if (c[0] == 'Y')
        {
          Self_Rotation = false;
        }
        else if (c[0] == 'A')
        {
          c[0] = '\0';
          R2 = true; R3 = true; R4 = true;
          if (Self_Rotation)
          {
            if (R1)
            {
              lcd.setCursor(0, 0);
              lcd.print("      UP       ");
              Rotate(360);
              R1 = false;
              if (!Go_Front)
                Go_Front = true;
            }
          }
          else if (Go_Front && Self_Rotation == false)
          {
            lcd.setCursor(0, 0);
            lcd.print("   Forward    ");
            if (measure_distance())
            {
              Go_Front = false;
              Stop();
            }
            else
              Font(Motor_Speed);
          }
        }
        else if (c[0] == 'E')
        {
          c[0] = '\0';
          R1 = true; R3 = true; R4 = true;
          if (Self_Rotation)
          {
            if (R2)
            {
              lcd.setCursor(0, 0);
              lcd.print("    DOWN     ");
              Rotate(180);
              R2 = false;
              if (!Go_Front)
                Go_Front = true;
            }
          }
          else
          {
            if (!Go_Front)
            {
              Go_Front = true;
            }
            lcd.setCursor(0, 0);
            lcd.print("   Backward   ");
            Backward(120);
          }
        }
        else if (c[0] == 'B')
        {
          c[0] = '\0';
          R1 = true; R2 = true; R3 = true;
          if (Self_Rotation)
          {
            if (R4)
            {
              lcd.setCursor(0, 0);
              lcd.print("    RIGHT      ");
              Rotate(270);
              R4 = false;
              if (!Go_Front)
                Go_Front = true;
            }
          }
          else if (Go_Front && Self_Rotation == false)
          {
            if (measure_distance())
            {
              Go_Front = false;
              Stop();
            }
            else
            {
              lcd.setCursor(0, 0);
              lcd.print("    RIGHT_Side      ");
              Right_Own(120);
            }
          }
        }
        else if (c[0] == 'C')
        {
          c[0] = '\0';
          R1 = true; R2 = true; R4 = true;
          if (Self_Rotation)
          {
            if (R3)
            {
              lcd.setCursor(0, 0);
              lcd.print("    LEFT      ");
              Rotate(90);
              R3 = false;
              if (!Go_Front)
                Go_Front = true;
            }
          }
          else if (Go_Front && Self_Rotation == false)
          {
            if (measure_distance())
            {
              Go_Front = false;
              Stop();
            }
            else
            {
              lcd.setCursor(0, 0);
              lcd.print("    LEFT_Side      ");
              Left_Own(120);
            }
          }
        }
        else if (c[0] == 'D')
        {
          lcd.setCursor(0, 0);
          lcd.print("    STOP       ");
          R1 = true; R2 = true; R3 = true; R4 = true;
          Stop();
        }
        else if (c[0] == 'O')
        {
          Motor_Speed = 80;
        }
        else if (c[0] == 'P')
        {
          Motor_Speed = 120;
        }
        else if (c[0] == 'R')
        {
          Motor_Speed = 200;
        }
        else if (c[0] == 'S')
        {
          Motor_Speed = 250;
        }
        c[0] = '\0';
      }
    }
    Stop();
    lcd.setCursor(0, 0);
    lcd.print("    STOP       ");
    digitalWrite(LED_pin, HIGH);
    checkMode();
  }
}
