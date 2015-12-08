#include <cctype>
#include <cstdlib>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

// Note that it's a terrible idea to push this string on the stack.
// It's also a terrible idea to pass s1 and s2 as references. RVO is great so
// why not just return a pair of strings.
// NOLINTNEXTLINE
void spalte_ab_erstem(std::string zeile, char split_char, std::string& s1,
                      std::string& s2) {
  std::string::size_type pos = zeile.find(split_char);
  s1 = zeile.substr(0, pos);
  s2 = zeile.substr(pos + 1);
}

int main() {
  std::string line, first_part, second_part;
  char character;
  std::cout << "Bitte geben Sie den String ein: ? ";
  std::getline(std::cin, line);
  std::cout
      << "Bitte geben Sie das Zeichen ein, an dem gespalten werden soll: ? ";
  std::cin >> std::noskipws >> character;
  spalte_ab_erstem(line, character, first_part, second_part);
  std::cout << "Erster Teil: " << first_part << '\n';
  std::cout << "Zweiter Teil: " << second_part << '\n';
  return EXIT_SUCCESS;
}
