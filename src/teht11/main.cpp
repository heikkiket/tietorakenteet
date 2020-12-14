#include <iostream>
#include "SortedArray.h"

using namespace std;

int main()
{
  SortedArray myArray{};
  auto nameList = {"Aapo",    "Eero", "Juhani", "Lauri",
                   "Simeoni", "Timo", "Tuomas"};
  for (auto name : nameList) {
    myArray.add(name);
  }

  myArray.printContents();
  return 0;
}
