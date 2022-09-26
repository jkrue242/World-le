cmake_minimum_required(VERSION 3.23)
cmake_minimum_required(VERSION 3.1)
project(World_le)

add_definitions(-std=c++11)

set(SOURCE_FILES main.cpp)
add_executable(World_le_run ${SOURCE_FILES})

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)

target_link_libraries(World_le_run src)
