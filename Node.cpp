#include "Node.h"

Node::Node() {
  std::cout << "Node luotu\n";
}

Node::Node(std::string str, Node* next) {
  std::cout << "[Node luotu sisällöllä]" << str << "\n";
  content = str;
  this->next = next;
}

Node::~Node() {
  if( next != NULL ){
    delete next;
  }

  std::cout << "[Node tuhottu]\n";
}

std::string Node::getContent() {
  return content;
}

Node* Node::getNext() {
  return next;
}
