const int buzzerPin = 8;
const int buttonPin = 2;

int buttonState = 0;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    tone(buzzerPin, 1000); 
  } else {
    noTone(buzzerPin); 
  }
}



