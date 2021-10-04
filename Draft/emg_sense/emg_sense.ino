void setup() {
  Serial.begin(9600);
}

void loop() {
  float mav = 0;
  for (int i = 0; i < 99; i++)
  {
    emg = analogRead(A0);
    delayMicroseconds(10);
    mav += emg;
  }
  emg = emg / 100;
  Serial.println(emg);
}
