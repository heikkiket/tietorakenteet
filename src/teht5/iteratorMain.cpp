#include <iostream>

#include "Stack.h"


int main(int argc, char *argv[])
{

  Stack testStack = Stack();
  testStack.push(1);
  testStack.push(2);
  testStack.push(3);

  std::cout << "Pinon koko on " << testStack.getSize() << "\n";

  std::cout << "Tulostetaan pino iteraattorilla:\n";
  for(auto node : testStack) {
    std::cout << node << std::endl;
  }

  return 0;
}
