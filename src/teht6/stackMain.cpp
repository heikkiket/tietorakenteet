#include <iostream>

#include "Stack.h"

int main()
{
  Stack testStack = Stack();
  std::cout << "Pinon koko on " << testStack.getSize() << "\n";
  testStack.push("Tänään");
  testStack.push("on");
  testStack.push("maanantai");
  std::cout << "Pinon koko on " << testStack.getSize() << "\n";
  testStack.printStack();
  std::string tulos = testStack.pop();
  std::cout << "Popattiin pino, ja tulos on " << tulos << "\n";
  testStack.printStack();
}
