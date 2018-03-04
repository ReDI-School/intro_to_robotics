#include <nRF24L01.h>
#include <RF24.h>

int CE_PIN = 7;
int CSN_PIN = 8;

byte address[] = "00001";

char PHRASE_1[] = "You talkin' to me?";
char PHRASE_2[] = "Then who the hell else";
char PHRASE_2_5[] = "are you talking...";
char PHRASE_3[] = "Well I'm the only one here.";
char PHRASE_4[] = "Who the fuck do you think";
char PHRASE_4_5[] = "you're talking to?";
char PHRASE_5[] = "Oh yeah?";
char PHRASE_6[] = "OK.";

RF24 radio(CE_PIN, CSN_PIN);

void setup()
{
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
}

int phrase = 0;

void loop()
{
  switch(phrase)
  {
    case 0:
    case 1:
    case 2:
    case 5:
      radio.write(&PHRASE_1, sizeof(PHRASE_1));
      break;
    case 3:
      radio.write(&PHRASE_2, sizeof(PHRASE_2));
      break;
    case 4:
      radio.write(&PHRASE_2_5, sizeof(PHRASE_2_5));
      break;
    case 6:
      radio.write(&PHRASE_3, sizeof(PHRASE_3));
      break;
    case 7:
      radio.write(&PHRASE_4, sizeof(PHRASE_4));
      break;
    case 8:
      radio.write(&PHRASE_4_5, sizeof(PHRASE_4_5));
      break;
    case 9:
      radio.write(&PHRASE_5, sizeof(PHRASE_5));
      break;
    case 10:
      radio.write(&PHRASE_6, sizeof(PHRASE_6));
      delay(1000);
      break;
  }

  phrase = (phrase >= 10 ? 0 : phrase+1);
  delay(1000);
}
