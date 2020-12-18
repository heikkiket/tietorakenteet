cmake_minimum_required(VERSION 3.10)
project(Tietorakenteet)

## Needed for c++17 features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

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

add_executable(binarytree-set teht17/Tester.cpp
  teht17/BinaryTree.cpp)

add_executable(setNopeustesti teht17/set-nopeustesti.cpp
  teht17/BinaryTree.cpp)


add_executable(omaNopeustesti teht17/oma-nopeustesti.cpp
  teht8-10/BinaryTree.cpp teht8-10/Node.cpp)

add_executable(matkakortti teht19-22/main.cpp
  teht19-22/matkakortti.cpp teht19-22/matkalippu.cpp)

## Tests
add_executable(runTests teht17/tests.cpp
 teht17/BinaryTree.cpp)


target_link_libraries(runTests gtest gtest_main)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

add_test(iteratorStackTests iteratorStackTests)
