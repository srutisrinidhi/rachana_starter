#include <Servo.h>

Servo right;  // create servo object to control a servo
Servo left;

// twelve servo objects can be created on most boards

//1 pixel is 0.0264583333 cm
//right servo moves an angle x
//left servo moves 5/6th of it by keeping a constant y
//this change changes x positions by 4 cm
//4 cm - 151.18112140865 PX
// i.e changes x position by 
int pos = 0;
 //arbitrary can change coordinates,
 //arbitrary can change coordinates
  int OFFSET1 = 115;
  int OFFSET2 = 180;
  int LENGTH = 100;
  int YAXIS = 200;
  float pi = 22/7;
  int angle1 = 0;
  int angle2 = 0;

  struct coordinates_t{
  int x = 50; //expected coordinates
  int y = 0; //expected coordinates
  int prevX; //coordinates from the previous movement
  int prevY; //coordinates from the previous movement
  float thetaRight;
  float thetaLeft;
};
coordinates_t coordinatesLoop;
void setup() {
  left.attach(9);  // attaches the servo on pin 9 to the servo object
  right.attach(6);
  Serial.begin(9600);
  coordinatesLoop.prevX = 0;
  coordinatesLoop.prevY = 0;
  coordinatesLoop.x = 0;
  coordinatesLoop.y = 0;
  coordinatesLoop.thetaRight = 0;
  coordinatesLoop.thetaLeft = 0;
  
  
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
 
/*
  int r = sqrt(x^2 + y^2);
  float thetaMain = atan(y/x);
  float thetaServo1 = thetaMain - acos(r/30);
  float thetaServo2 = acos(r/2*15) + thetaMain;
 right.write(thetaServo1*180/pi);
 left.write(thetaServo2*180/pi);
 Serial.println(thetaMain);

 */
 /*
 if(x > OFFSET1){
    angle1 = pi + acos(d1/2*LENGTH) - atan(x-OFFSET1/YAXIS - y);
  }
  else{
    angle1 = pi + acos(d1/2*LENGTH) + atan(OFFSET1-x/YAXIS - y);
  }
   if(x > OFFSET2){
    angle2 = pi - acos(d2/2*LENGTH) - atan(x-OFFSET2/YAXIS - y);
  }
  else{
    angle2 = pi - acos(d2/2*LENGTH) + atan(OFFSET2-x/YAXIS - y);
  }
  angle1 = angle1*180/pi;
  angle2 = angle2*180/pi;
  right.write(angle2);
  left.write(angle1);
  Serial.println(angle1);
  Serial.println(angle2);
*/



/*

right.write(60);
left.write(40);
delay(5000);


right.write(120);
left.write(90);
delay(5000);


right.write(70);
left.write(140);
delay(5000);

right.write(120);
left.write(90);
delay(10000);
*/




coordinatesLoop.x = x;
coordinatesLoop.y = y;
moveRight(5);
moveUp(10);


  /*right.write(40);
  left.write(20);
  delay(1000);
  right.write(80);
  left.write(0);
  delay(1000);
  */
  
}


void moveRight(int steps){
  //Movement is 5 cm, movement right, minimal movement in y direction
  
  thetaRight = atan((coordinatesLoop.y)/(coordinatesLoop.x));
  thetaLeft = thetaRight*(5/6);
  coordinatesLoop.prevX = coordinatesLoop.x;
  coordinatesLoop.x += 189*steps; //calculation of 4 cm into pixels
  coordinatesLoop.y += 0;
  coordinatesLoop.prevY = coordinatesLoop.y;
  right.write(coordinatesLoop.thetaRight);
  left.write(coordinatesLoop.thetaLeft);
  
}


void moveLeft(int steps){
  thetaLeft = atan((coordinatesLoop.y)/(coordinatesLoop.x));
    thetaRight = 2/3 * (thetaLeft);
    coordinatesLoop.prevX = coordinatesLoop.x;
    coordinatesLoop.x += 151*steps;
    coordinatesLoop.y += 0;
    coordinatesLoop.prevY = coordinatesLoop.y;
    right.write(coordinatesLoop.thetaRight);
    left.write(coordinatesLoop.thetaLeft);
  
}

void moveBack(int steps){
    thetaLeft = atan((coordinatesLoop.y)/(coordinatesLoop.x));
    thetaRight = thetaLeft;
    coordinatesLoop.prevX = coordinatesLoop.x;
    coordinatesLoop.prevY = coordinatesLoop.y;
    coordinatesLoop.y += 75*steps;
    right.write(coordinatesLoop.thetaRight);
    left.write(coordinatesLoop.thetaLeft);
  
}

void moveUp(int steps){
    thetaLeft = atan((coordinatesLoop.y)/(coordinatesLoop.x));
    thetaRight = thetaLeft;
    coordinatesLoop.prevX = coordinatesLoop.x;
    coordinatesLoop.prevY = coordinatesLoop.y;
    coordinatesLoop.y -= 75*steps;
    right.write(coordinatesLoop.thetaRight);
    left.write(coordinatesLoop.thetaLeft);
  
}

  





  
