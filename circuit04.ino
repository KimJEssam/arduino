#include "LedControl.h"
LedControl lc = LedControl(12, 10, 11, 1); //DIN:12, CS: 11, CLK:10
 
byte a[8] = {B01100110,
  B10011001,
  B10011001,
  B10000001,
  B10000001,
  B01000010,
  B00100100,
  B00011000
};

void setup()
{
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}
 
void loop()
{

  for (int row = 0; row < 8; row++)
  {
    lc.setRow(0, row, a[row]);  
    delay(25);
  }
}
