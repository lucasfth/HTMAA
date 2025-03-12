#define LMIN 13
#define LMOUT 12
#define RMIN 11
#define RMOUT 10


void setup() {
  pinMode(LMIN,INPUT);
  pinMode(LMOUT,OUTPUT);
  pinMode(RMIN,INPUT);
  pinMode(RMOUT,OUTPUT);
}

void loop() {
  if (digitalRead(LMIN) == LOW){
    digitalWrite(LMOUT,LOW);
  } else {
    digitalWrite(LMOUT,HIGH);
  }
  if (digitalRead(RMIN) == LOW){
    digitalWrite(RMOUT,LOW);
  } else {
    digitalWrite(RMOUT,HIGH);
  }
  
  // put your main code here, to run repeatedly:

}
