void HomePageInit()
{
  if (EEPROM_Settings[EEPROM_WiFi_Settings_Address] < 3)  //For WiFi Settings
  {
    if (EEPROM_Settings[EEPROM_WiFi_Settings_Address] == 1)
      Web_Vars[0] = "AP_Mode";
    else if (EEPROM_Settings[EEPROM_WiFi_Settings_Address] == 2)
      Web_Vars[0] = "STA_Mode";
    else if (EEPROM_Settings[EEPROM_WiFi_Settings_Address] == 3)
      Web_Vars[0] = "OFF";

    if (EEPROM_Settings[EEPROM_Weather_App_Address] == 1)
      Web_Vars[1] = "Web_Share";
    else if (EEPROM_Settings[EEPROM_Weather_App_Address] == 2)
      Web_Vars[1] = "Local_Share";
    else if (EEPROM_Settings[EEPROM_Weather_App_Address] == 3)
      Web_Vars[1] = "Sharing_OFF";

    if (EEPROM_Settings[EEPROM_HEARTBEAT_Address] == 1)
      Web_Vars[2] = "EN";
    else if (EEPROM_Settings[EEPROM_HEARTBEAT_Address] == 2)
      Web_Vars[2] = "DIS";

    if (EEPROM_Settings[EEPROM_Compass_Address] == 1)
      Web_Vars[3] = "EN";
    else if (EEPROM_Settings[EEPROM_Compass_Address] == 2)
      Web_Vars[3] = "DIS";

    HomePage PROGMEM = R"=====(
<html>
<head>
<title>Settings</title>
<script>
function initialisation()
{
  document.getElementById("ssid").value = ")=====" + WiFi_SSID + R"=====(";
  document.getElementById("pass").value = ")=====" + WiFi_PASS + R"=====(";
  document.getElementById("host_name").value = ")=====" + SPIFFS_Str[2] + R"=====(";
  document.getElementById("file_name").value = ")=====" + SPIFFS_Str[3] + R"=====(";
  document.getElementById("WiFi_Mode").value = ")=====" + Web_Vars[0] + R"=====(";
  document.getElementById("Data_Share").value = ")=====" + Web_Vars[1] + R"=====(";
  document.getElementById("Heart_Beat").value = ")=====" + Web_Vars[2] + R"=====(";
  document.getElementById("Compass").value = ")=====" + Web_Vars[3] + R"=====(";
  document.getElementById("datetime").value = ")=====" + datetime + R"=====(";
}

function show()
{
  var pass = document.getElementById("pass");
  var password_hide_btn = document.getElementById("password_hide_btn");
  if (pass.type === "password") {
        pass.type = "text";
    password_hide_btn.innerHTML = "Hide";
     } 
  else { 
    pass.type = "password";
    password_hide_btn.innerHTML = "Show";
  } 
}

function validateForm() {
  if(document.forms['Setting']['ssid'].value == "")
  {
    alert('Fill up the SSID');
    return false;
  }
  else if(document.forms['Setting']['pass'].value == "")
  {
    alert('Fill up the Password');
    return false;
  }
  else if(document.forms['Setting']['host_name'].value == "")
  {
    alert('Fill up the Host Name');
    return false;
  }
  else if(document.forms['Setting']['file_name'].value == "")
  {
    alert('Fill up the File Name');
    return false;
  }
  else if(document.forms['Setting']['WiFi_Mode'].value == "")
  {
    alert('Fill up the WiFi Mode');
    return false;
  }
  else if(document.forms['Setting']['Data_Share'].value == "")
  {
    alert('Fill up the Data Share');
    return false;
  }
  else if(document.forms['Setting']['Heart_Beat'].value == "")
  {
    alert('Fill up the Heart Beat');
    return false;
  }
  else if(document.forms['Setting']['Compass'].value == "")
  {
    alert('Fill up the Compass');
    return false;
  }
}
function WiFi_Mode_OFF()
{
  if((document.getElementById("Data_Share").value == "Web_Share") ||(document.getElementById("Data_Share").value == "Local_Share"))
    document.getElementById("WiFi_Mode").value = "OFF";
}
function Data_Share_OFF()
{
  if((document.getElementById("WiFi_Mode").value == "AP_Mode") ||(document.getElementById("STA_Mode").value == ""))
    document.getElementById("Data_Share").value = "Sharing_OFF";
}
function Clear()
{
  document.getElementById("ssid").value = "";
  document.getElementById("pass").value = "";
  document.getElementById("host_name").value = "";
  document.getElementById("file_name").value = "";
  document.getElementById("WiFi_Mode").value = "";
  document.getElementById("Data_Share").value = "";
  document.getElementById("Heart_Beat").value = "";
  document.getElementById("Compass").value = "";
}
</script>
</head>
<meta name='viewport' content='width=device-width, initial-scale=1'/>
<body onload = "initialisation()" bgcolor="#0099ff">
<center>
<table style="background-color:#0066cc" width=100%>
<tr>
<th style="font-size: 350%">
<font color = #ffffff>SETTINGS</font>
</th>
</tr>
</table>
</br>
<table>
<h3><u><font color = "#0000ff">WiFi STA</font></u></h3>
<form name='Setting' action='ChangeSettings' method='POST' onsubmit='return validateForm()'>
<tr>
<th>
<b>SSID:</b>
</th>
<td><input id = "ssid" name = "ssid" type="textbox"> &nbsp <button style="background-color:#0066cc;color:white" type = "button" onclick="window.location.href='/search'">Search</button></td>
</tr>
<tr></tr><tr></tr><tr></tr><tr></tr>
<tr>
<th>
<b>PASS: </b>
</th>
<td><input id = "pass" name = "password" type="password"> &nbsp &nbsp <button id = "password_hide_btn" style="background-color:#008080;color:white" type = "button" onclick = "show()">show</button></td>
</tr>
<tr></tr><tr></tr><tr></tr><tr></tr>
<tr>
<th><b>HOST: </b></th><td><input id = "host_name" name = "host_name" type="textbox"></td>
</tr>
<tr></tr><tr></tr><tr></tr><tr></tr>
<tr>
<th><b>FILE: </b></th><td><input id = "file_name" name = "file_name" type="textbox"></td>
</tr>
<tr></tr><tr></tr><tr></tr><tr></tr>
<tr>
<th><b>WiFi Mode: </b></th><td><select onchange="Data_Share_OFF()" name="WiFi_Mode" id="WiFi_Mode" value = "OFF">
    <option value="AP_Mode">Access Point</option>
    <option value="STA_Mode">Station</option>
    <option value="OFF">OFF</option>
  </select>
  </td>
</tr>
<tr></tr><tr></tr><tr></tr><tr></tr>
<tr>
<th><b>Data Share: </b></th><td><select onchange="WiFi_Mode_OFF()" name="Data_Share" id="Data_Share">
    <option value="Web_Share">Web Share</option>
    <option value="Local_Share">Local Share</option>
    <option value="Sharing_OFF">Sharing OFF</option>
  </select>
  </td>
</tr>
<tr></tr><tr></tr><tr></tr><tr></tr>
<tr>
<th><b>Heart Beat: </b></th><td><select name="Heart_Beat" id="Heart_Beat">
    <option value="EN">ENABLE</option>
    <option value="DIS">DISABLE</option>
  </select>
  </td>
</tr>
<tr></tr><tr></tr><tr></tr><tr></tr>
<tr>
<th><b>Compass: </b></th><td><select name="Compass" id="Compass">
    <option value="EN">ENABLE</option>
    <option value="DIS">DISABLE</option>
  </select>
  </td>
</tr>
<tr></tr><tr></tr><tr></tr><tr></tr>
<tr>
<th><b>Set Date Time: </b></th><td>
<input type="datetime-local" id="datetime" name="datetime">
  </td>
</tr>
<tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr>
<tr>
<td>
<button id = "clear_btn" style="background-color:green;color:white;width: 75px;height: 30px;" type = "button" onclick="Clear()">clear</button>
</td>
<td>
&nbsp &nbsp <input style="background-color:#0000ff;color:white;width: 75px;height: 30px;" type="submit"/>&nbsp &nbsp &nbsp 
<button style="background-color:red;width: 75px;height: 30px;" type = "button" onclick="window.location.href='/'"><font color="white">Reset</font></button></td></tr>
</form>
</table>
</center>
</body>
</html>
)=====";

UpdateSettingsPage PROGMEM = R"=====(
<html>
<head>
<title>Settings Saved</title>
</head>
<meta name='viewport' content='width=device-width, initial-scale=1'/>
<body bgcolor="#0099ff">
<center>
<table style="background-color:#0066cc" width=100%>
<tr>
<th style="font-size: 350%">
<font color = #ffffff>SETTINGS</font>
</th>
</tr>
</table>
</br></br></br>
<h1 style="font-size: 350%;color:red">Data Saved Successfully</h1>
</br></br>
<a href="/"><button style="font-size: 150%;color: white; background-color: #0066cc">Back</button></a>
</center>
</body>
</html>
)=====";
}

