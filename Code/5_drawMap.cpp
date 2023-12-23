#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include "0_header.hpp"

extern unsigned int windowWidth;
extern unsigned int windowHeight;
extern std::string tileContent;

void drawMap() {


  
  //Clear screen
  std::cout << CLEARSCREEN;
  //Draw Map
  for(int HeightPos = 0; HeightPos != windowHeight; HeightPos++) {
    std::cout << "\033[" << HeightPos << ";" << WALL_BUFFER_SIZE + 1 /* +1 adds a space for the char*/ << "H" << WALL_CHAR << "\033[" << HeightPos << ";" << (WALL_BUFFER_SIZE * 4) - 1 << "H" << WALL_CHAR;
  }

  for(int HeightPos = 0; HeightPos != windowHeight; HeightPos++) {
    std::cout << "\033[" << HeightPos << ";1H";
    for(int i = 0; i < WALL_BUFFER_SIZE; i++) {

      std::cout << "-";
    }
    std::cout << "\033[" << HeightPos << ";" << (WALL_BUFFER_SIZE * 4) << "H";

    for(int i = (WALL_BUFFER_SIZE * 4); i <= windowWidth; i++) {

      std::cout << "-";
    }
  }

}