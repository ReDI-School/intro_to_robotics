#pragma once

class Ultrasonic 
{
public:
  Ultrasonic(int trigPin, int echoPin, unsigned maxDistance = 200);
  void init() const;
  unsigned ping() const;
  void setMaxDistance(unsigned distance);
private:
  static const int CM_TO_US = 56;

  int mTrig;
  int mEcho;
  unsigned long mTimeout;
};

