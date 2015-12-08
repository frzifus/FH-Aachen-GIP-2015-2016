// Copyright [2015] <none>
#include <cstdlib>  // EXIT_SUCCESS, std::size_t

#include <array>     // std::array
#include <iomanip>   // std::setw, std::setfill
#include <iostream>  // std::cout, std::cin, std::flush
#include <string>    // std::string
#include <utility>   // std::pair

#include "boost/date_time/posix_time/posix_time.hpp"  // boost::posix_time

template <class BeforeEnter>
int EnterNumberFromRange(const std::pair<int, int> range,
                         BeforeEnter before_enter) {
  std::size_t tries{0};
  int number;
  // Using while instead of do while here because it doesn't really make a
  // difference and I can leave the loop before the increment even though tries
  // is a currently unused feature. Furthermore the range check seems more human
  // too me like this.
  while (true) {
    before_enter(tries);
    std::cin >> number;
    if (number >= range.first && number <= range.second) {
      break;
    }
    ++tries;
  }
  return number;
}

int main() {
  const boost::posix_time::time_duration end_of_day{
      boost::posix_time::hours(24)};
  boost::posix_time::time_duration interval;
  int hours, minutes;
  // enter departure time of first bus
  hours = EnterNumberFromRange({0, 23}, [](std::size_t) {
    std::cout << "Bitte geben Sie die Stunden der Startuhrzeit ein: ";
  });
  minutes = EnterNumberFromRange({0, 59}, [](std::size_t) {
    std::cout << "Bitte geben Sie die Minuten der Startuhrzeit ein: ";
  });
  boost::posix_time::time_duration next_bus{
      boost::posix_time::hours(hours) + boost::posix_time::minutes(minutes)};
  // print info about first bus
  std::cout << std::setfill('0') << "Der erste Bus faehrt also um "
            << std::setw(2) << next_bus.hours() << ':' << std::setw(2)
            << next_bus.minutes() << " Uhr.\n" << std::flush;
  // enter interval in minutes
  interval = boost::posix_time::minutes(
      EnterNumberFromRange({1, 180}, [](std::size_t) {
        std::cout << "Bitte geben Sie die Taktzeit in Minuten ein: ";
      }));
  while (next_bus < end_of_day) {
    // put linebreak when hours got incremented
    if (next_bus.hours() > hours) {
      hours = next_bus.hours();
      std::cout << '\n';  // no need to flush
    }
    // terrible solution but luckily no production
    std::cout << std::setw(2) << next_bus.hours() << ':' << std::setw(2)
              << next_bus.minutes() << "  ";
    next_bus += interval;
  }
  std::cout << std::flush;
  return EXIT_SUCCESS;
}
