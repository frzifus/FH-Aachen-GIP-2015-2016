#include "./RGB_Color.h"

#include <iostream>
#include <string>

RGB_Color::RGB_Color() : red_(255), green_(255), blue_(255) {}
RGB_Color::RGB_Color(int red, int green, int blue) {
  set_color(red, green, blue);
}
bool RGB_Color::is_color(int colorcode) const {
  return colorcode >= 0 && colorcode <= 255;
}
int RGB_Color::get_red() const { return red_; }
int RGB_Color::get_green() const { return green_; }
int RGB_Color::get_blue() const { return blue_; }
void RGB_Color::set_red(int red) {
  if (is_color(red)) {
    red_ = red;
  }
}
void RGB_Color::set_green(int green) {
  if (is_color(green)) {
    green_ = green;
  }
}
void RGB_Color::set_blue(int blue) {
  if (is_color(blue)) {
    blue_ = blue;
  }
}
void RGB_Color::set_color(int red, int green, int blue) {
  set_red(red);
  set_green(green);
  set_blue(blue);
}
void RGB_Color::display() const {
  std::cout << "rot: " << red_ << " gruen: " << green_ << " blau: " << blue_
            << '\n';
}
bool RGB_Color::input_color() {
  const std::array<std::string, 3> kColorNames = {"rot", "gruen", "blau"};
  std::array<int, 3> colors;
  for (std::size_t i = 0; i < colors.size(); ++i) {
    std::cout << kColorNames[i] << " (0...255): ? ";
    int color;
    std::cin >> color;
    if (!is_color(color)) return false;
    colors[i] = color;
  }
  red_ = colors[0];
  green_ = colors[1];
  blue_ = colors[2];
  return true;
}
