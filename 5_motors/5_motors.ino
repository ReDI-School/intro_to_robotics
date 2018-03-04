#include "MotorShield.h"

MotorShield shield;

const int SPEED = 200;

int RUN_MS = 2000;
int STOP_MS = 1000;
int TURN_MS = 1000;

void setup()
{
  Serial.begin(9600);
  shield.init();
}

void loop()
{
  shield.move(SPEED);
  delay(RUN_MS);

  shield.stop();
  delay(STOP_MS);

  shield.move(-SPEED);
  delay(RUN_MS);

  shield.stop();
  delay(STOP_MS);
  
  shield.turn(SPEED);
  delay(TURN_MS);

  shield.stop();
  delay(STOP_MS);

  shield.turn(-SPEED);
  delay(TURN_MS);

  shield.stop();
  delay(STOP_MS);
}
