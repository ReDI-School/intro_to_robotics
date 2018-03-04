// TODO: Customized RF24 library is used here (files are copied to the project folder). 
// Remove RF24 from Arduino IDE if you installed it before

#include "nRF24L01.h"
#include "RF24.h"
#include "MotorShield.h"

RF24 radio(/*TODO add CE pin here*/, /*TODO add CSN pin here*/);
MotorShield shield;

void setup() 
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, /*TODO add address here*/);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
  shield.init();
  shield.stop();
}



void loop() 
{
}
