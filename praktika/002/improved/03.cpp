// Copyright [2015] <none>
#include <iostream>

int main() {
  double laenge_meter;
  std::cout << "Bitte geben Sie die Laenge in Metern ein: ";
  std::cin >> laenge_meter;
  std::cout << "Die Laenge in Fuss lautet: " << laenge_meter * 3.2808
            << std::endl;
  return 0;
}
