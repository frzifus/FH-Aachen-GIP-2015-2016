// Copyright <none>
#include <iostream>  // std::cout std::cin
#include <string>    // std::string
#include <cstddef>   // std::size_t

void EnterLine(std::size_t, int);

const std::size_t ROWS{9};  // Avoid *ptr
const std::size_t COLS{9};  //

void EnterLine(std::size_t j, int sudoku[ROWS][COLS]) {
  std::string line;
  std::size_t count{0};
  std::string underline = "-------|-------|-------";
  do {
    std::getline(std::cin, line);
  } while ( 22 != line.length() && line == underline);
  for (std::size_t i{0}; i < line.length(); ++i) {
    if (line.at(i) >= '0' && line.at(i) <= '9' && count < 9) {
      sudoku[j][count] = line.at(i) - '0';
      count++;
    }
  }
}

void PrintLine(int sudoku[ROWS][COLS]) {
  std::cout << "Das Sudoku lautet:" << std::endl;
  for (std::size_t i{0}; i < ROWS; ++i) {
    for (std::size_t j{0}; j < COLS; ++j) {
      if (j == 3 || j == 6) {
        std::cout << ";//";
      }
      std::cout << ";" << sudoku[i][j];
    }
    std::cout << std::endl;
    if (i == 2 || i == 5) {
      std::cout << "=======//=======//=======" << std::endl;
    }
  }
}

int main() {
  int sudoku[ROWS][COLS] = {0};
  std::cout << "Bitte geben Sie das Sudoku ein:" << std::endl;
  for (std::size_t j{0}; j < ROWS; ++j) {
    EnterLine(j, sudoku);
  }
  PrintLine(sudoku);
  return 0;
}
