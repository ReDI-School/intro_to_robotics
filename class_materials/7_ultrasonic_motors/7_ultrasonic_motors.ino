#include "Ultrasonic.h"
#include "MotorShield.h"

Ultrasonic sonar(/*TODO Put here trigger pin*/, /*TODO Put here echo pin*/, /*TODO Put here max sensor distance in cm*/); 
MotorShield shield;

void setup() {
  Serial.begin(9600); 
  sonar.init();
  shield.init();
  // random seed initialization is needed if you need random
  randomSeed(analogRead(0));
}

void loop() {
  // this delay is recommended between two ultrasonic measurements
  delay(50); 
}
