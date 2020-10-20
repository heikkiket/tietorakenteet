#include "Stack.h"

Stack::Stack() {
  std::cout << "Pino luotu\n";
}

Stack::~Stack() {
  delete top;
  std::cout << "Pino tuhottu\n";
}

int Stack::getSize() {
  return size;
}

void Stack::push(std::string str) {

  Node* n = new Node(str, top);
  size++;
  top = n;
}

std::string Stack::pop() {

  std::string content = top->getContent();
  top = top->getNext();
  size--;
  return content;
}

void Stack::printStack() {
  std::cout << "Tulostan pinon: " << "\n";

  int i = size;
  Node* node = top;

  while(i > 0) {
    if( node != NULL ){
      std::cout << "  " << node->getContent() << "\n";
    }
    node = node->getNext();
    i--;
  }
}
