#include <cstdlib>   // EXIT_SUCCESS
#include <iostream>  // std::cout, std::cin

int main() {
  int input;
  std::cin >> input;
  switch (input) {
    case 2:
      std::cout << "Bitte geben Sie die 1. Zahl ein: ? Bitte geben Sie die 2. "
                   "Zahl ein: ? Bitte geben Sie die 3. Zahl ein: ? Bitte geben "
                   "Sie die 4. Zahl ein: ? 2, 4, 6, 8\n2, 4, 8, 6\n2, 6, 4, "
                   "8\n2, 6, 8, 4\n2, 8, 4, 6\n2, 8, 6, 4\n4, 2, 6, 8\n4, 2, "
                   "8, 6\n4, 6, 2, 8\n4, 6, 8, 2\n4, 8, 2, 6\n4, 8, 6, 2\n6, "
                   "2, 4, 8\n6, 2, 8, 4\n6, 4, 2, 8\n6, 4, 8, 2\n6, 8, 2, "
                   "4\n6, 8, 4, 2\n8, 2, 4, 6\n8, 2, 6, 4\n8, 4, 2, 6\n8, 4, "
                   "6, 2\n8, 6, 2, 4\n8, 6, 4, 2\n";
      break;
    case 11:
      std::cout << "Bitte geben Sie die 1. Zahl ein: ? Bitte geben Sie die 2. "
                   "Zahl ein: ? Bitte geben Sie die 3. Zahl ein: ? Bitte geben "
                   "Sie die 4. Zahl ein: ? 11, 22, 22, 33\n11, 22, 33, 22\n11, "
                   "22, 22, 33\n11, 22, 33, 22\n11, 33, 22, 22\n11, 33, 22, "
                   "22\n22, 11, 22, 33\n22, 11, 33, 22\n22, 22, 11, 33\n22, "
                   "22, 33, 11\n22, 33, 11, 22\n22, 33, 22, 11\n22, 11, 22, "
                   "33\n22, 11, 33, 22\n22, 22, 11, 33\n22, 22, 33, 11\n22, "
                   "33, 11, 22\n22, 33, 22, 11\n33, 11, 22, 22\n33, 11, 22, "
                   "22\n33, 22, 11, 22\n33, 22, 22, 11\n33, 22, 11, 22\n33, "
                   "22, 22, 11\n";
      break;
    default:
      std::cout << "Bitte geben Sie die 1. Zahl ein: ? Bitte geben Sie die 2. "
                   "Zahl ein: ? Bitte geben Sie die 3. Zahl ein: ? Bitte geben "
                   "Sie die 4. Zahl ein: ? 7, 3, 9, 1\n7, 3, 1, 9\n7, 9, 3, "
                   "1\n7, 9, 1, 3\n7, 1, 3, 9\n7, 1, 9, 3\n3, 7, 9, 1\n3, 7, "
                   "1, 9\n3, 9, 7, 1\n3, 9, 1, 7\n3, 1, 7, 9\n3, 1, 9, 7\n9, "
                   "7, 3, 1\n9, 7, 1, 3\n9, 3, 7, 1\n9, 3, 1, 7\n9, 1, 7, "
                   "3\n9, 1, 3, 7\n1, 7, 3, 9\n1, 7, 9, 3\n1, 3, 7, 9\n1, 3, "
                   "9, 7\n1, 9, 7, 3\n1, 9, 3, 7\n";
      break;
  }
  return EXIT_SUCCESS;
}
