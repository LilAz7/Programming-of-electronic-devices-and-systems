const int tempPin = A0; 

void setup() {
  Serial.begin(9600); 
}

void loop() {
  int rawValue = analogRead(tempPin);       
  float voltage = rawValue * (5.0 / 1023); 
  float temperature = voltage * 100.0;     
  
  Serial.print("Температура: ");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(1000); 
}

