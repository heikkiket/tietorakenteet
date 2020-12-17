#include <iostream>
#include <list>
#include <string>

using namespace std;

#include "SukuNimiComparator.cpp"
#include "matkakortti.h"
#include "EtunimiComparator.cpp"

int main()
{

  std::list<Matkakortti> kortit {};

  Matkakortti kortti1 {"Raimo", to_string(4)};
  Matkakortti kortti2 {"Aapo", to_string(5)};
  Matkakortti kortti3 {"Yrjö", to_string(3)};
  Matkakortti kortti4 {"Jorma", to_string(2)};
  // Matkakortti kortti5 {"Satu", to_string(6)};
  // Matkakortti kortti6 {"Pirkko", to_string(9)};
  // Matkakortti kortti7 {"Heikki", to_string(7)};
  // Matkakortti kortti8 {"Liisa", to_string(8)};
  // Matkakortti kortti9 {"Alma", to_string(1)};
  // Matkakortti kortti10 {"Sebastian", to_string(10)};

  // kortit.push_back(kortti5);
  // kortit.push_back(kortti8);
  kortit.push_back(kortti3);
  // kortit.push_back(kortti6);
  // kortit.push_back(kortti9);
  kortit.push_back(kortti2);
  kortit.push_back(kortti1);
  kortit.push_back(kortti4);
  // kortit.push_back(kortti10);
  // kortit.push_back(kortti7);

  std::cout << "Epäjärjestyksessä olevat kortit :\n";
  for(auto kortti : kortit) {
    kortti.tulostaKortinTiedot();
  }

  std::cout << "Järjestetään kortit matkustajanumeron perusteella:\n";
  kortit.sort();

  for (auto kortti : kortit) {
    kortti.tulostaKortinTiedot();
  }

  std::cout << "Järjestetään kortit sukunimen perusteella:\n";
  kortit.sort(SukuNimiComparator());

  for (auto kortti : kortit) {
    kortti.tulostaKortinTiedot();
  }

  std::cout << "Järjestetään kortit saldon ja etunimen perusteella:\n";
  kortit.sort(EtuNimiJaSaldoComparator());

  for (auto kortti : kortit) {
    kortti.tulostaKortinTiedot();
  }

  return 0;
}
