 #include <LedControl.h>

LedControl lc = LedControl(12,10,11,1);//매트릭스 모듈 연결.

int column = 1;  //초기 위치
int row = random(8)+1;
int directionX = 1;  //방향
int directionY = 1;
int paddle1 = 5;   //가변저항 Pin
int value;    //가변저항 값
int speed = 300;   //초기속도
int counter = 0;
int mult = 10;    //프레임이 지나간 횟수

void setup()
{
  lc.shutdown(0, false);
  lc.setIntensity(0, 1);
  lc.clearDisplay(0);
  randomSeed(analogRead(0));
}

void loop()
{
  value = analogRead(5);
  value = map(value, 200, 1024, 1, 6);  //가변저항의 값을, 저장후, 매트릭스 좌표값으로 변환 
  column += directionX;
  row += directionY;
  if (column==6&&directionX==1&&(value==row||value+1==row||value+2==row)){directionX = -1;} //공이 막대에 닿았을때, X축 이동방향 변경.
  if (column==0&&directionX==-1 ){directionX=1;}// 공이 천장에 닿았을때, 천장을 향해 움직이면, 방향변경.
  if (row==7&&directionY==1){directionY=-1;}//막대가 오른쪽 벽에 닿았으며, 오른쪽으로 움직이고 있으면 방향변경
  if (row==0&&directionY==-1){directionY=1;}//막대가 왼쪽 벽에 닿았으며, 왼쪽으로 움직이고 있으면 방향변경 
  if (column==7){oops();}//모듈이 바닥에 닿을때 oops함수 실행.
  lc.clearDisplay(0);
  lc.setLed(0, column, row, HIGH);
  lc.setLed(0, 7, value, HIGH);
  lc.setLed(0, 7, value+1, HIGH);
  lc.setLed(0, 7, value+2, HIGH);

  //화면에 막대와 공을 뿌려줍니다.
  if (!(counter%mult)){
    speed -= 5; 
    mult*mult;
  }

  //counter를 mult로 나눈값이 0일때 딜레이속도를 낮추고, mult를 제곱합니다.
  delay(speed);
  counter++;
}
void oops() {//화면 깜빡 깜빡하고 초기화
  for (int x=0; x<3; x++){
    lc.clearDisplay(0);
    delay(250);
    for (int y=0; y<8; y++) {
      lc.setRow(0, y, 255);
    }
    delay(250);
  }
  counter=0;
  speed=300;
  column=1;
  row = random(8)+1;
}
