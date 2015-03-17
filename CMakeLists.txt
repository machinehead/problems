cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

enable_testing()

macro(standard_test)
    add_test(stdtest python ${CMAKE_SOURCE_DIR}/testing/test.py ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
endmacro(standard_test)

add_subdirectory(problems)
add_subdirectory(generators)
