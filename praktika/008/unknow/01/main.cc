// Copyright 2015
#include <iostream>
#include <cctype>           // std::isdigit
#include "include/gui.h"    // gui::printout
#include "include/calc.h"   // calc:calculate
//     Check if character is decimal digit (function )
// #include "include/input.h"  // input::operator input::digit

int main() {
  char value;
  int resault, first_value, second_value;
  char vaildoperator;
  do {
    std::cout << "Geben Sie die 1. Ziffer der 1.Zahl ein: ";
    std::cin >> value;
  } while (!std::isdigit(value));
  first_value = (value - '0') * 10;

  do {
    std::cout << "Geben Sie die 2. Ziffer der 1.Zahl ein: ";
    std::cin >> value;
  } while (!isdigit(value));
  first_value += (value - '0');

  do {
    std::cout << "Geben Sie die 1. Ziffer der 2.Zahl ein: ";
    std::cin >> value;
  } while (!isdigit(value));
  second_value = (value - '0') * 10;

  do {
    std::cout << "Geben Sie die 2. Ziffer der 2.Zahl ein: ";
    std::cin >> value;
  } while (!isdigit(value));
  second_value += (value - '0');

  do {
    std::cout << "Geben Sie die Rechenoperation an (+ or -)";
    std::cin >> vaildoperator;
  } while (vaildoperator != '+' && vaildoperator !='-');
  /*
  first_value   = input::digit(1);
  second_value  = input::digit(2);
  vaildoperator = input::vaildoperator();
  */
  resault       = calc::calculate(first_value, second_value,
                                  vaildoperator);
  gui::printout(resault);
  return 0;
}
