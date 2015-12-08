// Copyright 2015 <none>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>

std::string ersetze(std::string zeile, char zu_ersetzendes_zeichen,
                    std::string ersatztext) {
  std::string::iterator pos =
      std::find(zeile.begin(), zeile.end(), zu_ersetzendes_zeichen);
  std::string resault;
  std::string front(zeile.begin(), pos);
  std::string end(pos + 1, zeile.end());
  resault += front + ersatztext + end;
  return resault;
}

int main(int argc, char *argv[]) {
  std::string request[3]{"Bitte geben Sie die Textzeile ein: ? ",
                         "Bitte geben Sie den einzusetzenden Text ein: ? ",
                         "Bitte geben Sie das zu ersetzende Zeichen ein: ?"};
  std::string row, bla, finish;
  char replace_char;
  std::cout << request[0];
  std::getline(std::cin, row);
  std::cout << request[1];
  std::getline(std::cin, bla);
  std::cout << request[2];
  std::cin >> replace_char;
  std::cout << "Ergebnis: " << ersetze(row, replace_char, bla) << std::endl;
  return 0;
}
