void Font(int pwm)
{
  if (pwm <= 250)
  {
    if (!_FState)
    {
      _FState = true;
      _FAng = compass.readHeading();
    }
    int _DAng = _FAng - compass.readHeading();
    if ((abs(_PWM2 - pwm)) >= 5)
    {
      _PWM1 = pwm;
      _PWM2 = pwm;
      Forward(_PWM1, _PWM2);
    }
    if ((_DAng > 0 && _DAng < 90) || _DAng < -270)
    {
      _PWM1--;
      _PWM2++;
      Forward(_PWM1, _PWM2);
    }
    else if ((_DAng < 0 && _DAng > -90) || _DAng > 270)
    {
      _PWM1++;
      _PWM2--;
      Forward(_PWM1, _PWM2);
    }
    else if (_DAng == 0)
    {
      _PWM1 = pwm;
      _PWM2 = pwm;
      Forward(_PWM1, _PWM2);
    }
  }
  else
  {
    Forward(pwm, (pwm - 5));
  }
}
