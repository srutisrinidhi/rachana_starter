#include <Servo.h>

Servo right;  // create servo object to control a servo
Servo left;

currRightAngle = 60;
currLeftAngle = 40;

coordinates_t coordinatesLoop;
void setup() {
  left.attach(9);  // attaches the servo on pin 9 to the servo object
  right.attach(6);
  Serial.begin(9600);
  left.write(currLeftAngle);
  right.write(currRightAngle);
  
}



void loop() {
  
  /*
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    right.write(pos);              // tell servo to go to position in variable 'pos'
    left.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    right.write(pos);              // tell servo to go to position in variable 'pos'
    left.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  */
  move_right(1);
  delay(5000);
  move_down(1);
  delay(5000);
  move_up(1);
  delay(5000);
  move_left(1);
  delay(10000);
  
}

void move_left(int step){
  currRightAngle = currRightAngle + 30*step
  currLeftAngle = currLeftAngle + (30*step)*5/6
  right.write(currRightAngle);
  left.write(currLeftAngle);

}

void move_left(int step){
  currRightAngle = currRightAngle - 30*step
  currLeftAngle = currLeftAngle - (30*step)*2/3
  right.write(currRightAngle);
  left.write(currLeftAngle);

}

void move_down(int step){
  currRightAngle = currRightAngle - 20*step
  currLeftAngle = currLeftAngle + 20*step
  right.write(currRightAngle);
  left.write(currLeftAngle);

}

void move_up(int step){
  currRightAngle = currRightAngle + 20*step
  currLeftAngle = currLeftAngle - 20*step
  right.write(currRightAngle);
  left.write(currLeftAngle);

}

