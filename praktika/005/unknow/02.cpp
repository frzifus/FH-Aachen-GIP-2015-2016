// Copyright 2015 <none>
#include <iostream>

double getConsumption();
void PrintAverageConsumption();
void PrintCurrentConsumption();
bool CheckNinetyNine();

double getConsumption() {
  double Consumption;
  do {
  std::cout << "Bitte geben Sie den neuen letzten Verbrauch ein: ? ";
  std::cin >> Consumption;
  } while (Consumption < 0);
  return Consumption;
}

void PrintAverageConsumption(double AverageConsumption) {
  std::cout << "Der Durchschnitt der letzten drei Verbrauchswerte betraegt "
            << AverageConsumption << std::endl;
}

void PrintCurrentConsumption(double CurrentConsumption) {
  std::cout << "Der bisherige Gesamtverbrauch betraegt "
            << CurrentConsumption << std::endl;
}

bool CheckNinetyNine(int num) {
  if (num != 99) {
    return true;
  }
  return false;
}

int main() {
  double Consumption[3] = {0, 0, 0};
  double AverageConsumption;
  int Counter(0);
  double CurrentConsumption(0);
  do {
    Consumption[Counter] = getConsumption();
    if (!CheckNinetyNine(Consumption[Counter])) {
      std::cout << std::endl;
      break;
    }
    AverageConsumption = (Consumption[0] + Consumption[1] + Consumption[2]) / 3;
    CurrentConsumption += Consumption[Counter];
    PrintCurrentConsumption(CurrentConsumption);
    PrintAverageConsumption(AverageConsumption);
    if (Counter >= 3) {
      Counter = 0;
    }
    Counter++;
  } while (true);
  return 0;
}
