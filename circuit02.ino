void setup() {
  Serial.begin(9600);
}
void loop() {
  int value = analogRead(A0);
  Serial.print(value);
  Serial.print(" ");
  delay(100);
  int min = 390;
  int max = 420;
  int level = map(value, min, max, 0, 9);
  if (level < 2) Serial.println("*");
  else if (level < 4) Serial.println("***");
  else if (level < 6) Serial.println("*********");
  else if (level < 8) Serial.println("*****************");
  else Serial.println("*****************************");
  delay(200);
}
