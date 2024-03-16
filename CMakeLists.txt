cmake_minimum_required(VERSION 3.21)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

file(GLOB files *.cpp
        BRO100/*.cpp
        BinarySearch/*.cpp
        CF/*.cpp
        Contest/*.cpp
        DFS/*.cpp
        LC/*.cpp
        NumberTheory/*.cpp
        Sliver/*.cpp
        TODO/*.cpp
        USACO/*.cpp
        XC200/*.cpp
        XC201/*.cpp
        XC202/*.cpp
        XC300/*.cpp
        XC301/*.cpp
        XC302/*.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable(${exe} ${file})
    message(\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
