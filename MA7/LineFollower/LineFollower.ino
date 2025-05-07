#define LMIN 13
#define LMOUT 3
#define RMIN 11
#define RMOUT 5

void setup() {
  pinMode(LMIN, INPUT);
  pinMode(LMOUT, OUTPUT);
  pinMode(RMIN, INPUT);
  pinMode(RMOUT, OUTPUT);
}

void loop() {
  if (digitalRead(LMIN) == LOW) {
    analogWrite(LMOUT, 0); // Motor off
  } else {
    analogWrite(LMOUT, 220); // 50% power
  }

  if (digitalRead(RMIN) == LOW) {
    analogWrite(RMOUT, 0); // Motor off
  } else {
    analogWrite(RMOUT, 170); // 50% power
  }
}
