#include <iostream>
#include "BinaryTree.h"


int main(int argc, char* argv[])
{
  BinaryTree *current = new BinaryTree();
  current->add("d");
  current->add("c");
  current->add("b");
  current->add("a");

  current->add("f");
  current->add("e");

  current->add("o");
  current->add("p");
  current->add("h");
  current->add("j");
  current->add("k");
  current->add("i");

  bool showHeights = true;
  std::cout << "Tulostetaan puu esijärjestyksessä:" << std::endl
            << current->PreOrder(showHeights) << std::endl;

  if(current->search("c")) {
    std::cout << "Arvo 'c' löytyi puusta.\n";
  }

  if (!current->search("z")) {
    std::cout << "Arvoa 'z' ei löytynyt puusta.\n";
  }

  if(current->inOrder())
    std::cout << "Puu on järjestyksessä.\n";
  else
    std::cout << "Puu ei ole järjestyksessä.\n";

  BinaryTree tree2 {};
  tree2.add("a");
  tree2.add("b");
  tree2.add("c");

  if(tree2.inOrder())
    std::cout << "Puu on järjestyksessä.\n";
  else
    std::cout << "Puu ei ole järjestyksessä.\n";

  return 0;
}
