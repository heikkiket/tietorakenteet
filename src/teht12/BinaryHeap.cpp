
#include "BinaryHeap.h"

BinaryHeap::BinaryHeap() {
  elements[0] = 0; // Heap begins from 1
}
BinaryHeap::~BinaryHeap() {}

void BinaryHeap::insert(int n) {
  elements[size] = n;

  if (isEmpty()) {
    size++;
    return;
  }

  int index = size;
  while(index > firstEl && elements[index/2] > elements[index]) {
    swap(index, index/2);

    index = index/2;
  }

  size++;
}

int BinaryHeap::deleteMin()
{
  if(isEmpty())
    throw EmptyHeapException;
  else {

    int index = firstEl;
    int ret = elements[index];
    elements[index] = elements[getSize()];

    minHeapify(index);

    size--;
    return ret;
  }

}

bool BinaryHeap::isEmpty()
{
  return size == 1;
}

int BinaryHeap::getSize()
{
  return size - 1;
}

std::string BinaryHeap::printArray()
{
  std::string str;
  for(int i = firstEl; i < size; i++) {
    str = str + "[" + std::to_string(elements[i]) + "] ";
  }
  str = str + '\n';

  for (int i = firstEl; i < size; i++) {
    str = str + " " + std::to_string(i) + "  ";
  }

  str = str + '\n';
  return str;
}

void BinaryHeap::minHeapify(int index)
{
  int left = 2*index;
  int right = 2 * index + 1;
  int smallest = index;

  if(left <= getSize() && elements[left] < elements[smallest])
    smallest = left;

  if(right <= getSize() && elements[right] < elements[smallest])
    smallest = right;

  if(smallest != index) {
    swap(index, smallest);
    minHeapify(smallest);
  }
}

void BinaryHeap::swap(int a, int b)
{
  int tmp = elements[a];
  elements[a] = elements[b];
  elements[b] = tmp;
}
