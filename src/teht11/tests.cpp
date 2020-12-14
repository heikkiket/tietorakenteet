#include <gtest/gtest.h>
#include "SortedArray.h"

class testSortedArray : public ::testing::Test {
protected:
  SortedArray myArray{};
public:
  testSortedArray()
  {
    auto nameList = {"Aapo", "Eero", "Juhani", "Lauri", "Simeoni", "Timo", "Tuomas"};
    for(auto name : nameList) { myArray.add(name); }
  }
};

class testArray : public ::testing::Test {
protected:
  SortedArray myEmptyArray{};
};

TEST_F(testSortedArray, search_middle) {
  ASSERT_EQ(myArray.search("Lauri"), 3);
  ASSERT_EQ(myArray.search("Mikko"), -1);
}

TEST_F(testSortedArray, search_even_array)
{
  myArray.add("Seppo");
  ASSERT_EQ(myArray.search("Lauri"), 3);
  ASSERT_EQ(myArray.search("Mikko"), -1);
}

TEST_F(testSortedArray, search_smaller_than_half) {
  ASSERT_EQ(myArray.search("Eero"), 1);
  ASSERT_EQ(myArray.search("Aake"), -1);
}

TEST_F(testSortedArray, search_bigger_than_half)
{
  ASSERT_EQ(myArray.search("Timo"), 5);
  ASSERT_EQ(myArray.search("Yrjö"), -1);
}

TEST_F(testArray, add_to_empty)
{
  myEmptyArray.add("Pekka");
  ASSERT_EQ(myEmptyArray.search("Pekka"), 0);
}

TEST_F(testArray, add_to_end)
{
  myEmptyArray.add("Pekka");
  myEmptyArray.add("Raimo");
  ASSERT_EQ(myEmptyArray.search("Pekka"), 0);
  ASSERT_EQ(myEmptyArray.search("Raimo"), 1);
}

TEST_F(testArray, add_to_second_to_last)
{
  myEmptyArray.add("Pekka");
  myEmptyArray.add("Satu");
  myEmptyArray.add("Raimo");

  ASSERT_EQ(myEmptyArray.search("Raimo"), 1);
  ASSERT_EQ(myEmptyArray.search("Satu"), 2);
}

TEST_F(testArray, add_to_start)
{
  myEmptyArray.add("Pekka");
  myEmptyArray.add("Aaro");

  ASSERT_EQ(myEmptyArray.search("Aaro"), 0);
  ASSERT_EQ(myEmptyArray.search("Pekka"), 1);
}

TEST_F(testArray, add_to_middle)
{
  myEmptyArray.add("Pekka");
  myEmptyArray.add("Raimo");
  myEmptyArray.add("Satu");
  myEmptyArray.add("Tero");

  myEmptyArray.add("Poke");

  ASSERT_EQ(myEmptyArray.search("Poke"), 1);
  ASSERT_EQ(myEmptyArray.search("Satu"), 3);
  ASSERT_EQ(myEmptyArray.search("Tero"), 4);

}
