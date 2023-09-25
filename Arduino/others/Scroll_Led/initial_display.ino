void initial_disp(int value)
{
  T[c] = value;
  c++;
  Serial.println(c);
  while (1)
  {
    if (keyboard.available())
    {
      Readstring();
    }
    if (c == 1)
    {
      for (int i = 0; i < 5; i++)
        Select(i, ch[T[c - 1]][i]);
    }
    else if (c > 1)
    {
      for (int i = 0; i < 5; i++)
        Select(i, ch[T[c - 2]][i]);
      for (int i = 8; i < 13; i++) {
        Select(i, ch[T[c - 1]][(i - 8)]);
      }
    }
  }
}

