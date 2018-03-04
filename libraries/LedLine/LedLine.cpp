#include "LedLine.h"
#include "Arduino.h"

LedLine::LedLine(int num, const int* const p)
{
  if (num > 0) 
  {
    mLedsNum = num;
    mPins = new int [mLedsNum];
    
    for (int i = 0; i < mLedsNum; ++i)
    {
      mPins[i] = p[i];  
    }
  }
}

LedLine::~LedLine()
{
  delete [] mPins;  
}

void LedLine::init() const
{   
  for (int i = 0; i < mLedsNum; ++i)
  {
    pinMode(mPins[i], OUTPUT);
  }
  setLeds(0);  
}

void LedLine::setLeds(unsigned mask) const
{
  if (mLedsNum > 0) 
  {
    for (int i = 0; i < mLedsNum; ++i) 
    {
      if (mask & 1) // last bit of num is 1
      {
        digitalWrite(mPins[i], HIGH);
      }
      else
      {
        digitalWrite(mPins[i], LOW);
      }
      mask >>= 1;
    }
  }
}

void LedLine::initAnimation()
{
  if (mLedsNum > 0)
  {
    setLeds(0);  
    // set the current led to the last one, as on every step we 
    // turn current led off and turn the next one on
    mCurAnimationLed = mLedsNum - 1;
  } 
}

void LedLine::nextAnimationStep(int delayMs)
{
  if (mLedsNum > 0)
  {
    digitalWrite(mPins[mCurAnimationLed], LOW);
    mCurAnimationLed = (mCurAnimationLed >= (mLedsNum - 1) ? 0 : mCurAnimationLed + 1);    
    digitalWrite(mPins[mCurAnimationLed], HIGH);
    delay(delayMs);
  }
}

