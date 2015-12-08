// Copyright 2015 <none>
#include <boost/algorithm/string.hpp>
#include <iostream>

int main() {
  std::string s;
  std::cout << "Bitte geben Sie die Textzeile ein: ? ";
  std::getline(std::cin, s);
  std::cout << "Vorher : ###" << s << "###" << std::endl;
  boost::algorithm::trim(s);
  std::cout << "Nachher: ###" << s << "###" << std::endl;
  return 0;
}
