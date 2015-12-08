// Copyright [2015] <none>
#include <iostream>

int main() {
  double geldmenge_euro;
  std::cout << "Bitte geben Sie die Geldmenge in Euro ein: ";
  std::cin >> geldmenge_euro;
  std::cout << "Die Geldmenge in US Dollar lautet: " << geldmenge_euro * 1.2957
            << std::endl;
  return 0;
}
