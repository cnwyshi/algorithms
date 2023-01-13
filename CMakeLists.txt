cmake_minimum_required(VERSION 3.21)
project(XCamp201A)

set(CMAKE_CXX_STANDARD 14)

file(GLOB files *.cpp BRO100/*.cpp XC201PRE/*.cpp XC201A/*.cpp XC202C/*.cpp CodeForces/*.cpp USACO/*.cpp CruelStudy/*.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable(${exe} ${file})
    message(\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
