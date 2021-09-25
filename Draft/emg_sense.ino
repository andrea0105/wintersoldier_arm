void setup() {
  Serial.begin(9600);
}

float sensing() {
  float mav = 0;
  for (int i = 0; i < 100; i++)
  {
    float emg = analogRead(A0);
    mav += emg;
    if (i == 99)
    {
      mav = mav / 100;
      return mav;
    }
  }
}

void loop() {
  float value = 0;
  value = sensing();
  Serial.println(value);
  delay(1);
}
