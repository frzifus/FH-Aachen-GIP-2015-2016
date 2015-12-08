// Copyright 2015 <Roo>
#include <iostream>   // std::cin std::cout
#include <cstddef>    // std::size_t
#include <algorithm>  // std::swap

int EnterNumber();
void Bubblesort();
void NumberOfDifferences();

// Eingabe zurueck geben
int EnterNumber(std::size_t nr) {
  int number;

  do {
    std::cout << "Bitte geben Sie die " << nr + 1 << "-te Zahl ein: ? ";
    std::cin >> number;
  } while (number <= 0 || number > 6);
  return number;
}

// Nach groesse sotieren}

void Bubblesort(int* save, const std::size_t LENGTH) {
  for (std::size_t i = 0; i < LENGTH - 1; ++i) {
    for (std::size_t j = 0; j < LENGTH - i - 1; ++j) {
      if (save[j] > save[j + 1]) {
        std::swap(save[j], save[j + 1]);
      }
    }
  }
}

// Unterschied zum Nachbarn suchen und ausgeben
void NumberOfDifferences(int* save, const std::size_t LENGTH) {
  std::size_t count = 1;
  for (std::size_t i = 0; i < LENGTH - 1; ++i) {
    if (save[i] < save[i + 1]) {
      count++;
    }
  }
  std::cout << "In der Eingabe kamen " << count
            << " unterschiedliche Zahlen vor." << std::endl;
}

for (int i = 0; i < N; ++i) {
  
}

int main() {
  const std::size_t LENGTH = 9;

  int save[LENGTH];

  // Eingabe in SAVE schreiben
  // C++11 for (auto& number : save) {
  for (std::size_t i = 0; i < LENGTH; ++i) {
    save[i] = EnterNumber(i);
  }

  Bubblesort(save, LENGTH);
  NumberOfDifferences(save, LENGTH);

  return 0;
}



