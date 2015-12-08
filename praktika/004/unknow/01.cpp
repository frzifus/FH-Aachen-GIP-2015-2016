// Copyright [2015] <none>
#include <cstddef>  // not in use
#include <iostream>
#include <string>

int CheckInt() {
  int shift;
  std::cout << "Bitte geben Sie die Anzahl Verschiebeposition ein "
               " (als positive ganze Zahl): ";
  if (std::cin >> shift) {
  } else if (!std::cin.bad() && !std::cin.eof()) {
    std::cout << "Ungueltige Eingabe! " << std::endl;
    return 0;  // no exit
  }
  return shift;
}

char ReplaceChar(char letter, int shift, char minimum, char maximum) {
  // letter + shift
  for (int i = 0; i <= shift; i++) {
    letter++;
    if (letter > maximum) {
      // value range, explitictly casting from int to char
      letter = /*static_cast<char>*/ (letter - (maximum - minimum));
      letter--;
    }
  }
  return letter;
}

std::string Cipher(std::string text, int shift) {
  std::string code;
  for (std::size_t i = 0; i < text.length(); i++) {
    char letter = text.at(i);
    if (letter <= 'z' && letter >= 'a') {  // lower case
      code += ReplaceChar(letter, shift, 'a', 'z');
    } else if (letter <= 'Z' && letter >= 'A') {     // upper case
      code += ReplaceChar(letter, shift, 'A', 'Z');  // seems redundant..
    } else {                                         // invalid
      code += letter;
    }
  }
  return code;
}

int main() {
  int shift;
  std::string text;
  std::cout << "Bitte geben Sie den zu verschluesselnden Text ein: ";
  std::getline(std::cin, text);
  shift = CheckInt();
  shift--;  // decrement index counter
  std::cout << "Value: " << Cipher(text, shift) << std::endl;
  return 0;
}
