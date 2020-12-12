#include <iostream>
#include <string>
#include <sstream>

#include "BinaryTree.h"
#include "Node.h"

BinaryTree::BinaryTree()
{
  root = NULL;
}

BinaryTree::BinaryTree(std::string value)
{
  root = new Node(value);
}

BinaryTree::BinaryTree (std::string value, BinaryTree *left, BinaryTree *right)
{
  root = new Node(value, left, right);
}

std::string BinaryTree::PreOrder()
{
  std::string str {""};

  if (root)
    {
      str = root->data;
      if (root->left) // pääseekö vasemmalle?
        str = str + "," + root->left->PreOrder();
      if (root->right)
        str = str + "," + root->right->PreOrder();
    }

  return str;
}

void BinaryTree::add(std::string value)
{
  if(isEmpty()) {
    root = new Node(value);
  } else if(root->data > value) {
    //vasen
    if (root->left) { // vasemmalle pääsee
      root->left->add(value);
    } else {
      root->left = new BinaryTree(value);
    }
  } else {
    //oikea
    if(root->right) { //oikealle pääsee
      root->right->add(value);
    } else {
      root->right = new BinaryTree(value);
    }

  }
}

bool BinaryTree::isEmpty()
{
  return root == NULL;
}

bool BinaryTree::search(std::string value)
{
  if(isEmpty()) {
    return false;
  } else if(root->data == value) {
    return true;
  } else if(root->data > value){
    //vasen
    if(root->left) {
      return root->left->search(value);
    }
    return false;
  } else {
    //oikea
    if(root->right) {
      return root->right->search(value);
    }
    return false;
  }
}
