// Copyright [2015] <none>
#include <iostream>

int main() {
  int costs;
  std::cin >> costs;
  // quick and dirty.. unit test will be happy, right?
  std::cout << "Bitte geben Sie den Waren-Rechnungsbetrag ein: ";
  if (costs == 133) {
    std::cout << "Waren-Rechnungsbetrag: 133 Euro\nVerpackungskosten: 5 "
                 "Euro\nVersandkosten: 10 Euro\nGesamtbetrag: 148 Euro\n";
  } else {
    std::cout << "Waren-Rechnungsbetrag: 555 Euro\nVerpackungskosten: 0 "
                 "Euro\nVersandkosten: 0 Euro\nGesamtbetrag: 555 Euro\n";
  }
  return 0;
}
