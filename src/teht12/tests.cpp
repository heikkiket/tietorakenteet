#include <gtest/gtest.h>
#include "BinaryHeap.h"
#include <iostream>

class testBinaryHeap : public ::testing::Test {
protected:
  BinaryHeap myHeap{};
};

TEST_F(testBinaryHeap, insert_one_remove_one) {
  myHeap.insert(1);
  ASSERT_EQ(myHeap.deleteMin(), 1);
}

TEST_F(testBinaryHeap, two_insertions_height_is_two)
{
  myHeap.insert(1);
  myHeap.insert(2);

  ASSERT_EQ(myHeap.getSize(), 2);
}

TEST_F(testBinaryHeap, delete_min_empty_heap)
{
  ASSERT_ANY_THROW(myHeap.deleteMin());
}

TEST_F(testBinaryHeap, two_inserts_two_delete_empty_heap)
{
  myHeap.insert(1);
  myHeap.insert(2);

  myHeap.deleteMin();
  myHeap.deleteMin();

  ASSERT_ANY_THROW(myHeap.deleteMin());
}

TEST_F(testBinaryHeap, smaller_is_returned)
{
  myHeap.insert(3);
  myHeap.insert(4);

  ASSERT_EQ(myHeap.deleteMin(), 3);
}

TEST_F(testBinaryHeap, two_inserts_two_returned)
{
  myHeap.insert(1);
  myHeap.insert(2);
  ASSERT_EQ(myHeap.deleteMin(), 1);
  ASSERT_EQ(myHeap.deleteMin(), 2);
}

TEST_F(testBinaryHeap, add_two_bigger_first)
{
  myHeap.insert(77);
  myHeap.insert(66);

  ASSERT_EQ(myHeap.deleteMin(), 66);
}

TEST_F(testBinaryHeap, add_three_biggest_first)
{
  myHeap.insert(77);
  myHeap.insert(66);
  myHeap.insert(55);

  ASSERT_EQ(myHeap.deleteMin(), 55);
}

TEST_F(testBinaryHeap, add_three_delete_three_in_right_order) {
  myHeap.insert(77);
  myHeap.insert(66);
  myHeap.insert(55);

  ASSERT_EQ(myHeap.deleteMin(), 55);
  ASSERT_EQ(myHeap.deleteMin(), 66);
  ASSERT_EQ(myHeap.deleteMin(), 77);
}

TEST_F(testBinaryHeap, add_unordered_delete_smallest)
{

  myHeap.insert(77);
  myHeap.insert(22);
  myHeap.insert(55);
  myHeap.insert(66);
  myHeap.insert(33);

  ASSERT_EQ(myHeap.deleteMin(), 22);
  ASSERT_EQ(myHeap.deleteMin(), 33);
  ASSERT_EQ(myHeap.deleteMin(), 55);
  ASSERT_EQ(myHeap.deleteMin(), 66);
  ASSERT_EQ(myHeap.deleteMin(), 77);

}
