cmake_minimum_required(VERSION 3.21)
project(XCamp201A)

set(CMAKE_CXX_STANDARD 14)

file(GLOB files *.cpp BRO100/*.cpp XC201PRE/*.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable(${exe} ${file} HW10Q01.cpp)
    message(\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
