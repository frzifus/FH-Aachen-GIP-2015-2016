// Copyright [2015] <none>
// Low quality code don't blame me use std::forward_list instead if you need a
// linked list or use std::list if you need a bidirectional linked list.
#include <cstdlib>

#include <iostream>
#include <functional>

struct TListenKnoten {
  int data;
  TListenKnoten* prev;
  TListenKnoten* next;
};

TListenKnoten* GetLastNode(TListenKnoten* node) {
  if (node != nullptr) {
    while (node->next != nullptr) {
      node = node->next;
    }
  }
  return node;
}

TListenKnoten* FindNode(TListenKnoten* node, int value) {
  while (node != nullptr) {
    if (node->data == value) {
      break;
    }
    node = node->next;
  }
  return node;
}

void DeallocateList(TListenKnoten* first) {
  TListenKnoten* node = first;
  while (node != nullptr) {
    // Next node will be first node
    first = node->next;
    // Release memory
    delete node;
    node = first;
  }
}

void PrintList(TListenKnoten* node,
               std::function<TListenKnoten*(TListenKnoten*)> get_next) {
  if (node == nullptr) {
    std::cout << "Leere Liste.\n";
  } else {
    std::cout << "[ ";
    do {
      std::cout << node->data;
      node = get_next(node);
      std::cout << (node != nullptr ? " , " : " ");
    } while (node != nullptr);
    std::cout << "]\n";
  }
}

// NOLINTNEXTLINE
void hinten_anfuegen(TListenKnoten*& first, int wert) {
  TListenKnoten* node = new TListenKnoten;
  node->data = wert;
  node->next = nullptr;
  if (first == nullptr) {
    node->prev = nullptr;
    first = node;
  } else {
    TListenKnoten* last = GetLastNode(first);
    node->prev = last;
    last->next = node;
  }
}

void liste_ausgeben(TListenKnoten* first) {
  PrintList(first,
            [](TListenKnoten* node) -> TListenKnoten* { return node->next; });
}

void liste_ausgeben_rueckwaerts(TListenKnoten* node) {
  TListenKnoten* last = GetLastNode(node);
  PrintList(last,
            [](TListenKnoten* node) -> TListenKnoten* { return node->prev; });
}

/**
 * This function will iterate over a node and insert a node with the value of
 * "value" before the node which contains the value of "search_value".
 * @param first The first node of the list
 * @param value The value to insert
 * @param search_value The value which will be searched for
 * @return True if value was found and node was inserted
 */
void einfuegen(TListenKnoten*& first, int value, int search_value) {
  TListenKnoten* next = FindNode(first, search_value);
  bool has_next = next != nullptr;
  /*
   * This code can perform better but the better performing solution would be a
   * hack. Instead we should put all this inside a class and update pointers to
   * the start and end.
   */
  TListenKnoten* prev = has_next ? next->prev : GetLastNode(first);
  // Construct new node
  TListenKnoten* node = new TListenKnoten;
  node->data = value;
  node->prev = prev;
  node->next = next;
  // Update links
  if (prev != nullptr)
    prev->next = node;
  else
    first = node;
  if (has_next) next->prev = node;
}

int main() {
  constexpr int LAENGE = 10;
  TListenKnoten* anker = nullptr;
  liste_ausgeben(anker);
  for (int i = 0; i < LAENGE; ++i) {
    hinten_anfuegen(anker, i * i);
  }
  liste_ausgeben(anker);
  liste_ausgeben_rueckwaerts(anker);
  int wert_neu, vor_wert;
  std::cout << "Einzufuegender Wert: ";
  std::cin >> wert_neu;
  std::cout << "Vor welchem Wert? ";
  std::cin >> vor_wert;
  einfuegen(anker, wert_neu, vor_wert);
  liste_ausgeben(anker);
  DeallocateList(anker);
  anker = nullptr;
  return EXIT_SUCCESS;
}
