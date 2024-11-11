// The analog inputs for the joystick are from a range of 0 to 1023
// x, y and button pins are the analog pin connections (button is digital) for the joystick
int xPin = A0;
int yPin = A1;

int ledPin = 13;
int buttonSwitchPin = 2;

// these int values contain where the joystick is currently on their respective axis
int valX;
int valY;

// These variables are meant to see the current and previous button state in addition to the Led state. It's meant for toggling led on/off
int buttonState;
int previousButtonState = HIGH;
bool ledState = false; // By default led state should be false 

void setup() {
  // Set led Pin to be output 
  pinMode(ledPin, OUTPUT);
  pinMode(xPin, INPUT); // change pins A0, A1, and 2 to inputs
  pinMode(yPin, INPUT);
  pinMode(buttonSwitchPin, INPUT_PULLUP); //this button requires the use of arduino's internal pull up resistor
}

void loop() {
  valX = analogRead(xPin); //read values from analog and digital inputs coming from joystick and update x and y values
  valY = analogRead(yPin);
  buttonState = digitalRead(buttonSwitchPin);

  // Toggle Button On/Off (Low for Press High For released)
  if (buttonState == LOW && previousButtonState == HIGH){
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    delay(50);
  }
}