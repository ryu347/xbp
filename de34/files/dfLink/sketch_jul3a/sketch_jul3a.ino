#include <Stepper.h>

const int stepsPerRevolution = 1900;  // ステップ数（モーターごとに異なる場合があります）
const int motorPin1 = 8;             // ステッピングモーターのピン1
const int motorPin2 = 9;             // ステッピングモーターのピン2
const int motorPin3 = 10;            // ステッピングモーターのピン3
const int motorPin4 = 11;            // ステッピングモーターのピン4

Stepper myStepper(stepsPerRevolution, motorPin1, motorPin2, motorPin3, motorPin4);
bool motorRunning = false;  // モーターが動作中かどうかのフラグ

void setup() {
  myStepper.setSpeed(65);  // 60 rpmに設定（1秒ごとに1回転）
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int command = Serial.read();
    if (command == '1') {
      if (!motorRunning) {
        // ステッピングモーターを3秒間回転させる
        myStepper.step(stepsPerRevolution);
        delay(3000);
        // ステッピングモーターを停止させる
        myStepper.step(0);
        motorRunning = true;
      }
    } else if (command == '0') {
      if (motorRunning) {
        // ステッピングモーターを3秒間逆回転させる
        myStepper.step(-stepsPerRevolution);
        delay(3000);
        // ステッピングモーターを停止させる
        myStepper.step(0);
        motorRunning = false;
      }
    }
  }
}