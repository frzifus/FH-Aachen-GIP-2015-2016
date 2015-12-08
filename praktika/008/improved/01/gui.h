// Copyright [2015] <none>
#ifndef PRAKTIKA_008_BENNE_01_GUI_H_
#define PRAKTIKA_008_BENNE_01_GUI_H_

#include <functional>
#include <set>
#include <string>

#include "./calc.h"

namespace gui {
// Didn't find a good solution to transform an enum to a set yet.
const std::set<char> kMathOperations{calc::MathOperation::PLUS,
                                     calc::MathOperation::MINUS};

// Function name was given by contractor
// NOLINTNEXTLINE
void printout(int result);
calc::MathOperation ReadMathOperation();
// Probably should be using a template instead of std::function
int ReadNumber(std::function<std::string(const int)> textof, const int digits);

}  // namespace gui

#endif  // PRAKTIKA_008_BENNE_01_GUI_H_
