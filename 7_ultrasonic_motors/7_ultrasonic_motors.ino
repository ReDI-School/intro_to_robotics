#include "Ultrasonic.h"
#include "MotorShield.h"

int TRIGGER_PIN = A5;
int ECHO_PIN = A4;
int MAX_DISTANCE = 200;
int AVOIDANCE_DISTANCE_CM = 20;

int PING_INTERVAL_MS = 50;
int TURN_TIME_MS = 500;

int SPEED = 200; 

Ultrasonic sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
MotorShield shield;

void setup() {
  Serial.begin(9600); 
  sonar.init();
  shield.init();
}

void loop() {
  delay(PING_INTERVAL_MS);  
             
  int distCm = sonar.ping();        

  if (distCm > 0 && distCm < AVOIDANCE_DISTANCE_CM) 
  {   
    // turn
    shield.turn(SPEED);
    
    delay(TURN_TIME_MS); 
  }
  else if (shield.getState() != MotorShield::FORWARD)
  {
    shield.move(SPEED);   
  }
}
