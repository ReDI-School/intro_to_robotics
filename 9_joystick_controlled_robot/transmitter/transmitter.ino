#include <nRF24L01.h>
#include <RF24.h>

int CE_PIN = 7;
int CSN_PIN = 8;

byte address[] = "00001";

int JOYSTICK_X = A0;
int JOYSTICK_Y = A1;

RF24 radio(CE_PIN, CSN_PIN);

void setup()
{
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
}

int xy[2];

void loop() 
{
  xy[0] = analogRead(JOYSTICK_X);

  xy[1] = analogRead(JOYSTICK_Y);

  // readings sending
  radio.write(&xy, sizeof(xy));
  delay(50);
}

