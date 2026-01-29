// Good practice to define globally used variables here

const int JOY_BUTTON = A1
const int JOY_X = A2
const int JOY_Y = A3

const int POT = A8

const int SERVO1 = A4
const int SERVO2 = A5
const int SERVO3 = A6
const int SERVO4 = A7


#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;


// Position Variables
int pos1 = 0;
int pos2 = 0;
int pos3 = 0; // Change to starting val from calibration
int pos4 = 0;

void setup() {
  // This code happens before the main loop
  
  // First, lets initializes pins: Prevents frying the board
  pinMode(JOY_BUTTON, INPUT_PULLUP); // High Impedence: when a pin is electrically disconnected
  // it can pick up on noise and read incorrectly. Arduinos have internal pull up resistors built in
  pinMode(JOY_x, INPUT); // Dont need it for the joystick or potentiometer because it is always electrically connected
  pinMode(JOY_Y, INPUT);
  pinMode(POT, INPUT)

  // When using the servo library, pinmode is not necessary 
  servo1.attach(SERVO1);
  servo2.attach(SERVO2);
  servo3.attach(SERVO3);
  servo4.attach(SERVO4);

  servo1.write(pos1)
  servo2.write(pos2)
}

// Need to pass &servo to ensure it doesnt declare another copy in the function and references the original
void write_angle(int analog_pin, Servo &servo){
  int analog_val = analogRead(analog_pin)
  int angle = map(analog_val, 0, 1023, 0, 180)
  servo.write(angle)
}

int move(int pos, int dir, Servo &servo){
  pos = pos + 1*dir;
  servo.write(pos);
  return pos;
}

int read_joy(int joy_pin){
  int joy_val = analogRead(joy_pin);
  
  if joy_val < 500{ // 12 bit buffer, 512 is the center 
    int dir = -1;
  }
  else if joy_val > 524{
    int dir = 1;
  }
  else{
    dir = 0
  }
  return dir
}




void loop() {
  // put your main code here, to run repeatedly:
  write_angle(POT, servo3);
  int dir_x = read_joy(JOY_X);
  int dir_y = read_joy(JOY_Y);
  pos1 = move(pos1, dir_x, servo1)
  pos2 = move(pos2, dir_y, servo2)




}
