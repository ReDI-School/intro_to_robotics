#include <Arduino.h>
#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int trig, int echo, unsigned maxDistance)
  : mTrig(trig)
  , mEcho(echo)
  , mTimeout(maxDistance * CM_TO_US) 
{ }

void Ultrasonic::init() const
{
  pinMode(mTrig, OUTPUT);
  pinMode(mEcho, INPUT);  
}

unsigned Ultrasonic::ping() const
{
  digitalWrite(mTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(mTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(mTrig, LOW);
  
  return pulseIn(mEcho, HIGH, mTimeout) / CM_TO_US;
}

void Ultrasonic::setMaxDistance(unsigned distance)
{
  mTimeout = distance * CM_TO_US;  
}

