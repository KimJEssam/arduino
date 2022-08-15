#include <Servo.h>
Servo servo2;

int dist()
{
  long duration;
  int cm;
  pinMode(5, OUTPUT);
  pinMode(3, INPUT);
  
  digitalWrite(5, LOW);  delayMicroseconds(2);
  digitalWrite(5, HIGH); delayMicroseconds(10);
  digitalWrite(5, LOW);

  duration = pulseIn(3, HIGH);
  cm = (duration*0.0343)/2;
  return cm;
}

void autobreak()
{
  int t, tb;
  t = dist();
  if(t<=50) tb = 180;
  else if(t>250) tb = 0;
  else tb = (1.0-(t-50.0)/(250-50))*180;
  servo2.write(tb);
}

void setup()
{
  servo2.attach(10);
}

void loop()
{
  autobreak();
}
