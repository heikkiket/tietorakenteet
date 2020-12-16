cmake_minimum_required(VERSION 3.10)
project(Tietorakenteet)


## GOOGLE test
enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


## PROJECT files
add_executable(queue teht2/queueMain.cpp
 teht2/Queue.cpp
 teht1/Node.cpp)

add_executable(iteratorStack teht5/iteratorMain.cpp
 teht5/Stack.cpp)

add_executable(stlListStack teht6/stackMain.cpp
 teht6/Stack.cpp)

add_executable(bintree teht8-10/BinaryTree.cpp
 teht8-10/Tester.cpp teht8-10/Node.cpp)

add_executable(binsearch teht11/main.cpp
 teht11/SortedArray.cpp)

add_executable(hashtable teht13/main.cpp
  teht13/HashTable.cpp)

add_executable(postfix_calc teht14/main.cpp
 teht14/Calc.cpp)

add_executable(matkakortti teht19-2/main.cpp
  teht19-2/matkakortti.cpp teht19-2/matkalippu.cpp)

## Tests
add_executable(runTests teht13/tests.cpp
 teht13/HashTable.cpp)


target_link_libraries(runTests gtest gtest_main)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

add_test(iteratorStackTests iteratorStackTests)
