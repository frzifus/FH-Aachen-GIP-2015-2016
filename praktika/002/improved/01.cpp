// Copyright [2015] <none>
#include <cmath>      // std::pow
#include <array>      // std::array
#include <string>     // std::string
#include <iostream>   // std::cin, std::cout

unsigned int CharToInt(const char& character) {
  return static_cast<unsigned int>(character - '0');
}

unsigned int EnterDigit(const unsigned int& digit, const std::string& descriptor) {
  const std::array<std::string, 6> DIGIT_DESCRIPTORS = {
      "Einer",     "Zehner",        "Hunderter",
      "Tausender", "Zehntausender", "Hunderttausender"};
  char input;
  std::cout << "Bitte geben Sie die " << DIGIT_DESCRIPTORS[digit]
            << "ziffer der " << descriptor << "Zahl ein: ";
  std::cin >> input;
  return CharToInt(input) * static_cast<unsigned int>(std::pow(10, digit));
}

unsigned int EnterNumber(unsigned int digits, const std::string& descriptor) {
  // may only be positive
  unsigned int result = 0;
  for (; digits > 0; --digits) {
    result += EnterDigit(digits - 1, descriptor);
  }
  return result;
}

int main() {
  const unsigned int DIGITS = 2;
  std::array<unsigned int, 2> number;
  number[0] = EnterNumber(DIGITS, "ersten ");
  number[1] = EnterNumber(DIGITS, "zweiten ");
  std::cout << "Die Summe der beiden Zahlen " << number[0] << " + " << number[1]
            << " lautet: " << number[0] + number[1] << std::endl;
  return 0;
}
