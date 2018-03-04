#include "Ultrasonic.h"

Ultrasonic sonar(/*TODO Put here trigger pin*/, /*TODO Put here echo pin*/, /*TODO Put here max sensor distance in cm*/); 

void setup() {
  Serial.begin(9600); 
  sonar.init();
}

void loop() {
  // this delay is recommended between two ultrasonic measurements
  delay(50); 
}
