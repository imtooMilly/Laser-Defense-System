#include <Servo.h>

Servo servoX;
Servo servoY;
// The analog inputs for the joystick are from a range of 0 to 1023
// x, y and button pins are the analog pin connections (button is digital) for the joystick
int xPin = A0;
int yPin = A1;

int xServoPin = 9;
int yServoPin = 10;

int servoMax = 90;

// these int values contain where the joystick is currently on their respective axis
int valX;
int valY;

// These int values store where the servo is currently in its rotation
int xServoPos;
int yServoPos;


void setup() {
  servoX.attach(xServoPin); // Attach servoX to pin 9 and servoY to pin 10
  servoY.attach(yServoPin); 

  pinMode(xPin, INPUT); // change pins A0, A1, and 2 to inputs
  pinMode(yPin, INPUT);
}

void loop() {
  valX = analogRead(xPin); //read values from analog and digital inputs coming from joystick and update x and y values
  valY = analogRead(yPin);

  // target = map(source, lowSource, highSource, lowTarget, highTarget)
  xServoPos = map(valX, 0, 1023, 0, servoMax);
  yServoPos = map(valY, 0, 1023, 0, servoMax);

  servoX.write(xServoPos);
  servoY.write(yServoPos);

}
