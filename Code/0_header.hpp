#ifndef _0_HEADER_HPP
#define _0_HEADER_HPP
#include <iostream>

#define CLEARSCREEN "\033[2J"
#define WALL_CHAR "H"
#define WALL_BUFFER_SIZE (windowWidth/5)


extern unsigned int wallAngle;  //Wall's angle of tilt in degrees
extern unsigned int ballAngle;  //Ball's angle
extern unsigned int OldBallAngle;   //The old ball angle
extern unsigned int pointXY[2]; //Ball's location cordinate's
extern unsigned int newPointXY[2];  //Ball's new location cordinate's
extern unsigned int windowWidth; //Width of terminal window
extern unsigned int windowHeight;   //Hieght of terminal window
extern unsigned int prevWidth;
extern unsigned int prevHeigth;

extern std::string tileContent;

void ball();
void drawMap();
void fileReadLine(int targetLineNumber);
int windowSizeUpdate();



#endif