void setup( )
{
  pinMode(13, OUTPUT);
}

void loop( )
{
  if(analogRead(5) < 512)
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
}
