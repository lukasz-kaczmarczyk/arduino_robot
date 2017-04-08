#ifndef DISTANCE_H
#define DISTANCE_H

#include "Arduino.h"


class Distance
{
  public:
    Distance(int echoPin, int trigPin);
    long getDistance();

  private:
  	int _echoPin, _trigPin;
};

#endif
