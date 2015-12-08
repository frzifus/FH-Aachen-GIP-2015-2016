// Copyright [2015] <none>
#include <cstdlib>    // EXIT_SUCCESS
#include <iostream>   // std::cout, std::cin, std::getline
#include <string>     // std::string
#include <algorithm>  // std::count

int main() {
  std::string userinput;
  std::string countable_chars;
  std::cout << "Bitte geben Sie den Text ein: ? ";
  std::getline(std::cin, userinput);
  std::cout << "Bitte geben Sie die zu zaehlenden Zeichen ein: ? ";
  std::getline(std::cin, countable_chars);
  // char
  for (const auto& character : countable_chars) {
    std::string::difference_type occurrences =
        std::count(userinput.begin(), userinput.end(), character);
    std::cout << "Der Buchstabe " << character << " kommt " << occurrences
              << " mal in dem Text vor." << std::endl;
  }
  return EXIT_SUCCESS;
}
