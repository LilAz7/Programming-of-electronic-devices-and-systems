const int startStopButtonPin = 2; 
const int resetButtonPin = 3;     

bool isRunning = false;           
unsigned long startTime = 0;      
unsigned long elapsedTime = 0;    
bool lastStartStopState = LOW;    
bool lastResetState = LOW;        

void setup() {
  pinMode(startStopButtonPin, INPUT_PULLUP); 
  pinMode(resetButtonPin, INPUT_PULLUP);     
  Serial.begin(9600);                        
}

void loop() {
  bool startStopState = digitalRead(startStopButtonPin);
  bool resetState = digitalRead(resetButtonPin);

  if (startStopState == LOW && lastStartStopState == HIGH) {
    isRunning = !isRunning; 
    if (isRunning) {
      startTime = millis() - elapsedTime; 
    }
  }
  lastStartStopState = startStopState;

  if (resetState == LOW && lastResetState == HIGH) {
    elapsedTime = 0; 
    isRunning = false;
  }
  lastResetState = resetState;

  if (isRunning) {
    elapsedTime = millis() - startTime;
  }

  Serial.print("Секундомер: ");
  Serial.println(elapsedTime / 1000.0, 2); 
  delay(100); 
}

