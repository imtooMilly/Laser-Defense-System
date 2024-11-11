// The analog inputs for the joystick are from a range of 0 to 1023
// x, y and button pins are the analog pin connections (button is digital) for the joystick
int xPin = A0;
int yPin = A1;

int laserPin = 13;
int buttonSwitchPin = 2;

// these int values contain where the joystick is currently on their respective axis
int valX;
int valY;

// These variables are meant to see the current and previous button state in addition to the Laser state. It's meant for toggling the laser on/off based on the button press
int buttonState;
int previousButtonState = HIGH;
bool laserState = false; // By default laser state should be false 


void setup() {
  // Set laser Pin to be output 
  pinMode(laserPin, OUTPUT);
  pinMode(xPin, INPUT); // change pins A0, A1, and 2 to inputs
  pinMode(yPin, INPUT);
  pinMode(buttonSwitchPin, INPUT_PULLUP); //this button requires the use of arduino's internal pull up resistor
}

void loop() {
  valX = analogRead(xPin); //read values from analog and digital inputs coming from joystick and update x and y values
  valY = analogRead(yPin);
  buttonState = digitalRead(buttonSwitchPin);

  // Toggle Button On/Off (How we know if the button was pressed is when we check if the state goes from HIGH TO LOW (based on the INPUT_PULLUP))
  if (buttonState == LOW && previousButtonState == HIGH){
    laserState = !laserState;
    digitalWrite(laserPin, laserState);
    delay(50);
  }

  // After button toggle, set the previous state variable state to be equal to the prior current state
  previousButtonState = buttonState;

}
