#include <TM1637Display.h>

#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO);

const int startStopButtonPin = 4; 
const int resetButtonPin = 5;     

bool isRunning = false;           
unsigned long startTime = 0;     
int timerDuration = 120;         
int remainingTime = timerDuration; 
bool lastStartStopState = LOW;    
bool lastResetState = LOW;       

void setup() {
  pinMode(startStopButtonPin, INPUT_PULLUP); 
  pinMode(resetButtonPin, INPUT_PULLUP);    

  display.setBrightness(7);                  
  display.showNumberDecEx(0b0000, 0, true);  
}

void loop() {
  bool startStopState = digitalRead(startStopButtonPin);
  bool resetState = digitalRead(resetButtonPin);

  if (startStopState == LOW && lastStartStopState == HIGH) {
    isRunning = !isRunning; 
    if (isRunning) {
      startTime = millis(); 
    }
  }
  lastStartStopState = startStopState;

  if (resetState == LOW && lastResetState == HIGH) {
    remainingTime = timerDuration; 
    isRunning = false;             
    updateDisplay();               
  }
  lastResetState = resetState;

  if (isRunning) {
    remainingTime = timerDuration - (millis() - startTime) / 1000;
    if (remainingTime <= 0) {
      remainingTime = 0;
      isRunning = false;
    }
  }

  updateDisplay();
  delay(100); 
}

void updateDisplay() {
  int minutes = remainingTime / 60; 
  int seconds = remainingTime % 60; 

  int displayTime = (minutes * 100) + seconds;

  display.showNumberDecEx(displayTime, 0b01000000, true); // Двоеточие включено
}
