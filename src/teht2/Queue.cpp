#include <iostream>

#include "Queue.h"

Queue::Queue() {
  std::cout << "[Jono luotu]\n";
}

Queue::~Queue() {
  delete first;

  std::cout << "[Jono tuhottu]\n";
}

void Queue::enqueue(std::string str) {
  Node* n = new Node(str, first);
  size++;
  first = n;

  if(last == NULL)
    last = n;
}

std::string Queue::dequeue() {
  if(size == 0)
    return "";

  if(size == 1) {
    std::string str = first->getContent();
    delete first;
    first = NULL;
    last = NULL;
    return str;
  }

  Node *node = first;

  while (node->getNext() != last) {
    node = node->getNext();
  }

  Node *toBeRemoved = last;
  last = node;
  std::string str = toBeRemoved->getContent();
  delete toBeRemoved;
  last->setNext(NULL);

  size--;

  return str;
}

void Queue::printQueue() {
  std::cout << "Tulostan jonon: "
            << "\n";

  int i = size;
  Node *node = first;

  while (i > 0) {
    if (node != NULL) {
      std::cout << "  " << node->getContent() << "\n";
    }
    node = node->getNext();
    i--;
  }
}
