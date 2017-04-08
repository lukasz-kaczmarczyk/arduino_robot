#ifndef RGB_LEDS
#define RGB_LEDS

#include "Arduino.h"


class RGB_Leds
{
  public:
    RGB_Leds(int pinRed, int pinGreen, int pinBlue);
    void setColor(int red, int green, int blue);

  private:
  	int _pinGreen, _pinBlue, _pinRed;
};

#endif
