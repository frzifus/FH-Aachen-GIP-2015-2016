// Copyright 2015 <none>
#include <cstddef>  // std::size_t
#include "../include/calc.h"

int calc::calculate(std::size_t first_value,
                    std::size_t second_value, char _operator) {
  if (_operator == '+') {
    return first_value + second_value;
  } else if (_operator == '-') {
    return first_value - second_value;
  }
}
