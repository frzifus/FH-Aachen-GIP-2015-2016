// Copyright [2015] <none>
#include <cstdlib>

#include <iostream>

#include "CImgGIP01.h"

int main() {
  constexpr int RECTANGLE_SIZE{50};
  constexpr int LEFT_BORDER{100};
  constexpr int RIGHT_BORDER{gip_win_sizeX - LEFT_BORDER};
  constexpr int RECTANGLE_MAX_RIGHT{RIGHT_BORDER - RECTANGLE_SIZE};
  int delta{10};
  int x{200};
  int y{300};

  gip_white_background();
  // We should probably implement some double buffering some day
  // This does look like a very inefficient way to do this
  while (gip_window_not_closed()) {
    gip_draw_rectangle(LEFT_BORDER, LEFT_BORDER, RIGHT_BORDER, RIGHT_BORDER,
                       blue);
    gip_draw_rectangle(x, y, x + RECTANGLE_SIZE, y + RECTANGLE_SIZE, white);
    x += delta;
    if (x <= LEFT_BORDER) {
      // If equal there's no need to do this (in assembly we could just do one
      // cmp and reuse the flags ZF == 0) but C++ is not that capable I guess
      x += LEFT_BORDER - x;
      delta *= -1;
    } else if (x >= RECTANGLE_MAX_RIGHT) {
      x -= x - RECTANGLE_MAX_RIGHT;
      delta *= -1;  // Somewhat redundant
    }
    // This does look like a very inefficient way to do this
    // I guess we only use around 3 fps so that not having double buffering
    // doesn't drive us totally crazy
    gip_wait(300);
  }
  return EXIT_SUCCESS;
}
