#include <Servo.h>
#include "Motor.h"
#include "RGB_Leds.h"
#include "Distance.h"

//times definitions
#define TIME_BACKWARD 1000 //1s
#define TIME_TURN 500      //0.5s
#define TIME_EXPLORE 1000  //1s
#define TIME_EXPLORE_FRONT 200 //0.2s
#define TIME_START 2000

//speed definitions: min 0, max 255
#define SPEED_BACKWARD 100

#define FALSE 0
#define TRUE 1

// buzer
#define BUZZER_PIN 19 //buzzer to arduino pin A5
#define FREQ_VALUE 555
#define TIME_ON 1000
#define TIME_OFF 500

//Servo
Servo myservo;  // create servo object to control a servo
#define SERVO_PIN 12

// Motor 1
#define IN1 13
#define IN2 8
#define EN_A 3 // Needs to be a PWM pin to be able to control motor speed

// Motor 2
#define IN3 2
#define IN4 4
#define EN_B 5 // Needs to be a PWM pin to be able to control motor speed

//ultrasonic definitions
#define TRIG_PIN 6
#define ECHO_PIN 7

//leds pinout:
#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11



//macros
#define LIGHT_RED myLeds.setColor(255,0,0) //red

long distanceFront, distanceLeft, distanceRight;
bool ifObstacle = FALSE;

Motor myMotor(IN1,IN2,IN3,IN4,EN_A,EN_B);
RGB_Leds myLeds(RED_PIN, GREEN_PIN, BLUE_PIN);
Distance myDistance(ECHO_PIN, TRIG_PIN);
  
void setup() {
  pinMode(BUZZER_PIN, OUTPUT);  
  myservo.attach(SERVO_PIN); 
  

  myservo.write(90);
  myLeds.setColor(0,255,0); //green

  delay(TIME_START);
  myMotor.moveForward(); 

}

void loop()
{  
  //get distance in front of robot
  distanceFront = myDistance.getDistance();

  if( distanceFront < 50 )
  {
    ifObstacle = TRUE;
    myMotor.stopMove();
    myservo.write(0);
    myLeds.setColor(255,255,255); //all
    delay(TIME_EXPLORE);

    
    distanceLeft = myDistance.getDistance();
    myservo.write(180);
    delay(TIME_EXPLORE);
    
    distanceRight = myDistance.getDistance();
    myservo.write(90);
    myLeds.setColor(255,0,0); //red
    digitalWrite(BUZZER_PIN, HIGH);
    myMotor.moveBackward(TIME_BACKWARD);
    if( distanceLeft < distanceRight )
    {
      myLeds.setColor(0,0,255); //blue
      myMotor.turnRight(TIME_TURN);
      digitalWrite(BUZZER_PIN, LOW);
    }
    else
    {
      myLeds.setColor(0,0,255); //blue
      myMotor.turnLeft(TIME_TURN);
      digitalWrite(BUZZER_PIN, LOW);
    }
  }
  else
  {
    if(TRUE == ifObstacle)
    {
      myLeds.setColor(0,255,0); //green
      myMotor.moveForward(); 
      
    }
  }
  
  delay(TIME_EXPLORE_FRONT);
  
}







  
  
