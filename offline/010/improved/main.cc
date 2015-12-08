#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <cstring>

#include <ios>
#include <iostream>
#include <limits>
#include <memory>
#include <string>

std::size_t mystrlen(const char* ptr) {
  const char* s;
  for (s = ptr; *s != '\0'; ++s) {}
  return static_cast<std::size_t>(s - ptr);
  // return std::strlen(ptr);
}

char* mystrnconcat(const char* sptr1, const char* sptr2, std::size_t count) {
  assert(sptr1 != nullptr);
  assert(sptr2 != nullptr);
  char* cstr = new char[count + 1];  // count + null
  assert(cstr != nullptr);
  char* s = cstr;
  // copy sptr1 to cstr
  while (count > 0 && *sptr1 != '\0') {
    *s++ = *sptr1++;
    --count;
  }
  // concat sptr2 and cstr
  while (count > 0 && *sptr2 != '\0') {
    *s++ = *sptr2++;
    --count;
  }
  // zero out the remaining
  while (count > 0) {
    *s++ = '\0';
    --count;
  }
  // null last char which we allocated just for this purpose
  *s = '\0';
  return cstr;
}

int main() {
  enum Operation { MYSTRLEN = 1, MYSTRNCONCAT };
  int option;
  std::cout << "Bitte waehlen Sie die Operation aus.\n-1- "
               "mystrlen()\n-2- mystrnconcat()\n";
  std::cin >> option;
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  switch (option) {
    case Operation::MYSTRLEN: {
      std::string buf;
      std::cout << "Zeichenkette? ";
      std::getline(std::cin, buf);
      std::cout << "Ergebnis mystrlen(): " << mystrlen(buf.c_str()) << '\n';
    } break;
    case Operation::MYSTRNCONCAT: {
      std::size_t count;
      std::string s1, s2;
      std::cout << "Erste Zeichenkette? ";
      std::getline(std::cin, s1);
      std::cout << "Zweite Zeichenkette? ";
      std::getline(std::cin, s2);
      std::cout << "Anzahl Zeichen? ";
      std::cin >> count;
      // char* result = mystrnconcat(s1.c_str(), s2.c_str(), count);
      std::unique_ptr<char[]> result(
          mystrnconcat(s1.c_str(), s2.c_str(), count));
      std::cout << "Ergebnis mystrnconcat(): " << result.get() << '\n';
      // delete[] result;
    } break;
    default:
      return EXIT_SUCCESS;
      break;
  }
  return EXIT_SUCCESS;
}
