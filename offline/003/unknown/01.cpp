#include <iostream>

// use std::array in c++11
int cost_level[2] = {300, 500};
int sum = {0}, stage = {0};
int shipment[3] = {10, 0, 0};
int package[3] = {5, 3, 0};

int main() {
  std::cout << "Bitte geben Sie den Waren-Rechnungsbetrag ein: ";
  std::cin >> sum;
  // use something like std::upper_bound in c++11
  if (sum > cost_level[0] && sum < cost_level[1]) {
    stage = 1;
  } else if (sum > cost_level[1]) {
    stage = 2;
  } else {
    stage = 0;
  }
  std::cout << "Versandkosten: " << shipment[stage] << " Euro" << std::endl;
  std::cout << "Verpackungskosten: " << package[stage] << " Euro" << std::endl;
  std::cout << "Gesamtbetrag: " << package[stage] + shipment[stage] + sum
            << " Euro" << std::endl;
  return 0;
}

/*
 https://docker.etechnik.fh-aachen.de/
     -> user: <nachname>
     -> passwort: <matr-nr>
     -> user: student
     -> password: student
*/
