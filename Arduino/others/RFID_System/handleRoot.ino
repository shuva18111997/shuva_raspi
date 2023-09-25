void handleRoot() {
  RFID_Access();
  String red = server.arg(0);          // read RGB arguments
  String green = server.arg(1);
  String blue = server.arg(2);
  RFID_Access();
  analogWrite(red_pin, green.toInt());
  analogWrite(green_pin, blue.toInt());
  analogWrite(blue_pin, red.toInt());
  RFID_Access();
  /*display.clearDisplay();
  display.setCursor(0, 10);
  display.println(green.toInt());
  display.println(blue.toInt());
  display.println(red.toInt());
  display.display();*/
  RFID_Access();
  String webpage;
  webpage += "<!DOCTYPE HTML>\r\n";
  webpage += "<html>\r\n";
  webpage += "<header><title>ESP8266 RGB LED</title><h1>ESP8266 RGBLED</h1></header>";

  webpage += "<head>";
  webpage += "<meta name='mobile-web-app-capable' content='yes' />";
  webpage += "<meta name='viewport' content='width=device-width' />";
  webpage += "</head>";

  webpage += "<body style='margin: 0px; padding: 0px;'>";
  webpage += "<canvas id='colorspace'></canvas></body>";

  webpage += "<script type='text/javascript'>";
  webpage += "(function () {";
  webpage += " var canvas = document.getElementById('colorspace');";
  webpage += " var ctx = canvas.getContext('2d');";
  webpage += " function drawCanvas() {";
  webpage += " var colours = ctx.createLinearGradient(0, 0, window.innerWidth, 0);";
  webpage += " for(var i=0; i <= 360; i+=10) {";
  webpage += " colours.addColorStop(i/360, 'hsl(' + i + ', 100%, 50%)');";
  webpage += " }";

  webpage += " ctx.fillStyle = colours;";
  webpage += " ctx.fillRect(0, 0, window.innerWidth, window.innerHeight);";
  webpage += " var luminance = ctx.createLinearGradient(0, 0, 0, ctx.canvas.height);";
  webpage += " luminance.addColorStop(0, '#ffffff');";
  webpage += " luminance.addColorStop(0.05, '#ffffff');";
  webpage += " luminance.addColorStop(0.5, 'rgba(0,0,0,0)');";
  webpage += " luminance.addColorStop(0.95, '#000000');";
  webpage += " luminance.addColorStop(1, '#000000');";
  webpage += " ctx.fillStyle = luminance;";
  webpage += " ctx.fillRect(0, 0, ctx.canvas.width, ctx.canvas.height);";
  webpage += " }";
  webpage += " var eventLocked = false;";

  webpage += " function handleEvent(clientX, clientY) {";
  webpage += " if(eventLocked) {";
  webpage += " return;";
  webpage += " }";

  webpage += " function colourCorrect(v) {";
  webpage += " return Math.round(1023-(v*v)/64);";
  webpage += " }";
  webpage += " var data = ctx.getImageData(clientX, clientY, 1, 1).data;";
  webpage += " var params = [";
  webpage += " 'r=' + colourCorrect(data[0]),";
  webpage += " 'g=' + colourCorrect(data[1]),";
  webpage += " 'b=' + colourCorrect(data[2])";
  webpage += " ].join('&');";
  webpage += " var req = new XMLHttpRequest();";
  webpage += " req.open('POST', '?' + params, true);";
  webpage += " req.send();";
  webpage += " eventLocked = true;";
  webpage += " req.onreadystatechange = function() {";
  webpage += " if(req.readyState == 4) {";
  webpage += " eventLocked = false;";
  webpage += " }";
  webpage += " }";
  webpage += " }";
  webpage += " canvas.addEventListener('click', function(event) {";
  webpage += " handleEvent(event.clientX, event.clientY, true);";
  webpage += " }, false);";
  webpage += " canvas.addEventListener('touchmove', function(event){";
  webpage += " handleEvent(event.touches[0].clientX, event.touches[0].clientY);";
  webpage += "}, false);";
  webpage += " function resizeCanvas() {";
  webpage += " canvas.width = window.innerWidth;";
  webpage += " canvas.height = window.innerHeight;";
  webpage += " drawCanvas();";
  webpage += " }";

  webpage += " window.addEventListener('resize', resizeCanvas, false);";
  webpage += " resizeCanvas();";
  webpage += " drawCanvas();";
  webpage += " document.ontouchmove = function(e) {e.preventDefault()};";
  webpage += " })();";
  webpage += "</script><html>\r\n";
  RFID_Access();
  RFID_Access();
  RFID_Access();
  RFID_Access();
  RFID_Access();
  server.send(200, "text/html", webpage);
  RFID_Access();
  RFID_Access();
  RFID_Access();
  RFID_Access();
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}