if(EEPROM_Settings[EEPROM_Weather_App_Address] == 2)
{
  HomePage PROGMEM = R"=====(
  <html>
  <head>
 <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <style type="text/css">
body
{  
background-image:url(pictures_weather);
background-position:center;
background-repeat:no-repeat;
background-size:cover;
width:90%;
}
#loader { 
border: 12px solid #f3f3f3; 
border-radius: 50%; 
border-top: 12px solid #444444; 
width: 70px; 
height: 70px; 
animation: spin 1s linear infinite; 
} 
          
@keyframes spin { 
  100% { 
    transform: rotate(360deg); 
  } 
} 
          
.center { 
  position: absolute; 
  top: 0; 
  bottom: 0; 
  left: 0; 
  right: 0; 
  margin: auto; 
}
</style>
</head>
<body>
<div id="loader" class="center"></div>
<script> 
document.onreadystatechange = function() { 
  if (document.readyState !== "complete") { 
    document.querySelector("body").style.visibility = "hidden"; 
    document.querySelector("#loader").style.visibility = "visible"; 
  } else { 
    document.querySelector("#loader").style.display = "none"; 
    document.querySelector("body").style.visibility = "visible";
    setInterval(autoUpdate, 1000);
  }
};

function autoUpdate()
{
  var xmlhttp = new XMLHttpRequest(); 
   
  xmlhttp.onreadystatechange = function() { 
    if (this.readyState == 4 && this.status == 200) { 
        myObj = JSON.parse(this.responseText); 
        document.getElementById("temp").innerHTML = myObj.temp; 
        document.getElementById("hum").innerHTML = myObj.hum; 
        document.getElementById("pre").innerHTML = myObj.pre;
    } 
}; 
xmlhttp.open("GET", "request", true); 
xmlhttp.send();
}

