#include <TM1637Display.h>

#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO);

const int incrementButtonPin = 4; 
const int resetButtonPin = 5;     

int counter = 0;                  
bool lastIncrementState = LOW;    
bool lastResetState = LOW;        

void setup() {
  pinMode(incrementButtonPin, INPUT_PULLUP); 
  pinMode(resetButtonPin, INPUT_PULLUP);     

  display.setBrightness(7);                  
  display.showNumberDec(counter);            
}

void loop() {
  bool incrementState = digitalRead(incrementButtonPin);
  bool resetState = digitalRead(resetButtonPin);

  if (incrementState == LOW && lastIncrementState == HIGH) {
    counter++; 
    if (counter > 9999) { 
      counter = 0;
    }
    updateDisplay();
  }
  lastIncrementState = incrementState;

  if (resetState == LOW && lastResetState == HIGH) {
    counter = 0; 
    updateDisplay();
  }
  lastResetState = resetState;

  delay(50); 
}

void updateDisplay() {
  display.showNumberDec(counter); 
}

