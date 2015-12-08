// Copyright [2015] <none>
#include <iostream>

int main() {
  double temperatur_celsius;
  std::cout << "Bitte geben Sie die Temperatur in Grad Celsius ein: ";
  std::cin >> temperatur_celsius;
  std::cout << "Die Temperatur in Fahrenheit lautet: "
            << temperatur_celsius * 1.8 + 32 << std::endl;
  return 0;
}
