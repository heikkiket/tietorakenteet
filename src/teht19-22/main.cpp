#include <iostream>
#include <ranges>
#include <list>
#include <string>

using namespace std;

#include "SukuNimiComparator.cpp"
#include "matkakortti.h"
#include "EtunimiComparator.cpp"

int main()
{

  std::list<Matkakortti> kortit {};

  Matkakortti kortti1 {"Raimo", "Karttunen"};
  Matkakortti kortti2 {"Aapo", "Kekkonen"};
  Matkakortti kortti3 {"Yrjö", "Reijakainen"};
  Matkakortti kortti4 {"Jorma", "Aalto"};

  kortit.push_back(kortti3);
  kortit.push_back(kortti2);
  kortit.push_back(kortti1);
  kortit.push_back(kortti4);

  std::cout << "Epäjärjestyksessä olevat kortit :\n";
  for(auto kortti : kortit) {
    kortti.tulostaKortinTiedot();
  }

  std::cout << "\n\nNäytetään vain henkilöt, joilla nimi on yli 4 merkkiä:\n";
  kortit.sort([](const Matkakortti &kortti1, const Matkakortti &kortti2) {
    return kortti1.sukunimi < kortti2.sukunimi;
  });

  for (auto kortti : kortit | std::views::filter(
                                                 [](const Matkakortti &kortti) {
                                                   return kortti.etunimi.length() > 4;
                                                 })
    )
    {
      kortti.tulostaKortinTiedot();
    }

  return 0;
}
