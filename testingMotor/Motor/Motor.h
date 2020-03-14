#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
  public:
    Motor(int pinA, int pinB, int pinC, int pinD, int holdingTime);
    void forward(int steps);
    void backward(int step);
    void stepForward();
    void stepBackward();
    void update();
    int aState;
    int bState;
    int cState;
    int dState;

  private:
    int a;
    int b;
    int c;
    int d;
    int holdingTime;
    int temp;

};

#endif
