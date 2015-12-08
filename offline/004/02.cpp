#include <cstdlib>   // EXIT_SUCCESS, std::size_t
#include <iostream>  // std::cout, std::cin
#include <string>    // std::string

// this program is really ugly
int main() {
  std::size_t width, height;
  std::string prefix = " ";
  std::cout << "Bitte geben Sie die Breite des Parallelogramms ein: ";
  std::cin >> width;
  std::cout << "Bitte geben Sie die Hoehe des Parallelogramms ein: ";
  std::cin >> height;
  std::string border(width, '*');
  std::string space(width - 2, ' ');
  std::cout << border << std::endl;
  // ugly ugly ugly
  for (std::size_t i = 0; i < height - 2; ++i) {
    std::cout << prefix << '*' << space << '*' << '\n';
    prefix += " ";
  }
  std::cout << prefix << border << "\n\n" << std::flush;
  return EXIT_SUCCESS;
}
