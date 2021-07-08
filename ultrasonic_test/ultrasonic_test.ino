#include <Ultrasonic.h>

int distance = 0;
Ultrasonic ultrasonic1(6, 7);

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
}

void loop() {
  distance = ultrasonic1.distanceRead();
  Serial.println(distance);
  if (distance < 100)  {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
  delay(100);
}
