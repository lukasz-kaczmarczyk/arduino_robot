#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"


class Motor
{
  public:
    Motor(int in1, int in2, int in3, int in4, int en_a, int en_b);
    //void moveBackward(int time);
    void moveBackward(int time, int speed = 100);
    void moveForward();
    void turnRight(int time);
    void turnLeft(int time);
    void stopMove();

  private:
  	int _in1, _in2, _in3, _in4, _en_a, _en_b;
};

#endif
