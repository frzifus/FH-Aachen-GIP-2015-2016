#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

int main() {
  char character;
  std::string text;
  std::cout << "Eingabe: ? ";
  std::getline(std::cin, text);
  std::cout << "Zeichen: ? ";
  std::cin >> character;
  std::string::iterator until = std::find_if(
      text.begin(), text.end(),
      [character](const char c) -> bool { return c == ' ' || c == character; });
  std::cout << "Ausgabe: " << std::string(text.begin(), until) << '\n';
  return EXIT_SUCCESS;
}
