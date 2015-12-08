// Copyright [2016] <none>
#define CIMGGIP_MAIN

#include <array>
#include <string>

#include "./MyRectangle.h"

#include "CImgGIP03.h"

int main() {
  while (gip_window_not_closed()) {
    // Alles neu zeichnen ...
    gip_white_background();

    std::array<MyRectangle, 2> rectangles;
    for (auto& rectangle : rectangles) {
      int x1 = gip_zufall(0, gip_win_sizeX);
      int y1 = gip_zufall(0, gip_win_sizeY);
      int x2 = gip_zufall(x1, gip_win_sizeX);
      int y2 = gip_zufall(y1, gip_win_sizeY);
      rectangle.set(x1, y1, x2, y2);
      rectangle.draw(blue);
    }
    for (const auto& rectangle : rectangles) {
      (rectangle * 0.5).draw(red);
    }
    std::string text = rectangles[0].does_not_collide_with(rectangles[1])
                           ? "Keine Kollision."
                           : "Kollision!";
    gip_draw_text(10, 10, text.c_str());
    // Pausieren ...
    gip_wait(4000);
  }
  return EXIT_SUCCESS;
}
