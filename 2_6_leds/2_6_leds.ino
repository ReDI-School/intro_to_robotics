void setup()
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}


void loop()
{
  for(int i = 7; i <= 12; i++)
  {
    digitalWrite(i, HIGH);
    delay(500);    
    digitalWrite(i, LOW);
  }
}

