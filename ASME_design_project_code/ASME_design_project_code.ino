// Good practice to define globally used variables here

const int JOY_BUTTON1 = 11;
const int JOY_X1 = A0;
const int JOY_Y1 = A1;

const int JOY_BUTTON2 =  12;
const int JOY_X2 = A2;
const int JOY_Y2 = A3;

const int SERVO1 = 2;
const int SERVO2 = 3;
const int SERVO3 = 4;
const int SERVO4 = 5;


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

const int speed = 5; // ADD SECOND

const int buffer = 20; // ADD SECOND



int move(int pos, int dir, Servo &servo){
  pos = pos + speed*dir;
  if (pos >= 180){
    pos = 180;
  }
  else if (pos <= 0){
    pos = 0;
  }

  servo.write(pos);
  return pos;

}

int read_joy(int joy_pin){
// Potential addition/extra could be to add a speed variable based on how far the joystick is pushed
  int joy_val = analogRead(joy_pin);
  int dir;

  if (joy_val < 512-buffer){ // 12 bit buffer, 512 is the center 
    dir = -1;
  }
  else if (joy_val > 512+buffer){
    dir = 1;
  }
  else {
    dir = 0;
  }
  return dir;
}


// Potential fucntion to add a button functionality 


void setup() {
  // This code happens before the main loop
  
  // First, lets initializes pins: Prevents frying the board
  // it can pick up on noise and read incorrectly. Arduinos have internal pull up resistors built in
  pinMode(JOY_X1, INPUT); // Dont need it for the joystick or potentiometer because it is always electrically connected
  pinMode(JOY_Y1, INPUT);
  pinMode(JOY_X2, INPUT); // Dont need it for the joystick or potentiometer because it is always electrically connected
  pinMode(JOY_Y2, INPUT);

  // When using the servo library, pinmode is not necessary 
  servo1.attach(SERVO1);
  servo2.attach(SERVO2);
  servo3.attach(SERVO3);
  servo4.attach(SERVO4);

  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
  servo4.write(pos4);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int dir_x1 = read_joy(JOY_X1);
  int dir_y1 = read_joy(JOY_Y1);
  pos1 = move(pos1, dir_x1, servo1);
  pos2 = move(pos2, dir_y1, servo2);

  int dir_x2 = read_joy(JOY_X2);
  int dir_y2 = read_joy(JOY_Y2);
  pos3 = move(pos3, dir_x2, servo3);
  pos4 = move(pos4, dir_y2, servo4);





}
