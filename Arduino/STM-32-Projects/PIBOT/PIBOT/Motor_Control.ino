/*******************************************************/

void Forward(int pwm1, int pwm2)
{
  /********M1-F*********/
  analogWrite(IN1, 0);
  analogWrite(IN2, pwm1);
  /********M2-F*********/
  analogWrite(IN3, 0);
  analogWrite(IN4, pwm2);
}

void Backward(int pwm)
{
  _FState=false;
  /********M1-B*********/
  analogWrite(IN1, pwm);
  analogWrite(IN2, 0);
  /********M2-B*********/
  analogWrite(IN3, pwm);
  analogWrite(IN4, 0);
}

void Stop()
{
  _FState=false;
  /********M1-S*********/
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  /********M2-S*********/
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}

void Right_Side(int pwm)
{
  _FState=false;
  /********M1-F*********/
  analogWrite(IN1, 0);
  analogWrite(IN2, pwm);
  /********M2-S*********/
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}

void Left_Side(int pwm)
{
  _FState=false;
  /********M1-S*********/
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  /********M2-F*********/
  analogWrite(IN3, 0);
  analogWrite(IN4, pwm);
}

void Right_Own(int pwm)
{
  _FState=false;
  /********M1-F*********/
  analogWrite(IN1, 0);
  analogWrite(IN2, pwm);
  /********M2-B*********/
  analogWrite(IN3, pwm);
  analogWrite(IN4, 0);
}

void Left_Own(int pwm)
{
  _FState=false;
  /********M1-B*********/
  analogWrite(IN1, pwm);
  analogWrite(IN2, 0);
  /********M2-F*********/
  analogWrite(IN3, 0);
  analogWrite(IN4, pwm);
}
/**************************************************/
