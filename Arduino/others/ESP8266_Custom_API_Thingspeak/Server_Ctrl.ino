void serchWiFi()
{
  String webpage = "";

  int Networks = WiFi.scanNetworks();
  if (Networks > 0)
  {
    webpage += "<center><table border='2'><tr><td><font color='blue'><center>AP_Name</center></font></td><td><font color='red'><center>AP_Strength</center></font></td><td><font color='Green'><center>AP_Select</center></font></td></tr>";

    for (int i = 0; i < Networks; i++)
    {
      webpage += "<tr><td><center>";
      webpage += (String)WiFi.SSID(i);
      webpage += "</center></td><td><center>";
      webpage += (String)WiFi.RSSI(i);
      webpage += " dB</center></td><td><center><a href='/SSID_Set?ssid=" + (String)WiFi.SSID(i) + "'><button>select</button></a>";
      webpage += "</center></td></tr>";
    }
    webpage += "</table><br><a href='/'><button>Refresh</button></a><br><a href='/SSID_Set'><h3><font color='red'>click Here to manually Added A Network</font></h3></a></center>";
  }
  else
  {
    webpage += "<center><h1>No WiFi Network Found!!!</h1><br><a href='/'><button>Refresh</button></a><br><a href='/SSID_Set'><h3><font color='red'>click Here to manually Added A Network</font></h3></a></center>";
  }
  server.send(200, "text/html", webpage);
}
void handleclient()
{
  String Recvssid = server.arg("ssid");
  String webpage = "";
  webpage += "<center><form method='get' action='SettingChange' onsubmit='return validateForm()'><h2>SSID:&nbsp <input type='text' name='ssid' id='ssid' value='" + Recvssid + "'><br></h2><h2>PASS:&nbsp";
  webpage += "<input type='password' name='pass' id='pass'><br></h2><input type='submit' value='SUBMIT'></form></center><script>function validateForm()";
  webpage += "{var ssid = document.getElementById('ssid').value;if(ssid == ''){alert('Blank ssid must be filled out');return false;}}</script>";
  server.send(200, "text/html", webpage);
}

void Updated()
{
  if (SPIFFS.exists("/config"))
  {
    File Writefile = SPIFFS.open("/config", "w");
    if (Writefile)
    {
      Writefile.println(server.arg("ssid"));
      Writefile.println(server.arg("pass"));
    }
  }
  String webpage = "<center><h1>Date is Updated.<br>OK Thanks.</h1></center>";
  server.send(200, "text/html", webpage);
  delay(1000);
  ESP.reset();
}