</script> 
<center>
</br></br></br></br>
  
<table>
<tr><h1><th><font size='6px' color=cc0000>&nbsp&nbsp&nbsp&nbsp&nbsp&nbspTemp:-</font></th><th>
<font size='6px' color=00bfff><p id = "temp"></p></font></th><th><img src="pictures_temp" alt="Nature image" width="50"/></th></h1></tr>
  
<tr><h1><th><font size='6px' color=rgb(85,193,129)>&nbsp&nbsp&nbsp&nbsp&nbsp&nbspHum:-</font></th><th>
<font size='6px' color=00bfff><p id = "hum"></p></font></th><th><img src="pictures_hum" alt="Nature image\" width="50"/></th></h1></tr>
  
<tr><h1><th><font size='6px' color='blue'>&nbsp&nbsp&nbsp&nbsp&nbspPre:-</font></th><th>
<font size='6px' color=00bfff><p id = "pre"></p></font></th><th><img src="pictures_pre" alt="Nature image" width="50"/></th></h1></tr>
</table>

</center>
</body>
</html>
  )=====";
  }

  PageNotFound PROGMEM = R"=====(
  <html>
  <head>
 <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  </head>
<body bgcolor="#ffff00">
<center>
</br></br></br></br></br></br></br></br></br></br></br>
<h1 style="color:red; font-size: 350%">404 Bad Request</h1>
</br>
<a href="/"><button style="font-size: 150%;color: white; background-color: #0066cc">Home</button></a>
</center>
</body>
</html>
  )=====";
}

void WiFi_Search()
{
  byte NumSSID = WiFi.scanNetworks();
  Serial.println(NumSSID);
  WiFiSearchPage PROGMEM = R"=====(
  <html>
  <head>
  <title>WiFi Search</title>
  </head>
  <meta name='viewport' content='width=device-width, initial-scale=1'/>
  <body bgcolor="#0099ff">
  <center>
  <table style="background-color:#0066cc" width=100%>
  <tr>
  <th style="font-size: 350%">
  <font color = #ffffff>WiFi Search</font>
  </th>
  </tr>
  </table>
  </br>
  )=====";

  if (NumSSID)
  {
    WiFiSearchPage PROGMEM += R"=====(
    <table border = "2">
    <form action="/" method="post">
    <tr>
    <th style="color: white;background-color: blue;"><center>WiFi SSID</center></th>
    <th style="color: white;background-color: blue;"><center>Strength(dBm)</center></th>
    <th style="color: white;background-color: blue;"><center>Click Here</center></th>
    </tr>
    )=====";
    for (byte i = 0; i < NumSSID; i++)
    {
      String WiFi_Range = (String)WiFi.RSSI(i);
      WiFiSearchPage PROGMEM += R"=====(
      <tr>
      <td style="color:#006699;background-color: #cceeff;"><center><b>
      )=====" + WiFi.SSID(i) + R"=====(
      </b></center></td>
      <td style="color:red;background-color: #cceeff;"><center><b>
      )=====" + WiFi_Range + R"=====(
      </b></center></td>
      <td style="background-color: #80ccff;"><center>
      <button type = "submit" name="ssid" value=")=====" + WiFi.SSID(i) + R"=====(" style="color:white;background-color:#0086b3;width:100%">Select</button>
      </center></td>
      </tr>
      )=====";
    }
    WiFiSearchPage PROGMEM += R"=====(
    </form>
    </table>
    )=====";
  }
  else
  {
    WiFiSearchPage PROGMEM += R"=====(
    <h1 style="color:red;font-size:50px">No Access Point Found</h1>
    )=====";
  }
  WiFiSearchPage PROGMEM += R"=====(
  </br>
  <button style="color:white;background-color:Blue;" onclick="window.location.href='/'">Back</button>
  <button style="color:white;background-color:red;" onclick="window.location.href='/search'">Rescan</button>
  </center>
  </body>
  </html>
  )=====";
}
