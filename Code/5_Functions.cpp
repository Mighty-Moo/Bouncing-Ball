#include "0_header.hpp"
    

    //Draws wall of 'H'
    void Interface::drawWall() {

      //Clear screen
      std::cout << CLEARSCREEN;

      //Draw Map
      for(int HeightPos = 0; HeightPos != Win_Width; HeightPos++) {
        std::cout << "\033[" << HeightPos << ";" << WALL_BUFFER_SIZE + 1 /* +1 adds a space for the char*/ << "H" << WALL_CHAR << "\033[" << HeightPos << ";" << (WALL_BUFFER_SIZE * 4) - 1 << "H" << WALL_CHAR;
      }
    }
  


    //Draws brick wall of '-'
    void Interface::drawBrick() {
      
        for(int HeightPos = 0; HeightPos != Win_Height; HeightPos++) {
          std::cout << "\033[" << HeightPos << ";1H";
          for(int i = 0; i < WALL_BUFFER_SIZE; i++) {

            std::cout << "-";
          }
          std::cout << "\033[" << HeightPos << ";" << (WALL_BUFFER_SIZE * 4) << "H";

          for(int i = (WALL_BUFFER_SIZE * 4); i <= Win_Width; i++) {

            std::cout << "-";
          }
        }

      }
  


    //Gets window size and terminates program if window is too small
    int Interface::windowSizeUpdate() {
  struct winsize size;
  
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

  prevHeight = Win_Height;
  prevWidth = Win_Width;

  //Tells player if window is too small
  if(Win_Height < 2 || Win_Width < 25) {
    std::cout << "\033[2J\033[0;0H";
    std::cerr << "Literally Unplayable" << std::endl;
    //If window is too small, close program
    return(-1);
  }
  return(0);
}
  


    //Suposedly reads a file by a specified line
    void Interface::fileReadLine(int targetLineNumber) {
    // Ask the OS for permission to read specified file
    std::ifstream inputFile("text_files/tiles.txt");  // Adjust the file path accordingly

    // The current line number
    unsigned int currentLine = 1;

    // Read until the target line
    while (currentLine < targetLineNumber && std::getline(inputFile, tileContent)) {
        currentLine++;
    }

    // Close the file before returning
    inputFile.close();
}
