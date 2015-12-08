// Copyright 2015 <Roo>

#include <iostream>
#include "include/sort.h"

int main() {
  const std::size_t INDEX = 10;
  int numbers[] = { 9, 3, 5, 2, 8, 6, 4, 3, 7, 8 };
  // Ausgabe des "Vorher" Zustands des Arrays...
  std::cout << "Vorher: ";
  for (std::size_t count{0}; count < INDEX; ++count)
    std::cout << numbers[count] << (count < INDEX - 1 ? ", " : "\n");
  // Aufruf der sortiere() Funktion...
  sort::Bubblesort(numbers, INDEX);
  // Ausgabe des "Nachher" Zustands des Arrays...
  std::cout << "Nachher: ";
  for (std::size_t count{0}; count < INDEX; ++count)
    std::cout << numbers[count] << (count < INDEX - 1 ? ", " : "\n");
  return 0;
}
