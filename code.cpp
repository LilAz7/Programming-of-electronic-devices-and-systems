const int buzzerPin = 8;
const int potPin = A0;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);
  int frequency = map(potValue, 0, 1023, 100, 2000);
  tone(buzzerPin, frequency);
  delay(10);
}

