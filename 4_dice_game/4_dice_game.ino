int BUTTON_PIN = 2;  
int LEDS_NUM = 6;
int ANIMATION_DELAY = 100;
 
void setup() 
{  
  Serial.begin(9600);
  
  pinMode(BUTTON_PIN, INPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  
  randomSeed(analogRead(0));
}

void resetAllLeds()
{
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

void setAllLeds()
{
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
}

int lastButtonState = 0;
long randomNum = 0;

void loop() 
{
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH) 
  { 
    resetAllLeds();  
    delay(ANIMATION_DELAY);
    setAllLeds();  
    delay(ANIMATION_DELAY);
  }
  else // buttonState == LOW
  {
    if (lastButtonState == HIGH)
    {
      resetAllLeds();  
      randomNum = random(7, 13);
      
      Serial.println(randomNum - 7);
    
      for (int i = 7; i < 13; i++)
      {
        if (i < randomNum)
        {
          digitalWrite(i, HIGH);
        }
        else
        {
          digitalWrite(i, LOW);  
        }
      }
    }
  }
  lastButtonState = buttonState;
}

