#pragma once

#include <Arduino.h>

struct Motor 
{
  Motor(int dir, int brake, int speed, int percent)
  : dirPin(dir)
  , brakePin(brake)
  , speedPin(speed)
  , speedPercent(percent)
  {}
  int dirPin;
  int brakePin;
  int speedPin;
  int speedPercent;
};


class MotorShield
{
public:
  enum State
  {
    STOPPED,
    FORWARD,
    BACKWARD,
    TURN_POSITIVE,
    TURN_NEGATIVE
  };

  // default constructor: two motors with default pin selection and no speed correction
  MotorShield() = default;  
  // constructor with two motors, user's pin selection
  MotorShield(const Motor & m1, const Motor & m2);

  // constructor with two motors, default pin selection, speed correction
  MotorShield(int m1SpeedPercent, int m2SpeedPercent);

  void init();
  void move(int speed);
  void stop();
  void turn(int speed);
  State getState() const;
private:
  Motor mMotor1 = {12, 9, 3, 100};
  Motor mMotor2 = {13, 8, 11, 100};
  State m_state = STOPPED;
};

