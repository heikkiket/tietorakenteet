#include <iostream>
#include "BinaryTree.h"


int main(int argc, char* argv[])
{
        BinaryTree *current, *left, *right;
        right = new BinaryTree("d");
        right = new BinaryTree("c", NULL, right);
        left = new BinaryTree("b");
        current = new BinaryTree("a", left, right);

        current->add("f");
        current->add("e");

        std::cout << "Tulostetaan puu esijärjestyksessä:" << std::endl
                  << current->PreOrder() << std::endl;

        if(current->search("c")) {
          std::cout << "Arvo 'c' löytyi puusta.\n";
        }
        return 0;
}
