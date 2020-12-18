#include <iostream>

#define SIZE 1000000

#include "../teht8-10/BinaryTree.h"
#include "randomString.cpp"


int main()
{
  BinaryTree setTree;

  for(int i = 0; i < SIZE; i++) {
    setTree.add(random_string(30));
  }

  for (int i = 0; i < SIZE; i++) {
    setTree.search(std::to_string(i));
  }

  return 0;
}
