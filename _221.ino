void setup( )
{
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
}

void light( )
{
  if(analogRead(A2) < 1024*30/100.0)
  {
    digitalWrite(7, HIGH);
    digitalWrite(4, HIGH);
  }
  else
  {
    digitalWrite(7, LOW);
    digitalWrite(4, LOW);
  }
}

void loop( )
{
  light( );
}
