// Good practice to define globally used variables here

const int ANALOG_BUTTON = A1
const int ANALOG_X = A2
const int ANALOG_Y = A3
const int SERVO1 = A4
const int SERVO2 = A5
const int SERVO3 = A6


// Place holders
const int x_offset = 0
const int y_offset = 0


void setup() {
  // Initializes pins
  pinMode(ANALOG_BUTTON, INPUT) // or pinMode(ANALOG_BUTTON, INPUT_PULLUP)
  pinMode(ANALOG_x, INPUT)
  pinMode(ANALOG_Y, INPUT)

  pinMode(SERVO1, OUTPUT)
  pinMode(SERVO2, OUTPUT)
  pinMode(SERVO3, OUTPUT)

}

void loop() {
  // put your main code here, to run repeatedly:

}
