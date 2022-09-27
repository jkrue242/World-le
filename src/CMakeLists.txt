cmake_minimum_required(VERSION 3.23)

project(src)
set(HEADER_FILES
        DataReader.h
        Worldle.h)

set(SOURCE_FILES
         DataReader.cpp
        Worldle.cpp)

configure_file(countryData.csv countryData.csv COPYONLY)
add_library(src STATIC ${SOURCE_FILES} ${HEADER_FILES})