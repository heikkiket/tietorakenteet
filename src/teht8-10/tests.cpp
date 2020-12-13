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

TEST_F(testBinaryTree, remove_from_empty_tree)
{
  ASSERT_FALSE(myTree.remove("a"));
}

TEST_F(testBinaryTree, remove_root_node) {
  myTree.add("a");
  ASSERT_TRUE(myTree.remove("a"));
  ASSERT_FALSE(myTree.search("a"));
}

TEST_F(testBinaryTree, remove_leaf) {
  myTree.add("b");
  myTree.add("a");
  ASSERT_TRUE(myTree.remove("a"));
  ASSERT_FALSE(myTree.search("a"));
}

TEST_F(testBinaryTree, remove_leaf_with_one_children) {
  myTree.add("c");
  myTree.add("b");
  myTree.add("a");
  ASSERT_TRUE(myTree.remove("b"));
  ASSERT_FALSE(myTree.search("b"));
  ASSERT_TRUE(myTree.search("a"));

  myTree.add("d");
  myTree.add("e");
  ASSERT_TRUE(myTree.remove("d"));
  ASSERT_FALSE(myTree.search("d"));
  ASSERT_TRUE(myTree.search("e"));
}

/*  This test checks that reference to the leaf
    is removed from parent */
TEST_F(testBinaryTree, remove_parent_reference)
{
  myTree.add("a");
  myTree.add("c");
  myTree.add("b");
  myTree.add("d");
  ASSERT_EQ("a,c,b,d", myTree.PreOrder());

  myTree.remove("b");
  ASSERT_FALSE(myTree.search("b"));
  ASSERT_EQ("a,c,d", myTree.PreOrder());
}

TEST_F(testBinaryTree, search_leftmost)
{
  myTree.add("c");
  myTree.add("b");
  myTree.add("a");

  ASSERT_EQ("a", myTree.returnLeftmost());
}

TEST_F(testBinaryTree, remove_leaf_with_two_children)
{
  myTree.add("a");
  myTree.add("c");
  myTree.add("b");
  myTree.add("d");
  ASSERT_EQ("a,c,b,d", myTree.PreOrder());

  myTree.remove("c");
  ASSERT_FALSE(myTree.search("c"));
  ASSERT_EQ("a,b,d", myTree.PreOrder());
}

TEST_F(testBinaryTree, initial_height_0)
{
  ASSERT_EQ(myTree.height(), -1);
}

TEST_F(testBinaryTree, root_node_height_1)
{
  myTree.add("a");
  ASSERT_EQ(myTree.height(), 0);
}

TEST_F(testBinaryTree, left_branch_height)
{
  myTree.add("c");
  myTree.add("b");
  ASSERT_EQ(myTree.height(), 1);
}

TEST_F(testBinaryTree, higher_branch_height)
{
  myTree.add("b");
  myTree.add("a");
  myTree.add("c");
  myTree.add("d");

  ASSERT_EQ(myTree.height(), 2);
}

TEST_F(testBinaryTree, show_heights)
{
  myTree.add("b");
  myTree.add("a");
  myTree.add("c");
  myTree.add("d");

  bool showHeights = true;
  ASSERT_EQ(myTree.PreOrder(showHeights), "b[2],a[0],c[1],d[0]");
}
