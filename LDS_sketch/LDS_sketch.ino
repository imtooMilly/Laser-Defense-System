#include <Servo.h>

Servo servoX;
Servo servoY;
Servo sensorServo;    // Controls the servo rotating the ultrasonic sensor

// The analog inputs for the joystick are from a range of 0 to 1023
// x, y and button pins are the analog pin connections (button is digital) for the joystick
int xPin = A0;
int yPin = A1;

int laserPin = 13;
int buttonSwitchPin = 2;

// These int values contain where the joystick is currently on their respective axis
int valX;
int valY;

// These variables are meant to see the current and previous (joystick) button state in addition to the Laser state. It's meant for toggling the laser on/off based on the button press
int joystickButtonState;
int previousJoystickButtonState = HIGH;
bool laserState = false; // By default laser state should be false 

// These int values store where the servo is currently in its rotation
int xServoPin = 9;
int yServoPin = 10;
int sensorServoPin = 11;

int servoMax = 180;
int xServoPos;
int yServoPos;
int currentSensorAngle = 0; 
bool increasing = true; // Tracks the direction of the sweep

// Mode selection variables
int modeButtonPin = 3; // New button for mode selection
int modeButtonState;
int previousModeButtonState = HIGH;
bool isJoystickMode = true; // By default it sets mode state to Joystick mode

// Ultrasonic sensor setup
int trigPin = 5;
int echoPin = 6; 
long duration;
int distance;

void setup() {
  servoX.attach(xServoPin); // Attach servoX to pin 9, servoY to pin 10, and the sensor servo to pin 11
  servoY.attach(yServoPin); 
  sensorServo.attach(sensorServoPin);

 
  pinMode(laserPin, OUTPUT);
  pinMode(xPin, INPUT); // change pins A0, A1, and 2 to inputs
  pinMode(yPin, INPUT);
  pinMode(buttonSwitchPin, INPUT_PULLUP); //this button requires the use of arduino's internal pull up resistor

  // Ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


  // Initialize Serial communication for debugging
  pinMode(modeButtonPin, INPUT_PULLUP); 
  Serial.begin(9600);

  // Print the initial mode
  Serial.println("Mode: Joystick");
}

void loop() {
  // Read mode button state
  modeButtonState = digitalRead(modeButtonPin);
  if (modeButtonState == LOW && previousModeButtonState == HIGH) {
    isJoystickMode = !isJoystickMode; // Toggle between modes
    printMode(); 
    delay(200); // Debounce delay
  }
  previousModeButtonState = modeButtonState;

  if (isJoystickMode) {
    // Joystick control
    joystickMode();
  } else {
    // Ultrasonic control
    ultrasonicMode();
  }
}

void joystickMode(){
  valX = analogRead(xPin); //read values from analog and digital inputs coming from joystick and update x and y values
  valY = analogRead(yPin);
  joystickButtonState = digitalRead(buttonSwitchPin);

  // target = map(source, lowSource, highSource, lowTarget, highTarget)
  xServoPos = map(valX, 0, 1023, 0, servoMax);
  yServoPos = map(valY, 0, 1023, 0, servoMax);

  servoX.write(xServoPos);
  servoY.write(yServoPos);

  // Toggle Button On/Off (How we know if the button was pressed is when we check if the state goes from HIGH TO LOW (based on the INPUT_PULLUP))
  if (joystickButtonState == LOW && previousJoystickButtonState == HIGH){
    laserState = !laserState;
    digitalWrite(laserPin, laserState);
    delay(50);
  }

  // After button toggle, set the previous state variable state to be equal to the prior current state
  previousJoystickButtonState = joystickButtonState;
}

void ultrasonicMode() {
  // Sweep the ultrasonic sensor incrementally
  sensorServo.write(currentSensorAngle);
  delay(200); // Allow the servo to stabilize

  // Measure distance
  distance = getDistance();

  // If the ultrasonic sensor detects an object within 50cm, move the servos
  if (distance > 0 && distance <= 50) { 
    int mappedX = map(currentSensorAngle, 0, 180, 0, servoMax);
    int mappedY = map(distance, 0, 200, 0, servoMax);

    servoX.write(mappedX);
    servoY.write(mappedY);

    digitalWrite(laserPin, HIGH);

    Serial.print("Object Detected - Sensor Angle: ");
    Serial.print(currentSensorAngle);
    Serial.print("°, Distance: ");
    Serial.print(distance);
    Serial.print(" cm, Mapped X: ");
    Serial.print(mappedX);
    Serial.print(", Mapped Y: ");
    Serial.println(mappedY);
  } else {
    digitalWrite(laserPin, LOW);
    Serial.println("No object detected.");
  }

  // Update the sensor angle for the next step
  if (increasing) {
    currentSensorAngle += 10;
    if (currentSensorAngle >= 180) {
      increasing = false; // Reverse direction
    }
  } else {
    currentSensorAngle -= 10;
    if (currentSensorAngle <= 0) {
      increasing = true; // Reverse direction
    }
  }
}


long getDistance() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time of flight
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  long calculatedDistance = duration * 0.034 / 2;
  return calculatedDistance;
}


void printMode() {
  // Print the current mode to the Serial Monitor
  if (isJoystickMode) {
    Serial.println("Mode: Joystick");
  } else {
    Serial.println("Mode: Ultrasonic");
  }
}
