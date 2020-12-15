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

  string exp = "5 2 * 3 + ";
  calc.add(exp);
  cout << exp << " Tulos: " << calc.calculate() << endl;;

  exp;
  exp = "5 2 3 + *";
  calc.add(exp);
  cout << exp << " Tulos: " << calc.calculate() << endl;

  return 0;
}

