#include <iostream>
#include <fstream>
#include <string>
#include "0_header.hpp"

// Declare tileContent globally so that it can be accessed externally
extern std::string tileContent;

void fileReadLine(int targetLineNumber) {
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

