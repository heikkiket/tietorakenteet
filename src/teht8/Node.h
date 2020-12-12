
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
  friend class BinaryTree;
public:
  Node(std::string value);
  Node (std::string value, BinaryTree *left, BinaryTree *right);

};

#endif
