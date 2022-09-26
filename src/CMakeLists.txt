cmake_minimum_required(VERSION 3.23)

project(src)
set(HEADER_FILES
        first.h)

set(SOURCE_FILES
        first.cpp)

add_library(src STATIC ${SOURCE_FILES} ${HEADER_FILES})