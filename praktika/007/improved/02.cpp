// Copyright [2015] <none>
#include <cstdlib>    // EXIT_SUCCESS, std::size_t
#include <limits>     // std::numeric_limits
#include <ios>        // std::streamsize
#include <iostream>   // std::cin, std::cout, std::getline
#include <string>     // std::string
#include <algorithm>  // std::reverse, std::find_if
#include <iterator>   // std::reverse_iterator

inline bool IsWordBorder(const char character) {
  return character == ' ' || character == '.';
}

/**
 * Non-const references are forbidden by the gsg but I'll use them in this case
 * because the task told me to.
 */
// NOLINTNEXTLINE
void MirrorWord(std::string& text, std::size_t position) {
  if (IsWordBorder(text[position])) {
    return;
  }
  std::string::iterator position_iter(
      text.begin() + static_cast<std::string::difference_type>(position));
  std::reverse_iterator<std::string::iterator> position_riter(position_iter);
  std::string::iterator word_end_iter =
      std::find_if(position_iter, text.end(), IsWordBorder);
  std::string::iterator word_start_iter =
      std::find_if(position_riter, text.rend(), IsWordBorder).base();

  std::reverse(word_start_iter, word_end_iter);
}

int main() {
  enum class Command : char {
    LEFT = 'l',
    RIGHT = 'r',
    REVERSE = 's',
    QUIT = 'q'
  };
  std::string text;
  std::size_t position = 0;
  std::cout << "Bitte geben Sie den Text ein: ";
  std::getline(std::cin, text);
  bool keep_running = true;
  do {
    std::cout << "Befehl (l: links, r: rechts, s: spiegeln, q: Ende) ?- ";
    char command = static_cast<char>(std::cin.get());  // Read one character
    if (command != '\n') {
      // Ignore characters until line break
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (!std::cin.good()) {
      std::cin.clear();
      std::cout << u8"\nUngültige Eingabe!\n";
      continue;
    }
    switch (static_cast<Command>(command)) {
      case Command::LEFT:
        if (position > 0) {
          --position;
        }
        break;
      case Command::RIGHT:
        if (position < text.size() - 1) {
          ++position;
        }
        break;
      case Command::REVERSE:
        MirrorWord(text, position);
        break;
      case Command::QUIT:
        keep_running = false;
        break;
      default:
        std::cout << u8"Ungültiger Befehl: " << command << '\n';
        continue;
        // break;
    }
    std::cout << '\n' << text << '\n' << std::string(position, ' ') << "*\n"
              << std::flush;
  } while (keep_running);
  return EXIT_SUCCESS;
}
