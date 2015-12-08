#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

/*
 * Pushing two strings on stack is a very bad idea but that's what they want
 * from me so don't blame me
 */
// NOLINTNEXTLINE
std::string ersetze(std::string line, char char_to_replace,
                    std::string replacement) {
  auto position = line.find(char_to_replace);
  if (position != std::string::npos) {
    line.replace(position, 1, replacement);
  }
  return line;
}

int main() {
  char char_to_replace;
  std::string line;
  std::string replacement;
  std::cout << "Bitte geben Sie die Textzeile ein: ? ";
  std::getline(std::cin, line);
  std::cout << "Bitte geben Sie den einzusetzenden Text ein: ? ";
  std::getline(std::cin, replacement);
  std::cout << "Bitte geben Sie das zu ersetzende Zeichen ein: ? ";
  std::cin >> char_to_replace;
  std::cout << "Ergebnis: " << ersetze(line, char_to_replace, replacement)
            << '\n';
  return EXIT_SUCCESS;
}
