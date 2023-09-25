void Show_Heart_Rate()
{
  WRITE_PERI_REG(SENS_SAR_READ_CTRL2_REG, 461058);
  //VERY IMPORTANT: DO THIS TO NOT HAVE INVERTED VALUES!
  SET_PERI_REG_MASK(SENS_SAR_READ_CTRL2_REG, SENS_SAR2_DATA_INV);

  analog_data = (analogRead(Heart_beat_Sonsor) / 4);

  samplecounter += 2;

  int N = samplecounter - lastBeatTime;


  if (analog_data < thresh && N > (time_between_beats / 5) * 3)

  {

    if (analog_data < trough_value)

    {

      trough_value = analog_data;

    }

  }


  if (analog_data > thresh && analog_data > peak_value)

  {

    peak_value = analog_data;

  }



  if (N > 250)

  {

    if ( (analog_data > thresh) && (pulse_signal == false) && (N > (time_between_beats / 5) * 3) )

    {

      pulse_signal = true;
      tft.setCursor(50, 150);
      tft.setTextColor(TFT_BLUE, 0x0006);
      tft.setTextSize(3);
      if (heart_rate < 100)
        tft.print(" ");
      tft.print(heart_rate);
      digitalWrite(Heart_beat_Indicator, LOW);
      time_between_beats = samplecounter - lastBeatTime;

      lastBeatTime = samplecounter;



      if (second_heartpulse)

      {

        second_heartpulse = false;

        for (int i = 0; i <= 9; i++)

        {

          beat[i] = time_between_beats; //Filling the array with the heart beat values

        }

      }


      if (first_heartpulse)

      {

        first_heartpulse = false;

        second_heartpulse = true;

        return;

      }


      word runningTotal = 0;


      for (int i = 0; i <= 8; i++)

      {

        beat[i] = beat[i + 1];

        runningTotal += beat[i];

      }


      beat[9] = time_between_beats;

      runningTotal += beat[9];

      runningTotal /= 10;

      heart_rate = 60000 / runningTotal;

    }

  }




  if (analog_data < thresh && pulse_signal == true)

  {

    pulse_signal = false;
    digitalWrite(Heart_beat_Indicator, HIGH);
    amplitude = peak_value - trough_value;

    thresh = amplitude / 2 + trough_value;

    peak_value = thresh;

    trough_value = thresh;

  }


  if (N > 2500)

  {

    thresh = 512;

    peak_value = 512;

    trough_value = 512;

    lastBeatTime = samplecounter;

    first_heartpulse = true;

    second_heartpulse = false;
  }
}
