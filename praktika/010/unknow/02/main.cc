// Copyright 2015 <Sascha + flymake>

#include <iostream>

struct TListenKnoten {
  int data;
  TListenKnoten *next;
  TListenKnoten *prev;
};

void HintenAnfuegen(TListenKnoten* &anker, int wert) {
  // neues Element mit wert initialisieren
  TListenKnoten *neuer_eintrag = new TListenKnoten;
  neuer_eintrag->data = wert;
  neuer_eintrag->next = nullptr;
  neuer_eintrag->prev = nullptr;
  if (anker == nullptr) {
    anker = neuer_eintrag;
  } else {  // Wert hinten an die Liste anfügen
    TListenKnoten *ptr = anker;
    while (ptr->next != nullptr) {
      ptr = ptr->next;  // Laufe liste erneut durch
    }
    ptr->next = neuer_eintrag;  // Fuege neuen eintrag hinten ein.
  }
}

void ListeAusgeben(TListenKnoten * anker) {
  if (anker == nullptr) {
    std::cout << "Leere Liste." << std::endl;
  } else {
    std::cout << "[ ";
    TListenKnoten *ptr = anker;
    do {
      std::cout << ptr->data;
      if (ptr->next != nullptr) {
        std::cout << " , ";
      } else {
        std::cout << " ";
      }
      ptr = ptr->next;
    } while (ptr != nullptr);
  std::cout << "]" << std::endl;
  }
}

void ListeAusgebenRueckwaerts(TListenKnoten* anker, TListenKnoten* end) {
  if (anker == nullptr) {
    std::cout << "Leere Liste." << std::endl;
  } else {
    std::cout << "[ ";
    TListenKnoten *ptr = anker;
    do {
      ptr = ptr->next;
       } while (ptr->next != nullptr);  // Suche nach dem Ende der Liste
    TListenKnoten *end = ptr;  // endpointer für die rückrichtung
    ptr = anker;
    // TListenKnoten *temp = new TListenKnoten;
    TListenKnoten *temp = end;
    while (ptr->next != nullptr) {
      // immer ein element abzeihen um so eine "vergammelte"
      // rueckrichtung zu erzeugen!
      if (ptr->next->data == temp->data) {
        // geht die Liste runter, komischer weise nur bis 4
        temp->prev = ptr;
        std::cout << temp->data << " , ";
        ptr = anker;
        temp = temp->prev;
      }
    // if(ptr->data == temp->data)
    ptr = ptr->next;
    }
    std::cout << temp->data;  // Das letzte element wird nachgeschoben! lol
    std::cout << " , "<< anker->data;  // den "anker", der eigendlich
                                  // kein Datenelement ist ausgeben
    std::cout << " ]" << std::endl;
  }
}
void Einfuegen(TListenKnoten* &anker, int wert_neu, int vor_wert) {
  // Wert_neu wird immmer hinten angefuegt, soll der Wert
  // nicht vorkommen so soll der Wert ans Ende der Liste angehängt werden.
  bool wert_gesetzt = false;
  TListenKnoten *ptr = anker;
  if (vor_wert == anker->data) {
    TListenKnoten *neuer_eintrag = new TListenKnoten;
    neuer_eintrag->data = ptr->data;
    neuer_eintrag->next = ptr;
    neuer_eintrag->data = wert_neu;
    anker = neuer_eintrag;
  } else {
    while (ptr->next != nullptr) {
      if (ptr->next->data == vor_wert && wert_gesetzt == false) {
        // ansonsten arbeite mit flags und dann fuege den gesuchten
        // datensatz ein!
        wert_gesetzt = true;
        TListenKnoten *neuer_eintrag = new TListenKnoten;
        neuer_eintrag->next = ptr->next;
        ptr->next = neuer_eintrag;
        neuer_eintrag->data = wert_neu;
      } else {
        ptr = ptr->next;
      }
    }
  }
}

int main() {
  int laenge{10};
  TListenKnoten *anker = nullptr;
  TListenKnoten *end = anker;
  for (int i{0}; i < laenge; ++i) {
    HintenAnfuegen(anker, i*i);
  }
  ListeAusgeben(anker);
  int option{0};
  std::cout << "Bitte waehlen Sie eine Option aus: " << std::endl
       << "1. Element Einfuegen" << std::endl
       << "2. Liste rueckwaerts ausgeben" << std::endl << ">>> ";
  std::cin >> option;
  if (option == 1) {
    int wert_neu, vor_wert;
    std::cout << "Einzufuegender Wert: ";
    std::cin >> wert_neu;
    std::cout << "Vor welchem Wert? ";
    std::cin >> vor_wert;
    Einfuegen(anker, wert_neu, vor_wert);
    ListeAusgeben(anker);
  } else if (option == 2) {
    ListeAusgebenRueckwaerts(anker, end);
  } else {
    std::cout << "Sie haben einen fehler bei der Eingabe gemacht!"
         << std::endl << "Einen schoenen Tag noch!" << std::endl;
  }
  // system("PAUSE");
  return 0;
}
