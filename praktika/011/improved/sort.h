// Copyright [2015] <none>
#ifndef PRAKTIKA_011_BENNE_SORT_H_
#define PRAKTIKA_011_BENNE_SORT_H_

#include <cstdlib>

#include <ostream>

template <class InputIt>
void Print(std::ostream&, InputIt, InputIt);  // NOLINT

void AssertSort();

template <class FwdIt>
constexpr void Merge(FwdIt, FwdIt, FwdIt);

template <class FwdIt>
constexpr void MergeSort(FwdIt, FwdIt);

template <class FwdIt>
constexpr void BubbleSort(FwdIt, FwdIt);
template <class FwdIt>
constexpr void InsertionSort(FwdIt, FwdIt);

void sortiere(int*, std::size_t);  // NOLINT

#endif  // PRAKTIKA_011_BENNE_SORT_H_
