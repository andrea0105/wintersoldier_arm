void setup() {
  Serial.begin(9600);
}

float sensing() {
  float mav = 0;
  for (int i = 0; i < 1000; i++)
  {
    float emg = analogRead(A0);
    mav += emg;
    if (i == 999)
    {
      mav = mav / (i+1);
      return mav;
    }
    else
      continue;
  }
}

void loop() {
  float value = 0;
  value = sensing();
  Serial.println(value);
  delay(1);
}
