
#ifndef NodeH
#define NodeH

#include <string>

class BinaryTree;

class Node
{
private:
  std::string data;
  BinaryTree *left;
  BinaryTree *right;
  BinaryTree *parent;
  friend class BinaryTree;
public:
  Node(std::string value, BinaryTree *parent);
  Node(std::string value, BinaryTree *left, BinaryTree *right);
  ~Node();

};

#endif
