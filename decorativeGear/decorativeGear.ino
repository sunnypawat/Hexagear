#include <Ultrasonic.h>

//declare distance variable for each ultrasonic sensor and ultrasonic pin
int d1, d2, d3, d4;
Ultrasonic us1(2, 3);
Ultrasonic us2(4, 5);
Ultrasonic us3(6, 7);
Ultrasonic us4(8, 9);

//declare a range distance
int in = 200;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
}

void loop() {
  // read individual distance from ultrasonic sensors
  d1 = us1.distanceRead();
  d2 = us2.distanceRead();
  d3 = us3.distanceRead();
  d4 = us4.distanceRead();

  //run within "in" distance
  if (d1 <= in) {
    //run motors

    //delay
    delay(5000);
    //stop motors
    
  }
  if (d2 <= in) {
    
  }
  if (d2 <= in) {
    
  }
  if (d2 <= in) {
    
  }
  delay(100);
}
