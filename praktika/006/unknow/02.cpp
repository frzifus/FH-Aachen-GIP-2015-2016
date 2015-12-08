// Copyright 2015 <none>
#include <iostream>  // std::cout std::cin std::size_t std::rand
#include <string>    // std::string std::to_string
#include <iomanip>   // std::fill std::setw

int emterY();

const std::size_t numRows = 20;
const std::size_t numCols = 51;
const std::size_t columnWidth = 3;

std::size_t EnterY(std::size_t maxRowValue, int count) {
  int input;
  do {
    std::cout << "Bitte geben Sie die " << count << ". Zahl ein: ? ";
    std::cin >> input;
  } while (input <= 0 || input > static_cast<int>(maxRowValue));
  return static_cast<std::size_t>(maxRowValue - input);
}

int main(int argc, char* argv[]) {
  std::size_t maxRowValue = numRows -1;
  std::size_t maxColValue = numCols -1;
  std::size_t minColValue = numCols - maxColValue;
  std::size_t temp_Y, count = 0;
  std::string Area[numRows][numCols];

  // Fuelle Feld mit Leerzeichen
  for (std::size_t row = 0; row < numRows; row++) {
    for (std::size_t col = 0; col < numCols; col++) {
      Area[row][col] = " ";
    }
  }

  for (std::size_t i = 0; i < maxRowValue; i++) {
      Area[i][0] = std::to_string(maxRowValue - i);
  }

  for (std::size_t i = 1; i <= maxColValue; i++) {
      Area[maxRowValue][i] = std::to_string(i);
  }

  while ( count < maxColValue ) {
    count++;
    // temp_Y =  maxRowValue - std::rand() % numRows + 0;
    temp_Y = EnterY(maxRowValue, count);
    Area[temp_Y][count] = "*";
    while ( temp_Y < maxRowValue - 1 ) {
      temp_Y++;
      Area[temp_Y][count] = ".";
      }
   }

  // Gebe Feld aus
  for ( std::size_t row = 0; row < numRows; row++ ) {
    for ( std::size_t col = 0; col < numCols; col++ ) {
      std::cout << std::setfill(' ') << std::setw(columnWidth)
                << Area[row][col];
    }
    std::cout << std::endl;
  }
  return 0;
}
