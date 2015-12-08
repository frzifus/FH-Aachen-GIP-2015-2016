#include <cstdlib>  // EXIT_SUCCESS, std::size_t

#include <iostream>   // std::cout
#include <algorithm>  // std::swap

template <class BidirIt>
void reverse(BidirIt first, BidirIt last) {
  while (first != last) {
    --last;
    if (first != last) {
      // swap first with last and move towards mid until finished
      std::swap(*first, *last);
      ++first;
    }
  }
}

template <class BidirIt>
bool next_permutation(BidirIt first, BidirIt last) {
  // No elements so we're done
  if (first == last) {
    return false;
  }
  BidirIt current = last;
  --current;
  // Only one element so we're done
  if (first == current) {
    return false;
  }

  while (true) {
    BidirIt tail, larger_current;

    tail = current;
    --current;
    // Find tails smallest element larger than head's final element
    if (*current < *tail) {
      // Head's final element
      larger_current = last;
      do {
        --larger_current;
      } while (*current >= *larger_current);
      // Swap current with an element near to last which is larger than current
      std::swap(*current, *larger_current);
      // Reverse tail
      reverse(tail, last);
      return true;
    }
    // We already went through all elements
    if (current == first) {
      // Permute to "original" state
      reverse(first, last);
      return false;
    }
  }
}

int main() {
  const std::size_t ORIGINAL_LENGTH = 4;
  std::size_t original[ORIGINAL_LENGTH] = {1, 2, 3, 4};
  do {
    for (std::size_t i = 0; i < ORIGINAL_LENGTH; ++i) {
      std::cout << original[i];
      if (i < ORIGINAL_LENGTH - 1) {
        std::cout << ", ";
      }
    }
    std::cout << '\n';
  } while (next_permutation(&original[0], &original[ORIGINAL_LENGTH]));
  /*
   * In C++11 I'd write:
  std::array<uint16_t, 4> original{1, 2, 3, 4};
  do {
    // uint16_t
    for (const auto& possibility : original) {
      std::cout << possibility;
      if (&possibility != &original.back()) {
        std::cout << ", ";
      }
    }
    std::cout << '\n';
  } while (std::next_permutation(original.begin(), original.end()));
  */
  std::cout << std::flush;
  return EXIT_SUCCESS;
}
