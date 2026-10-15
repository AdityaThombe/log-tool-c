cmake_minimum_required(VERSION 3.16)
project(log_tool C)

set(CMAKE_C_STANDARD 11)

add_library(logtool src/logtool.c)
target_include_directories(logtool PUBLIC include)

enable_testing()
add_executable(test_logtool tests/test_logtool.c)
target_link_libraries(test_logtool logtool)
add_test(NAME formats_level COMMAND test_logtool level)
add_test(NAME copies_tag COMMAND test_logtool tag)
add_test(NAME counts_lines COMMAND test_logtool lines)
