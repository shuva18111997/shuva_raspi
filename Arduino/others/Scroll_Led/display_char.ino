void disp_char()
{
  for (int i = 0; i < coloumn; i++)
  {
    total[i] = 0;
  }
  while (1)
  {
    for (int a = 0 ; a <= c + 1; a++)
    {
      if (a < c)
      {
        count = coloumn;
        for (int i = 0; i < 8; i++)
        {
          total[count] = ch[T[a]][i];
          count++;
        }
      }
      else
      {
        count = coloumn;
        for (int i = 0; i < 8; i++)
        {
          total[count] = 0;
          count++;
        }
      }
      for (int b = 0; b < 8; b++)
      {
        if (keyboard.available())
        {
          value = keyboard.read();
          if (value == PS2_ESC)
          {
            resetFunc();
          }
        }
        for (int i = 0; i < count; i++)
        {
          total[i] = total[i + 1];
        }
        for (int x = 0; x < ShiftTime; x++)
        {
          for (int i = 0; i < coloumn; i++)
          {
            Select(i, total[i]);
          }
        }
      }
    }
  }
}
