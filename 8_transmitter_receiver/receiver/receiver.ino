#include <nRF24L01.h>
#include <RF24.h>

int CE_PIN = 7;
int CSN_PIN = 8;

byte address[] = "00001";

RF24 radio(CE_PIN, CSN_PIN);

void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
}
void loop()
{
  if (radio.available())
  {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}
