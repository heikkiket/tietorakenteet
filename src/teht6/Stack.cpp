#include "Stack.h"

Stack::Stack() {
  list = std::list<std::string>{};
  std::cout << "[Pino luotu]\n";
}

Stack::~Stack() {
  std::cout << "Pino tuhottu\n";
}

int Stack::getSize() {
  return list.size();
}

void Stack::push(std::string str) {
  list.push_front(str);
}

std::string Stack::pop() {
  std::string str = "";
  if (!list.empty()) {
    str = list.front();
    list.pop_front();
  }

  return str;
}

void Stack::printStack() {
  std::cout << "Tulostan pinon: " << "\n";

  for(std::string node : list) {
    std::cout << "  " << node << "\n";
  }
}
