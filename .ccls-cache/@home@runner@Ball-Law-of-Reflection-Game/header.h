#ifndef HEADER_H
#define HEADER_H

//Wall's angle of tilt in degrees
extern unsigned int wallAngle;
//Ball's angle
extern unsigned int ballAngle;
//The old ball angle
extern unsigned int OldBallAngle;
//Ball's location cordinate's
extern unsigned int pointXY[2];
//Ball's new location cordinate's
extern unsigned int newPointXY[2];

void ball();

#endif