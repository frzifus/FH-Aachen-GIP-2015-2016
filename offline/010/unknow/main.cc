// Copyright [2015] <none>
#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

const int kMaxStrLen = 80;

int mystrlen(const char* ptr) {
  for (int i{}; i < kMaxStrLen; ++i) {
    if (ptr[i] == '\0') { return i; }
  }
}

char* mystrnconcat(const char* sptr1, const char* sptr2, int count) {
  char* c = new char[mystrlen(sptr1) + count];
  int i{};
  
  // strlen should not be part of a loop condition. Use a variable for that!
  // You don't want to search every single fucking time for '\0' to get the
  // strlen, do you?
  int len1 = mystrlen(sptr1),
      len2 = mystrlen(sptr2);

  // Approach: Since we allocated enough space for c, we can iterate safely
  for (; i < count && i < len1; ++i, ++c) {
    // We dereference the address and set the char at that position
    (*c) = sptr1[i];
  }
  // Since c is at the end of the string now, we have to reset it's position
  // back to the start. How it looks like in memory:
  // [CHAR][CHAR][CHAR][CHAR]
  //                    c is here
  // Since we know exactly how far we have moved our c, we can tell it to go
  // back by the same amount of bits, which is the size of the char times i
  c = c - sizeof(*c) * static_cast<long unsigned int>(i);

  for (int k{}; i < count && k < len2; ++i, ++k) {
    // Since Bjarne agreed that the first approach is bullshit, we have another
    // one here. You're familiar with that one already.
    c[i] = sptr2[k];
  }
  c[i] = '\0';
  return c;
}

int main() {
  cout << "Bitte waehlen Sie die Operation aus." << endl;
  cout << "-1- mystrlen()" << endl
       << "-2- mystrnconcat()" << endl;
  // Could've been an int, but this way it's safer
  char choice;
  cin >> choice;

  switch (choice) {
    case '1':
      {
        cout << "Zeichenkette? ";
        char c[kMaxStrLen];
        cin >> c;
        cout << "Ergebnis mystrlen(): " << mystrlen(c) << endl;
        break;
      }
    case '2':
      {
        cout << "Erste Zeichenkette? ";
        char c1[kMaxStrLen], c2[kMaxStrLen];
        cin >> c1;

        cout << "Zweite Zeichenkette? ";
        cin >> c2;

        cout << "Anzahl Zeichen? ";
        int zeichen;
        cin >> zeichen;

        cout << "Ergebnis mystrnconcat(): " << mystrnconcat(c1, c2, zeichen) << endl;
        // Unnecessary since it's the last case
        break;
      }
  }
  return 0;
}
