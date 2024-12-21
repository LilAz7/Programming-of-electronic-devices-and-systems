int red = 9;
int green = 10;
int blue = 11;


void setup() {
  // put your setup code here, to run once:
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(red, 255); //nilai warna untuk red 0-255
analogWrite(green, 0);
analogWrite(blue, 0);
delay(1000);
analogWrite(red, 0);
analogWrite(green, 255); //nilai warna untuk green 0-255
analogWrite(blue, 0);
delay(1000);
analogWrite(red, 0);
analogWrite(green, 0); 
analogWrite(blue, 255);//nilai warna untuk blue 0-255
delay(1000);
analogWrite(red, 255);
analogWrite(green, 0); 
analogWrite(blue, 255);
delay(1000);
analogWrite(red, 0);
analogWrite(green, 255); 
analogWrite(blue, 255);
delay(1000);
analogWrite(red, 255);
analogWrite(green, 255); 
analogWrite(blue, 0);
delay(1000);
}
