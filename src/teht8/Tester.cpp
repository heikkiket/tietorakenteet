#include <iostream>
#include "BinaryTree.h"


int main(int argc, char* argv[])
{
        BinaryTree *current, *left, *right;
        right = new BinaryTree("d");
        right = new BinaryTree("c", NULL, right);
        left = new BinaryTree("b");
        current = new BinaryTree("a", left, right);
        current->PreOrder();
        return 0;
}
