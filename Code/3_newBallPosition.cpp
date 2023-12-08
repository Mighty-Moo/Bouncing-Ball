#include <iostream>
#include <cmath>
#include "0_header.hpp"

// The angle of the wall's tilt
extern unsigned int wallAngle;
// Ball's angle in degrees
extern unsigned int ballAngle;
// The ball's previous angle
extern unsigned int OldBallAngle;
extern unsigned int pointXY[2];
extern unsigned int newPointXY[2];


void ballPosition() {
  // Distance from point a to b
  double distance;
  


  distance = sqrt(pow((pointXY[0] - newPointXY[0]), 2) + pow((pointXY[1] - newPointXY[1]), 2));

  pointXY[1] = pointXY[1] + distance * cos((ballAngle * (3.14159 / 180)));
  pointXY[0] = pointXY[0] + distance * sin((ballAngle * (3.14159 / 180)));
}
