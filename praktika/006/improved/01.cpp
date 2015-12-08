// Copyright [2015] <none>
#include <cstdlib>    // EXIT_SUCCESS
#include <cctype>     // std::isalpha
#include <iostream>   // std::cout, std::cin, std::getline
#include <string>     // std::string
#include <algorithm>  // std::transform, std::all_of, std::equal

// Note that this is nothing alike std::tolower and I'm only doing this because
// they want me to implement this
char tolower(char character) {
  const int DIFFERENCE{'a' - 'A'};
  if (character >= 'A' && character <= 'Z') {
    character = static_cast<char>(character + DIFFERENCE);
  }
  return character;
}

int main() {
  bool isalpha;
  std::string possible_palindrom;
  do {
    std::cout << "Text = ? ";
    std::getline(std::cin, possible_palindrom);
    isalpha = std::all_of(
        possible_palindrom.begin(), possible_palindrom.end(),
        [](const char CHARACTER) -> bool { return std::isalpha(CHARACTER); });
  } while (!isalpha);
  std::transform(possible_palindrom.begin(), possible_palindrom.end(),
                 possible_palindrom.begin(), [](const char CHARACTER) -> char {
                   return tolower(CHARACTER);
                 });
  if (std::equal(possible_palindrom.begin(),
                 possible_palindrom.begin() +
                     static_cast<std::string::difference_type>(
                         possible_palindrom.size() / 2),
                 possible_palindrom.rbegin())) {
    std::cout << "Das eingegebene Wort ist ein Palindrom." << std::endl;
  } else {
    std::cout << "Das eingegebene Wort ist KEIN Palindrom." << std::endl;
  }
  return EXIT_SUCCESS;
}
