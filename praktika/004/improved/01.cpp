// Copyright [2015] <none>
#include <cctype>   // std::isupper, std::toupper, std::tolower
#include <cstdlib>  // EXIT_SUCCESS, std::size_t

#include <algorithm>   // std::rotate, std::transform
#include <functional>  // std::bind, std::placeholders
#include <iostream>    // std::cout, std::cin, std::getline
#include <string>      // std::string

char TransformChar(const std::string& letters,
                   const std::string& transform_letters, char letter) {
  // save case
  bool isupper{std::isupper(letter)};
  // normalize
  letter = static_cast<char>(std::tolower(letter));
  // check if we can transform this char
  std::size_t position{letters.find(letter)};
  if (position != std::string::npos) {
    // transform char
    letter = transform_letters[position];
    if (isupper) {
      // restore case
      letter = static_cast<char>(std::toupper(letter));
    }
  }
  return letter;
}

template <class InputIt, class OutputIt>
void CaeserCipher(InputIt first, InputIt last, OutputIt first_d, int shift) {
  const std::string letters{"abcdefghijklmnopqrstuvwxyz"};
  std::string rotated_letters{letters};
  // no need to shift more than possible
  shift %= static_cast<int>(rotated_letters.size());
  if (shift > 0) {
    // rotate left by shift
    std::rotate(rotated_letters.begin(), rotated_letters.begin() + shift,
                rotated_letters.end());
  } else if (shift < 0) {
    // rotate right by shift
    std::rotate(rotated_letters.rbegin(), rotated_letters.rbegin() - shift,
                rotated_letters.rend());
  }
  // transform itself
  std::transform(first, last, first_d,
                 std::bind(TransformChar, letters, rotated_letters,
                           std::placeholders::_1));
}

int main() {
  std::string raw_text;
  int shift;

  std::cout << "Bitte geben Sie den zu verschluesselnden Text ein: ";
  std::getline(std::cin, raw_text);
  std::cout << "Bitte geben Sie die Anzahl Verschiebepositionen ein: ";
  std::cin >> shift;
  CaeserCipher(raw_text.begin(), raw_text.end(), raw_text.begin(), shift);
  std::cout << raw_text << std::endl;
  return EXIT_SUCCESS;
}
