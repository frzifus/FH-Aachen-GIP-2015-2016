// Copyright [2015] <none>
#include <cstdlib>

#include <array>
#include <iostream>
#include <string>
#include <utility>

int main() {
  const std::size_t SIZE = 3;
  const std::array<std::pair<int, std::string>, SIZE> time_helper{
      {{60 * 60, "Stunden"}, {60, "Minuten"}, {1, "Sekunden"}}};
  int seconds = 0;
  for (const auto& pair : time_helper) {
    int tmp;
    std::cout << pair.second << " ? ";
    std::cin >> tmp;
    seconds += tmp * pair.first;
  }
  std::cout << "Zeit in Sekunden: " << seconds << '\n';
  return EXIT_SUCCESS;
}
