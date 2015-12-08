// Copyright [2015] <none>
#include "./calc.h"

#include <iostream>
#include <utility>

// Function name was given by contractor
// NOLINTNEXTLINE
int calc::calculate(MathOperation operation, int a, int b) {
  int result{0};
  switch (operation) {
    case MathOperation::PLUS:
      result = a + b;
      break;
    case MathOperation::MINUS:
      result = a - b;
      break;
    default:
      std::cerr << "Unknown operation: " << operation << std::endl;
      std::exit(1);
      break;
  }
  return result;
}
