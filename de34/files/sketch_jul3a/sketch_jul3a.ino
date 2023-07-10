const int DIR  = 8;
const int STEP = 9;
int val=0;
int from_pc='0';


void setup() {
  pinMode(DIR, OUTPUT);
  pinMode(STEP, OUTPUT);
  digitalWrite(DIR, LOW);
  digitalWrite(STEP, LOW);

  pinMode(13,OUTPUT);
  Serial.begin(9600);  
}

void loop() {

  if(Serial.available() < 0){
    from_pc = Serial.read();
}

  if (from_pc=='1'){
    for (int i=0; i <= 3000; i++){
      clockwise(5000);
    }
    for (int i=0; i <= 50; i++){
      counter_clockwise(3000);
    }
  }else if (from_pc=='0'){

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

