#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
private:
  std::string content;
  Node* next;

public:
  Node();
  Node(std::string str, Node* next);
  Node(std::string str) : Node(str, NULL){};

  std::string getContent();
  Node* getNext();
  void setNext(Node *n);
  virtual ~Node();
};

#endif /* NODE_H */
