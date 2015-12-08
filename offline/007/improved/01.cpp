// Copyright [2015] <none>
#include <cstdlib>

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

const char EMPTY_PIXEL{'.'};
const char FILLED_PIXEL{'#'};

template <class FwdIt>
void FillCanvas(FwdIt first, FwdIt last) {
  for (; first != last; ++first) {
    (*first).fill(EMPTY_PIXEL);
  }
}

template <class FwdIt>
void PrintCanvas(FwdIt first, FwdIt last) {
  for (; first != last; ++first) {
    for (const char character : *first) {
      std::cout << character;
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

template <class FwdIt>
void FillPixel(FwdIt first, int x, int y) {
  using difference_type = typename std::iterator_traits<FwdIt>::difference_type;
  (*(first + static_cast<difference_type>(y)))[static_cast<std::size_t>(x)] =
      FILLED_PIXEL;
}

// Bresenham's line algorithm
// Should be using a class instead
template <class FwdIt>
void Linie(int x1, int y1, int x2, int y2, FwdIt first) {
  // Make x2 >= x1 if it isn't
  if (x1 > x2) {
    std::swap(x1, x2);
    std::swap(y1, y2);
  }
  // Check out if it's steep
  int dx = x2 - x1;
  int dy = std::abs(y2 - y1);
  const bool steep = dy > dx;
  // Swap axis if it's steep
  if (steep) {
    std::swap(x1, y1);
    std::swap(x2, y2);
    std::swap(dx, dy);
  }
  const float dxf = static_cast<float>(dx);
  const float dyf = static_cast<float>(dy);
  // Step up or step down?
  const int ystep = y1 < y2 ? 1 : -1;

  float error = dxf / 2.0f;

  for (; x1 < x2; x1++) {
    if (steep) {
      FillPixel(first, y1, x1);
    } else {
      FillPixel(first, x1, y1);
    }
    // No need to run if error - dyf * dxf >= 0
    error -= dyf;
    if (error < 0) {
      y1 += ystep;
      error += dxf;
    }
  }
}

int main() {
  const std::size_t CANVAS_SIZE{60};
  std::array<std::array<char, CANVAS_SIZE>, CANVAS_SIZE> canvas;
  FillCanvas(canvas.begin(), canvas.end());
  int x1{0}, y1{0}, x2{0}, y2{0};
  // I'll let the user enter invalid values.
  std::cout << "Bitte geben Sie den ersten Punkt ein: ? ";
  std::cin >> x1 >> y1;
  std::cout << "Bitte geben Sie den zweiten Punkt ein: ? ";
  std::cin >> x2 >> y2;
  Linie(x1, y1, x2, y2, canvas.begin());
  PrintCanvas(canvas.begin(), canvas.end());
  return EXIT_SUCCESS;
}
