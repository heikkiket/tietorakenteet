#ifndef BinaryTreeH
#define BinaryTreeH

#include <string>

class Node;

class BinaryTree
{
private:
  Node *root;

  BinaryTree *searchValue(std::string value);
  void removeValue();
  void replace(BinaryTree *newTree);
  BinaryTree *searchLeftmost();

public:
  BinaryTree();
  ~BinaryTree();
  BinaryTree(std::string value);
  BinaryTree(std::string value, BinaryTree *parent);
  BinaryTree (std::string value, BinaryTree *left, BinaryTree *right);

  void removeChild(Node *child);

  std::string PreOrder();
  void add(std::string value);
  bool isEmpty();
  bool search(std::string value);
  bool remove(std::string value);
  std::string returnLeftmost();
};

#endif
