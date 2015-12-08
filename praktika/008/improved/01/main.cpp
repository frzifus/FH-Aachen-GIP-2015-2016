// Copyright [2015] <none>
#include <cstdlib>

#include <string>

#include "./calc.h"
#include "./gui.h"

inline std::function<std::string(const int)> TextOfNumber(const char number) {
  return [number](const int digit) {
    return "Geben Sie die " + std::to_string(digit) + ". Ziffer der " + number +
           ". Zahl ein: ";
  };
}

int main() {
  constexpr int DIGITS = 2;
  int a = gui::ReadNumber(TextOfNumber('1'), DIGITS);
  int b = gui::ReadNumber(TextOfNumber('2'), DIGITS);
  calc::MathOperation operation = gui::ReadMathOperation();
  gui::printout(calc::calculate(operation, a, b));
  return EXIT_SUCCESS;
}
