#include <cstdlib>

#include <array>
#include <iostream>
#include <string>
#include <utility>

#include "./RGB_Color.h"

int main() {
  // Unit test doesn't care btw
  std::array<std::pair<std::string, RGB_Color>, 6> colors;
  colors[0] = std::make_pair("Weiss", RGB_Color());
  colors[1] = std::make_pair("Tuerkies", RGB_Color(0, 255, 255));
  // Could ignore that ugly way to match output since the unit test doesn't care
  colors[2] = std::make_pair("Gelb ", RGB_Color(255, 255, 0));
  colors[3] = std::make_pair("Magenta", RGB_Color(255, 0, 255));
  // Could ignore that ugly way to match output since the unit test doesn't care
  colors[4] = std::make_pair("\nFarbe 1", RGB_Color(255, 255, 128));
  // Redundant
  colors[5] = std::make_pair("\nFarbe 2", RGB_Color(255, 255, 128));
  for (const auto& color_pair : colors) {
    const auto& name = color_pair.first;
    const auto& color = color_pair.second;
    std::cout << name << ":\n";
    color.display();
  }
  auto& color = colors[5].second;
  std::cout << "\nNeu-Eingabe von Farbe 2:\n";
  if (!color.input_color()) {
    std::cout << "Falsche Eingabe!\n";
  }
  std::cout << "\nFarbe 2 jetzt:\n";
  color.display();
  return EXIT_SUCCESS;
}
