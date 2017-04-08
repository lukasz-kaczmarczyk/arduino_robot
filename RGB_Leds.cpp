#include "RGB_Leds.h"

RGB_Leds::RGB_Leds(int pinRed, int pinGreen, int pinBlue)
{
  _pinRed = pinRed;
  _pinGreen = pinGreen;
  _pinBlue = pinBlue;
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT); 
} 

void RGB_Leds::setColor(int red, int green, int blue)
{
  analogWrite(_pinRed, red);
  analogWrite(_pinGreen, green);
  analogWrite(_pinBlue, blue);  
}