#include <Servo.h>
Servo servo1;

void setup( )
{
  servo1.attach(9);
}

void ta( )
{
  int t, ta; float c;
  t=analogRead(A0);
  c=(5.0*t*100)/1024;
  if(c<=25) ta=0;
  else if(c>34) ta=180;
  else ta=(c-24)/(34-24)*180;
  servo1.write(ta);
}

void loop( )
{
  ta( );
}
