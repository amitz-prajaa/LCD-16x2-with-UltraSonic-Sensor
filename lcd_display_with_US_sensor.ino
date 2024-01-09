#include <LiquidCrystal.h>

LiquidCrystal lcd(4, 6, 10, 12, 14, 16);  // Set the LCD I2C address and size (16x2)
const int triger = 18 ;
const int echo = 20 ;
long duration ;
int  distance ;

void setup() {
//   Serial.begin(9600);
      pinMode(triger , OUTPUT);
      pinMode(echo , INPUT);
}

void loop() {
  // Your loop code here

   digitalWrite(triger, LOW);
  delayMicroseconds(2);

  // Set the trigPin high for 10 microseconds
  digitalWrite(triger, HIGH);
  delayMicroseconds(10);
  digitalWrite(triger, LOW);

  // Measure the echoPin duration
  duration = pulseIn(echo, HIGH);
      
  // Calculate the distance
  distance = duration * 0.034 / 2;


  lcd.setCursor(0,0);
  lcd.print("Distance : ");
  lcd.print(distance);
  delay(1000);
  lcd.clear();

 

  
}
