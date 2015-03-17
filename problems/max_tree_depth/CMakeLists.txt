project(max_tree_depth)

add_executable(max_tree_depth main.cpp)

standard_test()

add_test(valid1 bash -c "cat ${CMAKE_CURRENT_SOURCE_DIR}/test/test1.in | ${CMAKE_CURRENT_BINARY_DIR}/max_tree_depth | diff -u ${CMAKE_CURRENT_SOURCE_DIR}/test/test1.out -")
add_test(valid2 bash -c "cat ${CMAKE_CURRENT_SOURCE_DIR}/test/test2.in | ${CMAKE_CURRENT_BINARY_DIR}/max_tree_depth | diff -u ${CMAKE_CURRENT_SOURCE_DIR}/test/test2.out -")
