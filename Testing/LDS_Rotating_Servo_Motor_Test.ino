#include <Servo.h>

Servo servoX;

void setup() {
  // put your setup code here, to run once
  servoX.attach(7);

}

void loop() {
  // put your main code here, to run repeatedly:
  servoX.write(90);
  Serial.write("Moved 90 degrees");
  delay(5000);
  servoX.write(0);
  delay(5000);
}