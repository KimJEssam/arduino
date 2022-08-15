void setup( )
{
  pinMode(A5, INPUT);

}

void loop( )
{
  analogWrite(3, (1023-analogRead(5))/4);
}
