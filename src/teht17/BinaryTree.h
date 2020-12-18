#ifndef BinaryTreeH
#define BinaryTreeH

#include <string>
#include <set>

class Node;

class BinaryTree
{
private:
  std::set<std::string> binarytree;
public:
  BinaryTree();
  ~BinaryTree();
  BinaryTree(std::string value);
  BinaryTree(std::string value, BinaryTree *parent);
  BinaryTree (std::string value, BinaryTree *left, BinaryTree *right);

  void removeChild(Node *child);

  std::string PreOrder();
  std::string PreOrder(bool showHeights);
  void add(std::string value);
  bool isEmpty();
  bool inOrder();
  bool search(std::string value);
  bool remove(std::string value);
  std::string returnLeftmost();
  int height();
};

#endif
