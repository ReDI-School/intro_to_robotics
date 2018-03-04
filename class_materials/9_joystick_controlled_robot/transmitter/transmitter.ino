// TODO: RF24 by TMRh20 library must be installed in Arduino IDE
// use Sketch->Include Library->Manage Libraries menu

#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(/*TODO add CE pin here*/, /*TODO add CSN pin here*/);

void setup() 
{
  radio.begin();
  radio.openWritingPipe(/*TODO add address here*/);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
  Serial.begin(9600);
}

void loop() 
{
  // Some minimum delay is recommended between transmissions
  delay(50);
}
