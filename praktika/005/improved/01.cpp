// Copyright [2015] <none>
#include <cstdlib>    // EXIT_SUCCESS, std::size_t
#include <iostream>   // std::cout
#include <vector>     // std::vector
#include <string>     // std::string, std::to_string
#include <utility>    // std::pair
#include <algorithm>  // std::distance

typedef std::pair<unsigned int, unsigned int> Domino;

template <class BidirIt>
void PrintDominos(BidirIt first, BidirIt last) {
  // I should probably use a real console graphics library in real code because
  // this is way too dirty
  const std::string DOMINO_LINE{"+---+---+"};
  std::string border{""};
  std::string values{""};
  for (BidirIt current = first; current != last; ++current) {
    Domino domino{*current};
    if (current != first) {
      border += ' ';
      values += "| |";
    } else {
      values += '|';
    }
    border += DOMINO_LINE;
    values += " " + std::to_string(domino.first) + " |";
    values += " " + std::to_string(domino.second) + " ";
  }
  border += '\n';
  values += "|\n";
  std::cout << border << values << border << std::flush;
}

int main() {
  // This is a terrible name for this variable
  const std::size_t MAX_DOMINOS_PER_ROW{6 + 1};
  std::vector<Domino> dominos;
  // Allocate memory, no need to do this multiple times since clear leaves the
  // capacity unchanged
  dominos.reserve(MAX_DOMINOS_PER_ROW);
  // I'm not sure how I can get around these raw loops
  for (std::size_t i = 0; i < MAX_DOMINOS_PER_ROW; ++i) {
    for (std::size_t j = i; j < MAX_DOMINOS_PER_ROW; ++j) {
      dominos.emplace_back(i, j);
    }
    PrintDominos(dominos.begin(), dominos.end());
    dominos.clear();
  }
  return EXIT_SUCCESS;
}
