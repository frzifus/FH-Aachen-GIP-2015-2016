// Copyright 2015 <none>
#include <iostream>  // std::cout std::cin std::getline
#include <string>    // std::string
#include <cstddef>   // std::size_t

void MirrorWord(std::string&, std::size_t);
char EnterCommand();

void MirrorWord(const std::string &text, std::size_t position) {
  std::size_t last_letter = position;
  std::size_t first_letter = position;
  std::string temp_str;
  std::size_t j;
                                                               /*
                                                                * LoopParty->inc()
                                                                */
  if (text[position] == ' ' || text[position] == '.') {
      return;
  }

  while (last_letter < text.length()) {
    if (text[last_letter] == ' ' || text[last_letter] == '.') {
      break;
    }
    last_letter++;
  }

  while (first_letter > 0) {
    if (text[first_letter] == ' ' || text[first_letter] == '.') {
      first_letter++;                                            // y i know ~.~
      break;
    }
    first_letter--;
  }

  for (std::size_t i = first_letter; i < last_letter; ++i) {
    temp_str += text.at(i);
    j = temp_str.length();
  }

  for (std::size_t i = first_letter; i < last_letter; ++i) {
    j--;
    text.at(i) = temp_str.at(j);
  }
}

char EnterCommand() {
  char input;
  std::cout << "Befehl (l: links, r: rechts, s: spiegeln, q: Ende) ?- ";
  std::cin >> input;
  return input;
}

int main() {
  enum Command { LEFT = 'l', RIGHT = 'r', REVERSE = 's', QUIT = 'q' };
  std::size_t position {};
  std::string text;
  char command;

  std::cout << "Bitte geben Sie einen Text ein: ";
  std::getline(std::cin, text);

  do {
    command = EnterCommand();
    switch (command) {
      case LEFT:
        if (position > 0) {
          position--;
        }
        break;
      case RIGHT:
        if (position < text.length() -1) {
          position++;
        }
        break;
      case REVERSE:
        MirrorWord(text, position);
        break;
      default:
        break;
    }
    std::cout << text << std::endl;
    std::cout << std::string(position, ' ') << '*' << std::endl;
  } while (command != QUIT);
  return 0;
}
