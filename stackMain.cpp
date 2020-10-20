#include <iostream>

#include "Stack.h"

int main()
{
  Stack testStack = Stack();
  std::cout << "Pinon koko on " << testStack.getSize() << "\n";
  testStack.push("Testisisalto");
  testStack.push("Testi 2");
  testStack.push("Testi 3");
  std::cout << "Pinon koko on " << testStack.getSize() << "\n";
  testStack.printStack();
  // std::string tulos = testStack.pop();
  // std::cout << "Popattiin pino, ja tulos on " << tulos << "\n";
  // testStack.printStack();
}
