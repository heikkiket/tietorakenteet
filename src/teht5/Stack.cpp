#include <iostream>
#include "Stack.h"

Stack::Stack() {
  if(this->debug)
    std::cout << "Stack created";
}

Stack::Stack(int size) : Stack{} {
}

Stack::~Stack() {
  if (this->debug)
    std::cout << "Stack destroyed";
}

int Stack::push(int number) {
  if (isFull()) {
    if(debug)
      std::cout << "Can't push to full stack";
    return -1;
  }

  this->stack[size++] = number;
  return 0;
}

int Stack::pop()
{
  if(isEmpty())
    return -1;

  return this->stack[--size];
}

bool Stack::isEmpty() {
  return size == 0;
}

bool Stack::isFull() {
  return size == MAX_SIZE;
}

int Stack::getSize()
{
  return size;
}

Stack::iterator Stack::begin() {

  return Stack::iterator(*this, 0);
}

Stack::iterator Stack::end() {

  return Stack::iterator(*this, size);
}

Stack::iterator::iterator(Stack &ContainerParam, int index) : myStack(ContainerParam),
                                                              currentIndex(index){}

Stack::iterator & Stack::iterator::operator++()
{
   currentIndex++;
   return *this;
}

Stack::iterator & Stack::iterator::operator++(int)
{
  return ++(*this);
}

bool Stack::iterator::operator!=(const iterator &rhs) const {
  return currentIndex != rhs.currentIndex;
}

int Stack::iterator::operator*() const
{
  return myStack.stack[currentIndex];
}
