int Pin[]={2,3,4,5,6,7,8,9,10};
int first=410;     //첫번째 구간
int second=415;    //두번째 구간

void setup(){
  Serial.begin(9600);
  for(int i=0; i<9; i++){
    pinMode(Pin[i], OUTPUT);
  }
}

void loop(){
  int value = analogRead(A0);                              
  Serial.println(value);    
  delay(100);

  if(value<first){    
    for(int i=0; i<3; i++) digitalWrite(Pin[i],HIGH);
    for(int i=3; i<9; i++) digitalWrite(Pin[i],LOW);
  }
  else if(value<second){
    for(int i=0; i<6; i++) digitalWrite(Pin[i],HIGH);
    for(int i=6; i<9; i++) digitalWrite(Pin[i],LOW);
  }
  else for(int i=0; i<9; i++) digitalWrite(Pin[i],HIGH);
  delay(300);
  for(int i=0; i<9; i++) digitalWrite(Pin[i],LOW);
  delay(100);
}

//시리얼 모니터 반응이 없으면 사운드센서의 가변저항을 조정해야 합니다!
