#include "nRF24L01.h"
#include "RF24.h"
#include "MotorShield.h"

int CE_PIN = A4;
int CSN_PIN = A5;

byte address[] = "00001";

RF24 radio(CE_PIN, CSN_PIN);
MotorShield shield;

int xy[2];

void setup() 
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
  shield.init();
  shield.stop();
}

void loop() 
{
  if (radio.available())
  {
    radio.read(&xy, sizeof(xy));
  
    int motor_x = map(xy[0], 0, 1023, -255, 255);
    int motor_y = map(xy[1], 0, 1023, -255, 255);
  
    Serial.print(motor_x);
    Serial.print(" ");
    Serial.println(motor_y);

    if (abs(motor_x) > 100 )
    {
      shield.turn(motor_x);
    }
    else if (abs(motor_y) > 100 )
    {
      shield.move(motor_y);
    }
    else
    {
      shield.stop();
    }
  }
  
}
