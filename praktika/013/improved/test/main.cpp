// Copyright [2016] <none>
#define CATCH_CONFIG_RUNNER
#include <iostream>

#include "catch.h"

int main(int argc, char* const argv[]) {
  int result = Catch::Session().run(argc, argv);
  std::cout << "Resultatwert: " << result << '\n';
  return result;
}
