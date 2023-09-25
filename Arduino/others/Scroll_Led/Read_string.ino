void Readstring() {
  if (keyboard.available())
  {
    value = keyboard.read();
    if (value >= 65 && value <= 90)
    {
      value = value - 65;
      initial_disp(value);
    }
  }
  if (value == PS2_ESC)
  {
    resetFunc();
  }
  if (value == PS2_ENTER)
  {
    disp_char();
  }
  if ((value == PS2_DELETE) && c != 0)
  {
    c = c - 1;
  }
}

