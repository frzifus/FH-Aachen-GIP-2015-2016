// Copyright [2015] <none>
#include <cstdlib>   // EXIT_SUCCESS, std::size_t
#include <iostream>  // std::cin, std::cout, std::getline
#include <array>     // std::array
#include <string>    // std::string

typedef std::array<std::array<int, 9>, 9> SodokuBoard;

// Terrible solution
// Not sore how this compares to iterators in terms of performance because I'm
// pretty sure that a const reference is not pushed onto the stack
// TODO(mash): use iterators instead
SodokuBoard ParseBoard(const std::array<std::string, 11>& lines) {
  // Input is assumed to be correct, we want digits from these positions
  const std::array<std::size_t, 9> POSITIONS{1, 3, 5, 9, 11, 13, 17, 19, 21};
  SodokuBoard board;
  std::size_t ignored{0};
  for (std::size_t i{0}; i < lines.size(); ++i) {
    // Ignore lines without information
    if (i == 3 || i == 7) {
      ignored++;
      continue;
    }
    for (std::size_t j{0}; j < POSITIONS.size(); ++j) {
      board[i - ignored][j] = lines[i][POSITIONS[j]] - '0';
    }
  }
  return board;
}

void PrintBoard(SodokuBoard board) {
  const std::string SEPERATOR{"=======//=======//=======\n"};
  // Terrible solution
  for (std::size_t i{0}; i < board.size(); ++i) {
    for (std::size_t j{0}; j < board[i].size(); j++) {
      std::cout << ';' << board[i][j];
      if (&board[i][j] == &board[i].back()) {
        // line break after last number in row
        std::cout << '\n';
      } else if ((j + 1) % 3 == 0) {
        // seperator if it's divisible by 3
        std::cout << ";//";
      }
    }
    // seperator if it's divisible by 3 and not last row
    if ((i + 1) % 3 == 0 && &board[i] != &board.back()) {
      std::cout << SEPERATOR;
    }
  }
}

int main() {
  std::array<std::string, 11> lines;
  std::cout << "Bitte geben Sie das Sodoku ein:\n";
  // std::string
  for (auto& line : lines) {
    std::getline(std::cin, line);
  }
  PrintBoard(ParseBoard(lines));
  return EXIT_SUCCESS;
}
