// Copyright [2015] <none>
#include <cstdlib>    // EXIT_SUCCESS, std::size_t
#include <iostream>   // std::cout, std::cin
#include <array>      // std::array
#include <algorithm>  // std::accumulate, std::rotate

// Don't do stuff like this in real code!
int main() {
  const int EXIT_VALUE{99};
  const std::size_t N_AVG{3};

  double consumption{-1};
  double total_consumption{0};

  std::array<double, N_AVG> last_consumption;
  last_consumption.fill(0);
  do {
    // this check is useless on first iteration and could be removed by adding
    // two lines of code
    if (consumption >= 0) {
      // rotate left by one
      std::rotate(last_consumption.begin(), last_consumption.begin() + 1,
                  last_consumption.end());
      // set last
      last_consumption[N_AVG - 1] = consumption;
      // get avearge of N_AVG elements
      double average = std::accumulate(last_consumption.begin(),
                                       last_consumption.end(), 0.0);
      average /= static_cast<double>(N_AVG);
      // update total consumption
      total_consumption += consumption;
      // give the user some info
      std::cout << "Der bisherige Gesamtverbrauch betraegt "
                << total_consumption << std::endl;
      std::cout << "Der Durchschnitt der letzten drei Verbrauchswerte betraegt "
                << average << std::endl;
    }
    std::cout << "Bitte geben Sie den neuen letzten Verbrauchswert ein: ? ";
    std::cin >> consumption;
  } while (static_cast<int>(consumption) != EXIT_VALUE);
  return EXIT_SUCCESS;
}
