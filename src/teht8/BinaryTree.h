#ifndef BinaryTreeH
#define BinaryTreeH

#include <string>

class Node;

class BinaryTree
{
private:
        Node *root;

public:
  BinaryTree();
  BinaryTree(std::string value);
  BinaryTree (std::string value, BinaryTree *left, BinaryTree *right);
  std::string PreOrder();
  void add(std::string value);
  bool isEmpty();
  bool search(std::string value);
};

#endif
