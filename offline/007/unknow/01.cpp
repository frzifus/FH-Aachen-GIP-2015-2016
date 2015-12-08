#include <iostream>
using namespace std;
const char empty_pixel = '.';
const char filled_pixel = '#';
const int canvas_size = 60;

// Globale Variablen sollten nicht verwendet werden. Aber wir haben noch nicht
// gelernt, wie man Arrays als Parameter in Funktionen hineinreichen kann.
// Daher muessen wir das Array hier doch als globale Variable definieren, damit
// alle Funktionen darauf zugreifen koennen ...
char canvas[canvas_size][canvas_size];
void init_canvas() {
  for (int x = 0; x < canvas_size; x++)
    for (int y = 0; y < canvas_size; y++) canvas[x][y] = empty_pixel;
}
void print_canvas() {
  for (int y = 0; y < canvas_size; y++) {
    for (int x = 0; x < canvas_size; x++) {
      cout << canvas[x][y];
    }
    cout << endl;
  }
  cout << endl;
}
void linie(int x1, int y1, int x2, int y2) {
  int x3 = x1 > x2 ? x1 - x2 : x2 - x1;
  int y3 = y1 > y2 ? y1 - y2 : y2 - y1;
  if (x3 < 2 && y3 < 2) {
    canvas[x2][y2] = canvas[x1][y1] = filled_pixel;
  } else {
    // Berechne die ganzzahligen Koordinaten des
    // Punktes in der Mitte zwischen den beiden
    // Ausgangspunkten:
    int x_mitte = (x1 + x2) / 2;
    int y_mitte = (y1 + y2) / 2;
    // Rekursive Aufrufe:

    // 1. Linie vom ersten Punkt bis zur Mitte
    // 2. Linie von der Mitte bis zum zweiten Punkt
    linie(x_mitte, y_mitte, x1, y1);
    linie(x_mitte, y_mitte, x2, y2);
  }
}
int main() {
  init_canvas();
  int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  do {
      cout << "Bitte geben Sie den ersten Punkt ein: ? ";
      cin >> x1 >> y1;
  } while (x1 < 0 || x1 >= canvas_size || y1 < 0 || y1 >= canvas_size);
  do {
      cout << "Bitte geben Sie den zweiten Punkt ein: ? ";
      cin >> x2 >> y2;
  } while (x2 < 0 || x2 >= canvas_size || y2 < 0 || y2 >= canvas_size);
  linie(x1, y1, x2, y2);
  print_canvas();
  system("PAUSE");
  return 0;
}
