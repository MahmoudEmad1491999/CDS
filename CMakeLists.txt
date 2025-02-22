cmake_minimum_required(VERSION 3.18)

project(CDS DESCRIPTION "C Library for Data Structures." VERSION 0.1)


add_library(Assertion INTERFACE)
target_include_directories(Assertion INTERFACE ${CMAKE_CURRENT_LIST_DIR}/inc/)


add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src/)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/tests/)


