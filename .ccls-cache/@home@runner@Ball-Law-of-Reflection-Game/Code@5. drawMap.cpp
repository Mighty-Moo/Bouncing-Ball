#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

extern unsigned int windowWidth;
extern unsigned int windowHeight;
extern std::string tileContent;

void drawMap() {



  //Clear screen
  std::cout << "\033[2J\033[0;0H";
  //Draw Map
  for(int y = 1; y != windowHeight; y++) {
    std::cout << "\033[" << y << ";" << 12 << "H" << tileContent << "\033[" << y << ";" << (windowWidth - 14) << "H" << tileContent;
  }

}