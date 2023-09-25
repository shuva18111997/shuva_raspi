void RF_Mode()
{
  Change_Mode = true;
  RF_CTRL("ON");
  while(1)
  {
    checkMode();  
  }
}
