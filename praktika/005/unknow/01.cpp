// Copyright 2015 <none>
#include <iostream>
#include <string>

void PrintLine(int zahl) {
  std::string domino;
  for (int i = 0; i <= zahl; i++) {
    domino += "+---+---+ ";
  }
  std::cout << domino << std::endl;
}

int main() {
  int p{0}, y{0}, x{0};
  PrintLine(6);
  while (x <= 6) {
    std::cout << "| " << x << " | " << y <<  " | ";
    if (y >= 6) {
      std::cout << std::endl;
      PrintLine(y - p);
      x++;
      y = p;
      p++;
    }
    y++;
  }
  return 0;
}
