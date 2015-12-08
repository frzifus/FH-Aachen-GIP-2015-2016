// Copyright [2015] <none>
#include <iostream>

int main() {
  double eingabe;
  int auswahl;

  std::cout << "Ihre Eingabe: ";
  std::cin >> eingabe;
  std::cout << "Ihre Auswahl der Umwandlung:" << std::endl;
  std::cout << " 1 - Celsius in Fahrenheit" << std::endl;
  std::cout << " 2 - Meter in Fuss" << std::endl;
  std::cout << " 3 - Euro in US Dollar" << std::endl;
  std::cin >> auswahl;

  double ergebnis = 0.5 * (1.8 * eingabe + 32) * (auswahl - 2) * (auswahl - 3) -
                    3.2808 * eingabe * (auswahl - 1) * (auswahl - 3) +
                    0.5 * 1.2957 * eingabe * (auswahl - 1) * (auswahl - 2);

  std::cout << "Das Ergebnis lautet: " << ergebnis << std::endl;
  return 0;
}
