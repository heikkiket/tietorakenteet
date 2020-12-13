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
  root = new Node(value, NULL);
}

BinaryTree::BinaryTree(std::string value, BinaryTree *parent)
{
  root = new Node(value, parent);
}

BinaryTree::BinaryTree (std::string value, BinaryTree *left, BinaryTree *right)
{
  root = new Node(value, left, right);
}

BinaryTree::~BinaryTree()
{
  delete root;
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
    root = new Node(value, NULL);
  } else if(root->data > value) {
    //vasen
    if (root->left) { // vasemmalle pääsee
      root->left->add(value);
    } else {
      root->left = new BinaryTree(value, this);
    }
  } else {
    //oikea
    if(root->right) { //oikealle pääsee
      root->right->add(value);
    } else {
      root->right = new BinaryTree(value, this);
    }

  }
}

bool BinaryTree::isEmpty()
{
  return root == NULL;
}

bool BinaryTree::search(std::string value)
{
  if(searchValue(value) == NULL) {
    return false;
  } else {
    return true;
  }
}

bool BinaryTree::remove(std::string value) {
  BinaryTree * found = searchValue(value);
  if (found != NULL) {
    if(found->root->left && found->root->right) {
      BinaryTree *leftmost = found->searchLeftmost();
      found->root->data = leftmost->root->data;
      delete leftmost;
    } else if(found->root->left) {
      found->replace(found->root->left);
    } else if(found->root->right) {
      found->replace(found->root->right);
    } else if (found == this){ // we are at the root node
      delete root;
      root = NULL;
    } else {
      delete found;
    }
    return true;
  }
  else {
    return false;
  }
}

BinaryTree *BinaryTree::searchValue(std::string value)
{
  if(isEmpty()) {
    return NULL;
  } else if(root->data == value) {
    return this;
  } else if(root->data > value) {
    //vasen
    if(root->left) {
      return root->left->searchValue(value);
    }
    return NULL;
  } else {
    //oikea
    if(root->right) {
      return root->right->searchValue(value);
    }
    return NULL;
  }
}

BinaryTree *BinaryTree::searchLeftmost()
{
  if(root->left) {
    return root->left->searchLeftmost();
  } else {
    return this;
  }
}

std::string BinaryTree::returnLeftmost()
{
  BinaryTree *t = searchLeftmost();
  return t->root->data;
}

void BinaryTree::removeValue()
{
  delete root;
  root = NULL;
}

void BinaryTree::replace(BinaryTree *newTree)
{
  *this = *newTree;
}

void BinaryTree::removeChild(Node *child)
{
  if (root->left) {
    if (root->left->root == child) {
      root->left = NULL;
    }
  }

  if (root->right) {
    if (root->right && root->right->root == child) {
      root->right = NULL;
    }
  }

}
