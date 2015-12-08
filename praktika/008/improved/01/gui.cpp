// Copyright [2015] <none>
#include "./gui.h"

#include <cstdlib>
#include <cctype>
#include <cmath>

#include <functional>
#include <iostream>
#include <string>

#include "./calc.h"

// Function name was given by contractor
// NOLINTNEXTLINE
void gui::printout(int result) {
  std::cout << "Das Ergebnis lautet: " << result << std::endl;
}

calc::MathOperation gui::ReadMathOperation() {
  char operation;
  do {
    std::cout << "Geben Sie die Rechenoperation ein (+ oder -): ";
    std::cin >> operation;
  } while (kMathOperations.find(operation) == kMathOperations.end());
  return static_cast<calc::MathOperation>(operation);
}

int gui::ReadNumber(std::function<std::string(const int)> textof,
                    const int digits) {
  int number{0};
  for (int i{1}; i <= digits; ++i) {
    char digit;
    do {
      std::cout << textof(i);
      std::cin >> digit;
    } while (!static_cast<bool>(std::isdigit(digit)));
    number += static_cast<int>(std::pow(10, digits - i) * (digit - '0'));
  }
  return number;
}
