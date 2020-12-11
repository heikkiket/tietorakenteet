#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <list>

class Stack {
private:
  std::list<std::string> list;

public:
  Stack();
  virtual ~Stack();

  std::string pop();
  void push(std::string str);
  int getSize();
  void printStack();
};

#endif /* STACK_H */
