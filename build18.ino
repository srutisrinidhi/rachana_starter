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
 int x = 50;
 //arbitrary can change coordinates,
 int y = 50;
 //arbitrary can change coordinates
  int OFFSET1 = 115;
  int OFFSET2 = 180;
  int LENGTH = 100;
  int YAXIS = 200;
  float pi = 22/7;
  int angle1 = 0;
  int angle2 = 0;

  struct coordinates_t{
  int x; //expected coordinates
  int y; //expected coordinates
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




coordinatesLoop.x = y;
coordinatesLoop.y = y;
coordinates_t coordinatesLoop = coordinateToMovement(coordinatesLoop);
right.write(coordinatesLoop.thetaRight);
left.write(coordinatesLoop.thetaLeft);
  /*right.write(40);
  left.write(20);
  delay(1000);
  right.write(80);
  left.write(0);
  delay(1000);
  */
  
}



coordinates_t coordinateToMovement(coordinates_t coordinatesLoop){
  //definition of the function
//takes coordinatesLoop
//uses a center point 0, 0
//calculates the angle to the coordinatesLoop
  int centerX = 0;
  int centerY = 0;
  float thetaRight = 0;
  float thetaLeft = 0;


  //Movement is 5 cm, movement right, minimal movement in y direction
  if ((coordinatesLoop.prevY- coordinatesLoop.y == 0) && (coordinatesLoop.x > coordinatesLoop.prevX)){
  thetaRight = atan((coordinatesLoop.y-centerY)/(coordinatesLoop.y-centerX));
  thetaLeft = thetaRight*(5/6);
  coordinatesLoop.prevX = coordinatesLoop.x;
  coordinatesLoop.x += 189; //calculation of 4 cm into pixels
  coordinatesLoop.y += 0;
  coordinatesLoop.prevY = coordinatesLoop.y;
  }

//movement is 4 cm, movement is to the left, minimal movement in y direction
  else if((coordinatesLoop.prevY - coordinatesLoop.y == 0) && (coordinatesLoop.x < coordinatesLoop.prevX)){
    thetaLeft = atan((coordinatesLoop.y-centerY)/(coordinatesLoop.y-centerX));
    thetaRight = 2/3 * (thetaLeft);
    coordinatesLoop.prevX = coordinatesLoop.x;
    coordinatesLoop.x += 151;
    coordinatesLoop.y += 0;
    coordinatesLoop.prevY = coordinatesLoop.y;
  }

  // movement is 2 cm change, movement to the back, minimal movement in x direction
  else if((coordinatesLoop.prevX - coordinatesLoop.x == 0) && (coordinatesLoop.y < coordinatesLoop.prevY)){
    thetaLeft = atan((coordinatesLoop.y-centerY)/(coordinatesLoop.y-centerX));
    thetaRight = thetaLeft;
    coordinatesLoop.prevX = coordinatesLoop.x;
    coordinatesLoop.prevY = coordinatesLoop.y;
    coordinatesLoop.y += 75;
     
  }
  else{
    coordinatesLoop.x = 0;
    coordinatesLoop.y = 0;
  }
  Serial.println(coordinatesLoop.prevX);
  Serial.println(coordinatesLoop.prevY);
  Serial.println(coordinatesLoop.x);
  Serial.println(coordinatesLoop.y);
  Serial.println(coordinatesLoop.thetaRight);
  Serial.println(coordinatesLoop.thetaLeft);
  
    
return coordinatesLoop;
  
  
}
