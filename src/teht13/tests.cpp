#include <gtest/gtest.h>
#include "HashTable.h"

class testHashTable : public ::testing::Test {
protected:
  HashTable myTbl{};
};

TEST_F(testHashTable, when_created_is_empty) {
  ASSERT_TRUE(myTbl.isEmpty());
}

TEST_F(testHashTable, hash_str_returns_asciicode)
{
  ASSERT_EQ(myTbl.hashStr("a"), 97);
  ASSERT_EQ(myTbl.hashStr("b"), 98);
  ASSERT_EQ(myTbl.hashStr("A"), 65);
}

TEST_F(testHashTable, hash_str_multiplies_chars)
{
  ASSERT_EQ(myTbl.hashStr("aa"), 97 * 1 + 97 * 2);
  ASSERT_EQ(myTbl.hashStr("AA"), 65 * 1 + 65 * 2);
}

TEST_F(testHashTable, table_has_max_size)
{
  ASSERT_EQ(myTbl.maxSize, 31);
}

TEST_F(testHashTable, hash_function_modulo_works)
{
  int maxSize {myTbl.maxSize};

  ASSERT_EQ(myTbl.hashCode("a"), 97 % maxSize);
  ASSERT_EQ(myTbl.hashCode("A"), 65 % maxSize);
}

TEST_F(testHashTable, adding_and_searching_works)
{
  myTbl.add("test");

  ASSERT_TRUE(myTbl.search("test"));
  ASSERT_FALSE(myTbl.search("asd"));
}

TEST_F(testHashTable, multiple_adds_first_can_be_searched)
{
  myTbl.add("test");
  myTbl.add("asd");

  ASSERT_TRUE(myTbl.search("test"));
}

TEST_F(testHashTable, key_collision_both_saved)
{
  myTbl.add("test");
  myTbl.add("joulupukki");

  ASSERT_TRUE(myTbl.search("test"));
  ASSERT_TRUE(myTbl.search("joulupukki"));
}

TEST_F(testHashTable, searching_empty_table_returns_false)
{
  ASSERT_FALSE(myTbl.search("foo"));
}

TEST_F(testHashTable, key_must_be_unique)
{
  ASSERT_NO_THROW(myTbl.add("test"));
  try {
    myTbl.add("test");
  } catch (const char *msg) {
    ASSERT_STREQ(msg, "duplicate key");
  }
}

TEST_F(testHashTable, cant_save_to_full_table)
{
  for(int i = 0; i < 31; i++) {
    myTbl.add(to_string(i));
  }

  ASSERT_THROW(myTbl.add("test"), const char*);

  try {
    myTbl.add("test");
  } catch (const char *msg) {
    ASSERT_STREQ(msg, "table full");
  }
}

TEST_F(testHashTable, emptyStringNotAllowed)
{
  try{ myTbl.add(""); } catch(const char* msg) {
    ASSERT_STREQ(msg, "empty key not allowed");
  }

}
