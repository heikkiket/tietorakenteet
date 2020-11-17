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

## Tests
add_executable(runTests teht2/tests.cpp
  teht2/Queue.cpp
  teht1/Node.cpp)
target_link_libraries(runTests gtest gtest_main)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
add_test( runUnitTests runTests)
