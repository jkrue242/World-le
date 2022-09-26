cmake_minimum_required(VERSION 3.23)

project(unit_tests)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(RunUnitTests
        Constructor.cpp)

target_link_libraries(RunUnitTests gtest gtest_main)
target_link_libraries(RunUnitTests src)