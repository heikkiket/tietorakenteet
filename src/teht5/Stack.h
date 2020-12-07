#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 5

#include <iostream>
#include <iterator>

class Stack {
private:
  int size = 0;
  int stack[MAX_SIZE];
  bool debug = false;
  bool empty = true;

  bool isFull();

  class iterator : public std::iterator<std::output_iterator_tag, int>
  {
    public:
    explicit iterator(Stack & stackParam, int index);

      int operator*() const;
      iterator & operator++();
    iterator & operator++(int);
      bool operator!=(const iterator &) const;
  private:
    Stack &myStack;
    int currentIndex;
  };

public:
  Stack();
  Stack(int size);
  virtual ~Stack();

  int pop();
  int push(int number);
  int getSize();
  void printStack();
  void enableDebug();
  bool isEmpty();

  iterator begin();
  iterator end();
};

#endif /* STACK_H */
