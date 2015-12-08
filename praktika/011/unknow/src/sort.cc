// Copyright 2015 <Roo>

#include <cstddef>        // std::size_t
#include <algorithm>      // std::swap
#include "../include/sort.h"

void sort::Bubblesort(int* save, const std::size_t LENGTH) {
  for (std::size_t i = 0; i < LENGTH - 1; ++i) {
    for (std::size_t j = 0; j < LENGTH - i - 1; ++j) {
      if (save[j] > save[j + 1]) {
        std::swap(save[j], save[j + 1]);
      }
    }
  }
}
