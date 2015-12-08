// Copyright [2015] <none>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <string>

int main() {
  std::string text;
  std::cout << "Eingabe: ? ";
  std::getline(std::cin, text);
  std::reverse(text.begin(), text.end());
  std::cout << "Ausgabe: " << text << '\n';
  return EXIT_SUCCESS;
}
