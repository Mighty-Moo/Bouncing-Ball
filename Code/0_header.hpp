#ifndef _0_HEADER_HPP
#define _0_HEADER_HPP
#include <iostream>

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
extern unsigned int windowWidth;
extern unsigned int windowHeight;

extern std::string tileContent;

void ball();
void drawMap();
void fileReadLine(int targetLineNumber);
int windowSizeUpdate();



#endif