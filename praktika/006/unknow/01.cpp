// Copyright 2015 <none>
#include <iostream>  // std::cout std::cin
#include <string>    // std::getline std::string

std::string input();
void castToLower();
bool palindrom();

/* Prueft Char Array und wandelt GroS- in Kleinbuchstaben
 * Keine Rueckgabe
 */
void castToLower(std::string &forward) {
  for (size_t i = 0; i < forward.length(); i++) {
    if (forward.at(i) >= 'A' && forward.at(i) <= 'Z') {
      forward.at(i) += 'a' - 'A';
    }
  }
}

/* Dreht Wort um und prueft ob es mit dem alten uebereinstimmt
 * Gibt true zuruek
 */
bool checkPalindrom(std::string forward) {
  std::string backward;
  for (int i = forward.length() - 1; i >= 0; i--) {
    backward += forward.at(i);
  }
  return forward == backward;
}

/* Ueberprueft Eingabe ueber ASCII werte
 * Gibt gueltigen string zurueck
 * Keine Abbruchbedingung
 */
std::string input() {
  std::string candidate;    // Zu pruefende Eingabe
  char letter;              // Vergleichsbuchstabe
  bool examination = true;  // Gueltigkeit

  while (examination) {
    std::cout << "Eingabe: ";
    std::getline(std::cin, candidate);
    examination = true;
    for (size_t i = 0; i < candidate.length(); i++) {
      letter = candidate.at(i);
      if ((letter >= 'A' && letter <= 'Z') ||
          (letter >= 'a' && letter <= 'z')) {
        continue;
      } else {
        examination = false;
      }
    }
    if (examination) {
      return candidate;  // input vaild
    }
  }
}

int main() {
  std::string eingabe, save;

  eingabe = input();     // Speichert Eingabe
  save = eingabe;        // Sichert Eingabewert
  castToLower(eingabe);  // Wandelt Eingabe in kleinbuchstaben

  if (checkPalindrom(eingabe)) {
    std::cout << save << " ist ein Palindrom" << std::endl;
  } else {
    std::cout << save << " ist kein Palindrom" << std::endl;
  }
  return 0;
}
