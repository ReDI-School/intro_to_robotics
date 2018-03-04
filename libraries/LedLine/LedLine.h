#pragma once

class LedLine
{
public:
  LedLine(int num, const int* const p);
  ~LedLine();
  void init() const;   
  void setLeds(unsigned mask) const;
  void initAnimation();
  void nextAnimationStep(int delayMs); 
private:  
  int * mPins = nullptr;
  int mLedsNum = 0;
  int mCurAnimationLed = 0;
};
