const int NR_PINS = 11;
const int ledPins[NR_PINS] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
const int MIN_DELAY = 30; // ms
const int MAX_DELAY = 250; // ms
int delayVal = MAX_DELAY;

void setup() {
  Serial.begin(9600);
  for (int i = 1; i <= NR_PINS; ++i) {
    pinMode(ledPins[i + 1], OUTPUT);
  }
}

void blink(int pin, int delayVal) {
  //  Serial.println(pin, DEC);
  digitalWrite(ledPins[pin], HIGH);
  delay(delayVal);
  digitalWrite(ledPins[pin], LOW);
}

int getDelayFromPotMeter() {
  int potentioMeterValue = analogRead(A4);
  Serial.print("potentioMeterValue ");
  Serial.println(potentioMeterValue, DEC);
  return map(potentioMeterValue, 0, 1023, MAX_DELAY, MIN_DELAY);
}

void loop() {
  for (int i = 0; i < NR_PINS; ++i) {
    blink(i, getDelayFromPotMeter());
  }

  for (int i = NR_PINS - 2; i > 0; --i) {
    blink(i, getDelayFromPotMeter());
  }
}
