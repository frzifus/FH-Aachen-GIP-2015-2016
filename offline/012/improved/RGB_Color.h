#ifndef OFFLINE_012_RGB_COLOR_H_
#define OFFLINE_012_RGB_COLOR_H_
#include <cstdlib>

#include <array>
#include <tuple>

class RGB_Color {
 public:
  RGB_Color();
  RGB_Color(int red, int green, int blue);
  // Bad getter names
  bool is_color(int colorcode) const;
  int get_red() const;
  int get_green() const;
  int get_blue() const;
  void set_red(int red);
  void set_green(int green);
  void set_blue(int blue);
  void set_color(int red, int green, int blue);
  // Bad design
  void display() const;
  // Bad design
  bool input_color();

 private:
  int red_;
  int green_;
  int blue_;
};

#endif  // OFFLINE_012_RGB_COLOR_H_
