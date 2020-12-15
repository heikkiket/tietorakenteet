#include <iostream>
#include <sstream>
#include <vector>

#include "Calc.h"

using namespace std;

int main() {
  std::string str = " 1 2 +";

  Calc calc {};
  auto arr = calc.tokenize(str);

  for (auto tok : arr) {
    std::cout << tok << std::endl;
  }

  // calc.add("1 2 + 2 + 3 + 4");
  calc.add("5 2 3 + *");
  calc.calculate();
  return 0;
}

