#include <gtest/gtest.h>
#include "Calc.h"

class testCalc : public ::testing::Test {
protected:
  Calc myCalc {};
public:
  testCalc() {

  }
};

TEST_F(testCalc, tokenize) {
  std::deque<std::string> arr = myCalc.tokenize("1 2 +");
  ASSERT_EQ(arr.size(), 3);
  ASSERT_EQ(arr.front(), "1");
  ASSERT_EQ(arr.back(), "+");
}

TEST_F(testCalc, add_expression)
{
  myCalc.add("1 2 +");
}

TEST_F(testCalc, add_empty_fails)
{
  ASSERT_ANY_THROW(myCalc.add(""));
}

TEST_F(testCalc, weird_fails)
{
  ASSERT_ANY_THROW(myCalc.add("1 + 2 + 3 + 4"));
}

TEST_F(testCalc, returns_static_expression)
{
  myCalc.add("1");
  ASSERT_EQ(myCalc.calculate(), 1.0);

  myCalc.add("2");
  ASSERT_EQ(myCalc.calculate(), 2.0);
}

TEST_F(testCalc, doesnt_allow_sole_operator)
{
  ASSERT_ANY_THROW(myCalc.add("+"));
  ASSERT_ANY_THROW(myCalc.add("-"));
  ASSERT_ANY_THROW(myCalc.add("*"));
  ASSERT_ANY_THROW(myCalc.add("/"));

  ASSERT_NO_THROW(myCalc.add("1"));
}

TEST_F(testCalc, amount_of_operands_and_operators_match)
{
  ASSERT_NO_THROW(myCalc.add("1 2 +"));

  ASSERT_ANY_THROW(myCalc.add("1 2 + -"));

  ASSERT_ANY_THROW(myCalc.add("1 2 3 -"));
}

TEST_F(testCalc, simple_sum)
{
  myCalc.add("1 2 +");

  ASSERT_EQ(myCalc.calculate(), 3);
}

TEST_F(testCalc, simple_multiply) {
  myCalc.add("3 2 *");

  ASSERT_EQ(myCalc.calculate(), 6);
}

TEST_F(testCalc, simple_dimin) {
  myCalc.add("9 7 -");

  ASSERT_EQ(myCalc.calculate(), 2);
}

TEST_F(testCalc, simple_division) {
  myCalc.add("10 2 /");

  ASSERT_EQ(myCalc.calculate(), 5);
}

TEST_F(testCalc, postfix_expr)
{
  myCalc.add("2 3 + 5 *");

  ASSERT_EQ(myCalc.calculate(), 25);
}

TEST_F(testCalc, more_complex_postfix_expr) {
  myCalc.add("5 2 3 + *");

  ASSERT_EQ(myCalc.calculate(), 25);
}
