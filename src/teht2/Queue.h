#ifndef QUEUE_H
#define QUEUE_H

#include <string>

#include "../teht1/Node.h"

class Queue {
private:
  Node* first = NULL;
  Node* last = NULL;
  int size = 0;
public:
  Queue();
  virtual ~Queue();
  void enqueue(std::string str);
  std::string dequeue();
  void printQueue();

};

#endif /* QUEUE_H */
