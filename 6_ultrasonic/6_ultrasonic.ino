#include "Ultrasonic.h"

int TRIGGER_PIN = 12;
int ECHO_PIN = 11;
unsigned MAX_DISTANCE = 200;

Ultrasonic sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() {
  Serial.begin(9600); 
  sonar.init();
}

void loop() {
  delay(50);                     
  Serial.print("Ping: ");
  Serial.print(sonar.ping()); 
  Serial.println("cm");
}
