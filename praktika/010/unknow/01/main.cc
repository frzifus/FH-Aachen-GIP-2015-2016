// Copyright 2015 <none>

#include "./CImgGIP02.h"

struct Box {
  int x;
  int y;
  int delta_y;
};

const int BOX_SIZE = 50;
const int BOX_MAX = gip_win_sizeX / (BOX_SIZE + 20);
const int BOX_MAX_DELTA_Y = 90;

void start_box_at_top(Box& b, int count) {
  // Setze b.x und b.y für das Kästchen ...
  b.x = count * (BOX_SIZE + 20) + 10;
  b.y = 0;
  if (b.delta_y > 0 && (b.delta_y + 10) < BOX_MAX_DELTA_Y) {
    b.delta_y += 10;
  } else {  // sonst: setze Fallgeschw auf Zufallswert
    b.delta_y = gip_zufall(20, BOX_MAX_DELTA_Y / 2);
  }
}

void draw_boxes(Box boxes[]) {
  gip_white_background();
  for (int i{}; i < BOX_MAX; ++i) {
    Box& replace = boxes[i];
    gip_draw_rectangle(replace.x, replace.y, replace.x + BOX_SIZE,
                       replace.y + BOX_SIZE, blue);
  }
}

bool update_boxes(Box boxes[]) {
  // Koordinaten updaten ...
  // Wenn Box am unteren Ende "rausgefallen",
  // dann oben wieder starten lassen ...
  for (int i{}; i < BOX_MAX; ++i) {
    Box& replace = boxes[i];
    replace.y += replace.delta_y;
    if (replace.y > gip_win_sizeY) {
      return false;
    }
  }
  draw_boxes(boxes);
  return true;
}

void check_if_box_clicked(Box boxes[]) {
  int mx = gip_mouse_x();
  int my = gip_mouse_y();
  for (int i{0}; i < BOX_MAX; ++i) {
    Box& replace = boxes[i];
    if ((mx >= replace.x && mx <= replace.x + BOX_SIZE) &&
        (my >= replace.y && my <= replace.y + BOX_SIZE)) {
      start_box_at_top(replace, i);
    }
  }
}

int main() {
  Box boxes[BOX_MAX] = {0};
  bool keep_going = true;
  for (int i{0}; i < BOX_MAX; i++) {
    start_box_at_top(boxes[i], i);
  }
  draw_boxes(boxes);
  while (keep_going && gip_window_not_closed()) {
    for (int loop_count{0}; loop_count < 200; loop_count++) {
      gip_wait(5);
      if (gip_mouse_button1_pressed()) {
        check_if_box_clicked(boxes);
      }
    }
    keep_going = update_boxes(boxes);
  }
  return 0;
}
