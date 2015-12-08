// Copyright [2015] <none>
#include <cstdlib>

#include <algorithm>
#include <array>
#include <iostream>

#include "./sort.h"

int main() {
  // constexpr std::size_t N = 10;
  // int nums[] = {9, 3, 5, 2, 8, 6, 4, 3, 7, 8};
  std::array<int, 10> numbers = {9, 3, 5, 2, 8, 6, 4, 3, 7, 8};
  std::cout << "Vorher: ";
  // Print(std::cout, &nums[0], &nums[N]);
  Print(std::cout, numbers.begin(), numbers.end());
  std::cout << "Nachher: ";
  // sortiere(nums, N);
  sortiere(numbers.data(), numbers.size());
  // InsertionSort(numbers.begin(), numbers.end());
  // BubbleSort(numbers.begin(), numbers.end());
  // MergeSort(numbers.begin(), numbers.end());
  /*
   * This is usually a very well crafted introsort and should definitely be
   * used instead of any home brew sorting algorithm.
   */
  // std::sort(numbers.begin(), numbers.end());
  // Print(std::cout, &nums[0], &nums[N]);
  Print(std::cout, numbers.begin(), numbers.end());
  AssertSort();
  return EXIT_SUCCESS;
}
