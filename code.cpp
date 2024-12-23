const int tempPin = A0; // Пин, к которому подключен датчик LM35
const float BETA = 3950;

void setup() {
  Serial.begin(9600); // Инициализация Serial Monitor
}

void loop() {
  int rawValue = analogRead(tempPin);       // Считываем аналоговое значение (0-1023)
  /*float voltage = rawValue * (5.0 / 1023);*/
 
  float temp = 1 / (log(1 / (1023. / rawValue - 1)) / BETA + 1.0 / 298.15) - 273.15; // Преобразуем в напряжение (в вольтах)
  /*float temperature = voltage * 100.0;     // Преобразуем напряжение в температуру (°C)*/
  
  // Выводим данные в Serial Monitor
  Serial.print("Температура: ");
  Serial.print(temp);
  Serial.println(" °C");

  delay(1000); // Задержка 1 секунда
}

