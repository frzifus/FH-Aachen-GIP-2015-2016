// Copyright [2015] <none>
#include <cstdlib>

#include <algorithm>
#include <chrono>
#include <iostream>
#include <ratio>

#include "CImgGIP02.h"

struct Box {
  int x;
  int y;
  int delta_y;
  Box() : delta_y(0) {}
};
// Die Größe jedes Kästchens (Quadrat => Länge == Breite) ...
constexpr int BOX_SIZE = 50;

// Kästchen Nr. "count" am oberen Bildschirmrand "starten".
// Fälle:
// 1. Zu Beginn des Spiels
// 2. Neustart (nach dem Anklicken), mit erhöhter Geschwindigkeit
// NOLINTNEXTLINE
void StartBoxAtTop(Box& box, int count) {
  // Maximale Fallgeschwindigkeit (in Pixel pro Bildschirmupdate) ...
  constexpr int BOX_MAX_DELTA_Y = 90;
  // Set position of box
  box.x = count * (BOX_SIZE + 20) + 10;
  box.y = 0;
  if (box.delta_y == 0) {
    // Set velocity to random value if it didn't have a velocity yet
    // Usually a box without velocity did not exist before
    box.delta_y = gip_zufall(20, BOX_MAX_DELTA_Y / 2);
  } else if (box.delta_y != BOX_MAX_DELTA_Y) {
    ++box.delta_y;
  }
}
// DrawBoxes():
// Zeichne die Kästchen boxes[0] bis boxes[box_max] ...
template <class InputIt>
void DrawBoxes(InputIt first, InputIt last) {
  // Lösche den bisherigen Fensterinhalt komplett,
  // d.h. komplettes Neuzeichnen aller Kästchen etc ...
  gip_white_background();
  // Und jetzt alle Kästchen zeichnen.
  // Linke obere Ecke: (boxes[i].x, boxes[i].y)
  // Größe: box_size x box_size
  // Farbe: blue
  std::for_each(first, last, [](const Box& box) {
    gip_draw_rectangle(box.x, box.y, box.x + BOX_SIZE, box.y + BOX_SIZE, blue);
  });
}
// UpdateBoxes():
// 1. Berechne neue y-Koordinate (Box boxes[i] fällt um boxes[i].delta_y)
// 2. Prüfe, ob eine Box das untere Fensterende gip_win_sizeY überschritten
// hat.Falls ja : gib sofort false zurück
// 3. (Sonst:) Rufe DrawBoxes() auf, gib true zurück
template <class FwdIt>
bool UpdateBoxes(FwdIt first, FwdIt last) {
  // Koordinaten updaten ...
  // Wenn Box am unteren Ende "rausgefallen",
  // dann oben wieder starten lassen ...
  bool redraw = std::none_of(first, last, [](Box& box) {
    box.y += box.delta_y;
    return box.y > gip_win_sizeY;
  });
  if (redraw) {
    DrawBoxes(first, last);
  }
  return redraw;
}
// CheckIfBoxClicked():
// Annahme: Funktion wird nur aufgerufen, wenn die Maus wirklich
// geklickt wurde. Die Funktion braucht dies also nicht mehr zu prüfen.
// Nimm die Koordinaten der Mausposition und prüfe dann für jede Box durch,
// ob die Koordinaten innerhalb der Box liegen. Falls ja, rufe für diese
// Box dann start_box_at_top() auf.
template <class FwdIt>
void ClickBox(FwdIt first, FwdIt last) {
  int mx = gip_mouse_x();
  int my = gip_mouse_y();
  for (; first != last; ++first) {
    Box& box = *first;
    if (mx >= box.x && mx <= box.x + BOX_SIZE && my >= box.y &&
        my <= box.y + BOX_SIZE) {
      StartBoxAtTop(box, static_cast<int>(std::distance(first, last) - 1));
      break;
    }
  }
}

int main() {
  constexpr int kMillisecondsOfSecond = 1000;
  // Wieviele Kästchen passen nebeneinander ins Fenster,
  // bei Kästchengröße box_size und 20 Pixel Zwischenraum
  // zwischen den Kästchen ...
  constexpr int BOX_MAX = gip_win_sizeX / (BOX_SIZE + 20);
  std::array<Box, BOX_MAX> boxes;
  bool keep_going = true;
  for (std::size_t i = 0; i != boxes.size(); ++i) {
    StartBoxAtTop(boxes[i], static_cast<int>(i));
  }
  DrawBoxes(boxes.begin(), boxes.end());
  // CImg wasn't made for this at all and this is a terrible way to do this
  while (keep_going && gip_window_not_closed()) {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    while (true) {
      gip_wait(5);
      if (gip_mouse_button1_pressed()) {
        ClickBox(boxes.rbegin(), boxes.rend());
      }
      end = std::chrono::system_clock::now();
      auto elapsed_milliseconds =
          std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
              .count();
      if (elapsed_milliseconds >= kMillisecondsOfSecond) {
        start = end;
        if (elapsed_milliseconds > kMillisecondsOfSecond) {
          start += std::chrono::milliseconds(kMillisecondsOfSecond -
                                             elapsed_milliseconds);
        }
        break;
      }
    }
    keep_going = UpdateBoxes(boxes.begin(), boxes.end());
  }
  return EXIT_SUCCESS;
}

