#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int pinA, int pinB, int pinC, int pinD, int holdingTime){
  a = pinA;
  b = pinB;
  c = pinC;
  d = pinD;
  holdingTime  = holdingTime;
  aState = 1;
  bState = 0;
  cState = 0;
  dState = 0;
  temp   = 0;

  pinMode(a, OUTPUT);
  digitalWrite(a, LOW);
  pinMode(b, OUTPUT);
  digitalWrite(b, LOW);
  pinMode(c, OUTPUT);
  digitalWrite(c, LOW);
  pinMode(d, OUTPUT);
  digitalWrite(d, LOW);
}

void Motor::update(){
    digitalWrite(a, aState);
    digitalWrite(b, bState);
    digitalWrite(c, cState);
    digitalWrite(d, dState);
    delay(10);
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);

}

void Motor::stepForward(){
  temp   = aState;
  aState = bState;
  bState = cState;
  cState = dState;
  dState = temp;
  update();
}

void Motor::stepBackward(){
  temp   = dState;
  dState = cState;
  cState = bState;
  bState = aState;
  aState = temp;
  update();
}

void Motor::forward(int steps){
    for( int i=0; i<steps; i++){
        stepForward();
    }
}

void Motor::backward(int step){
    for( int i=0; i<steps; i++){
        stepBackward();
    }
}
