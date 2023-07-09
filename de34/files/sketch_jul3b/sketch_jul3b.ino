const int DIR  = 8;
const int STEP = 9;

void setup() {
  pinMode(DIR, OUTPUT);
  pinMode(STEP, OUTPUT);
  digitalWrite(DIR, LOW);
  digitalWrite(STEP, LOW);
}

void loop() {

  for (int i=0; i <= 100; i++){
    clockwise(5000);
  }
  for (int i=0; i <= 100; i++){
    counter_clockwise(5000);
  }
}

void clockwise(int delaytime){
  digitalWrite(DIR, HIGH);//HIGHは時計回り

  digitalWrite(STEP, HIGH);
  delayMicroseconds(delaytime);
  digitalWrite(STEP, LOW);
  delayMicroseconds(delaytime);

}

void counter_clockwise(int delaytime){

  digitalWrite(DIR, LOW);//はLOWは反時計回り
  digitalWrite(STEP, HIGH);
  delayMicroseconds(delaytime);
  digitalWrite(STEP, LOW);
  delayMicroseconds(delaytime);
}
