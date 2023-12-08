#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include "0_header.hpp"

extern std::string tileContent;

void fileReadLine(int targetLineNumber) {
  // The number of the line to be read

  /* Maybe instead of std::string use char the size of the counted chars on the
   * line?*/

  // Ask the OS for permission to read/write specified file
  std::ifstream inputFile("Bouncing-Ball/text_files/tiles.txt");

  if (inputFile.is_open()) {
    // The current line number
    unsigned int currentLine = 1;

    // Read until the target line or end of file
    while (
        currentLine < targetLineNumber &&
        inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n')) {
      currentLine++;
    }

    std::getline(inputFile, tileContent);

    inputFile.close();
  }


}
