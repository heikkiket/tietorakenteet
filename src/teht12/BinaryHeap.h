#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#define MAX_SIZE 10

#include <exception>
#include <string>
#include <iostream>

class BinaryHeap
{
private:
  int firstEl = 1;
  int size = firstEl;
  int elements[MAX_SIZE];

  bool isEmpty();
  int smallerChild(int index);
  void minHeapify(int index);
  void swap(int a, int b);
public :
  BinaryHeap();
  virtual ~BinaryHeap();
  void insert(int n);
  int deleteMin();
  int getSize();
  std::string printArray();

  class EmptyHeapException: public std::exception {} EmptyHeapException;
};

#endif /* BINARYHEAP_H */
