const byte audioPin =  6;
const byte trigPin  = 11;
const byte echoPin  = 12;

long duration, cm, inches;

void setup() {
  Serial.begin (9600);
  pinMode(audioPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  for (int frequency = 100; frequency < 1000; frequency += 40) {
    int duration = readPotMeter();
    int distance = readDistance();
    tone(audioPin, frequency + distance);
    delay(duration);
  }
}

int readPotMeter() {
  return map(analogRead(A4), 0, 1023, 8, 100);
}

int readDistance() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  int distance = pulseIn(echoPin, HIGH);

  // Convert the time into a distance
  // cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  //  nches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135

  // meting is soms opeens heel ver weg
  while (distance > 10000) {
    distance = 10000;
  }

  return map(distance, 0, 10000, 0, 500);
}
