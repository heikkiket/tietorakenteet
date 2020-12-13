#include <string.h>
#include <iostream>

#include "Node.h"
#include "BinaryTree.h"

Node::Node(std::string value, BinaryTree * parent)
{
  data = value;
  left = right = NULL;
  this->parent = parent;
}

Node::Node(std::string value, BinaryTree *left, BinaryTree *right)
{
  data = value;
  this->left = left;
  this->right = right;
  this->parent = NULL;
}

Node::~Node()
{
  if (parent != NULL)
    parent->removeChild(this);


  if(left)
    delete left;

  if(right)
    delete right;
}

