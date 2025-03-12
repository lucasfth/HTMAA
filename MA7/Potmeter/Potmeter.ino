#define OUT 13
#define POTIN A0

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  pinMode(A0, INPUT);
}

void loop() {
  Serial.println(analogRead(A0));
  delay(1000);
}
