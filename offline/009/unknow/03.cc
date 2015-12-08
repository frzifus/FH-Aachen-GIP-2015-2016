// Copyright 2015 <none>

#include <iostream>
#include <algorithm>
#include <string>

void spalte_ab_erstem(std::string zeile, char split_char, std::string *s1,
                      std::string *s2) {
  std::string::iterator pos = std::find(zeile.begin(), zeile.end(), split_char);
  s1(zeile.begin(), pos);
  s2(pos + 1, zeile.end());
}

int main() {
  std::string s, first_part, second_part, zeile;
  std::cout << "Bitte geben Sie den String ein: ?";
  std::getline(std::cin, zeile);
  std::cout << "Bitte geben Sie das Zeichen ein,"
            << " an dem gespalten werden soll: ?";
  std::cin >> s;
  spalte_ab_erstem(zeile, s, first_part, second_part);
  std::cout << "Erster Teil: " << first_part << std::endl;
  std::cout << "Zweiter Teil: " << second_part << std::endl;
  return 0;
}
