int BUTTON_PIN = 2;    
int LED_PIN =  13; //built in LED  

void setup() 
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() 
{
  int buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == HIGH) 
  {
    digitalWrite(LED_PIN, HIGH);
  } 
  else 
  {  
    digitalWrite(LED_PIN, LOW);
  }
}
