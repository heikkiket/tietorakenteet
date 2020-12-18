#include <iostream>
#include <string>
#include <sstream>

#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
}

BinaryTree::BinaryTree(std::string value)
{
  binarytree.insert(value);
}

BinaryTree::BinaryTree(std::string value, BinaryTree *parent)
{
}

BinaryTree::BinaryTree (std::string value, BinaryTree *left, BinaryTree *right)
{
}

BinaryTree::~BinaryTree()
{
}

std::string BinaryTree::PreOrder()
{
  return "";
}

std::string BinaryTree::PreOrder(bool showHeights) {
  // std::string str {""};

  // if (!binarytree.empty())
  //   {
  //     str = binarytree.

  //     if (showHeights) {
  //       str = str + "[" + std::to_string(height()) + "]";
  //     }

  //     if (root->left) // pääseekö vasemmalle?
  //       str = str + "," + root->left->PreOrder(showHeights);

  //     if (root->right)
  //       str = str + "," + root->right->PreOrder(showHeights);

  // }

  // return str;
  return "";
}

bool BinaryTree::inOrder()
{
  auto it = binarytree.begin();
  auto prev = it->data();
  it++;
  while(it != binarytree.end()) {
    if(it->data() < prev)
      return false;
    it++;
  }
  return true;
}

void BinaryTree::add(std::string value)
{
  binarytree.insert(value);
}

bool BinaryTree::isEmpty()
{
  return binarytree.empty();
}

bool BinaryTree::search(std::string value)
{
  return binarytree.count(value);
}

bool BinaryTree::remove(std::string value) {
  auto node = binarytree.extract(value);
  if(node.empty())
    return false;
  else return true;
}


int BinaryTree::height()
{
  return 0;
}
