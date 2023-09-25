void BLE_Mode()
{
  bool Go_Front = true;
  BLE_CTRL("ON");
  Serial2.begin(9600);
  pinMode(BLE_Status, INPUT);
  lcd.clear();
  lcd.home();
  lcd.print("Enjoy Bluetooth");
  lcd.setCursor(6, 1);
  lcd.print("Mode");
  delay(1000);
  Change_Mode = true;
  while (1)
  {
    if (!digitalRead(BLE_Status))
    {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("Bluetooth");
      lcd.setCursor(1, 1);
      lcd.print("Not Connected");
    }
    else
    {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("Bluetooth");
      lcd.setCursor(3, 1);
      lcd.print("Connected");
      delay(1000);
    }
    while (digitalRead(BLE_Status))
    {
      while (Serial2.available())
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
        char c = Serial2.read();

        if (c == 'Z')
        {
          Self_Rotation = true;
        }
        else if (c == 'Y')
        {
          Self_Rotation = false;
        }
        else if (c == 'A')
        {
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
            {
              Font(Motor_Speed);
            }
          }
        }
        else if (c == 'E')
        {
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
        else if (c == 'B')
        {
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
        else if (c == 'C')
        {
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
        else if (c == 'D')
        {
          lcd.setCursor(0, 0);
          lcd.print("    STOP       ");
          R1 = true; R2 = true; R3 = true; R4 = true;
          Stop();
        }
        else if (c == 'O')
        {
          Motor_Speed = 80;
        }
        else if (c == 'P')
        {
          Motor_Speed = 120;
        }
        else if (c == 'R')
        {
          Motor_Speed = 200;
        }
        else if (c == 'S')
        {
          Motor_Speed = 250;
        }
        c = '\n';
      }
    }
    Stop();
    checkMode();
    delay(100);
  }
}
