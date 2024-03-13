#include <Servo.h>

int RB = 3;
int RA = 5;
int LB = 6;
int LA = 9;
const int servoPin = 10;
const int servoPin2 = 11;
const int infraSensorPin = 8;
const int infraSensorPin2 = 7;
char data;

Servo myServo, myServo2;


void setup() {
  pinMode(RA, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LA, OUTPUT);
  pinMode(LB, OUTPUT);
  myServo.attach(servoPin);
  myServo2.attach(servoPin2);
  pinMode(infraSensorPin, INPUT);
  pinMode(infraSensorPin2, INPUT);
  Serial.begin(9600);
}

void maju() {
  digitalWrite(RA, HIGH);
  digitalWrite(LA, HIGH);
  digitalWrite(RB, LOW);
  digitalWrite(LB, LOW);
}

void kiriMaju() {

  digitalWrite(RA, HIGH);
  digitalWrite(RB, LOW);
  digitalWrite(LB, LOW);
  analogWrite(LA, 130);
}

void kananMaju() {
  analogWrite(RA, 130);
  digitalWrite(RB, LOW);
  digitalWrite(LB, LOW);
  digitalWrite(LA, HIGH);
}

void mundur() {
  digitalWrite(RA, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(RB, HIGH);
  digitalWrite(LB, HIGH);
}

void mundurKanan() {
  digitalWrite(RA, LOW);
  analogWrite(RB, 130);
  digitalWrite(LB, HIGH);
  digitalWrite(LA, LOW);
}

void mundurKiri() {
  digitalWrite(RA, LOW);
  analogWrite(LB, 130);
  digitalWrite(RB, HIGH);
  digitalWrite(LA, LOW);
}

void turnRight() {
  digitalWrite(RA, LOW);
  digitalWrite(LA, HIGH);
  digitalWrite(RB, LOW);
  digitalWrite(LB, LOW);
}

void turnLeft() {
  digitalWrite(RA, HIGH);
  digitalWrite(LA, LOW);
  digitalWrite(RB, LOW);
  digitalWrite(LB, LOW);
}

void berhenti() {
  digitalWrite(RA, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(RB, LOW);
  digitalWrite(LB, LOW);
}

void angkatServo() {
  myServo2.write(90);
  myServo.write(90);
}

void turunServo(){
  myServo2.write(0);
  myServo.write(0);
}

void deteksiSampah() {
  int obstacleDetected = digitalRead(infraSensorPin);
  int obstacleDetected2 = digitalRead(infraSensorPin2);

  if (obstacleDetected == 0 || obstacleDetected2 == 0) {
    myServo2.write(0);
    myServo.write(90);
  } else {
    myServo2.write(90);
    myServo.write(0);
  }
}


void loop() {
  
    if (data == 'F') {
      maju();
    } else if (data == 'G') {
      kiriMaju();
    } else if (data == 'I') {
      kananMaju();
    } else if (data == 'H') {
      mundurKiri();
    } else if (data == 'J') {
      mundurKanan();
    } else if (data == 'B') {
      mundur();
    } else if (data == 'R') {
      turnRight();
    } else if (data == 'L') {
      turnLeft();
    } else if (data == 'W') {
      angkatServo();
    } else if (data == 'w'){
      turunServo();
    }else {
      berhenti();
    }
    deteksiSampah();
  }
}