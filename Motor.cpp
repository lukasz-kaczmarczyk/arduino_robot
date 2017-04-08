#include "Motor.h"

//static struct motor_t;

Motor::Motor(int in1, int in2, int in3, int in4, int en_a, int en_b)
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(en_a, OUTPUT);
  pinMode(en_b, OUTPUT);
  
  _in1 = in1;
  _in2 = in2;
  _in3 = in3;
  _in4 = in4;
  _en_a = en_a;
  _en_b = en_b;
}

/*
void Motor::moveBackward(int time)
{
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, HIGH);
    digitalWrite(_in3, HIGH);
    digitalWrite(_in4, LOW);
    analogWrite(_en_a,80);
    analogWrite(_en_b,80);
   	delay(time); 
}
*/
void Motor::moveBackward(int time, int speed)
{
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, HIGH);
    digitalWrite(_in3, HIGH);
    digitalWrite(_in4, LOW);
    analogWrite(_en_a,speed);
    analogWrite(_en_b,speed);
   	delay(time); 
}

void Motor::moveForward()
{
  digitalWrite(_in1, HIGH);
  digitalWrite(_in2, LOW);
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, HIGH);
  analogWrite(_en_a,100);
  analogWrite(_en_b,100);
}

void Motor::turnRight(int time)
{
      digitalWrite(_in1, HIGH);
      digitalWrite(_in2, LOW);
      digitalWrite(_in3, LOW);
      digitalWrite(_in4, LOW);
      analogWrite(_en_a,80);
      analogWrite(_en_b,0); 
      Serial.println("right");
      delay(time); 
}

void Motor::turnLeft(int time)
{
      digitalWrite(_in1, LOW);
      digitalWrite(_in2, LOW);
      digitalWrite(_in3, LOW);
      digitalWrite(_in4, HIGH);
      analogWrite(_en_a,0);
      analogWrite(_en_b,80); 
      Serial.println("left");
      delay(500); 
}

void Motor::stopMove()
{
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, LOW);
    digitalWrite(_in3, LOW);
    digitalWrite(_in4, LOW);
    analogWrite(_en_a,0);
    analogWrite(_en_b,0); 
}


static struct {
  int in1;
  int in2;
  int pwn;
}motor_t;

