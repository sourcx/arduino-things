// Nodig:
// Sluit 11 LEDs aan op 2-12
// Sluit je potentionmeter aan op A4

void setup() {
  for (int i = 2; i <= 12; ++i) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  int meting = map(analogRead(A4), 0, 1023, 12, 2);
  
  for (int i = 2; i <= 12; ++i) {
    digitalWrite(i, LOW);  
  }

  digitalWrite(meting, HIGH);
}
