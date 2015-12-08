#include <cstdlib>   // EXIT_SUCCESS, std::size_t
#include <limits>    // std::numeric_limits
#include <iostream>  // std::cout, std::cin
#include <set>       // std::set

int main() {
  const std::size_t NUM_NUMBERS{9};
  std::set<int> numbers;
  for (std::size_t i{0}; i < NUM_NUMBERS; ++i) {
    int number;
    do {
      std::cout << "Bitte geben Sie die " << i + 1 << "-te Zahl ein: ? ";
      std::cin >> number;
      if (!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
      }
    } while (number < 1 || number > 6);  // [1..6] allowed
    numbers.emplace(number);
  }
  std::cout << "In der Eingabe kamen " << numbers.size()
            << " unterschiedliche Zahlen vor." << std::endl;
  return EXIT_SUCCESS;
}
