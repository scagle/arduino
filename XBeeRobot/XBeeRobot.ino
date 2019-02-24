#include <SoftwareSerial.h>

#define LEFT_PWM 9
#define RIGHT_PWM 10
#define trigPin 13
#define echoPin 12

int right, left = 0;
int dir = 0;
SoftwareSerial XBee(2, 3);

void setup() {
  XBee.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  pinMode(LEFT_PWM, OUTPUT);
  pinMode(RIGHT_PWM, OUTPUT);
  Serial.begin(9600);
  
  rest();
}

void loop() {
  /*long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if ((distance > 1) && (distance < 100))
  {
    Serial.println(distance);
  }
  if (distance > 3 && distance < 10)
  {
    
  }
  */
  if (XBee.available())
  {
    char ch = XBee.read();
    Serial.println(ch);
    
    switch (ch)
    {
        case 'w':
          dir = 1;
          forward();
          break;
        case 's':
          dir = -1;
          back();
          break;
        case 'q':
          dir = 0;
          rest();
          break;
        case 'd':
          if (left > 0)
          {
            left-=5;
          }
          else
          {
            right+=5;
          }
          if (dir == 1) forward(); if (dir == -1) back();
          break;
        case 'a':
          if (right > 0)
          {
            right-=5;
          }
          else
          {
            left+=5;
          }
          if (dir == 1) forward(); if (dir == -1) back();
          break;
    }
  }
}
void rest()
{
  analogWrite(RIGHT_PWM, 0);
  analogWrite(LEFT_PWM, 0);
  right = 0;
  left = 0;
}
void forward()
{
  analogWrite(RIGHT_PWM, 240-right);
  analogWrite(LEFT_PWM, 140+left);
}

void back()
{
  analogWrite(RIGHT_PWM, 140+right);
  analogWrite(LEFT_PWM, 240-left);
}

