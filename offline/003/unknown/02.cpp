#include <cstddef>
#include <iostream>
#include <string>

int main() {
  std::string word;
  std::size_t length;
  std::cout << "Bitte geben Sie die Zeichenkette ein: ";
  std::getline(std::cin, word);
  length = word.length();
  std::cout << "Die umgedrehte Zeichenkette lautet: ";
  while (length > 0) {
    length--;
    std::cout << word.at(length);
  }
  std::cout << std::endl;
  return 0;
}
