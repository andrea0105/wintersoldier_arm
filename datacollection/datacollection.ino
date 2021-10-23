const int RED = 22;
const int GREEN = 23;
int n = 0;

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  Serial.println("Be Ready in 5 seconds");
  digitalWrite(RED, LOW);
  delay(5000);
  digitalWrite(RED, HIGH);
}

void loop() {
  digitalWrite(GREEN, LOW);
  float emg = 0;
  float mav = 0;
  for (int j = 0; j < 500; j++) {
    for (int i = 0; i < 100; i++) {
    emg = analogRead(A0) / 1024;
    }
  mav = emg / 100;
  Serial.write(mav);
  delay(1);
  }
  n += 1;
  Serial.write(n);
  digitalWrite(GREEN, HIGH);
  if (n == 100) {
   Serial.write('%'); 
  }
}
