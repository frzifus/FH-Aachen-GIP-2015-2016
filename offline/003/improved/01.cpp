// Copyright [2015] <none>
#include <iostream>

int main() {
  unsigned int costs, packaging_costs{0}, shipping_costs{0};
  std::cout << "Bitte geben Sie den Waren-Rechnungsbetrag ein: ";
  std::cin >> costs;
  std::cout << "Waren-Rechnungsbetrag: " << costs << " Euro\n";
  /*
   * Terrible solution but luckily this is not real life.
   * Probably wanna do a map upper bound where the map key is holding a pair in
   * real life.
   */
  if (costs < 300) {
    packaging_costs = 5;
    shipping_costs = 10;
  } else if (costs < 500) {
    packaging_costs = 3;
  }
  costs += packaging_costs + shipping_costs;
  std::cout << "Verpackungskosten: " << packaging_costs << " Euro\n";
  std::cout << "Versandkosten: " << shipping_costs << " Euro\n";
  std::cout << "Gesamtbetrag: " << costs << " Euro" << std::endl;  // flush
  return 0;
}
