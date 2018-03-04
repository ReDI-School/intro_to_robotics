#include "MotorShield.h"

MotorShield shield;

void setup()
{
  Serial.begin(9600);
  shield.init();
}

void loop()
{
}
