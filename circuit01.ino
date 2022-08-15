int Pin[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
void setup() {
  for (int i = 0; i < 9; i++) {
    pinMode(Pin[i], OUTPUT);
  }
}
void loop() {
  int value = analogRead(A0);
  int level = map(value, 0, 1023, 0, 9);
  for (int i = 0; i < 9; i++) {
    if (i < level) {
      digitalWrite(Pin[i], HIGH);
    }
    else {
      digitalWrite(Pin[i], LOW);
    }
  }
}
