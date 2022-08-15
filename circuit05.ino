#include "LedControl.h"
LedControl lc=LedControl(12,10,11,1);
int min=390;   //최소값, 시리얼 모니터링
int max=420;   //최대값, 시리얼 모니터링

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
  Serial.begin(9600);
}

void draw(int level) {
  byte A[]={B00000000,B00000000,B00000000,B00011000,B00011000,B00000000,B00000000,B00000000};
  byte B[]={B00000000,B00000000,B00111100,B00111100,B00111100,B00111100,B00000000,B00000000};
  byte C[]={B11111111,B11111111,B11000011,B11000011,B11000011,B11000011,B11111111,B11111111};
  
  if(level==0){
      for(int i=0; i<8; i++){
        lc.setColumn(0,i,A[i]);
      }
      delay(100);
  }
  else if(level==1){
      for(int i=0; i<8; i++){
        lc.setColumn(0,i,B[i]);
      }
      delay(100);
  }
  else{
      for(int i=0; i<8; i++){
        lc.setColumn(0,i,C[i]);
      }
      delay(100);
  }
  for(int i=0; i<8; i++){
      lc.setColumn(0,i,B00000000);
  }
  delay(150);
}
 
void loop() { 
  int value = analogRead(A0);                              
  Serial.print(value);    
  delay(100);

  int level=map(value,min,max,0,9);
  level=map(level,0,9,0,2);
  draw(level);
  Serial.print(" "); 
  Serial.println(level); 
}
