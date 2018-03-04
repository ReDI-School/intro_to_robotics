// TODO: RF24 by TMRh20 library must be installed in Arduino IDE
// use Sketch->Include Library->Manage Libraries menu

#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(/*TODO add CE pin here*/, /*TODO add CSN pin here*/);

void setup() 
{
  Serial.begin(c);
  radio.begin();
  radio.openReadingPipe(0, /*TODO add address here*/);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
}

void loop() 
{
}
