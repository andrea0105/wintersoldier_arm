void setup() {
  Serial.begin(9600);
  int n = 0;
}

void loop() {
  float mav = 0;
  float emg = 0;
  for (int j = 0; j < 1000; j++) {
    for (int i = 0; i < 100; i++) {
    emg = analogRead(A0) / 1024;
    mav += emg;
    }
  mav = mav / 100;
  Serial.print(mav);
  delay(1);
  }
  n += 1;
  Serial.println("%d[s]",n);
  if (n == 60)
    break;
}
