void Rotate(int angle)
{
  bool state1, state2, state3, state4 = true;
  char c = 'N';
  int cnt = 0;
  while (1)
  {
    int ang = (angle - compass.readHeading());
    
    if (cnt >= 5)
    {
      Stop();
      break;
    }
    //ang(+Ve)
    if (ang > 0 && ang <= 90)
    {
      if (state1)
      {
        state1 = false;
        state2 = true;
        state3 = true;
        state4 = true;
        cnt += 1;
      }
      Left_Own(80);
    }
    //########################################//
    else if (ang > 90 && ang <= 180)
    {
      if (c == 'N')
      {
        c = 'L';
        Left_Own(200);
      }
      else if (c == 'R')
      {
        Right_Own(200);
      }
      else if (c == 'L')
      {
        Left_Own(200);
      }
    }
    else if (ang > 180 && ang <= 270)
    {
      if (c == 'N')
      {
        c = 'R';
        Right_Own(200);
      }
      else if (c == 'R')
      {
        Right_Own(200);
      }
      else if (c == 'L')
      {
        Left_Own(200);
      }
    }
    //########################################//
    else if (ang > 270 && ang <= 359)
    {
      if (state2)
      {
        state1 = true;
        state2 = false;
        state3 = true;
        state4 = true;
        cnt += 1;
      }
      Right_Own(80);
    }
    //########################################//
    //ang(-Ve)
    else if (ang < 0 && ang >= -90)
    {
      if (state3)
      {
        state1 = true;
        state2 = true;
        state3 = false;
        state4 = true;
        cnt += 1;
      }
      Right_Own(80);
    }
    //########################################//
    else if (ang < -90 && ang >= -180)
    {
      if (c == 'N')
      {
        c = 'R';
        Right_Own(200);
      }
      else if (c == 'R')
      {
        Right_Own(200);
      }
      else if (c == 'L')
      {
        Left_Own(200);
      }
    }
    else if (ang < -180 && ang >= -270)
    {
      if (c == 'N')
      {
        c = 'L';
        Left_Own(200);
      }
      else if (c == 'R')
      {
        Right_Own(200);
      }
      else if (c == 'L')
      {
        Left_Own(200);
      }
    }
    //########################################//
    else if (ang < - 270 && ang >= -359)
    {
      if (state4)
      {
        state1 = true;
        state2 = true;
        state3 = true;
        state4 = false;
        cnt += 1;
      }
      Left_Own(80);
    }
    //########################################//
    else if ( ang == 0)
    {
      Stop();
      break;
    }
  }
}
