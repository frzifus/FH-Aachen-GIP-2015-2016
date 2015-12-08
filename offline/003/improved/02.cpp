// Copyright [2015] <none>
#include <iostream>   // std::cout, std::cin, std::getline
#include <string>     // std::string
#include <algorithm>  // std::reverse

int main() {
  std::string userinput;
  std::cout << "Bitte geben Sie die Zeichenkette ein: ";
  std::getline(std::cin, userinput);                 // read line from cin
  std::reverse(userinput.begin(), userinput.end());  // reverse string
  std::cout << "Die umgekehrte Zeichenkette lautet: " << userinput << std::endl;
  return 0;
}
