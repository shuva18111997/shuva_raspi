#include<ESP8266WiFi.h>
#include <math.h>

const char* ssid = "shuva";
const char* password = "39039820";

double ThermistorC(int RawADC) {
  double Temp;
  Temp = log(10000.0 * ((1024.0 / RawADC - 1)));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp )) * Temp );
  Temp = Temp - 273.15;
  return Temp;
}
WiFiServer server(80);
void setup() {
  Serial.begin(115200);
  delay(10);

  // conect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected");

  //start the server
  server.begin();
  Serial.println("Server Started");


  // Print the  IP ADRESS
  Serial.println("USE THE URL TO CONNECT: ");
  Serial.println("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");




}

void loop() {
  // Check if a client has connected
  WiFiClient Client = server.available();
  if (!Client) {
    return;
  }
  // Wait until the client sends some data
  Serial.println("new Client");
  while (!Client.available()) {
    delay(1);
  }
  //Read the first line of the request
  String request = Client.readStringUntil('\r');
  Serial.println(request);
  Client.flush();

}




  // Return the responce
  Client.println("HTTP/1.1 200 OK");
  Client.println("Content-Type: text/html") ;
  Client.println("");//   do not forgot this line
  Client.println("<!DOCTYPE HTML>");
  Client.println("<HTML>");
  Client.println("<meta http-equiv= \"refresh\" content=\"10\">");

  Client.print("Temperature in 'C' is: ");

  Client.println("<br>-<br>");
  Client.println("temperature :");
  int valC;
  valC = analogRead(A0);
  float  tempC = ThermistorC(valC);

  Client.println(tempC);
  Client.println(" *C");
  Client.println("<br>-<br>");
  Client.println("</html>");


  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");

}
