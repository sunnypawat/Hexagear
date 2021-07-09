#include <Stepper.h>

const int stepsPerRevolution = 200;
const int minRPM = 10;
const int hrRPM = 10;

//declare stepper motors
Stepper hour1(4096, 22, 24, 26, 28);
Stepper hour2(4096, 23, 25, 27, 29);
Stepper min1(4096, 30, 32, 34, 36);
Stepper min2(4096, 31, 32, 35, 37);


void setup() {
  // nothing to setup
}

void loop() {
  hour1.setSpeed(hrRPM);
  hour2.setSpeed(hrRPM);
  min1.setSpeed(minRPM);
  min2.setSpeed(minRPM);
  
  for(int i = 0; i < 360; i++) {
    hour1.step(1);
    hour2.step(1);
    min1.step(1);
    min2.step(1);
  }
}
