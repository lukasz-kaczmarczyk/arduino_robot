#include "Distance.h"

Distance::Distance(int echoPin, int trigPin)
{
  _echoPin = echoPin;
  _trigPin = trigPin;
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
} 

long Distance::getDistance()
{
  long dur, dist;
  digitalWrite(_trigPin, LOW); 
  delayMicroseconds(2); 

  digitalWrite(_trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(_trigPin, LOW);
 dur = pulseIn(_echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 dist = (dur/2) / 29.1;
 return dist; 
}
