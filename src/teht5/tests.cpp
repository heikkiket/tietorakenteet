#include <gtest/gtest.h>
#include "Stack.h"

class myTestStack : public ::testing::Test {
protected:
  Stack myStack;
  Stack smallStack{5};
};

TEST_F(myTestStack, pop_empty_stack) {
  ASSERT_EQ((myStack.pop()),-1);
}

TEST_F(myTestStack, after_push_not_empty) {
  myStack.push(1);
  ASSERT_FALSE(myStack.isEmpty());
}

TEST_F(myTestStack, after_one_push_and_one_pop_is_empty) {
  myStack.push(1);
  myStack.pop();
  ASSERT_TRUE(myStack.isEmpty());
}

TEST_F(myTestStack, number_pushed_same_returned) {
  myStack.push(5);
  ASSERT_EQ(myStack.pop(), 5);

  myStack.push(4);
  ASSERT_EQ(myStack.pop(), 4);
}

TEST_F(myTestStack, two_pushes_one_pop_not_empty) {
  myStack.push(1);
  myStack.push(1);
  myStack.pop();
  ASSERT_FALSE(myStack.isEmpty());
}

TEST_F(myTestStack, cant_push_to_full_stack) {
  smallStack.push(1);
  smallStack.push(1);
  smallStack.push(1);
  smallStack.push(1);
  smallStack.push(1);
  ASSERT_EQ(smallStack.push(1), -1);
}

TEST_F(myTestStack, whats_pushed_gets_popped) {
  myStack.push(22);
  myStack.push(33);

  ASSERT_EQ(myStack.pop(), 33);
  ASSERT_EQ(myStack.pop(), 22);
}

TEST_F(myTestStack, iterator_iterates) {
  myStack.push(1);
  myStack.push(2);
  auto it = myStack.begin();
  ASSERT_EQ(*it, 1);
  it++;
  ASSERT_EQ(*it, 2);
}
