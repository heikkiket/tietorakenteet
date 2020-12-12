#include <gtest/gtest.h>
#include "BinaryTree.h"

class testBinaryTree : public ::testing::Test {
protected:
  BinaryTree myTree{};
};

TEST_F(testBinaryTree, isEmpty) {
  ASSERT_TRUE(myTree.isEmpty());
}

TEST_F(testBinaryTree, isNotEmpty)
{
  BinaryTree tree2 {"foo"};
  ASSERT_FALSE(tree2.isEmpty());
}

TEST_F(testBinaryTree, addValue)
{
  myTree.add("foo");
  ASSERT_FALSE(myTree.isEmpty());
}

TEST_F(testBinaryTree, add_smaller_value)
{
  myTree.add("c");
  ASSERT_EQ("c", myTree.PreOrder());

  myTree.add("b");
  ASSERT_EQ("c,b", myTree.PreOrder());

  myTree.add("a");
  ASSERT_EQ("c,b,a", myTree.PreOrder());
}

TEST_F(testBinaryTree, add_bigger_value)
{
  myTree.add("a");
  myTree.add("b");

  ASSERT_EQ("a,b", myTree.PreOrder());

  myTree.add("c");
  ASSERT_EQ("a,b,c", myTree.PreOrder());
}

TEST_F(testBinaryTree, search_empty_tree)
{
  ASSERT_FALSE(myTree.search("a"));
}

TEST_F(testBinaryTree, search_root)
{
  myTree.add("a");
  ASSERT_TRUE(myTree.search("a"));
  ASSERT_FALSE(myTree.search("b"));
}

TEST_F(testBinaryTree, search_left_child) {
  myTree.add("d");
  myTree.add("c");
  ASSERT_TRUE(myTree.search("c"));
  ASSERT_FALSE(myTree.search("b"));

  myTree.add("b");
  ASSERT_TRUE(myTree.search("b"));

  ASSERT_FALSE(myTree.search("a"));
}

TEST_F(testBinaryTree, search_right_child)
{
  myTree.add("a");
  myTree.add("b");
  ASSERT_TRUE(myTree.search("b"));
  ASSERT_FALSE(myTree.search("c"));

  myTree.add("c");
  ASSERT_TRUE(myTree.search("c"));

  ASSERT_FALSE(myTree.search("d"));
}
