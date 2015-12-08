#include <cctype>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

inline bool IsNoSpace(const char character) {
  return !static_cast<bool>(std::isspace(character));
}

template <class BidirIt, class OutputIt, class UnaryPredicate>
OutputIt Trim(BidirIt first, BidirIt last, OutputIt first_d, UnaryPredicate p) {
  BidirIt first_result = std::find_if(first, last, p);
  BidirIt last_result = std::find_if(std::reverse_iterator<BidirIt>(last),
                                     std::reverse_iterator<BidirIt>(first), p)
                            .base();
  return std::copy(first_result, last_result, first_d);
}

// Note that it's a bad idea to copy the string on stack
std::string trimme(std::string s) {
  std::string result;
  Trim(s.begin(), s.end(), std::back_inserter(result), IsNoSpace);
  return result;
}

int main() {
  std::string line;
  std::cout << "Bitte geben Sie die Textzeile ein: ? ";
  std::getline(std::cin, line);
  std::cout << "Vorher: ###" << line << "###\n";
  std::cout << "Nachher: ###" << trimme(line) << "###\n";
  return EXIT_SUCCESS;
}
