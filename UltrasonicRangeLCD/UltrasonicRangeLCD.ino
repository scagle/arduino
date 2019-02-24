#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 5, 4, 3, 2);


#define trigPin 13
#define echoPin 12

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  long inches = microsecondsToInches(duration);
  long cm = microsecondsToCentimeters(duration);
  if (cm == 0 && inches == 0)
  {
    lcd.clear();
    lcd.print("  Too far away");
  }
  else if (cm < 200 && inches < 200)
  {
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("About ");
    lcd.print(inches);
    lcd.setCursor(12, 0);
    lcd.print("in");
    lcd.setCursor(0,1);
    lcd.print("& About ");
    lcd.print(cm);
    lcd.setCursor(12, 1);
    lcd.print("cm");
    delay(200);
  }
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
