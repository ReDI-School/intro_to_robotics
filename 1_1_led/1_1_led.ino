
int LED_PIN = 12;
int DELAY = 500; //ms

void setup()
{
  pinMode(LED_PIN, OUTPUT);   
}

void loop()
{
  digitalWrite(LED_PIN, HIGH);
  delay(DELAY);                 
  digitalWrite(LED_PIN, LOW); 
  delay(DELAY);    
}
