#ifndef STACK_H
#define STACK_H

#include <iostream>

#include "Node.h"

class Stack {
private:
  Node* top = NULL;
  int size = 0;

public:
  Stack();
  virtual ~Stack();

  std::string pop();
  void push(std::string str);
  int getSize();
  void printStack();
};

#endif /* STACK_H */
