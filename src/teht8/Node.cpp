#include <string.h>

#include "Node.h"
#include "BinaryTree.h"

Node::Node(std::string value)
{
  data = value;
  left = right = NULL;
}

Node::Node(std::string value, BinaryTree *left, BinaryTree *right)
{
  data = value;
  this->left = left;
  this->right = right;
}

