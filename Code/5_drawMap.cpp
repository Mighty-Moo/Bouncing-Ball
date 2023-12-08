#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include "0_header.hpp"

extern unsigned int windowWidth;
extern unsigned int windowHeight;
extern std::string tileContent;

void drawMap() {



  //Clear screen
  std::cout << "\033[2J\033[0;0H";
  //Draw Map
  for(int y = 0; y != windowHeight; y++) {
    std::cout << "\033[" << y-1 << ";" << 12 << "H" << "H" << "\033[" << y << ";" << (windowWidth - 14) << "H" << tileContent;
  }

}