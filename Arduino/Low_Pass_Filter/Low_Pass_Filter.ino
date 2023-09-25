//Y(n) = Y(n - 1) + Σ(h(k) * X(n - k))
//Y(n) = Y(n - 1) + X(n)*h(0) + X(n-1)*h(1)
//Y(0) = Y(0 - 1) + (X(0)*h(0) + X(0-1)*h(1)) X(Not Possible)
//Y(1) = Y(0) + (X(1)*h(0) + X(0)*h(1))
//Y(2) = Y(1) + (X(2)*h(0) + X(1)*h(1))
//Y(3) = Y(2) + (X(3)*h(0) + X(2)*h(1))
//. . . . .
//Y(N) = Y(N - 1) + (X(N)*h(0) + X(N - 1)*h(1))
float xn1 = 0;
float yn1 = 0;
int k = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  float xn = analogRead(36); //For ESP32
  //float xn = analogRead(A0);  //For Arduino

  // Compute the filtered signal
  float yn = 0.93908194*yn1 + 0.03045903*xn + 0.03045903*xn1;

  delay(1);
  xn1 = xn;
  yn1 = yn;

  if(k % 3 == 0){
    // This extra conditional statement is here to reduce
    // the number of times the data is sent through the serial port
    // because sending data through the serial port
    // messes with the sampling frequency
  
    // Output
    Serial.print(2*xn);
    Serial.print(" ");
    Serial.println(2*yn);
    delayMicroseconds(500);
  }
  k = k+1;
}
