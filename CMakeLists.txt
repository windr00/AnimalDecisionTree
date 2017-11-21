cmake_minimum_required(VERSION 3.5)
project(AnimalDecisionTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp conditional_binary_tree.cpp conditional_binary_tree.h conditions.h results.h)
add_executable(AnimalDecisionTree ${SOURCE_FILES})
