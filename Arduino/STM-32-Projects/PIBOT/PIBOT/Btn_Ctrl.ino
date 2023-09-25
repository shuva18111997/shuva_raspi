void BtnUpCtrl()
{
  static unsigned long premillis = 0;
  if (millis() - premillis > 200)
  {
    if (Change_Mode)
    {
      if (btn1St)
      {
        btn1St = false;
        cnt++;
      }
      if (Select_Mode)
      {
        UD_cnt = !UD_cnt;
      }
    }
    else
    {
      mode--;
      if (mode < 0)
      {
        mode = 1;
      }
    }
  }
  premillis = millis();
}
/****************************/
void BtnDownCtrl()
{
  static unsigned long premillis = 0;
  if (millis() - premillis > 200)
  {
    if (Change_Mode)
    {
      if (btn2St)
      {
        btn2St = false;
        cnt++;
      }
      if (Select_Mode)
      {
        UD_cnt = !UD_cnt;
      }
    }
    else
    {
      mode++;
      if (mode > 1)
      {
        mode = 0;
      }
    }
  }
  premillis = millis();
}
/****************************/
void BtnLeftCtrl()
{
  static unsigned long premillis = 0;
  if (millis() - premillis > 200)
  {
    if (Change_Mode)
    {
      if (btn3St)
      {
        btn3St = false;
        cnt++;
      }
      if (Select_Mode)
      {
        count = 10;
      }
    }
    else
    {
      count--;
      if (count < 0)
      {
        count = 4;
      }
    }
  }
  premillis = millis();
}
/****************************/
void BtnRightCtrl()
{
  static unsigned long premillis = 0;
  if (millis() - premillis > 200)
  {
    if (Change_Mode)
    {
      if (btn4St)
      {
        btn4St = false;
        cnt++;
      }
      if (Select_Mode)
      {
        count = 10;
      }
    }
    else
    {
      count++;
      if (count > 4)
      {
        count = 0;
      }
    }
  }
  premillis = millis();
}
/****************************/
