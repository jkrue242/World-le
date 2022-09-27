cmake_minimum_required(VERSION 3.23)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runUnitTests ConstructorTest.cpp FileReaderTest.cpp TestData.h TestData.cpp TestData.h)
configure_file(testCountries.txt testCountries.txt COPYONLY)

target_link_libraries(runUnitTests gtest gtest_main)
target_link_libraries(runUnitTests src)